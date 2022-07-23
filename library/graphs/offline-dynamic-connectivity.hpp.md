---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graphs/dsu-rollback.hpp
    title: library/graphs/dsu-rollback.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/spoj/spoj-DYNACON2.test.cpp
    title: verify/spoj/spoj-DYNACON2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n\r\nstruct DSURollBack {\r\n\tstd::vector<int> e;\r\n\t\r\n\t\
    void init(int n) {\r\n\t\te = std::vector<int>(n, -1);\r\n\t}\r\n\r\n\tint get(int\
    \ x) {\r\n\t\treturn e[x] < 0 ? x : get(e[x]);\r\n\t}\r\n\r\n\tbool same_set(int\
    \ a, int b) {\r\n\t\treturn get(a) == get(b);\r\n\t}\r\n\r\n\tint size(int x)\
    \ {\r\n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tstd::vector<std::array<int, 4>>\
    \ mod;\r\n\t\r\n\tbool unite(int x, int y) {\r\n\t\tx = get(x), y = get(y);\r\n\
    \t\tif (x == y) {\r\n\t\t\tmod.push_back({-1, -1, -1, -1});\r\n\t\t\treturn 0;\r\
    \n\t\t}\r\n\t\tif (e[x] > e[y]) std::swap(x, y);\r\n\t\tmod.push_back({x, y, e[x],\
    \ e[y]});\r\n\t\te[x] += e[y], e[y] = x;\r\n\t\treturn true;\r\n\t}\r\n\r\n\t\
    void rollback() {\r\n\t\tauto a = mod.back();\r\n\t\tmod.pop_back();\r\n\t\tif\
    \ (a[0] != -1) {\r\n\t\t\te[a[0]] = a[2];\r\n\t\t\te[a[1]] = a[3];\r\n\t\t}\r\n\
    \t}\r\n};\r\n\r\nstruct OfflineDynamicConnectivity {\r\n\tDSURollBack dsu;\r\n\
    \tint sz;\r\n\tstd::vector<std::vector<std::pair<int, int>>> seg;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> queries;\r\n\tstd::vector<int> ans;\r\n\r\n\tvoid upd(int l, int r, std::pair<int,\
    \ int> p) {\r\n\t\t// add edge p from time [l, r]\r\n\t\tfor (l += sz, r += sz\
    \ + 1; l < r; l /= 2, r /= 2) {\r\n\t\t\tif (l & 1) seg[l++].push_back(p);\r\n\
    \t\t\tif (r & 1) seg[--r].push_back(p);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid process(int\
    \ ind) {\r\n\t\tfor (auto& t : seg[ind]) {\r\n\t\t\tdsu.unite(t.first, t.second);\r\
    \n\t\t}\r\n\t\tif (ind >= sz) {\r\n\t\t\t// Process the queries at time ti\r\n\
    \t\t\t// Do stuff with D\r\n\t\t\tint ti = ind - sz; \r\n\t\t\tfor (auto& qq :\
    \ queries[ti]) {\r\n\t\t\t\tans.push_back(dsu.same_set(qq.first, qq.second));\r\
    \n\t\t\t}\r\n\t\t} else {\r\n\t\t\tprocess(2 * ind); process(2 * ind + 1);\r\n\
    \t\t}\r\n\t\tfor (auto& t : seg[ind]) {\r\n\t\t\tdsu.rollback();\r\n\t\t}\r\n\t\
    }\r\n\r\n\tvoid init(int n, int max_time) {\r\n\t\tsz = 1;\r\n\t\twhile (sz <\
    \ max_time) sz *= 2;\r\n\t\tseg.assign(2 * sz, {});\r\n\t\tqueries.assign(sz,\
    \ {});\r\n\t\tdsu.init(n);\r\n\t}\r\n\r\n\tvoid add_query(int ti, int u, int v)\
    \ {\r\n\t\tqueries[ti].emplace_back(u, v);\r\n\t}\r\n\t\r\n\tstd::vector<int>\
    \ solve() {\r\n\t\tprocess(1);\r\n\t\treturn ans;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\n#include \"dsu-rollback.hpp\"\r\n\r\nstruct OfflineDynamicConnectivity\
    \ {\r\n\tDSURollBack dsu;\r\n\tint sz;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> seg;\r\n\tstd::vector<std::vector<std::pair<int, int>>> queries;\r\n\t\
    std::vector<int> ans;\r\n\r\n\tvoid upd(int l, int r, std::pair<int, int> p) {\r\
    \n\t\t// add edge p from time [l, r]\r\n\t\tfor (l += sz, r += sz + 1; l < r;\
    \ l /= 2, r /= 2) {\r\n\t\t\tif (l & 1) seg[l++].push_back(p);\r\n\t\t\tif (r\
    \ & 1) seg[--r].push_back(p);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid process(int ind) {\r\
    \n\t\tfor (auto& t : seg[ind]) {\r\n\t\t\tdsu.unite(t.first, t.second);\r\n\t\t\
    }\r\n\t\tif (ind >= sz) {\r\n\t\t\t// Process the queries at time ti\r\n\t\t\t\
    // Do stuff with D\r\n\t\t\tint ti = ind - sz; \r\n\t\t\tfor (auto& qq : queries[ti])\
    \ {\r\n\t\t\t\tans.push_back(dsu.same_set(qq.first, qq.second));\r\n\t\t\t}\r\n\
    \t\t} else {\r\n\t\t\tprocess(2 * ind); process(2 * ind + 1);\r\n\t\t}\r\n\t\t\
    for (auto& t : seg[ind]) {\r\n\t\t\tdsu.rollback();\r\n\t\t}\r\n\t}\r\n\r\n\t\
    void init(int n, int max_time) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < max_time) sz\
    \ *= 2;\r\n\t\tseg.assign(2 * sz, {});\r\n\t\tqueries.assign(sz, {});\r\n\t\t\
    dsu.init(n);\r\n\t}\r\n\r\n\tvoid add_query(int ti, int u, int v) {\r\n\t\tqueries[ti].emplace_back(u,\
    \ v);\r\n\t}\r\n\t\r\n\tstd::vector<int> solve() {\r\n\t\tprocess(1);\r\n\t\t\
    return ans;\r\n\t}\r\n};"
  dependsOn:
  - library/graphs/dsu-rollback.hpp
  isVerificationFile: false
  path: library/graphs/offline-dynamic-connectivity.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/spoj/spoj-DYNACON2.test.cpp
documentation_of: library/graphs/offline-dynamic-connectivity.hpp
layout: document
redirect_from:
- /library/library/graphs/offline-dynamic-connectivity.hpp
- /library/library/graphs/offline-dynamic-connectivity.hpp.html
title: library/graphs/offline-dynamic-connectivity.hpp
---
