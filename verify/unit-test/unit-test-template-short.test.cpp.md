---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-short.cpp
    title: library/contest/template-short.cpp
  - icon: ':heavy_check_mark:'
    path: library/contest/template-short.hpp
    title: library/contest/template-short.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links: []
  bundledCode: "#define IGNORE \"just testing compilation\"\n\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define f1r(i, a, b) for (int i = (a); i < (b); ++i)\n\
    #define f0r(i, a) f1r(i, 0, a)\n#define each(t, a) for (auto& t : a)\n\n#define\
    \ mp make_pair\n#define f first\n#define s second\n#define pb push_back\n#define\
    \ eb emplace_back\n#define sz(x) (int)(x).size()\n#define all(x) begin(x), end(x)\n\
    \ntypedef long long ll;\ntypedef vector<int> vi;\ntypedef vector<ll> vl;\ntypedef\
    \ pair<int, int> pi;\ntypedef pair<ll, ll> pl;\ntypedef vector<pi> vpi;\ntypedef\
    \ vector<pl> vpl;\n\ntemplate <class T> bool ckmin(T& a, const T& b) { return\
    \ b < a ? a = b, 1 : 0; }\ntemplate <class T> bool ckmax(T& a, const T& b) { return\
    \ a < b ? a = b, 1 : 0; }\n\nint main() {\n\tios::sync_with_stdio(false);\n\t\
    cin.tie(nullptr);\n\treturn 0;\n}\n"
  code: '#define IGNORE "just testing compilation"


    #include "../../library/contest/template-short.cpp"'
  dependsOn:
  - library/contest/template-short.cpp
  - library/contest/template-short.hpp
  isVerificationFile: true
  path: verify/unit-test/unit-test-template-short.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 13:46:51-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-template-short.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-template-short.test.cpp
- /verify/verify/unit-test/unit-test-template-short.test.cpp.html
title: verify/unit-test/unit-test-template-short.test.cpp
---
