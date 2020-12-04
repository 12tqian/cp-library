---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/euler_path.cpp\"\n#include<bits/stdc++.h>\r\
    \n\r\ntemplate <bool directed> struct Euler {\r\n    int n;\r\n    std::vector<std::vector<std::pair<int,\
    \ int>>> adj;\r\n    std::vector<std::vector<std::pair<int, int>>::iterator> its;\r\
    \n    std::vector<bool> used;\r\n    void init(int _n) {\r\n        n = _n;\r\n\
    \        adj.resize(n);\r\n    }\r\n    void ae(int u, int v) {\r\n        int\
    \ m = (int) used.size();\r\n        used.push_back(false);\r\n        adj[u].emplace_back(v,\
    \ m);\r\n        if (!directed) {\r\n            adj[v].emplace_back(u, m);\r\n\
    \        }\r\n    }\r\n    std::vector<std::pair<int, int>> euler_path() {\r\n\
    \        int cnt = 0;\r\n        int src = -1;\r\n        for (int i = 0; i <\
    \ n; i++) {\r\n            int sz = (int) adj[i].size();\r\n            cnt +=\
    \ sz % 2;\r\n            if (sz == 0) {\r\n                continue;\r\n     \
    \       }\r\n            if (src == -1) {\r\n                src = i;\r\n    \
    \        } else if (src % 2 == 0) {\r\n                src = i;\r\n          \
    \  }\r\n        }\r\n        if (src == -1) {\r\n            return {};\r\n  \
    \      }\r\n        return get_path(src);\r\n    }\r\n    std::vector<std::pair<int,\
    \ int>> get_path(int src = 0) {\r\n        its.resize(n);\r\n        std::vector<std::pair<int,\
    \ int>> ans, s{{src, -1}};\r\n        for (int i = 0; i < n; i++) {\r\n      \
    \      its[i] = adj[i].begin();\r\n        }\r\n        int lst = -1;\r\n    \
    \    while ((int) s.size()) {\r\n            int x = s.back().first;\r\n     \
    \       auto& it = its[x];\r\n            auto en = adj[x].end();\r\n        \
    \    while (it != en && used[it->second]) {\r\n                ++it;\r\n     \
    \       }\r\n            if (it == en) {\r\n                if (lst != -1 && lst\
    \ != x) {\r\n                    return {};\r\n                }\r\n         \
    \       ans.push_back(s.back());\r\n                s.pop_back();\r\n        \
    \        if ((int) s.size()) {\r\n                    lst = s.back().first;\r\n\
    \                }\r\n            } else {\r\n                s.push_back(*it);\r\
    \n                used[it->second] = 1;\r\n            }\r\n        }\r\n    \
    \    if ((int) ans.size() != (int) used.size() + 1) {\r\n            return {};\r\
    \n        }\r\n        reverse(ans.begin(), ans.end());\r\n        return ans;\r\
    \n    }\r\n};\r\n\r\nint main() {\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\ntemplate <bool directed> struct Euler {\r\n\
    \    int n;\r\n    std::vector<std::vector<std::pair<int, int>>> adj;\r\n    std::vector<std::vector<std::pair<int,\
    \ int>>::iterator> its;\r\n    std::vector<bool> used;\r\n    void init(int _n)\
    \ {\r\n        n = _n;\r\n        adj.resize(n);\r\n    }\r\n    void ae(int u,\
    \ int v) {\r\n        int m = (int) used.size();\r\n        used.push_back(false);\r\
    \n        adj[u].emplace_back(v, m);\r\n        if (!directed) {\r\n         \
    \   adj[v].emplace_back(u, m);\r\n        }\r\n    }\r\n    std::vector<std::pair<int,\
    \ int>> euler_path() {\r\n        int cnt = 0;\r\n        int src = -1;\r\n  \
    \      for (int i = 0; i < n; i++) {\r\n            int sz = (int) adj[i].size();\r\
    \n            cnt += sz % 2;\r\n            if (sz == 0) {\r\n               \
    \ continue;\r\n            }\r\n            if (src == -1) {\r\n             \
    \   src = i;\r\n            } else if (src % 2 == 0) {\r\n                src\
    \ = i;\r\n            }\r\n        }\r\n        if (src == -1) {\r\n         \
    \   return {};\r\n        }\r\n        return get_path(src);\r\n    }\r\n    std::vector<std::pair<int,\
    \ int>> get_path(int src = 0) {\r\n        its.resize(n);\r\n        std::vector<std::pair<int,\
    \ int>> ans, s{{src, -1}};\r\n        for (int i = 0; i < n; i++) {\r\n      \
    \      its[i] = adj[i].begin();\r\n        }\r\n        int lst = -1;\r\n    \
    \    while ((int) s.size()) {\r\n            int x = s.back().first;\r\n     \
    \       auto& it = its[x];\r\n            auto en = adj[x].end();\r\n        \
    \    while (it != en && used[it->second]) {\r\n                ++it;\r\n     \
    \       }\r\n            if (it == en) {\r\n                if (lst != -1 && lst\
    \ != x) {\r\n                    return {};\r\n                }\r\n         \
    \       ans.push_back(s.back());\r\n                s.pop_back();\r\n        \
    \        if ((int) s.size()) {\r\n                    lst = s.back().first;\r\n\
    \                }\r\n            } else {\r\n                s.push_back(*it);\r\
    \n                used[it->second] = 1;\r\n            }\r\n        }\r\n    \
    \    if ((int) ans.size() != (int) used.size() + 1) {\r\n            return {};\r\
    \n        }\r\n        reverse(ans.begin(), ans.end());\r\n        return ans;\r\
    \n    }\r\n};\r\n\r\nint main() {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/euler_path.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:56:10-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/euler_path.cpp
layout: document
redirect_from:
- /library/library/graphs/euler_path.cpp
- /library/library/graphs/euler_path.cpp.html
title: library/graphs/euler_path.cpp
---
