---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/euler_path.cpp\"\n#include<bits/stdc++.h>\n\
    \ntemplate <bool directed> struct Euler {\n    int n;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> adj;\n    std::vector<std::vector<std::pair<int, int>>::iterator> its;\n\
    \    std::vector<bool> used;\n    void init(int _n) {\n        n = _n;\n     \
    \   adj.resize(n);\n    }\n    void ae(int u, int v) {\n        int m = (int)\
    \ used.size();\n        used.push_back(false);\n        adj[u].emplace_back(v,\
    \ m);\n        if (!directed) {\n            adj[v].emplace_back(u, m);\n    \
    \    }\n    }\n    std::vector<std::pair<int, int>> euler_path() {\n        int\
    \ cnt = 0;\n        int src = -1;\n        for (int i = 0; i < n; i++) {\n   \
    \         int sz = (int) adj[i].size();\n            cnt += sz % 2;\n        \
    \    if (sz == 0) {\n                continue;\n            }\n            if\
    \ (src == -1) {\n                src = i;\n            } else if (src % 2 == 0)\
    \ {\n                src = i;\n            }\n        }\n        if (src == -1)\
    \ {\n            return {};\n        }\n        return get_path(src);\n    }\n\
    \    std::vector<std::pair<int, int>> get_path(int src = 0) {\n        its.resize(n);\n\
    \        std::vector<std::pair<int, int>> ans, s{{src, -1}};\n        for (int\
    \ i = 0; i < n; i++) {\n            its[i] = adj[i].begin();\n        }\n    \
    \    int lst = -1;\n        while ((int) s.size()) {\n            int x = s.back().first;\n\
    \            auto& it = its[x];\n            auto en = adj[x].end();\n       \
    \     while (it != en && used[it->second]) {\n                ++it;\n        \
    \    }\n            if (it == en) {\n                if (lst != -1 && lst != x)\
    \ {\n                    return {};\n                }\n                ans.push_back(s.back());\n\
    \                s.pop_back();\n                if ((int) s.size()) {\n      \
    \              lst = s.back().first;\n                }\n            } else {\n\
    \                s.push_back(*it);\n                used[it->second] = 1;\n  \
    \          }\n        }\n        if ((int) ans.size() != (int) used.size() + 1)\
    \ {\n            return {};\n        }\n        reverse(ans.begin(), ans.end());\n\
    \        return ans;\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <bool directed> struct Euler {\n    int\
    \ n;\n    std::vector<std::vector<std::pair<int, int>>> adj;\n    std::vector<std::vector<std::pair<int,\
    \ int>>::iterator> its;\n    std::vector<bool> used;\n    void init(int _n) {\n\
    \        n = _n;\n        adj.resize(n);\n    }\n    void ae(int u, int v) {\n\
    \        int m = (int) used.size();\n        used.push_back(false);\n        adj[u].emplace_back(v,\
    \ m);\n        if (!directed) {\n            adj[v].emplace_back(u, m);\n    \
    \    }\n    }\n    std::vector<std::pair<int, int>> euler_path() {\n        int\
    \ cnt = 0;\n        int src = -1;\n        for (int i = 0; i < n; i++) {\n   \
    \         int sz = (int) adj[i].size();\n            cnt += sz % 2;\n        \
    \    if (sz == 0) {\n                continue;\n            }\n            if\
    \ (src == -1) {\n                src = i;\n            } else if (src % 2 == 0)\
    \ {\n                src = i;\n            }\n        }\n        if (src == -1)\
    \ {\n            return {};\n        }\n        return get_path(src);\n    }\n\
    \    std::vector<std::pair<int, int>> get_path(int src = 0) {\n        its.resize(n);\n\
    \        std::vector<std::pair<int, int>> ans, s{{src, -1}};\n        for (int\
    \ i = 0; i < n; i++) {\n            its[i] = adj[i].begin();\n        }\n    \
    \    int lst = -1;\n        while ((int) s.size()) {\n            int x = s.back().first;\n\
    \            auto& it = its[x];\n            auto en = adj[x].end();\n       \
    \     while (it != en && used[it->second]) {\n                ++it;\n        \
    \    }\n            if (it == en) {\n                if (lst != -1 && lst != x)\
    \ {\n                    return {};\n                }\n                ans.push_back(s.back());\n\
    \                s.pop_back();\n                if ((int) s.size()) {\n      \
    \              lst = s.back().first;\n                }\n            } else {\n\
    \                s.push_back(*it);\n                used[it->second] = 1;\n  \
    \          }\n        }\n        if ((int) ans.size() != (int) used.size() + 1)\
    \ {\n            return {};\n        }\n        reverse(ans.begin(), ans.end());\n\
    \        return ans;\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/euler_path.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/euler_path.cpp
layout: document
redirect_from:
- /library/library/graphs/euler_path.cpp
- /library/library/graphs/euler_path.cpp.html
title: library/graphs/euler_path.cpp
---
