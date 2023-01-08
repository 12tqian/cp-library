---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/geometry/geometry-2d.hpp
    title: library/geometry/geometry-2d.hpp
  - icon: ':heavy_check_mark:'
    path: library/geometry/point.hpp
    title: library/geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n\r\ntemplate <typename T>\
    \ struct Point {\r\npublic:\r\n\tT x, y;\r\n\tPoint() : x(0), y(0) {}\r\n\tPoint(T\
    \ x_, T y_) : x(x_), y(y_) {}\r\n\ttemplate <typename U> explicit Point(const\
    \ Point<U>& p) : x(p.x), y(p.y) {}\r\n\tPoint(const std::pair<T, T>& p) : x(p.first),\
    \ y(p.second) {}\r\n\tPoint(const std::complex<T>& p) : x(real(p)), y(imag(p))\
    \ {}\r\n\texplicit operator std::pair<T, T>() const { return std::pair<T, T>(x,\
    \ y); }\r\n\texplicit operator std::complex<T>() const { return std::complex<T>(x,\
    \ y); }\r\n\r\n\tfriend std::ostream& operator<<(std::ostream &o, const Point&\
    \ p) { \r\n\t\treturn o << '(' << p.x << ',' << p.y << ')'; }\r\n\tfriend std::istream&\
    \ operator>>(std::istream &i, Point& p) { return i >> p.x >> p.y; }\r\n\tfriend\
    \ bool operator==(const Point& a, const Point& b) { return a.x == b.x && a.y ==\
    \ b.y; }\r\n\tfriend bool operator!=(const Point& a, const Point& b) { return\
    \ !(a == b); }\r\n\tfriend bool operator<(const Point& a, const Point& b) { \r\
    \n\t\treturn (a.x != b.x ? a.x < b.x : a.y < b.y); }\r\n\r\n\tfriend T norm(const\
    \ Point& a) { return a.x * a.x + a.y * a.y; }\r\n\tfriend T abs(const Point& p)\
    \ { return std::hypot(p.x, p.y); }\r\n\tfriend T unit(const Point& a) { if (a\
    \ == Point()) return a; return a / abs(a); }\r\n\tfriend Point conj(const Point&\
    \ a) { return Point(a.x, -a.y); }\r\n\tfriend Point perp(const Point& a) { return\
    \ Point(-a.y, a.x); }\r\n\tfriend long double arg(const Point& p) { return atan2(p.y,\
    \ p.x); }\r\n\tfriend Point dir(long double angle) { return Point(cos(angle),\
    \ sin(angle)); }\r\n\r\n\tPoint& operator+=(const Point& p) { x += p.x, y += p.y;\
    \ return *this; }\r\n\tPoint& operator-=(const Point& p) { x -= p.x, y -= p.y;\
    \ return *this; }\r\n\tPoint& operator*=(const T &t) { x *= t, y *= t; return\
    \ *this; }\r\n\tPoint& operator/=(const T &t) { x /= t, y /= t; return *this;\
    \ }\r\n\tPoint& operator*=(const Point& t) { \r\n\t\tPoint res = Point(x, y) *\
    \ t; x = res.x, y = res.y; return *this; }\r\n\tPoint& operator/=(const Point&\
    \ t) { \r\n\t\tPoint res = Point(x, y) / t; x = res.x, y = res.y; return *this;\
    \ }\r\n\r\n\tfriend Point operator+(const Point& a, const Point& b) { return Point(a.x\
    \ + b.x, a.y + b.y); }\r\n\tfriend Point operator-(const Point& a, const Point&\
    \ b) { return Point(a.x - b.x, a.y - b.y); }\r\n\tfriend Point operator*(const\
    \ Point& a, const T &t) { return Point(a.x * t, a.y * t); }\r\n\tfriend Point\
    \ operator*(const T &t ,const Point& a) { return Point(t * a.x, t * a.y); }\r\n\
    \tfriend Point operator/(const Point& a, const T &t) { return Point(a.x / t, a.y\
    \ / t); }\r\n\tfriend Point operator*(const Point& a, const Point& b) { \r\n\t\
    \treturn Point(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y); }\r\n\tfriend Point\
    \ operator/(const Point& a, const Point& b) { \r\n\t\treturn Point(a * conj(b)\
    \ / norm(b)); }\r\n\r\n\tfriend T int_norm(const Point& a) { return __gcd(a.x,\
    \ a.y); }\r\n\tfriend T int_unit(const Point& a) { if (a == Point()) return a;\
    \ return a / int_norm(a); }\r\n\r\n\tfriend T cross(const Point& a, const Point&\
    \ b) { return a.x * b.y - a.y * b.x; }\r\n\tfriend T dot(const Point& a, const\
    \ Point& b) { return a.x * b.x + a.y * b.y; }\r\n\tfriend T area(const Point&\
    \ a, const Point& b, const Point& c) { return cross(b - a, c - a); }\r\n\r\n\t\
    // Returns conj(a) * b\r\n\tfriend Point rotation(const Point& a, const Point&\
    \ b) { return Point(dot(a, b), cross(a, b)); }\r\n\r\n\tfriend bool same_dir(const\
    \ Point& a, const Point& b) { return cross(a, b) == 0 && dot(a, b) > 0; }\r\n\r\
    \n\t// check if 180 <= s..t < 360\r\n\tfriend bool is_reflex(const Point& a, const\
    \ Point& b) { \r\n\t\tauto c = cross(a, b); return c ? (c < 0) : (dot(a, b) <\
    \ 0); }\r\n\r\n\t// operator < (s, t) for angles in [base, base+2pi)\r\n\tfriend\
    \ bool angle_less(const Point& base, const Point& s, const Point& t) {\r\n\t\t\
    int r = is_reflex(base, s) - is_reflex(base, t);\r\n\t\treturn r ? (r < 0) : (0\
    \ < cross(s, t));\r\n\t}\r\n\r\n\tfriend bool angle_cmp(const Point& base) {\r\
    \n\t\treturn [base](const Point& s, const Point& t) { return angle_less(base,\
    \ s, t); };\r\n\t}\r\n\tfriend bool angle_cmp_center(const Point& center, const\
    \ Point& dir) {\r\n\t\treturn [center, dir](const Point& s, const Point& t) ->\
    \ bool { \r\n\t\t\treturn angle_less(dir, s - center, t - center); };\r\n\t}\r\
    \n\r\n\t// is p in [s,t] taken ccw? 1/0/-1 for in/border/out\r\n\tfriend int angle_between(const\
    \ Point& s, const Point& t, const Point& p) {\r\n\t\tif (same_dir(p, s) || same_dir(p,\
    \ t)) return 0;\r\n\t\treturn angle_less(s, p, t) ? 1 : -1;\r\n\t}\r\n};\n\r\n\
    namespace Geometry2D {\r\n\r\ntemplate <class T> int sign(T x) { return (x > 0)\
    \ - (x < 0); }\r\ntemplate <class T> Point<T> reflect(const Point<T>& p, const\
    \ Point<T>& a, const Point<T>& b) {\r\n\t\treturn a + conj((p - a) / (b - a))\
    \ * (b - a); }\r\ntemplate <class T> Point<T> foot( const Point<T>& p, const Point<T>&\
    \ a, const Point<T>& b) {\r\n\t\treturn (p + reflect(p, a, b)) / (T) 2; }\r\n\
    template <class T> bool on_segment(Point<T> p, Point<T> a, Point<T> b) {\r\n\t\
    return area(a, b, p) == 0 && dot(p - a, p - b) <= 0; }\r\n\r\ntemplate <class\
    \ T>\r\nstd::vector<Point<T>> segment_intersect(Point<T> a, Point<T> b, Point<T>\
    \ c, Point<T> d) {\r\n\tT x = area(a, b, c), y = area(a, b, d);\r\n\tT X = area(c,\
    \ d, a), Y = area(c, d, b);\r\n\tif (sign(x) * sign(y) < 0 && sign(X) * sign(Y)\
    \ < 0)\r\n\t\treturn {(d * x - c * y) / (x - y)};\r\n\tstd::set<Point<T>> s;\r\
    \n\tif (on_segment(a, c, d))\r\n\t\ts.insert(a);\r\n\tif (on_segment(b, c, d))\r\
    \n\t\ts.insert(b);\r\n\tif (on_segment(c, a, b))\r\n\t\ts.insert(c);\r\n\tif (on_segment(d,\
    \ a, b))\r\n\t\ts.insert(d);\r\n\treturn {s.begin(), s.end()};\r\n}\r\n\r\ntemplate\
    \ <class T> Point<T> extension(Point<T> a, Point<T> b, Point<T> c, Point<T> d)\
    \ {\r\n\tT x = cross(a, b, c);\r\n\tT y = cross(a, b, d);\r\n\treturn (d * x -\
    \ c * y) / (x - y);\r\n}\r\n\r\ntemplate <class T> std::pair<int, Point<T>> line_intersect(Point<T>\
    \ a, Point<T> b, Point<T> c, Point<T> d) {\r\n\t// returns -1 if infinitely, 0\
    \ if none, 1 if unique \r\n\tif (cross(b - a, d - c) == 0)\r\n\t\treturn {-(cross(a,\
    \ c, d) == 0), Point<T>()};\r\n\telse \r\n\t\treturn {1, extend(a, b, c, d)};\r\
    \n}\r\n\r\ntemplate <class T> T line_dist(Point<T> p, Point<T> a, Point<T> b)\
    \ {\r\n\treturn abs(area(p, a, b)) / abs(a - b); }\r\n\r\ntemplate <class T> T\
    \ point_segment_dist(Point<T> p, Point<T> a, Point<T> b) {\r\n\tif (dot(p - a,\
    \ b - a) <= 0)\r\n\t\treturn abs(p - a);\r\n\tif (dot(p - b, a - b) <= 0)\r\n\t\
    \treturn abs(p - b);\r\n\treturn line_dist(p, a, b);\r\n}\r\n\r\ntemplate <class\
    \ T> T segment_segment_dist(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {\r\
    \n\tstd::vector<Point<T>> v = segment_intersect(a, b, c, d);\r\n\tif (!v.empty())\r\
    \n\t\treturn 0;\r\n\treturn std::min({point_segment_dist(a, c, d), point_segment_dist(b,\
    \ c, d), \r\n\t\tpoint_segment_dist(c, a, b), point_segment_dist(d, a, b)});\r\
    \n}\r\n\r\ntemplate <class T> std::pair<Point<T>, T> centroid_area(const std::vector<Point<T>>\
    \ v) {\r\n\t// pair of centroid and area, positive means CCW, negative means CW\r\
    \n\tPoint<T> centroid(0, 0);\r\n\tT area = 0;\r\n\tfor (int i = 0; i < (int)v.size();\
    \ i++) {\r\n\t\tint j = (i + 1) % ((int)v.size());\r\n\t\tT a = cross(v[i], v[j]);\r\
    \n\t\tcentroid += a * (v[i] + v[j]);\r\n\t\tarea += a;\r\n\t}\r\n\treturn {centroid\
    \ / area / (T) 3, area / 2};\r\n}\r\n\r\ntemplate<class T> int polygon_point(const\
    \ std::vector<Point<T>>& p, Point<T> z) {\r\n\t// returns -1 if outside, 0 if\
    \ on, 1 if inside\r\n\tint n = (int)p.size();\r\n\tint ans = 0;\r\n\tfor (int\
    \ i = 0; i < n; i++) {\r\n\t\tPoint<T> x = p[i], y = p[(i + 1) % n];\r\n\t\tif\
    \ (x.y > y.y) \r\n\t\t\tstd::swap(x, y);\r\n\t\tif (on_segment(z, x, y))\r\n\t\
    \t\treturn 0;\r\n\t\tans ^= (x.y <= z.y && y.y > z.y && area(z, x, y) > 0);\r\n\
    \t}\r\n\treturn ans ? 1 : -1;\r\n}\r\n\r\n} // Geometry2D\n\r\nusing P = Point<long\
    \ long>;\r\n\r\nusing namespace Geometry2D;\r\n\r\nint half(P x) {\r\n\treturn\
    \ x.y != 0 ? sign(x.y) : -sign(x.x); \r\n}\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n;\r\n\tcin >> n;\r\n\tvector<Point<long long>>\
    \ p(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tcin >> p[i];\r\n\t}\r\n\tsort(p.begin(),\
    \ p.end(), [&](P a, P b) {\r\n\t\tint A = half(a), B = half(b);\r\n\t\treturn\
    \ A == B ? cross(a, b) > 0 : A < B;\r\n\t});\r\n\tfor (int i = 0; i < n; ++i)\
    \ {\r\n\t\tcout << p[i].x << ' ' << p[i].y << '\\n';\r\n\t}\r\n\treturn 0;\r\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/geometry/geometry-2d.hpp\"\r\n\r\nusing P = Point<long long>;\r\n\
    \r\nusing namespace Geometry2D;\r\n\r\nint half(P x) {\r\n\treturn x.y != 0 ?\
    \ sign(x.y) : -sign(x.x); \r\n}\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n;\r\n\tcin >> n;\r\n\tvector<Point<long long>>\
    \ p(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tcin >> p[i];\r\n\t}\r\n\tsort(p.begin(),\
    \ p.end(), [&](P a, P b) {\r\n\t\tint A = half(a), B = half(b);\r\n\t\treturn\
    \ A == B ? cross(a, b) > 0 : A < B;\r\n\t});\r\n\tfor (int i = 0; i < n; ++i)\
    \ {\r\n\t\tcout << p[i].x << ' ' << p[i].y << '\\n';\r\n\t}\r\n\treturn 0;\r\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/geometry/geometry-2d.hpp
  - library/geometry/point.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-sort_points_by_argument.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-sort_points_by_argument.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-sort_points_by_argument.test.cpp
- /verify/verify/yosupo/yosupo-sort_points_by_argument.test.cpp.html
title: verify/yosupo/yosupo-sort_points_by_argument.test.cpp
---
