---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/geometry/point.hpp
    title: library/geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <typename T> struct Point {\npublic:\n\tT x, y;\n\tPoint() : x(0),\
    \ y(0) {}\n\tPoint(T x_, T y_) : x(x_), y(y_) {}\n\ttemplate <typename U> explicit\
    \ Point(const Point<U> &p) : x(p.x), y(p.y) {}\n\tPoint(const std::pair<T, T>\
    \ &p) : x(p.first), y(p.second) {}\n\tPoint(const std::complex<T> &p) : x(real(p)),\
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
    \ angle_less(s, p, t) ? 1 : -1;\n\t}\n};\n\nusing P = Point<long long>;\n\nusing\
    \ namespace Geometry2D;\n\nint half(P x) {\n\treturn x.y != 0 ? sign(x.y) : -sign(x.x);\
    \ \n}\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\t\
    int n;\n\tcin >> n;\n\tvector<Point<long long>> p(n);\n\tfor (int i = 0; i < n;\
    \ ++i) {\n\t\tcin >> p[i];\n\t}\n\tsort(p.begin(), p.end(), [&](P a, P b) {\n\t\
    \tint A = half(a), B = half(b);\n\t\treturn A == B ? cross(a, b) > 0 : A < B;\n\
    \t});\n\tfor (int i = 0; i < n; ++i) {\n\t\tcout << p[i].x << ' ' << p[i].y <<\
    \ '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/geometry/point.hpp\"\
    \n\nusing P = Point<long long>;\n\nusing namespace Geometry2D;\n\nint half(P x)\
    \ {\n\treturn x.y != 0 ? sign(x.y) : -sign(x.x); \n}\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n;\n\tcin >> n;\n\tvector<Point<long long>> p(n);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tcin >> p[i];\n\t}\n\tsort(p.begin(), p.end(),\
    \ [&](P a, P b) {\n\t\tint A = half(a), B = half(b);\n\t\treturn A == B ? cross(a,\
    \ b) > 0 : A < B;\n\t});\n\tfor (int i = 0; i < n; ++i) {\n\t\tcout << p[i].x\
    \ << ' ' << p[i].y << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/geometry/point.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-sort_points_by_argument.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-sort_points_by_argument.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-sort_points_by_argument.test.cpp
- /verify/verify/yosupo/yosupo-sort_points_by_argument.test.cpp.html
title: verify/yosupo/yosupo-sort_points_by_argument.test.cpp
---
