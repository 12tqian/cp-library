---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/geometry/convex_hull.cpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <typename T> struct Point {\npublic:\n    T x, y;\n    Point() : x(0),\
    \ y(0) {}\n    Point(T x_, T y_) : x(x_), y(y_) {}\n    template <typename U>\
    \ explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}\n    Point(const std::pair<T,\
    \ T>& p) : x(p.first), y(p.second) {}\n    Point(const std::complex<T>& p) : x(real(p)),\
    \ y(imag(p)) {}\n    explicit operator std::pair<T, T> () const { return std::pair<T,\
    \ T>(x, y); }\n    explicit operator std::complex<T> () const { return std::complex<T>(x,\
    \ y); }\n\n    friend std::ostream& operator << (std::ostream& o, const Point&\
    \ p) { \n        return o << '(' << p.x << ',' << p.y << ')'; }\n    friend std::istream&\
    \ operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }\n    friend\
    \ bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y\
    \ == b.y; }\n    friend bool operator != (const Point& a, const Point& b) { return\
    \ !(a == b); }\n    friend bool operator < (const Point& a, const Point& b) {\
    \ \n        return (a.x != b.x ? a.x < b.x : a.y < b.y); }\n\n    friend T norm(const\
    \ Point& a) { return a.x * a.x + a.y * a.y; }\n    friend T abs(const Point& p)\
    \ { return std::hypot(p.x, p.y); }\n    friend T unit(const Point& a) { if (a\
    \ == Point()) return a; return a / abs(a); }\n    friend Point conj(const Point&\
    \ a) { return Point(a.x, -a.y); }\n    friend Point perp(const Point& a) { return\
    \ Point(-a.y, a.x); }\n    friend long double arg(const Point& p) { return atan2(p.y,\
    \ p.x); }\n    friend Point dir(long double angle) { return Point(cos(angle),\
    \ sin(angle)); }\n\n    Point& operator += (const Point& p) { x += p.x, y += p.y;\
    \ return *this; }\n    Point& operator -= (const Point& p) { x -= p.x, y -= p.y;\
    \ return *this; }\n    Point& operator *= (const T& t) { x *= t, y *= t; return\
    \ *this; }\n    Point& operator /= (const T& t) { x /= t, y /= t; return *this;\
    \ }\n    Point& operator *= (const Point& t) { \n        Point res = Point(x,\
    \ y) * t; x = res.x, y = res.y; return *this; }\n    Point& operator /= (const\
    \ Point& t) { \n        Point res = Point(x, y) / t; x = res.x, y = res.y; return\
    \ *this; }\n\n    friend Point operator + (const Point& a, const Point& b) { return\
    \ Point(a.x + b.x, a.y + b.y); }\n    friend Point operator - (const Point& a,\
    \ const Point& b) { return Point(a.x - b.x, a.y - b.y); }\n    friend Point operator\
    \ * (const Point& a, const T& t) { return Point(a.x * t, a.y * t); }\n    friend\
    \ Point operator * (const T& t ,const Point& a) { return Point(t * a.x, t * a.y);\
    \ }\n    friend Point operator / (const Point& a, const T& t) { return Point(a.x\
    \ / t, a.y / t); }\n    friend Point operator * (const Point& a, const Point&\
    \ b) { \n        return Point(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y); }\n\
    \    friend Point operator / (const Point& a, const Point& b) { \n        return\
    \ Point(a * conj(b) / norm(b)); }\n\n    friend T int_norm(const Point& a) { return\
    \ __gcd(a.x, a.y); }\n    friend T int_unit(const Point& a) { if (a == Point())\
    \ return a; return a / int_norm(a); }\n\n    friend T cross(const Point& a, const\
    \ Point& b) { return a.x * b.y - a.y * b.x; }\n    friend T dot(const Point& a,\
    \ const Point& b) { return a.x * b.x + a.y * b.y; }\n    friend T area(const Point&\
    \ a, const Point& b, const Point& c) { return cross(b - a, c - a); }\n\n    //\
    \ Returns conj(a) * b\n    friend Point rotation(const Point& a, const Point&\
    \ b) { return Point(dot(a, b), cross(a, b)); }\n\n    friend bool same_dir(const\
    \ Point& a, const Point& b) { return cross(a, b) == 0 && dot(a, b) > 0; }\n\n\
    \    // check if 180 <= s..t < 360\n    friend bool is_reflex(const Point& a,\
    \ const Point& b) { \n        auto c = cross(a, b); return c ? (c < 0) : (dot(a,\
    \ b) < 0); }\n\n    // operator < (s, t) for angles in [base, base+2pi)\n    friend\
    \ bool angle_less(const Point& base, const Point& s, const Point& t) {\n     \
    \   int r = is_reflex(base, s) - is_reflex(base, t);\n        return r ? (r <\
    \ 0) : (0 < cross(s, t));\n    }\n\n    friend bool angle_cmp(const Point& base)\
    \ {\n        return [base](const Point& s, const Point& t) { return angle_less(base,\
    \ s, t); };\n    }\n    friend bool angle_cmp_center(const Point& center, const\
    \ Point& dir) {\n        return [center, dir](const Point& s, const Point& t)\
    \ -> bool { \n            return angle_less(dir, s - center, t - center); };\n\
    \    }\n\n    // is p in [s,t] taken ccw? 1/0/-1 for in/border/out\n    friend\
    \ int angle_between(const Point& s, const Point& t, const Point& p) {\n      \
    \  if (same_dir(p, s) || same_dir(p, t)) return 0;\n        return angle_less(s,\
    \ p, t) ? 1 : -1;\n    }\n};\n\nnamespace ConvexHull {\n\ntemplate <class T>\n\
    std::pair<std::vector<int>, std::vector<int>> upper_lower_hull(const std::vector<Point<T>>&\
    \ v) {\n    std::vector<int> p((int) v.size()), upper, lower;\n    iota(p.begin(),\
    \ p.end(), 0);\n    sort(p.begin(), p.end(), [&v](int a, int b) { return v[a]\
    \ < v[b]; });\n    for (int& i : p) {\n        while ((int) upper.size() > 1 &&\
    \ \n            area(v[upper[(int) upper.size() - 2]], v[upper.back()], v[i])\
    \ >= 0) \n            upper.pop_back();\n        upper.push_back(i);\n       \
    \ while ((int) lower.size() > 1 && \n            area(v[lower[(int) lower.size()\
    \ - 2]], v[lower.back()], v[i]) <= 0) \n            lower.pop_back();\n      \
    \  lower.push_back(i);\n    }\n    return {upper, lower};\n}\n\ntemplate <class\
    \ T> std::vector<int> hull_index(const std::vector<Point<T>>& v) {\n    std::vector<int>\
    \ upper, lower;\n    tie(upper, lower) = upper_lower_hull(v);\n    if ((int) lower.size()\
    \ <= 1) \n        return lower;\n    if (v[lower[0]] == v[lower[1]])\n       \
    \ return {0};\n    lower.insert(lower.end(), 1 + upper.rbegin(), upper.rend()\
    \ - 1);\n    return lower;\n}\n\ntemplate <class T> std::vector<Point<T>> convex_hull(const\
    \ std::vector<Point<T>>& v) {\n    std::vector<int> w = hull_index(v);\n    std::vector<Point<T>>\
    \ res;\n    for (auto& t : w)\n        res.push_back(v[t]);\n    return res;\n\
    }\n\n} // ConvexHull\n\nint main() {\n    using namespace std;\n    using namespace\
    \ ConvexHull;\n    ios_base::sync_with_stdio(0);\n    while (true) {\n       \
    \ int n; cin >> n;\n        if (n == 0) \n            return 0;\n        vector<Point<int>>\
    \ v(n);\n        for (int i = 0; i < n; i++)\n            cin >> v[i].x >> v[i].y;\n\
    \        auto hull = convex_hull(v);\n        cout << (int) hull.size() << '\\\
    n';       \n        for (auto& p : hull)\n            cout << p.x << \" \" <<\
    \ p.y << '\\n';\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <typename T> struct Point {\npublic:\n\
    \    T x, y;\n    Point() : x(0), y(0) {}\n    Point(T x_, T y_) : x(x_), y(y_)\
    \ {}\n    template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y)\
    \ {}\n    Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}\n    Point(const\
    \ std::complex<T>& p) : x(real(p)), y(imag(p)) {}\n    explicit operator std::pair<T,\
    \ T> () const { return std::pair<T, T>(x, y); }\n    explicit operator std::complex<T>\
    \ () const { return std::complex<T>(x, y); }\n\n    friend std::ostream& operator\
    \ << (std::ostream& o, const Point& p) { \n        return o << '(' << p.x << ','\
    \ << p.y << ')'; }\n    friend std::istream& operator >> (std::istream& i, Point&\
    \ p) { return i >> p.x >> p.y; }\n    friend bool operator == (const Point& a,\
    \ const Point& b) { return a.x == b.x && a.y == b.y; }\n    friend bool operator\
    \ != (const Point& a, const Point& b) { return !(a == b); }\n    friend bool operator\
    \ < (const Point& a, const Point& b) { \n        return (a.x != b.x ? a.x < b.x\
    \ : a.y < b.y); }\n\n    friend T norm(const Point& a) { return a.x * a.x + a.y\
    \ * a.y; }\n    friend T abs(const Point& p) { return std::hypot(p.x, p.y); }\n\
    \    friend T unit(const Point& a) { if (a == Point()) return a; return a / abs(a);\
    \ }\n    friend Point conj(const Point& a) { return Point(a.x, -a.y); }\n    friend\
    \ Point perp(const Point& a) { return Point(-a.y, a.x); }\n    friend long double\
    \ arg(const Point& p) { return atan2(p.y, p.x); }\n    friend Point dir(long double\
    \ angle) { return Point(cos(angle), sin(angle)); }\n\n    Point& operator += (const\
    \ Point& p) { x += p.x, y += p.y; return *this; }\n    Point& operator -= (const\
    \ Point& p) { x -= p.x, y -= p.y; return *this; }\n    Point& operator *= (const\
    \ T& t) { x *= t, y *= t; return *this; }\n    Point& operator /= (const T& t)\
    \ { x /= t, y /= t; return *this; }\n    Point& operator *= (const Point& t) {\
    \ \n        Point res = Point(x, y) * t; x = res.x, y = res.y; return *this; }\n\
    \    Point& operator /= (const Point& t) { \n        Point res = Point(x, y) /\
    \ t; x = res.x, y = res.y; return *this; }\n\n    friend Point operator + (const\
    \ Point& a, const Point& b) { return Point(a.x + b.x, a.y + b.y); }\n    friend\
    \ Point operator - (const Point& a, const Point& b) { return Point(a.x - b.x,\
    \ a.y - b.y); }\n    friend Point operator * (const Point& a, const T& t) { return\
    \ Point(a.x * t, a.y * t); }\n    friend Point operator * (const T& t ,const Point&\
    \ a) { return Point(t * a.x, t * a.y); }\n    friend Point operator / (const Point&\
    \ a, const T& t) { return Point(a.x / t, a.y / t); }\n    friend Point operator\
    \ * (const Point& a, const Point& b) { \n        return Point(a.x * b.x - a.y\
    \ * b.y, a.y * b.x + a.x * b.y); }\n    friend Point operator / (const Point&\
    \ a, const Point& b) { \n        return Point(a * conj(b) / norm(b)); }\n\n  \
    \  friend T int_norm(const Point& a) { return __gcd(a.x, a.y); }\n    friend T\
    \ int_unit(const Point& a) { if (a == Point()) return a; return a / int_norm(a);\
    \ }\n\n    friend T cross(const Point& a, const Point& b) { return a.x * b.y -\
    \ a.y * b.x; }\n    friend T dot(const Point& a, const Point& b) { return a.x\
    \ * b.x + a.y * b.y; }\n    friend T area(const Point& a, const Point& b, const\
    \ Point& c) { return cross(b - a, c - a); }\n\n    // Returns conj(a) * b\n  \
    \  friend Point rotation(const Point& a, const Point& b) { return Point(dot(a,\
    \ b), cross(a, b)); }\n\n    friend bool same_dir(const Point& a, const Point&\
    \ b) { return cross(a, b) == 0 && dot(a, b) > 0; }\n\n    // check if 180 <= s..t\
    \ < 360\n    friend bool is_reflex(const Point& a, const Point& b) { \n      \
    \  auto c = cross(a, b); return c ? (c < 0) : (dot(a, b) < 0); }\n\n    // operator\
    \ < (s, t) for angles in [base, base+2pi)\n    friend bool angle_less(const Point&\
    \ base, const Point& s, const Point& t) {\n        int r = is_reflex(base, s)\
    \ - is_reflex(base, t);\n        return r ? (r < 0) : (0 < cross(s, t));\n   \
    \ }\n\n    friend bool angle_cmp(const Point& base) {\n        return [base](const\
    \ Point& s, const Point& t) { return angle_less(base, s, t); };\n    }\n    friend\
    \ bool angle_cmp_center(const Point& center, const Point& dir) {\n        return\
    \ [center, dir](const Point& s, const Point& t) -> bool { \n            return\
    \ angle_less(dir, s - center, t - center); };\n    }\n\n    // is p in [s,t] taken\
    \ ccw? 1/0/-1 for in/border/out\n    friend int angle_between(const Point& s,\
    \ const Point& t, const Point& p) {\n        if (same_dir(p, s) || same_dir(p,\
    \ t)) return 0;\n        return angle_less(s, p, t) ? 1 : -1;\n    }\n};\n\nnamespace\
    \ ConvexHull {\n\ntemplate <class T>\nstd::pair<std::vector<int>, std::vector<int>>\
    \ upper_lower_hull(const std::vector<Point<T>>& v) {\n    std::vector<int> p((int)\
    \ v.size()), upper, lower;\n    iota(p.begin(), p.end(), 0);\n    sort(p.begin(),\
    \ p.end(), [&v](int a, int b) { return v[a] < v[b]; });\n    for (int& i : p)\
    \ {\n        while ((int) upper.size() > 1 && \n            area(v[upper[(int)\
    \ upper.size() - 2]], v[upper.back()], v[i]) >= 0) \n            upper.pop_back();\n\
    \        upper.push_back(i);\n        while ((int) lower.size() > 1 && \n    \
    \        area(v[lower[(int) lower.size() - 2]], v[lower.back()], v[i]) <= 0) \n\
    \            lower.pop_back();\n        lower.push_back(i);\n    }\n    return\
    \ {upper, lower};\n}\n\ntemplate <class T> std::vector<int> hull_index(const std::vector<Point<T>>&\
    \ v) {\n    std::vector<int> upper, lower;\n    tie(upper, lower) = upper_lower_hull(v);\n\
    \    if ((int) lower.size() <= 1) \n        return lower;\n    if (v[lower[0]]\
    \ == v[lower[1]])\n        return {0};\n    lower.insert(lower.end(), 1 + upper.rbegin(),\
    \ upper.rend() - 1);\n    return lower;\n}\n\ntemplate <class T> std::vector<Point<T>>\
    \ convex_hull(const std::vector<Point<T>>& v) {\n    std::vector<int> w = hull_index(v);\n\
    \    std::vector<Point<T>> res;\n    for (auto& t : w)\n        res.push_back(v[t]);\n\
    \    return res;\n}\n\n} // ConvexHull\n\nint main() {\n    using namespace std;\n\
    \    using namespace ConvexHull;\n    ios_base::sync_with_stdio(0);\n    while\
    \ (true) {\n        int n; cin >> n;\n        if (n == 0) \n            return\
    \ 0;\n        vector<Point<int>> v(n);\n        for (int i = 0; i < n; i++)\n\
    \            cin >> v[i].x >> v[i].y;\n        auto hull = convex_hull(v);\n \
    \       cout << (int) hull.size() << '\\n';       \n        for (auto& p : hull)\n\
    \            cout << p.x << \" \" << p.y << '\\n';\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/convex_hull.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/convex_hull.cpp
layout: document
redirect_from:
- /library/library/geometry/convex_hull.cpp
- /library/library/geometry/convex_hull.cpp.html
title: library/geometry/convex_hull.cpp
---
