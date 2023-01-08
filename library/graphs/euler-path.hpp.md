---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/codeforces/codeforces-1494F.test.cpp
    title: verify/codeforces/codeforces-1494F.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <bool directed> struct Euler {\r\n\tint n;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> adj;\r\n\tstd::vector<std::vector<std::pair<int, int>>::iterator> its;\r\
    \n\tstd::vector<bool> used;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\t\
    adj.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tint m = (int)used.size();\r\
    \n\t\tused.push_back(false);\r\n\t\tadj[u].emplace_back(v, m);\r\n\t\tif (!directed)\
    \ {\r\n\t\t\tadj[v].emplace_back(u, m);\r\n\t\t}\r\n\t}\r\n\r\n\tstd::vector<std::pair<int,\
    \ int>> euler_path() {\r\n\t\tint cnt = 0;\r\n\t\tfor (int i = 0; i < n; i++)\
    \ \r\n\t\t\tcnt += (int)adj[i].size() % 2;\r\n\t\tif (cnt == 2) {\r\n\t\t\tfor\
    \ (int i = 0; i < n; i++) \r\n\t\t\t\tif ((int)adj[i].size() % 2) \r\n\t\t\t\t\
    \treturn get_path(i);\r\n\t\t} else if (cnt == 0) {\r\n\t\t\treturn get_path(0);\r\
    \n\t\t}\r\n\t\treturn {};\r\n\t}\r\n\t\r\n\tstd::vector<std::pair<int, int>> get_path(int\
    \ src = 0) {\r\n\t\tits.resize(n);\r\n\t\tstd::vector<std::pair<int, int>> ans,\
    \ s{{src, -1}};\r\n\t\tfor (int i = 0; i < n; i++) {\r\n\t\t\tits[i] = adj[i].begin();\r\
    \n\t\t}\r\n\t\tint lst = -1;\r\n\t\twhile ((int)s.size()) {\r\n\t\t\tint x = s.back().first;\r\
    \n\t\t\tauto& it = its[x];\r\n\t\t\tauto en = adj[x].end();\r\n\t\t\twhile (it\
    \ != en && used[it->second]) {\r\n\t\t\t\t++it;\r\n\t\t\t}\r\n\t\t\tif (it ==\
    \ en) {\r\n\t\t\t\tif (lst != -1 && lst != x) {\r\n\t\t\t\t\treturn {};\r\n\t\t\
    \t\t}\r\n\t\t\t\tans.push_back(s.back());\r\n\t\t\t\ts.pop_back();\r\n\t\t\t\t\
    if ((int)s.size()) {\r\n\t\t\t\t\tlst = s.back().first;\r\n\t\t\t\t}\r\n\t\t\t\
    } else {\r\n\t\t\t\ts.push_back(*it);\r\n\t\t\t\tused[it->second] = 1;\r\n\t\t\
    \t}\r\n\t\t}\r\n\t\tif ((int)ans.size() != (int)used.size() + 1) {\r\n\t\t\treturn\
    \ {};\r\n\t\t}\r\n\t\treverse(ans.begin(), ans.end());\r\n\t\treturn ans;\r\n\t\
    }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <bool directed> struct Euler {\r\n\tint n;\r\
    \n\tstd::vector<std::vector<std::pair<int, int>>> adj;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>::iterator> its;\r\n\tstd::vector<bool> used;\r\n\r\n\tvoid init(int _n)\
    \ {\r\n\t\tn = _n;\r\n\t\tadj.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int u, int v)\
    \ {\r\n\t\tint m = (int)used.size();\r\n\t\tused.push_back(false);\r\n\t\tadj[u].emplace_back(v,\
    \ m);\r\n\t\tif (!directed) {\r\n\t\t\tadj[v].emplace_back(u, m);\r\n\t\t}\r\n\
    \t}\r\n\r\n\tstd::vector<std::pair<int, int>> euler_path() {\r\n\t\tint cnt =\
    \ 0;\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tcnt += (int)adj[i].size() %\
    \ 2;\r\n\t\tif (cnt == 2) {\r\n\t\t\tfor (int i = 0; i < n; i++) \r\n\t\t\t\t\
    if ((int)adj[i].size() % 2) \r\n\t\t\t\t\treturn get_path(i);\r\n\t\t} else if\
    \ (cnt == 0) {\r\n\t\t\treturn get_path(0);\r\n\t\t}\r\n\t\treturn {};\r\n\t}\r\
    \n\t\r\n\tstd::vector<std::pair<int, int>> get_path(int src = 0) {\r\n\t\tits.resize(n);\r\
    \n\t\tstd::vector<std::pair<int, int>> ans, s{{src, -1}};\r\n\t\tfor (int i =\
    \ 0; i < n; i++) {\r\n\t\t\tits[i] = adj[i].begin();\r\n\t\t}\r\n\t\tint lst =\
    \ -1;\r\n\t\twhile ((int)s.size()) {\r\n\t\t\tint x = s.back().first;\r\n\t\t\t\
    auto& it = its[x];\r\n\t\t\tauto en = adj[x].end();\r\n\t\t\twhile (it != en &&\
    \ used[it->second]) {\r\n\t\t\t\t++it;\r\n\t\t\t}\r\n\t\t\tif (it == en) {\r\n\
    \t\t\t\tif (lst != -1 && lst != x) {\r\n\t\t\t\t\treturn {};\r\n\t\t\t\t}\r\n\t\
    \t\t\tans.push_back(s.back());\r\n\t\t\t\ts.pop_back();\r\n\t\t\t\tif ((int)s.size())\
    \ {\r\n\t\t\t\t\tlst = s.back().first;\r\n\t\t\t\t}\r\n\t\t\t} else {\r\n\t\t\t\
    \ts.push_back(*it);\r\n\t\t\t\tused[it->second] = 1;\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tif ((int)ans.size() != (int)used.size() + 1) {\r\n\t\t\treturn {};\r\n\t\t}\r\
    \n\t\treverse(ans.begin(), ans.end());\r\n\t\treturn ans;\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/euler-path.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/codeforces/codeforces-1494F.test.cpp
documentation_of: library/graphs/euler-path.hpp
layout: document
title: Euler Path
---

## Euler Path 

### Functions
- `get_path`: Finds an Euler path in $\mathcal O(N + M)$ starting from $src$ if it exists. Returns empty list if there is none, otherwise returns a list of edges. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/DFS/EulerPath%20(12.2).h)

