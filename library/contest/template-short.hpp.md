---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-short.cpp
    title: library/contest/template-short.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1299D.test.cpp
    title: verify/codeforces/codeforces-1299D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1494F.test.cpp
    title: verify/codeforces/codeforces-1494F.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/spoj/spoj-QTREE2.test.cpp
    title: verify/spoj/spoj-QTREE2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-template-short.test.cpp
    title: verify/unit-test/unit-test-template-short.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
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
    \ T& b) { return a < b ? a = b, 1 : 0; }\n"
  code: "#pragma once\r\n\r\n#include <bits/stdc++.h>\r\n\r\nusing namespace std;\r\
    \n\r\n#define f1r(i, a, b) for (int i = (a); i < (b); ++i)\r\n#define f0r(i, a)\
    \ f1r(i, 0, a)\r\n#define each(t, a) for (auto& t : a)\r\n\r\n#define mp make_pair\r\
    \n#define f first\r\n#define s second\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define sz(x) (int)(x).size()\r\n#define all(x) begin(x), end(x)\r\n\r\ntypedef\
    \ long long ll;\r\ntypedef vector<int> vi;\r\ntypedef vector<ll> vl;\r\ntypedef\
    \ pair<int, int> pi;\r\ntypedef pair<ll, ll> pl;\r\ntypedef vector<pi> vpi;\r\n\
    typedef vector<pl> vpl;\r\n\r\ntemplate <class T> bool ckmin(T& a, const T& b)\
    \ { return b < a ? a = b, 1 : 0; }\r\ntemplate <class T> bool ckmax(T& a, const\
    \ T& b) { return a < b ? a = b, 1 : 0; }"
  dependsOn: []
  isVerificationFile: false
  path: library/contest/template-short.hpp
  requiredBy:
  - library/contest/template-short.cpp
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/spoj/spoj-QTREE2.test.cpp
  - verify/codeforces/codeforces-1299D.test.cpp
  - verify/codeforces/codeforces-1494F.test.cpp
  - verify/unit-test/unit-test-template-short.test.cpp
documentation_of: library/contest/template-short.hpp
layout: document
redirect_from:
- /library/library/contest/template-short.hpp
- /library/library/contest/template-short.hpp.html
title: library/contest/template-short.hpp
---
