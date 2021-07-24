---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\n/**\n * 0 is ckmin, 1 is ckmax, 2 is range add\n */\ntemplate <class\
    \ C> struct SegmentTreeBeats {\n\tusing T = std::pair<std::pair<C, C>, int>;\n\
    \tconst C INF = std::numeric_limits<C>::max();\n\tstd::vector<C> mx_mod, mn_mod,\
    \ mod, sum;\n\tstd::vector<T> mx, mn;\n\tint sz; \n\n\tvoid init(int sz_) {\n\t\
    \tsz = 1; \n\t\twhile (sz < sz_) sz *= 2;\n\t\tmx_mod.assign(2 * sz, 0);\n\t\t\
    mn_mod.assign(2 * sz, 0);\n\t\tmod.assign(2 * sz, 0);\n\t\tsum.assign(2 * sz,\
    \ 0);\n\t\tmx.assign(2 * sz, {{0, 0}, 0});\n\t\tmn.assign(2 * sz, {{0, 0}, 0});\n\
    \t\tbuild();\n\t}\n\n\tvoid build(int ind = 1, int L = 0, int R = -1) {\n\t\t\
    if (R == -1) R += sz;\n\t\tmx_mod[ind] = INF, mn_mod[ind] = -INF, mod[ind] = 0;\n\
    \t\tif (L == R) {\n\t\t\tmx[ind] = {{0, -INF}, 1};\n\t\t\tmn[ind] = {{0, INF},\
    \ 1};\n\t\t\tsum[ind] = 0;\n\t\t\treturn;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\
    \tbuild(2 * ind, L, M); build(2 * ind + 1, M + 1, R);\n\t\tpull(ind);\n\t}\n\n\
    \tT comb_mn(T a, T b) {\n\t\tif (a > b) \n\t\t\tstd::swap(a, b);\n\t\tif (a.first.first\
    \ == b.first.first) \n\t\t\treturn  {{a.first.first, \n\t\t\t\tstd::min(a.first.second,\
    \ b.first.second)}, \n\t\t\t\ta.second + b.second};\n\t\treturn {{a.first.first,\
    \ std::min(a.first.second, b.first.first)}, a.second};\n\t}\n\n\tT comb_mx(T a,\
    \ T b) {\n\t\tif (a < b) std::swap(a, b);\n\t\tif (a.first.first == b.first.first)\
    \ \n\t\t\treturn  {{a.first.first, \n\t\t\t\tstd::max(a.first.second, b.first.second)},\
    \ \n\t\t\t\ta.second + b.second};\n\t\treturn {{a.first.first, std::max(a.first.second,\
    \ b.first.first)}, \n\t\t\ta.second};\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind]\
    \ = sum[2 * ind] + sum[2 * ind + 1];\n\t\tmn[ind] = comb_mn(mn[2 * ind], mn[2\
    \ * ind + 1]);\n\t\tmx[ind] = comb_mx(mx[2 * ind], mx[2 * ind + 1]);\n\t}\n\n\t\
    void push(int ind, int L, int R) {\n\t\tauto chk = [](C &a, C b, C c) {\n\t\t\t\
    if (a == b)\n\t\t\t\ta = c;\n\t\t};\n\t\tif (mn_mod[ind] != -INF) {\n\t\t\tif\
    \ (mn_mod[ind] > mn[ind].first.first) {\n\t\t\t\tsum[ind] += (mn_mod[ind] - mn[ind].first.first)\
    \ * mn[ind].second;\n\t\t\t\tchk(mx[ind].first.first, mn[ind].first.first, mn_mod[ind]);\n\
    \t\t\t\tchk(mx[ind].first.second, mn[ind].first.first, mn_mod[ind]);\n\t\t\t\t\
    mn[ind].first.first = mn_mod[ind];\n\t\t\t\tif (L != R) {\n\t\t\t\t\tfor (int\
    \ i = 0; i < 2; i++) {\n\t\t\t\t\t\tint pos = 2 * ind + i;\n\t\t\t\t\t\tmn_mod[pos]\
    \ = std::max(mn_mod[pos], mn_mod[ind] - mod[pos]);\n\t\t\t\t\t\tmx_mod[pos] =\
    \ std::max(mx_mod[pos], mn_mod[pos]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    mn_mod[ind] = -INF;\n\t\t}\n\t\tif (mx_mod[ind] != INF) {\n\t\t\tif (mx_mod[ind]\
    \ < mx[ind].first.first) {\n\t\t\t\tsum[ind] += (mx_mod[ind] - mx[ind].first.first)\
    \ * mx[ind].second;\n\t\t\t\tchk(mn[ind].first.first, mx[ind].first.first, mx_mod[ind]);\n\
    \t\t\t\tchk(mn[ind].first.second, mx[ind].first.first, mx_mod[ind]);\n\t\t\t\t\
    mx[ind].first.first = mx_mod[ind];\n\t\t\t\tif (L != R) {\n\t\t\t\t\tfor (int\
    \ i = 0; i < 2; i++) {\n\t\t\t\t\t\tint pos = 2 * ind + i;\n\t\t\t\t\t\tmx_mod[pos]\
    \ = std::min(mx_mod[pos], mx_mod[ind] - mod[pos]);\n\t\t\t\t\t\tmn_mod[pos] =\
    \ std::min(mn_mod[pos], mx_mod[pos]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    mx_mod[ind] = INF;\n\t\t}\n\t\tif (mod[ind] != 0) {\n\t\t\tsum[ind] += mod[ind]\
    \ * (R - L + 1);\n\t\t\tauto inc = [&](T &a, C b) {\n\t\t\t\tif (std::abs(a.first.first)\
    \ != INF) \n\t\t\t\t\ta.first.first += b;\n\t\t\t\tif (std::abs(a.first.second)\
    \ != INF)\n\t\t\t\t\ta.first.second += b;\n\t\t\t};\n\t\t\tinc(mx[ind], mod[ind]);\
    \ inc(mn[ind], mod[ind]);\n\t\t\tif (L != R) {\n\t\t\t\tfor (int i = 0; i < 2;\
    \ i++) {\n\t\t\t\t\tint pos = 2 * ind + i;\n\t\t\t\t\tmod[pos] += mod[ind];\n\t\
    \t\t\t}\n\t\t\t}\n\t\t\tmod[ind] = 0;\n\t\t}\n\t}\n\n\tC qsum(int lo, int hi,\
    \ int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind,\
    \ L, R);\n\t\tif (R < lo || hi < L)\n\t\t\treturn 0;\n\t\tif (lo <= L && R <=\
    \ hi)     \n\t\t\treturn sum[ind];\n\t\tint M = (L + R) / 2;\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n\t}\n\n\tC qmax(int\
    \ lo, int hi, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\
    \t\tpush(ind, L, R);\n\t\tif (R < lo || hi < L)\n\t\t\treturn -INF;\n\t\tif (lo\
    \ <= L && R <= hi)     \n\t\t\treturn mx[ind].first.first;\n\t\tint M = (L + R)\
    \ / 2;\n\t\treturn std::max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind\
    \ + 1, M + 1, R));\n\t}\n\n\tC qmin(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (R < lo ||\
    \ hi < L)\n\t\t\treturn INF;\n\t\tif (lo <= L && R <= hi)     \n\t\t\treturn mn[ind].first.first;\n\
    \t\tint M = (L + R) / 2;\n\t\treturn std::min(qmin(lo, hi, 2 * ind, L, M), qmin(lo,\
    \ hi, 2 * ind + 1, M + 1, R));\n\t}\n\t\n\tvoid upd(int t, int lo, int hi, C b,\
    \ int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind,\
    \ L, R);\n\t\tif (R < lo || hi < L) \n\t\t\treturn;\n\t\tif (t == 0) \n\t\t\t\
    if (b >= mx[ind].first.first)\n\t\t\t\treturn;\n\t\telse if (t == 1)\n\t\t\tif\
    \ (b <= mn[ind].first.first)\n\t\t\t\treturn;\n\t\tif (lo <= L && R <= hi) {\n\
    \t\t\tif (t == 0) {\n\t\t\t\tif (b  > mx[ind].first.second) {\n\t\t\t\t\tmx_mod[ind]\
    \ = b;\n\t\t\t\t\tpush(ind, L, R);\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t} else\
    \ if (t == 1) {\n\t\t\t\tif (b < mn[ind].first.second) {\n\t\t\t\t\tmn_mod[ind]\
    \ = b;\n\t\t\t\t\tpush(ind, L, R);\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t} else\
    \ if (t == 2) {\n\t\t\t\tmod[ind] = b;\n\t\t\t\tpush(ind, L, R);\n\t\t\t\treturn;\n\
    \t\t\t} else assert(false);\n\t\t}\n\t\tassert(L != R);\n\t\tint M = (L + R) /\
    \ 2;\n\t\tupd(t, lo, hi, b, 2 * ind, L, M); upd(t, lo, hi, b, 2 * ind + 1, M +\
    \ 1, R);\n\t\tpull(ind);\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\t\
    ios_base::sync_with_stdio(0);\n\tint n, q; cin >> n >> q;\n\tSegmentTreeBeats<long\
    \ long> S;\n\tS.init(n);\n\tstd::vector<long long> a(n);\n\tfor (int i = 0; i\
    \ < n; i++)\n\t   \n\t\tcin >> a[i], S.upd(2, i, i, a[i]);\n\twhile (q--) {\n\t\
    \tint t, l, r; cin >> t >> l >> r;\n\t\tr--;\n\t\tif (t <= 2) {\n\t\t\tlong long\
    \ b; cin >> b;\n\t\t\tS.upd(t, l, r, b);\n\t\t} else {\n\t\t\tcout << S.qsum(l,\
    \ r) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#pragma once\n\n/**\n * 0 is ckmin, 1 is ckmax, 2 is range add\n */\ntemplate\
    \ <class C> struct SegmentTreeBeats {\n\tusing T = std::pair<std::pair<C, C>,\
    \ int>;\n\tconst C INF = std::numeric_limits<C>::max();\n\tstd::vector<C> mx_mod,\
    \ mn_mod, mod, sum;\n\tstd::vector<T> mx, mn;\n\tint sz; \n\n\tvoid init(int sz_)\
    \ {\n\t\tsz = 1; \n\t\twhile (sz < sz_) sz *= 2;\n\t\tmx_mod.assign(2 * sz, 0);\n\
    \t\tmn_mod.assign(2 * sz, 0);\n\t\tmod.assign(2 * sz, 0);\n\t\tsum.assign(2 *\
    \ sz, 0);\n\t\tmx.assign(2 * sz, {{0, 0}, 0});\n\t\tmn.assign(2 * sz, {{0, 0},\
    \ 0});\n\t\tbuild();\n\t}\n\n\tvoid build(int ind = 1, int L = 0, int R = -1)\
    \ {\n\t\tif (R == -1) R += sz;\n\t\tmx_mod[ind] = INF, mn_mod[ind] = -INF, mod[ind]\
    \ = 0;\n\t\tif (L == R) {\n\t\t\tmx[ind] = {{0, -INF}, 1};\n\t\t\tmn[ind] = {{0,\
    \ INF}, 1};\n\t\t\tsum[ind] = 0;\n\t\t\treturn;\n\t\t}\n\t\tint M = (L + R) /\
    \ 2;\n\t\tbuild(2 * ind, L, M); build(2 * ind + 1, M + 1, R);\n\t\tpull(ind);\n\
    \t}\n\n\tT comb_mn(T a, T b) {\n\t\tif (a > b) \n\t\t\tstd::swap(a, b);\n\t\t\
    if (a.first.first == b.first.first) \n\t\t\treturn  {{a.first.first, \n\t\t\t\t\
    std::min(a.first.second, b.first.second)}, \n\t\t\t\ta.second + b.second};\n\t\
    \treturn {{a.first.first, std::min(a.first.second, b.first.first)}, a.second};\n\
    \t}\n\n\tT comb_mx(T a, T b) {\n\t\tif (a < b) std::swap(a, b);\n\t\tif (a.first.first\
    \ == b.first.first) \n\t\t\treturn  {{a.first.first, \n\t\t\t\tstd::max(a.first.second,\
    \ b.first.second)}, \n\t\t\t\ta.second + b.second};\n\t\treturn {{a.first.first,\
    \ std::max(a.first.second, b.first.first)}, \n\t\t\ta.second};\n\t}\n\n\tvoid\
    \ pull(int ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n\t\tmn[ind]\
    \ = comb_mn(mn[2 * ind], mn[2 * ind + 1]);\n\t\tmx[ind] = comb_mx(mx[2 * ind],\
    \ mx[2 * ind + 1]);\n\t}\n\n\tvoid push(int ind, int L, int R) {\n\t\tauto chk\
    \ = [](C &a, C b, C c) {\n\t\t\tif (a == b)\n\t\t\t\ta = c;\n\t\t};\n\t\tif (mn_mod[ind]\
    \ != -INF) {\n\t\t\tif (mn_mod[ind] > mn[ind].first.first) {\n\t\t\t\tsum[ind]\
    \ += (mn_mod[ind] - mn[ind].first.first) * mn[ind].second;\n\t\t\t\tchk(mx[ind].first.first,\
    \ mn[ind].first.first, mn_mod[ind]);\n\t\t\t\tchk(mx[ind].first.second, mn[ind].first.first,\
    \ mn_mod[ind]);\n\t\t\t\tmn[ind].first.first = mn_mod[ind];\n\t\t\t\tif (L !=\
    \ R) {\n\t\t\t\t\tfor (int i = 0; i < 2; i++) {\n\t\t\t\t\t\tint pos = 2 * ind\
    \ + i;\n\t\t\t\t\t\tmn_mod[pos] = std::max(mn_mod[pos], mn_mod[ind] - mod[pos]);\n\
    \t\t\t\t\t\tmx_mod[pos] = std::max(mx_mod[pos], mn_mod[pos]);\n\t\t\t\t\t}\n\t\
    \t\t\t}\n\t\t\t}\n\t\t\tmn_mod[ind] = -INF;\n\t\t}\n\t\tif (mx_mod[ind] != INF)\
    \ {\n\t\t\tif (mx_mod[ind] < mx[ind].first.first) {\n\t\t\t\tsum[ind] += (mx_mod[ind]\
    \ - mx[ind].first.first) * mx[ind].second;\n\t\t\t\tchk(mn[ind].first.first, mx[ind].first.first,\
    \ mx_mod[ind]);\n\t\t\t\tchk(mn[ind].first.second, mx[ind].first.first, mx_mod[ind]);\n\
    \t\t\t\tmx[ind].first.first = mx_mod[ind];\n\t\t\t\tif (L != R) {\n\t\t\t\t\t\
    for (int i = 0; i < 2; i++) {\n\t\t\t\t\t\tint pos = 2 * ind + i;\n\t\t\t\t\t\t\
    mx_mod[pos] = std::min(mx_mod[pos], mx_mod[ind] - mod[pos]);\n\t\t\t\t\t\tmn_mod[pos]\
    \ = std::min(mn_mod[pos], mx_mod[pos]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \tmx_mod[ind] = INF;\n\t\t}\n\t\tif (mod[ind] != 0) {\n\t\t\tsum[ind] += mod[ind]\
    \ * (R - L + 1);\n\t\t\tauto inc = [&](T &a, C b) {\n\t\t\t\tif (std::abs(a.first.first)\
    \ != INF) \n\t\t\t\t\ta.first.first += b;\n\t\t\t\tif (std::abs(a.first.second)\
    \ != INF)\n\t\t\t\t\ta.first.second += b;\n\t\t\t};\n\t\t\tinc(mx[ind], mod[ind]);\
    \ inc(mn[ind], mod[ind]);\n\t\t\tif (L != R) {\n\t\t\t\tfor (int i = 0; i < 2;\
    \ i++) {\n\t\t\t\t\tint pos = 2 * ind + i;\n\t\t\t\t\tmod[pos] += mod[ind];\n\t\
    \t\t\t}\n\t\t\t}\n\t\t\tmod[ind] = 0;\n\t\t}\n\t}\n\n\tC qsum(int lo, int hi,\
    \ int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind,\
    \ L, R);\n\t\tif (R < lo || hi < L)\n\t\t\treturn 0;\n\t\tif (lo <= L && R <=\
    \ hi)     \n\t\t\treturn sum[ind];\n\t\tint M = (L + R) / 2;\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n\t}\n\n\tC qmax(int\
    \ lo, int hi, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\
    \t\tpush(ind, L, R);\n\t\tif (R < lo || hi < L)\n\t\t\treturn -INF;\n\t\tif (lo\
    \ <= L && R <= hi)     \n\t\t\treturn mx[ind].first.first;\n\t\tint M = (L + R)\
    \ / 2;\n\t\treturn std::max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind\
    \ + 1, M + 1, R));\n\t}\n\n\tC qmin(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (R < lo ||\
    \ hi < L)\n\t\t\treturn INF;\n\t\tif (lo <= L && R <= hi)     \n\t\t\treturn mn[ind].first.first;\n\
    \t\tint M = (L + R) / 2;\n\t\treturn std::min(qmin(lo, hi, 2 * ind, L, M), qmin(lo,\
    \ hi, 2 * ind + 1, M + 1, R));\n\t}\n\t\n\tvoid upd(int t, int lo, int hi, C b,\
    \ int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind,\
    \ L, R);\n\t\tif (R < lo || hi < L) \n\t\t\treturn;\n\t\tif (t == 0) \n\t\t\t\
    if (b >= mx[ind].first.first)\n\t\t\t\treturn;\n\t\telse if (t == 1)\n\t\t\tif\
    \ (b <= mn[ind].first.first)\n\t\t\t\treturn;\n\t\tif (lo <= L && R <= hi) {\n\
    \t\t\tif (t == 0) {\n\t\t\t\tif (b  > mx[ind].first.second) {\n\t\t\t\t\tmx_mod[ind]\
    \ = b;\n\t\t\t\t\tpush(ind, L, R);\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t} else\
    \ if (t == 1) {\n\t\t\t\tif (b < mn[ind].first.second) {\n\t\t\t\t\tmn_mod[ind]\
    \ = b;\n\t\t\t\t\tpush(ind, L, R);\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t} else\
    \ if (t == 2) {\n\t\t\t\tmod[ind] = b;\n\t\t\t\tpush(ind, L, R);\n\t\t\t\treturn;\n\
    \t\t\t} else assert(false);\n\t\t}\n\t\tassert(L != R);\n\t\tint M = (L + R) /\
    \ 2;\n\t\tupd(t, lo, hi, b, 2 * ind, L, M); upd(t, lo, hi, b, 2 * ind + 1, M +\
    \ 1, R);\n\t\tpull(ind);\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\t\
    ios_base::sync_with_stdio(0);\n\tint n, q; cin >> n >> q;\n\tSegmentTreeBeats<long\
    \ long> S;\n\tS.init(n);\n\tstd::vector<long long> a(n);\n\tfor (int i = 0; i\
    \ < n; i++)\n\t   \n\t\tcin >> a[i], S.upd(2, i, i, a[i]);\n\twhile (q--) {\n\t\
    \tint t, l, r; cin >> t >> l >> r;\n\t\tr--;\n\t\tif (t <= 2) {\n\t\t\tlong long\
    \ b; cin >> b;\n\t\t\tS.upd(t, l, r, b);\n\t\t} else {\n\t\t\tcout << S.qsum(l,\
    \ r) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/segment-tree-beats.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/segment-tree-beats.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/segment-tree-beats.hpp
- /library/library/data-structures/1d-range-queries/segment-tree-beats.hpp.html
title: library/data-structures/1d-range-queries/segment-tree-beats.hpp
---
