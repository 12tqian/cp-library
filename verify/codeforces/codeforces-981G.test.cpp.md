---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/affine-segment-tree.hpp
    title: library/data-structures/1d-range-queries/affine-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/interval-union.hpp
    title: library/data-structures/1d-range-queries/interval-union.hpp
  - icon: ':question:'
    path: library/numerical/mod-int2.hpp
    title: library/numerical/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/981/problem/G
    links:
    - https://codeforces.com/contest/981/problem/G
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/981/problem/G\"\n\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class T> struct AffineSegmentTree {\n\tint sz;\n\tstd::vector<T> sum,\
    \ mult, add;\n\n\tvoid push(int ind, int L, int R) { // modify values for current\
    \ node\n\t\tsum[ind] *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\n\t\tif\
    \ (L != R) {\n\t\t\tmult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\n\
    \t\t\tadd[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\n\t\t\tadd[2 * ind\
    \ + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n\t\t}\n\t\tadd[ind] = 0; mult[ind]\
    \ = 1;\n\t}\n\n\tvoid init(int n) {\n\t\tsz = 1;\n\t\twhile (sz < n) sz *= 2;\n\
    \t\tmult.assign(2 * sz, 1);\n\t\tsum.assign(2 * sz, 0);\n\t\tadd.assign(2 * sz,\
    \ 0);\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind\
    \ + 1];\n\t}\n\n\t// t == 0 is add, t == 1 is for multiplying\n\tvoid upd(int\
    \ t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R ==\
    \ -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi < L || R < lo) return;\n\t\t\
    if (lo <= L && R <= hi) {\n\t\t\tif(t == 0) add[ind] = inc;  \n\t\t\telse mult[ind]\
    \ = inc;\n\t\t\tpush(ind, L, R); return;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\t\
    upd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1, M + 1, R);\n\
    \t\tpull(ind);\n\t}\n\t\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (lo > R ||\
    \ L > hi) return 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint M =\
    \ (L + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind\
    \ + 1, M + 1, R);\n\t}\n};\n\n// 5 is a root of both mods\ntemplate <int MOD,\
    \ int RT> struct Mint {\n\tstatic const int mod = MOD;\n\tstatic constexpr Mint\
    \ rt() { return RT; } // primitive root for FFT\n\tint v; \n\texplicit operator\
    \ int() const { return v; } // explicit -> don't silently convert to int\n\tMint()\
    \ { v = 0; }\n\tMint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v\
    \ % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const Mint &a, const\
    \ Mint &b) { return a.v == b.v; }\n\tfriend bool operator!=(const Mint &a, const\
    \ Mint &b) { return !(a == b); }\n\tfriend bool operator<(const Mint &a, const\
    \ Mint &b) { return a.v < b.v; }\n\tfriend bool operator>(const Mint &a, const\
    \ Mint &b) { return a.v > b.v; }\n\tfriend bool operator<=(const Mint &a, const\
    \ Mint &b) { return a.v <= b.v; }\n\tfriend bool operator>=(const Mint &a, const\
    \ Mint &b) { return a.v >= b.v; }\n\tfriend std::istream& operator >> (std::istream\
    \ &in, Mint &a) { \n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\n\
    \tfriend std::ostream& operator << (std::ostream &os, const Mint &a) { return\
    \ os << a.v; }\n\tMint& operator+=(const Mint &m) { \n\t\tif ((v += m.v) >= MOD)\
    \ v -= MOD; \n\t\treturn *this; }\n\tMint& operator-=(const Mint &m) { \n\t\t\
    if ((v -= m.v) < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const\
    \ Mint &m) { \n\t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const\
    \ Mint &m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long\
    \ p) {\n\t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint &a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint &b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint &b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint &b) { return a /= b; }\n};\n\ntemplate <class T>\
    \ struct IntervalUnion {\n\tconst T INF = std::numeric_limits<T>::max();\n\tstd::set<std::pair<T,\
    \ T>> le, ri;\n\n\tvoid reset() {\n\t\tle.clear();\n\t\tri.clear();\n\t}\n\n\t\
    // inserts an interval while returning the intervals it intersected with\n\tstd::vector<std::pair<T,\
    \ T>> insert(std::pair<T, T> x) {\n\t\tstd::set<std::pair<T, T>> bad;\n\t\tstd::vector<std::pair<T,\
    \ T>> ret;\n\t\tstd::pair<T, T> use1 = {x.first, -INF}, use2 = {x.second, INF};\n\
    \t\tauto it1 = le.lower_bound(use1);\n\t\tauto it2 = ri.lower_bound(use2);\n\t\
    \tif (it2 != ri.end()) {\n\t\t\tT lo = it2->second, hi = it2->first;\n\t\t\tif\
    \ (lo <= x.first && x.second <= hi) {\n\t\t\t\tret.emplace_back(lo, hi);\n\t\t\
    \t\tT mn = x.first, mx = x.second;\n\t\t\t\tfor (auto &b : ret) {\n\t\t\t\t\t\
    le.erase(b); ri.erase({b.second, b.first});\n\t\t\t\t\tmn = std::min(mn, b.first);\
    \ mx = std::max(mx, b.second);\n\t\t\t\t}\n\t\t\t\tle.emplace(mn, mx); ri.emplace(mx,\
    \ mn);\n\t\t\t\treturn ret;\n\t\t\t}\n\t\t}\n\t\tif (it1 != le.end()) {\n\t\t\t\
    while (it1 != le.end()) {\n\t\t\t\tauto val = (*it1);\n\t\t\t\tif (val.first <=\
    \ x.second) bad.insert(val);\n\t\t\t\telse break;\n\t\t\t\tit1 = next(it1);\n\t\
    \t\t}\n\t\t}\n\t\tif (it2 != ri.begin()) {\n\t\t\tit2 = prev(it2);\n\t\t\twhile\
    \ (true) {\n\t\t\t\tauto val = *it2;\n\t\t\t\tif (val.first >= x.first) bad.emplace(val.second,\
    \ val.first);\n\t\t\t\telse break;\n\t\t\t\tif (it2 == ri.begin()) break;\n\t\t\
    \t\tit2 = prev(it2);\n\t\t\t}\n\t\t}\n\t\tfor (auto &b : bad) ret.emplace_back(b);\n\
    \t\tT mn = x.first, mx = x.second;\n\t\tfor (auto &b : ret) {\n\t\t\tle.erase(b);\
    \ ri.erase({b.second, b.first});\n\t\t\tmn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\n\t\t}\n\t\tle.emplace(mn, mx); ri.emplace(mx, mn);\n\t\treturn ret;\n\
    \t}\n};\n\nusing mi = Mint<998244353, 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<IntervalUnion<int>>\
    \ iu(n);\n\tAffineSegmentTree<mi> seg;\n\tseg.init(n);\n\twhile (q--) {\n\t\t\
    int t;\n\t\tcin >> t;\n\t\tif (t == 1) {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >>\
    \ r >> x;\n\t\t\t--l, --r, --x;\n\t\t\tvector<pair<int, int>> use = iu[x].insert({l,\
    \ r});\n\t\t\tfor (auto &y : use) {\n\t\t\t\tseg.upd(1, max(l, y.first), min(r,\
    \ y.second), 2);\n\t\t\t}\n\t\t\tif (!use.empty()) {\n\t\t\t\tfor (int i = 0;\
    \ i < use.size() + 1; ++i) {\n\t\t\t\t\tif (i == 0) {\n\t\t\t\t\t\tseg.upd(0,\
    \ l, use[i].first - 1, 1);\n\t\t\t\t\t} else if (i != use.size()) {\n\t\t\t\t\t\
    \tseg.upd(0, use[i - 1].second + 1, use[i].first - 1, 1);\n\t\t\t\t\t} else {\n\
    \t\t\t\t\t\tseg.upd(0, use[i - 1].second + 1, r, 1);\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t} else {\n\t\t\t\tseg.upd(0, l, r, 1);\n\t\t\t}\n\t\t} else {\n\t\t\tint\
    \ l, r;\n\t\t\tcin >> l >> r;\n\t\t\t--l, --r;\n\t\t\tcout << seg.qsum(l, r) <<\
    \ '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/981/problem/G\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/affine-segment-tree.hpp\"\
    \n#include \"../../library/numerical/mod-int2.hpp\"\n#include \"../../library/data-structures/1d-range-queries/interval-union.hpp\"\
    \n\nusing mi = Mint<998244353, 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<IntervalUnion<int>>\
    \ iu(n);\n\tAffineSegmentTree<mi> seg;\n\tseg.init(n);\n\twhile (q--) {\n\t\t\
    int t;\n\t\tcin >> t;\n\t\tif (t == 1) {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >>\
    \ r >> x;\n\t\t\t--l, --r, --x;\n\t\t\tvector<pair<int, int>> use = iu[x].insert({l,\
    \ r});\n\t\t\tfor (auto &y : use) {\n\t\t\t\tseg.upd(1, max(l, y.first), min(r,\
    \ y.second), 2);\n\t\t\t}\n\t\t\tif (!use.empty()) {\n\t\t\t\tfor (int i = 0;\
    \ i < use.size() + 1; ++i) {\n\t\t\t\t\tif (i == 0) {\n\t\t\t\t\t\tseg.upd(0,\
    \ l, use[i].first - 1, 1);\n\t\t\t\t\t} else if (i != use.size()) {\n\t\t\t\t\t\
    \tseg.upd(0, use[i - 1].second + 1, use[i].first - 1, 1);\n\t\t\t\t\t} else {\n\
    \t\t\t\t\t\tseg.upd(0, use[i - 1].second + 1, r, 1);\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t} else {\n\t\t\t\tseg.upd(0, l, r, 1);\n\t\t\t}\n\t\t} else {\n\t\t\tint\
    \ l, r;\n\t\t\tcin >> l >> r;\n\t\t\t--l, --r;\n\t\t\tcout << seg.qsum(l, r) <<\
    \ '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/affine-segment-tree.hpp
  - library/numerical/mod-int2.hpp
  - library/data-structures/1d-range-queries/interval-union.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-981G.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-981G.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-981G.test.cpp
- /verify/verify/codeforces/codeforces-981G.test.cpp.html
title: verify/codeforces/codeforces-981G.test.cpp
---
