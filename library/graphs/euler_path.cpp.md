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
    \n/**\n * Finds Euler path in O(N + M) from a starting vertex\n * To find which\
    \ vertex to start, use parities\n */\n\ntemplate <bool directed> struct Euler\
    \ {\n    int n;\n    std::vector<std::vector<std::pair<int, int>>> adj;\n    std::vector<std::vector<std::pair<int,\
    \ int>>::iterator> its;\n    std::vector<bool> used;\n\n    void init(int _n)\
    \ {\n        n = _n;\n        adj.resize(n);\n    }\n\n    void ae(int u, int\
    \ v) {\n        int m = (int)used.size();\n        used.push_back(false);\n  \
    \      adj[u].emplace_back(v, m);\n        if (!directed) {\n            adj[v].emplace_back(u,\
    \ m);\n        }\n    }\n    \n    std::vector<std::pair<int, int>> get_path(int\
    \ src = 0) {\n        its.resize(n);\n        std::vector<std::pair<int, int>>\
    \ ans, s{{src, -1}};\n        for (int i = 0; i < n; i++) {\n            its[i]\
    \ = adj[i].begin();\n        }\n        int lst = -1;\n        while ((int)s.size())\
    \ {\n            int x = s.back().first;\n            auto& it = its[x];\n   \
    \         auto en = adj[x].end();\n            while (it != en && used[it->second])\
    \ {\n                ++it;\n            }\n            if (it == en) {\n     \
    \           if (lst != -1 && lst != x) {\n                    return {};\n   \
    \             }\n                ans.push_back(s.back());\n                s.pop_back();\n\
    \                if ((int)s.size()) {\n                    lst = s.back().first;\n\
    \                }\n            } else {\n                s.push_back(*it);\n\
    \                used[it->second] = 1;\n            }\n        }\n        if ((int)ans.size()\
    \ != (int)used.size() + 1) {\n            return {};\n        }\n        reverse(ans.begin(),\
    \ ans.end());\n        return ans;\n    }\n};\n\nint main() {\n    return 0;\n\
    }\n"
  code: "#include<bits/stdc++.h>\n\n/**\n * Finds Euler path in O(N + M) from a starting\
    \ vertex\n * To find which vertex to start, use parities\n */\n\ntemplate <bool\
    \ directed> struct Euler {\n    int n;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> adj;\n    std::vector<std::vector<std::pair<int, int>>::iterator> its;\n\
    \    std::vector<bool> used;\n\n    void init(int _n) {\n        n = _n;\n   \
    \     adj.resize(n);\n    }\n\n    void ae(int u, int v) {\n        int m = (int)used.size();\n\
    \        used.push_back(false);\n        adj[u].emplace_back(v, m);\n        if\
    \ (!directed) {\n            adj[v].emplace_back(u, m);\n        }\n    }\n  \
    \  \n    std::vector<std::pair<int, int>> get_path(int src = 0) {\n        its.resize(n);\n\
    \        std::vector<std::pair<int, int>> ans, s{{src, -1}};\n        for (int\
    \ i = 0; i < n; i++) {\n            its[i] = adj[i].begin();\n        }\n    \
    \    int lst = -1;\n        while ((int)s.size()) {\n            int x = s.back().first;\n\
    \            auto& it = its[x];\n            auto en = adj[x].end();\n       \
    \     while (it != en && used[it->second]) {\n                ++it;\n        \
    \    }\n            if (it == en) {\n                if (lst != -1 && lst != x)\
    \ {\n                    return {};\n                }\n                ans.push_back(s.back());\n\
    \                s.pop_back();\n                if ((int)s.size()) {\n       \
    \             lst = s.back().first;\n                }\n            } else {\n\
    \                s.push_back(*it);\n                used[it->second] = 1;\n  \
    \          }\n        }\n        if ((int)ans.size() != (int)used.size() + 1)\
    \ {\n            return {};\n        }\n        reverse(ans.begin(), ans.end());\n\
    \        return ans;\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/euler_path.cpp
  requiredBy: []
  timestamp: '2021-03-03 13:43:05-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/euler_path.cpp
layout: document
redirect_from:
- /library/library/graphs/euler_path.cpp
- /library/library/graphs/euler_path.cpp.html
title: library/graphs/euler_path.cpp
---
