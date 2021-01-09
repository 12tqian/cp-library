---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/flows/push_relabel.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * Treat this as a black box xD\n * Calculates max flow\n * You can probably\
    \ add stuff to recover it\n * Most cases, Dinic is better since you understand\
    \ it\n */\n\ntemplate <class F> struct PushRelabel {\n\n    struct Edge { int\
    \ to, rev; F flow; };\n\n    const F INF = std::numeric_limits<F>::max();  \n\n\
    \    int n, s, t, highest, work;\n    std::vector<std::vector<Edge>> adj;\n  \
    \  std::vector<std::vector<int>> lst, gap;\n    std::vector<int> height, cnt;\n\
    \    std::vector<F> excess;\n\n    void init(int n_) {\n        n = n_;\n    \
    \    adj.clear(); adj.resize(2 * n);\n        lst.clear(); lst.resize(2 * n);\n\
    \        gap.clear(); gap.resize(2 * n);\n        height.assign(2 * n, 0);\n \
    \       cnt.assign(2 * n, 0);\n        excess.assign(2 * n, 0);\n        work\
    \ = highest = 0;\n        s = 0;\n        t = n - 1;\n    }\n\n    void ae(int\
    \ u, int v, F cap) {\n        assert(cap >= 0);\n        Edge a{v, (int) adj[v].size(),\
    \ cap};\n        Edge b{u, (int) adj[u].size(), 0};\n        adj[u].push_back(a);\n\
    \        adj[v].push_back(b);\n    }\n\n    void update_height(int v, int nh)\
    \ {\n        work++;\n        if (height[v] != n)\n            cnt[height[v]]--;\n\
    \        height[v] = nh;\n        if (nh == n)\n            return;\n        cnt[nh]++;\n\
    \        highest = nh;\n        gap[nh].push_back(v);\n        if (excess[v] >\
    \ 0)\n            lst[nh].push_back(v);\n    }\n\n    void global_relabel() {\n\
    \        work = 0;\n        for (int i = 0; i < n; i++)\n            height[i]\
    \ = n, cnt[i] = 0;\n        for (int i = 0; i < highest; i++) \n            lst[i].clear(),\
    \ gap[i].clear();\n        height[t] = 0;\n        std::queue<int> q({t});\n \
    \       while (!q.empty()) {\n            int v = q.front();\n            q.pop();\n\
    \            for (auto& e : adj[v]) \n                if (height[e.to] == n &&\
    \ adj[e.to][e.rev].flow > 0)\n                    q.push(e.to), update_height(e.to,\
    \ height[v] + 1);\n            highest = height[v];\n        }\n    }\n\n    void\
    \ push(int v, Edge& e) {\n        if (excess[e.to] == 0)\n            lst[height[e.to]].push_back(e.to);\n\
    \        F df = std::min(excess[v], e.flow);\n        e.flow -= df, adj[e.to][e.rev].flow\
    \ += df;\n        excess[v] -= df, excess[e.to] += df;\n    }\n\n    void discharge(int\
    \ v) {\n        int nh = n;\n        for (auto& e : adj[v]) \n            if (e.flow\
    \ > 0)\n                if (height[v] == height[e.to] + 1) {\n               \
    \     push(v, e);\n                    if (excess[v] <= 0)\n                 \
    \       return;\n                } else {\n                    nh = std::min(nh,\
    \ height[e.to] + 1);\n                }\n        if (cnt[height[v]] > 1) \n  \
    \          update_height(v, nh);\n        else {\n            for (int i = height[v];\
    \ i <= highest; i++) {\n                for (auto& j : gap[i])\n             \
    \       update_height(j, n);\n                gap[i].clear();\n            }\n\
    \        }\n    }\n    \n    F max_flow(int s_, int t_) {\n        s = s_, t =\
    \ t_;\n        if (s == t)\n            return -1;\n        for (int i = 0; i\
    \ < n; i++)\n            excess[i] = 0;\n        excess[s] = INF, excess[t] =\
    \ -INF;\n        global_relabel();\n        for (auto& e : adj[s]) \n        \
    \    push(s, e);\n        for (; highest >= 0; highest--)\n            while (!lst[highest].empty())\
    \ {\n                int v = lst[highest].back();\n                lst[highest].pop_back();\n\
    \                discharge(v);\n                if (work > 4 * n)\n          \
    \          global_relabel();\n            }\n        return excess[t] + INF;\n\
    \    }\n};\n\nint main() {\n    using namespace std;\n    ios_base::sync_with_stdio(0);\n\
    \    int n, m;\n    cin >> n >> m;\n    PushRelabel<long long> P;\n    P.init(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u >> v >> w;\n\
    \        u--, v--;\n        P.ae(u, v, w);\n        P.ae(v, u, w);\n    }\n  \
    \  cout << P.max_flow(0, n - 1) << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Treat this as a black box xD\n * Calculates\
    \ max flow\n * You can probably add stuff to recover it\n * Most cases, Dinic\
    \ is better since you understand it\n */\n\ntemplate <class F> struct PushRelabel\
    \ {\n\n    struct Edge { int to, rev; F flow; };\n\n    const F INF = std::numeric_limits<F>::max();\
    \  \n\n    int n, s, t, highest, work;\n    std::vector<std::vector<Edge>> adj;\n\
    \    std::vector<std::vector<int>> lst, gap;\n    std::vector<int> height, cnt;\n\
    \    std::vector<F> excess;\n\n    void init(int n_) {\n        n = n_;\n    \
    \    adj.clear(); adj.resize(2 * n);\n        lst.clear(); lst.resize(2 * n);\n\
    \        gap.clear(); gap.resize(2 * n);\n        height.assign(2 * n, 0);\n \
    \       cnt.assign(2 * n, 0);\n        excess.assign(2 * n, 0);\n        work\
    \ = highest = 0;\n        s = 0;\n        t = n - 1;\n    }\n\n    void ae(int\
    \ u, int v, F cap) {\n        assert(cap >= 0);\n        Edge a{v, (int) adj[v].size(),\
    \ cap};\n        Edge b{u, (int) adj[u].size(), 0};\n        adj[u].push_back(a);\n\
    \        adj[v].push_back(b);\n    }\n\n    void update_height(int v, int nh)\
    \ {\n        work++;\n        if (height[v] != n)\n            cnt[height[v]]--;\n\
    \        height[v] = nh;\n        if (nh == n)\n            return;\n        cnt[nh]++;\n\
    \        highest = nh;\n        gap[nh].push_back(v);\n        if (excess[v] >\
    \ 0)\n            lst[nh].push_back(v);\n    }\n\n    void global_relabel() {\n\
    \        work = 0;\n        for (int i = 0; i < n; i++)\n            height[i]\
    \ = n, cnt[i] = 0;\n        for (int i = 0; i < highest; i++) \n            lst[i].clear(),\
    \ gap[i].clear();\n        height[t] = 0;\n        std::queue<int> q({t});\n \
    \       while (!q.empty()) {\n            int v = q.front();\n            q.pop();\n\
    \            for (auto& e : adj[v]) \n                if (height[e.to] == n &&\
    \ adj[e.to][e.rev].flow > 0)\n                    q.push(e.to), update_height(e.to,\
    \ height[v] + 1);\n            highest = height[v];\n        }\n    }\n\n    void\
    \ push(int v, Edge& e) {\n        if (excess[e.to] == 0)\n            lst[height[e.to]].push_back(e.to);\n\
    \        F df = std::min(excess[v], e.flow);\n        e.flow -= df, adj[e.to][e.rev].flow\
    \ += df;\n        excess[v] -= df, excess[e.to] += df;\n    }\n\n    void discharge(int\
    \ v) {\n        int nh = n;\n        for (auto& e : adj[v]) \n            if (e.flow\
    \ > 0)\n                if (height[v] == height[e.to] + 1) {\n               \
    \     push(v, e);\n                    if (excess[v] <= 0)\n                 \
    \       return;\n                } else {\n                    nh = std::min(nh,\
    \ height[e.to] + 1);\n                }\n        if (cnt[height[v]] > 1) \n  \
    \          update_height(v, nh);\n        else {\n            for (int i = height[v];\
    \ i <= highest; i++) {\n                for (auto& j : gap[i])\n             \
    \       update_height(j, n);\n                gap[i].clear();\n            }\n\
    \        }\n    }\n    \n    F max_flow(int s_, int t_) {\n        s = s_, t =\
    \ t_;\n        if (s == t)\n            return -1;\n        for (int i = 0; i\
    \ < n; i++)\n            excess[i] = 0;\n        excess[s] = INF, excess[t] =\
    \ -INF;\n        global_relabel();\n        for (auto& e : adj[s]) \n        \
    \    push(s, e);\n        for (; highest >= 0; highest--)\n            while (!lst[highest].empty())\
    \ {\n                int v = lst[highest].back();\n                lst[highest].pop_back();\n\
    \                discharge(v);\n                if (work > 4 * n)\n          \
    \          global_relabel();\n            }\n        return excess[t] + INF;\n\
    \    }\n};\n\nint main() {\n    using namespace std;\n    ios_base::sync_with_stdio(0);\n\
    \    int n, m;\n    cin >> n >> m;\n    PushRelabel<long long> P;\n    P.init(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u >> v >> w;\n\
    \        u--, v--;\n        P.ae(u, v, w);\n        P.ae(v, u, w);\n    }\n  \
    \  cout << P.max_flow(0, n - 1) << '\\n';\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/push_relabel.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/flows/push_relabel.cpp
layout: document
redirect_from:
- /library/library/graphs/flows/push_relabel.cpp
- /library/library/graphs/flows/push_relabel.cpp.html
title: library/graphs/flows/push_relabel.cpp
---
