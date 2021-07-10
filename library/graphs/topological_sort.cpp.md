---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/topological_sort.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * If size of std::vector is n, then it is a DAG, if it's not n, then there\
    \ is no topological sorting\n */\n\nstd::vector<int> topo_sort(std::vector<std::vector<int>>\
    \ adj) {\n\tint n = (int)adj.size();\n\tstd::vector<int> in(n);\n\tstd::vector<int>\
    \ res;\n\tstd::list<int> todo;\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int\
    \ j : adj[i]) {\n\t\t\t++in[j];\n\t\t}\n\t}\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tif (!in[i]) {\n\t\t\ttodo.push_back(i);\n\t\t}\n\t}\n\twhile (!todo.empty())\
    \ {\n\t\tint x = todo.front();\n\t\ttodo.pop_front();\n\t\tres.push_back(x);\n\
    \t\tfor (int nxt : adj[x]) {\n\t\t\tif (!(--in[nxt])) {\n\t\t\t\ttodo.push_back(nxt);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n\nint main() {\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * If size of std::vector is n, then it\
    \ is a DAG, if it's not n, then there is no topological sorting\n */\n\nstd::vector<int>\
    \ topo_sort(std::vector<std::vector<int>> adj) {\n\tint n = (int)adj.size();\n\
    \tstd::vector<int> in(n);\n\tstd::vector<int> res;\n\tstd::list<int> todo;\n\t\
    for (int i = 0; i < n; i++) {\n\t\tfor (int j : adj[i]) {\n\t\t\t++in[j];\n\t\t\
    }\n\t}\n\tfor (int i = 0; i < n; i++) {\n\t\tif (!in[i]) {\n\t\t\ttodo.push_back(i);\n\
    \t\t}\n\t}\n\twhile (!todo.empty()) {\n\t\tint x = todo.front();\n\t\ttodo.pop_front();\n\
    \t\tres.push_back(x);\n\t\tfor (int nxt : adj[x]) {\n\t\t\tif (!(--in[nxt])) {\n\
    \t\t\t\ttodo.push_back(nxt);\n\t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n\nint main()\
    \ {\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/topological_sort.cpp
  requiredBy: []
  timestamp: '2021-07-10 12:34:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/topological_sort.cpp
layout: document
redirect_from:
- /library/library/graphs/topological_sort.cpp
- /library/library/graphs/topological_sort.cpp.html
title: library/graphs/topological_sort.cpp
---
