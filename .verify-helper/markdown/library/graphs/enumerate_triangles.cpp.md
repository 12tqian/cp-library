---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/enumerate_triangles.cpp\"\n#include<bits/stdc++.h>\r\
    \n\r\nconst int MOD = 998244353;\r\nint main() {\r\n    std::ios_base::sync_with_stdio(0);\
    \ std::cin.tie(0);\r\n    int n, m; std::cin >> n >> m;\r\n    std::vector<long\
    \ long> x(n);\r\n    for (int i = 0; i < n; i++) std::cin >> x[i];\r\n    std::vector<std::vector<int>>\
    \ adj(n);\r\n    for (int i = 0; i < m; i++) {\r\n        int u, v; std::cin >>\
    \ u >> v;\r\n        adj[u].push_back(v);\r\n        adj[v].push_back(u);\r\n\
    \    }\r\n    std::vector<int> vert(n);\r\n    std::vector<bool> good(n);\r\n\
    \    std::vector<bool> done(n);\r\n    iota(vert.begin(), vert.end(), 0);\r\n\
    \    sort(vert.begin(), vert.end(), [&](int i, int j) { return adj[i].size() <\
    \ adj[j].size(); });\r\n    int ans = 0;\r\n    for (int u: vert) {\r\n      \
    \  done[u] = true;\r\n        for (int v: adj[u]) good[v] = true;\r\n        for\
    \ (int v: adj[u]) {\r\n            if (done[v]) {\r\n                for (int\
    \ w: adj[v]) {\r\n                    if (!good[w]) continue;\r\n            \
    \        long long add = (x[u] * x[v]) % MOD;\r\n                    add = (add\
    \ * x[w]) % MOD;\r\n                    ans += add;\r\n                    if\
    \ (ans >= MOD) ans -= MOD;\r\n                }\r\n            }\r\n        }\r\
    \n        for (int v: adj[u]) good[v] = false;\r\n    }\r\n    auto mod_pow =\
    \ [&](long long base, long long exp) -> long long {\r\n        long long res =\
    \ 1;\r\n        while (exp) {\r\n            if (exp & 1) {\r\n              \
    \  res *= base;\r\n                res %= MOD;\r\n            }\r\n          \
    \  base *= base;\r\n            base %= MOD;\r\n            exp >>= 1;\r\n   \
    \     }\r\n        return res;\r\n    };\r\n    ans = (mod_pow(3, MOD - 2) * ans)\
    \ % MOD;\r\n    std::cout << ans << '\\n';\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\nconst int MOD = 998244353;\r\nint main() {\r\
    \n    std::ios_base::sync_with_stdio(0); std::cin.tie(0);\r\n    int n, m; std::cin\
    \ >> n >> m;\r\n    std::vector<long long> x(n);\r\n    for (int i = 0; i < n;\
    \ i++) std::cin >> x[i];\r\n    std::vector<std::vector<int>> adj(n);\r\n    for\
    \ (int i = 0; i < m; i++) {\r\n        int u, v; std::cin >> u >> v;\r\n     \
    \   adj[u].push_back(v);\r\n        adj[v].push_back(u);\r\n    }\r\n    std::vector<int>\
    \ vert(n);\r\n    std::vector<bool> good(n);\r\n    std::vector<bool> done(n);\r\
    \n    iota(vert.begin(), vert.end(), 0);\r\n    sort(vert.begin(), vert.end(),\
    \ [&](int i, int j) { return adj[i].size() < adj[j].size(); });\r\n    int ans\
    \ = 0;\r\n    for (int u: vert) {\r\n        done[u] = true;\r\n        for (int\
    \ v: adj[u]) good[v] = true;\r\n        for (int v: adj[u]) {\r\n            if\
    \ (done[v]) {\r\n                for (int w: adj[v]) {\r\n                   \
    \ if (!good[w]) continue;\r\n                    long long add = (x[u] * x[v])\
    \ % MOD;\r\n                    add = (add * x[w]) % MOD;\r\n                \
    \    ans += add;\r\n                    if (ans >= MOD) ans -= MOD;\r\n      \
    \          }\r\n            }\r\n        }\r\n        for (int v: adj[u]) good[v]\
    \ = false;\r\n    }\r\n    auto mod_pow = [&](long long base, long long exp) ->\
    \ long long {\r\n        long long res = 1;\r\n        while (exp) {\r\n     \
    \       if (exp & 1) {\r\n                res *= base;\r\n                res\
    \ %= MOD;\r\n            }\r\n            base *= base;\r\n            base %=\
    \ MOD;\r\n            exp >>= 1;\r\n        }\r\n        return res;\r\n    };\r\
    \n    ans = (mod_pow(3, MOD - 2) * ans) % MOD;\r\n    std::cout << ans << '\\\
    n';\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/enumerate_triangles.cpp
  requiredBy: []
  timestamp: '2020-11-24 21:12:56-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/enumerate_triangles.cpp
layout: document
redirect_from:
- /library/library/graphs/enumerate_triangles.cpp
- /library/library/graphs/enumerate_triangles.cpp.html
title: library/graphs/enumerate_triangles.cpp
---
