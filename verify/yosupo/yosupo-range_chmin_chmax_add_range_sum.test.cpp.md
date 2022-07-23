---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/segment-tree-beats.hpp
    title: Segment Tree Beats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class C> struct\
    \ SegmentTreeBeats {\r\n\tusing T = std::pair<std::pair<C, C>, int>;\r\n\tconst\
    \ C INF = std::numeric_limits<C>::max();\r\n\tstd::vector<C> mx_mod, mn_mod, mod,\
    \ sum;\r\n\tstd::vector<T> mx, mn;\r\n\tint sz; \r\n\r\n\tvoid init(int sz_) {\r\
    \n\t\tsz = 1; \r\n\t\twhile (sz < sz_) sz *= 2;\r\n\t\tmx_mod.assign(2 * sz, 0);\r\
    \n\t\tmn_mod.assign(2 * sz, 0);\r\n\t\tmod.assign(2 * sz, 0);\r\n\t\tsum.assign(2\
    \ * sz, 0);\r\n\t\tmx.assign(2 * sz, {{0, 0}, 0});\r\n\t\tmn.assign(2 * sz, {{0,\
    \ 0}, 0});\r\n\t\tbuild();\r\n\t}\r\n\r\n\tvoid build(int ind = 1, int L = 0,\
    \ int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tmx_mod[ind] = INF, mn_mod[ind]\
    \ = -INF, mod[ind] = 0;\r\n\t\tif (L == R) {\r\n\t\t\tmx[ind] = {{0, -INF}, 1};\r\
    \n\t\t\tmn[ind] = {{0, INF}, 1};\r\n\t\t\tsum[ind] = 0;\r\n\t\t\treturn;\r\n\t\
    \t}\r\n\t\tint M = (L + R) / 2;\r\n\t\tbuild(2 * ind, L, M); build(2 * ind + 1,\
    \ M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n\r\n\tT comb_mn(T a, T b) {\r\n\t\tif\
    \ (a > b) \r\n\t\t\tstd::swap(a, b);\r\n\t\tif (a.first.first == b.first.first)\
    \ \r\n\t\t\treturn  {{a.first.first, \r\n\t\t\t\tstd::min(a.first.second, b.first.second)},\
    \ \r\n\t\t\t\ta.second + b.second};\r\n\t\treturn {{a.first.first, std::min(a.first.second,\
    \ b.first.first)}, a.second};\r\n\t}\r\n\r\n\tT comb_mx(T a, T b) {\r\n\t\tif\
    \ (a < b) std::swap(a, b);\r\n\t\tif (a.first.first == b.first.first) \r\n\t\t\
    \treturn  {{a.first.first, \r\n\t\t\t\tstd::max(a.first.second, b.first.second)},\
    \ \r\n\t\t\t\ta.second + b.second};\r\n\t\treturn {{a.first.first, std::max(a.first.second,\
    \ b.first.first)}, \r\n\t\t\ta.second};\r\n\t}\r\n\r\n\tvoid pull(int ind) {\r\
    \n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\n\t\tmn[ind] = comb_mn(mn[2\
    \ * ind], mn[2 * ind + 1]);\r\n\t\tmx[ind] = comb_mx(mx[2 * ind], mx[2 * ind +\
    \ 1]);\r\n\t}\r\n\r\n\tvoid push(int ind, int L, int R) {\r\n\t\tauto chk = [](C&\
    \ a, C b, C c) {\r\n\t\t\tif (a == b)\r\n\t\t\t\ta = c;\r\n\t\t};\r\n\t\tif (mn_mod[ind]\
    \ != -INF) {\r\n\t\t\tif (mn_mod[ind] > mn[ind].first.first) {\r\n\t\t\t\tsum[ind]\
    \ += (mn_mod[ind] - mn[ind].first.first) * mn[ind].second;\r\n\t\t\t\tchk(mx[ind].first.first,\
    \ mn[ind].first.first, mn_mod[ind]);\r\n\t\t\t\tchk(mx[ind].first.second, mn[ind].first.first,\
    \ mn_mod[ind]);\r\n\t\t\t\tmn[ind].first.first = mn_mod[ind];\r\n\t\t\t\tif (L\
    \ != R) {\r\n\t\t\t\t\tfor (int i = 0; i < 2; i++) {\r\n\t\t\t\t\t\tint pos =\
    \ 2 * ind + i;\r\n\t\t\t\t\t\tmn_mod[pos] = std::max(mn_mod[pos], mn_mod[ind]\
    \ - mod[pos]);\r\n\t\t\t\t\t\tmx_mod[pos] = std::max(mx_mod[pos], mn_mod[pos]);\r\
    \n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tmn_mod[ind] = -INF;\r\n\t\t}\r\n\
    \t\tif (mx_mod[ind] != INF) {\r\n\t\t\tif (mx_mod[ind] < mx[ind].first.first)\
    \ {\r\n\t\t\t\tsum[ind] += (mx_mod[ind] - mx[ind].first.first) * mx[ind].second;\r\
    \n\t\t\t\tchk(mn[ind].first.first, mx[ind].first.first, mx_mod[ind]);\r\n\t\t\t\
    \tchk(mn[ind].first.second, mx[ind].first.first, mx_mod[ind]);\r\n\t\t\t\tmx[ind].first.first\
    \ = mx_mod[ind];\r\n\t\t\t\tif (L != R) {\r\n\t\t\t\t\tfor (int i = 0; i < 2;\
    \ i++) {\r\n\t\t\t\t\t\tint pos = 2 * ind + i;\r\n\t\t\t\t\t\tmx_mod[pos] = std::min(mx_mod[pos],\
    \ mx_mod[ind] - mod[pos]);\r\n\t\t\t\t\t\tmn_mod[pos] = std::min(mn_mod[pos],\
    \ mx_mod[pos]);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tmx_mod[ind] =\
    \ INF;\r\n\t\t}\r\n\t\tif (mod[ind] != 0) {\r\n\t\t\tsum[ind] += mod[ind] * (R\
    \ - L + 1);\r\n\t\t\tauto inc = [&](T& a, C b) {\r\n\t\t\t\tif (std::abs(a.first.first)\
    \ != INF) \r\n\t\t\t\t\ta.first.first += b;\r\n\t\t\t\tif (std::abs(a.first.second)\
    \ != INF)\r\n\t\t\t\t\ta.first.second += b;\r\n\t\t\t};\r\n\t\t\tinc(mx[ind],\
    \ mod[ind]); inc(mn[ind], mod[ind]);\r\n\t\t\tif (L != R) {\r\n\t\t\t\tfor (int\
    \ i = 0; i < 2; i++) {\r\n\t\t\t\t\tint pos = 2 * ind + i;\r\n\t\t\t\t\tmod[pos]\
    \ += mod[ind];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tmod[ind] = 0;\r\n\t\t}\r\n\t}\r\
    \n\r\n\tC qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif\
    \ (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (R < lo || hi < L)\r\n\t\
    \t\treturn 0;\r\n\t\tif (lo <= L && R <= hi)     \r\n\t\t\treturn sum[ind];\r\n\
    \t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo,\
    \ hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n\r\n\tC qmax(int lo, int hi, int ind =\
    \ 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L,\
    \ R);\r\n\t\tif (R < lo || hi < L)\r\n\t\t\treturn -INF;\r\n\t\tif (lo <= L &&\
    \ R <= hi)     \r\n\t\t\treturn mx[ind].first.first;\r\n\t\tint M = (L + R) /\
    \ 2;\r\n\t\treturn std::max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind\
    \ + 1, M + 1, R));\r\n\t}\r\n\r\n\tC qmin(int lo, int hi, int ind = 1, int L =\
    \ 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\t\
    if (R < lo || hi < L)\r\n\t\t\treturn INF;\r\n\t\tif (lo <= L && R <= hi)    \
    \ \r\n\t\t\treturn mn[ind].first.first;\r\n\t\tint M = (L + R) / 2;\r\n\t\treturn\
    \ std::min(qmin(lo, hi, 2 * ind, L, M), qmin(lo, hi, 2 * ind + 1, M + 1, R));\r\
    \n\t}\r\n\t\r\n\tvoid upd(int t, int lo, int hi, C b, int ind = 1, int L = 0,\
    \ int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif\
    \ (R < lo || hi < L) \r\n\t\t\treturn;\r\n\t\tif (t == 0) \r\n\t\t\tif (b >= mx[ind].first.first)\r\
    \n\t\t\t\treturn;\r\n\t\telse if (t == 1)\r\n\t\t\tif (b <= mn[ind].first.first)\r\
    \n\t\t\t\treturn;\r\n\t\tif (lo <= L && R <= hi) {\r\n\t\t\tif (t == 0) {\r\n\t\
    \t\t\tif (b  > mx[ind].first.second) {\r\n\t\t\t\t\tmx_mod[ind] = b;\r\n\t\t\t\
    \t\tpush(ind, L, R);\r\n\t\t\t\t\treturn;\r\n\t\t\t\t}\r\n\t\t\t} else if (t ==\
    \ 1) {\r\n\t\t\t\tif (b < mn[ind].first.second) {\r\n\t\t\t\t\tmn_mod[ind] = b;\r\
    \n\t\t\t\t\tpush(ind, L, R);\r\n\t\t\t\t\treturn;\r\n\t\t\t\t}\r\n\t\t\t} else\
    \ if (t == 2) {\r\n\t\t\t\tmod[ind] = b;\r\n\t\t\t\tpush(ind, L, R);\r\n\t\t\t\
    \treturn;\r\n\t\t\t} else assert(false);\r\n\t\t}\r\n\t\tassert(L != R);\r\n\t\
    \tint M = (L + R) / 2;\r\n\t\tupd(t, lo, hi, b, 2 * ind, L, M); upd(t, lo, hi,\
    \ b, 2 * ind + 1, M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n};\n\r\nint main() {\r\
    \n\tusing namespace std;\r\n\tios_base::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, q; cin >> n >> q;\r\n\tSegmentTreeBeats<long long> S;\r\n\tS.init(n);\r\
    \n\tstd::vector<long long> a(n);\r\n\tfor (int i = 0; i < n; i++)\r\n\t\tcin >>\
    \ a[i], S.upd(2, i, i, a[i]);\r\n\twhile (q--) {\r\n\t\tint t, l, r; cin >> t\
    \ >> l >> r;\r\n\t\tr--;\r\n\t\tif (t <= 2) {\r\n\t\t\tlong long b; cin >> b;\r\
    \n\t\t\tS.upd(t, l, r, b);\r\n\t\t} else {\r\n\t\t\tcout << S.qsum(l, r) << '\\\
    n';\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/data-structures/1d-range-queries/segment-tree-beats.hpp\"\r\n\r\n\
    int main() {\r\n\tusing namespace std;\r\n\tios_base::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n, q; cin >> n >> q;\r\n\tSegmentTreeBeats<long\
    \ long> S;\r\n\tS.init(n);\r\n\tstd::vector<long long> a(n);\r\n\tfor (int i =\
    \ 0; i < n; i++)\r\n\t\tcin >> a[i], S.upd(2, i, i, a[i]);\r\n\twhile (q--) {\r\
    \n\t\tint t, l, r; cin >> t >> l >> r;\r\n\t\tr--;\r\n\t\tif (t <= 2) {\r\n\t\t\
    \tlong long b; cin >> b;\r\n\t\t\tS.upd(t, l, r, b);\r\n\t\t} else {\r\n\t\t\t\
    cout << S.qsum(l, r) << '\\n';\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/segment-tree-beats.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/yosupo/yosupo-range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/yosupo/yosupo-range_chmin_chmax_add_range_sum.test.cpp
---
