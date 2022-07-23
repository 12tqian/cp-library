---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/data-structures/1d-range-queries/affine-segment-tree.hpp
    title: library/data-structures/1d-range-queries/affine-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/interval-union.hpp
    title: library/data-structures/1d-range-queries/interval-union.hpp
  - icon: ':question:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
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
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/981/problem/G\"\r\
    \n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> struct\
    \ AffineSegmentTree {\r\n\tint sz;\r\n\tstd::vector<T> sum, mult, add;\r\n\r\n\
    \tvoid push(int ind, int L, int R) { // modify values for current node\r\n\t\t\
    sum[ind] *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\r\n\t\tif (L != R)\
    \ {\r\n\t\t\tmult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\r\n\t\
    \t\tadd[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\r\n\t\t\tadd[2 * ind\
    \ + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\r\n\t\t}\r\n\t\tadd[ind] =\
    \ 0; mult[ind] = 1;\r\n\t}\r\n\r\n\tvoid init(int n) {\r\n\t\tsz = 1;\r\n\t\t\
    while (sz < n) sz *= 2;\r\n\t\tmult.assign(2 * sz, 1);\r\n\t\tsum.assign(2 * sz,\
    \ 0);\r\n\t\tadd.assign(2 * sz, 0);\r\n\t}\r\n\r\n\tvoid pull(int ind) {\r\n\t\
    \tsum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\n\t}\r\n\r\n\t// t == 0 is add,\
    \ t == 1 is for multiplying\r\n\tvoid upd(int t, int lo, int hi, T inc, int ind\
    \ = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind,\
    \ L, R);\r\n\t\tif (hi < L || R < lo) return;\r\n\t\tif (lo <= L && R <= hi) {\r\
    \n\t\t\tif(t == 0) add[ind] = inc;  \r\n\t\t\telse mult[ind] = inc;\r\n\t\t\t\
    push(ind, L, R); return;\r\n\t\t}\r\n\t\tint M = (L + R) / 2;\r\n\t\tupd(t, lo,\
    \ hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1, M + 1, R);\r\n\t\t\
    pull(ind);\r\n\t}\r\n\t\r\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (lo\
    \ > R || L > hi) return 0;\r\n\t\tif (lo <= L && R <= hi) return sum[ind];\r\n\
    \t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo,\
    \ hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};\r\n\r\n// 5 is a root of both mods\r\
    \ntemplate <int MOD, int RT> struct Mint {\r\n\tstatic const int mod = MOD;\r\n\
    \tstatic constexpr Mint rt() { return RT; } // primitive root for FFT\r\n\tstatic\
    \ constexpr int md() { return MOD; } // primitive root for FFT\r\n\tint v; \r\n\
    \texplicit operator int() const { return v; } // explicit -> don't silently convert\
    \ to int\r\n\texplicit operator bool() const { return v != 0; }\r\n\tMint() {\
    \ v = 0; }\r\n\tMint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v\
    \ % MOD); if (v < 0) v += MOD; }\r\n\tfriend bool operator==(const Mint& a, const\
    \ Mint& b) { return a.v == b.v; }\r\n\tfriend bool operator!=(const Mint& a, const\
    \ Mint& b) { return !(a == b); }\r\n\tfriend bool operator<(const Mint& a, const\
    \ Mint& b) { return a.v < b.v; }\r\n\tfriend bool operator>(const Mint& a, const\
    \ Mint& b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const Mint& a, const\
    \ Mint& b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const Mint& a, const\
    \ Mint& b) { return a.v >= b.v; }\r\n\tfriend std::istream& operator >> (std::istream&\
    \ in, Mint& a) { \r\n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\r\
    \n\tfriend std::ostream& operator << (std::ostream& os, const Mint& a) { return\
    \ os << a.v; }\r\n\tMint& operator+=(const Mint& m) { \r\n\t\tif ((v += m.v) >=\
    \ MOD) v -= MOD; \r\n\t\treturn *this; }\r\n\tMint& operator-=(const Mint& m)\
    \ { \r\n\t\tif ((v -= m.v) < 0) v += MOD; \r\n\t\treturn *this; }\r\n\tMint& operator*=(const\
    \ Mint& m) { \r\n\t\tv = (long long)v * m.v % MOD; return *this; }\r\n\tMint&\
    \ operator/=(const Mint& m) { return (*this) *= inv(m); }\r\n\tfriend Mint pow(Mint\
    \ a, long long p) {\r\n\t\tMint ans = 1; assert(p >= 0);\r\n\t\tfor (; p; p /=\
    \ 2, a *= a) if (p & 1) ans *= a;\r\n\t\treturn ans; \r\n\t}\r\n\tfriend Mint\
    \ inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }\r\n\tMint operator-()\
    \ const { return Mint(-v); }\r\n\tMint& operator++() { return *this += 1; }\r\n\
    \tMint& operator--() { return *this -= 1; }\r\n\tfriend Mint operator+(Mint a,\
    \ const Mint& b) { return a += b; }\r\n\tfriend Mint operator-(Mint a, const Mint&\
    \ b) { return a -= b; }\r\n\tfriend Mint operator*(Mint a, const Mint& b) { return\
    \ a *= b; }\r\n\tfriend Mint operator/(Mint a, const Mint& b) { return a /= b;\
    \ }\r\n};\r\n\r\ntemplate <class T> struct IntervalUnion {\r\n\tconst T INF =\
    \ std::numeric_limits<T>::max();\r\n\tstd::set<std::pair<T, T>> le, ri;\r\n\r\n\
    \tvoid reset() {\r\n\t\tle.clear();\r\n\t\tri.clear();\r\n\t}\r\n\r\n\t// inserts\
    \ an interval while returning the intervals it intersected with\r\n\tstd::vector<std::pair<T,\
    \ T>> insert(std::pair<T, T> x) {\r\n\t\tstd::set<std::pair<T, T>> bad;\r\n\t\t\
    std::vector<std::pair<T, T>> ret;\r\n\t\tstd::pair<T, T> use1 = {x.first, -INF},\
    \ use2 = {x.second, INF};\r\n\t\tauto it1 = le.lower_bound(use1);\r\n\t\tauto\
    \ it2 = ri.lower_bound(use2);\r\n\t\tif (it2 != ri.end()) {\r\n\t\t\tT lo = it2->second,\
    \ hi = it2->first;\r\n\t\t\tif (lo <= x.first && x.second <= hi) {\r\n\t\t\t\t\
    ret.emplace_back(lo, hi);\r\n\t\t\t\tT mn = x.first, mx = x.second;\r\n\t\t\t\t\
    for (auto& b : ret) {\r\n\t\t\t\t\tle.erase(b); ri.erase({b.second, b.first});\r\
    \n\t\t\t\t\tmn = std::min(mn, b.first); mx = std::max(mx, b.second);\r\n\t\t\t\
    \t}\r\n\t\t\t\tle.emplace(mn, mx); ri.emplace(mx, mn);\r\n\t\t\t\treturn ret;\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif (it1 != le.end()) {\r\n\t\t\twhile (it1 != le.end())\
    \ {\r\n\t\t\t\tauto val = (*it1);\r\n\t\t\t\tif (val.first <= x.second) bad.insert(val);\r\
    \n\t\t\t\telse break;\r\n\t\t\t\tit1 = next(it1);\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    if (it2 != ri.begin()) {\r\n\t\t\tit2 = prev(it2);\r\n\t\t\twhile (true) {\r\n\
    \t\t\t\tauto val = *it2;\r\n\t\t\t\tif (val.first >= x.first) bad.emplace(val.second,\
    \ val.first);\r\n\t\t\t\telse break;\r\n\t\t\t\tif (it2 == ri.begin()) break;\r\
    \n\t\t\t\tit2 = prev(it2);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (auto& b : bad) ret.emplace_back(b);\r\
    \n\t\tT mn = x.first, mx = x.second;\r\n\t\tfor (auto& b : ret) {\r\n\t\t\tle.erase(b);\
    \ ri.erase({b.second, b.first});\r\n\t\t\tmn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\r\n\t\t}\r\n\t\tle.emplace(mn, mx); ri.emplace(mx, mn);\r\n\t\treturn\
    \ ret;\r\n\t}\r\n};\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\nint main() {\r\n\
    \tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr); \r\n\tint n, q;\r\n\tcin\
    \ >> n >> q;\r\n\tvector<IntervalUnion<int>> iu(n);\r\n\tAffineSegmentTree<mi>\
    \ seg;\r\n\tseg.init(n);\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\
    \t\tif (t == 1) {\r\n\t\t\tint l, r, x;\r\n\t\t\tcin >> l >> r >> x;\r\n\t\t\t\
    --l, --r, --x;\r\n\t\t\tvector<pair<int, int>> use = iu[x].insert({l, r});\r\n\
    \t\t\tfor (auto &y : use) {\r\n\t\t\t\tseg.upd(1, max(l, y.first), min(r, y.second),\
    \ 2);\r\n\t\t\t}\r\n\t\t\tif (!use.empty()) {\r\n\t\t\t\tfor (int i = 0; i < use.size()\
    \ + 1; ++i) {\r\n\t\t\t\t\tif (i == 0) {\r\n\t\t\t\t\t\tseg.upd(0, l, use[i].first\
    \ - 1, 1);\r\n\t\t\t\t\t} else if (i != use.size()) {\r\n\t\t\t\t\t\tseg.upd(0,\
    \ use[i - 1].second + 1, use[i].first - 1, 1);\r\n\t\t\t\t\t} else {\r\n\t\t\t\
    \t\t\tseg.upd(0, use[i - 1].second + 1, r, 1);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\
    \t\t\t} else {\r\n\t\t\t\tseg.upd(0, l, r, 1);\r\n\t\t\t}\r\n\t\t} else {\r\n\t\
    \t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--l, --r;\r\n\t\t\tcout << seg.qsum(l,\
    \ r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/981/problem/G\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/affine-segment-tree.hpp\"\
    \r\n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\r\n#include \"\
    ../../library/data-structures/1d-range-queries/interval-union.hpp\"\r\n\r\nusing\
    \ mi = Mint<998244353, 5>;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr); \r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<IntervalUnion<int>>\
    \ iu(n);\r\n\tAffineSegmentTree<mi> seg;\r\n\tseg.init(n);\r\n\twhile (q--) {\r\
    \n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 1) {\r\n\t\t\tint l, r, x;\r\n\t\
    \t\tcin >> l >> r >> x;\r\n\t\t\t--l, --r, --x;\r\n\t\t\tvector<pair<int, int>>\
    \ use = iu[x].insert({l, r});\r\n\t\t\tfor (auto &y : use) {\r\n\t\t\t\tseg.upd(1,\
    \ max(l, y.first), min(r, y.second), 2);\r\n\t\t\t}\r\n\t\t\tif (!use.empty())\
    \ {\r\n\t\t\t\tfor (int i = 0; i < use.size() + 1; ++i) {\r\n\t\t\t\t\tif (i ==\
    \ 0) {\r\n\t\t\t\t\t\tseg.upd(0, l, use[i].first - 1, 1);\r\n\t\t\t\t\t} else\
    \ if (i != use.size()) {\r\n\t\t\t\t\t\tseg.upd(0, use[i - 1].second + 1, use[i].first\
    \ - 1, 1);\r\n\t\t\t\t\t} else {\r\n\t\t\t\t\t\tseg.upd(0, use[i - 1].second +\
    \ 1, r, 1);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t} else {\r\n\t\t\t\tseg.upd(0,\
    \ l, r, 1);\r\n\t\t\t}\r\n\t\t} else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >>\
    \ r;\r\n\t\t\t--l, --r;\r\n\t\t\tcout << seg.qsum(l, r) << '\\n';\r\n\t\t}\r\n\
    \t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/affine-segment-tree.hpp
  - library/modular-arithmetic/mod-int2.hpp
  - library/data-structures/1d-range-queries/interval-union.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-981G.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-981G.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-981G.test.cpp
- /verify/verify/codeforces/codeforces-981G.test.cpp.html
title: verify/codeforces/codeforces-981G.test.cpp
---
