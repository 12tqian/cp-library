---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-fraction.test.cpp
    title: verify/unit-test/unit-test-fraction.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nstruct Frac {\r\n\tlong long n, d;\r\n\tFrac(long long _n, long\
    \ long _d) {\r\n\t\tn = _n, d = _d;\r\n\t\tlong long g = std::__gcd(n, d); n /=\
    \ g, d /= g;\r\n\t\tif (d < 0) n *= -1, d *= -1;\r\n\t}\r\n\tlong double eval()\
    \ { return (long double)n / d; }\r\n\tFrac(long long _n) : Frac(_n, 1) {}\r\n\t\
    Frac() : Frac(0) {}\r\n\tfriend Frac abs(Frac F) { return Frac(abs(F.n), F.d);\
    \ }\r\n\tfriend bool operator<(const Frac& l, const Frac& r) { return l.n * r.d\
    \ < r.n * l.d; }\r\n\tfriend bool operator<=(const Frac& l, const Frac& r) { return\
    \ l.n * r.d <= r.n * l.d; }\r\n\tfriend bool operator>(const Frac& l, const Frac&\
    \ r) { return l.n * r.d > r.n * l.d; }\r\n\tfriend bool operator>=(const Frac&\
    \ l, const Frac& r) { return l.n * r.d >= r.n * l.d; }\r\n\tfriend bool operator==(const\
    \ Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d; }\r\n\tfriend bool\
    \ operator!=(const Frac& l, const Frac& r) { return !(l == r); }\r\n\tFrac operator-()\
    \ const { return Frac(-n, d); }\r\n\tfriend Frac operator+(const Frac& l, const\
    \ Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }\r\n\tfriend Frac\
    \ operator-(const Frac& l, const Frac& r) { return Frac(l.n * r.d - r.n * l.d,\
    \ l.d * r.d); }\r\n\tfriend Frac operator*(const Frac& l, const Frac& r) { return\
    \ Frac(l.n * r.n, l.d * r.d); }\r\n\tfriend Frac operator*(const Frac& l, long\
    \ long r) { return l * Frac(r, 1); }\r\n\tfriend Frac operator*(long long r, const\
    \ Frac& l) { return l * r; }\r\n\tfriend Frac operator/(const Frac& l, const Frac&\
    \ r) { return l * Frac(r.d, r.n); }\r\n\tfriend Frac operator/(const Frac& l,\
    \ const long long& r) { return l / Frac(r, 1); }\r\n\tfriend Frac operator/(const\
    \ long long& l, const Frac& r) { return Frac(l, 1) / r; }\r\n\tfriend Frac& operator+=(Frac&\
    \ l, const Frac& r) { return l = l + r; }\r\n\tfriend Frac& operator-=(Frac& l,\
    \ const Frac& r) { return l = l - r; }\r\n\ttemplate <class T> friend Frac& operator*=(Frac&\
    \ l, const T& r) { return l = l * r; }\r\n\ttemplate <class T> friend Frac& operator/=(Frac&\
    \ l, const T& r) { return l = l / r; }\r\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const Frac& a) { return os << a.n << \"/\" << a.d; }\r\n};\n"
  code: "#pragma once\r\n\r\nstruct Frac {\r\n\tlong long n, d;\r\n\tFrac(long long\
    \ _n, long long _d) {\r\n\t\tn = _n, d = _d;\r\n\t\tlong long g = std::__gcd(n,\
    \ d); n /= g, d /= g;\r\n\t\tif (d < 0) n *= -1, d *= -1;\r\n\t}\r\n\tlong double\
    \ eval() { return (long double)n / d; }\r\n\tFrac(long long _n) : Frac(_n, 1)\
    \ {}\r\n\tFrac() : Frac(0) {}\r\n\tfriend Frac abs(Frac F) { return Frac(abs(F.n),\
    \ F.d); }\r\n\tfriend bool operator<(const Frac& l, const Frac& r) { return l.n\
    \ * r.d < r.n * l.d; }\r\n\tfriend bool operator<=(const Frac& l, const Frac&\
    \ r) { return l.n * r.d <= r.n * l.d; }\r\n\tfriend bool operator>(const Frac&\
    \ l, const Frac& r) { return l.n * r.d > r.n * l.d; }\r\n\tfriend bool operator>=(const\
    \ Frac& l, const Frac& r) { return l.n * r.d >= r.n * l.d; }\r\n\tfriend bool\
    \ operator==(const Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d;\
    \ }\r\n\tfriend bool operator!=(const Frac& l, const Frac& r) { return !(l ==\
    \ r); }\r\n\tFrac operator-() const { return Frac(-n, d); }\r\n\tfriend Frac operator+(const\
    \ Frac& l, const Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }\r\
    \n\tfriend Frac operator-(const Frac& l, const Frac& r) { return Frac(l.n * r.d\
    \ - r.n * l.d, l.d * r.d); }\r\n\tfriend Frac operator*(const Frac& l, const Frac&\
    \ r) { return Frac(l.n * r.n, l.d * r.d); }\r\n\tfriend Frac operator*(const Frac&\
    \ l, long long r) { return l * Frac(r, 1); }\r\n\tfriend Frac operator*(long long\
    \ r, const Frac& l) { return l * r; }\r\n\tfriend Frac operator/(const Frac& l,\
    \ const Frac& r) { return l * Frac(r.d, r.n); }\r\n\tfriend Frac operator/(const\
    \ Frac& l, const long long& r) { return l / Frac(r, 1); }\r\n\tfriend Frac operator/(const\
    \ long long& l, const Frac& r) { return Frac(l, 1) / r; }\r\n\tfriend Frac& operator+=(Frac&\
    \ l, const Frac& r) { return l = l + r; }\r\n\tfriend Frac& operator-=(Frac& l,\
    \ const Frac& r) { return l = l - r; }\r\n\ttemplate <class T> friend Frac& operator*=(Frac&\
    \ l, const T& r) { return l = l * r; }\r\n\ttemplate <class T> friend Frac& operator/=(Frac&\
    \ l, const T& r) { return l = l / r; }\r\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const Frac& a) { return os << a.n << \"/\" << a.d; }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/fraction.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit-test/unit-test-fraction.test.cpp
documentation_of: library/numerical/fraction.hpp
layout: document
redirect_from:
- /library/library/numerical/fraction.hpp
- /library/library/numerical/fraction.hpp.html
title: library/numerical/fraction.hpp
---
