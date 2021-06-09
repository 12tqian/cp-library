---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/mod_int.cpp\"\n#include<bits/stdc++.h>\n\
    \nconst int MOD = 1e9 + 7;\n\ntypedef std::decay<decltype(MOD)>::type mod_t; \n\
    struct mi {\n    mod_t val;\n    explicit operator mod_t() const { return val;\
    \ }\n    mi() { val = 0; }\n    mi(const long long& v) {\n        val = (-MOD\
    \ <= v && v <= MOD) ? v : v % MOD;\n        if (val < 0) val += MOD; }\n    friend\
    \ std::istream& operator>>(std::istream& in, mi& a) { \n        long long x; std::cin\
    \ >> x; a = mi(x); return in; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mi& a) { return os << a.val; }\n    friend bool operator==(const mi&\
    \ a, const mi& b) { return a.val == b.val; }\n    friend bool operator!=(const\
    \ mi& a, const mi& b) { return !(a == b); }    \n    friend bool operator<(const\
    \ mi& a, const mi& b) { return a.val < b.val; }\n    friend bool operator>(const\
    \ mi& a, const mi& b) { return a.val > b.val; }\n    friend bool operator<=(const\
    \ mi& a, const mi& b) { return a.val <= b.val; }\n    friend bool operator>=(const\
    \ mi& a, const mi& b) { return a.val >= b.val; }\n    mi operator-() const { return\
    \ mi(-val); }\n    mi& operator+=(const mi& m) {\n        if ((val += m.val) >=\
    \ MOD) val -= MOD;\n        return *this; }\n    mi& operator-=(const mi& m) {\n\
    \        if ((val -= m.val) < 0) val += MOD;\n        return *this; }\n    mi&\
    \ operator*=(const mi& m) { val = (long long) val * m.val % MOD;\n        return\
    \ *this; }\n    friend mi pow(mi a, long long p) {\n        mi ans = 1; assert(p\
    \ >= 0);\n        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n        return\
    \ ans; }\n    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD -\
    \ 2); }\n    mi& operator/=(const mi& m) { return (*this) *= inv(m); }\n    friend\
    \ mi operator+(mi a, const mi& b) { return a += b; }\n    friend mi operator-(mi\
    \ a, const mi& b) { return a -= b; }\n    friend mi operator*(mi a, const mi&\
    \ b) { return a *= b; }\n    friend mi operator/(mi a, const mi& b) { return a\
    \ /= b; }\n};\n\nint main(){\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nconst int MOD = 1e9 + 7;\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n    mod_t val;\n    explicit operator mod_t() const {\
    \ return val; }\n    mi() { val = 0; }\n    mi(const long long& v) {\n       \
    \ val = (-MOD <= v && v <= MOD) ? v : v % MOD;\n        if (val < 0) val += MOD;\
    \ }\n    friend std::istream& operator>>(std::istream& in, mi& a) { \n       \
    \ long long x; std::cin >> x; a = mi(x); return in; }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mi& a) { return os << a.val; }\n    friend\
    \ bool operator==(const mi& a, const mi& b) { return a.val == b.val; }\n    friend\
    \ bool operator!=(const mi& a, const mi& b) { return !(a == b); }    \n    friend\
    \ bool operator<(const mi& a, const mi& b) { return a.val < b.val; }\n    friend\
    \ bool operator>(const mi& a, const mi& b) { return a.val > b.val; }\n    friend\
    \ bool operator<=(const mi& a, const mi& b) { return a.val <= b.val; }\n    friend\
    \ bool operator>=(const mi& a, const mi& b) { return a.val >= b.val; }\n    mi\
    \ operator-() const { return mi(-val); }\n    mi& operator+=(const mi& m) {\n\
    \        if ((val += m.val) >= MOD) val -= MOD;\n        return *this; }\n   \
    \ mi& operator-=(const mi& m) {\n        if ((val -= m.val) < 0) val += MOD;\n\
    \        return *this; }\n    mi& operator*=(const mi& m) { val = (long long)\
    \ val * m.val % MOD;\n        return *this; }\n    friend mi pow(mi a, long long\
    \ p) {\n        mi ans = 1; assert(p >= 0);\n        for (; p; p /= 2, a *= a)\
    \ if (p & 1) ans *= a;\n        return ans; }\n    friend mi inv(const mi& a)\
    \ { assert(a != 0); return pow(a, MOD - 2); }\n    mi& operator/=(const mi& m)\
    \ { return (*this) *= inv(m); }\n    friend mi operator+(mi a, const mi& b) {\
    \ return a += b; }\n    friend mi operator-(mi a, const mi& b) { return a -= b;\
    \ }\n    friend mi operator*(mi a, const mi& b) { return a *= b; }\n    friend\
    \ mi operator/(mi a, const mi& b) { return a /= b; }\n};\n\nint main(){\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/mod_int.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:10:15-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/mod_int.cpp
layout: document
redirect_from:
- /library/library/numerical/mod_int.cpp
- /library/library/numerical/mod_int.cpp.html
title: library/numerical/mod_int.cpp
---
