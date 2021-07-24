---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "library/graphs/euler_path.cpp"

    '
  code: "#include <bits/stdc++.h>\n\n/**\n * Finds Euler path in O(N + M) from a starting\
    \ vertex\n * To find which vertex to start, use parities\n */\n\ntemplate <bool\
    \ directed> struct Euler {\n\tint n;\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> adj;\n\tstd::vector<std::vector<std::pair<int, int>>::iterator> its;\n\
    \tstd::vector<bool> used;\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tadj.resize(n);\n\
    \t}\n\n\tvoid ae(int u, int v) {\n\t\tint m = (int)used.size();\n\t\tused.push_back(false);\n\
    \t\tadj[u].emplace_back(v, m);\n\t\tif (!directed) {\n\t\t\tadj[v].emplace_back(u,\
    \ m);\n\t\t}\n\t}\n\t\n\tstd::vector<std::pair<int, int>> get_path(int src = 0)\
    \ {\n\t\tits.resize(n);\n\t\tstd::vector<std::pair<int, int>> ans, s{{src, -1}};\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\tits[i] = adj[i].begin();\n\t\t}\n\t\t\
    int lst = -1;\n\t\twhile ((int)s.size()) {\n\t\t\tint x = s.back().first;\n\t\t\
    \tauto &it = its[x];\n\t\t\tauto en = adj[x].end();\n\t\t\twhile (it != en &&\
    \ used[it->second]) {\n\t\t\t\t++it;\n\t\t\t}\n\t\t\tif (it == en) {\n\t\t\t\t\
    if (lst != -1 && lst != x) {\n\t\t\t\t\treturn {};\n\t\t\t\t}\n\t\t\t\tans.push_back(s.back());\n\
    \t\t\t\ts.pop_back();\n\t\t\t\tif ((int)s.size()) {\n\t\t\t\t\tlst = s.back().first;\n\
    \t\t\t\t}\n\t\t\t} else {\n\t\t\t\ts.push_back(*it);\n\t\t\t\tused[it->second]\
    \ = 1;\n\t\t\t}\n\t\t}\n\t\tif ((int)ans.size() != (int)used.size() + 1) {\n\t\
    \t\treturn {};\n\t\t}\n\t\treverse(ans.begin(), ans.end());\n\t\treturn ans;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/euler_path.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/euler_path.cpp
layout: document
redirect_from:
- /library/library/graphs/euler_path.cpp
- /library/library/graphs/euler_path.cpp.html
title: library/graphs/euler_path.cpp
---
