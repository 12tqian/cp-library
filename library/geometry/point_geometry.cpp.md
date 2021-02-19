---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/geometry/point_geometry.cpp\"\n#include <bits/stdc++.h>\n\
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
    \ p, t) ? 1 : -1;\n    }\n};\n\nnamespace Geometry2D {\n\ntemplate <class T> int\
    \ sign(T x) { return (x > 0) - (x < 0); }\ntemplate <class T> Point<T> reflect(const\
    \ Point<T>& p, const Point<T>& a, const Point<T>& b) {\n        return a + conj((p\
    \ - a) / (b - a)) * (b - a); }\ntemplate <class T> Point<T> foot( const Point<T>&\
    \ p, const Point<T>& a, const Point<T>& b) {\n        return (p + reflect(p, a,\
    \ b)) / (T) 2; }\ntemplate <class T> bool on_segment(Point<T> p, Point<T> a, Point<T>\
    \ b) {\n    return area(a, b, p) == 0 && dot(p - a, p - b) <= 0; }\n\ntemplate\
    \ <class T>\nstd::vector<Point<T>> segment_intersect(Point<T> a, Point<T> b, Point<T>\
    \ c, Point<T> d) {\n    T x = area(a, b, c), y = area(a, b, d);\n    T X = area(c,\
    \ d, a), Y = area(c, d, b);\n    if (sign(x) * sign(y) < 0 && sign(X) * sign(Y)\
    \ < 0)\n        return {(d * x - c * y) / (x - y)};\n    std::set<Point<T>> s;\n\
    \    if (on_segment(a, c, d))\n        s.insert(a);\n    if (on_segment(b, c,\
    \ d))\n        s.insert(b);\n    if (on_segment(c, a, b))\n        s.insert(c);\n\
    \    if (on_segment(d, a, b))\n        s.insert(d);\n    return {s.begin(), s.end()};\n\
    }\n\ntemplate <class T> Point<T> extension(Point<T> a, Point<T> b, Point<T> c,\
    \ Point<T> d) {\n    T x = cross(a, b, c);\n    T y = cross(a, b, d);\n    return\
    \ (d * x - c * y) / (x - y);\n}\n\ntemplate <class T> std::pair<int, Point<T>>\
    \ line_intersect(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {\n    // returns\
    \ -1 if infinitely, 0 if none, 1 if unique \n    if (cross(b - a, d - c) == 0)\n\
    \        return {-(cross(a, c, d) == 0), Point<T>()};\n    else \n        return\
    \ {1, extend(a, b, c, d)};\n}\n\ntemplate <class T> T line_dist(Point<T> p, Point<T>\
    \ a, Point<T> b) {\n    return abs(area(p, a, b)) / abs(a - b); }\n\ntemplate\
    \ <class T> T point_segment_dist(Point<T> p, Point<T> a, Point<T> b) {\n    if\
    \ (dot(p - a, b - a) <= 0)\n        return abs(p - a);\n    if (dot(p - b, a -\
    \ b) <= 0)\n        return abs(p - b);\n    return line_dist(p, a, b);\n}\n\n\
    template <class T> T segment_segment_dist(Point<T> a, Point<T> b, Point<T> c,\
    \ Point<T> d) {\n    std::vector<Point<T>> v = segment_intersect(a, b, c, d);\n\
    \    if (!v.empty())\n        return 0;\n    return std::min({point_segment_dist(a,\
    \ c, d), point_segment_dist(b, c, d), \n        point_segment_dist(c, a, b), point_segment_dist(d,\
    \ a, b)});\n}\n\ntemplate <class T> std::pair<Point<T>, T> centroid_area(const\
    \ std::vector<Point<T>> v) {\n    // pair of centroid and area, positive means\
    \ CCW, negative means CW\n    Point<T> centroid(0, 0);\n    T area = 0;\n    for\
    \ (int i = 0; i < (int)v.size(); i++) {\n        int j = (i + 1) % ((int)v.size());\n\
    \        T a = cross(v[i], v[j]);\n        centroid += a * (v[i] + v[j]);\n  \
    \      area += a;\n    }\n    return {centroid / area / (T) 3, area / 2};\n}\n\
    \ntemplate<class T> int polygon_point(const std::vector<Point<T>>& p, Point<T>\
    \ z) {\n    // returns -1 if outside, 0 if on, 1 if inside\n    int n = (int)p.size();\n\
    \    int ans = 0;\n    for (int i = 0; i < n; i++) {\n        Point<T> x = p[i],\
    \ y = p[(i + 1) % n];\n        if (x.y > y.y) \n            std::swap(x, y);\n\
    \        if (on_segment(z, x, y))\n            return 0;\n        ans ^= (x.y\
    \ <= z.y && y.y > z.y && area(z, x, y) > 0);\n    }\n    return ans ? 1 : -1;\n\
    }\n\n} // Geometry2D\n\nint main() {\n    using namespace std;\n    using namespace\
    \ Geometry2D;\n    typedef long double ld;\n    typedef Point<long double> P;\n\
    \    cout << setprecision(1) << fixed;\n    while (true) {\n        int n; cin\
    \ >> n;\n        if (n == 0)\n            return 0;\n        vector<Point<int>>\
    \ v(n);\n        for (int i = 0; i < n; i++) \n            cin >> v[i].x >> v[i].y;\n\
    \        int m; cin >> m;\n        while (m--) {\n            Point<int> p;\n\
    \            cin >> p.x >> p.y;\n            int res = polygon_point(v, p);\n\
    \            if (res == -1)\n                cout << \"out\\n\";\n           \
    \ else if (res == 0)\n                cout << \"on\\n\";\n            else \n\
    \                cout << \"in\\n\";\n        }\n    }\n    return 0;\n}\n"
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
    \ Geometry2D {\n\ntemplate <class T> int sign(T x) { return (x > 0) - (x < 0);\
    \ }\ntemplate <class T> Point<T> reflect(const Point<T>& p, const Point<T>& a,\
    \ const Point<T>& b) {\n        return a + conj((p - a) / (b - a)) * (b - a);\
    \ }\ntemplate <class T> Point<T> foot( const Point<T>& p, const Point<T>& a, const\
    \ Point<T>& b) {\n        return (p + reflect(p, a, b)) / (T) 2; }\ntemplate <class\
    \ T> bool on_segment(Point<T> p, Point<T> a, Point<T> b) {\n    return area(a,\
    \ b, p) == 0 && dot(p - a, p - b) <= 0; }\n\ntemplate <class T>\nstd::vector<Point<T>>\
    \ segment_intersect(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {\n    T x\
    \ = area(a, b, c), y = area(a, b, d);\n    T X = area(c, d, a), Y = area(c, d,\
    \ b);\n    if (sign(x) * sign(y) < 0 && sign(X) * sign(Y) < 0)\n        return\
    \ {(d * x - c * y) / (x - y)};\n    std::set<Point<T>> s;\n    if (on_segment(a,\
    \ c, d))\n        s.insert(a);\n    if (on_segment(b, c, d))\n        s.insert(b);\n\
    \    if (on_segment(c, a, b))\n        s.insert(c);\n    if (on_segment(d, a,\
    \ b))\n        s.insert(d);\n    return {s.begin(), s.end()};\n}\n\ntemplate <class\
    \ T> Point<T> extension(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {\n  \
    \  T x = cross(a, b, c);\n    T y = cross(a, b, d);\n    return (d * x - c * y)\
    \ / (x - y);\n}\n\ntemplate <class T> std::pair<int, Point<T>> line_intersect(Point<T>\
    \ a, Point<T> b, Point<T> c, Point<T> d) {\n    // returns -1 if infinitely, 0\
    \ if none, 1 if unique \n    if (cross(b - a, d - c) == 0)\n        return {-(cross(a,\
    \ c, d) == 0), Point<T>()};\n    else \n        return {1, extend(a, b, c, d)};\n\
    }\n\ntemplate <class T> T line_dist(Point<T> p, Point<T> a, Point<T> b) {\n  \
    \  return abs(area(p, a, b)) / abs(a - b); }\n\ntemplate <class T> T point_segment_dist(Point<T>\
    \ p, Point<T> a, Point<T> b) {\n    if (dot(p - a, b - a) <= 0)\n        return\
    \ abs(p - a);\n    if (dot(p - b, a - b) <= 0)\n        return abs(p - b);\n \
    \   return line_dist(p, a, b);\n}\n\ntemplate <class T> T segment_segment_dist(Point<T>\
    \ a, Point<T> b, Point<T> c, Point<T> d) {\n    std::vector<Point<T>> v = segment_intersect(a,\
    \ b, c, d);\n    if (!v.empty())\n        return 0;\n    return std::min({point_segment_dist(a,\
    \ c, d), point_segment_dist(b, c, d), \n        point_segment_dist(c, a, b), point_segment_dist(d,\
    \ a, b)});\n}\n\ntemplate <class T> std::pair<Point<T>, T> centroid_area(const\
    \ std::vector<Point<T>> v) {\n    // pair of centroid and area, positive means\
    \ CCW, negative means CW\n    Point<T> centroid(0, 0);\n    T area = 0;\n    for\
    \ (int i = 0; i < (int)v.size(); i++) {\n        int j = (i + 1) % ((int)v.size());\n\
    \        T a = cross(v[i], v[j]);\n        centroid += a * (v[i] + v[j]);\n  \
    \      area += a;\n    }\n    return {centroid / area / (T) 3, area / 2};\n}\n\
    \ntemplate<class T> int polygon_point(const std::vector<Point<T>>& p, Point<T>\
    \ z) {\n    // returns -1 if outside, 0 if on, 1 if inside\n    int n = (int)p.size();\n\
    \    int ans = 0;\n    for (int i = 0; i < n; i++) {\n        Point<T> x = p[i],\
    \ y = p[(i + 1) % n];\n        if (x.y > y.y) \n            std::swap(x, y);\n\
    \        if (on_segment(z, x, y))\n            return 0;\n        ans ^= (x.y\
    \ <= z.y && y.y > z.y && area(z, x, y) > 0);\n    }\n    return ans ? 1 : -1;\n\
    }\n\n} // Geometry2D\n\nint main() {\n    using namespace std;\n    using namespace\
    \ Geometry2D;\n    typedef long double ld;\n    typedef Point<long double> P;\n\
    \    cout << setprecision(1) << fixed;\n    while (true) {\n        int n; cin\
    \ >> n;\n        if (n == 0)\n            return 0;\n        vector<Point<int>>\
    \ v(n);\n        for (int i = 0; i < n; i++) \n            cin >> v[i].x >> v[i].y;\n\
    \        int m; cin >> m;\n        while (m--) {\n            Point<int> p;\n\
    \            cin >> p.x >> p.y;\n            int res = polygon_point(v, p);\n\
    \            if (res == -1)\n                cout << \"out\\n\";\n           \
    \ else if (res == 0)\n                cout << \"on\\n\";\n            else \n\
    \                cout << \"in\\n\";\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/point_geometry.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/point_geometry.cpp
layout: document
redirect_from:
- /library/library/geometry/point_geometry.cpp
- /library/library/geometry/point_geometry.cpp.html
title: library/geometry/point_geometry.cpp
---
