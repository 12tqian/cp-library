---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/topological-sort.cpp
    title: test/topological-sort.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\n/**\n * If size of std::vector is n, then it is a DAG, if it's not\
    \ n, then there is no topological sorting\n */\n\nstd::vector<int> topo_sort(std::vector<std::vector<int>>\
    \ adj) {\n\tint n = (int)adj.size();\n\tstd::vector<int> in(n);\n\tstd::vector<int>\
    \ res;\n\tstd::list<int> todo;\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int\
    \ j : adj[i]) {\n\t\t\t++in[j];\n\t\t}\n\t}\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tif (!in[i]) {\n\t\t\ttodo.push_back(i);\n\t\t}\n\t}\n\twhile (!todo.empty())\
    \ {\n\t\tint x = todo.front();\n\t\ttodo.pop_front();\n\t\tres.push_back(x);\n\
    \t\tfor (int nxt : adj[x]) {\n\t\t\tif (!(--in[nxt])) {\n\t\t\t\ttodo.push_back(nxt);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n\n/**\n * If size of std::vector is n, then it is a DAG, if\
    \ it's not n, then there is no topological sorting\n */\n\nstd::vector<int> topo_sort(std::vector<std::vector<int>>\
    \ adj) {\n\tint n = (int)adj.size();\n\tstd::vector<int> in(n);\n\tstd::vector<int>\
    \ res;\n\tstd::list<int> todo;\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int\
    \ j : adj[i]) {\n\t\t\t++in[j];\n\t\t}\n\t}\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tif (!in[i]) {\n\t\t\ttodo.push_back(i);\n\t\t}\n\t}\n\twhile (!todo.empty())\
    \ {\n\t\tint x = todo.front();\n\t\ttodo.pop_front();\n\t\tres.push_back(x);\n\
    \t\tfor (int nxt : adj[x]) {\n\t\t\tif (!(--in[nxt])) {\n\t\t\t\ttodo.push_back(nxt);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/topological-sort.hpp
  requiredBy:
  - test/topological-sort.cpp
  timestamp: '2021-07-24 22:29:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/topological-sort.hpp
layout: document
redirect_from:
- /library/library/graphs/topological-sort.hpp
- /library/library/graphs/topological-sort.hpp.html
title: library/graphs/topological-sort.hpp
---
