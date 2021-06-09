---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/frac.cpp\"\n#include<bits/stdc++.h>\n\n\
    struct Frac {\n\tlong long n, d;\n\tFrac(long long _n, long long _d) {\n\t\tn\
    \ = _n, d = _d;\n\t\tlong long g = std::__gcd(n, d); n /= g, d /= g;\n\t\tif (d\
    \ < 0) n *= -1, d *= -1;\n\t}\n\tFrac(long long _n) : Frac(_n, 1) {}\n\tFrac()\
    \ : Frac(0) {}\n\tfriend Frac abs(Frac F) { return Frac(abs(F.n), F.d); }\n\t\
    friend bool operator<(const Frac& l, const Frac& r) { return l.n * r.d < r.n *\
    \ l.d; }\n\tfriend bool operator<=(const Frac& l, const Frac& r) { return l.n\
    \ * r.d <= r.n * l.d; }\n\tfriend bool operator>(const Frac& l, const Frac& r)\
    \ { return l.n * r.d > r.n * l.d; }\n\tfriend bool operator>=(const Frac& l, const\
    \ Frac& r) { return l.n * r.d >= r.n * l.d; }\n\tfriend bool operator==(const\
    \ Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d; }\n\tfriend bool\
    \ operator!=(const Frac& l, const Frac& r) { return !(l == r); }\n\tFrac operator-()\
    \ const { return Frac(-n, d); }\n\tfriend Frac operator+(const Frac& l, const\
    \ Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }\n\tfriend Frac operator-(const\
    \ Frac& l, const Frac& r) { return Frac(l.n * r.d - r.n * l.d, l.d * r.d); }\n\
    \tfriend Frac operator*(const Frac& l, const Frac& r) { return Frac(l.n * r.n,\
    \ l.d * r.d); }\n\tfriend Frac operator*(const Frac& l, int r) { return l * Frac(r,\
    \ 1); }\n\tfriend Frac operator*(int r, const Frac& l) { return l * r; }\n\tfriend\
    \ Frac operator/(const Frac& l, const Frac& r) { return l * Frac(r.d, r.n); }\n\
    \tfriend Frac operator/(const Frac& l, const int& r) { return l / Frac(r, 1);\
    \ }\n\tfriend Frac operator/(const int& l, const Frac& r) { return Frac(l, 1)\
    \ / r; }\n\tfriend Frac& operator+=(Frac& l, const Frac& r) { return l = l + r;\
    \ }\n\tfriend Frac& operator-=(Frac& l, const Frac& r) { return l = l - r; }\n\
    \ttemplate <class T> friend Frac& operator*=(Frac& l, const T& r) { return l =\
    \ l * r; }\n\ttemplate <class T> friend Frac& operator/=(Frac& l, const T& r)\
    \ { return l = l / r; }\n\tfriend std::ostream& operator<<(std::ostream& os, const\
    \ Frac& a) { return os << a.n << \"/\" << a.d; }\n};\n\nint main() {\n\treturn\
    \ 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nstruct Frac {\n\tlong long n, d;\n\tFrac(long\
    \ long _n, long long _d) {\n\t\tn = _n, d = _d;\n\t\tlong long g = std::__gcd(n,\
    \ d); n /= g, d /= g;\n\t\tif (d < 0) n *= -1, d *= -1;\n\t}\n\tFrac(long long\
    \ _n) : Frac(_n, 1) {}\n\tFrac() : Frac(0) {}\n\tfriend Frac abs(Frac F) { return\
    \ Frac(abs(F.n), F.d); }\n\tfriend bool operator<(const Frac& l, const Frac& r)\
    \ { return l.n * r.d < r.n * l.d; }\n\tfriend bool operator<=(const Frac& l, const\
    \ Frac& r) { return l.n * r.d <= r.n * l.d; }\n\tfriend bool operator>(const Frac&\
    \ l, const Frac& r) { return l.n * r.d > r.n * l.d; }\n\tfriend bool operator>=(const\
    \ Frac& l, const Frac& r) { return l.n * r.d >= r.n * l.d; }\n\tfriend bool operator==(const\
    \ Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d; }\n\tfriend bool\
    \ operator!=(const Frac& l, const Frac& r) { return !(l == r); }\n\tFrac operator-()\
    \ const { return Frac(-n, d); }\n\tfriend Frac operator+(const Frac& l, const\
    \ Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }\n\tfriend Frac operator-(const\
    \ Frac& l, const Frac& r) { return Frac(l.n * r.d - r.n * l.d, l.d * r.d); }\n\
    \tfriend Frac operator*(const Frac& l, const Frac& r) { return Frac(l.n * r.n,\
    \ l.d * r.d); }\n\tfriend Frac operator*(const Frac& l, int r) { return l * Frac(r,\
    \ 1); }\n\tfriend Frac operator*(int r, const Frac& l) { return l * r; }\n\tfriend\
    \ Frac operator/(const Frac& l, const Frac& r) { return l * Frac(r.d, r.n); }\n\
    \tfriend Frac operator/(const Frac& l, const int& r) { return l / Frac(r, 1);\
    \ }\n\tfriend Frac operator/(const int& l, const Frac& r) { return Frac(l, 1)\
    \ / r; }\n\tfriend Frac& operator+=(Frac& l, const Frac& r) { return l = l + r;\
    \ }\n\tfriend Frac& operator-=(Frac& l, const Frac& r) { return l = l - r; }\n\
    \ttemplate <class T> friend Frac& operator*=(Frac& l, const T& r) { return l =\
    \ l * r; }\n\ttemplate <class T> friend Frac& operator/=(Frac& l, const T& r)\
    \ { return l = l / r; }\n\tfriend std::ostream& operator<<(std::ostream& os, const\
    \ Frac& a) { return os << a.n << \"/\" << a.d; }\n};\n\nint main() {\n\treturn\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/frac.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/frac.cpp
layout: document
redirect_from:
- /library/library/numerical/frac.cpp
- /library/library/numerical/frac.cpp.html
title: library/numerical/frac.cpp
---
