---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/graphs/dsu.hpp
    title: library/graphs/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/kruskal.hpp
    title: library/graphs/kruskal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n\r\nstruct DSU {\r\n\tstd::vector<int>\
    \ e;\r\n\r\n\tvoid init(int n) {\r\n\t\te = std::vector<int>(n, -1);\r\n\t}\r\n\
    \r\n\tint get(int x) {\r\n\t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\r\n\t}\r\
    \n\r\n\tbool same_set(int a, int b) {\r\n\t\treturn get(a) == get(b);\r\n\t}\r\
    \n\r\n\tint size(int x) {\r\n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tbool unite(int\
    \ x, int y) {\r\n\t\tx = get(x), y = get(y);\r\n\t\tif (x == y) return false;\r\
    \n\t\tif (e[x] > e[y]) std::swap(x, y);\r\n\t\te[x] += e[y]; e[y] = x;\r\n\t\t\
    return true;\r\n\t}\r\n};\r\n\r\n\r\n// weight, start, end\r\nlong long kruskal(std::vector<std::array<int,\
    \ 3>> edge) {\r\n\tDSU D;\r\n\tint n = 0;\r\n\tfor (auto& a : edge) {\r\n\t\t\
    n = std::max(n, a[1]);\r\n\t\tn = std::max(n, a[2]);\r\n\t}\r\n\t++n;\r\n\tD.init(n);\r\
    \n\tsort(edge.begin(), edge.end());\r\n\tlong long ans = 0;\r\n\tfor (auto& a\
    \ : edge) {\r\n\t\tif (D.unite(a[1], a[2])) {\r\n\t\t\tans += a[0];\r\n\t\t}\r\
    \n\t}\r\n\treturn ans;\r\n}\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tvector<array<int,\
    \ 3>> edges;\r\n\tfor (int i = 0; i < m; ++i) {\r\n\t\tint u, v, w;\r\n\t\tcin\
    \ >> u >> v >> w;\r\n\t\tedges.push_back({w, u, v});\r\n\t}\r\n\tcout << kruskal(edges)\
    \ << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/graphs/kruskal.hpp\"\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tvector<array<int,\
    \ 3>> edges;\r\n\tfor (int i = 0; i < m; ++i) {\r\n\t\tint u, v, w;\r\n\t\tcin\
    \ >> u >> v >> w;\r\n\t\tedges.push_back({w, u, v});\r\n\t}\r\n\tcout << kruskal(edges)\
    \ << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/kruskal.hpp
  - library/graphs/dsu.hpp
  isVerificationFile: true
  path: verify/aizu/aizu-GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/aizu-GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/aizu-GRL_2_A.test.cpp
- /verify/verify/aizu/aizu-GRL_2_A.test.cpp.html
title: verify/aizu/aizu-GRL_2_A.test.cpp
---
