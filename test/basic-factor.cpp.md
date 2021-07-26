---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':warning:'
    path: library/number-theory/basic-factor.hpp
    title: library/number-theory/basic-factor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#define IGNORE\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <deque>\n#include <iostream>\n#include <iomanip>\n#include\
    \ <list>\n#include <map>\n#include <numeric>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <vector>\n\nusing namespace std;\n\n/**\n * Factors in O(sqrt(n))\n *\
    \ Divisors in O(sqrt(n))\n * phi in O(sqrt(n))\n */\n\nnamespace FactorBasic {\n\
    \ntemplate <class T> std::vector<std::pair<T, int>> factor(T x) {\n\tstd::vector<std::pair<T,\
    \ int>> pri;\n\tfor (T i = 2; i * i <= x; ++i) {\n\t\tif (x % i == 0) {\n\t\t\t\
    int t = 0;\n\t\t\twhile (x % i == 0) x /= i, t++;\n\t\t\tpri.push_back({i, t});\n\
    \t\t}\n\t}\n\tif (x > 1) pri.push_back({x, 1});\n\treturn pri;\n}\n\ntemplate\
    \ <class T> T phi(T x) {\n\tfor (auto &a : factor(x)) x -= x / a.first;\n\treturn\
    \ x;\n}\n\ntemplate <class T> void tour(std::vector<std::pair<T, int>> &v, std::vector<T>\
    \ &res, int ind, T cur) {\n\tif (ind == (int)v.size()) res.push_back(cur);\n\t\
    else {\n\t\tT mul = 1;\n\t\tfor (int i = 0; i < v[ind].second + 1; i++) {\n\t\t\
    \ttour(v, res, ind + 1, cur * mul);\n\t\t\tmul *= v[ind].first;\n\t\t}\n\t}\n\
    }\n\ntemplate <class T> std::vector<T> get_divisor(T x) {\n\tauto v = factor(x);\n\
    \tstd::vector<T> res; \n\ttour(v, res, 0, (T) 1);\n\tsort(res.begin(), res.end());\n\
    \treturn res;\n}\n\n}\n\n// verified probably using SPOJ?\nint main() {\n\tusing\
    \ namespace FactorBasic;\n\tusing namespace std;\n\twhile (true) {\n\t\tlong long\
    \ n;\n\t\tcin >> n;\n\t\tif (n == 0) return 0;\n\t\tauto f = factor(n);\n\t\t\
    for (auto x : f) {\n\t\t\tcout << x.first << \"^\" << x.second << \" \";\n\t\t\
    }\n\t\tcout << '\\n';\n\t}  \n\treturn 0;\n}\n"
  code: "#define IGNORE\n\n#include \"../library/contest/template-minimal.hpp\"\n\
    #include \"../library/number-theory/basic-factor.hpp\"\n\n// verified probably\
    \ using SPOJ?\nint main() {\n\tusing namespace FactorBasic;\n\tusing namespace\
    \ std;\n\twhile (true) {\n\t\tlong long n;\n\t\tcin >> n;\n\t\tif (n == 0) return\
    \ 0;\n\t\tauto f = factor(n);\n\t\tfor (auto x : f) {\n\t\t\tcout << x.first <<\
    \ \"^\" << x.second << \" \";\n\t\t}\n\t\tcout << '\\n';\n\t}  \n\treturn 0;\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/basic-factor.hpp
  isVerificationFile: false
  path: test/basic-factor.cpp
  requiredBy: []
  timestamp: '2021-07-24 23:00:09-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/basic-factor.cpp
layout: document
redirect_from:
- /library/test/basic-factor.cpp
- /library/test/basic-factor.cpp.html
title: test/basic-factor.cpp
---
