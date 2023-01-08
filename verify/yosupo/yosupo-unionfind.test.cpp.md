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
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\
    \n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nstruct DSU {\r\n  std::vector<int>\
    \ e;\r\n\r\n  DSU() = default;\r\n  DSU(int n) { init(n); }\r\n\r\n  void init(int\
    \ n) { e = std::vector<int>(n, -1); }\r\n\r\n  int get(int x) { return e[x] <\
    \ 0 ? x : e[x] = get(e[x]); }\r\n\r\n  bool same_set(int a, int b) { return get(a)\
    \ == get(b); }\r\n\r\n  int size(int x) { return -e[get(x)]; }\r\n\r\n  bool unite(int\
    \ x, int y) {\r\n    x = get(x), y = get(y);\r\n    if (x == y) return false;\r\
    \n    if (e[x] > e[y]) std::swap(x, y);\r\n    e[x] += e[y];\r\n    e[y] = x;\r\
    \n    return true;\r\n  }\r\n};\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tDSU dsu;\r\n\tdsu.init(n);\r\
    \n\twhile (q--) {\r\n\t\tint t, u, v;\r\n\t\tcin >> t >> u >> v;\r\n\t\tif (t\
    \ == 0) {\r\n\t\t\tdsu.unite(u, v);\r\n\t\t} else {\r\n\t\t\tcout << dsu.same_set(u,\
    \ v) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/dsu.hpp\"\
    \r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, q;\r\n\tcin >> n >> q;\r\n\tDSU dsu;\r\n\tdsu.init(n);\r\n\twhile (q--)\
    \ {\r\n\t\tint t, u, v;\r\n\t\tcin >> t >> u >> v;\r\n\t\tif (t == 0) {\r\n\t\t\
    \tdsu.unite(u, v);\r\n\t\t} else {\r\n\t\t\tcout << dsu.same_set(u, v) << '\\\
    n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/dsu.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 14:16:34-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-unionfind.test.cpp
- /verify/verify/yosupo/yosupo-unionfind.test.cpp.html
title: verify/yosupo/yosupo-unionfind.test.cpp
---
