---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graphs/low-link.hpp
    title: library/graphs/low-link.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/graphs/block-cut-tree.hpp
    title: library/graphs/block-cut-tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-biconnected_components.test.cpp
    title: verify/yosupo/yosupo-biconnected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\n\ntemplate <typename G>\nstruct LowLink {\n\tint N;\n\tconst G&\
    \ g;\n\tstd::vector<int> ord, low, articulation;\n\tstd::vector<std::pair<int,\
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
    return k;\n\t}\n};\n\ntemplate <typename G>\nstruct BiConnectedComponents : LowLink<G>\
    \ {\n\tusing LL = LowLink<G>;\n\n\tstd::vector<int> used;\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> bc; // will not include BCC's of size 1!\n\tstd::vector<std::pair<int,\
    \ int>> tmp;\n\n\tBiConnectedComponents(const G& _g) : LL(_g) { build(); }\n\n\
    \tvoid build() {\n\t\tused.assign(this->g.size(), 0);\n\t\tfor (int i = 0; i <\
    \ (int)used.size(); i++) {\n\t\t\tif (!used[i]) dfs(i, -1);\n\t\t}\n\t}\n\n\t\
    void dfs(int idx, int par) {\n\t\tused[idx] = true;\n\t\tfor (auto& to : this->g[idx])\
    \ {\n\t\t\tif (to == par) continue;\n\t\t\tif (!used[to] || this->ord[to] < this->ord[idx])\
    \ {\n\t\t\t\ttmp.emplace_back(std::minmax(idx, to));\n\t\t\t}\n\t\t\tif (!used[to])\
    \ {\n\t\t\t\tdfs(to, idx);\n\t\t\t\tif (this->low[to] >= this->ord[idx]) {\n\t\
    \t\t\t\tbc.emplace_back();\n\t\t\t\t\twhile (true) {\n\t\t\t\t\t\tauto e = tmp.back();\n\
    \t\t\t\t\t\tbc.back().emplace_back(e);\n\t\t\t\t\t\ttmp.pop_back();\n\t\t\t\t\t\
    \tif (e.first == std::min(idx, to) && e.second == std::max(idx, to)) {\n\t\t\t\
    \t\t\t\tbreak;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "#pragma once \n\n#include \"low-link.hpp\"\n\ntemplate <typename G>\nstruct\
    \ BiConnectedComponents : LowLink<G> {\n\tusing LL = LowLink<G>;\n\n\tstd::vector<int>\
    \ used;\n\tstd::vector<std::vector<std::pair<int, int>>> bc; // will not include\
    \ BCC's of size 1!\n\tstd::vector<std::pair<int, int>> tmp;\n\n\tBiConnectedComponents(const\
    \ G& _g) : LL(_g) { build(); }\n\n\tvoid build() {\n\t\tused.assign(this->g.size(),\
    \ 0);\n\t\tfor (int i = 0; i < (int)used.size(); i++) {\n\t\t\tif (!used[i]) dfs(i,\
    \ -1);\n\t\t}\n\t}\n\n\tvoid dfs(int idx, int par) {\n\t\tused[idx] = true;\n\t\
    \tfor (auto& to : this->g[idx]) {\n\t\t\tif (to == par) continue;\n\t\t\tif (!used[to]\
    \ || this->ord[to] < this->ord[idx]) {\n\t\t\t\ttmp.emplace_back(std::minmax(idx,\
    \ to));\n\t\t\t}\n\t\t\tif (!used[to]) {\n\t\t\t\tdfs(to, idx);\n\t\t\t\tif (this->low[to]\
    \ >= this->ord[idx]) {\n\t\t\t\t\tbc.emplace_back();\n\t\t\t\t\twhile (true) {\n\
    \t\t\t\t\t\tauto e = tmp.back();\n\t\t\t\t\t\tbc.back().emplace_back(e);\n\t\t\
    \t\t\t\ttmp.pop_back();\n\t\t\t\t\t\tif (e.first == std::min(idx, to) && e.second\
    \ == std::max(idx, to)) {\n\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t}\n};"
  dependsOn:
  - library/graphs/low-link.hpp
  isVerificationFile: false
  path: library/graphs/biconnected-components.hpp
  requiredBy:
  - library/graphs/block-cut-tree.hpp
  timestamp: '2022-07-23 18:03:31-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-biconnected_components.test.cpp
documentation_of: library/graphs/biconnected-components.hpp
layout: document
redirect_from:
- /library/library/graphs/biconnected-components.hpp
- /library/library/graphs/biconnected-components.hpp.html
title: library/graphs/biconnected-components.hpp
---
