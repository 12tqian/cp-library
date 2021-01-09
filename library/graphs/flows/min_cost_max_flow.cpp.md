---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/flows/min_cost_max_flow.cpp\"\n#include <bits/stdc++.h>\n\
    /**\n * to get back the original edges, assign ID's in ae\n */\n\ntemplate <class\
    \ F, class C> struct MCMF {\n    struct Edge { int to; F flow, cap; C cost; };\n\
    \n    int n;\n    std::vector<C> p, dist;\n    std::vector<int> pre;\n    std::vector<Edge>\
    \ edges;\n    std::vector<std::vector<int>> adj;\n\n    const C INF  = std::numeric_limits<C>::max();\n\
    \n    void init(int n_) {\n        n = n_;\n        p.assign(n, 0);\n        dist.assign(n,\
    \ 0);\n        pre.assign(n, 0);\n        adj.clear(); adj.resize(n);\n      \
    \  edges.clear();\n    }\n\n    void ae(int u, int v, F cap, C cost) {\n     \
    \   assert(cap >= 0);\n        adj[u].push_back((int) edges.size());\n       \
    \ edges.push_back({v, 0, cap, cost});\n        adj[v].push_back((int) edges.size());\n\
    \        edges.push_back({u, 0, 0, -cost});\n    }\n\n    bool path(int s, int\
    \ t) {\n        for (int i = 0; i < n; i++) \n            dist[i] = INF;\n   \
    \     using T = std::pair<C, int>;\n        std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> todo;\n        todo.push({dist[s] = 0, s});\n        while\
    \ (!todo.empty()) {\n            T x = todo.top();\n            todo.pop();\n\
    \            if (x.first > dist[x.second])\n                continue;\n      \
    \      for (auto& eid : adj[x.second]) {\n                const Edge& e = edges[eid];\n\
    \                if (e.flow < e.cap && dist[e.to] > x.first + e.cost + p[x.second]\
    \ - p[e.to]) {\n                    dist[e.to] = x.first + e.cost + p[x.second]\
    \ - p[e.to];\n                    pre[e.to] = eid;\n                    todo.push({dist[e.to],\
    \ e.to});\n                }\n            }\n        }\n        return dist[t]\
    \ != INF;\n    }\n\n    std::pair<F, C> calc(int s, int t) {\n        assert(s\
    \ != t);\n        for (int unused = 0; unused < n; unused++)\n            for\
    \ (int eid = 0; eid < (int) edges.size(); eid++) {\n                const Edge&\
    \ e = edges[eid];\n                if (e.cap)\n                    p[e.to] = std::min(p[e.to],\
    \ p[edges[eid ^ 1].to] + e.cost);\n            }\n        F total_flow = 0;\n\
    \        C total_cost = 0;\n        while (path(s, t)) {\n            for (int\
    \ i = 0; i < n; i++)\n                p[i] += dist[i];\n            F df = std::numeric_limits<F>::max();\n\
    \            for (int x = t; x != s; x = edges[pre[x] ^ 1].to) {\n           \
    \     const Edge& e = edges[pre[x]];\n                df = std::min(df, e.cap\
    \ - e.flow);\n            }\n            total_flow += df;\n            total_cost\
    \ += (p[t] - p[s]) * df;\n            for (int x = t; x != s; x = edges[pre[x]\
    \ ^ 1].to) \n                edges[pre[x]].flow += df, edges[pre[x] ^ 1].flow\
    \ -= df;\n        }\n        return {total_flow, total_cost};\n    }\n};\n\nint\
    \ main() {\n    using namespace std;\n    int n, m, s, t;\n    cin >> n >> m >>\
    \ s >> t;\n    MCMF<int, int> M;\n    M.init(n);\n    for (int i = 0; i < m; i++)\
    \ {\n        int u, v, c, w;\n        cin >> u >> v >> c >> w;\n        M.ae(u,\
    \ v, c, w);\n    }\n    auto res = M.calc(s, t);\n    cout << res.first << \"\
    \ \" << res.second << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n/**\n * to get back the original edges, assign\
    \ ID's in ae\n */\n\ntemplate <class F, class C> struct MCMF {\n    struct Edge\
    \ { int to; F flow, cap; C cost; };\n\n    int n;\n    std::vector<C> p, dist;\n\
    \    std::vector<int> pre;\n    std::vector<Edge> edges;\n    std::vector<std::vector<int>>\
    \ adj;\n\n    const C INF  = std::numeric_limits<C>::max();\n\n    void init(int\
    \ n_) {\n        n = n_;\n        p.assign(n, 0);\n        dist.assign(n, 0);\n\
    \        pre.assign(n, 0);\n        adj.clear(); adj.resize(n);\n        edges.clear();\n\
    \    }\n\n    void ae(int u, int v, F cap, C cost) {\n        assert(cap >= 0);\n\
    \        adj[u].push_back((int) edges.size());\n        edges.push_back({v, 0,\
    \ cap, cost});\n        adj[v].push_back((int) edges.size());\n        edges.push_back({u,\
    \ 0, 0, -cost});\n    }\n\n    bool path(int s, int t) {\n        for (int i =\
    \ 0; i < n; i++) \n            dist[i] = INF;\n        using T = std::pair<C,\
    \ int>;\n        std::priority_queue<T, std::vector<T>, std::greater<T>> todo;\n\
    \        todo.push({dist[s] = 0, s});\n        while (!todo.empty()) {\n     \
    \       T x = todo.top();\n            todo.pop();\n            if (x.first >\
    \ dist[x.second])\n                continue;\n            for (auto& eid : adj[x.second])\
    \ {\n                const Edge& e = edges[eid];\n                if (e.flow <\
    \ e.cap && dist[e.to] > x.first + e.cost + p[x.second] - p[e.to]) {\n        \
    \            dist[e.to] = x.first + e.cost + p[x.second] - p[e.to];\n        \
    \            pre[e.to] = eid;\n                    todo.push({dist[e.to], e.to});\n\
    \                }\n            }\n        }\n        return dist[t] != INF;\n\
    \    }\n\n    std::pair<F, C> calc(int s, int t) {\n        assert(s != t);\n\
    \        for (int unused = 0; unused < n; unused++)\n            for (int eid\
    \ = 0; eid < (int) edges.size(); eid++) {\n                const Edge& e = edges[eid];\n\
    \                if (e.cap)\n                    p[e.to] = std::min(p[e.to], p[edges[eid\
    \ ^ 1].to] + e.cost);\n            }\n        F total_flow = 0;\n        C total_cost\
    \ = 0;\n        while (path(s, t)) {\n            for (int i = 0; i < n; i++)\n\
    \                p[i] += dist[i];\n            F df = std::numeric_limits<F>::max();\n\
    \            for (int x = t; x != s; x = edges[pre[x] ^ 1].to) {\n           \
    \     const Edge& e = edges[pre[x]];\n                df = std::min(df, e.cap\
    \ - e.flow);\n            }\n            total_flow += df;\n            total_cost\
    \ += (p[t] - p[s]) * df;\n            for (int x = t; x != s; x = edges[pre[x]\
    \ ^ 1].to) \n                edges[pre[x]].flow += df, edges[pre[x] ^ 1].flow\
    \ -= df;\n        }\n        return {total_flow, total_cost};\n    }\n};\n\nint\
    \ main() {\n    using namespace std;\n    int n, m, s, t;\n    cin >> n >> m >>\
    \ s >> t;\n    MCMF<int, int> M;\n    M.init(n);\n    for (int i = 0; i < m; i++)\
    \ {\n        int u, v, c, w;\n        cin >> u >> v >> c >> w;\n        M.ae(u,\
    \ v, c, w);\n    }\n    auto res = M.calc(s, t);\n    cout << res.first << \"\
    \ \" << res.second << '\\n';\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/min_cost_max_flow.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/flows/min_cost_max_flow.cpp
layout: document
redirect_from:
- /library/library/graphs/flows/min_cost_max_flow.cpp
- /library/library/graphs/flows/min_cost_max_flow.cpp.html
title: library/graphs/flows/min_cost_max_flow.cpp
---
