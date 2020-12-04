---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/geometry/convex_hull.cpp\"\n#include <bits/stdc++.h>\r\
    \n\r\ntemplate <typename T> struct Point {\r\npublic:\r\n    T x, y;\r\n    Point()\
    \ : x(0), y(0) {}\r\n    Point(T x_, T y_) : x(x_), y(y_) {}\r\n    template <typename\
    \ U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}\r\n    Point(const\
    \ std::pair<T, T>& p) : x(p.first), y(p.second) {}\r\n    Point(const std::complex<T>&\
    \ p) : x(real(p)), y(imag(p)) {}\r\n    explicit operator std::pair<T, T> () const\
    \ { return std::pair<T, T>(x, y); }\r\n    explicit operator std::complex<T> ()\
    \ const { return std::complex<T>(x, y); }\r\n\r\n    friend std::ostream& operator\
    \ << (std::ostream& o, const Point& p) { \r\n        return o << '(' << p.x <<\
    \ ',' << p.y << ')'; }\r\n    friend std::istream& operator >> (std::istream&\
    \ i, Point& p) { return i >> p.x >> p.y; }\r\n    friend bool operator == (const\
    \ Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }\r\n    friend\
    \ bool operator != (const Point& a, const Point& b) { return !(a == b); }\r\n\
    \    friend bool operator < (const Point& a, const Point& b) { \r\n        return\
    \ (a.x != b.x ? a.x < b.x : a.y < b.y); }\r\n\r\n    friend T norm(const Point&\
    \ a) { return a.x * a.x + a.y * a.y; }\r\n    friend T abs(const Point& p) { return\
    \ std::hypot(p.x, p.y); }\r\n    friend T unit(const Point& a) { if (a == Point())\
    \ return a; return a / abs(a); }\r\n    friend Point conj(const Point& a) { return\
    \ Point(a.x, -a.y); }\r\n    friend Point perp(const Point& a) { return Point(-a.y,\
    \ a.x); }\r\n    friend long double arg(const Point& p) { return atan2(p.y, p.x);\
    \ }\r\n    friend Point dir(long double angle) { return Point(cos(angle), sin(angle));\
    \ }\r\n\r\n    Point& operator += (const Point& p) { x += p.x, y += p.y; return\
    \ *this; }\r\n    Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return\
    \ *this; }\r\n    Point& operator *= (const T& t) { x *= t, y *= t; return *this;\
    \ }\r\n    Point& operator /= (const T& t) { x /= t, y /= t; return *this; }\r\
    \n    Point& operator *= (const Point& t) { \r\n        Point res = Point(x, y)\
    \ * t; x = res.x, y = res.y; return *this; }\r\n    Point& operator /= (const\
    \ Point& t) { \r\n        Point res = Point(x, y) / t; x = res.x, y = res.y; return\
    \ *this; }\r\n\r\n    friend Point operator + (const Point& a, const Point& b)\
    \ { return Point(a.x + b.x, a.y + b.y); }\r\n    friend Point operator - (const\
    \ Point& a, const Point& b) { return Point(a.x - b.x, a.y - b.y); }\r\n    friend\
    \ Point operator * (const Point& a, const T& t) { return Point(a.x * t, a.y *\
    \ t); }\r\n    friend Point operator * (const T& t ,const Point& a) { return Point(t\
    \ * a.x, t * a.y); }\r\n    friend Point operator / (const Point& a, const T&\
    \ t) { return Point(a.x / t, a.y / t); }\r\n    friend Point operator * (const\
    \ Point& a, const Point& b) { \r\n        return Point(a.x * b.x - a.y * b.y,\
    \ a.y * b.x + a.x * b.y); }\r\n    friend Point operator / (const Point& a, const\
    \ Point& b) { \r\n        return Point(a * conj(b) / norm(b)); }\r\n\r\n    friend\
    \ T int_norm(const Point& a) { return __gcd(a.x, a.y); }\r\n    friend T int_unit(const\
    \ Point& a) { if (a == Point()) return a; return a / int_norm(a); }\r\n\r\n  \
    \  friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x;\
    \ }\r\n    friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y\
    \ * b.y; }\r\n    friend T area(const Point& a, const Point& b, const Point& c)\
    \ { return cross(b - a, c - a); }\r\n\r\n    // Returns conj(a) * b\r\n    friend\
    \ Point rotation(const Point& a, const Point& b) { return Point(dot(a, b), cross(a,\
    \ b)); }\r\n\r\n    friend bool same_dir(const Point& a, const Point& b) { return\
    \ cross(a, b) == 0 && dot(a, b) > 0; }\r\n\r\n    // check if 180 <= s..t < 360\r\
    \n    friend bool is_reflex(const Point& a, const Point& b) { \r\n        auto\
    \ c = cross(a, b); return c ? (c < 0) : (dot(a, b) < 0); }\r\n\r\n    // operator\
    \ < (s, t) for angles in [base, base+2pi)\r\n    friend bool angle_less(const\
    \ Point& base, const Point& s, const Point& t) {\r\n        int r = is_reflex(base,\
    \ s) - is_reflex(base, t);\r\n        return r ? (r < 0) : (0 < cross(s, t));\r\
    \n    }\r\n\r\n    friend bool angle_cmp(const Point& base) {\r\n        return\
    \ [base](const Point& s, const Point& t) { return angle_less(base, s, t); };\r\
    \n    }\r\n    friend bool angle_cmp_center(const Point& center, const Point&\
    \ dir) {\r\n        return [center, dir](const Point& s, const Point& t) -> bool\
    \ { \r\n            return angle_less(dir, s - center, t - center); };\r\n   \
    \ }\r\n\r\n    // is p in [s,t] taken ccw? 1/0/-1 for in/border/out\r\n    friend\
    \ int angle_between(const Point& s, const Point& t, const Point& p) {\r\n    \
    \    if (same_dir(p, s) || same_dir(p, t)) return 0;\r\n        return angle_less(s,\
    \ p, t) ? 1 : -1;\r\n    }\r\n};\r\n\r\nnamespace ConvexHull {\r\n\r\ntemplate\
    \ <class T>\r\nstd::pair<std::vector<int>, std::vector<int>> upper_lower_hull(const\
    \ std::vector<Point<T>>& v) {\r\n    std::vector<int> p((int) v.size()), upper,\
    \ lower;\r\n    iota(p.begin(), p.end(), 0);\r\n    sort(p.begin(), p.end(), [&v](int\
    \ a, int b) { return v[a] < v[b]; });\r\n    for (int& i : p) {\r\n        while\
    \ ((int) upper.size() > 1 && \r\n            area(v[upper[(int) upper.size() -\
    \ 2]], v[upper.back()], v[i]) >= 0) \r\n            upper.pop_back();\r\n    \
    \    upper.push_back(i);\r\n        while ((int) lower.size() > 1 && \r\n    \
    \        area(v[lower[(int) lower.size() - 2]], v[lower.back()], v[i]) <= 0) \r\
    \n            lower.pop_back();\r\n        lower.push_back(i);\r\n    }\r\n  \
    \  return {upper, lower};\r\n}\r\ntemplate <class T> std::vector<int> hull_index(const\
    \ std::vector<Point<T>>& v) {\r\n    std::vector<int> upper, lower;\r\n    tie(upper,\
    \ lower) = upper_lower_hull(v);\r\n    if ((int) lower.size() <= 1) \r\n     \
    \   return lower;\r\n    if (v[lower[0]] == v[lower[1]])\r\n        return {0};\r\
    \n    lower.insert(lower.end(), 1 + upper.rbegin(), upper.rend() - 1);\r\n   \
    \ return lower;\r\n}\r\ntemplate <class T> std::vector<Point<T>> convex_hull(const\
    \ std::vector<Point<T>>& v) {\r\n    std::vector<int> w = hull_index(v);\r\n \
    \   std::vector<Point<T>> res;\r\n    for (auto& t : w)\r\n        res.push_back(v[t]);\r\
    \n    return res;\r\n}\r\n\r\n} // ConvexHull\r\n\r\nint main() {\r\n    using\
    \ namespace std;\r\n    using namespace ConvexHull;\r\n    ios_base::sync_with_stdio(0);\r\
    \n    while (true) {\r\n        int n; cin >> n;\r\n        if (n == 0) \r\n \
    \           return 0;\r\n        vector<Point<int>> v(n);\r\n        for (int\
    \ i = 0; i < n; i++)\r\n            cin >> v[i].x >> v[i].y;\r\n        auto hull\
    \ = convex_hull(v);\r\n        cout << (int) hull.size() << '\\n';       \r\n\
    \        for (auto& p : hull)\r\n            cout << p.x << \" \" << p.y << '\\\
    n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\n\r\ntemplate <typename T> struct Point {\r\n\
    public:\r\n    T x, y;\r\n    Point() : x(0), y(0) {}\r\n    Point(T x_, T y_)\
    \ : x(x_), y(y_) {}\r\n    template <typename U> explicit Point(const Point<U>&\
    \ p) : x(p.x), y(p.y) {}\r\n    Point(const std::pair<T, T>& p) : x(p.first),\
    \ y(p.second) {}\r\n    Point(const std::complex<T>& p) : x(real(p)), y(imag(p))\
    \ {}\r\n    explicit operator std::pair<T, T> () const { return std::pair<T, T>(x,\
    \ y); }\r\n    explicit operator std::complex<T> () const { return std::complex<T>(x,\
    \ y); }\r\n\r\n    friend std::ostream& operator << (std::ostream& o, const Point&\
    \ p) { \r\n        return o << '(' << p.x << ',' << p.y << ')'; }\r\n    friend\
    \ std::istream& operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y;\
    \ }\r\n    friend bool operator == (const Point& a, const Point& b) { return a.x\
    \ == b.x && a.y == b.y; }\r\n    friend bool operator != (const Point& a, const\
    \ Point& b) { return !(a == b); }\r\n    friend bool operator < (const Point&\
    \ a, const Point& b) { \r\n        return (a.x != b.x ? a.x < b.x : a.y < b.y);\
    \ }\r\n\r\n    friend T norm(const Point& a) { return a.x * a.x + a.y * a.y; }\r\
    \n    friend T abs(const Point& p) { return std::hypot(p.x, p.y); }\r\n    friend\
    \ T unit(const Point& a) { if (a == Point()) return a; return a / abs(a); }\r\n\
    \    friend Point conj(const Point& a) { return Point(a.x, -a.y); }\r\n    friend\
    \ Point perp(const Point& a) { return Point(-a.y, a.x); }\r\n    friend long double\
    \ arg(const Point& p) { return atan2(p.y, p.x); }\r\n    friend Point dir(long\
    \ double angle) { return Point(cos(angle), sin(angle)); }\r\n\r\n    Point& operator\
    \ += (const Point& p) { x += p.x, y += p.y; return *this; }\r\n    Point& operator\
    \ -= (const Point& p) { x -= p.x, y -= p.y; return *this; }\r\n    Point& operator\
    \ *= (const T& t) { x *= t, y *= t; return *this; }\r\n    Point& operator /=\
    \ (const T& t) { x /= t, y /= t; return *this; }\r\n    Point& operator *= (const\
    \ Point& t) { \r\n        Point res = Point(x, y) * t; x = res.x, y = res.y; return\
    \ *this; }\r\n    Point& operator /= (const Point& t) { \r\n        Point res\
    \ = Point(x, y) / t; x = res.x, y = res.y; return *this; }\r\n\r\n    friend Point\
    \ operator + (const Point& a, const Point& b) { return Point(a.x + b.x, a.y +\
    \ b.y); }\r\n    friend Point operator - (const Point& a, const Point& b) { return\
    \ Point(a.x - b.x, a.y - b.y); }\r\n    friend Point operator * (const Point&\
    \ a, const T& t) { return Point(a.x * t, a.y * t); }\r\n    friend Point operator\
    \ * (const T& t ,const Point& a) { return Point(t * a.x, t * a.y); }\r\n    friend\
    \ Point operator / (const Point& a, const T& t) { return Point(a.x / t, a.y /\
    \ t); }\r\n    friend Point operator * (const Point& a, const Point& b) { \r\n\
    \        return Point(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y); }\r\n   \
    \ friend Point operator / (const Point& a, const Point& b) { \r\n        return\
    \ Point(a * conj(b) / norm(b)); }\r\n\r\n    friend T int_norm(const Point& a)\
    \ { return __gcd(a.x, a.y); }\r\n    friend T int_unit(const Point& a) { if (a\
    \ == Point()) return a; return a / int_norm(a); }\r\n\r\n    friend T cross(const\
    \ Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }\r\n    friend T\
    \ dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }\r\n  \
    \  friend T area(const Point& a, const Point& b, const Point& c) { return cross(b\
    \ - a, c - a); }\r\n\r\n    // Returns conj(a) * b\r\n    friend Point rotation(const\
    \ Point& a, const Point& b) { return Point(dot(a, b), cross(a, b)); }\r\n\r\n\
    \    friend bool same_dir(const Point& a, const Point& b) { return cross(a, b)\
    \ == 0 && dot(a, b) > 0; }\r\n\r\n    // check if 180 <= s..t < 360\r\n    friend\
    \ bool is_reflex(const Point& a, const Point& b) { \r\n        auto c = cross(a,\
    \ b); return c ? (c < 0) : (dot(a, b) < 0); }\r\n\r\n    // operator < (s, t)\
    \ for angles in [base, base+2pi)\r\n    friend bool angle_less(const Point& base,\
    \ const Point& s, const Point& t) {\r\n        int r = is_reflex(base, s) - is_reflex(base,\
    \ t);\r\n        return r ? (r < 0) : (0 < cross(s, t));\r\n    }\r\n\r\n    friend\
    \ bool angle_cmp(const Point& base) {\r\n        return [base](const Point& s,\
    \ const Point& t) { return angle_less(base, s, t); };\r\n    }\r\n    friend bool\
    \ angle_cmp_center(const Point& center, const Point& dir) {\r\n        return\
    \ [center, dir](const Point& s, const Point& t) -> bool { \r\n            return\
    \ angle_less(dir, s - center, t - center); };\r\n    }\r\n\r\n    // is p in [s,t]\
    \ taken ccw? 1/0/-1 for in/border/out\r\n    friend int angle_between(const Point&\
    \ s, const Point& t, const Point& p) {\r\n        if (same_dir(p, s) || same_dir(p,\
    \ t)) return 0;\r\n        return angle_less(s, p, t) ? 1 : -1;\r\n    }\r\n};\r\
    \n\r\nnamespace ConvexHull {\r\n\r\ntemplate <class T>\r\nstd::pair<std::vector<int>,\
    \ std::vector<int>> upper_lower_hull(const std::vector<Point<T>>& v) {\r\n   \
    \ std::vector<int> p((int) v.size()), upper, lower;\r\n    iota(p.begin(), p.end(),\
    \ 0);\r\n    sort(p.begin(), p.end(), [&v](int a, int b) { return v[a] < v[b];\
    \ });\r\n    for (int& i : p) {\r\n        while ((int) upper.size() > 1 && \r\
    \n            area(v[upper[(int) upper.size() - 2]], v[upper.back()], v[i]) >=\
    \ 0) \r\n            upper.pop_back();\r\n        upper.push_back(i);\r\n    \
    \    while ((int) lower.size() > 1 && \r\n            area(v[lower[(int) lower.size()\
    \ - 2]], v[lower.back()], v[i]) <= 0) \r\n            lower.pop_back();\r\n  \
    \      lower.push_back(i);\r\n    }\r\n    return {upper, lower};\r\n}\r\ntemplate\
    \ <class T> std::vector<int> hull_index(const std::vector<Point<T>>& v) {\r\n\
    \    std::vector<int> upper, lower;\r\n    tie(upper, lower) = upper_lower_hull(v);\r\
    \n    if ((int) lower.size() <= 1) \r\n        return lower;\r\n    if (v[lower[0]]\
    \ == v[lower[1]])\r\n        return {0};\r\n    lower.insert(lower.end(), 1 +\
    \ upper.rbegin(), upper.rend() - 1);\r\n    return lower;\r\n}\r\ntemplate <class\
    \ T> std::vector<Point<T>> convex_hull(const std::vector<Point<T>>& v) {\r\n \
    \   std::vector<int> w = hull_index(v);\r\n    std::vector<Point<T>> res;\r\n\
    \    for (auto& t : w)\r\n        res.push_back(v[t]);\r\n    return res;\r\n\
    }\r\n\r\n} // ConvexHull\r\n\r\nint main() {\r\n    using namespace std;\r\n \
    \   using namespace ConvexHull;\r\n    ios_base::sync_with_stdio(0);\r\n    while\
    \ (true) {\r\n        int n; cin >> n;\r\n        if (n == 0) \r\n           \
    \ return 0;\r\n        vector<Point<int>> v(n);\r\n        for (int i = 0; i <\
    \ n; i++)\r\n            cin >> v[i].x >> v[i].y;\r\n        auto hull = convex_hull(v);\r\
    \n        cout << (int) hull.size() << '\\n';       \r\n        for (auto& p :\
    \ hull)\r\n            cout << p.x << \" \" << p.y << '\\n';\r\n    }\r\n    return\
    \ 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/convex_hull.cpp
  requiredBy: []
  timestamp: '2020-12-03 10:39:41-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/convex_hull.cpp
layout: document
redirect_from:
- /library/library/geometry/convex_hull.cpp
- /library/library/geometry/convex_hull.cpp.html
title: library/geometry/convex_hull.cpp
---
