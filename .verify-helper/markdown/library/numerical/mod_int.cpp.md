---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\numerical\\\\mod_int.cpp\"\n#include<bits/stdc++.h>\r\
    \nconst int MOD = 1e9 + 7;\r\ntypedef std::decay <decltype(MOD)>::type mod_t;\r\
    \nstruct mi {\r\n    mod_t val;\r\n    explicit operator mod_t() const { return\
    \ val; }\r\n    mi() { val = 0; }\r\n    mi(const long long& v) {\r\n        val\
    \ = (-MOD <= v && v <= MOD) ? v : v % MOD;\r\n        if (val < 0) val += MOD;\
    \ }\r\n    friend std::istream& operator >> (std::istream& in, mi& a) { \r\n \
    \       long long x; std::cin >> x; a = mi(x); return in; }\r\n    friend std::ostream&\
    \ operator << (std::ostream& os, const mi& a) { return os << a.val; }\r\n    friend\
    \ bool operator == (const mi& a, const mi& b) { return a.val == b.val; }\r\n \
    \   friend bool operator != (const mi& a, const mi& b) { return !(a == b); } \
    \   \r\n    friend bool operator < (const mi& a, const mi& b) { return a.val <\
    \ b.val; }\r\n    friend bool operator > (const mi& a, const mi& b) { return a.val\
    \ > b.val; }\r\n    friend bool operator <= (const mi& a, const mi& b) { return\
    \ a.val <= b.val; }\r\n    friend bool operator >= (const mi& a, const mi& b)\
    \ { return a.val >= b.val; }\r\n    mi operator - () const { return mi(-val);\
    \ }\r\n    mi& operator += (const mi& m) {\r\n        if ((val += m.val) >= MOD)\
    \ val -= MOD;\r\n        return *this; }\r\n    mi& operator -= (const mi& m)\
    \ {\r\n        if ((val -= m.val) < 0) val += MOD;\r\n        return *this; }\r\
    \n    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;\r\n\
    \        return *this; }\r\n    friend mi pow(mi a, long long p) {\r\n       \
    \ mi ans = 1; assert(p >= 0);\r\n        for (; p; p /= 2, a *= a) if (p & 1)\
    \ ans *= a;\r\n        return ans; }\r\n    friend mi inv(const mi& a) { assert(a\
    \ != 0); return pow(a, MOD - 2); }\r\n    mi& operator /= (const mi& m) { return\
    \ (*this) *= inv(m); }\r\n    friend mi operator + (mi a, const mi& b) { return\
    \ a += b; }\r\n    friend mi operator - (mi a, const mi& b) { return a -= b; }\r\
    \n    friend mi operator * (mi a, const mi& b) { return a *= b; }\r\n    friend\
    \ mi operator / (mi a, const mi& b) { return a /= b; }\r\n};\r\n\r\nint main(){\r\
    \n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\nconst int MOD = 1e9 + 7;\r\ntypedef std::decay\
    \ <decltype(MOD)>::type mod_t;\r\nstruct mi {\r\n    mod_t val;\r\n    explicit\
    \ operator mod_t() const { return val; }\r\n    mi() { val = 0; }\r\n    mi(const\
    \ long long& v) {\r\n        val = (-MOD <= v && v <= MOD) ? v : v % MOD;\r\n\
    \        if (val < 0) val += MOD; }\r\n    friend std::istream& operator >> (std::istream&\
    \ in, mi& a) { \r\n        long long x; std::cin >> x; a = mi(x); return in; }\r\
    \n    friend std::ostream& operator << (std::ostream& os, const mi& a) { return\
    \ os << a.val; }\r\n    friend bool operator == (const mi& a, const mi& b) { return\
    \ a.val == b.val; }\r\n    friend bool operator != (const mi& a, const mi& b)\
    \ { return !(a == b); }    \r\n    friend bool operator < (const mi& a, const\
    \ mi& b) { return a.val < b.val; }\r\n    friend bool operator > (const mi& a,\
    \ const mi& b) { return a.val > b.val; }\r\n    friend bool operator <= (const\
    \ mi& a, const mi& b) { return a.val <= b.val; }\r\n    friend bool operator >=\
    \ (const mi& a, const mi& b) { return a.val >= b.val; }\r\n    mi operator - ()\
    \ const { return mi(-val); }\r\n    mi& operator += (const mi& m) {\r\n      \
    \  if ((val += m.val) >= MOD) val -= MOD;\r\n        return *this; }\r\n    mi&\
    \ operator -= (const mi& m) {\r\n        if ((val -= m.val) < 0) val += MOD;\r\
    \n        return *this; }\r\n    mi& operator *= (const mi& m) { val = (long long)\
    \ val * m.val % MOD;\r\n        return *this; }\r\n    friend mi pow(mi a, long\
    \ long p) {\r\n        mi ans = 1; assert(p >= 0);\r\n        for (; p; p /= 2,\
    \ a *= a) if (p & 1) ans *= a;\r\n        return ans; }\r\n    friend mi inv(const\
    \ mi& a) { assert(a != 0); return pow(a, MOD - 2); }\r\n    mi& operator /= (const\
    \ mi& m) { return (*this) *= inv(m); }\r\n    friend mi operator + (mi a, const\
    \ mi& b) { return a += b; }\r\n    friend mi operator - (mi a, const mi& b) {\
    \ return a -= b; }\r\n    friend mi operator * (mi a, const mi& b) { return a\
    \ *= b; }\r\n    friend mi operator / (mi a, const mi& b) { return a /= b; }\r\
    \n};\r\n\r\nint main(){\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\numerical\mod_int.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:52:25-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\numerical\mod_int.cpp
layout: document
redirect_from:
- /library\library\numerical\mod_int.cpp
- /library\library\numerical\mod_int.cpp.html
title: library\numerical\mod_int.cpp
---
