---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#define PROBLEM \"https://open.kattis.com/problems/convexhull\"\n\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n\ntemplate <typename T> struct Point {\npublic:\n\tT x, y;\n\tPoint() : x(0),\
    \ y(0) {}\n\tPoint(T x_, T y_) : x(x_), y(y_) {}\n\ttemplate <typename U> explicit\
    \ Point(const Point<U>& p) : x(p.x), y(p.y) {}\n\tPoint(const std::pair<T, T>&\
    \ p) : x(p.first), y(p.second) {}\n\tPoint(const std::complex<T>& p) : x(real(p)),\
    \ y(imag(p)) {}\n\texplicit operator std::pair<T, T>() const { return std::pair<T,\
    \ T>(x, y); }\n\texplicit operator std::complex<T>() const { return std::complex<T>(x,\
    \ y); }\n\n\tfriend std::ostream& operator<<(std::ostream &o, const Point& p)\
    \ { \n\t\treturn o << '(' << p.x << ',' << p.y << ')'; }\n\tfriend std::istream&\
    \ operator>>(std::istream &i, Point& p) { return i >> p.x >> p.y; }\n\tfriend\
    \ bool operator==(const Point& a, const Point& b) { return a.x == b.x && a.y ==\
    \ b.y; }\n\tfriend bool operator!=(const Point& a, const Point& b) { return !(a\
    \ == b); }\n\tfriend bool operator<(const Point& a, const Point& b) { \n\t\treturn\
    \ (a.x != b.x ? a.x < b.x : a.y < b.y); }\n\n\tfriend T norm(const Point& a) {\
    \ return a.x * a.x + a.y * a.y; }\n\tfriend T abs(const Point& p) { return std::hypot(p.x,\
    \ p.y); }\n\tfriend T unit(const Point& a) { if (a == Point()) return a; return\
    \ a / abs(a); }\n\tfriend Point conj(const Point& a) { return Point(a.x, -a.y);\
    \ }\n\tfriend Point perp(const Point& a) { return Point(-a.y, a.x); }\n\tfriend\
    \ long double arg(const Point& p) { return atan2(p.y, p.x); }\n\tfriend Point\
    \ dir(long double angle) { return Point(cos(angle), sin(angle)); }\n\n\tPoint&\
    \ operator+=(const Point& p) { x += p.x, y += p.y; return *this; }\n\tPoint& operator-=(const\
    \ Point& p) { x -= p.x, y -= p.y; return *this; }\n\tPoint& operator*=(const T\
    \ &t) { x *= t, y *= t; return *this; }\n\tPoint& operator/=(const T &t) { x /=\
    \ t, y /= t; return *this; }\n\tPoint& operator*=(const Point& t) { \n\t\tPoint\
    \ res = Point(x, y) * t; x = res.x, y = res.y; return *this; }\n\tPoint& operator/=(const\
    \ Point& t) { \n\t\tPoint res = Point(x, y) / t; x = res.x, y = res.y; return\
    \ *this; }\n\n\tfriend Point operator+(const Point& a, const Point& b) { return\
    \ Point(a.x + b.x, a.y + b.y); }\n\tfriend Point operator-(const Point& a, const\
    \ Point& b) { return Point(a.x - b.x, a.y - b.y); }\n\tfriend Point operator*(const\
    \ Point& a, const T &t) { return Point(a.x * t, a.y * t); }\n\tfriend Point operator*(const\
    \ T &t ,const Point& a) { return Point(t * a.x, t * a.y); }\n\tfriend Point operator/(const\
    \ Point& a, const T &t) { return Point(a.x / t, a.y / t); }\n\tfriend Point operator*(const\
    \ Point& a, const Point& b) { \n\t\treturn Point(a.x * b.x - a.y * b.y, a.y *\
    \ b.x + a.x * b.y); }\n\tfriend Point operator/(const Point& a, const Point& b)\
    \ { \n\t\treturn Point(a * conj(b) / norm(b)); }\n\n\tfriend T int_norm(const\
    \ Point& a) { return __gcd(a.x, a.y); }\n\tfriend T int_unit(const Point& a) {\
    \ if (a == Point()) return a; return a / int_norm(a); }\n\n\tfriend T cross(const\
    \ Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }\n\tfriend T dot(const\
    \ Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }\n\tfriend T area(const\
    \ Point& a, const Point& b, const Point& c) { return cross(b - a, c - a); }\n\n\
    \t// Returns conj(a) * b\n\tfriend Point rotation(const Point& a, const Point&\
    \ b) { return Point(dot(a, b), cross(a, b)); }\n\n\tfriend bool same_dir(const\
    \ Point& a, const Point& b) { return cross(a, b) == 0 && dot(a, b) > 0; }\n\n\t\
    // check if 180 <= s..t < 360\n\tfriend bool is_reflex(const Point& a, const Point&\
    \ b) { \n\t\tauto c = cross(a, b); return c ? (c < 0) : (dot(a, b) < 0); }\n\n\
    \t// operator < (s, t) for angles in [base, base+2pi)\n\tfriend bool angle_less(const\
    \ Point& base, const Point& s, const Point& t) {\n\t\tint r = is_reflex(base,\
    \ s) - is_reflex(base, t);\n\t\treturn r ? (r < 0) : (0 < cross(s, t));\n\t}\n\
    \n\tfriend bool angle_cmp(const Point& base) {\n\t\treturn [base](const Point&\
    \ s, const Point& t) { return angle_less(base, s, t); };\n\t}\n\tfriend bool angle_cmp_center(const\
    \ Point& center, const Point& dir) {\n\t\treturn [center, dir](const Point& s,\
    \ const Point& t) -> bool { \n\t\t\treturn angle_less(dir, s - center, t - center);\
    \ };\n\t}\n\n\t// is p in [s,t] taken ccw? 1/0/-1 for in/border/out\n\tfriend\
    \ int angle_between(const Point& s, const Point& t, const Point& p) {\n\t\tif\
    \ (same_dir(p, s) || same_dir(p, t)) return 0;\n\t\treturn angle_less(s, p, t)\
    \ ? 1 : -1;\n\t}\n};\n\nnamespace ConvexHull {\n\ntemplate <class T>\nstd::pair<std::vector<int>,\
    \ std::vector<int>> upper_lower_hull(const std::vector<Point<T>>& v) {\n\tstd::vector<int>\
    \ p((int)v.size()), upper, lower;\n\tiota(p.begin(), p.end(), 0);\n\tsort(p.begin(),\
    \ p.end(), [&v](int a, int b) { return v[a] < v[b]; });\n\tfor (int i : p) {\n\
    \t\twhile ((int)upper.size() > 1 && \n\t\t\tarea(v[upper[(int)upper.size() - 2]],\
    \ v[upper.back()], v[i]) >= 0) \n\t\t\tupper.pop_back();\n\t\tupper.push_back(i);\n\
    \t\twhile ((int)lower.size() > 1 && \n\t\t\tarea(v[lower[(int)lower.size() - 2]],\
    \ v[lower.back()], v[i]) <= 0) \n\t\t\tlower.pop_back();\n\t\tlower.push_back(i);\n\
    \t}\n\treturn {upper, lower};\n}\n\ntemplate <class T> std::vector<int> hull_index(const\
    \ std::vector<Point<T>>& v) {\n\tstd::vector<int> upper, lower;\n\ttie(upper,\
    \ lower) = upper_lower_hull(v);\n\tif ((int)lower.size() <= 1) \n\t\treturn lower;\n\
    \tif (v[lower[0]] == v[lower[1]])\n\t\treturn {0};\n\tlower.insert(lower.end(),\
    \ 1 + upper.rbegin(), upper.rend() - 1);\n\treturn lower;\n}\n\ntemplate <class\
    \ T> std::vector<Point<T>> convex_hull(const std::vector<Point<T>>& v) {\n\tstd::vector<int>\
    \ w = hull_index(v);\n\tstd::vector<Point<T>> res;\n\tfor (auto& t : w)\n\t\t\
    res.push_back(v[t]);\n\treturn res;\n}\n\n} // ConvexHull\n\n// kattis verified\n\
    int main() {\n\tusing namespace std;\n\tusing namespace ConvexHull;\n\tios_base::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\twhile (true) {\n\t\tint n; cin >> n;\n\t\tif (n == 0) \n\
    \t\t\treturn 0;\n\t\tvector<Point<int>> v(n);\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t\tcin >> v[i].x >> v[i].y;\n\t\tauto hull = convex_hull(v);\n\t\tcout << (int)hull.size()\
    \ << '\\n';       \n\t\tfor (auto &p : hull)\n\t\t\tcout << p.x << \" \" << p.y\
    \ << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/problems/convexhull\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/geometry/convex-hull.hpp\"\
    \n\n// kattis verified\nint main() {\n\tusing namespace std;\n\tusing namespace\
    \ ConvexHull;\n\tios_base::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\twhile\
    \ (true) {\n\t\tint n; cin >> n;\n\t\tif (n == 0) \n\t\t\treturn 0;\n\t\tvector<Point<int>>\
    \ v(n);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tcin >> v[i].x >> v[i].y;\n\t\t\
    auto hull = convex_hull(v);\n\t\tcout << (int)hull.size() << '\\n';       \n\t\
    \tfor (auto &p : hull)\n\t\t\tcout << p.x << \" \" << p.y << '\\n';\n\t}\n\treturn\
    \ 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/geometry/convex-hull.hpp
  - library/geometry/point.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-convexhull.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 13:21:48-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-convexhull.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-convexhull.test.cpp
- /verify/verify/kattis/kattis-convexhull.test.cpp.html
title: verify/kattis/kattis-convexhull.test.cpp
---
