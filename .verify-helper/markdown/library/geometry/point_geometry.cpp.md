---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\geometry\\\\point_geometry.cpp\"\n#include <bits/stdc++.h>\r\
    \ntemplate <typename T> struct Point {\r\npublic:\r\n    T x, y;\r\n    Point()\
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
    \ p, t) ? 1 : -1;\r\n    }\r\n};\r\n\r\nnamespace Geometry2D {\r\n\r\ntemplate\
    \ <class T> int sign(T x) { return (x > 0) - (x < 0); }\r\ntemplate <class T>\
    \ Point<T> reflect(const Point<T>& p, const Point<T>& a, const Point<T>& b) {\r\
    \n        return a + conj((p - a) / (b - a)) * (b - a); }\r\ntemplate <class T>\
    \ Point<T> foot( const Point<T>& p, const Point<T>& a, const Point<T>& b) {\r\n\
    \        return (p + reflect(p, a, b)) / (T) 2; }\r\ntemplate <class T> bool on_segment(Point<T>\
    \ p, Point<T> a, Point<T> b) {\r\n    return area(a, b, p) == 0 && dot(p - a,\
    \ p - b) <= 0; }\r\ntemplate <class T>\r\nstd::vector<Point<T>> segment_intersect(Point<T>\
    \ a, Point<T> b, Point<T> c, Point<T> d) {\r\n    T x = area(a, b, c), y = area(a,\
    \ b, d);\r\n    T X = area(c, d, a), Y = area(c, d, b);\r\n    if (sign(x) * sign(y)\
    \ < 0 && sign(X) * sign(Y) < 0)\r\n        return {(d * x - c * y) / (x - y)};\r\
    \n    std::set<Point<T>> s;\r\n    if (on_segment(a, c, d))\r\n        s.insert(a);\r\
    \n    if (on_segment(b, c, d))\r\n        s.insert(b);\r\n    if (on_segment(c,\
    \ a, b))\r\n        s.insert(c);\r\n    if (on_segment(d, a, b))\r\n        s.insert(d);\r\
    \n    return {s.begin(), s.end()};\r\n}\r\ntemplate <class T> T line_dist(Point<T>\
    \ p, Point<T> a, Point<T> b) {\r\n    return abs(area(p, a, b)) / abs(a - b);\
    \ }\r\ntemplate <class T> T point_segment_dist(Point<T> p, Point<T> a, Point<T>\
    \ b) {\r\n    if (dot(p - a, b - a) <= 0)\r\n        return abs(p - a);\r\n  \
    \  if (dot(p - b, a - b) <= 0)\r\n        return abs(p - b);\r\n    return line_dist(p,\
    \ a, b);\r\n}\r\ntemplate <class T> T segment_segment_dist(Point<T> a, Point<T>\
    \ b, Point<T> c, Point<T> d) {\r\n    std::vector<Point<T>> v = segment_intersect(a,\
    \ b, c, d);\r\n    if (!v.empty())\r\n        return 0;\r\n    return std::min({point_segment_dist(a,\
    \ c, d), point_segment_dist(b, c, d), \r\n        point_segment_dist(c, a, b),\
    \ point_segment_dist(d, a, b)});\r\n}\r\n\r\n} // Geometry2D\r\n\r\nint main()\
    \ {\r\n    using namespace std;\r\n    using namespace Geometry2D;\r\n    typedef\
    \ long double ld;\r\n    typedef Point<long double> P;\r\n    cout << setprecision(2)\
    \ << fixed;\r\n    int n; cin >> n;\r\n    while (n--) {\r\n        ld x1, y1,\
    \ x2, y2, x3, y3, x4, y4;\r\n        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >>\
    \ x4 >> y4;\r\n        ld ans = segment_segment_dist(P(x1, y1), P(x2, y2), P(x3,\
    \ y3), P(x4, y4));\r\n        cout << ans << '\\n';\r\n    }\r\n    return 0;\r\
    \n}\n"
  code: "#include <bits/stdc++.h>\r\ntemplate <typename T> struct Point {\r\npublic:\r\
    \n    T x, y;\r\n    Point() : x(0), y(0) {}\r\n    Point(T x_, T y_) : x(x_),\
    \ y(y_) {}\r\n    template <typename U> explicit Point(const Point<U>& p) : x(p.x),\
    \ y(p.y) {}\r\n    Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}\r\
    \n    Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}\r\n    explicit\
    \ operator std::pair<T, T> () const { return std::pair<T, T>(x, y); }\r\n    explicit\
    \ operator std::complex<T> () const { return std::complex<T>(x, y); }\r\n\r\n\
    \    friend std::ostream& operator << (std::ostream& o, const Point& p) { \r\n\
    \        return o << '(' << p.x << ',' << p.y << ')'; }\r\n    friend std::istream&\
    \ operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }\r\n    friend\
    \ bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y\
    \ == b.y; }\r\n    friend bool operator != (const Point& a, const Point& b) {\
    \ return !(a == b); }\r\n    friend bool operator < (const Point& a, const Point&\
    \ b) { \r\n        return (a.x != b.x ? a.x < b.x : a.y < b.y); }\r\n\r\n    friend\
    \ T norm(const Point& a) { return a.x * a.x + a.y * a.y; }\r\n    friend T abs(const\
    \ Point& p) { return std::hypot(p.x, p.y); }\r\n    friend T unit(const Point&\
    \ a) { if (a == Point()) return a; return a / abs(a); }\r\n    friend Point conj(const\
    \ Point& a) { return Point(a.x, -a.y); }\r\n    friend Point perp(const Point&\
    \ a) { return Point(-a.y, a.x); }\r\n    friend long double arg(const Point& p)\
    \ { return atan2(p.y, p.x); }\r\n    friend Point dir(long double angle) { return\
    \ Point(cos(angle), sin(angle)); }\r\n\r\n    Point& operator += (const Point&\
    \ p) { x += p.x, y += p.y; return *this; }\r\n    Point& operator -= (const Point&\
    \ p) { x -= p.x, y -= p.y; return *this; }\r\n    Point& operator *= (const T&\
    \ t) { x *= t, y *= t; return *this; }\r\n    Point& operator /= (const T& t)\
    \ { x /= t, y /= t; return *this; }\r\n    Point& operator *= (const Point& t)\
    \ { \r\n        Point res = Point(x, y) * t; x = res.x, y = res.y; return *this;\
    \ }\r\n    Point& operator /= (const Point& t) { \r\n        Point res = Point(x,\
    \ y) / t; x = res.x, y = res.y; return *this; }\r\n\r\n    friend Point operator\
    \ + (const Point& a, const Point& b) { return Point(a.x + b.x, a.y + b.y); }\r\
    \n    friend Point operator - (const Point& a, const Point& b) { return Point(a.x\
    \ - b.x, a.y - b.y); }\r\n    friend Point operator * (const Point& a, const T&\
    \ t) { return Point(a.x * t, a.y * t); }\r\n    friend Point operator * (const\
    \ T& t ,const Point& a) { return Point(t * a.x, t * a.y); }\r\n    friend Point\
    \ operator / (const Point& a, const T& t) { return Point(a.x / t, a.y / t); }\r\
    \n    friend Point operator * (const Point& a, const Point& b) { \r\n        return\
    \ Point(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y); }\r\n    friend Point operator\
    \ / (const Point& a, const Point& b) { \r\n        return Point(a * conj(b) /\
    \ norm(b)); }\r\n\r\n    friend T int_norm(const Point& a) { return __gcd(a.x,\
    \ a.y); }\r\n    friend T int_unit(const Point& a) { if (a == Point()) return\
    \ a; return a / int_norm(a); }\r\n\r\n    friend T cross(const Point& a, const\
    \ Point& b) { return a.x * b.y - a.y * b.x; }\r\n    friend T dot(const Point&\
    \ a, const Point& b) { return a.x * b.x + a.y * b.y; }\r\n    friend T area(const\
    \ Point& a, const Point& b, const Point& c) { return cross(b - a, c - a); }\r\n\
    \r\n    // Returns conj(a) * b\r\n    friend Point rotation(const Point& a, const\
    \ Point& b) { return Point(dot(a, b), cross(a, b)); }\r\n\r\n    friend bool same_dir(const\
    \ Point& a, const Point& b) { return cross(a, b) == 0 && dot(a, b) > 0; }\r\n\r\
    \n    // check if 180 <= s..t < 360\r\n    friend bool is_reflex(const Point&\
    \ a, const Point& b) { \r\n        auto c = cross(a, b); return c ? (c < 0) :\
    \ (dot(a, b) < 0); }\r\n\r\n    // operator < (s, t) for angles in [base, base+2pi)\r\
    \n    friend bool angle_less(const Point& base, const Point& s, const Point& t)\
    \ {\r\n        int r = is_reflex(base, s) - is_reflex(base, t);\r\n        return\
    \ r ? (r < 0) : (0 < cross(s, t));\r\n    }\r\n\r\n    friend bool angle_cmp(const\
    \ Point& base) {\r\n        return [base](const Point& s, const Point& t) { return\
    \ angle_less(base, s, t); };\r\n    }\r\n    friend bool angle_cmp_center(const\
    \ Point& center, const Point& dir) {\r\n        return [center, dir](const Point&\
    \ s, const Point& t) -> bool { \r\n            return angle_less(dir, s - center,\
    \ t - center); };\r\n    }\r\n\r\n    // is p in [s,t] taken ccw? 1/0/-1 for in/border/out\r\
    \n    friend int angle_between(const Point& s, const Point& t, const Point& p)\
    \ {\r\n        if (same_dir(p, s) || same_dir(p, t)) return 0;\r\n        return\
    \ angle_less(s, p, t) ? 1 : -1;\r\n    }\r\n};\r\n\r\nnamespace Geometry2D {\r\
    \n\r\ntemplate <class T> int sign(T x) { return (x > 0) - (x < 0); }\r\ntemplate\
    \ <class T> Point<T> reflect(const Point<T>& p, const Point<T>& a, const Point<T>&\
    \ b) {\r\n        return a + conj((p - a) / (b - a)) * (b - a); }\r\ntemplate\
    \ <class T> Point<T> foot( const Point<T>& p, const Point<T>& a, const Point<T>&\
    \ b) {\r\n        return (p + reflect(p, a, b)) / (T) 2; }\r\ntemplate <class\
    \ T> bool on_segment(Point<T> p, Point<T> a, Point<T> b) {\r\n    return area(a,\
    \ b, p) == 0 && dot(p - a, p - b) <= 0; }\r\ntemplate <class T>\r\nstd::vector<Point<T>>\
    \ segment_intersect(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {\r\n    T\
    \ x = area(a, b, c), y = area(a, b, d);\r\n    T X = area(c, d, a), Y = area(c,\
    \ d, b);\r\n    if (sign(x) * sign(y) < 0 && sign(X) * sign(Y) < 0)\r\n      \
    \  return {(d * x - c * y) / (x - y)};\r\n    std::set<Point<T>> s;\r\n    if\
    \ (on_segment(a, c, d))\r\n        s.insert(a);\r\n    if (on_segment(b, c, d))\r\
    \n        s.insert(b);\r\n    if (on_segment(c, a, b))\r\n        s.insert(c);\r\
    \n    if (on_segment(d, a, b))\r\n        s.insert(d);\r\n    return {s.begin(),\
    \ s.end()};\r\n}\r\ntemplate <class T> T line_dist(Point<T> p, Point<T> a, Point<T>\
    \ b) {\r\n    return abs(area(p, a, b)) / abs(a - b); }\r\ntemplate <class T>\
    \ T point_segment_dist(Point<T> p, Point<T> a, Point<T> b) {\r\n    if (dot(p\
    \ - a, b - a) <= 0)\r\n        return abs(p - a);\r\n    if (dot(p - b, a - b)\
    \ <= 0)\r\n        return abs(p - b);\r\n    return line_dist(p, a, b);\r\n}\r\
    \ntemplate <class T> T segment_segment_dist(Point<T> a, Point<T> b, Point<T> c,\
    \ Point<T> d) {\r\n    std::vector<Point<T>> v = segment_intersect(a, b, c, d);\r\
    \n    if (!v.empty())\r\n        return 0;\r\n    return std::min({point_segment_dist(a,\
    \ c, d), point_segment_dist(b, c, d), \r\n        point_segment_dist(c, a, b),\
    \ point_segment_dist(d, a, b)});\r\n}\r\n\r\n} // Geometry2D\r\n\r\nint main()\
    \ {\r\n    using namespace std;\r\n    using namespace Geometry2D;\r\n    typedef\
    \ long double ld;\r\n    typedef Point<long double> P;\r\n    cout << setprecision(2)\
    \ << fixed;\r\n    int n; cin >> n;\r\n    while (n--) {\r\n        ld x1, y1,\
    \ x2, y2, x3, y3, x4, y4;\r\n        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >>\
    \ x4 >> y4;\r\n        ld ans = segment_segment_dist(P(x1, y1), P(x2, y2), P(x3,\
    \ y3), P(x4, y4));\r\n        cout << ans << '\\n';\r\n    }\r\n    return 0;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: library\geometry\point_geometry.cpp
  requiredBy: []
  timestamp: '2020-12-03 10:55:49-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\geometry\point_geometry.cpp
layout: document
redirect_from:
- /library\library\geometry\point_geometry.cpp
- /library\library\geometry\point_geometry.cpp.html
title: library\geometry\point_geometry.cpp
---
