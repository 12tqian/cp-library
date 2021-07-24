---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/enumerate_triangles.cpp\"\n#include <bits/stdc++.h>\n\
    \nconst int MOD = 998244353;\n\nint main() {\n\tstd::ios_base::sync_with_stdio(0);\
    \ std::cin.tie(0);\n\tint n, m; std::cin >> n >> m;\n\tstd::vector<long long>\
    \ x(n);\n\tfor (int i = 0; i < n; i++) std::cin >> x[i];\n\tstd::vector<std::vector<int>>\
    \ adj(n);\n\tfor (int i = 0; i < m; i++) {\n\t\tint u, v; std::cin >> u >> v;\n\
    \t\tadj[u].push_back(v);\n\t\tadj[v].push_back(u);\n\t}\n\tstd::vector<int> vert(n);\n\
    \tstd::vector<bool> good(n);\n\tstd::vector<bool> done(n);\n\tiota(vert.begin(),\
    \ vert.end(), 0);\n\tsort(vert.begin(), vert.end(), [&](int i, int j) { return\
    \ adj[i].size() < adj[j].size(); });\n\tint ans = 0;\n\tfor (int u : vert) {\n\
    \t\tdone[u] = true;\n\t\tfor (int v : adj[u]) good[v] = true;\n\t\tfor (int v\
    \ : adj[u]) {\n\t\t\tif (done[v]) {\n\t\t\t\tfor (int w : adj[v]) {\n\t\t\t\t\t\
    if (!good[w]) continue;\n\t\t\t\t\tlong long add = (x[u] * x[v]) % MOD;\n\t\t\t\
    \t\tadd = (add * x[w]) % MOD;\n\t\t\t\t\tans += add;\n\t\t\t\t\tif (ans >= MOD)\
    \ ans -= MOD;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (int v: adj[u]) good[v] = false;\n\
    \t}\n\tauto mod_pow = [&](long long base, long long exp) -> long long {\n\t\t\
    long long res = 1;\n\t\twhile (exp) {\n\t\t\tif (exp & 1) {\n\t\t\t\tres *= base;\n\
    \t\t\t\tres %= MOD;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\tbase %= MOD;\n\t\t\t\
    exp >>= 1;\n\t\t}\n\t\treturn res;\n\t};\n\tans = (mod_pow(3, MOD - 2) * ans)\
    \ % MOD;\n\tstd::cout << ans << '\\n';\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nconst int MOD = 998244353;\n\nint main() {\n\t\
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);\n\tint n, m; std::cin >> n\
    \ >> m;\n\tstd::vector<long long> x(n);\n\tfor (int i = 0; i < n; i++) std::cin\
    \ >> x[i];\n\tstd::vector<std::vector<int>> adj(n);\n\tfor (int i = 0; i < m;\
    \ i++) {\n\t\tint u, v; std::cin >> u >> v;\n\t\tadj[u].push_back(v);\n\t\tadj[v].push_back(u);\n\
    \t}\n\tstd::vector<int> vert(n);\n\tstd::vector<bool> good(n);\n\tstd::vector<bool>\
    \ done(n);\n\tiota(vert.begin(), vert.end(), 0);\n\tsort(vert.begin(), vert.end(),\
    \ [&](int i, int j) { return adj[i].size() < adj[j].size(); });\n\tint ans = 0;\n\
    \tfor (int u : vert) {\n\t\tdone[u] = true;\n\t\tfor (int v : adj[u]) good[v]\
    \ = true;\n\t\tfor (int v : adj[u]) {\n\t\t\tif (done[v]) {\n\t\t\t\tfor (int\
    \ w : adj[v]) {\n\t\t\t\t\tif (!good[w]) continue;\n\t\t\t\t\tlong long add =\
    \ (x[u] * x[v]) % MOD;\n\t\t\t\t\tadd = (add * x[w]) % MOD;\n\t\t\t\t\tans +=\
    \ add;\n\t\t\t\t\tif (ans >= MOD) ans -= MOD;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    for (int v: adj[u]) good[v] = false;\n\t}\n\tauto mod_pow = [&](long long base,\
    \ long long exp) -> long long {\n\t\tlong long res = 1;\n\t\twhile (exp) {\n\t\
    \t\tif (exp & 1) {\n\t\t\t\tres *= base;\n\t\t\t\tres %= MOD;\n\t\t\t}\n\t\t\t\
    base *= base;\n\t\t\tbase %= MOD;\n\t\t\texp >>= 1;\n\t\t}\n\t\treturn res;\n\t\
    };\n\tans = (mod_pow(3, MOD - 2) * ans) % MOD;\n\tstd::cout << ans << '\\n';\n\
    \treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/enumerate_triangles.cpp
  requiredBy: []
  timestamp: '2021-07-10 12:34:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/enumerate_triangles.cpp
layout: document
redirect_from:
- /library/library/graphs/enumerate_triangles.cpp
- /library/library/graphs/enumerate_triangles.cpp.html
title: library/graphs/enumerate_triangles.cpp
---