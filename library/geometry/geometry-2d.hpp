#pragma once

#include "point.hpp"

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