---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
    title: library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n// Set to minimums, negate for maximums\n\ntemplate <class T> struct LiChaoTree\
    \ {\n\tstruct Line {\n\t\tT slope, intercept;\n\t\tLine(T slope, T intercept)\
    \ : slope(slope), intercept(intercept) {}\n\t\tinline T get(T x) const { return\
    \ slope * x + intercept; }\n\t\tinline bool over(const Line &other, const T &x)\
    \ {\n\t\t\treturn get(x) < other.get(x);\n\t\t}\n\t};\n\n\tstd::vector<T> xset;\n\
    \tstd::vector<Line> seg;\n\tint sz;\n\n\tLiChaoTree(const std::vector<T> &x) :\
    \ xset(x) {\n\t\tsort(xset.begin(), xset.end());\n\t\txset.erase(unique(xset.begin(),\
    \ xset.end()), xset.end());\n\t\tsz = 1;\n\t\twhile (sz < (int) xset.size()) sz\
    \ <<= 1;\n\t\twhile ((int) xset.size() < sz) xset.push_back(xset.back());\n\t\t\
    seg.assign(2 * sz, Line(0, std::numeric_limits<T>::max()));\n\t}\n\n\tint get_more_idx(T\
    \ k) {\n\t\treturn lower_bound(xset.begin(), xset.end(), k) - xset.begin();\n\t\
    }\n\n\tint get_less_idx(T k) {\n\t\tint ret = upper_bound(xset.begin(), xset.end(),\
    \ k) - xset.begin();\n\t\treturn std::max(0, ret - 1);\n\t}\n\n\tvoid inner_update(T\
    \ a, T b, int ind, int L, int R) {\n\t\tLine line(a, b);\n\t\twhile (true) {\n\
    \t\t\tint M = (L + R) >> 1;\n\t\t\tbool l_over = line.over(seg[ind], xset[L]);\n\
    \t\t\tbool r_over = line.over(seg[ind], xset[R - 1]);\n\t\t\tif (l_over == r_over)\
    \ {\n\t\t\t\tif (l_over) std::swap(seg[ind], line);\n\t\t\t\treturn;\n\t\t\t}\n\
    \t\t\tbool m_over = line.over(seg[ind], xset[M]);\n\t\t\tif (m_over) std::swap(seg[ind],\
    \ line);\n\t\t\tif (l_over != m_over) \n\t\t\t\tind = (ind << 1), R = M;\n\t\t\
    \telse \n\t\t\t\tind = (ind << 1) | 1, L = M;\n\n\t\t}\n\t}\n\n\tvoid inner_update(T\
    \ a, T b, int ind) {\n\t\tint L, R;\n\t\tint up = 31 - __builtin_clz(ind);\n\t\
    \tL = (sz >> up) * (ind - (1 << up));\n\t\tR = L + (sz >> up);\n\t\tinner_update(a,\
    \ b, ind, L, R);\n\t}\n\n\tvoid update(T a, T b) { inner_update(a, b, 1, 0, sz);\
    \ }\n\n\tvoid update_segment(T a, T b, T lo, T hi) {\n\t\tint L = get_more_idx(lo)\
    \ + sz;\n\t\tint R = get_less_idx(hi) + sz + 1;\n\t\tfor (; L < R; L >>= 1, R\
    \ >>= 1) {\n\t\t\tif (L & 1) inner_update(a, b, L++);\n\t\t\tif (R & 1) inner_update(a,\
    \ b, --R);\n\t\t}\n\t}\n\n\tT inner_query(T x, int ind) {\n\t\tT ret = seg[ind].get(x);\n\
    \t\twhile (ind > 1) {\n\t\t\tind = ind >> 1;\n\t\t\tret = std::min(ret, seg[ind].get(x));\n\
    \t\t}\n\t\treturn ret;\n\t}\n\n\tT query_idx(int k) {\n\t\tconst T x = xset[k];\n\
    \t\tk += sz;\n\t\treturn inner_query(x, k);\n\t}\n\t\n\tT query(T x) { return\
    \ query_idx(get_more_idx(x)); }\n};\n\nint main() {\n\tusing namespace std;\n\t\
    cin.tie(0)->sync_with_stdio(0);\n\tint n, q; cin >> n >> q;\n\tvector<long long>\
    \ a(n), b(n), l(n), r(n);\t\n\tfor (int i = 0; i < n; i++) \n\t\tcin >> l[i] >>\
    \ r[i] >> a[i] >> b[i];\n\tvector<long long> c(q), d(q), e(q), f(q), g(q);\n\t\
    vector<long long> xs;\n\tfor (int i = 0; i < q; i++) {\n\t\tcin >> c[i];\n\t\t\
    if (c[i]) {\n\t\t\tcin >> d[i];\n\t\t\txs.push_back(d[i]);\n\t\t} else {\n\t\t\
    \tcin >> d[i] >> e[i] >> f[i] >> g[i];\n\t\t}\n\t}\n\txs.push_back(numeric_limits<long\
    \ long>::min());\n\txs.push_back(numeric_limits<long long>::max());\n\tLiChaoTree<long\
    \ long> L(xs);\n\tfor (int i = 0; i < n; i++) {\n\t\tL.update_segment(a[i], b[i],\
    \ l[i], r[i] - 1);\n\t}\n\tfor (int i = 0; i < q; i++) {\n\t\tif (c[i]) {\n\t\t\
    \tlong long ans = L.query(d[i]);\n\t\t\tif (ans == numeric_limits<long long>::max())\
    \ \n\t\t\t\tcout << \"INFINITY\\n\";\n\t\t\telse \n\t\t\t\tcout << ans << '\\\
    n';\n\t\t} else {\n\t\t\tL.update_segment(f[i], g[i], d[i], e[i] - 1);\n\t\t}\n\
    \t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/li-chao-tree-offline.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, q; cin >> n >> q;\n\tvector<long long> a(n), b(n), l(n), r(n);\t\n\tfor\
    \ (int i = 0; i < n; i++) \n\t\tcin >> l[i] >> r[i] >> a[i] >> b[i];\n\tvector<long\
    \ long> c(q), d(q), e(q), f(q), g(q);\n\tvector<long long> xs;\n\tfor (int i =\
    \ 0; i < q; i++) {\n\t\tcin >> c[i];\n\t\tif (c[i]) {\n\t\t\tcin >> d[i];\n\t\t\
    \txs.push_back(d[i]);\n\t\t} else {\n\t\t\tcin >> d[i] >> e[i] >> f[i] >> g[i];\n\
    \t\t}\n\t}\n\txs.push_back(numeric_limits<long long>::min());\n\txs.push_back(numeric_limits<long\
    \ long>::max());\n\tLiChaoTree<long long> L(xs);\n\tfor (int i = 0; i < n; i++)\
    \ {\n\t\tL.update_segment(a[i], b[i], l[i], r[i] - 1);\n\t}\n\tfor (int i = 0;\
    \ i < q; i++) {\n\t\tif (c[i]) {\n\t\t\tlong long ans = L.query(d[i]);\n\t\t\t\
    if (ans == numeric_limits<long long>::max()) \n\t\t\t\tcout << \"INFINITY\\n\"\
    ;\n\t\t\telse \n\t\t\t\tcout << ans << '\\n';\n\t\t} else {\n\t\t\tL.update_segment(f[i],\
    \ g[i], d[i], e[i] - 1);\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
- /verify/verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp.html
title: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
---
