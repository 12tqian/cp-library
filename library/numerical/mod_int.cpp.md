---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n\nconst int MOD = 1e9 + 7;\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n\tmod_t val;\n\texplicit operator mod_t() const { return\
    \ val; }\n\tmi() { val = 0; }\n\tmi(const long long &v) {\n\t\tval = (-MOD <=\
    \ v && v <= MOD) ? v : v % MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend std::istream&\
    \ operator>>(std::istream &in, mi &a) { \n\t\tlong long x; std::cin >> x; a =\
    \ mi(x); return in; }\n\tfriend std::ostream& operator<<(std::ostream &os, const\
    \ mi &a) { return os << a.val; }\n\tfriend bool operator==(const mi &a, const\
    \ mi &b) { return a.val == b.val; }\n\tfriend bool operator!=(const mi &a, const\
    \ mi &b) { return !(a == b); }    \n\tfriend bool operator<(const mi &a, const\
    \ mi &b) { return a.val < b.val; }\n\tfriend bool operator>(const mi &a, const\
    \ mi &b) { return a.val > b.val; }\n\tfriend bool operator<=(const mi &a, const\
    \ mi &b) { return a.val <= b.val; }\n\tfriend bool operator>=(const mi &a, const\
    \ mi &b) { return a.val >= b.val; }\n\tmi operator-() const { return mi(-val);\
    \ }\n\tmi& operator+=(const mi &m) {\n\t\tif ((val += m.val) >= MOD) val -= MOD;\n\
    \t\treturn *this; }\n\tmi& operator-=(const mi &m) {\n\t\tif ((val -= m.val) <\
    \ 0) val += MOD;\n\t\treturn *this; }\n\tmi& operator*=(const mi &m) { val = (long\
    \ long)val * m.val % MOD;\n\t\treturn *this; }\n\tfriend mi pow(mi a, long long\
    \ p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p &\
    \ 1) ans *= a;\n\t\treturn ans; }\n\tfriend mi inv(const mi &a) { assert(a !=\
    \ 0); return pow(a, MOD - 2); }\n\tmi& operator/=(const mi &m) { return (*this)\
    \ *= inv(m); }\n\tfriend mi operator+(mi a, const mi &b) { return a += b; }\n\t\
    friend mi operator-(mi a, const mi &b) { return a -= b; }\n\tfriend mi operator*(mi\
    \ a, const mi &b) { return a *= b; }\n\tfriend mi operator/(mi a, const mi &b)\
    \ { return a /= b; }\n};\n"
  code: "#include <bits/stdc++.h>\n\nconst int MOD = 1e9 + 7;\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n\tmod_t val;\n\texplicit operator mod_t() const { return\
    \ val; }\n\tmi() { val = 0; }\n\tmi(const long long &v) {\n\t\tval = (-MOD <=\
    \ v && v <= MOD) ? v : v % MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend std::istream&\
    \ operator>>(std::istream &in, mi &a) { \n\t\tlong long x; std::cin >> x; a =\
    \ mi(x); return in; }\n\tfriend std::ostream& operator<<(std::ostream &os, const\
    \ mi &a) { return os << a.val; }\n\tfriend bool operator==(const mi &a, const\
    \ mi &b) { return a.val == b.val; }\n\tfriend bool operator!=(const mi &a, const\
    \ mi &b) { return !(a == b); }    \n\tfriend bool operator<(const mi &a, const\
    \ mi &b) { return a.val < b.val; }\n\tfriend bool operator>(const mi &a, const\
    \ mi &b) { return a.val > b.val; }\n\tfriend bool operator<=(const mi &a, const\
    \ mi &b) { return a.val <= b.val; }\n\tfriend bool operator>=(const mi &a, const\
    \ mi &b) { return a.val >= b.val; }\n\tmi operator-() const { return mi(-val);\
    \ }\n\tmi& operator+=(const mi &m) {\n\t\tif ((val += m.val) >= MOD) val -= MOD;\n\
    \t\treturn *this; }\n\tmi& operator-=(const mi &m) {\n\t\tif ((val -= m.val) <\
    \ 0) val += MOD;\n\t\treturn *this; }\n\tmi& operator*=(const mi &m) { val = (long\
    \ long)val * m.val % MOD;\n\t\treturn *this; }\n\tfriend mi pow(mi a, long long\
    \ p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p &\
    \ 1) ans *= a;\n\t\treturn ans; }\n\tfriend mi inv(const mi &a) { assert(a !=\
    \ 0); return pow(a, MOD - 2); }\n\tmi& operator/=(const mi &m) { return (*this)\
    \ *= inv(m); }\n\tfriend mi operator+(mi a, const mi &b) { return a += b; }\n\t\
    friend mi operator-(mi a, const mi &b) { return a -= b; }\n\tfriend mi operator*(mi\
    \ a, const mi &b) { return a *= b; }\n\tfriend mi operator/(mi a, const mi &b)\
    \ { return a /= b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/mod_int.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/mod_int.cpp
layout: document
redirect_from:
- /library/library/numerical/mod_int.cpp
- /library/library/numerical/mod_int.cpp.html
title: library/numerical/mod_int.cpp
---
