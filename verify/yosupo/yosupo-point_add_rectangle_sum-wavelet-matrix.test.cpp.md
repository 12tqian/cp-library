---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/2d-range-queries/wavelet-matrix.hpp
    title: library/data-structures/2d-range-queries/wavelet-matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n#include <immintrin.h>\r\n\
    \r\nstruct bit_vector {\r\n\tusing u32 = uint32_t;\r\n\tusing i64 = int64_t;\r\
    \n\tusing u64 = uint64_t;\r\n\r\n\tstatic constexpr u32 w = 64;\r\n\tstd::vector<u64>\
    \ block;\r\n\tstd::vector<u32> count;\r\n\tu32 n, zeros;\r\n\r\n\tinline u32 get(u32\
    \ i) const { return u32(block[i / w] >> (i % w)) & 1u; }\r\n\tinline void set(u32\
    \ i) { block[i / w] |= 1LL << (i % w); }\r\n\r\n\tbit_vector() {}\r\n\tbit_vector(int\
    \ _n) { init(_n); }\r\n\t__attribute__((optimize(\"O3,unroll-loops\"))) void init(int\
    \ _n) {\r\n\t\tn = zeros = _n;\r\n\t\tblock.resize(n / w + 1, 0);\r\n\t\tcount.resize(block.size(),\
    \ 0);\r\n\t}\r\n\r\n\t__attribute__((target(\"popcnt\"))) void build() {\r\n\t\
    \tfor (u32 i = 1; i < block.size(); ++i)\r\n\t\t\tcount[i] = count[i - 1] + _mm_popcnt_u64(block[i\
    \ - 1]);\r\n\t\tzeros = rank0(n);\r\n\t}\r\n\r\n\tinline u32 rank0(u32 i) const\
    \ { return i - rank1(i); }\r\n\r\n\t__attribute__((target(\"bmi2,popcnt\"))) inline\
    \ u32 rank1(u32 i) const {\r\n\t\treturn count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\r\n\t}\r\n};\r\n\r\ntemplate <typename S, typename T>\r\nstruct\
    \ WaveletMatrix {\r\n\tusing u32 = uint32_t;\r\n\tusing i64 = int64_t;\r\n\tusing\
    \ u64 = uint64_t;\r\n\r\n\tstruct BIT {\r\n\t\tu32 N;\r\n\t\tstd::vector<T> data;\r\
    \n\r\n\t\tBIT() = default;\r\n\t\tBIT(int size) { init(size); }\r\n\r\n\t\tvoid\
    \ init(int size) {\r\n\t\t\tN = size;\r\n\t\t\tdata.assign(N + 1, 0);\r\n\t\t\
    }\r\n\r\n\t\t__attribute__((target(\"bmi\"))) void add(u32 k, T x) {\r\n\t\t\t\
    for (++k; k <= N; k += _blsi_u32(k)) data[k] += x;\r\n\t\t}\r\n\r\n\t\t__attribute__((target(\"\
    bmi\"))) T sum(u32 k) const {\r\n\t\t\tT ret = T();\r\n\t\t\tfor (; k; k = _blsr_u32(k))\
    \ ret += data[k];\r\n\t\t\treturn ret;\r\n\t\t}\r\n\r\n\t\t__attribute__((target(\"\
    bmi\"))) T sum(int l, int r) const {\r\n\t\t\tT ret = T();\r\n\t\t\twhile (l !=\
    \ r) {\r\n\t\t\t\tif (l < r) {\r\n\t\t\t\t\tret += data[r];\r\n\t\t\t\t\tr = _blsr_u32(r);\r\
    \n\t\t\t\t} else {\r\n\t\t\t\t\tret -= data[l];\r\n\t\t\t\t\tl = _blsr_u32(l);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\treturn ret;\r\n\t\t}\r\n\t};\r\n\r\n\tusing P\
    \ = std::pair<S, S>;\r\n\tint n, lg;\r\n\tstd::vector<bit_vector> bv;\r\n\tstd::vector<BIT>\
    \ bit;\r\n\tstd::vector<P> ps;\r\n\tstd::vector<S> ys;\r\n\r\n\tWaveletMatrix()\
    \ {}\r\n\r\n\tvoid add_point(S x, S y) {\r\n\t\tps.emplace_back(x, y);\r\n\t\t\
    ys.emplace_back(y);\r\n\t}\r\n\r\n\t__attribute__((optimize(\"O3\"))) void build()\
    \ {\r\n\t\tsort(begin(ps), end(ps));\r\n\t\tps.erase(unique(begin(ps), end(ps)),\
    \ end(ps));\r\n\t\tn = ps.size();\r\n\t\tsort(begin(ys), end(ys));\r\n\t\tys.erase(unique(begin(ys),\
    \ end(ys)), end(ys));\r\n\t\tstd::vector<u32> cur(n), nxt(n);\r\n\t\tfor (int\
    \ i = 0; i < n; ++i) cur[i] = yid(ps[i].second);\r\n\t\tlg = std::__lg(std::max(n,\
    \ 1)) + 1;\r\n\t\tbv.assign(lg, n);\r\n\t\tbit.assign(lg, n);\r\n\t\tfor (int\
    \ h = lg - 1; h >= 0; --h) {\r\n\t\t\tfor (int i = 0; i < n; ++i)\r\n\t\t\t\t\
    if ((cur[i] >> h) & 1) bv[h].set(i);\r\n\t\t\tbv[h].build();\r\n\t\t\tstd::array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\r\n\t\t\tfor (int i = 0; i < n;\
    \ ++i) *it[bv[h].get(i)]++ = cur[i];\r\n\t\t\tswap(cur, nxt);\r\n\t\t}\r\n\t}\r\
    \n\r\n\tint xid(S x) const {\r\n\t\treturn lower_bound(\r\n\t\t\t\t\t\t\t begin(ps),\
    \ end(ps), std::make_pair(x, S()),\r\n\t\t\t\t\t\t\t [](const P& a, const P& b)\
    \ { return a.first < b.first; }) -\r\n\t\t\t\t\t begin(ps);\r\n\t}\r\n\r\n\tint\
    \ yid(S y) const { return lower_bound(begin(ys), end(ys), y) - begin(ys); }\r\n\
    \r\n\tvoid add(S x, S y, T val) {\r\n\t\tint i = lower_bound(begin(ps), end(ps),\
    \ P{x, y}) - begin(ps);\r\n\t\tfor (int h = lg - 1; h >= 0; --h) {\r\n\t\t\tint\
    \ i0 = bv[h].rank0(i);\r\n\t\t\tif (bv[h].get(i))\r\n\t\t\t\ti += bv[h].zeros\
    \ - i0;\r\n\t\t\telse\r\n\t\t\t\ti = i0;\r\n\t\t\tbit[h].add(i, val);\r\n\t\t\
    }\r\n\t}\r\n\r\n\tT sum(int l, int r, u32 upper) const {\r\n\t\tT res = 0;\r\n\
    \t\tfor (int h = lg; h--;) {\r\n\t\t\tint l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\
    \n\t\t\tif ((upper >> h) & 1) {\r\n\t\t\t\tres += bit[h].sum(l0, r0);\r\n\t\t\t\
    \tl += bv[h].zeros - l0;\r\n\t\t\t\tr += bv[h].zeros - r0;\r\n\t\t\t} else {\r\
    \n\t\t\t\tl = l0, r = r0;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\
    \tT sum(S lx, S rx, S ly, S ry) const {\r\n\t\t++rx, ++ry;\r\n\t\tint l = xid(lx),\
    \ r = xid(rx);\r\n\t\treturn sum(l, r, yid(ry)) - sum(l, r, yid(ly));\r\n\t}\r\
    \n};\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, q;\r\n\tcin >> n >> q;\r\n\tWaveletMatrix<int, long long> wm;\r\n\t\
    vector<int> x(n), y(n), w(n), c(q), s(q), t(q), u(q), v(q);\r\n\tfor (int i =\
    \ 0; i < n; ++i) {\r\n\t\tcin >> x[i] >> y[i] >> w[i];\r\n\t\twm.add_point(x[i],\
    \ y[i]);\r\n\t}\r\n\tfor (int i = 0; i < q; ++i) { \r\n\t\tcin >> c[i] >> s[i]\
    \ >> t[i] >> u[i];\r\n\t\tif (c[i]) {\r\n\t\t\tcin >> v[i];\r\n\t\t} else {\r\n\
    \t\t\twm.add_point(s[i], t[i]);\r\n\t\t}\r\n\t}\r\n\twm.build();\r\n\tfor (int\
    \ i = 0; i < n; ++i) {\r\n\t\twm.add(x[i], y[i], w[i]);\r\n\t}\r\n\tfor (int i\
    \ = 0; i < q; ++i) {\r\n\t\tif (c[i]) {\r\n\t\t\tcout << wm.sum(s[i], u[i] - 1,\
    \ t[i], v[i] - 1) << '\\n';\r\n\t\t} else {\r\n\t\t\twm.add(s[i], t[i], u[i]);\r\
    \n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/data-structures/2d-range-queries/wavelet-matrix.hpp\"\r\n\r\nint\
    \ main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n,\
    \ q;\r\n\tcin >> n >> q;\r\n\tWaveletMatrix<int, long long> wm;\r\n\tvector<int>\
    \ x(n), y(n), w(n), c(q), s(q), t(q), u(q), v(q);\r\n\tfor (int i = 0; i < n;\
    \ ++i) {\r\n\t\tcin >> x[i] >> y[i] >> w[i];\r\n\t\twm.add_point(x[i], y[i]);\r\
    \n\t}\r\n\tfor (int i = 0; i < q; ++i) { \r\n\t\tcin >> c[i] >> s[i] >> t[i] >>\
    \ u[i];\r\n\t\tif (c[i]) {\r\n\t\t\tcin >> v[i];\r\n\t\t} else {\r\n\t\t\twm.add_point(s[i],\
    \ t[i]);\r\n\t\t}\r\n\t}\r\n\twm.build();\r\n\tfor (int i = 0; i < n; ++i) {\r\
    \n\t\twm.add(x[i], y[i], w[i]);\r\n\t}\r\n\tfor (int i = 0; i < q; ++i) {\r\n\t\
    \tif (c[i]) {\r\n\t\t\tcout << wm.sum(s[i], u[i] - 1, t[i], v[i] - 1) << '\\n';\r\
    \n\t\t} else {\r\n\t\t\twm.add(s[i], t[i], u[i]);\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/2d-range-queries/wavelet-matrix.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp
- /verify/verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp.html
title: verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp
---
