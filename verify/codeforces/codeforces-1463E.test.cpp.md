---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/graphs/dsu.hpp
    title: library/graphs/dsu.hpp
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
    PROBLEM: https://codeforces.com/contest/1463/problem/E
    links:
    - https://codeforces.com/contest/1463/problem/E
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1463/problem/E\"\n\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nstruct DSU {\n\tstd::vector<int> e;\n\n\tvoid init(int n) {\n\t\te = std::vector<int>(n,\
    \ -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\n\
    \t}\n\n\tbool same_set(int a, int b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\t\
    int size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tbool unite(int x, int y) {\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ std::swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\n\t\treturn true;\n\t}\n};\n\n\
    \n/**\n * If size of std::vector is n, then it is a DAG, if it's not n, then there\
    \ is no topological sorting\n */\n\nstd::vector<int> topo_sort(std::vector<std::vector<int>>\
    \ adj) {\n\tint n = (int)adj.size();\n\tstd::vector<int> in(n);\n\tstd::vector<int>\
    \ res;\n\tstd::list<int> todo;\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int\
    \ j : adj[i]) {\n\t\t\t++in[j];\n\t\t}\n\t}\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tif (!in[i]) {\n\t\t\ttodo.push_back(i);\n\t\t}\n\t}\n\twhile (!todo.empty())\
    \ {\n\t\tint x = todo.front();\n\t\ttodo.pop_front();\n\t\tres.push_back(x);\n\
    \t\tfor (int nxt : adj[x]) {\n\t\t\tif (!(--in[nxt])) {\n\t\t\t\ttodo.push_back(nxt);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, k;\n\tcin >> n >> k;\n\tvector<pair<int, int>> ed,\
    \ con;\n\tDSU dsu;\n\tdsu.init(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tint p;\n\
    \t\tcin >> p;\n\t\t--p;\n\t\tif (p != -1) {\n\t\t\ted.emplace_back(p, i);\n\t\t\
    }\n\t}\n\tvector<int> go(n, -1);\n\tfor (int i = 0; i < k; ++i) {\n\t\tint x,\
    \ y;\n\t\tcin >> x >> y;\n\t\t--x, --y;\n\t\tcon.emplace_back(x, y);\n\t\tgo[x]\
    \ = y;\n\t\tdsu.unite(x, y);\n\t}\n\tvector<vector<int>> comps(n), ord(n);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tcomps[dsu.get(i)].push_back(i);\n\t}\n\tmap<int,\
    \ int> conv;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (comps[i].empty()) {\n\t\
    \t\tcontinue;\n\t\t}\n\t\tint sz = comps[i].size();\n\t\tconv.clear();\n\t\tvector<vector<int>>\
    \ g(sz);\n\t\tfor (int j = 0; j < sz; ++j) {\n\t\t\tconv[comps[i][j]] = j;\n\t\
    \t}\n\t\tfor (int x : comps[i]) {\n\t\t\tif (go[x] == -1) {\n\t\t\t\tcontinue;\n\
    \t\t\t}\n\t\t\tif (conv.find(go[x]) == conv.end()) {\n\t\t\t\tcout << -1 << '\\\
    n';\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tg[conv[x]].push_back(conv[go[x]]);\n\t\t\
    }\n\t\tauto res = topo_sort(g);\n\t\tif (res.size() != sz) {\n\t\t\tcout << 0\
    \ << '\\n';\n\t\t\treturn 0;\n\t\t}\n\t\tfor (int x : res) {\n\t\t\tord[i].push_back(comps[i][x]);\n\
    \t\t}\n\t}\n\tvector<vector<int>> g(n);\n\tfor (auto [u, v] : ed) {\n\t\tu = dsu.get(u);\n\
    \t\tv = dsu.get(v);\n\t\tif (u != v) {\n\t\t\tg[u].push_back(v);\n\t\t}\n\t}\n\
    \tauto res = topo_sort(g);\n\tif (res.size() < n) {\n\t\tcout << 0 << '\\n';\n\
    \t\treturn 0;\n\t}\n\tvector<int> ans;\n\tfor (int x : res) {\n\t\tfor (int y\
    \ : ord[x]) {\n\t\t\tans.push_back(y);\n\t\t}\n\t}\n\tvector<int> rev(n);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\trev[ans[i]] = i;\n\t}\n\tfor (auto [u, v] :\
    \ ed) {\n\t\tif (rev[u] > rev[v]) {\n\t\t\tcout << 0 << '\\n';\n\t\t\treturn 0;\n\
    \t\t}\n\t}\n\tfor (int i = 0; i < n; ++i) {\n\t\tcout << ans[i] + 1 << ' ';\n\t\
    }\n\tcout << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1463/problem/E\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/graphs/dsu.hpp\"\
    \n#include \"../../library/graphs/topological-sort.hpp\"\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, k;\n\tcin >> n >> k;\n\tvector<pair<int, int>> ed,\
    \ con;\n\tDSU dsu;\n\tdsu.init(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tint p;\n\
    \t\tcin >> p;\n\t\t--p;\n\t\tif (p != -1) {\n\t\t\ted.emplace_back(p, i);\n\t\t\
    }\n\t}\n\tvector<int> go(n, -1);\n\tfor (int i = 0; i < k; ++i) {\n\t\tint x,\
    \ y;\n\t\tcin >> x >> y;\n\t\t--x, --y;\n\t\tcon.emplace_back(x, y);\n\t\tgo[x]\
    \ = y;\n\t\tdsu.unite(x, y);\n\t}\n\tvector<vector<int>> comps(n), ord(n);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tcomps[dsu.get(i)].push_back(i);\n\t}\n\tmap<int,\
    \ int> conv;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (comps[i].empty()) {\n\t\
    \t\tcontinue;\n\t\t}\n\t\tint sz = comps[i].size();\n\t\tconv.clear();\n\t\tvector<vector<int>>\
    \ g(sz);\n\t\tfor (int j = 0; j < sz; ++j) {\n\t\t\tconv[comps[i][j]] = j;\n\t\
    \t}\n\t\tfor (int x : comps[i]) {\n\t\t\tif (go[x] == -1) {\n\t\t\t\tcontinue;\n\
    \t\t\t}\n\t\t\tif (conv.find(go[x]) == conv.end()) {\n\t\t\t\tcout << -1 << '\\\
    n';\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tg[conv[x]].push_back(conv[go[x]]);\n\t\t\
    }\n\t\tauto res = topo_sort(g);\n\t\tif (res.size() != sz) {\n\t\t\tcout << 0\
    \ << '\\n';\n\t\t\treturn 0;\n\t\t}\n\t\tfor (int x : res) {\n\t\t\tord[i].push_back(comps[i][x]);\n\
    \t\t}\n\t}\n\tvector<vector<int>> g(n);\n\tfor (auto [u, v] : ed) {\n\t\tu = dsu.get(u);\n\
    \t\tv = dsu.get(v);\n\t\tif (u != v) {\n\t\t\tg[u].push_back(v);\n\t\t}\n\t}\n\
    \tauto res = topo_sort(g);\n\tif (res.size() < n) {\n\t\tcout << 0 << '\\n';\n\
    \t\treturn 0;\n\t}\n\tvector<int> ans;\n\tfor (int x : res) {\n\t\tfor (int y\
    \ : ord[x]) {\n\t\t\tans.push_back(y);\n\t\t}\n\t}\n\tvector<int> rev(n);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\trev[ans[i]] = i;\n\t}\n\tfor (auto [u, v] :\
    \ ed) {\n\t\tif (rev[u] > rev[v]) {\n\t\t\tcout << 0 << '\\n';\n\t\t\treturn 0;\n\
    \t\t}\n\t}\n\tfor (int i = 0; i < n; ++i) {\n\t\tcout << ans[i] + 1 << ' ';\n\t\
    }\n\tcout << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/dsu.hpp
  - library/graphs/topological-sort.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1463E.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1463E.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1463E.test.cpp
- /verify/verify/codeforces/codeforces-1463E.test.cpp.html
title: verify/codeforces/codeforces-1463E.test.cpp
---
