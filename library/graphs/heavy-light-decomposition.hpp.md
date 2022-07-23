---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
    title: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class G> \r\nstruct HeavyLightDecomposition {\r\nprivate:\r\
    \n\tvoid dfs_sz(int cur) {\r\n\t\tsize[cur] = 1;\r\n\t\tfor (auto& dst : g[cur])\
    \ {\r\n\t\t\tif (dst == par[cur]) {\r\n\t\t\t\tif (g[cur].size() >= 2 && int(dst)\
    \ == int(g[cur][0]))\r\n\t\t\t\t\tstd::swap(g[cur][0], g[cur][1]);\r\n\t\t\t\t\
    else\r\n\t\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdepth[dst] = depth[cur] + 1;\r\
    \n\t\t\tpar[dst] = cur;\r\n\t\t\tdfs_sz(dst);\r\n\t\t\tsize[cur] += size[dst];\r\
    \n\t\t\tif (size[dst] > size[g[cur][0]]) {\r\n\t\t\t\tstd::swap(dst, g[cur][0]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dfs_hld(int cur) {\r\n\t\tdown[cur] =\
    \ id++;\r\n\t\tfor (auto dst : g[cur]) {\r\n\t\t\tif (dst == par[cur]) continue;\r\
    \n\t\t\tnxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\r\n\t\t\
    \tdfs_hld(dst);\r\n\t\t}\r\n\t\tup[cur] = id;\r\n\t}\r\n\r\n\t// [u, v)\r\n\t\
    std::vector<std::pair<int, int>> ascend(int u, int v) const {\r\n\t\tstd::vector<std::pair<int,\
    \ int>> res;\r\n\t\twhile (nxt[u] != nxt[v]) {\r\n\t\t\tres.emplace_back(down[u],\
    \ down[nxt[u]]);\r\n\t\t\tu = par[nxt[u]];\r\n\t\t}\r\n\t\tif (u != v) res.emplace_back(down[u],\
    \ down[v] + 1);\r\n\t\treturn res;\r\n\t}\r\n\r\n\t// (u, v]\r\n\tstd::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\r\n\t\tif (u == v) return {};\r\n\t\tif\
    \ (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};\r\n\t\tauto res = descend(u,\
    \ par[nxt[v]]);\r\n\t\tres.emplace_back(down[nxt[v]], down[v]);\r\n\t\treturn\
    \ res;\r\n\t}\r\n\r\npublic:\r\n\tG g;\r\n\tint id;\r\n\tstd::vector<int> size,\
    \ depth, down, up, nxt, par;\r\n\r\n\tHeavyLightDecomposition(G& _g, std::vector<int>\
    \ roots = {0})\r\n\t\t\t: g(_g),\r\n\t\t\t\tid(0),\r\n\t\t\t\tsize(g.size(), 0),\r\
    \n\t\t\t\tdepth(g.size(), 0),\r\n\t\t\t\tdown(g.size(), -1),\r\n\t\t\t\tup(g.size(),\
    \ -1),\r\n\t\t\t\tnxt(g.size(), 0), \r\n\t\t\t\tpar(g.size(), 0) {\r\n\t\tfor\
    \ (int root : roots) {\r\n\t\t\tpar[root] = nxt[root] = root;\r\n\t\t\tdfs_sz(root);\r\
    \n\t\t\tdfs_hld(root);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid build(std::vector<int> roots)\
    \ {\r\n\t\tfor (int root : roots) {\r\n\t\t\tpar[root] = nxt[root] = root;\r\n\
    \t\t\tdfs_sz(root);\r\n\t\t\tdfs_hld(root);\r\n\t\t}\r\n\t}\r\n\r\n\t// [l, r],\
    \ inclusive for subtree\r\n\tstd::pair<int, int> idx(int i) const { return {down[i],\
    \ up[i] - 1}; }\r\n\r\n\ttemplate <class F>\r\n\tvoid path_query(int u, int v,\
    \ bool vertex, const F& f) {\r\n\t\tint l = lca(u, v);\r\n\t\tfor (auto&& [a,\
    \ b] : ascend(u, l)) {\r\n\t\t\tint s = a + 1, t = b;\r\n\t\t\ts > t ? f(t, s\
    \ - 1) : f(s, t - 1);\r\n\t\t}\r\n\t\tif (vertex) f(down[l], down[l]);\r\n\t\t\
    for (auto&& [a, b] : descend(l, v)) {\r\n\t\t\tint s = a, t = b + 1;\r\n\t\t\t\
    s > t ? f(t, s - 1) : f(s, t - 1);\r\n\t\t}\r\n\t}\r\n\r\n\ttemplate <class F>\r\
    \n\tvoid path_noncommutative_query(int u, int v, bool vertex, const F& f) {\r\n\
    \t\tint l = lca(u, v);\r\n\t\tfor (auto&& [a, b] : ascend(u, l)) f(a + 1, b -\
    \ 1);\r\n\t\tif (vertex) f(down[l], down[l]);\r\n\t\tfor (auto&& [a, b] : descend(l,\
    \ v)) f(a, b);\r\n\t}\r\n\r\n\ttemplate <class F>\r\n\tvoid subtree_query(int\
    \ u, bool vertex, const F& f) {\r\n\t\tf(down[u] + int(!vertex), up[u] - 1);\r\
    \n\t}\r\n\r\n\tint lca(int a, int b) {\r\n\t\twhile (nxt[a] != nxt[b]) {\r\n\t\
    \t\tif (down[a] < down[b]) std::swap(a, b);\r\n\t\t\ta = par[nxt[a]];\r\n\t\t\
    }\r\n\t\treturn depth[a] < depth[b] ? a : b;\r\n\t}\r\n\r\n\tint dist(int a, int\
    \ b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class G> \r\nstruct HeavyLightDecomposition\
    \ {\r\nprivate:\r\n\tvoid dfs_sz(int cur) {\r\n\t\tsize[cur] = 1;\r\n\t\tfor (auto&\
    \ dst : g[cur]) {\r\n\t\t\tif (dst == par[cur]) {\r\n\t\t\t\tif (g[cur].size()\
    \ >= 2 && int(dst) == int(g[cur][0]))\r\n\t\t\t\t\tstd::swap(g[cur][0], g[cur][1]);\r\
    \n\t\t\t\telse\r\n\t\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdepth[dst] = depth[cur]\
    \ + 1;\r\n\t\t\tpar[dst] = cur;\r\n\t\t\tdfs_sz(dst);\r\n\t\t\tsize[cur] += size[dst];\r\
    \n\t\t\tif (size[dst] > size[g[cur][0]]) {\r\n\t\t\t\tstd::swap(dst, g[cur][0]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dfs_hld(int cur) {\r\n\t\tdown[cur] =\
    \ id++;\r\n\t\tfor (auto dst : g[cur]) {\r\n\t\t\tif (dst == par[cur]) continue;\r\
    \n\t\t\tnxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\r\n\t\t\
    \tdfs_hld(dst);\r\n\t\t}\r\n\t\tup[cur] = id;\r\n\t}\r\n\r\n\t// [u, v)\r\n\t\
    std::vector<std::pair<int, int>> ascend(int u, int v) const {\r\n\t\tstd::vector<std::pair<int,\
    \ int>> res;\r\n\t\twhile (nxt[u] != nxt[v]) {\r\n\t\t\tres.emplace_back(down[u],\
    \ down[nxt[u]]);\r\n\t\t\tu = par[nxt[u]];\r\n\t\t}\r\n\t\tif (u != v) res.emplace_back(down[u],\
    \ down[v] + 1);\r\n\t\treturn res;\r\n\t}\r\n\r\n\t// (u, v]\r\n\tstd::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\r\n\t\tif (u == v) return {};\r\n\t\tif\
    \ (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};\r\n\t\tauto res = descend(u,\
    \ par[nxt[v]]);\r\n\t\tres.emplace_back(down[nxt[v]], down[v]);\r\n\t\treturn\
    \ res;\r\n\t}\r\n\r\npublic:\r\n\tG g;\r\n\tint id;\r\n\tstd::vector<int> size,\
    \ depth, down, up, nxt, par;\r\n\r\n\tHeavyLightDecomposition(G& _g, std::vector<int>\
    \ roots = {0})\r\n\t\t\t: g(_g),\r\n\t\t\t\tid(0),\r\n\t\t\t\tsize(g.size(), 0),\r\
    \n\t\t\t\tdepth(g.size(), 0),\r\n\t\t\t\tdown(g.size(), -1),\r\n\t\t\t\tup(g.size(),\
    \ -1),\r\n\t\t\t\tnxt(g.size(), 0), \r\n\t\t\t\tpar(g.size(), 0) {\r\n\t\tfor\
    \ (int root : roots) {\r\n\t\t\tpar[root] = nxt[root] = root;\r\n\t\t\tdfs_sz(root);\r\
    \n\t\t\tdfs_hld(root);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid build(std::vector<int> roots)\
    \ {\r\n\t\tfor (int root : roots) {\r\n\t\t\tpar[root] = nxt[root] = root;\r\n\
    \t\t\tdfs_sz(root);\r\n\t\t\tdfs_hld(root);\r\n\t\t}\r\n\t}\r\n\r\n\t// [l, r],\
    \ inclusive for subtree\r\n\tstd::pair<int, int> idx(int i) const { return {down[i],\
    \ up[i] - 1}; }\r\n\r\n\ttemplate <class F>\r\n\tvoid path_query(int u, int v,\
    \ bool vertex, const F& f) {\r\n\t\tint l = lca(u, v);\r\n\t\tfor (auto&& [a,\
    \ b] : ascend(u, l)) {\r\n\t\t\tint s = a + 1, t = b;\r\n\t\t\ts > t ? f(t, s\
    \ - 1) : f(s, t - 1);\r\n\t\t}\r\n\t\tif (vertex) f(down[l], down[l]);\r\n\t\t\
    for (auto&& [a, b] : descend(l, v)) {\r\n\t\t\tint s = a, t = b + 1;\r\n\t\t\t\
    s > t ? f(t, s - 1) : f(s, t - 1);\r\n\t\t}\r\n\t}\r\n\r\n\ttemplate <class F>\r\
    \n\tvoid path_noncommutative_query(int u, int v, bool vertex, const F& f) {\r\n\
    \t\tint l = lca(u, v);\r\n\t\tfor (auto&& [a, b] : ascend(u, l)) f(a + 1, b -\
    \ 1);\r\n\t\tif (vertex) f(down[l], down[l]);\r\n\t\tfor (auto&& [a, b] : descend(l,\
    \ v)) f(a, b);\r\n\t}\r\n\r\n\ttemplate <class F>\r\n\tvoid subtree_query(int\
    \ u, bool vertex, const F& f) {\r\n\t\tf(down[u] + int(!vertex), up[u] - 1);\r\
    \n\t}\r\n\r\n\tint lca(int a, int b) {\r\n\t\twhile (nxt[a] != nxt[b]) {\r\n\t\
    \t\tif (down[a] < down[b]) std::swap(a, b);\r\n\t\t\ta = par[nxt[a]];\r\n\t\t\
    }\r\n\t\treturn depth[a] < depth[b] ? a : b;\r\n\t}\r\n\r\n\tint dist(int a, int\
    \ b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/heavy-light-decomposition.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
documentation_of: library/graphs/heavy-light-decomposition.hpp
layout: document
redirect_from:
- /library/library/graphs/heavy-light-decomposition.hpp
- /library/library/graphs/heavy-light-decomposition.hpp.html
title: library/graphs/heavy-light-decomposition.hpp
---
