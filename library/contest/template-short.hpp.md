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
  bundledCode: '

    #include <bits/stdc++.h>


    using namespace std;


    #define f1r(i, a, b) for (int i = (a); i < (b); ++i)

    #define f0r(i, a) f1r(i, 0, a)

    #define each(t, a) for (auto& t : a)


    #define mp make_pair

    #define f first

    #define s second

    #define pb push_back

    #define eb emplace_back

    #define sz(x) (int)(x).size()

    #define all(x) begin(x), end(x)


    typedef long long ll;

    typedef vector<int> vi;

    typedef vector<ll> vl;

    typedef pair<int, int> pi;

    typedef pair<ll, ll> pl;

    typedef vector<pi> vpi;

    typedef vector<pl> vpl;


    template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0;
    }

    template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0;
    }

    '
  code: '#pragma once


    #include <bits/stdc++.h>


    using namespace std;


    #define f1r(i, a, b) for (int i = (a); i < (b); ++i)

    #define f0r(i, a) f1r(i, 0, a)

    #define each(t, a) for (auto& t : a)


    #define mp make_pair

    #define f first

    #define s second

    #define pb push_back

    #define eb emplace_back

    #define sz(x) (int)(x).size()

    #define all(x) begin(x), end(x)


    typedef long long ll;

    typedef vector<int> vi;

    typedef vector<ll> vl;

    typedef pair<int, int> pi;

    typedef pair<ll, ll> pl;

    typedef vector<pi> vpi;

    typedef vector<pl> vpl;


    template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0;
    }

    template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0;
    }'
  dependsOn: []
  isVerificationFile: false
  path: library/contest/template-short.hpp
  requiredBy:
  - library/contest/template-short.cpp
  timestamp: '2021-08-16 13:46:51-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1494F.test.cpp
  - verify/codeforces/codeforces-1299D.test.cpp
  - verify/spoj/spoj-QTREE2.test.cpp
  - verify/unit-test/unit-test-template-short.test.cpp
documentation_of: library/contest/template-short.hpp
layout: document
redirect_from:
- /library/library/contest/template-short.hpp
- /library/library/contest/template-short.hpp.html
title: library/contest/template-short.hpp
---
