---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graphs/biconnected-components.hpp
    title: library/graphs/biconnected-components.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/block-cut-tree.hpp
    title: library/graphs/block-cut-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/lca-jump.hpp
    title: LCA Jump
  - icon: ':heavy_check_mark:'
    path: library/graphs/low-link.hpp
    title: library/graphs/low-link.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1326
    links:
    - https://yukicoder.me/problems/no/1326
  bundledCode: "#define PROBLEM \"https://yukicoder.me/problems/no/1326\"\n\n#include\
    \ <bits/stdc++.h>\n\n\n\n\ntemplate <typename G>\nstruct LowLink {\n\tint N;\n\
    \tconst G& g;\n\tstd::vector<int> ord, low, articulation;\n\tstd::vector<std::pair<int,\
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
    \t\taux[i].push_back(j);\n\t\taux[j].push_back(i);\n\t};\n};\n\r\nstruct LCAJump\
    \ {\r\n\tint n;\r\n\tstd::vector<std::vector<int>> par;\r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\tstd::vector<int> depth;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\
    \n\t\tint d = 1;\r\n\t\twhile ((1 << d) < n) d++;\r\n\t\tpar.assign(d, std::vector<int>(n));\r\
    \n\t\tadj.resize(n);\r\n\t\tdepth.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int x, int\
    \ y) {\r\n\t\tadj[x].push_back(y);\r\n\t\tadj[y].push_back(x);\r\n\t}\r\n\r\n\t\
    void gen(int root = 0) {\r\n\t\tpar[0][root] = root;\r\n\t\tdfs(root);\r\n\t}\r\
    \n\r\n\tvoid dfs(int src = 0) {\r\n\t\tfor (int i = 1; i < (int)par.size(); i++)\
    \ {\r\n\t\t\tpar[i][src] = par[i - 1][par[i - 1][src]];\r\n\t\t}\r\n\t\tfor (int\
    \ nxt : adj[src]) {\r\n\t\t\tif (nxt == par[0][src]) continue;\r\n\t\t\tdepth[nxt]\
    \ = depth[par[0][nxt] = src] + 1;\r\n\t\t\tdfs(nxt);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    int jump(int x, int d) {\r\n\t\tfor (int i = 0; i < (int)par.size(); i++) {\r\n\
    \t\t\tif ((d >> i) & 1) {\r\n\t\t\t\tx = par[i][x];\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    return x;\r\n\t}\r\n\t\r\n\tint lca(int x, int y) {\r\n\t\tif (depth[x] < depth[y])\
    \ std::swap(x, y);\r\n\t\tx = jump(x, depth[x] - depth[y]);\r\n\t\tif (x == y)\
    \ return x;\r\n\t\tfor (int i = (int)par.size() - 1; i >= 0; i--) {\r\n\t\t\t\
    int nx = par[i][x];\r\n\t\t\tint ny = par[i][y];\r\n\t\t\tif (nx != ny) x = nx,\
    \ y = ny;\r\n\t\t}\r\n\t\treturn par[0][x];\r\n\t}\r\n};\n\nint main() {\n\tusing\
    \ namespace std;\n\tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>> g(n);\n\
    \twhile (m--) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t--u, --v;\n\t\tg[u].push_back(v);\n\
    \t\tg[v].push_back(u);\n\t}\n\tBlockCutTree bct(g);\n\tg = bct.aux;\n\tLCAJump\
    \ lca;\n\tint sz = (int)g.size();\n\tlca.init(sz);\n\tfor (int u = 0; u < sz;\
    \ ++u) {\n\t\tfor (int v : g[u]) {\n\t\t\tif (u < v) {\n\t\t\t\tlca.ae(u, v);\n\
    \t\t\t}\n\t\t}\n\t}\n\tlca.gen(0);\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\
    \tint u, v;\n\t\tcin >> u >> v;\n\t\t--u, --v;\n\t\tif (u == v) {\n\t\t\tcout\
    \ << 0 << '\\n';\n\t\t\tcontinue;\t\n\t\t}\n\t\tint ans = lca.depth[bct.id(u)];\n\
    \t\tans += lca.depth[bct.id(v)];\n\t\tans -= lca.depth[lca.lca(bct.id(u), bct.id(v))]\
    \ * 2;\n\t\tans -= bct.is_arti(u);\n\t\tans -= bct.is_arti(v);\n\t\tans /= 2;\n\
    \t\tcout << ans << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1326\"\n\n#include <bits/stdc++.h>\n\
    \n#include \"../../library/graphs/block-cut-tree.hpp\"\n#include \"../../library/graphs/lca-jump.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>>\
    \ g(n);\n\twhile (m--) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t--u, --v;\n\t\
    \tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\t}\n\tBlockCutTree bct(g);\n\t\
    g = bct.aux;\n\tLCAJump lca;\n\tint sz = (int)g.size();\n\tlca.init(sz);\n\tfor\
    \ (int u = 0; u < sz; ++u) {\n\t\tfor (int v : g[u]) {\n\t\t\tif (u < v) {\n\t\
    \t\t\tlca.ae(u, v);\n\t\t\t}\n\t\t}\n\t}\n\tlca.gen(0);\n\tint q;\n\tcin >> q;\n\
    \twhile (q--) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t--u, --v;\n\t\tif (u ==\
    \ v) {\n\t\t\tcout << 0 << '\\n';\n\t\t\tcontinue;\t\n\t\t}\n\t\tint ans = lca.depth[bct.id(u)];\n\
    \t\tans += lca.depth[bct.id(v)];\n\t\tans -= lca.depth[lca.lca(bct.id(u), bct.id(v))]\
    \ * 2;\n\t\tans -= bct.is_arti(u);\n\t\tans -= bct.is_arti(v);\n\t\tans /= 2;\n\
    \t\tcout << ans << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/graphs/block-cut-tree.hpp
  - library/graphs/biconnected-components.hpp
  - library/graphs/low-link.hpp
  - library/graphs/lca-jump.hpp
  isVerificationFile: true
  path: verify/yukicoder/yukicoder-1326.test.cpp
  requiredBy: []
  timestamp: '2022-07-23 18:26:25-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yukicoder/yukicoder-1326.test.cpp
layout: document
redirect_from:
- /verify/verify/yukicoder/yukicoder-1326.test.cpp
- /verify/verify/yukicoder/yukicoder-1326.test.cpp.html
title: verify/yukicoder/yukicoder-1326.test.cpp
---
