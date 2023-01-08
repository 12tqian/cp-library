---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/codeforces/codeforces-1463E.test.cpp
    title: verify/codeforces/codeforces-1463E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\nstd::vector<int> topo_sort(std::vector<std::vector<int>> adj)\
    \ {\r\n\tint n = (int)adj.size();\r\n\tstd::vector<int> in(n);\r\n\tstd::vector<int>\
    \ res;\r\n\tstd::list<int> todo;\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tfor\
    \ (int j : adj[i]) {\r\n\t\t\t++in[j];\r\n\t\t}\r\n\t}\r\n\tfor (int i = 0; i\
    \ < n; i++) {\r\n\t\tif (!in[i]) {\r\n\t\t\ttodo.push_back(i);\r\n\t\t}\r\n\t\
    }\r\n\twhile (!todo.empty()) {\r\n\t\tint x = todo.front();\r\n\t\ttodo.pop_front();\r\
    \n\t\tres.push_back(x);\r\n\t\tfor (int nxt : adj[x]) {\r\n\t\t\tif (!(--in[nxt]))\
    \ {\r\n\t\t\t\ttodo.push_back(nxt);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn res;\r\
    \n}\n"
  code: "#pragma once\r\n\r\nstd::vector<int> topo_sort(std::vector<std::vector<int>>\
    \ adj) {\r\n\tint n = (int)adj.size();\r\n\tstd::vector<int> in(n);\r\n\tstd::vector<int>\
    \ res;\r\n\tstd::list<int> todo;\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tfor\
    \ (int j : adj[i]) {\r\n\t\t\t++in[j];\r\n\t\t}\r\n\t}\r\n\tfor (int i = 0; i\
    \ < n; i++) {\r\n\t\tif (!in[i]) {\r\n\t\t\ttodo.push_back(i);\r\n\t\t}\r\n\t\
    }\r\n\twhile (!todo.empty()) {\r\n\t\tint x = todo.front();\r\n\t\ttodo.pop_front();\r\
    \n\t\tres.push_back(x);\r\n\t\tfor (int nxt : adj[x]) {\r\n\t\t\tif (!(--in[nxt]))\
    \ {\r\n\t\t\t\ttodo.push_back(nxt);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn res;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/topological-sort.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/codeforces/codeforces-1463E.test.cpp
documentation_of: library/graphs/topological-sort.hpp
layout: document
title: Topological Sort
---

## Topological Sort

### Functions
- `topo_sort(adj)`: Returns topological ordering given adjacency lists. It will return a list of size less than $n$ if there is no topological ordering. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Basics/TopoSort%20(7.4).h)

