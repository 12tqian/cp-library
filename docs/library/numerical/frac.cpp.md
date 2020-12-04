---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\numerical\\\\frac.cpp\"\n#include<bits/stdc++.h>\r\
    \nstruct Frac {\r\n    long long n, d;\r\n    Frac(long long _n, long long _d)\
    \ {\r\n        n = _n, d = _d;\r\n        long long g = std::__gcd(n, d); n /=\
    \ g, d /= g;\r\n        if (d < 0) n *= -1, d *= -1;\r\n    }\r\n    Frac(long\
    \ long _n) : Frac(_n, 1) {}\r\n    Frac() : Frac(0) {}\r\n    friend Frac abs(Frac\
    \ F) { return Frac(abs(F.n), F.d); }\r\n    friend bool operator < (const Frac&\
    \ l, const Frac& r) { return l.n * r.d < r.n * l.d; }\r\n    friend bool operator\
    \ <= (const Frac& l, const Frac& r) { return l.n * r.d <= r.n * l.d; }\r\n   \
    \ friend bool operator > (const Frac& l, const Frac& r) { return l.n * r.d > r.n\
    \ * l.d; }\r\n    friend bool operator >= (const Frac& l, const Frac& r) { return\
    \ l.n * r.d >= r.n * l.d; }\r\n    friend bool operator == (const Frac& l, const\
    \ Frac& r) { return l.n == r.n && l.d == r.d; }\r\n    friend bool operator !=\
    \ (const Frac& l, const Frac& r) { return !(l == r); }\r\n    Frac operator -\
    \ () const { return Frac(-n, d); }\r\n    friend Frac operator + (const Frac&\
    \ l, const Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }\r\n   \
    \ friend Frac operator - (const Frac& l, const Frac& r) { return Frac(l.n * r.d\
    \ - r.n * l.d, l.d * r.d); }\r\n    friend Frac operator * (const Frac& l, const\
    \ Frac& r) { return Frac(l.n * r.n, l.d * r.d); }\r\n    friend Frac operator\
    \ * (const Frac& l, int r) { return l * Frac(r, 1); }\r\n    friend Frac operator\
    \ * (int r, const Frac& l) { return l * r; }\r\n    friend Frac operator / (const\
    \ Frac& l, const Frac& r) { return l * Frac(r.d, r.n); }\r\n    friend Frac operator\
    \ / (const Frac& l, const int& r) { return l / Frac(r, 1); }\r\n    friend Frac\
    \ operator / (const int& l, const Frac& r) { return Frac(l, 1) / r; }\r\n    friend\
    \ Frac& operator += (Frac& l, const Frac& r) { return l = l + r; }\r\n    friend\
    \ Frac& operator -= (Frac& l, const Frac& r) { return l = l - r; }\r\n    template\
    \ <class T> friend Frac& operator *= (Frac& l, const T& r) { return l = l * r;\
    \ }\r\n    template <class T> friend Frac& operator /= (Frac& l, const T& r) {\
    \ return l = l / r; }\r\n    friend std::ostream& operator << (std::ostream& os,\
    \ const Frac& a) { return os << a.n << \"/\" << a.d; }\r\n};\r\nint main() {\r\
    \n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\nstruct Frac {\r\n    long long n, d;\r\n    Frac(long\
    \ long _n, long long _d) {\r\n        n = _n, d = _d;\r\n        long long g =\
    \ std::__gcd(n, d); n /= g, d /= g;\r\n        if (d < 0) n *= -1, d *= -1;\r\n\
    \    }\r\n    Frac(long long _n) : Frac(_n, 1) {}\r\n    Frac() : Frac(0) {}\r\
    \n    friend Frac abs(Frac F) { return Frac(abs(F.n), F.d); }\r\n    friend bool\
    \ operator < (const Frac& l, const Frac& r) { return l.n * r.d < r.n * l.d; }\r\
    \n    friend bool operator <= (const Frac& l, const Frac& r) { return l.n * r.d\
    \ <= r.n * l.d; }\r\n    friend bool operator > (const Frac& l, const Frac& r)\
    \ { return l.n * r.d > r.n * l.d; }\r\n    friend bool operator >= (const Frac&\
    \ l, const Frac& r) { return l.n * r.d >= r.n * l.d; }\r\n    friend bool operator\
    \ == (const Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d; }\r\n \
    \   friend bool operator != (const Frac& l, const Frac& r) { return !(l == r);\
    \ }\r\n    Frac operator - () const { return Frac(-n, d); }\r\n    friend Frac\
    \ operator + (const Frac& l, const Frac& r) { return Frac(l.n * r.d + r.n * l.d,\
    \ l.d * r.d); }\r\n    friend Frac operator - (const Frac& l, const Frac& r) {\
    \ return Frac(l.n * r.d - r.n * l.d, l.d * r.d); }\r\n    friend Frac operator\
    \ * (const Frac& l, const Frac& r) { return Frac(l.n * r.n, l.d * r.d); }\r\n\
    \    friend Frac operator * (const Frac& l, int r) { return l * Frac(r, 1); }\r\
    \n    friend Frac operator * (int r, const Frac& l) { return l * r; }\r\n    friend\
    \ Frac operator / (const Frac& l, const Frac& r) { return l * Frac(r.d, r.n);\
    \ }\r\n    friend Frac operator / (const Frac& l, const int& r) { return l / Frac(r,\
    \ 1); }\r\n    friend Frac operator / (const int& l, const Frac& r) { return Frac(l,\
    \ 1) / r; }\r\n    friend Frac& operator += (Frac& l, const Frac& r) { return\
    \ l = l + r; }\r\n    friend Frac& operator -= (Frac& l, const Frac& r) { return\
    \ l = l - r; }\r\n    template <class T> friend Frac& operator *= (Frac& l, const\
    \ T& r) { return l = l * r; }\r\n    template <class T> friend Frac& operator\
    \ /= (Frac& l, const T& r) { return l = l / r; }\r\n    friend std::ostream& operator\
    \ << (std::ostream& os, const Frac& a) { return os << a.n << \"/\" << a.d; }\r\
    \n};\r\nint main() {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\numerical\frac.cpp
  requiredBy: []
  timestamp: '2020-12-02 20:59:55-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\numerical\frac.cpp
layout: document
redirect_from:
- /library\library\numerical\frac.cpp
- /library\library\numerical\frac.cpp.html
title: library\numerical\frac.cpp
---
