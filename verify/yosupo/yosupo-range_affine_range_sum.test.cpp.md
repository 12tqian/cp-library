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
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
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
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n// 5 is a root of both mods\r\
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
    \ }\r\n};\r\n\r\ntemplate <class T> struct AffineSegmentTree {\r\n\tint sz;\r\n\
    \tstd::vector<T> sum, mult, add;\r\n\r\n\tvoid push(int ind, int L, int R) { //\
    \ modify values for current node\r\n\t\tsum[ind] *= mult[ind]; sum[ind] += (R\
    \ - L + 1) * add[ind];\r\n\t\tif (L != R) {\r\n\t\t\tmult[2 * ind] *= mult[ind];\
    \ mult[2 * ind + 1] *= mult[ind];\r\n\t\t\tadd[2 * ind] *= mult[ind]; add[2 *\
    \ ind] += add[ind];\r\n\t\t\tadd[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] +=\
    \ add[ind];\r\n\t\t}\r\n\t\tadd[ind] = 0; mult[ind] = 1;\r\n\t}\r\n\r\n\tvoid\
    \ init(int n) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < n) sz *= 2;\r\n\t\tmult.assign(2\
    \ * sz, 1);\r\n\t\tsum.assign(2 * sz, 0);\r\n\t\tadd.assign(2 * sz, 0);\r\n\t\
    }\r\n\r\n\tvoid pull(int ind) {\r\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind +\
    \ 1];\r\n\t}\r\n\r\n\t// t == 0 is add, t == 1 is for multiplying\r\n\tvoid upd(int\
    \ t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R\
    \ == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (hi < L || R < lo) return;\r\
    \n\t\tif (lo <= L && R <= hi) {\r\n\t\t\tif(t == 0) add[ind] = inc;  \r\n\t\t\t\
    else mult[ind] = inc;\r\n\t\t\tpush(ind, L, R); return;\r\n\t\t}\r\n\t\tint M\
    \ = (L + R) / 2;\r\n\t\tupd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc,\
    \ 2 * ind + 1, M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n\t\r\n\tT qsum(int lo, int\
    \ hi, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\
    \tpush(ind, L, R);\r\n\t\tif (lo > R || L > hi) return 0;\r\n\t\tif (lo <= L &&\
    \ R <= hi) return sum[ind];\r\n\t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};\r\n\r\
    \nusing mi = Mint<998244353, 5>;\r\n\r\nint main() {\r\n\tcin.tie(0)->sync_with_stdio(false);\r\
    \n\tint n, q;\r\n\tAffineSegmentTree<mi> seg;\r\n\tcin >> n >> q;\r\n\tseg.init(n);\r\
    \n\tvector<int> a(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\
    \n\t\tseg.upd(0, i, i, a[i]);\r\n\t}\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\t\
    cin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint l, r, b, c;\r\n\t\t\tcin >> l >> r\
    \ >> b >> c;\r\n\t\t\tseg.upd(1, l, r - 1, b);\r\n\t\t\tseg.upd(0, l, r - 1, c);\r\
    \n\t\t} else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\tcout << seg.qsum(l,\
    \ r - 1) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/modular-arithmetic/mod-int2.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/affine-segment-tree.hpp\"\
    \r\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\nint main() {\r\n\tcin.tie(0)->sync_with_stdio(false);\r\
    \n\tint n, q;\r\n\tAffineSegmentTree<mi> seg;\r\n\tcin >> n >> q;\r\n\tseg.init(n);\r\
    \n\tvector<int> a(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\
    \n\t\tseg.upd(0, i, i, a[i]);\r\n\t}\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\t\
    cin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint l, r, b, c;\r\n\t\t\tcin >> l >> r\
    \ >> b >> c;\r\n\t\t\tseg.upd(1, l, r - 1, b);\r\n\t\t\tseg.upd(0, l, r - 1, c);\r\
    \n\t\t} else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\tcout << seg.qsum(l,\
    \ r - 1) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/modular-arithmetic/mod-int2.hpp
  - library/data-structures/1d-range-queries/affine-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-range_affine_range_sum.test.cpp
- /verify/verify/yosupo/yosupo-range_affine_range_sum.test.cpp.html
title: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
---
