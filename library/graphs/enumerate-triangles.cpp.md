---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-enumerate_triangles.test.cpp
    title: verify/yosupo/yosupo-enumerate_triangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\
    \n#include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nconst int MOD = 998244353;\r\
    \n\r\nint main() {\r\n\tstd::ios_base::sync_with_stdio(0); std::cin.tie(0);\r\n\
    \tint n, m; std::cin >> n >> m;\r\n\tstd::vector<long long> x(n);\r\n\tfor (int\
    \ i = 0; i < n; i++) std::cin >> x[i];\r\n\tstd::vector<std::vector<int>> adj(n);\r\
    \n\tfor (int i = 0; i < m; i++) {\r\n\t\tint u, v; std::cin >> u >> v;\r\n\t\t\
    adj[u].push_back(v);\r\n\t\tadj[v].push_back(u);\r\n\t}\r\n\tstd::vector<int>\
    \ vert(n);\r\n\tstd::vector<bool> good(n);\r\n\tstd::vector<bool> done(n);\r\n\
    \tiota(vert.begin(), vert.end(), 0);\r\n\tsort(vert.begin(), vert.end(), [&](int\
    \ i, int j) { return adj[i].size() < adj[j].size(); });\r\n\tint ans = 0;\r\n\t\
    for (int u : vert) {\r\n\t\tdone[u] = true;\r\n\t\tfor (int v : adj[u]) good[v]\
    \ = true;\r\n\t\tfor (int v : adj[u]) {\r\n\t\t\tif (done[v]) {\r\n\t\t\t\tfor\
    \ (int w : adj[v]) {\r\n\t\t\t\t\tif (!good[w]) continue;\r\n\t\t\t\t\tlong long\
    \ add = (x[u] * x[v]) % MOD;\r\n\t\t\t\t\tadd = (add * x[w]) % MOD;\r\n\t\t\t\t\
    \tans += add;\r\n\t\t\t\t\tif (ans >= MOD) ans -= MOD;\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\tfor (int v: adj[u]) good[v] = false;\r\n\t}\r\n\tauto mod_pow\
    \ = [&](long long base, long long exp) -> long long {\r\n\t\tlong long res = 1;\r\
    \n\t\twhile (exp) {\r\n\t\t\tif (exp & 1) {\r\n\t\t\t\tres *= base;\r\n\t\t\t\t\
    res %= MOD;\r\n\t\t\t}\r\n\t\t\tbase *= base;\r\n\t\t\tbase %= MOD;\r\n\t\t\t\
    exp >>= 1;\r\n\t\t}\r\n\t\treturn res;\r\n\t};\r\n\tans = (mod_pow(3, MOD - 2)\
    \ * ans) % MOD;\r\n\tstd::cout << ans << '\\n';\r\n\treturn 0;\r\n}\r\n"
  code: "#include \"../contest/template-minimal.hpp\"\r\n\r\nconst int MOD = 998244353;\r\
    \n\r\nint main() {\r\n\tstd::ios_base::sync_with_stdio(0); std::cin.tie(0);\r\n\
    \tint n, m; std::cin >> n >> m;\r\n\tstd::vector<long long> x(n);\r\n\tfor (int\
    \ i = 0; i < n; i++) std::cin >> x[i];\r\n\tstd::vector<std::vector<int>> adj(n);\r\
    \n\tfor (int i = 0; i < m; i++) {\r\n\t\tint u, v; std::cin >> u >> v;\r\n\t\t\
    adj[u].push_back(v);\r\n\t\tadj[v].push_back(u);\r\n\t}\r\n\tstd::vector<int>\
    \ vert(n);\r\n\tstd::vector<bool> good(n);\r\n\tstd::vector<bool> done(n);\r\n\
    \tiota(vert.begin(), vert.end(), 0);\r\n\tsort(vert.begin(), vert.end(), [&](int\
    \ i, int j) { return adj[i].size() < adj[j].size(); });\r\n\tint ans = 0;\r\n\t\
    for (int u : vert) {\r\n\t\tdone[u] = true;\r\n\t\tfor (int v : adj[u]) good[v]\
    \ = true;\r\n\t\tfor (int v : adj[u]) {\r\n\t\t\tif (done[v]) {\r\n\t\t\t\tfor\
    \ (int w : adj[v]) {\r\n\t\t\t\t\tif (!good[w]) continue;\r\n\t\t\t\t\tlong long\
    \ add = (x[u] * x[v]) % MOD;\r\n\t\t\t\t\tadd = (add * x[w]) % MOD;\r\n\t\t\t\t\
    \tans += add;\r\n\t\t\t\t\tif (ans >= MOD) ans -= MOD;\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\tfor (int v: adj[u]) good[v] = false;\r\n\t}\r\n\tauto mod_pow\
    \ = [&](long long base, long long exp) -> long long {\r\n\t\tlong long res = 1;\r\
    \n\t\twhile (exp) {\r\n\t\t\tif (exp & 1) {\r\n\t\t\t\tres *= base;\r\n\t\t\t\t\
    res %= MOD;\r\n\t\t\t}\r\n\t\t\tbase *= base;\r\n\t\t\tbase %= MOD;\r\n\t\t\t\
    exp >>= 1;\r\n\t\t}\r\n\t\treturn res;\r\n\t};\r\n\tans = (mod_pow(3, MOD - 2)\
    \ * ans) % MOD;\r\n\tstd::cout << ans << '\\n';\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  isVerificationFile: false
  path: library/graphs/enumerate-triangles.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-enumerate_triangles.test.cpp
documentation_of: library/graphs/enumerate-triangles.cpp
layout: document
redirect_from:
- /library/library/graphs/enumerate-triangles.cpp
- /library/library/graphs/enumerate-triangles.cpp.html
title: library/graphs/enumerate-triangles.cpp
---
