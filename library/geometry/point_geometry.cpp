#include <bits/stdc++.h>

template <typename T> struct Point {
public:
	T x, y;
	Point() : x(0), y(0) {}
	Point(T x_, T y_) : x(x_), y(y_) {}
	template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}
	Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
	Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
	explicit operator std::pair<T, T>() const { return std::pair<T, T>(x, y); }
	explicit operator std::complex<T>() const { return std::complex<T>(x, y); }

	friend std::ostream& operator<<(std::ostream& o, const Point& p) { 
		return o << '(' << p.x << ',' << p.y << ')'; }
	friend std::istream& operator>>(std::istream& i, Point& p) { return i >> p.x >> p.y; }
	friend bool operator==(const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
	friend bool operator!=(const Point& a, const Point& b) { return !(a == b); }
	friend bool operator<(const Point& a, const Point& b) { 
		return (a.x != b.x ? a.x < b.x : a.y < b.y); }

	friend T norm(const Point& a) { return a.x * a.x + a.y * a.y; }
	friend T abs(const Point& p) { return std::hypot(p.x, p.y); }
	friend T unit(const Point& a) { if (a == Point()) return a; return a / abs(a); }
	friend Point conj(const Point& a) { return Point(a.x, -a.y); }
	friend Point perp(const Point& a) { return Point(-a.y, a.x); }
	friend long double arg(const Point& p) { return atan2(p.y, p.x); }
	friend Point dir(long double angle) { return Point(cos(angle), sin(angle)); }

	Point& operator+=(const Point& p) { x += p.x, y += p.y; return *this; }
	Point& operator-=(const Point& p) { x -= p.x, y -= p.y; return *this; }
	Point& operator*=(const T& t) { x *= t, y *= t; return *this; }
	Point& operator/=(const T& t) { x /= t, y /= t; return *this; }
	Point& operator*=(const Point& t) { 
		Point res = Point(x, y) * t; x = res.x, y = res.y; return *this; }
	Point& operator/=(const Point& t) { 
		Point res = Point(x, y) / t; x = res.x, y = res.y; return *this; }

	friend Point operator+(const Point& a, const Point& b) { return Point(a.x + b.x, a.y + b.y); }
	friend Point operator-(const Point& a, const Point& b) { return Point(a.x - b.x, a.y - b.y); }
	friend Point operator*(const Point& a, const T& t) { return Point(a.x * t, a.y * t); }
	friend Point operator*(const T& t ,const Point& a) { return Point(t * a.x, t * a.y); }
	friend Point operator/(const Point& a, const T& t) { return Point(a.x / t, a.y / t); }
	friend Point operator*(const Point& a, const Point& b) { 
		return Point(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y); }
	friend Point operator/(const Point& a, const Point& b) { 
		return Point(a * conj(b) / norm(b)); }

	friend T int_norm(const Point& a) { return __gcd(a.x, a.y); }
	friend T int_unit(const Point& a) { if (a == Point()) return a; return a / int_norm(a); }

	friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
	friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
	friend T area(const Point& a, const Point& b, const Point& c) { return cross(b - a, c - a); }

	// Returns conj(a) * b
	friend Point rotation(const Point& a, const Point& b) { return Point(dot(a, b), cross(a, b)); }

	friend bool same_dir(const Point& a, const Point& b) { return cross(a, b) == 0 && dot(a, b) > 0; }

	// check if 180 <= s..t < 360
	friend bool is_reflex(const Point& a, const Point& b) { 
		auto c = cross(a, b); return c ? (c < 0) : (dot(a, b) < 0); }

	// operator < (s, t) for angles in [base, base+2pi)
	friend bool angle_less(const Point& base, const Point& s, const Point& t) {
		int r = is_reflex(base, s) - is_reflex(base, t);
		return r ? (r < 0) : (0 < cross(s, t));
	}

	friend bool angle_cmp(const Point& base) {
		return [base](const Point& s, const Point& t) { return angle_less(base, s, t); };
	}
	friend bool angle_cmp_center(const Point& center, const Point& dir) {
		return [center, dir](const Point& s, const Point& t) -> bool { 
			return angle_less(dir, s - center, t - center); };
	}

	// is p in [s,t] taken ccw? 1/0/-1 for in/border/out
	friend int angle_between(const Point& s, const Point& t, const Point& p) {
		if (same_dir(p, s) || same_dir(p, t)) return 0;
		return angle_less(s, p, t) ? 1 : -1;
	}
};

