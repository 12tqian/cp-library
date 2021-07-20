---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/two_sat.cpp\"\n#include <bits/stdc++.h>\n\
    \nstruct SCC {\n    int n, ti;\n    \n    std::vector<std::vector<int>> g;\n \
    \   \n    std::vector<int> disc, comp, stk, comps;\n\n    void init(int _n) {\n\
    \        n = _n;\n        ti = 0;\n        g.resize(n);\n        disc.resize(n);\n\
    \        comp.assign(n, -1);\n    }\n\n    void ae(int u, int v) {\n        g[u].push_back(v);\n\
    \    }\n\n    int dfs(int u) {\n        int low = disc[u] = ++ti;\n        stk.push_back(u);\n\
    \        for (int v : g[u]) {\n            if (comp[v] == -1) {\n            \
    \    low = std::min(low, disc[v] ? : dfs(v));\n            }\n        }\n    \
    \    if (low == disc[u]) {\n            comps.push_back(u);\n            for (int\
    \ v  = -1; v != u; ) {\n                comp[v = stk.back()] = u;\n          \
    \      stk.pop_back();\n            }\n        }\n        return low;\n    }\n\
    \n    void gen() {\n        for (int i = 0; i < n; ++i) {\n            if (disc[i]\
    \ == 0) {\n                dfs(i);\n            }\n        }\n        reverse(comps.begin(),\
    \ comps.end());\n    }\n};\n\nstruct TwoSat {\n    int n = 0;\n    \n    std::vector<std::array<int,\
    \ 2>> edges;\n\n    void init(int n_) { n = n_; }\n    \n    int add_var() { return\
    \ n++; }\n    \n    void either(int x, int y) {\n        x = std::max(2 * x, -1\
    \ - 2 * x);\n        y = std::max(2 * y, -1 - 2 * y);\n        edges.push_back({x,\
    \ y});\n    }\n\n    void implies(int x, int y) { either(~x, y); }\n    \n   \
    \ void must(int x) { either(x, x); }\n    \n    void at_most_one(const std::vector<int>&\
    \ v) {\n        if ((int)v.size() <= 1) {\n            return;\n        }\n  \
    \      int cur = ~v[0];\n        for (int i = 2; i < (int)v.size(); ++i) {\n \
    \           int nxt = add_var();\n            either(cur, ~v[i]);\n          \
    \  either(cur, nxt);\n            either(~v[i], nxt);\n            cur = ~nxt;\n\
    \        }\n        either(cur, ~v[1]);\n    }\n    \n    std::vector<bool> solve(int\
    \ n_ = -1) {\n        if (n_ != -1) {\n            n = n_;\n        }\n      \
    \  SCC S;\n        S.init(2 * n);\n        for (auto [u, v] : edges) {\n     \
    \       S.ae(u ^ 1, v);\n            S.ae(v ^ 1, u);\n        }\n        S.gen();\n\
    \        reverse(S.comps.begin(), S.comps.end());\n        for (int i = 0; i <\
    \ 2 * n; i += 2) {\n            if (S.comp[i] == S.comp[i ^ 1]) {\n          \
    \      return {};\n            }\n        }\n        std::vector<int> tmp(2 *\
    \ n);\n        for (int i : S.comps) {\n            if (tmp[i] == 0) {\n     \
    \           tmp[i] = 1;\n                tmp[S.comp[i ^ 1]] = -1;\n          \
    \  }\n        }\n        std::vector<bool> ans(n);\n        for (int i = 0; i\
    \ < n; ++i) {\n            ans[i] = tmp[S.comp[2 * i]] == 1;\n        }\n    \
    \    return ans;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\nstruct SCC {\n    int n, ti;\n    \n    std::vector<std::vector<int>>\
    \ g;\n    \n    std::vector<int> disc, comp, stk, comps;\n\n    void init(int\
    \ _n) {\n        n = _n;\n        ti = 0;\n        g.resize(n);\n        disc.resize(n);\n\
    \        comp.assign(n, -1);\n    }\n\n    void ae(int u, int v) {\n        g[u].push_back(v);\n\
    \    }\n\n    int dfs(int u) {\n        int low = disc[u] = ++ti;\n        stk.push_back(u);\n\
    \        for (int v : g[u]) {\n            if (comp[v] == -1) {\n            \
    \    low = std::min(low, disc[v] ? : dfs(v));\n            }\n        }\n    \
    \    if (low == disc[u]) {\n            comps.push_back(u);\n            for (int\
    \ v  = -1; v != u; ) {\n                comp[v = stk.back()] = u;\n          \
    \      stk.pop_back();\n            }\n        }\n        return low;\n    }\n\
    \n    void gen() {\n        for (int i = 0; i < n; ++i) {\n            if (disc[i]\
    \ == 0) {\n                dfs(i);\n            }\n        }\n        reverse(comps.begin(),\
    \ comps.end());\n    }\n};\n\nstruct TwoSat {\n    int n = 0;\n    \n    std::vector<std::array<int,\
    \ 2>> edges;\n\n    void init(int n_) { n = n_; }\n    \n    int add_var() { return\
    \ n++; }\n    \n    void either(int x, int y) {\n        x = std::max(2 * x, -1\
    \ - 2 * x);\n        y = std::max(2 * y, -1 - 2 * y);\n        edges.push_back({x,\
    \ y});\n    }\n\n    void implies(int x, int y) { either(~x, y); }\n    \n   \
    \ void must(int x) { either(x, x); }\n    \n    void at_most_one(const std::vector<int>&\
    \ v) {\n        if ((int)v.size() <= 1) {\n            return;\n        }\n  \
    \      int cur = ~v[0];\n        for (int i = 2; i < (int)v.size(); ++i) {\n \
    \           int nxt = add_var();\n            either(cur, ~v[i]);\n          \
    \  either(cur, nxt);\n            either(~v[i], nxt);\n            cur = ~nxt;\n\
    \        }\n        either(cur, ~v[1]);\n    }\n    \n    std::vector<bool> solve(int\
    \ n_ = -1) {\n        if (n_ != -1) {\n            n = n_;\n        }\n      \
    \  SCC S;\n        S.init(2 * n);\n        for (auto [u, v] : edges) {\n     \
    \       S.ae(u ^ 1, v);\n            S.ae(v ^ 1, u);\n        }\n        S.gen();\n\
    \        reverse(S.comps.begin(), S.comps.end());\n        for (int i = 0; i <\
    \ 2 * n; i += 2) {\n            if (S.comp[i] == S.comp[i ^ 1]) {\n          \
    \      return {};\n            }\n        }\n        std::vector<int> tmp(2 *\
    \ n);\n        for (int i : S.comps) {\n            if (tmp[i] == 0) {\n     \
    \           tmp[i] = 1;\n                tmp[S.comp[i ^ 1]] = -1;\n          \
    \  }\n        }\n        std::vector<bool> ans(n);\n        for (int i = 0; i\
    \ < n; ++i) {\n            ans[i] = tmp[S.comp[2 * i]] == 1;\n        }\n    \
    \    return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/two_sat.cpp
  requiredBy: []
  timestamp: '2021-07-20 00:09:44-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/two_sat.cpp
layout: document
redirect_from:
- /library/library/graphs/two_sat.cpp
- /library/library/graphs/two_sat.cpp.html
title: library/graphs/two_sat.cpp
---
