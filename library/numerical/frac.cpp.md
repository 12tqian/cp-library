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
    struct Frac {\n    long long n, d;\n    Frac(long long _n, long long _d) {\n \
    \       n = _n, d = _d;\n        long long g = std::__gcd(n, d); n /= g, d /=\
    \ g;\n        if (d < 0) n *= -1, d *= -1;\n    }\n    Frac(long long _n) : Frac(_n,\
    \ 1) {}\n    Frac() : Frac(0) {}\n    friend Frac abs(Frac F) { return Frac(abs(F.n),\
    \ F.d); }\n    friend bool operator<(const Frac& l, const Frac& r) { return l.n\
    \ * r.d < r.n * l.d; }\n    friend bool operator<=(const Frac& l, const Frac&\
    \ r) { return l.n * r.d <= r.n * l.d; }\n    friend bool operator>(const Frac&\
    \ l, const Frac& r) { return l.n * r.d > r.n * l.d; }\n    friend bool operator>=(const\
    \ Frac& l, const Frac& r) { return l.n * r.d >= r.n * l.d; }\n    friend bool\
    \ operator==(const Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d;\
    \ }\n    friend bool operator!=(const Frac& l, const Frac& r) { return !(l ==\
    \ r); }\n    Frac operator-() const { return Frac(-n, d); }\n    friend Frac operator+(const\
    \ Frac& l, const Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }\n\
    \    friend Frac operator-(const Frac& l, const Frac& r) { return Frac(l.n * r.d\
    \ - r.n * l.d, l.d * r.d); }\n    friend Frac operator*(const Frac& l, const Frac&\
    \ r) { return Frac(l.n * r.n, l.d * r.d); }\n    friend Frac operator*(const Frac&\
    \ l, int r) { return l * Frac(r, 1); }\n    friend Frac operator*(int r, const\
    \ Frac& l) { return l * r; }\n    friend Frac operator/(const Frac& l, const Frac&\
    \ r) { return l * Frac(r.d, r.n); }\n    friend Frac operator/(const Frac& l,\
    \ const int& r) { return l / Frac(r, 1); }\n    friend Frac operator/(const int&\
    \ l, const Frac& r) { return Frac(l, 1) / r; }\n    friend Frac& operator+=(Frac&\
    \ l, const Frac& r) { return l = l + r; }\n    friend Frac& operator-=(Frac& l,\
    \ const Frac& r) { return l = l - r; }\n    template <class T> friend Frac& operator*=(Frac&\
    \ l, const T& r) { return l = l * r; }\n    template <class T> friend Frac& operator/=(Frac&\
    \ l, const T& r) { return l = l / r; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Frac& a) { return os << a.n << \"/\" << a.d; }\n};\n\nint main() {\n\
    \    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nstruct Frac {\n    long long n, d;\n    Frac(long\
    \ long _n, long long _d) {\n        n = _n, d = _d;\n        long long g = std::__gcd(n,\
    \ d); n /= g, d /= g;\n        if (d < 0) n *= -1, d *= -1;\n    }\n    Frac(long\
    \ long _n) : Frac(_n, 1) {}\n    Frac() : Frac(0) {}\n    friend Frac abs(Frac\
    \ F) { return Frac(abs(F.n), F.d); }\n    friend bool operator<(const Frac& l,\
    \ const Frac& r) { return l.n * r.d < r.n * l.d; }\n    friend bool operator<=(const\
    \ Frac& l, const Frac& r) { return l.n * r.d <= r.n * l.d; }\n    friend bool\
    \ operator>(const Frac& l, const Frac& r) { return l.n * r.d > r.n * l.d; }\n\
    \    friend bool operator>=(const Frac& l, const Frac& r) { return l.n * r.d >=\
    \ r.n * l.d; }\n    friend bool operator==(const Frac& l, const Frac& r) { return\
    \ l.n == r.n && l.d == r.d; }\n    friend bool operator!=(const Frac& l, const\
    \ Frac& r) { return !(l == r); }\n    Frac operator-() const { return Frac(-n,\
    \ d); }\n    friend Frac operator+(const Frac& l, const Frac& r) { return Frac(l.n\
    \ * r.d + r.n * l.d, l.d * r.d); }\n    friend Frac operator-(const Frac& l, const\
    \ Frac& r) { return Frac(l.n * r.d - r.n * l.d, l.d * r.d); }\n    friend Frac\
    \ operator*(const Frac& l, const Frac& r) { return Frac(l.n * r.n, l.d * r.d);\
    \ }\n    friend Frac operator*(const Frac& l, int r) { return l * Frac(r, 1);\
    \ }\n    friend Frac operator*(int r, const Frac& l) { return l * r; }\n    friend\
    \ Frac operator/(const Frac& l, const Frac& r) { return l * Frac(r.d, r.n); }\n\
    \    friend Frac operator/(const Frac& l, const int& r) { return l / Frac(r, 1);\
    \ }\n    friend Frac operator/(const int& l, const Frac& r) { return Frac(l, 1)\
    \ / r; }\n    friend Frac& operator+=(Frac& l, const Frac& r) { return l = l +\
    \ r; }\n    friend Frac& operator-=(Frac& l, const Frac& r) { return l = l - r;\
    \ }\n    template <class T> friend Frac& operator*=(Frac& l, const T& r) { return\
    \ l = l * r; }\n    template <class T> friend Frac& operator/=(Frac& l, const\
    \ T& r) { return l = l / r; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Frac& a) { return os << a.n << \"/\" << a.d; }\n};\n\nint main() {\n\
    \    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/frac.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:10:15-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/frac.cpp
layout: document
redirect_from:
- /library/library/numerical/frac.cpp
- /library/library/numerical/frac.cpp.html
title: library/numerical/frac.cpp
---
