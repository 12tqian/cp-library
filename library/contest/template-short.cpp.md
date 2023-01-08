---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-short.hpp
    title: library/contest/template-short.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-template-short.test.cpp
    title: verify/unit-test/unit-test-template-short.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n#include <bits/stdc++.h>\r\n\r\nusing namespace std;\r\n\r\n#define\
    \ f1r(i, a, b) for (int i = (a); i < (b); ++i)\r\n#define f0r(i, a) f1r(i, 0,\
    \ a)\r\n#define each(t, a) for (auto& t : a)\r\n\r\n#define mp make_pair\r\n#define\
    \ f first\r\n#define s second\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define sz(x) (int)(x).size()\r\n#define all(x) begin(x), end(x)\r\n\r\ntypedef\
    \ long long ll;\r\ntypedef vector<int> vi;\r\ntypedef vector<ll> vl;\r\ntypedef\
    \ pair<int, int> pi;\r\ntypedef pair<ll, ll> pl;\r\ntypedef vector<pi> vpi;\r\n\
    typedef vector<pl> vpl;\r\n\r\ntemplate <class T> bool ckmin(T& a, const T& b)\
    \ { return b < a ? a = b, 1 : 0; }\r\ntemplate <class T> bool ckmax(T& a, const\
    \ T& b) { return a < b ? a = b, 1 : 0; }\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\treturn 0;\r\n}\r\n"
  code: "#include \"template-short.hpp\"\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-short.hpp
  isVerificationFile: false
  path: library/contest/template-short.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit-test/unit-test-template-short.test.cpp
documentation_of: library/contest/template-short.cpp
layout: document
redirect_from:
- /library/library/contest/template-short.cpp
- /library/library/contest/template-short.cpp.html
title: library/contest/template-short.cpp
---
