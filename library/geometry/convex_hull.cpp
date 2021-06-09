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

namespace ConvexHull {

template <class T>
std::pair<std::vector<int>, std::vector<int>> upper_lower_hull(const std::vector<Point<T>>& v) {
    std::vector<int> p((int)v.size()), upper, lower;
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&v](int a, int b) { return v[a] < v[b]; });
    for (int& i : p) {
        while ((int)upper.size() > 1 && 
            area(v[upper[(int)upper.size() - 2]], v[upper.back()], v[i]) >= 0) 
            upper.pop_back();
        upper.push_back(i);
        while ((int)lower.size() > 1 && 
            area(v[lower[(int)lower.size() - 2]], v[lower.back()], v[i]) <= 0) 
            lower.pop_back();
        lower.push_back(i);
    }
    return {upper, lower};
}

template <class T> std::vector<int> hull_index(const std::vector<Point<T>>& v) {
    std::vector<int> upper, lower;
    tie(upper, lower) = upper_lower_hull(v);
    if ((int)lower.size() <= 1) 
        return lower;
    if (v[lower[0]] == v[lower[1]])
        return {0};
    lower.insert(lower.end(), 1 + upper.rbegin(), upper.rend() - 1);
    return lower;
}

template <class T> std::vector<Point<T>> convex_hull(const std::vector<Point<T>>& v) {
    std::vector<int> w = hull_index(v);
    std::vector<Point<T>> res;
    for (auto& t : w)
        res.push_back(v[t]);
    return res;
}

} // ConvexHull

int main() {
    using namespace std;
    using namespace ConvexHull;
    ios_base::sync_with_stdio(0);
    while (true) {
        int n; cin >> n;
        if (n == 0) 
            return 0;
        vector<Point<int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].x >> v[i].y;
        auto hull = convex_hull(v);
        cout << (int)hull.size() << '\n';       
        for (auto& p : hull)
            cout << p.x << " " << p.y << '\n';
    }
    return 0;
}