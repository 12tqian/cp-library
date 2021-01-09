---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/bellman_ford.cpp\"\n#include <bits/stdc++.h>\n\
    /**\n* dist is INF if you can't reach and -INF if it is in a negative cycle\n\
    * negative cycle is same thing as gen, it just doesn't do gen_bad\n* also it returns\
    \ a negative cycle :D\n*/\n\ntemplate <class T> struct BellmanFord {\n    const\
    \ T INF = std::numeric_limits<T>::max();\n    int n; \n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<std::pair<std::pair<int, int>, T>> edges;\n    std::vector<T>\
    \ dist;\n\n    void init(int n_) {\n        n = n_;\n        adj.assign(n, std::vector<int>());\n\
    \        edges.clear();\n        dist.assign(n, 0);\n    }\n\n    void ae(int\
    \ u, int v, T w) {\n        adj[u].push_back(v);\n        edges.push_back({{u,\
    \ v}, w});\n    }   \n\n    void gen_bad(int x) {\n        if (dist[x] == -INF)\n\
    \            return;\n        dist[x] = -INF;\n        for (auto& nxt : adj[x])\n\
    \            gen_bad(nxt);\n    }\n\n    void gen(int src) {\n        for (int\
    \ i = 0; i < n; i++) \n            dist[i] = INF;\n        dist[src] = 0;\n  \
    \      for (int i = 0; i < n; i++)\n            for (auto& e : edges) \n     \
    \           if (dist[e.first.first] < INF)\n                    dist[e.first.second]\
    \ = std::min(dist[e.first.second], dist[e.first.first] + e.second);\n        for\
    \ (auto& e : edges) \n            if (dist[e.first.first] < INF && dist[e.first.second]\
    \ > dist[e.first.first] + e.second)\n            gen_bad(e.first.second);\n  \
    \  }\n    \n    std::vector<int> negative_cycle(int src = 0) {\n        for (int\
    \ i = 0; i < n; i++)\n            dist[src] = INF;\n        dist[src] = 0;\n \
    \       std::vector<int> pre(n);\n        for (auto& e : edges) \n           \
    \ if (e.first.first == e.first.second && e.second < 0) \n                return\
    \ {e.first.first};\n        for (int i = 0; i < n; i++) \n            for (auto&\
    \ e : edges) \n                if (dist[e.first.first] < INF)\n              \
    \      if (dist[e.first.second] > dist[e.first.first] + e.second) {\n        \
    \                dist[e.first.second] = dist[e.first.first] + e.second;\n    \
    \                    pre[e.first.second] = e.first.first;\n                  \
    \  }\n        for (auto& e : edges) \n            if (dist[e.first.first] < INF)\n\
    \                if (dist[e.first.second] > dist[e.first.first] + e.second) {\n\
    \                    int x = e.first.second;\n                    for (int i =\
    \ 0; i < n; i++)\n                        x = pre[x];\n                    std::vector<int>\
    \ cycle;\n                    for (int v = x; v != x || cycle.empty(); v = pre[v])\n\
    \                        cycle.push_back(v);\n                    reverse(cycle.begin(),\
    \ cycle.end());\n                    return cycle;\n                }\n      \
    \  return {};\n    }\n};\n\nint main() {\n    using namespace std;\n    while\
    \ (true) {\n        int n, m, q, s; cin >> n >> m >> q >> s;\n        if (n ==\
    \ 0)\n            exit(0);\n        BellmanFord<long long> B;\n        B.init(n);\n\
    \        for (int i = 0; i < m; i++) {\n            int u, v, w; cin >> u >> v\
    \ >> w;\n            B.ae(u, v, w);\n        }\n        B.gen(s);\n        while\
    \ (q--) {\n            int x; cin >> x;\n            long long dist = B.dist[x];\n\
    \            if (dist == B.INF) \n                cout << \"Impossible\\n\";\n\
    \            else if (dist == -B.INF)\n                cout << \"-Infinity\\n\"\
    ;\n            else \n                cout << B.dist[x] << '\\n';\n        }\n\
    \    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n/**\n* dist is INF if you can't reach and -INF\
    \ if it is in a negative cycle\n* negative cycle is same thing as gen, it just\
    \ doesn't do gen_bad\n* also it returns a negative cycle :D\n*/\n\ntemplate <class\
    \ T> struct BellmanFord {\n    const T INF = std::numeric_limits<T>::max();\n\
    \    int n; \n    std::vector<std::vector<int>> adj;\n    std::vector<std::pair<std::pair<int,\
    \ int>, T>> edges;\n    std::vector<T> dist;\n\n    void init(int n_) {\n    \
    \    n = n_;\n        adj.assign(n, std::vector<int>());\n        edges.clear();\n\
    \        dist.assign(n, 0);\n    }\n\n    void ae(int u, int v, T w) {\n     \
    \   adj[u].push_back(v);\n        edges.push_back({{u, v}, w});\n    }   \n\n\
    \    void gen_bad(int x) {\n        if (dist[x] == -INF)\n            return;\n\
    \        dist[x] = -INF;\n        for (auto& nxt : adj[x])\n            gen_bad(nxt);\n\
    \    }\n\n    void gen(int src) {\n        for (int i = 0; i < n; i++) \n    \
    \        dist[i] = INF;\n        dist[src] = 0;\n        for (int i = 0; i < n;\
    \ i++)\n            for (auto& e : edges) \n                if (dist[e.first.first]\
    \ < INF)\n                    dist[e.first.second] = std::min(dist[e.first.second],\
    \ dist[e.first.first] + e.second);\n        for (auto& e : edges) \n         \
    \   if (dist[e.first.first] < INF && dist[e.first.second] > dist[e.first.first]\
    \ + e.second)\n            gen_bad(e.first.second);\n    }\n    \n    std::vector<int>\
    \ negative_cycle(int src = 0) {\n        for (int i = 0; i < n; i++)\n       \
    \     dist[src] = INF;\n        dist[src] = 0;\n        std::vector<int> pre(n);\n\
    \        for (auto& e : edges) \n            if (e.first.first == e.first.second\
    \ && e.second < 0) \n                return {e.first.first};\n        for (int\
    \ i = 0; i < n; i++) \n            for (auto& e : edges) \n                if\
    \ (dist[e.first.first] < INF)\n                    if (dist[e.first.second] >\
    \ dist[e.first.first] + e.second) {\n                        dist[e.first.second]\
    \ = dist[e.first.first] + e.second;\n                        pre[e.first.second]\
    \ = e.first.first;\n                    }\n        for (auto& e : edges) \n  \
    \          if (dist[e.first.first] < INF)\n                if (dist[e.first.second]\
    \ > dist[e.first.first] + e.second) {\n                    int x = e.first.second;\n\
    \                    for (int i = 0; i < n; i++)\n                        x =\
    \ pre[x];\n                    std::vector<int> cycle;\n                    for\
    \ (int v = x; v != x || cycle.empty(); v = pre[v])\n                        cycle.push_back(v);\n\
    \                    reverse(cycle.begin(), cycle.end());\n                  \
    \  return cycle;\n                }\n        return {};\n    }\n};\n\nint main()\
    \ {\n    using namespace std;\n    while (true) {\n        int n, m, q, s; cin\
    \ >> n >> m >> q >> s;\n        if (n == 0)\n            exit(0);\n        BellmanFord<long\
    \ long> B;\n        B.init(n);\n        for (int i = 0; i < m; i++) {\n      \
    \      int u, v, w; cin >> u >> v >> w;\n            B.ae(u, v, w);\n        }\n\
    \        B.gen(s);\n        while (q--) {\n            int x; cin >> x;\n    \
    \        long long dist = B.dist[x];\n            if (dist == B.INF) \n      \
    \          cout << \"Impossible\\n\";\n            else if (dist == -B.INF)\n\
    \                cout << \"-Infinity\\n\";\n            else \n              \
    \  cout << B.dist[x] << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/bellman_ford.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/bellman_ford.cpp
layout: document
redirect_from:
- /library/library/graphs/bellman_ford.cpp
- /library/library/graphs/bellman_ford.cpp.html
title: library/graphs/bellman_ford.cpp
---
