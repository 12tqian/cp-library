---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
    title: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  - icon: ':question:'
    path: library/numerical/mod-int2.hpp
    title: library/numerical/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class D, class L, class OpDD, class OpDL, class OpLL> struct LazySegmentTree\
    \ {\n\tD e_d;\n\tL e_l;\n\tOpDD op_dd; \n\tOpDL op_dl;\n\tOpLL op_ll;\n\tint sz,\
    \ lg;  \n\tstd::vector<D> d;\n\tstd::vector<L> lz;\n\n\tLazySegmentTree(const\
    \ std::vector<D>& v,\n\t\t\tD _e_d,\n\t\t\tL _e_l,\n\t\t\tOpDD _op_dd,\n\t\t\t\
    OpDL _op_dl,\n\t\t\tOpLL _op_ll)\n\t\t: e_d(_e_d), e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl),\
    \ op_ll(_op_ll) {\n\t\tint n = int(v.size());\n\t\tlg = 1;\n\t\twhile ((1 << lg)\
    \ < n) lg++;\n\t\tsz = 1 << lg;\n\t\td = std::vector<D>(2 * sz, e_d);\n\t\tlz\
    \ = std::vector<L>(2 * sz, e_l);\n\t\tfor (int i = 0; i < n; i++) d[sz + i] =\
    \ v[i];\n\t\tfor (int i = sz - 1; i >= 0; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t\
    }\n\n\tvoid all_add(int k, L x) {\n\t\td[k] = op_dl(d[k], x);\n\t\tif (k < sz)\
    \ lz[k] = op_ll(lz[k], x);\n\t}\n\n\tvoid push(int k) {\n\t\tall_add(2 * k, lz[k]);\n\
    \t\tall_add(2 * k + 1, lz[k]);\n\t\tlz[k] = e_l;\n\t}\n\n\tvoid update(int k)\
    \ { d[k] = op_dd(d[2 * k], d[2 * k + 1]); }\n\n\tvoid set(int p, D x) {\n\t\t\
    p += sz;\n\t\tfor (int i = lg; i >= 1; i--) push(p >> i);\n\t\td[p] = x;\n\t\t\
    for (int i = 1; i <= lg; i++) update(p >> i);\n\t}\n\n\tvoid add(int a, int b,\
    \ L x, int l, int r, int k) {\n\t\tif (b <= l || r <= a) return;\n\t\tif (a <=\
    \ l && r <= b) {\n\t\t\tall_add(k, x);\n\t\t\treturn;\n\t\t}\n\t\tpush(k);\n\t\
    \tint mid = (l + r) / 2;\n\t\tadd(a, b, x, l, mid, 2 * k);\n\t\tadd(a, b, x, mid,\
    \ r, 2 * k + 1);\n\t\tupdate(k);\n\t}\n\n\tvoid add(int a, int b, L x) {\n\t\t\
    a += sz;\n\t\tb += sz + 1;\n\t\tfor (int i = lg; i >= 1; i--) {\n\t\t\tif (((a\
    \ >> i) << i) != a) push(a >> i);\n\t\t\tif (((b >> i) << i) != b) push((b - 1)\
    \ >> i);\n\t\t}\n\t\t{\n\t\t\tint a2 = a, b2 = b;\n\t\t\twhile (a < b) {\n\t\t\
    \t\tif (a & 1) all_add(a++, x);\n\t\t\t\tif (b & 1) all_add(--b, x);\n\t\t\t\t\
    a >>= 1;\n\t\t\t\tb >>= 1;\n\t\t\t}\n\t\t\ta = a2;\n\t\t\tb = b2;\n\t\t}\n\t\t\
    for (int i = 1; i <= lg; i++) {\n\t\t\tif (((a >> i) << i) != a) update(a >> i);\n\
    \t\t\tif (((b >> i) << i) != b) update((b - 1) >> i);\n\t\t}\n\t}\n\n\tD single(int\
    \ p) {\n\t\tp += sz;\n\t\tfor (int i = lg; i >= 1; i--) push(p >> i);\n\t\treturn\
    \ d[p];\n\t}\n\n\tD sum(int a, int b, int l, int r, int k) {\n\t\tif (b <= l ||\
    \ r <= a) return e_d;\n\t\tif (a <= l && r <= b) return d[k];\n\t\tpush(k);\n\t\
    \tint mid = (l + r) / 2;\n\t\treturn op_dd(sum(a, b, l, mid, 2 * k), sum(a, b,\
    \ mid, r, 2 * k + 1));\n\t}\n\n\tD sum(int a, int b) {\n\t\tif (a == b) return\
    \ e_d;\n\t\ta += sz;\n\t\tb += sz + 1;\n\t\tfor (int i = lg; i >= 1; i--) {\n\t\
    \t\tif (((a >> i) << i) != a) push(a >> i);\n\t\t\tif (((b >> i) << i) != b) push((b\
    \ - 1) >> i);\n\t\t}\n\t\tD sml = e_d, smr = e_d;\n\t\twhile (a < b) {\n\t\t\t\
    if (a & 1) sml = op_dd(sml, d[a++]);\n\t\t\tif (b & 1) smr = op_dd(d[--b], smr);\n\
    \t\t\ta >>= 1;\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn op_dd(sml, smr);\n\t}\n\n\t\
    D all_sum() const { return d[1]; }\n};\n\ntemplate <class D, class L, class OpDD,\
    \ class OpDL, class OpLL>\nLazySegmentTree<D, L, OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D>\
    \ v,\n\t\t\t\t\t\t\t\t\t\tD e_d,\n\t\t\t\t\t\t\t\t\t\tL e_l,\n\t\t\t\t\t\t\t\t\
    \t\tOpDD op_dd,\n\t\t\t\t\t\t\t\t\t\tOpDL op_dl,\n\t\t\t\t\t\t\t\t\t\tOpLL op_ll)\
    \ {\n\treturn LazySegmentTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl,\
    \ op_ll);\n}\n\n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct\
    \ Mint {\n\tstatic const int mod = MOD;\n\tstatic constexpr Mint rt() { return\
    \ RT; } // primitive root for FFT\n\tint v; \n\texplicit operator int() const\
    \ { return v; } // explicit -> don't silently convert to int\n\tMint() { v = 0;\
    \ }\n\tMint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD);\
    \ if (v < 0) v += MOD; }\n\tfriend bool operator==(const Mint &a, const Mint &b)\
    \ { return a.v == b.v; }\n\tfriend bool operator!=(const Mint &a, const Mint &b)\
    \ { return !(a == b); }\n\tfriend bool operator<(const Mint &a, const Mint &b)\
    \ { return a.v < b.v; }\n\tfriend bool operator>(const Mint &a, const Mint &b)\
    \ { return a.v > b.v; }\n\tfriend bool operator<=(const Mint &a, const Mint &b)\
    \ { return a.v <= b.v; }\n\tfriend bool operator>=(const Mint &a, const Mint &b)\
    \ { return a.v >= b.v; }\n\tfriend std::istream& operator >> (std::istream &in,\
    \ Mint &a) { \n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\n\tfriend\
    \ std::ostream& operator << (std::ostream &os, const Mint &a) { return os << a.v;\
    \ }\n\tMint& operator+=(const Mint &m) { \n\t\tif ((v += m.v) >= MOD) v -= MOD;\
    \ \n\t\treturn *this; }\n\tMint& operator-=(const Mint &m) { \n\t\tif ((v -= m.v)\
    \ < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const Mint &m) { \n\
    \t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const Mint\
    \ &m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long p) {\n\
    \t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans\
    \ *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint &a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint &b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint &b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint &b) { return a /= b; }\n};\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\t\
    int n, q;\n\tcin >> n >> q;\n\tconst array<mi, 2> ID = {1, 0};\n\tauto comb =\
    \ [&](array<mi, 2> x, array<mi, 2> y) {\n\t\treturn array<mi, 2>{x[0] * y[0],\
    \ x[1] * y[0] + y[1]};\n\t};\n\tvector<array<mi, 2>> v(n);\n\tfor (int i = 0;\
    \ i < n; ++i) {\n\t\tcin >> v[i][0] >> v[i][1];\n\t}\n\tauto seg = get_lazy_segment_tree(\n\
    \t\tv, ID, ID, comb, comb, comb\n\t);\n\twhile (q--) {\n\t\tint t;\n\t\tcin >>\
    \ t;\n\t\tif (t == 0) {\n\t\t\tint p, c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\t\
    seg.set(p, {c, d});\n\t\t} else {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >>\
    \ x;\n\t\t\t--r;\n\t\t\tauto res = seg.sum(l, r);\n\t\t\tmi ans = res[0] * x +\
    \ res[1];\n\t\t\tcout << ans << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/general-full-segment-tree.hpp\"\
    \n#include \"../../library/numerical/mod-int2.hpp\"\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\t\
    int n, q;\n\tcin >> n >> q;\n\tconst array<mi, 2> ID = {1, 0};\n\tauto comb =\
    \ [&](array<mi, 2> x, array<mi, 2> y) {\n\t\treturn array<mi, 2>{x[0] * y[0],\
    \ x[1] * y[0] + y[1]};\n\t};\n\tvector<array<mi, 2>> v(n);\n\tfor (int i = 0;\
    \ i < n; ++i) {\n\t\tcin >> v[i][0] >> v[i][1];\n\t}\n\tauto seg = get_lazy_segment_tree(\n\
    \t\tv, ID, ID, comb, comb, comb\n\t);\n\twhile (q--) {\n\t\tint t;\n\t\tcin >>\
    \ t;\n\t\tif (t == 0) {\n\t\t\tint p, c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\t\
    seg.set(p, {c, d});\n\t\t} else {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >>\
    \ x;\n\t\t\t--r;\n\t\t\tauto res = seg.sum(l, r);\n\t\t\tmi ans = res[0] * x +\
    \ res[1];\n\t\t\tcout << ans << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  - library/numerical/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2021-07-30 21:40:50-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_set_range_composite.test.cpp
- /verify/verify/yosupo/yosupo-point_set_range_composite.test.cpp.html
title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
---
