---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n\nstruct SCC {\n\tint n, ti;\n\t\n\tstd::vector<std::vector<int>>\
    \ g;\n\t\n\tstd::vector<int> disc, comp, stk, comps;\n\n\tvoid init(int _n) {\n\
    \t\tn = _n;\n\t\tti = 0;\n\t\tg.resize(n);\n\t\tdisc.resize(n);\n\t\tcomp.assign(n,\
    \ -1);\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t}\n\n\tint\
    \ dfs(int u) {\n\t\tint low = disc[u] = ++ti;\n\t\tstk.push_back(u);\n\t\tfor\
    \ (int v : g[u]) {\n\t\t\tif (comp[v] == -1) {\n\t\t\t\tlow = std::min(low, disc[v]\
    \ ? : dfs(v));\n\t\t\t}\n\t\t}\n\t\tif (low == disc[u]) {\n\t\t\tcomps.push_back(u);\n\
    \t\t\tfor (int v  = -1; v != u; ) {\n\t\t\t\tcomp[v = stk.back()] = u;\n\t\t\t\
    \tstk.pop_back();\n\t\t\t}\n\t\t}\n\t\treturn low;\n\t}\n\n\tvoid gen() {\n\t\t\
    for (int i = 0; i < n; ++i) {\n\t\t\tif (disc[i] == 0) {\n\t\t\t\tdfs(i);\n\t\t\
    \t}\n\t\t}\n\t\treverse(comps.begin(), comps.end());\n\t}\n};\n\nstruct TwoSat\
    \ {\n\tint n = 0;\n\t\n\tstd::vector<std::array<int, 2>> edges;\n\n\tvoid init(int\
    \ n_) { n = n_; }\n\t\n\tint add_var() { return n++; }\n\t\n\tvoid either(int\
    \ x, int y) {\n\t\tx = std::max(2 * x, -1 - 2 * x);\n\t\ty = std::max(2 * y, -1\
    \ - 2 * y);\n\t\tedges.push_back({x, y});\n\t}\n\n\tvoid implies(int x, int y)\
    \ { either(~x, y); }\n\t\n\tvoid must(int x) { either(x, x); }\n\t\n\tvoid at_most_one(const\
    \ std::vector<int> &v) {\n\t\tif ((int)v.size() <= 1) {\n\t\t\treturn;\n\t\t}\n\
    \t\tint cur = ~v[0];\n\t\tfor (int i = 2; i < (int)v.size(); ++i) {\n\t\t\tint\
    \ nxt = add_var();\n\t\t\teither(cur, ~v[i]);\n\t\t\teither(cur, nxt);\n\t\t\t\
    either(~v[i], nxt);\n\t\t\tcur = ~nxt;\n\t\t}\n\t\teither(cur, ~v[1]);\n\t}\n\t\
    \n\tstd::vector<bool> solve(int n_ = -1) {\n\t\tif (n_ != -1) {\n\t\t\tn = n_;\n\
    \t\t}\n\t\tSCC S;\n\t\tS.init(2 * n);\n\t\tfor (auto [u, v] : edges) {\n\t\t\t\
    S.ae(u ^ 1, v);\n\t\t\tS.ae(v ^ 1, u);\n\t\t}\n\t\tS.gen();\n\t\treverse(S.comps.begin(),\
    \ S.comps.end());\n\t\tfor (int i = 0; i < 2 * n; i += 2) {\n\t\t\tif (S.comp[i]\
    \ == S.comp[i ^ 1]) {\n\t\t\t\treturn {};\n\t\t\t}\n\t\t}\n\t\tstd::vector<int>\
    \ tmp(2 * n);\n\t\tfor (int i : S.comps) {\n\t\t\tif (tmp[i] == 0) {\n\t\t\t\t\
    tmp[i] = 1;\n\t\t\t\ttmp[S.comp[i ^ 1]] = -1;\n\t\t\t}\n\t\t}\n\t\tstd::vector<bool>\
    \ ans(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tans[i] = tmp[S.comp[2 * i]]\
    \ == 1;\n\t\t}\n\t\treturn ans;\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\n\nstruct SCC {\n\tint n, ti;\n\t\n\tstd::vector<std::vector<int>>\
    \ g;\n\t\n\tstd::vector<int> disc, comp, stk, comps;\n\n\tvoid init(int _n) {\n\
    \t\tn = _n;\n\t\tti = 0;\n\t\tg.resize(n);\n\t\tdisc.resize(n);\n\t\tcomp.assign(n,\
    \ -1);\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t}\n\n\tint\
    \ dfs(int u) {\n\t\tint low = disc[u] = ++ti;\n\t\tstk.push_back(u);\n\t\tfor\
    \ (int v : g[u]) {\n\t\t\tif (comp[v] == -1) {\n\t\t\t\tlow = std::min(low, disc[v]\
    \ ? : dfs(v));\n\t\t\t}\n\t\t}\n\t\tif (low == disc[u]) {\n\t\t\tcomps.push_back(u);\n\
    \t\t\tfor (int v  = -1; v != u; ) {\n\t\t\t\tcomp[v = stk.back()] = u;\n\t\t\t\
    \tstk.pop_back();\n\t\t\t}\n\t\t}\n\t\treturn low;\n\t}\n\n\tvoid gen() {\n\t\t\
    for (int i = 0; i < n; ++i) {\n\t\t\tif (disc[i] == 0) {\n\t\t\t\tdfs(i);\n\t\t\
    \t}\n\t\t}\n\t\treverse(comps.begin(), comps.end());\n\t}\n};\n\nstruct TwoSat\
    \ {\n\tint n = 0;\n\t\n\tstd::vector<std::array<int, 2>> edges;\n\n\tvoid init(int\
    \ n_) { n = n_; }\n\t\n\tint add_var() { return n++; }\n\t\n\tvoid either(int\
    \ x, int y) {\n\t\tx = std::max(2 * x, -1 - 2 * x);\n\t\ty = std::max(2 * y, -1\
    \ - 2 * y);\n\t\tedges.push_back({x, y});\n\t}\n\n\tvoid implies(int x, int y)\
    \ { either(~x, y); }\n\t\n\tvoid must(int x) { either(x, x); }\n\t\n\tvoid at_most_one(const\
    \ std::vector<int> &v) {\n\t\tif ((int)v.size() <= 1) {\n\t\t\treturn;\n\t\t}\n\
    \t\tint cur = ~v[0];\n\t\tfor (int i = 2; i < (int)v.size(); ++i) {\n\t\t\tint\
    \ nxt = add_var();\n\t\t\teither(cur, ~v[i]);\n\t\t\teither(cur, nxt);\n\t\t\t\
    either(~v[i], nxt);\n\t\t\tcur = ~nxt;\n\t\t}\n\t\teither(cur, ~v[1]);\n\t}\n\t\
    \n\tstd::vector<bool> solve(int n_ = -1) {\n\t\tif (n_ != -1) {\n\t\t\tn = n_;\n\
    \t\t}\n\t\tSCC S;\n\t\tS.init(2 * n);\n\t\tfor (auto [u, v] : edges) {\n\t\t\t\
    S.ae(u ^ 1, v);\n\t\t\tS.ae(v ^ 1, u);\n\t\t}\n\t\tS.gen();\n\t\treverse(S.comps.begin(),\
    \ S.comps.end());\n\t\tfor (int i = 0; i < 2 * n; i += 2) {\n\t\t\tif (S.comp[i]\
    \ == S.comp[i ^ 1]) {\n\t\t\t\treturn {};\n\t\t\t}\n\t\t}\n\t\tstd::vector<int>\
    \ tmp(2 * n);\n\t\tfor (int i : S.comps) {\n\t\t\tif (tmp[i] == 0) {\n\t\t\t\t\
    tmp[i] = 1;\n\t\t\t\ttmp[S.comp[i ^ 1]] = -1;\n\t\t\t}\n\t\t}\n\t\tstd::vector<bool>\
    \ ans(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tans[i] = tmp[S.comp[2 * i]]\
    \ == 1;\n\t\t}\n\t\treturn ans;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/two-sat.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:26:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/two-sat.hpp
layout: document
redirect_from:
- /library/library/graphs/two-sat.hpp
- /library/library/graphs/two-sat.hpp.html
title: library/graphs/two-sat.hpp
---
