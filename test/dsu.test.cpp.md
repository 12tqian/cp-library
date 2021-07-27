---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/dsu.hpp
    title: library/graphs/dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
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
    \nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tDSU dsu;\n\tdsu.init(n);\n\twhile (q--) {\n\t\tint t,\
    \ u, v;\n\t\tcin >> t >> u >> v;\n\t\tif (t == 0) {\n\t\t\tdsu.unite(u, v);\n\t\
    \t} else {\n\t\t\tcout << dsu.same_set(u, v) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../library/contest/template-minimal.hpp\"\n#include \"../library/graphs/dsu.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tDSU dsu;\n\tdsu.init(n);\n\twhile (q--) {\n\t\tint t,\
    \ u, v;\n\t\tcin >> t >> u >> v;\n\t\tif (t == 0) {\n\t\t\tdsu.unite(u, v);\n\t\
    \t} else {\n\t\t\tcout << dsu.same_set(u, v) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/dsu.hpp
  isVerificationFile: true
  path: test/dsu.test.cpp
  requiredBy: []
  timestamp: '2021-07-25 17:11:24-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dsu.test.cpp
layout: document
redirect_from:
- /verify/test/dsu.test.cpp
- /verify/test/dsu.test.cpp.html
title: test/dsu.test.cpp
---
