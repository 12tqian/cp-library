---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/enumerate_triangles.cpp\"\n#include<bits/stdc++.h>\n\
    \nconst int MOD = 998244353;\n\nint main() {\n    std::ios_base::sync_with_stdio(0);\
    \ std::cin.tie(0);\n    int n, m; std::cin >> n >> m;\n    std::vector<long long>\
    \ x(n);\n    for (int i = 0; i < n; i++) std::cin >> x[i];\n    std::vector<std::vector<int>>\
    \ adj(n);\n    for (int i = 0; i < m; i++) {\n        int u, v; std::cin >> u\
    \ >> v;\n        adj[u].push_back(v);\n        adj[v].push_back(u);\n    }\n \
    \   std::vector<int> vert(n);\n    std::vector<bool> good(n);\n    std::vector<bool>\
    \ done(n);\n    iota(vert.begin(), vert.end(), 0);\n    sort(vert.begin(), vert.end(),\
    \ [&](int i, int j) { return adj[i].size() < adj[j].size(); });\n    int ans =\
    \ 0;\n    for (int u: vert) {\n        done[u] = true;\n        for (int v: adj[u])\
    \ good[v] = true;\n        for (int v: adj[u]) {\n            if (done[v]) {\n\
    \                for (int w: adj[v]) {\n                    if (!good[w]) continue;\n\
    \                    long long add = (x[u] * x[v]) % MOD;\n                  \
    \  add = (add * x[w]) % MOD;\n                    ans += add;\n              \
    \      if (ans >= MOD) ans -= MOD;\n                }\n            }\n       \
    \ }\n        for (int v: adj[u]) good[v] = false;\n    }\n    auto mod_pow = [&](long\
    \ long base, long long exp) -> long long {\n        long long res = 1;\n     \
    \   while (exp) {\n            if (exp & 1) {\n                res *= base;\n\
    \                res %= MOD;\n            }\n            base *= base;\n     \
    \       base %= MOD;\n            exp >>= 1;\n        }\n        return res;\n\
    \    };\n    ans = (mod_pow(3, MOD - 2) * ans) % MOD;\n    std::cout << ans <<\
    \ '\\n';\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nconst int MOD = 998244353;\n\nint main() {\n \
    \   std::ios_base::sync_with_stdio(0); std::cin.tie(0);\n    int n, m; std::cin\
    \ >> n >> m;\n    std::vector<long long> x(n);\n    for (int i = 0; i < n; i++)\
    \ std::cin >> x[i];\n    std::vector<std::vector<int>> adj(n);\n    for (int i\
    \ = 0; i < m; i++) {\n        int u, v; std::cin >> u >> v;\n        adj[u].push_back(v);\n\
    \        adj[v].push_back(u);\n    }\n    std::vector<int> vert(n);\n    std::vector<bool>\
    \ good(n);\n    std::vector<bool> done(n);\n    iota(vert.begin(), vert.end(),\
    \ 0);\n    sort(vert.begin(), vert.end(), [&](int i, int j) { return adj[i].size()\
    \ < adj[j].size(); });\n    int ans = 0;\n    for (int u: vert) {\n        done[u]\
    \ = true;\n        for (int v: adj[u]) good[v] = true;\n        for (int v: adj[u])\
    \ {\n            if (done[v]) {\n                for (int w: adj[v]) {\n     \
    \               if (!good[w]) continue;\n                    long long add = (x[u]\
    \ * x[v]) % MOD;\n                    add = (add * x[w]) % MOD;\n            \
    \        ans += add;\n                    if (ans >= MOD) ans -= MOD;\n      \
    \          }\n            }\n        }\n        for (int v: adj[u]) good[v] =\
    \ false;\n    }\n    auto mod_pow = [&](long long base, long long exp) -> long\
    \ long {\n        long long res = 1;\n        while (exp) {\n            if (exp\
    \ & 1) {\n                res *= base;\n                res %= MOD;\n        \
    \    }\n            base *= base;\n            base %= MOD;\n            exp >>=\
    \ 1;\n        }\n        return res;\n    };\n    ans = (mod_pow(3, MOD - 2) *\
    \ ans) % MOD;\n    std::cout << ans << '\\n';\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/enumerate_triangles.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/enumerate_triangles.cpp
layout: document
redirect_from:
- /library/library/graphs/enumerate_triangles.cpp
- /library/library/graphs/enumerate_triangles.cpp.html
title: library/graphs/enumerate_triangles.cpp
---
