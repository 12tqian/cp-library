---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/geometry/convex-hull.hpp
    title: library/geometry/convex-hull.hpp
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
    PROBLEM: https://open.kattis.com/problems/convexhull
    links:
    - https://open.kattis.com/problems/convexhull
  bundledCode: "#define PROBLEM \"https://open.kattis.com/problems/convexhull\"\r\n\
    \r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
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
    namespace ConvexHull {\r\n\r\ntemplate <class T>\r\nstd::pair<std::vector<int>,\
    \ std::vector<int>> upper_lower_hull(const std::vector<Point<T>>& v) {\r\n\tstd::vector<int>\
    \ p((int)v.size()), upper, lower;\r\n\tiota(p.begin(), p.end(), 0);\r\n\tsort(p.begin(),\
    \ p.end(), [&v](int a, int b) { return v[a] < v[b]; });\r\n\tfor (int i : p) {\r\
    \n\t\twhile ((int)upper.size() > 1 && \r\n\t\t\tarea(v[upper[(int)upper.size()\
    \ - 2]], v[upper.back()], v[i]) >= 0) \r\n\t\t\tupper.pop_back();\r\n\t\tupper.push_back(i);\r\
    \n\t\twhile ((int)lower.size() > 1 && \r\n\t\t\tarea(v[lower[(int)lower.size()\
    \ - 2]], v[lower.back()], v[i]) <= 0) \r\n\t\t\tlower.pop_back();\r\n\t\tlower.push_back(i);\r\
    \n\t}\r\n\treturn {upper, lower};\r\n}\r\n\r\ntemplate <class T> std::vector<int>\
    \ hull_index(const std::vector<Point<T>>& v) {\r\n\tstd::vector<int> upper, lower;\r\
    \n\ttie(upper, lower) = upper_lower_hull(v);\r\n\tif ((int)lower.size() <= 1)\
    \ \r\n\t\treturn lower;\r\n\tif (v[lower[0]] == v[lower[1]])\r\n\t\treturn {0};\r\
    \n\tlower.insert(lower.end(), 1 + upper.rbegin(), upper.rend() - 1);\r\n\treturn\
    \ lower;\r\n}\r\n\r\ntemplate <class T> std::vector<Point<T>> convex_hull(const\
    \ std::vector<Point<T>>& v) {\r\n\tstd::vector<int> w = hull_index(v);\r\n\tstd::vector<Point<T>>\
    \ res;\r\n\tfor (auto& t : w)\r\n\t\tres.push_back(v[t]);\r\n\treturn res;\r\n\
    }\r\n\r\n} // ConvexHull\n\r\n// kattis verified\r\nint main() {\r\n\tusing namespace\
    \ std;\r\n\tusing namespace ConvexHull;\r\n\tios_base::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\twhile (true) {\r\n\t\tint n; cin >> n;\r\n\t\tif (n\
    \ == 0) \r\n\t\t\treturn 0;\r\n\t\tvector<Point<int>> v(n);\r\n\t\tfor (int i\
    \ = 0; i < n; i++)\r\n\t\t\tcin >> v[i].x >> v[i].y;\r\n\t\tauto hull = convex_hull(v);\r\
    \n\t\tcout << (int)hull.size() << '\\n';       \r\n\t\tfor (auto &p : hull)\r\n\
    \t\t\tcout << p.x << \" \" << p.y << '\\n';\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/problems/convexhull\"\r\n\r\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/geometry/convex-hull.hpp\"\
    \r\n\r\n// kattis verified\r\nint main() {\r\n\tusing namespace std;\r\n\tusing\
    \ namespace ConvexHull;\r\n\tios_base::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\twhile (true) {\r\n\t\tint n; cin >> n;\r\n\t\tif (n == 0) \r\n\t\t\treturn\
    \ 0;\r\n\t\tvector<Point<int>> v(n);\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\
    \tcin >> v[i].x >> v[i].y;\r\n\t\tauto hull = convex_hull(v);\r\n\t\tcout << (int)hull.size()\
    \ << '\\n';       \r\n\t\tfor (auto &p : hull)\r\n\t\t\tcout << p.x << \" \" <<\
    \ p.y << '\\n';\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/geometry/convex-hull.hpp
  - library/geometry/point.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-convexhull.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-convexhull.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-convexhull.test.cpp
- /verify/verify/kattis/kattis-convexhull.test.cpp.html
title: verify/kattis/kattis-convexhull.test.cpp
---
