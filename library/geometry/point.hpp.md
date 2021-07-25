---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/geometry/convex-hull.hpp
    title: library/geometry/convex-hull.hpp
  - icon: ':warning:'
    path: library/geometry/geometry-2d.hpp
    title: library/geometry/geometry-2d.hpp
  - icon: ':warning:'
    path: test/convex-hull.cpp
    title: test/convex-hull.cpp
  - icon: ':warning:'
    path: test/geometry-2d.cpp
    title: test/geometry-2d.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/angular-sort.test.cpp
    title: test/angular-sort.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\ntemplate <typename T> struct Point {\npublic:\n\tT x, y;\n\tPoint()\
    \ : x(0), y(0) {}\n\tPoint(T x_, T y_) : x(x_), y(y_) {}\n\ttemplate <typename\
    \ U> explicit Point(const Point<U> &p) : x(p.x), y(p.y) {}\n\tPoint(const std::pair<T,\
    \ T> &p) : x(p.first), y(p.second) {}\n\tPoint(const std::complex<T> &p) : x(real(p)),\
    \ y(imag(p)) {}\n\texplicit operator std::pair<T, T>() const { return std::pair<T,\
    \ T>(x, y); }\n\texplicit operator std::complex<T>() const { return std::complex<T>(x,\
    \ y); }\n\n\tfriend std::ostream& operator<<(std::ostream &o, const Point &p)\
    \ { \n\t\treturn o << '(' << p.x << ',' << p.y << ')'; }\n\tfriend std::istream&\
    \ operator>>(std::istream &i, Point &p) { return i >> p.x >> p.y; }\n\tfriend\
    \ bool operator==(const Point &a, const Point &b) { return a.x == b.x && a.y ==\
    \ b.y; }\n\tfriend bool operator!=(const Point &a, const Point &b) { return !(a\
    \ == b); }\n\tfriend bool operator<(const Point &a, const Point &b) { \n\t\treturn\
    \ (a.x != b.x ? a.x < b.x : a.y < b.y); }\n\n\tfriend T norm(const Point &a) {\
    \ return a.x * a.x + a.y * a.y; }\n\tfriend T abs(const Point &p) { return std::hypot(p.x,\
    \ p.y); }\n\tfriend T unit(const Point &a) { if (a == Point()) return a; return\
    \ a / abs(a); }\n\tfriend Point conj(const Point &a) { return Point(a.x, -a.y);\
    \ }\n\tfriend Point perp(const Point &a) { return Point(-a.y, a.x); }\n\tfriend\
    \ long double arg(const Point &p) { return atan2(p.y, p.x); }\n\tfriend Point\
    \ dir(long double angle) { return Point(cos(angle), sin(angle)); }\n\n\tPoint&\
    \ operator+=(const Point &p) { x += p.x, y += p.y; return *this; }\n\tPoint& operator-=(const\
    \ Point &p) { x -= p.x, y -= p.y; return *this; }\n\tPoint& operator*=(const T\
    \ &t) { x *= t, y *= t; return *this; }\n\tPoint& operator/=(const T &t) { x /=\
    \ t, y /= t; return *this; }\n\tPoint& operator*=(const Point &t) { \n\t\tPoint\
    \ res = Point(x, y) * t; x = res.x, y = res.y; return *this; }\n\tPoint& operator/=(const\
    \ Point &t) { \n\t\tPoint res = Point(x, y) / t; x = res.x, y = res.y; return\
    \ *this; }\n\n\tfriend Point operator+(const Point &a, const Point &b) { return\
    \ Point(a.x + b.x, a.y + b.y); }\n\tfriend Point operator-(const Point &a, const\
    \ Point &b) { return Point(a.x - b.x, a.y - b.y); }\n\tfriend Point operator*(const\
    \ Point &a, const T &t) { return Point(a.x * t, a.y * t); }\n\tfriend Point operator*(const\
    \ T &t ,const Point &a) { return Point(t * a.x, t * a.y); }\n\tfriend Point operator/(const\
    \ Point &a, const T &t) { return Point(a.x / t, a.y / t); }\n\tfriend Point operator*(const\
    \ Point &a, const Point &b) { \n\t\treturn Point(a.x * b.x - a.y * b.y, a.y *\
    \ b.x + a.x * b.y); }\n\tfriend Point operator/(const Point &a, const Point &b)\
    \ { \n\t\treturn Point(a * conj(b) / norm(b)); }\n\n\tfriend T int_norm(const\
    \ Point &a) { return __gcd(a.x, a.y); }\n\tfriend T int_unit(const Point &a) {\
    \ if (a == Point()) return a; return a / int_norm(a); }\n\n\tfriend T cross(const\
    \ Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }\n\tfriend T dot(const\
    \ Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }\n\tfriend T area(const\
    \ Point &a, const Point &b, const Point &c) { return cross(b - a, c - a); }\n\n\
    \t// Returns conj(a) * b\n\tfriend Point rotation(const Point &a, const Point\
    \ &b) { return Point(dot(a, b), cross(a, b)); }\n\n\tfriend bool same_dir(const\
    \ Point &a, const Point &b) { return cross(a, b) == 0 && dot(a, b) > 0; }\n\n\t\
    // check if 180 <= s..t < 360\n\tfriend bool is_reflex(const Point &a, const Point\
    \ &b) { \n\t\tauto c = cross(a, b); return c ? (c < 0) : (dot(a, b) < 0); }\n\n\
    \t// operator < (s, t) for angles in [base, base+2pi)\n\tfriend bool angle_less(const\
    \ Point &base, const Point &s, const Point &t) {\n\t\tint r = is_reflex(base,\
    \ s) - is_reflex(base, t);\n\t\treturn r ? (r < 0) : (0 < cross(s, t));\n\t}\n\
    \n\tfriend bool angle_cmp(const Point &base) {\n\t\treturn [base](const Point\
    \ &s, const Point &t) { return angle_less(base, s, t); };\n\t}\n\tfriend bool\
    \ angle_cmp_center(const Point &center, const Point &dir) {\n\t\treturn [center,\
    \ dir](const Point &s, const Point &t) -> bool { \n\t\t\treturn angle_less(dir,\
    \ s - center, t - center); };\n\t}\n\n\t// is p in [s,t] taken ccw? 1/0/-1 for\
    \ in/border/out\n\tfriend int angle_between(const Point &s, const Point &t, const\
    \ Point &p) {\n\t\tif (same_dir(p, s) || same_dir(p, t)) return 0;\n\t\treturn\
    \ angle_less(s, p, t) ? 1 : -1;\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <typename T> struct Point {\npublic:\n\tT x, y;\n\
    \tPoint() : x(0), y(0) {}\n\tPoint(T x_, T y_) : x(x_), y(y_) {}\n\ttemplate <typename\
    \ U> explicit Point(const Point<U> &p) : x(p.x), y(p.y) {}\n\tPoint(const std::pair<T,\
    \ T> &p) : x(p.first), y(p.second) {}\n\tPoint(const std::complex<T> &p) : x(real(p)),\
    \ y(imag(p)) {}\n\texplicit operator std::pair<T, T>() const { return std::pair<T,\
    \ T>(x, y); }\n\texplicit operator std::complex<T>() const { return std::complex<T>(x,\
    \ y); }\n\n\tfriend std::ostream& operator<<(std::ostream &o, const Point &p)\
    \ { \n\t\treturn o << '(' << p.x << ',' << p.y << ')'; }\n\tfriend std::istream&\
    \ operator>>(std::istream &i, Point &p) { return i >> p.x >> p.y; }\n\tfriend\
    \ bool operator==(const Point &a, const Point &b) { return a.x == b.x && a.y ==\
    \ b.y; }\n\tfriend bool operator!=(const Point &a, const Point &b) { return !(a\
    \ == b); }\n\tfriend bool operator<(const Point &a, const Point &b) { \n\t\treturn\
    \ (a.x != b.x ? a.x < b.x : a.y < b.y); }\n\n\tfriend T norm(const Point &a) {\
    \ return a.x * a.x + a.y * a.y; }\n\tfriend T abs(const Point &p) { return std::hypot(p.x,\
    \ p.y); }\n\tfriend T unit(const Point &a) { if (a == Point()) return a; return\
    \ a / abs(a); }\n\tfriend Point conj(const Point &a) { return Point(a.x, -a.y);\
    \ }\n\tfriend Point perp(const Point &a) { return Point(-a.y, a.x); }\n\tfriend\
    \ long double arg(const Point &p) { return atan2(p.y, p.x); }\n\tfriend Point\
    \ dir(long double angle) { return Point(cos(angle), sin(angle)); }\n\n\tPoint&\
    \ operator+=(const Point &p) { x += p.x, y += p.y; return *this; }\n\tPoint& operator-=(const\
    \ Point &p) { x -= p.x, y -= p.y; return *this; }\n\tPoint& operator*=(const T\
    \ &t) { x *= t, y *= t; return *this; }\n\tPoint& operator/=(const T &t) { x /=\
    \ t, y /= t; return *this; }\n\tPoint& operator*=(const Point &t) { \n\t\tPoint\
    \ res = Point(x, y) * t; x = res.x, y = res.y; return *this; }\n\tPoint& operator/=(const\
    \ Point &t) { \n\t\tPoint res = Point(x, y) / t; x = res.x, y = res.y; return\
    \ *this; }\n\n\tfriend Point operator+(const Point &a, const Point &b) { return\
    \ Point(a.x + b.x, a.y + b.y); }\n\tfriend Point operator-(const Point &a, const\
    \ Point &b) { return Point(a.x - b.x, a.y - b.y); }\n\tfriend Point operator*(const\
    \ Point &a, const T &t) { return Point(a.x * t, a.y * t); }\n\tfriend Point operator*(const\
    \ T &t ,const Point &a) { return Point(t * a.x, t * a.y); }\n\tfriend Point operator/(const\
    \ Point &a, const T &t) { return Point(a.x / t, a.y / t); }\n\tfriend Point operator*(const\
    \ Point &a, const Point &b) { \n\t\treturn Point(a.x * b.x - a.y * b.y, a.y *\
    \ b.x + a.x * b.y); }\n\tfriend Point operator/(const Point &a, const Point &b)\
    \ { \n\t\treturn Point(a * conj(b) / norm(b)); }\n\n\tfriend T int_norm(const\
    \ Point &a) { return __gcd(a.x, a.y); }\n\tfriend T int_unit(const Point &a) {\
    \ if (a == Point()) return a; return a / int_norm(a); }\n\n\tfriend T cross(const\
    \ Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }\n\tfriend T dot(const\
    \ Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }\n\tfriend T area(const\
    \ Point &a, const Point &b, const Point &c) { return cross(b - a, c - a); }\n\n\
    \t// Returns conj(a) * b\n\tfriend Point rotation(const Point &a, const Point\
    \ &b) { return Point(dot(a, b), cross(a, b)); }\n\n\tfriend bool same_dir(const\
    \ Point &a, const Point &b) { return cross(a, b) == 0 && dot(a, b) > 0; }\n\n\t\
    // check if 180 <= s..t < 360\n\tfriend bool is_reflex(const Point &a, const Point\
    \ &b) { \n\t\tauto c = cross(a, b); return c ? (c < 0) : (dot(a, b) < 0); }\n\n\
    \t// operator < (s, t) for angles in [base, base+2pi)\n\tfriend bool angle_less(const\
    \ Point &base, const Point &s, const Point &t) {\n\t\tint r = is_reflex(base,\
    \ s) - is_reflex(base, t);\n\t\treturn r ? (r < 0) : (0 < cross(s, t));\n\t}\n\
    \n\tfriend bool angle_cmp(const Point &base) {\n\t\treturn [base](const Point\
    \ &s, const Point &t) { return angle_less(base, s, t); };\n\t}\n\tfriend bool\
    \ angle_cmp_center(const Point &center, const Point &dir) {\n\t\treturn [center,\
    \ dir](const Point &s, const Point &t) -> bool { \n\t\t\treturn angle_less(dir,\
    \ s - center, t - center); };\n\t}\n\n\t// is p in [s,t] taken ccw? 1/0/-1 for\
    \ in/border/out\n\tfriend int angle_between(const Point &s, const Point &t, const\
    \ Point &p) {\n\t\tif (same_dir(p, s) || same_dir(p, t)) return 0;\n\t\treturn\
    \ angle_less(s, p, t) ? 1 : -1;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/point.hpp
  requiredBy:
  - test/geometry-2d.cpp
  - test/convex-hull.cpp
  - library/geometry/geometry-2d.hpp
  - library/geometry/convex-hull.hpp
  timestamp: '2021-07-24 21:53:34-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/angular-sort.test.cpp
documentation_of: library/geometry/point.hpp
layout: document
redirect_from:
- /library/library/geometry/point.hpp
- /library/library/geometry/point.hpp.html
title: library/geometry/point.hpp
---
