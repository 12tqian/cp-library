---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graphs/biconnected-components.hpp
    title: library/graphs/biconnected-components.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/block-cut-tree.hpp
    title: library/graphs/block-cut-tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-biconnected_components.test.cpp
    title: verify/yosupo/yosupo-biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yukicoder-yuki_1326.test.cpp
    title: verify/yukicoder/yukicoder-yuki_1326.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <typename G>\nstruct LowLink {\n\tint N;\n\tconst G& g;\n\
    \tstd::vector<int> ord, low, articulation;\n\tstd::vector<std::pair<int, int>>\
    \ bridge;\n\n\tLowLink(const G& _g) : g(_g) {\n\t\tN = (int)g.size();\n\t\tord.resize(N,\
    \ -1);\n\t\tlow.resize(N, -1);\n\t\tint k = 0;\n\t\tfor (int i = 0; i < N; i++)\n\
    \t\t\tif (ord[i] == -1) k = dfs(i, k, -1);\n\t}\n\n\tint dfs(int idx, int k, int\
    \ par) {\n\t\tlow[idx] = (ord[idx] = k++);\n\t\tint cnt = 0;\n\t\tbool is_arti\
    \ = false, flg = false;\n\t\tfor (auto &to : g[idx]) {\n\t\t\tif (ord[to] == -1)\
    \ {\n\t\t\t\tcnt++;\n\t\t\t\tk = dfs(to, k, idx);\n\t\t\t\tlow[idx] = std::min(low[idx],\
    \ low[to]);\n\t\t\t\tis_arti |= (par != -1) && (low[to] >= ord[idx]);\n\t\t\t\t\
    if (ord[idx] < low[to]) {\n\t\t\t\t\tbridge.emplace_back(std::minmax(idx, (int)to));\n\
    \t\t\t\t}\n\t\t\t} else if (to != par || std::exchange(flg, true)) {\n\t\t\t\t\
    low[idx] = std::min(low[idx], ord[to]);\n\t\t\t}\n\t\t}\n\t\tis_arti |= par ==\
    \ -1 && cnt > 1;\n\t\tif (is_arti) articulation.push_back(idx);\n\t\treturn k;\n\
    \t}\n};\n"
  code: "#pragma once\n\ntemplate <typename G>\nstruct LowLink {\n\tint N;\n\tconst\
    \ G& g;\n\tstd::vector<int> ord, low, articulation;\n\tstd::vector<std::pair<int,\
    \ int>> bridge;\n\n\tLowLink(const G& _g) : g(_g) {\n\t\tN = (int)g.size();\n\t\
    \tord.resize(N, -1);\n\t\tlow.resize(N, -1);\n\t\tint k = 0;\n\t\tfor (int i =\
    \ 0; i < N; i++)\n\t\t\tif (ord[i] == -1) k = dfs(i, k, -1);\n\t}\n\n\tint dfs(int\
    \ idx, int k, int par) {\n\t\tlow[idx] = (ord[idx] = k++);\n\t\tint cnt = 0;\n\
    \t\tbool is_arti = false, flg = false;\n\t\tfor (auto &to : g[idx]) {\n\t\t\t\
    if (ord[to] == -1) {\n\t\t\t\tcnt++;\n\t\t\t\tk = dfs(to, k, idx);\n\t\t\t\tlow[idx]\
    \ = std::min(low[idx], low[to]);\n\t\t\t\tis_arti |= (par != -1) && (low[to] >=\
    \ ord[idx]);\n\t\t\t\tif (ord[idx] < low[to]) {\n\t\t\t\t\tbridge.emplace_back(std::minmax(idx,\
    \ (int)to));\n\t\t\t\t}\n\t\t\t} else if (to != par || std::exchange(flg, true))\
    \ {\n\t\t\t\tlow[idx] = std::min(low[idx], ord[to]);\n\t\t\t}\n\t\t}\n\t\tis_arti\
    \ |= par == -1 && cnt > 1;\n\t\tif (is_arti) articulation.push_back(idx);\n\t\t\
    return k;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/low-link.hpp
  requiredBy:
  - library/graphs/block-cut-tree.hpp
  - library/graphs/biconnected-components.hpp
  timestamp: '2022-07-23 18:03:31-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/yukicoder-yuki_1326.test.cpp
  - verify/yosupo/yosupo-biconnected_components.test.cpp
documentation_of: library/graphs/low-link.hpp
layout: document
redirect_from:
- /library/library/graphs/low-link.hpp
- /library/library/graphs/low-link.hpp.html
title: library/graphs/low-link.hpp
---
