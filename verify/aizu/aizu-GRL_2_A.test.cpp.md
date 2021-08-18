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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n\nstruct DSU {\n\tstd::vector<int> e;\n\n\tvoid init(int n) {\n\t\te = std::vector<int>(n,\
    \ -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\n\
    \t}\n\n\tbool same_set(int a, int b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\t\
    int size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tbool unite(int x, int y) {\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ std::swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\n\t\treturn true;\n\t}\n};\n\n\
    \n// weight, start, end\nlong long kruskal(std::vector<std::array<int, 3>> edge)\
    \ {\n\tDSU D;\n\tint n = 0;\n\tfor (auto& a : edge) {\n\t\tn = std::max(n, a[1]);\n\
    \t\tn = std::max(n, a[2]);\n\t}\n\t++n;\n\tD.init(n);\n\tsort(edge.begin(), edge.end());\n\
    \tlong long ans = 0;\n\tfor (auto& a : edge) {\n\t\tif (D.unite(a[1], a[2])) {\n\
    \t\t\tans += a[0];\n\t\t}\n\t}\n\treturn ans;\n}\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, m;\n\tcin >> n >> m;\n\tvector<array<int, 3>> edges;\n\
    \tfor (int i = 0; i < m; ++i) {\n\t\tint u, v, w;\n\t\tcin >> u >> v >> w;\n\t\
    \tedges.push_back({w, u, v});\n\t}\n\tcout << kruskal(edges) << '\\n';\n\treturn\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/graphs/kruskal.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n,\
    \ m;\n\tcin >> n >> m;\n\tvector<array<int, 3>> edges;\n\tfor (int i = 0; i <\
    \ m; ++i) {\n\t\tint u, v, w;\n\t\tcin >> u >> v >> w;\n\t\tedges.push_back({w,\
    \ u, v});\n\t}\n\tcout << kruskal(edges) << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/kruskal.hpp
  - library/graphs/dsu.hpp
  isVerificationFile: true
  path: verify/aizu/aizu-GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 13:31:52-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/aizu-GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/aizu-GRL_2_A.test.cpp
- /verify/verify/aizu/aizu-GRL_2_A.test.cpp.html
title: verify/aizu/aizu-GRL_2_A.test.cpp
---