namespace Geometry2D {

template <class T> int sign(T x) { return (x > 0) - (x < 0); }
template <class T> Point<T> reflect(const Point<T>& p, const Point<T>& a, const Point<T>& b) {
		return a + conj((p - a) / (b - a)) * (b - a); }
template <class T> Point<T> foot( const Point<T>& p, const Point<T>& a, const Point<T>& b) {
		return (p + reflect(p, a, b)) / (T) 2; }
template <class T> bool on_segment(Point<T> p, Point<T> a, Point<T> b) {
	return area(a, b, p) == 0 && dot(p - a, p - b) <= 0; }

template <class T>
std::vector<Point<T>> segment_intersect(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
	T x = area(a, b, c), y = area(a, b, d);
	T X = area(c, d, a), Y = area(c, d, b);
	if (sign(x) * sign(y) < 0 && sign(X) * sign(Y) < 0)
		return {(d * x - c * y) / (x - y)};
	std::set<Point<T>> s;
	if (on_segment(a, c, d))
		s.insert(a);
	if (on_segment(b, c, d))
		s.insert(b);
	if (on_segment(c, a, b))
		s.insert(c);
	if (on_segment(d, a, b))
		s.insert(d);
	return {s.begin(), s.end()};
}

template <class T> Point<T> extension(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
	T x = cross(a, b, c);
	T y = cross(a, b, d);
	return (d * x - c * y) / (x - y);
}

template <class T> std::pair<int, Point<T>> line_intersect(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
	// returns -1 if infinitely, 0 if none, 1 if unique 
	if (cross(b - a, d - c) == 0)
		return {-(cross(a, c, d) == 0), Point<T>()};
	else 
		return {1, extend(a, b, c, d)};
}

template <class T> T line_dist(Point<T> p, Point<T> a, Point<T> b) {
	return abs(area(p, a, b)) / abs(a - b); }

template <class T> T point_segment_dist(Point<T> p, Point<T> a, Point<T> b) {
	if (dot(p - a, b - a) <= 0)
		return abs(p - a);
	if (dot(p - b, a - b) <= 0)
		return abs(p - b);
	return line_dist(p, a, b);
}

template <class T> T segment_segment_dist(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
	std::vector<Point<T>> v = segment_intersect(a, b, c, d);
	if (!v.empty())
		return 0;
	return std::min({point_segment_dist(a, c, d), point_segment_dist(b, c, d), 
		point_segment_dist(c, a, b), point_segment_dist(d, a, b)});
}

template <class T> std::pair<Point<T>, T> centroid_area(const std::vector<Point<T>> v) {
	// pair of centroid and area, positive means CCW, negative means CW
	Point<T> centroid(0, 0);
	T area = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		int j = (i + 1) % ((int)v.size());
		T a = cross(v[i], v[j]);
		centroid += a * (v[i] + v[j]);
		area += a;
	}
	return {centroid / area / (T) 3, area / 2};
}

template<class T> int polygon_point(const std::vector<Point<T>>& p, Point<T> z) {
	// returns -1 if outside, 0 if on, 1 if inside
	int n = (int)p.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		Point<T> x = p[i], y = p[(i + 1) % n];
		if (x.y > y.y) 
			std::swap(x, y);
		if (on_segment(z, x, y))
			return 0;
		ans ^= (x.y <= z.y && y.y > z.y && area(z, x, y) > 0);
	}
	return ans ? 1 : -1;
}

} // Geometry2D

int main() {
	using namespace std;
	using namespace Geometry2D;
	typedef long double ld;
	typedef Point<long double> P;
	cout << setprecision(1) << fixed;
	while (true) {
		int n; cin >> n;
		if (n == 0)
			return 0;
		vector<Point<int>> v(n);
		for (int i = 0; i < n; i++) 
			cin >> v[i].x >> v[i].y;
		int m; cin >> m;
		while (m--) {
			Point<int> p;
			cin >> p.x >> p.y;
			int res = polygon_point(v, p);
			if (res == -1)
				cout << "out\n";
			else if (res == 0)
				cout << "on\n";
			else 
				cout << "in\n";
		}
	}
	return 0;
}