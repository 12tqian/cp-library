---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/flows/hungarian.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * Another black box algorithm I don't understand\n * But I can use \n\
    \ * O(N^2M) for N jobs and M workers \n * 0-indexed\n * Returns the cost, and\
    \ the assignment\n * job stores the job each worker gets assigned to\n * In the\
    \ example below, they wanted the worker each job got assigned to, so I inverted\
    \ it\n */\n\ntemplate <class C> std::pair<C, std::vector<int>> hungarian(const\
    \ std::vector<std::vector<C>>& a_) {\n    const C INF = std::numeric_limits<C>::max();\n\
    \    int n = (int)a_.size();\n    int m = (int)a_[0].size();\n    assert(n <=\
    \ m);\n    std::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));\n \
    \   for (int i = 0; i < n; i++)\n        for (int j = 0; j < m; j++)\n       \
    \     a[i + 1][j + 1] = a_[i][j];\n    std::vector<C> u(n + 1), v(m + 1);\n  \
    \  std::vector<int> job(m + 1);\n    for (int i = 1; i <= n; i++) {\n        int\
    \ w = 0;\n        job[w] = i;\n        std::vector<C> dist(m + 1, INF);\n    \
    \    std::vector<int> pre(m + 1, -1);\n        std::vector<bool> done(m + 1);\n\
    \        while (job[w]) {\n            done[w] = 1;\n            int j = job[w],\
    \ nxt;\n            C delta = INF;\n            for (int ww = 0; ww <= m; ww++)\
    \ {\n                if (!done[ww]) {\n                    if (dist[ww] > a[j][ww]\
    \ - u[j] - v[ww]) {\n                        dist[ww] = a[j][ww] - u[j] - v[ww];\n\
    \                        pre[ww] = w; \n                    }\n              \
    \      if (delta > dist[ww]) {\n                        delta = dist[ww];\n  \
    \                      nxt = ww;\n                    }\n                }\n \
    \           }\n            for (int ww = 0; ww <= m; ww++) {\n               \
    \ if (done[ww]) {\n                    u[job[ww]] += delta;\n                \
    \    v[ww] -= delta;\n                } else {\n                    dist[ww] -=\
    \ delta;\n                }\n            }\n            w = nxt;\n        }\n\
    \        for (int ww; w; w = ww) \n            job[w] = job[ww = pre[w]];\n  \
    \  }\n    job.erase(job.begin());\n    for (int i = 0; i < m; i++)\n        job[i]--;\n\
    \    return {-v[0], job};\n}\n\nint main() {\n    using namespace std;\n    int\
    \ n; cin >> n;\n    vector<vector<long long>> a(n, vector<long long>(n));\n  \
    \  for (int i = 0; i < n; i++)\n        for (int j = 0; j < n; j++) cin >> a[i][j];\n\
    \    auto res = hungarian(a);\n    vector<int> loc(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        loc[res.second[i]] = i;\n    }\n    cout << res.first <<\
    \ '\\n';\n    for (int x : loc) \n        cout << x << \" \";\n    cout << '\\\
    n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Another black box algorithm I don't understand\n\
    \ * But I can use \n * O(N^2M) for N jobs and M workers \n * 0-indexed\n * Returns\
    \ the cost, and the assignment\n * job stores the job each worker gets assigned\
    \ to\n * In the example below, they wanted the worker each job got assigned to,\
    \ so I inverted it\n */\n\ntemplate <class C> std::pair<C, std::vector<int>> hungarian(const\
    \ std::vector<std::vector<C>>& a_) {\n    const C INF = std::numeric_limits<C>::max();\n\
    \    int n = (int)a_.size();\n    int m = (int)a_[0].size();\n    assert(n <=\
    \ m);\n    std::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));\n \
    \   for (int i = 0; i < n; i++)\n        for (int j = 0; j < m; j++)\n       \
    \     a[i + 1][j + 1] = a_[i][j];\n    std::vector<C> u(n + 1), v(m + 1);\n  \
    \  std::vector<int> job(m + 1);\n    for (int i = 1; i <= n; i++) {\n        int\
    \ w = 0;\n        job[w] = i;\n        std::vector<C> dist(m + 1, INF);\n    \
    \    std::vector<int> pre(m + 1, -1);\n        std::vector<bool> done(m + 1);\n\
    \        while (job[w]) {\n            done[w] = 1;\n            int j = job[w],\
    \ nxt;\n            C delta = INF;\n            for (int ww = 0; ww <= m; ww++)\
    \ {\n                if (!done[ww]) {\n                    if (dist[ww] > a[j][ww]\
    \ - u[j] - v[ww]) {\n                        dist[ww] = a[j][ww] - u[j] - v[ww];\n\
    \                        pre[ww] = w; \n                    }\n              \
    \      if (delta > dist[ww]) {\n                        delta = dist[ww];\n  \
    \                      nxt = ww;\n                    }\n                }\n \
    \           }\n            for (int ww = 0; ww <= m; ww++) {\n               \
    \ if (done[ww]) {\n                    u[job[ww]] += delta;\n                \
    \    v[ww] -= delta;\n                } else {\n                    dist[ww] -=\
    \ delta;\n                }\n            }\n            w = nxt;\n        }\n\
    \        for (int ww; w; w = ww) \n            job[w] = job[ww = pre[w]];\n  \
    \  }\n    job.erase(job.begin());\n    for (int i = 0; i < m; i++)\n        job[i]--;\n\
    \    return {-v[0], job};\n}\n\nint main() {\n    using namespace std;\n    int\
    \ n; cin >> n;\n    vector<vector<long long>> a(n, vector<long long>(n));\n  \
    \  for (int i = 0; i < n; i++)\n        for (int j = 0; j < n; j++) cin >> a[i][j];\n\
    \    auto res = hungarian(a);\n    vector<int> loc(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        loc[res.second[i]] = i;\n    }\n    cout << res.first <<\
    \ '\\n';\n    for (int x : loc) \n        cout << x << \" \";\n    cout << '\\\
    n';\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/hungarian.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/flows/hungarian.cpp
layout: document
redirect_from:
- /library/library/graphs/flows/hungarian.cpp
- /library/library/graphs/flows/hungarian.cpp.html
title: library/graphs/flows/hungarian.cpp
---
