---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/graphs/topological-sort.hpp
    title: library/graphs/topological-sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.spoj.com/problems/TOPOSORT/
    links:
    - https://www.spoj.com/problems/TOPOSORT/
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/TOPOSORT/\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n/**\n * If size of std::vector is n, then it is a DAG, if it's not n, then there\
    \ is no topological sorting\n */\n\nstd::vector<int> topo_sort(std::vector<std::vector<int>>\
    \ adj) {\n\tint n = (int)adj.size();\n\tstd::vector<int> in(n);\n\tstd::vector<int>\
    \ res;\n\tstd::list<int> todo;\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int\
    \ j : adj[i]) {\n\t\t\t++in[j];\n\t\t}\n\t}\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tif (!in[i]) {\n\t\t\ttodo.push_back(i);\n\t\t}\n\t}\n\twhile (!todo.empty())\
    \ {\n\t\tint x = todo.front();\n\t\ttodo.pop_front();\n\t\tres.push_back(x);\n\
    \t\tfor (int nxt : adj[x]) {\n\t\t\tif (!(--in[nxt])) {\n\t\t\t\ttodo.push_back(nxt);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>> g(n);\n\
    \tfor (int i = 0; i < m; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t--u, --v;\n\
    \t\tg[u].push_back(v);\n\t}\n\tauto res = topo_sort(g);\n\tif (res.empty()) {\n\
    \t\tcout << \"Sandro fails.\" << '\\n';\n\t} else {\n\t\tfor (int x : res) {\n\
    \t\t\tcout << x + 1 << ' ';\n\t\t}\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/TOPOSORT/\"\n\n#include \"\
    ../library/contest/template-minimal.hpp\"\n#include \"../library/graphs/topological-sort.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n,\
    \ m;\n\tcin >> n >> m;\n\tvector<vector<int>> g(n);\n\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t--u, --v;\n\t\tg[u].push_back(v);\n\
    \t}\n\tauto res = topo_sort(g);\n\tif (res.empty()) {\n\t\tcout << \"Sandro fails.\"\
    \ << '\\n';\n\t} else {\n\t\tfor (int x : res) {\n\t\t\tcout << x + 1 << ' ';\n\
    \t\t}\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/topological-sort.hpp
  isVerificationFile: true
  path: test/topological-sort.test.cpp
  requiredBy: []
  timestamp: '2021-07-26 20:50:03-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/topological-sort.test.cpp
layout: document
redirect_from:
- /verify/test/topological-sort.test.cpp
- /verify/test/topological-sort.test.cpp.html
title: test/topological-sort.test.cpp
---
