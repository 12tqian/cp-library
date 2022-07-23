---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graphs/biconnected-components.hpp
    title: library/graphs/biconnected-components.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/low-link.hpp
    title: library/graphs/low-link.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yukicoder-yuki_1326.test.cpp
    title: verify/yukicoder/yukicoder-yuki_1326.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\n\n\ntemplate <typename G>\nstruct LowLink {\n\tint N;\n\tconst G&\
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
    \t\t\t\tbreak;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n};\n\
    \ntemplate <typename G>\nstruct BlockCutTree {\n\tconst G& g;\n\tBiConnectedComponents<G>\
    \ bcc;\n\tstd::vector<std::vector<int>> aux;\n\tstd::vector<int> idar, idcc;\n\
    \n\tBlockCutTree(const G& _g) : g(_g), bcc(g) { build(); }\n\n\tvoid build() {\n\
    \t\tauto ar = bcc.articulation;\n\t\tidar.resize(g.size(), -1);\n\t\tidcc.resize(g.size(),\
    \ -1);\n\t\tfor (int i = 0; i < (int)ar.size(); i++) idar[ar[i]] = i;\n\n\t\t\
    aux.resize(ar.size() + bcc.bc.size());\n\t\tstd::vector<int> last(g.size(), -1);\n\
    \t\tfor (int i = 0; i < (int)bcc.bc.size(); i++) {\n\t\t\tstd::vector<int> st;\n\
    \t\t\tfor (auto& [u, v] : bcc.bc[i]) st.push_back(u), st.push_back(v);\n\t\t\t\
    for (auto& u : st) {\n\t\t\t\tif (idar[u] == -1)\n\t\t\t\t\tidcc[u] = i + (int)ar.size();\n\
    \t\t\t\telse if (last[u] != i) {\n\t\t\t\t\tadd(i + (int)ar.size(), idar[u]);\n\
    \t\t\t\t\tlast[u] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<int>&\
    \ operator[](int i) { return aux[i]; }\n\n\tint size() const { return (int)aux.size();\
    \ }\n\n\tint id(int i) { return idar[i] == -1 ? idcc[i] : idar[i]; }\n\n\tbool\
    \ is_arti(int i) { return idar[i] != -1; }\n\n\tint arti() const { return bcc.articulation.size();\
    \ }\n\nprivate:\n\tvoid add(int i, int j) {\n\t\tif (i == -1 or j == -1) return;\n\
    \t\taux[i].push_back(j);\n\t\taux[j].push_back(i);\n\t};\n};\n"
  code: "#pragma once\n\n#include \"biconnected-components.hpp\"\n\ntemplate <typename\
    \ G>\nstruct BlockCutTree {\n\tconst G& g;\n\tBiConnectedComponents<G> bcc;\n\t\
    std::vector<std::vector<int>> aux;\n\tstd::vector<int> idar, idcc;\n\n\tBlockCutTree(const\
    \ G& _g) : g(_g), bcc(g) { build(); }\n\n\tvoid build() {\n\t\tauto ar = bcc.articulation;\n\
    \t\tidar.resize(g.size(), -1);\n\t\tidcc.resize(g.size(), -1);\n\t\tfor (int i\
    \ = 0; i < (int)ar.size(); i++) idar[ar[i]] = i;\n\n\t\taux.resize(ar.size() +\
    \ bcc.bc.size());\n\t\tstd::vector<int> last(g.size(), -1);\n\t\tfor (int i =\
    \ 0; i < (int)bcc.bc.size(); i++) {\n\t\t\tstd::vector<int> st;\n\t\t\tfor (auto&\
    \ [u, v] : bcc.bc[i]) st.push_back(u), st.push_back(v);\n\t\t\tfor (auto& u :\
    \ st) {\n\t\t\t\tif (idar[u] == -1)\n\t\t\t\t\tidcc[u] = i + (int)ar.size();\n\
    \t\t\t\telse if (last[u] != i) {\n\t\t\t\t\tadd(i + (int)ar.size(), idar[u]);\n\
    \t\t\t\t\tlast[u] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<int>&\
    \ operator[](int i) { return aux[i]; }\n\n\tint size() const { return (int)aux.size();\
    \ }\n\n\tint id(int i) { return idar[i] == -1 ? idcc[i] : idar[i]; }\n\n\tbool\
    \ is_arti(int i) { return idar[i] != -1; }\n\n\tint arti() const { return bcc.articulation.size();\
    \ }\n\nprivate:\n\tvoid add(int i, int j) {\n\t\tif (i == -1 or j == -1) return;\n\
    \t\taux[i].push_back(j);\n\t\taux[j].push_back(i);\n\t};\n};"
  dependsOn:
  - library/graphs/biconnected-components.hpp
  - library/graphs/low-link.hpp
  isVerificationFile: false
  path: library/graphs/block-cut-tree.hpp
  requiredBy: []
  timestamp: '2022-07-23 18:16:07-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/yukicoder-yuki_1326.test.cpp
documentation_of: library/graphs/block-cut-tree.hpp
layout: document
redirect_from:
- /library/library/graphs/block-cut-tree.hpp
- /library/library/graphs/block-cut-tree.hpp.html
title: library/graphs/block-cut-tree.hpp
---
