---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\graphs\\\\topological_sort.cpp\"\n#include<bits/stdc++.h>\r\
    \n\r\n// if size of std::vector is n, then it is a DAG\r\n\r\nstd::vector<int>\
    \ topo_sort(std::vector<std::vector<int>> adj) {\r\n    int n = (int) adj.size();\r\
    \n    std::vector<int> in(n);\r\n    std::vector<int> res;\r\n    std::list<int>\
    \ todo;\r\n    for (int i = 0; i < n; i++) {\r\n        for (int j : adj[i]) {\r\
    \n            ++in[j];\r\n        }\r\n    }\r\n    for (int i = 0; i < n; i++)\
    \ {\r\n        if (!in[i]) {\r\n            todo.push_back(i);\r\n        }\r\n\
    \    }\r\n    while (!todo.empty()) {\r\n        int x = todo.front();\r\n   \
    \     todo.pop_front();\r\n        res.push_back(x);\r\n        for (int nxt :\
    \ adj[x]) {\r\n            if (!(--in[nxt])) {\r\n                todo.push_back(nxt);\r\
    \n            }\r\n        }\r\n    }\r\n    return res;\r\n}\r\n\r\nint main()\
    \ {\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\n// if size of std::vector is n, then it is\
    \ a DAG\r\n\r\nstd::vector<int> topo_sort(std::vector<std::vector<int>> adj) {\r\
    \n    int n = (int) adj.size();\r\n    std::vector<int> in(n);\r\n    std::vector<int>\
    \ res;\r\n    std::list<int> todo;\r\n    for (int i = 0; i < n; i++) {\r\n  \
    \      for (int j : adj[i]) {\r\n            ++in[j];\r\n        }\r\n    }\r\n\
    \    for (int i = 0; i < n; i++) {\r\n        if (!in[i]) {\r\n            todo.push_back(i);\r\
    \n        }\r\n    }\r\n    while (!todo.empty()) {\r\n        int x = todo.front();\r\
    \n        todo.pop_front();\r\n        res.push_back(x);\r\n        for (int nxt\
    \ : adj[x]) {\r\n            if (!(--in[nxt])) {\r\n                todo.push_back(nxt);\r\
    \n            }\r\n        }\r\n    }\r\n    return res;\r\n}\r\n\r\nint main()\
    \ {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\graphs\topological_sort.cpp
  requiredBy: []
  timestamp: '2020-11-24 21:15:50-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\graphs\topological_sort.cpp
layout: document
redirect_from:
- /library\library\graphs\topological_sort.cpp
- /library\library\graphs\topological_sort.cpp.html
title: library\graphs\topological_sort.cpp
---
