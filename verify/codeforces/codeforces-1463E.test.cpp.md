---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/dsu.hpp
    title: library/graphs/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/topological-sort.hpp
    title: Topological Sort
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/1463/problem/E
    links:
    - https://codeforces.com/contest/1463/problem/E
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1463/problem/E\"\r\
    \n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nstruct DSU {\r\n\tstd::vector<int>\
    \ e;\r\n\r\n\tvoid init(int n) {\r\n\t\te = std::vector<int>(n, -1);\r\n\t}\r\n\
    \r\n\tint get(int x) {\r\n\t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\r\n\t}\r\
    \n\r\n\tbool same_set(int a, int b) {\r\n\t\treturn get(a) == get(b);\r\n\t}\r\
    \n\r\n\tint size(int x) {\r\n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tbool unite(int\
    \ x, int y) {\r\n\t\tx = get(x), y = get(y);\r\n\t\tif (x == y) return false;\r\
    \n\t\tif (e[x] > e[y]) std::swap(x, y);\r\n\t\te[x] += e[y]; e[y] = x;\r\n\t\t\
    return true;\r\n\t}\r\n};\r\n\r\n\r\nstd::vector<int> topo_sort(std::vector<std::vector<int>>\
    \ adj) {\r\n\tint n = (int)adj.size();\r\n\tstd::vector<int> in(n);\r\n\tstd::vector<int>\
    \ res;\r\n\tstd::list<int> todo;\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tfor\
    \ (int j : adj[i]) {\r\n\t\t\t++in[j];\r\n\t\t}\r\n\t}\r\n\tfor (int i = 0; i\
    \ < n; i++) {\r\n\t\tif (!in[i]) {\r\n\t\t\ttodo.push_back(i);\r\n\t\t}\r\n\t\
    }\r\n\twhile (!todo.empty()) {\r\n\t\tint x = todo.front();\r\n\t\ttodo.pop_front();\r\
    \n\t\tres.push_back(x);\r\n\t\tfor (int nxt : adj[x]) {\r\n\t\t\tif (!(--in[nxt]))\
    \ {\r\n\t\t\t\ttodo.push_back(nxt);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn res;\r\
    \n}\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, k;\r\n\tcin >> n >> k;\r\n\tvector<pair<int, int>> ed, con;\r\n\tDSU\
    \ dsu;\r\n\tdsu.init(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tint p;\r\n\t\
    \tcin >> p;\r\n\t\t--p;\r\n\t\tif (p != -1) {\r\n\t\t\ted.emplace_back(p, i);\r\
    \n\t\t}\r\n\t}\r\n\tvector<int> go(n, -1);\r\n\tfor (int i = 0; i < k; ++i) {\r\
    \n\t\tint x, y;\r\n\t\tcin >> x >> y;\r\n\t\t--x, --y;\r\n\t\tcon.emplace_back(x,\
    \ y);\r\n\t\tgo[x] = y;\r\n\t\tdsu.unite(x, y);\r\n\t}\r\n\tvector<vector<int>>\
    \ comps(n), ord(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tcomps[dsu.get(i)].push_back(i);\r\
    \n\t}\r\n\tmap<int, int> conv;\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tif (comps[i].empty())\
    \ {\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tint sz = comps[i].size();\r\n\t\tconv.clear();\r\
    \n\t\tvector<vector<int>> g(sz);\r\n\t\tfor (int j = 0; j < sz; ++j) {\r\n\t\t\
    \tconv[comps[i][j]] = j;\r\n\t\t}\r\n\t\tfor (int x : comps[i]) {\r\n\t\t\tif\
    \ (go[x] == -1) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tif (conv.find(go[x])\
    \ == conv.end()) {\r\n\t\t\t\tcout << -1 << '\\n';\r\n\t\t\t\treturn 0;\r\n\t\t\
    \t}\r\n\t\t\tg[conv[x]].push_back(conv[go[x]]);\r\n\t\t}\r\n\t\tauto res = topo_sort(g);\r\
    \n\t\tif (res.size() != sz) {\r\n\t\t\tcout << 0 << '\\n';\r\n\t\t\treturn 0;\r\
    \n\t\t}\r\n\t\tfor (int x : res) {\r\n\t\t\tord[i].push_back(comps[i][x]);\r\n\
    \t\t}\r\n\t}\r\n\tvector<vector<int>> g(n);\r\n\tfor (auto [u, v] : ed) {\r\n\t\
    \tu = dsu.get(u);\r\n\t\tv = dsu.get(v);\r\n\t\tif (u != v) {\r\n\t\t\tg[u].push_back(v);\r\
    \n\t\t}\r\n\t}\r\n\tauto res = topo_sort(g);\r\n\tif (res.size() < n) {\r\n\t\t\
    cout << 0 << '\\n';\r\n\t\treturn 0;\r\n\t}\r\n\tvector<int> ans;\r\n\tfor (int\
    \ x : res) {\r\n\t\tfor (int y : ord[x]) {\r\n\t\t\tans.push_back(y);\r\n\t\t\
    }\r\n\t}\r\n\tvector<int> rev(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\trev[ans[i]]\
    \ = i;\r\n\t}\r\n\tfor (auto [u, v] : ed) {\r\n\t\tif (rev[u] > rev[v]) {\r\n\t\
    \t\tcout << 0 << '\\n';\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n\tfor (int i = 0;\
    \ i < n; ++i) {\r\n\t\tcout << ans[i] + 1 << ' ';\r\n\t}\r\n\tcout << '\\n';\r\
    \n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1463/problem/E\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/dsu.hpp\"\
    \r\n#include \"../../library/graphs/topological-sort.hpp\"\r\n\r\nint main() {\r\
    \n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n, k;\r\n\tcin\
    \ >> n >> k;\r\n\tvector<pair<int, int>> ed, con;\r\n\tDSU dsu;\r\n\tdsu.init(n);\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tint p;\r\n\t\tcin >> p;\r\n\t\t--p;\r\
    \n\t\tif (p != -1) {\r\n\t\t\ted.emplace_back(p, i);\r\n\t\t}\r\n\t}\r\n\tvector<int>\
    \ go(n, -1);\r\n\tfor (int i = 0; i < k; ++i) {\r\n\t\tint x, y;\r\n\t\tcin >>\
    \ x >> y;\r\n\t\t--x, --y;\r\n\t\tcon.emplace_back(x, y);\r\n\t\tgo[x] = y;\r\n\
    \t\tdsu.unite(x, y);\r\n\t}\r\n\tvector<vector<int>> comps(n), ord(n);\r\n\tfor\
    \ (int i = 0; i < n; ++i) {\r\n\t\tcomps[dsu.get(i)].push_back(i);\r\n\t}\r\n\t\
    map<int, int> conv;\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tif (comps[i].empty())\
    \ {\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tint sz = comps[i].size();\r\n\t\tconv.clear();\r\
    \n\t\tvector<vector<int>> g(sz);\r\n\t\tfor (int j = 0; j < sz; ++j) {\r\n\t\t\
    \tconv[comps[i][j]] = j;\r\n\t\t}\r\n\t\tfor (int x : comps[i]) {\r\n\t\t\tif\
    \ (go[x] == -1) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tif (conv.find(go[x])\
    \ == conv.end()) {\r\n\t\t\t\tcout << -1 << '\\n';\r\n\t\t\t\treturn 0;\r\n\t\t\
    \t}\r\n\t\t\tg[conv[x]].push_back(conv[go[x]]);\r\n\t\t}\r\n\t\tauto res = topo_sort(g);\r\
    \n\t\tif (res.size() != sz) {\r\n\t\t\tcout << 0 << '\\n';\r\n\t\t\treturn 0;\r\
    \n\t\t}\r\n\t\tfor (int x : res) {\r\n\t\t\tord[i].push_back(comps[i][x]);\r\n\
    \t\t}\r\n\t}\r\n\tvector<vector<int>> g(n);\r\n\tfor (auto [u, v] : ed) {\r\n\t\
    \tu = dsu.get(u);\r\n\t\tv = dsu.get(v);\r\n\t\tif (u != v) {\r\n\t\t\tg[u].push_back(v);\r\
    \n\t\t}\r\n\t}\r\n\tauto res = topo_sort(g);\r\n\tif (res.size() < n) {\r\n\t\t\
    cout << 0 << '\\n';\r\n\t\treturn 0;\r\n\t}\r\n\tvector<int> ans;\r\n\tfor (int\
    \ x : res) {\r\n\t\tfor (int y : ord[x]) {\r\n\t\t\tans.push_back(y);\r\n\t\t\
    }\r\n\t}\r\n\tvector<int> rev(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\trev[ans[i]]\
    \ = i;\r\n\t}\r\n\tfor (auto [u, v] : ed) {\r\n\t\tif (rev[u] > rev[v]) {\r\n\t\
    \t\tcout << 0 << '\\n';\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n\tfor (int i = 0;\
    \ i < n; ++i) {\r\n\t\tcout << ans[i] + 1 << ' ';\r\n\t}\r\n\tcout << '\\n';\r\
    \n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/dsu.hpp
  - library/graphs/topological-sort.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1463E.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1463E.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1463E.test.cpp
- /verify/verify/codeforces/codeforces-1463E.test.cpp.html
title: verify/codeforces/codeforces-1463E.test.cpp
---
