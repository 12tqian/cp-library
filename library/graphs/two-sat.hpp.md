---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/atcoder/atcoder-abc210_f.test.cpp
    title: verify/atcoder/atcoder-abc210_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nstruct SCC {\r\n\tint n, ti;\r\n\t\r\n\tstd::vector<std::vector<int>>\
    \ g;\r\n\t\r\n\tstd::vector<int> disc, comp, stk, comps;\r\n\r\n\tvoid init(int\
    \ _n) {\r\n\t\tn = _n;\r\n\t\tti = 0;\r\n\t\tg.resize(n);\r\n\t\tdisc.resize(n);\r\
    \n\t\tcomp.assign(n, -1);\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tg[u].push_back(v);\r\
    \n\t}\r\n\r\n\tint dfs(int u) {\r\n\t\tint low = disc[u] = ++ti;\r\n\t\tstk.push_back(u);\r\
    \n\t\tfor (int v : g[u]) {\r\n\t\t\tif (comp[v] == -1) {\r\n\t\t\t\tlow = std::min(low,\
    \ disc[v] ? : dfs(v));\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (low == disc[u]) {\r\n\t\t\
    \tcomps.push_back(u);\r\n\t\t\tfor (int v  = -1; v != u; ) {\r\n\t\t\t\tcomp[v\
    \ = stk.back()] = u;\r\n\t\t\t\tstk.pop_back();\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ low;\r\n\t}\r\n\r\n\tvoid gen() {\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\
    \t\tif (disc[i] == 0) {\r\n\t\t\t\tdfs(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\treverse(comps.begin(),\
    \ comps.end());\r\n\t}\r\n};\r\n\r\nstruct TwoSat {\r\n\tint n = 0;\r\n\t\r\n\t\
    std::vector<std::array<int, 2>> edges;\r\n\r\n\tvoid init(int n_) { n = n_; }\r\
    \n\t\r\n\tint add_var() { return n++; }\r\n\t\r\n\tvoid either(int x, int y) {\r\
    \n\t\tx = std::max(2 * x, -1 - 2 * x);\r\n\t\ty = std::max(2 * y, -1 - 2 * y);\r\
    \n\t\tedges.push_back({x, y});\r\n\t}\r\n\r\n\tvoid implies(int x, int y) { either(~x,\
    \ y); }\r\n\t\r\n\tvoid must(int x) { either(x, x); }\r\n\t\r\n\tvoid at_most_one(const\
    \ std::vector<int>& v) {\r\n\t\tif ((int)v.size() <= 1) {\r\n\t\t\treturn;\r\n\
    \t\t}\r\n\t\tint cur = ~v[0];\r\n\t\tfor (int i = 2; i < (int)v.size(); ++i) {\r\
    \n\t\t\tint nxt = add_var();\r\n\t\t\teither(cur, ~v[i]);\r\n\t\t\teither(cur,\
    \ nxt);\r\n\t\t\teither(~v[i], nxt);\r\n\t\t\tcur = ~nxt;\r\n\t\t}\r\n\t\teither(cur,\
    \ ~v[1]);\r\n\t}\r\n\t\r\n\tstd::vector<bool> solve(int n_ = -1) {\r\n\t\tif (n_\
    \ != -1) {\r\n\t\t\tn = n_;\r\n\t\t}\r\n\t\tSCC S;\r\n\t\tS.init(2 * n);\r\n\t\
    \tfor (auto [u, v] : edges) {\r\n\t\t\tS.ae(u ^ 1, v);\r\n\t\t\tS.ae(v ^ 1, u);\r\
    \n\t\t}\r\n\t\tS.gen();\r\n\t\treverse(S.comps.begin(), S.comps.end());\r\n\t\t\
    for (int i = 0; i < 2 * n; i += 2) {\r\n\t\t\tif (S.comp[i] == S.comp[i ^ 1])\
    \ {\r\n\t\t\t\treturn {};\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int> tmp(2 *\
    \ n);\r\n\t\tfor (int i : S.comps) {\r\n\t\t\tif (tmp[i] == 0) {\r\n\t\t\t\ttmp[i]\
    \ = 1;\r\n\t\t\t\ttmp[S.comp[i ^ 1]] = -1;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<bool>\
    \ ans(n);\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tans[i] = tmp[S.comp[2\
    \ * i]] == 1;\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\nstruct SCC {\r\n\tint n, ti;\r\n\t\r\n\tstd::vector<std::vector<int>>\
    \ g;\r\n\t\r\n\tstd::vector<int> disc, comp, stk, comps;\r\n\r\n\tvoid init(int\
    \ _n) {\r\n\t\tn = _n;\r\n\t\tti = 0;\r\n\t\tg.resize(n);\r\n\t\tdisc.resize(n);\r\
    \n\t\tcomp.assign(n, -1);\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tg[u].push_back(v);\r\
    \n\t}\r\n\r\n\tint dfs(int u) {\r\n\t\tint low = disc[u] = ++ti;\r\n\t\tstk.push_back(u);\r\
    \n\t\tfor (int v : g[u]) {\r\n\t\t\tif (comp[v] == -1) {\r\n\t\t\t\tlow = std::min(low,\
    \ disc[v] ? : dfs(v));\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (low == disc[u]) {\r\n\t\t\
    \tcomps.push_back(u);\r\n\t\t\tfor (int v  = -1; v != u; ) {\r\n\t\t\t\tcomp[v\
    \ = stk.back()] = u;\r\n\t\t\t\tstk.pop_back();\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ low;\r\n\t}\r\n\r\n\tvoid gen() {\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\
    \t\tif (disc[i] == 0) {\r\n\t\t\t\tdfs(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\treverse(comps.begin(),\
    \ comps.end());\r\n\t}\r\n};\r\n\r\nstruct TwoSat {\r\n\tint n = 0;\r\n\t\r\n\t\
    std::vector<std::array<int, 2>> edges;\r\n\r\n\tvoid init(int n_) { n = n_; }\r\
    \n\t\r\n\tint add_var() { return n++; }\r\n\t\r\n\tvoid either(int x, int y) {\r\
    \n\t\tx = std::max(2 * x, -1 - 2 * x);\r\n\t\ty = std::max(2 * y, -1 - 2 * y);\r\
    \n\t\tedges.push_back({x, y});\r\n\t}\r\n\r\n\tvoid implies(int x, int y) { either(~x,\
    \ y); }\r\n\t\r\n\tvoid must(int x) { either(x, x); }\r\n\t\r\n\tvoid at_most_one(const\
    \ std::vector<int>& v) {\r\n\t\tif ((int)v.size() <= 1) {\r\n\t\t\treturn;\r\n\
    \t\t}\r\n\t\tint cur = ~v[0];\r\n\t\tfor (int i = 2; i < (int)v.size(); ++i) {\r\
    \n\t\t\tint nxt = add_var();\r\n\t\t\teither(cur, ~v[i]);\r\n\t\t\teither(cur,\
    \ nxt);\r\n\t\t\teither(~v[i], nxt);\r\n\t\t\tcur = ~nxt;\r\n\t\t}\r\n\t\teither(cur,\
    \ ~v[1]);\r\n\t}\r\n\t\r\n\tstd::vector<bool> solve(int n_ = -1) {\r\n\t\tif (n_\
    \ != -1) {\r\n\t\t\tn = n_;\r\n\t\t}\r\n\t\tSCC S;\r\n\t\tS.init(2 * n);\r\n\t\
    \tfor (auto [u, v] : edges) {\r\n\t\t\tS.ae(u ^ 1, v);\r\n\t\t\tS.ae(v ^ 1, u);\r\
    \n\t\t}\r\n\t\tS.gen();\r\n\t\treverse(S.comps.begin(), S.comps.end());\r\n\t\t\
    for (int i = 0; i < 2 * n; i += 2) {\r\n\t\t\tif (S.comp[i] == S.comp[i ^ 1])\
    \ {\r\n\t\t\t\treturn {};\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int> tmp(2 *\
    \ n);\r\n\t\tfor (int i : S.comps) {\r\n\t\t\tif (tmp[i] == 0) {\r\n\t\t\t\ttmp[i]\
    \ = 1;\r\n\t\t\t\ttmp[S.comp[i ^ 1]] = -1;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<bool>\
    \ ans(n);\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tans[i] = tmp[S.comp[2\
    \ * i]] == 1;\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/two-sat.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/atcoder/atcoder-abc210_f.test.cpp
documentation_of: library/graphs/two-sat.hpp
layout: document
redirect_from:
- /library/library/graphs/two-sat.hpp
- /library/library/graphs/two-sat.hpp.html
title: library/graphs/two-sat.hpp
---
