---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/topological_sort.cpp\"\n#include<bits/stdc++.h>\n\
    \n/**\n * If size of std::vector is n, then it is a DAG, if it's not n, then there\
    \ is no topological sorting\n */\n\nstd::vector<int> topo_sort(std::vector<std::vector<int>>\
    \ adj) {\n    int n = (int)adj.size();\n    std::vector<int> in(n);\n    std::vector<int>\
    \ res;\n    std::list<int> todo;\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int j : adj[i]) {\n            ++in[j];\n        }\n    }\n    for (int i =\
    \ 0; i < n; i++) {\n        if (!in[i]) {\n            todo.push_back(i);\n  \
    \      }\n    }\n    while (!todo.empty()) {\n        int x = todo.front();\n\
    \        todo.pop_front();\n        res.push_back(x);\n        for (int nxt :\
    \ adj[x]) {\n            if (!(--in[nxt])) {\n                todo.push_back(nxt);\n\
    \            }\n        }\n    }\n    return res;\n}\n\nint main() {\n    return\
    \ 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\n/**\n * If size of std::vector is n, then it is\
    \ a DAG, if it's not n, then there is no topological sorting\n */\n\nstd::vector<int>\
    \ topo_sort(std::vector<std::vector<int>> adj) {\n    int n = (int)adj.size();\n\
    \    std::vector<int> in(n);\n    std::vector<int> res;\n    std::list<int> todo;\n\
    \    for (int i = 0; i < n; i++) {\n        for (int j : adj[i]) {\n         \
    \   ++in[j];\n        }\n    }\n    for (int i = 0; i < n; i++) {\n        if\
    \ (!in[i]) {\n            todo.push_back(i);\n        }\n    }\n    while (!todo.empty())\
    \ {\n        int x = todo.front();\n        todo.pop_front();\n        res.push_back(x);\n\
    \        for (int nxt : adj[x]) {\n            if (!(--in[nxt])) {\n         \
    \       todo.push_back(nxt);\n            }\n        }\n    }\n    return res;\n\
    }\n\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/topological_sort.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/topological_sort.cpp
layout: document
redirect_from:
- /library/library/graphs/topological_sort.cpp
- /library/library/graphs/topological_sort.cpp.html
title: library/graphs/topological_sort.cpp
---
