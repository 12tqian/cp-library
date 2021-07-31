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
  bundledCode: "template <class G> \nstruct HeavyLightDecomposition {\nprivate:\n\t\
    void dfs_sz(int cur) {\n\t\tsize[cur] = 1;\n\t\tfor (auto& dst : g[cur]) {\n\t\
    \t\tif (dst == par[cur]) {\n\t\t\t\tif (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \t\t\t\t\tstd::swap(g[cur][0], g[cur][1]);\n\t\t\t\telse\n\t\t\t\t\tcontinue;\n\
    \t\t\t}\n\t\t\tdepth[dst] = depth[cur] + 1;\n\t\t\tpar[dst] = cur;\n\t\t\tdfs_sz(dst);\n\
    \t\t\tsize[cur] += size[dst];\n\t\t\tif (size[dst] > size[g[cur][0]]) {\n\t\t\t\
    \tstd::swap(dst, g[cur][0]);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid dfs_hld(int cur) {\n\
    \t\tdown[cur] = id++;\n\t\tfor (auto dst : g[cur]) {\n\t\t\tif (dst == par[cur])\
    \ continue;\n\t\t\tnxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \t\t\tdfs_hld(dst);\n\t\t}\n\t\tup[cur] = id;\n\t}\n\n\t// [u, v)\n\tstd::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n\t\tstd::vector<std::pair<int, int>> res;\n\
    \t\twhile (nxt[u] != nxt[v]) {\n\t\t\tres.emplace_back(down[u], down[nxt[u]]);\n\
    \t\t\tu = par[nxt[u]];\n\t\t}\n\t\tif (u != v) res.emplace_back(down[u], down[v]\
    \ + 1);\n\t\treturn res;\n\t}\n\n\t// (u, v]\n\tstd::vector<std::pair<int, int>>\
    \ descend(int u, int v) const {\n\t\tif (u == v) return {};\n\t\tif (nxt[u] ==\
    \ nxt[v]) return {{down[u] + 1, down[v]}};\n\t\tauto res = descend(u, par[nxt[v]]);\n\
    \t\tres.emplace_back(down[nxt[v]], down[v]);\n\t\treturn res;\n\t}\n\npublic:\n\
    \tG g;\n\tint id;\n\tstd::vector<int> size, depth, down, up, nxt, par;\n\n\tHeavyLightDecomposition(G&\
    \ _g, std::vector<int> roots = {0})\n\t\t\t: g(_g),\n\t\t\t\tid(0),\n\t\t\t\t\
    size(g.size(), 0),\n\t\t\t\tdepth(g.size(), 0),\n\t\t\t\tdown(g.size(), -1),\n\
    \t\t\t\tup(g.size(), -1),\n\t\t\t\tnxt(g.size(), 0), \n\t\t\t\tpar(g.size(), 0)\
    \ {\n\t\tfor (int root : roots) {\n\t\t\tpar[root] = nxt[root] = root;\n\t\t\t\
    dfs_sz(root);\n\t\t\tdfs_hld(root);\n\t\t}\n\t}\n\n\tvoid build(std::vector<int>\
    \ roots) {\n\t\tfor (int root : roots) {\n\t\t\tpar[root] = nxt[root] = root;\n\
    \t\t\tdfs_sz(root);\n\t\t\tdfs_hld(root);\n\t\t}\n\t}\n\n\t// [l, r], inclusive\
    \ for subtree\n\tstd::pair<int, int> idx(int i) const { return {down[i], up[i]\
    \ - 1}; }\n\n\ttemplate <class F>\n\tvoid path_query(int u, int v, bool vertex,\
    \ const F& f) {\n\t\tint l = lca(u, v);\n\t\tfor (auto&& [a, b] : ascend(u, l))\
    \ {\n\t\t\tint s = a + 1, t = b;\n\t\t\ts > t ? f(t, s - 1) : f(s, t - 1);\n\t\
    \t}\n\t\tif (vertex) f(down[l], down[l]);\n\t\tfor (auto&& [a, b] : descend(l,\
    \ v)) {\n\t\t\tint s = a, t = b + 1;\n\t\t\ts > t ? f(t, s - 1) : f(s, t - 1);\n\
    \t\t}\n\t}\n\n\ttemplate <class F>\n\tvoid path_noncommutative_query(int u, int\
    \ v, bool vertex, const F& f) {\n\t\tint l = lca(u, v);\n\t\tfor (auto&& [a, b]\
    \ : ascend(u, l)) f(a + 1, b - 1);\n\t\tif (vertex) f(down[l], down[l]);\n\t\t\
    for (auto&& [a, b] : descend(l, v)) f(a, b);\n\t}\n\n\ttemplate <class F>\n\t\
    void subtree_query(int u, bool vertex, const F& f) {\n\t\tf(down[u] + int(!vertex),\
    \ up[u] - 1);\n\t}\n\n\tint lca(int a, int b) {\n\t\twhile (nxt[a] != nxt[b])\
    \ {\n\t\t\tif (down[a] < down[b]) std::swap(a, b);\n\t\t\ta = par[nxt[a]];\n\t\
    \t}\n\t\treturn depth[a] < depth[b] ? a : b;\n\t}\n\n\tint dist(int a, int b)\
    \ { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};\n"
  code: "template <class G> \nstruct HeavyLightDecomposition {\nprivate:\n\tvoid dfs_sz(int\
    \ cur) {\n\t\tsize[cur] = 1;\n\t\tfor (auto& dst : g[cur]) {\n\t\t\tif (dst ==\
    \ par[cur]) {\n\t\t\t\tif (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \t\t\t\t\tstd::swap(g[cur][0], g[cur][1]);\n\t\t\t\telse\n\t\t\t\t\tcontinue;\n\
    \t\t\t}\n\t\t\tdepth[dst] = depth[cur] + 1;\n\t\t\tpar[dst] = cur;\n\t\t\tdfs_sz(dst);\n\
    \t\t\tsize[cur] += size[dst];\n\t\t\tif (size[dst] > size[g[cur][0]]) {\n\t\t\t\
    \tstd::swap(dst, g[cur][0]);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid dfs_hld(int cur) {\n\
    \t\tdown[cur] = id++;\n\t\tfor (auto dst : g[cur]) {\n\t\t\tif (dst == par[cur])\
    \ continue;\n\t\t\tnxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \t\t\tdfs_hld(dst);\n\t\t}\n\t\tup[cur] = id;\n\t}\n\n\t// [u, v)\n\tstd::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n\t\tstd::vector<std::pair<int, int>> res;\n\
    \t\twhile (nxt[u] != nxt[v]) {\n\t\t\tres.emplace_back(down[u], down[nxt[u]]);\n\
    \t\t\tu = par[nxt[u]];\n\t\t}\n\t\tif (u != v) res.emplace_back(down[u], down[v]\
    \ + 1);\n\t\treturn res;\n\t}\n\n\t// (u, v]\n\tstd::vector<std::pair<int, int>>\
    \ descend(int u, int v) const {\n\t\tif (u == v) return {};\n\t\tif (nxt[u] ==\
    \ nxt[v]) return {{down[u] + 1, down[v]}};\n\t\tauto res = descend(u, par[nxt[v]]);\n\
    \t\tres.emplace_back(down[nxt[v]], down[v]);\n\t\treturn res;\n\t}\n\npublic:\n\
    \tG g;\n\tint id;\n\tstd::vector<int> size, depth, down, up, nxt, par;\n\n\tHeavyLightDecomposition(G&\
    \ _g, std::vector<int> roots = {0})\n\t\t\t: g(_g),\n\t\t\t\tid(0),\n\t\t\t\t\
    size(g.size(), 0),\n\t\t\t\tdepth(g.size(), 0),\n\t\t\t\tdown(g.size(), -1),\n\
    \t\t\t\tup(g.size(), -1),\n\t\t\t\tnxt(g.size(), 0), \n\t\t\t\tpar(g.size(), 0)\
    \ {\n\t\tfor (int root : roots) {\n\t\t\tpar[root] = nxt[root] = root;\n\t\t\t\
    dfs_sz(root);\n\t\t\tdfs_hld(root);\n\t\t}\n\t}\n\n\tvoid build(std::vector<int>\
    \ roots) {\n\t\tfor (int root : roots) {\n\t\t\tpar[root] = nxt[root] = root;\n\
    \t\t\tdfs_sz(root);\n\t\t\tdfs_hld(root);\n\t\t}\n\t}\n\n\t// [l, r], inclusive\
    \ for subtree\n\tstd::pair<int, int> idx(int i) const { return {down[i], up[i]\
    \ - 1}; }\n\n\ttemplate <class F>\n\tvoid path_query(int u, int v, bool vertex,\
    \ const F& f) {\n\t\tint l = lca(u, v);\n\t\tfor (auto&& [a, b] : ascend(u, l))\
    \ {\n\t\t\tint s = a + 1, t = b;\n\t\t\ts > t ? f(t, s - 1) : f(s, t - 1);\n\t\
    \t}\n\t\tif (vertex) f(down[l], down[l]);\n\t\tfor (auto&& [a, b] : descend(l,\
    \ v)) {\n\t\t\tint s = a, t = b + 1;\n\t\t\ts > t ? f(t, s - 1) : f(s, t - 1);\n\
    \t\t}\n\t}\n\n\ttemplate <class F>\n\tvoid path_noncommutative_query(int u, int\
    \ v, bool vertex, const F& f) {\n\t\tint l = lca(u, v);\n\t\tfor (auto&& [a, b]\
    \ : ascend(u, l)) f(a + 1, b - 1);\n\t\tif (vertex) f(down[l], down[l]);\n\t\t\
    for (auto&& [a, b] : descend(l, v)) f(a, b);\n\t}\n\n\ttemplate <class F>\n\t\
    void subtree_query(int u, bool vertex, const F& f) {\n\t\tf(down[u] + int(!vertex),\
    \ up[u] - 1);\n\t}\n\n\tint lca(int a, int b) {\n\t\twhile (nxt[a] != nxt[b])\
    \ {\n\t\t\tif (down[a] < down[b]) std::swap(a, b);\n\t\t\ta = par[nxt[a]];\n\t\
    \t}\n\t\treturn depth[a] < depth[b] ? a : b;\n\t}\n\n\tint dist(int a, int b)\
    \ { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/heavy-light-decomposition.hpp
  requiredBy: []
  timestamp: '2021-07-31 14:30:12-04:00'
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
