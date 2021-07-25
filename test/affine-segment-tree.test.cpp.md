---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/affine-segment-tree.hpp
    title: library/data-structures/1d-range-queries/affine-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/mod-int2.hpp
    title: library/numerical/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\n// 5 is\
    \ a root of both mods\ntemplate <int MOD, int RT> struct Mint {\n\tstatic const\
    \ int mod = MOD;\n\tstatic constexpr Mint rt() { return RT; } // primitive root\
    \ for FFT\n\tint v; \n\texplicit operator int() const { return v; } // explicit\
    \ -> don't silently convert to int\n\tMint() { v = 0; }\n\tMint(long long _v)\
    \ { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\
    \tfriend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }\n\
    \tfriend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }\n\
    \tfriend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }\n\t\
    friend bool operator>(const Mint &a, const Mint &b) { return a.v > b.v; }\n\t\
    friend bool operator<=(const Mint &a, const Mint &b) { return a.v <= b.v; }\n\t\
    friend bool operator>=(const Mint &a, const Mint &b) { return a.v >= b.v; }\n\t\
    friend std::istream& operator >> (std::istream &in, Mint &a) { \n\t\tlong long\
    \ x; std::cin >> x; a = Mint(x); return in; }\n\tfriend std::ostream& operator\
    \ << (std::ostream &os, const Mint &a) { return os << a.v; }\n\tMint& operator+=(const\
    \ Mint &m) { \n\t\tif ((v += m.v) >= MOD) v -= MOD; \n\t\treturn *this; }\n\t\
    Mint& operator-=(const Mint &m) { \n\t\tif ((v -= m.v) < 0) v += MOD; \n\t\treturn\
    \ *this; }\n\tMint& operator*=(const Mint &m) { \n\t\tv = (long long)v * m.v %\
    \ MOD; return *this; }\n\tMint& operator/=(const Mint &m) { return (*this) *=\
    \ inv(m); }\n\tfriend Mint pow(Mint a, long long p) {\n\t\tMint ans = 1; assert(p\
    \ >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans;\
    \ \n\t}\n\tfriend Mint inv(const Mint &a) { assert(a.v != 0); return pow(a, MOD\
    \ - 2); }\n\tMint operator-() const { return Mint(-v); }\n\tMint& operator++()\
    \ { return *this += 1; }\n\tMint& operator--() { return *this -= 1; }\n\tfriend\
    \ Mint operator+(Mint a, const Mint &b) { return a += b; }\n\tfriend Mint operator-(Mint\
    \ a, const Mint &b) { return a -= b; }\n\tfriend Mint operator*(Mint a, const\
    \ Mint &b) { return a *= b; }\n\tfriend Mint operator/(Mint a, const Mint &b)\
    \ { return a /= b; }\n};\n\ntemplate <class T> struct AffineSegmentTree {\n\t\
    int sz;\n\tstd::vector<T> sum, mult, add;\n\n\tvoid push(int ind, int L, int R)\
    \ { // modify values for current node\n\t\tsum[ind] *= mult[ind]; sum[ind] +=\
    \ (R - L + 1) * add[ind];\n\t\tif (L != R) {\n\t\t\tmult[2 * ind] *= mult[ind];\
    \ mult[2 * ind + 1] *= mult[ind];\n\t\t\tadd[2 * ind] *= mult[ind]; add[2 * ind]\
    \ += add[ind];\n\t\t\tadd[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n\
    \t\t}\n\t\tadd[ind] = 0; mult[ind] = 1;\n\t}\n\n\tvoid init(int n) {\n\t\tsz =\
    \ 1;\n\t\twhile (sz < n) sz *= 2;\n\t\tmult.assign(2 * sz, 1);\n\t\tsum.assign(2\
    \ * sz, 0);\n\t\tadd.assign(2 * sz, 0);\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind]\
    \ = sum[2 * ind] + sum[2 * ind + 1];\n\t}\n\n\t// t == 0 is add, t == 1 is for\
    \ multiplying\n\tvoid upd(int t, int lo, int hi, T inc, int ind = 1, int L = 0,\
    \ int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi <\
    \ L || R < lo) return;\n\t\tif (lo <= L && R <= hi) {\n\t\t\tif(t == 0) add[ind]\
    \ = inc;  \n\t\t\telse mult[ind] = inc;\n\t\t\tpush(ind, L, R); return;\n\t\t\
    }\n\t\tint M = (L + R) / 2;\n\t\tupd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo,\
    \ hi, inc, 2 * ind + 1, M + 1, R);\n\t\tpull(ind);\n\t}\n\t\n\tT qsum(int lo,\
    \ int hi, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\
    \tpush(ind, L, R);\n\t\tif (lo > R || L > hi) return 0;\n\t\tif (lo <= L && R\
    \ <= hi) return sum[ind];\n\t\tint M = (L + R) / 2;\n\t\treturn qsum(lo, hi, 2\
    \ * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n\t}\n};\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nint main() {\n\tcin.tie(0)->sync_with_stdio(false);\n\tint n, q;\n\t\
    AffineSegmentTree<mi> seg;\n\tcin >> n >> q;\n\tseg.init(n);\n\tvector<int> a(n);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tcin >> a[i];\n\t\tseg.upd(0, i, i, a[i]);\n\
    \t}\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ l, r, b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tseg.upd(1, l, r - 1, b);\n\
    \t\t\tseg.upd(0, l, r - 1, c);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l\
    \ >> r;\n\t\t\tcout << seg.qsum(l, r - 1) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/numerical/mod-int2.hpp\"\
    \n#include \"../library/data-structures/1d-range-queries/affine-segment-tree.hpp\"\
    \n\nusing mi = Mint<998244353, 5>;\n\nint main() {\n\tcin.tie(0)->sync_with_stdio(false);\n\
    \tint n, q;\n\tAffineSegmentTree<mi> seg;\n\tcin >> n >> q;\n\tseg.init(n);\n\t\
    vector<int> a(n);\n\tfor (int i = 0; i < n; i++) {\n\t\tcin >> a[i];\n\t\tseg.upd(0,\
    \ i, i, a[i]);\n\t}\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t ==\
    \ 0) {\n\t\t\tint l, r, b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tseg.upd(1,\
    \ l, r - 1, b);\n\t\t\tseg.upd(0, l, r - 1, c);\n\t\t} else {\n\t\t\tint l, r;\n\
    \t\t\tcin >> l >> r;\n\t\t\tcout << seg.qsum(l, r - 1) << '\\n';\n\t\t}\n\t}\n\
    \treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/mod-int2.hpp
  - library/data-structures/1d-range-queries/affine-segment-tree.hpp
  isVerificationFile: true
  path: test/affine-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 21:44:19-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/affine-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/test/affine-segment-tree.test.cpp
- /verify/test/affine-segment-tree.test.cpp.html
title: test/affine-segment-tree.test.cpp
---
