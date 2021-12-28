---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/2d-range-queries/wavelet-matrix.hpp
    title: library/data-structures/2d-range-queries/wavelet-matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n#include <immintrin.h>\n\nstruct bit_vector {\n\tusing u32 = uint32_t;\n\tusing\
    \ i64 = int64_t;\n\tusing u64 = uint64_t;\n\n\tstatic constexpr u32 w = 64;\n\t\
    std::vector<u64> block;\n\tstd::vector<u32> count;\n\tu32 n, zeros;\n\n\tinline\
    \ u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u; }\n\tinline\
    \ void set(u32 i) { block[i / w] |= 1LL << (i % w); }\n\n\tbit_vector() {}\n\t\
    bit_vector(int _n) { init(_n); }\n\t__attribute__((optimize(\"O3,unroll-loops\"\
    ))) void init(int _n) {\n\t\tn = zeros = _n;\n\t\tblock.resize(n / w + 1, 0);\n\
    \t\tcount.resize(block.size(), 0);\n\t}\n\n\t__attribute__((target(\"popcnt\"\
    ))) void build() {\n\t\tfor (u32 i = 1; i < block.size(); ++i)\n\t\t\tcount[i]\
    \ = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n\t\tzeros = rank0(n);\n\t}\n\
    \n\tinline u32 rank0(u32 i) const { return i - rank1(i); }\n\n\t__attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\n\t\treturn count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\n\t}\n};\n\ntemplate <typename S, typename T>\nstruct WaveletMatrix\
    \ {\n\tusing u32 = uint32_t;\n\tusing i64 = int64_t;\n\tusing u64 = uint64_t;\n\
    \n\tstruct BIT {\n\t\tu32 N;\n\t\tstd::vector<T> data;\n\n\t\tBIT() = default;\n\
    \t\tBIT(int size) { init(size); }\n\n\t\tvoid init(int size) {\n\t\t\tN = size;\n\
    \t\t\tdata.assign(N + 1, 0);\n\t\t}\n\n\t\t__attribute__((target(\"bmi\"))) void\
    \ add(u32 k, T x) {\n\t\t\tfor (++k; k <= N; k += _blsi_u32(k)) data[k] += x;\n\
    \t\t}\n\n\t\t__attribute__((target(\"bmi\"))) T sum(u32 k) const {\n\t\t\tT ret\
    \ = T();\n\t\t\tfor (; k; k = _blsr_u32(k)) ret += data[k];\n\t\t\treturn ret;\n\
    \t\t}\n\n\t\t__attribute__((target(\"bmi\"))) T sum(int l, int r) const {\n\t\t\
    \tT ret = T();\n\t\t\twhile (l != r) {\n\t\t\t\tif (l < r) {\n\t\t\t\t\tret +=\
    \ data[r];\n\t\t\t\t\tr = _blsr_u32(r);\n\t\t\t\t} else {\n\t\t\t\t\tret -= data[l];\n\
    \t\t\t\t\tl = _blsr_u32(l);\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn ret;\n\t\t}\n\t\
    };\n\n\tusing P = std::pair<S, S>;\n\tint n, lg;\n\tstd::vector<bit_vector> bv;\n\
    \tstd::vector<BIT> bit;\n\tstd::vector<P> ps;\n\tstd::vector<S> ys;\n\n\tWaveletMatrix()\
    \ {}\n\n\tvoid add_point(S x, S y) {\n\t\tps.emplace_back(x, y);\n\t\tys.emplace_back(y);\n\
    \t}\n\n\t__attribute__((optimize(\"O3\"))) void build() {\n\t\tsort(begin(ps),\
    \ end(ps));\n\t\tps.erase(unique(begin(ps), end(ps)), end(ps));\n\t\tn = ps.size();\n\
    \t\tsort(begin(ys), end(ys));\n\t\tys.erase(unique(begin(ys), end(ys)), end(ys));\n\
    \t\tstd::vector<u32> cur(n), nxt(n);\n\t\tfor (int i = 0; i < n; ++i) cur[i] =\
    \ yid(ps[i].second);\n\t\tlg = std::__lg(std::max(n, 1)) + 1;\n\t\tbv.assign(lg,\
    \ n);\n\t\tbit.assign(lg, n);\n\t\tfor (int h = lg - 1; h >= 0; --h) {\n\t\t\t\
    for (int i = 0; i < n; ++i)\n\t\t\t\tif ((cur[i] >> h) & 1) bv[h].set(i);\n\t\t\
    \tbv[h].build();\n\t\t\tstd::array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt)\
    \ + bv[h].zeros};\n\t\t\tfor (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n\
    \t\t\tswap(cur, nxt);\n\t\t}\n\t}\n\n\tint xid(S x) const {\n\t\treturn lower_bound(\n\
    \t\t\t\t\t\t\t begin(ps), end(ps), std::make_pair(x, S()),\n\t\t\t\t\t\t\t [](const\
    \ P& a, const P& b) { return a.first < b.first; }) -\n\t\t\t\t\t begin(ps);\n\t\
    }\n\n\tint yid(S y) const { return lower_bound(begin(ys), end(ys), y) - begin(ys);\
    \ }\n\n\tvoid add(S x, S y, T val) {\n\t\tint i = lower_bound(begin(ps), end(ps),\
    \ P{x, y}) - begin(ps);\n\t\tfor (int h = lg - 1; h >= 0; --h) {\n\t\t\tint i0\
    \ = bv[h].rank0(i);\n\t\t\tif (bv[h].get(i))\n\t\t\t\ti += bv[h].zeros - i0;\n\
    \t\t\telse\n\t\t\t\ti = i0;\n\t\t\tbit[h].add(i, val);\n\t\t}\n\t}\n\n\tT sum(int\
    \ l, int r, u32 upper) const {\n\t\tT res = 0;\n\t\tfor (int h = lg; h--;) {\n\
    \t\t\tint l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\t\t\tif ((upper >> h) &\
    \ 1) {\n\t\t\t\tres += bit[h].sum(l0, r0);\n\t\t\t\tl += bv[h].zeros - l0;\n\t\
    \t\t\tr += bv[h].zeros - r0;\n\t\t\t} else {\n\t\t\t\tl = l0, r = r0;\n\t\t\t\
    }\n\t\t}\n\t\treturn res;\n\t}\n\n\tT sum(S lx, S rx, S ly, S ry) const {\n\t\t\
    ++rx, ++ry;\n\t\tint l = xid(lx), r = xid(rx);\n\t\treturn sum(l, r, yid(ry))\
    \ - sum(l, r, yid(ly));\n\t}\n};\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tWaveletMatrix<int, long\
    \ long> wm;\n\tvector<int> x(n), y(n), w(n), c(q), s(q), t(q), u(q), v(q);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tcin >> x[i] >> y[i] >> w[i];\n\t\twm.add_point(x[i],\
    \ y[i]);\n\t}\n\tfor (int i = 0; i < q; ++i) { \n\t\tcin >> c[i] >> s[i] >> t[i]\
    \ >> u[i];\n\t\tif (c[i]) {\n\t\t\tcin >> v[i];\n\t\t} else {\n\t\t\twm.add_point(s[i],\
    \ t[i]);\n\t\t}\n\t}\n\twm.build();\n\tfor (int i = 0; i < n; ++i) {\n\t\twm.add(x[i],\
    \ y[i], w[i]);\n\t}\n\tfor (int i = 0; i < q; ++i) {\n\t\tif (c[i]) {\n\t\t\t\
    cout << wm.sum(s[i], u[i] - 1, t[i], v[i] - 1) << '\\n';\n\t\t} else {\n\t\t\t\
    wm.add(s[i], t[i], u[i]);\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/2d-range-queries/wavelet-matrix.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tWaveletMatrix<int, long long> wm;\n\tvector<int> x(n),\
    \ y(n), w(n), c(q), s(q), t(q), u(q), v(q);\n\tfor (int i = 0; i < n; ++i) {\n\
    \t\tcin >> x[i] >> y[i] >> w[i];\n\t\twm.add_point(x[i], y[i]);\n\t}\n\tfor (int\
    \ i = 0; i < q; ++i) { \n\t\tcin >> c[i] >> s[i] >> t[i] >> u[i];\n\t\tif (c[i])\
    \ {\n\t\t\tcin >> v[i];\n\t\t} else {\n\t\t\twm.add_point(s[i], t[i]);\n\t\t}\n\
    \t}\n\twm.build();\n\tfor (int i = 0; i < n; ++i) {\n\t\twm.add(x[i], y[i], w[i]);\n\
    \t}\n\tfor (int i = 0; i < q; ++i) {\n\t\tif (c[i]) {\n\t\t\tcout << wm.sum(s[i],\
    \ u[i] - 1, t[i], v[i] - 1) << '\\n';\n\t\t} else {\n\t\t\twm.add(s[i], t[i],\
    \ u[i]);\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/2d-range-queries/wavelet-matrix.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp
  requiredBy: []
  timestamp: '2021-12-27 21:29:57-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp
- /verify/verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp.html
title: verify/yosupo/yosupo-point_add_rectangle_sum-wavelet-matrix.test.cpp
---
