---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/number-theory/basic-factor.hpp
    title: Basic Factoring
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.spoj.com/problems/FACT0/
    links:
    - https://www.spoj.com/problems/FACT0/
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/FACT0/\"\r\n\r\n\r\
    \n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include <cassert>\r\
    \n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n#include <cstdio>\r\
    \n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\n#include <deque>\r\
    \n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\n#include <map>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\n#include <set>\r\
    \n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\n#include\
    \ <vector>\r\n\r\nusing namespace std;\n\r\nnamespace FactorBasic {\r\n\r\ntemplate\
    \ <class T> std::vector<std::pair<T, int>> factor(T x) {\r\n\tstd::vector<std::pair<T,\
    \ int>> pri;\r\n\tfor (T i = 2; i * i <= x; ++i) {\r\n\t\tif (x % i == 0) {\r\n\
    \t\t\tint t = 0;\r\n\t\t\twhile (x % i == 0) x /= i, t++;\r\n\t\t\tpri.push_back({i,\
    \ t});\r\n\t\t}\r\n\t}\r\n\tif (x > 1) pri.push_back({x, 1});\r\n\treturn pri;\r\
    \n}\r\n\r\ntemplate <class T> T phi(T x) {\r\n\tfor (auto& a : factor(x)) x -=\
    \ x / a.first;\r\n\treturn x;\r\n}\r\n\r\ntemplate <class T> void tour(std::vector<std::pair<T,\
    \ int>>& v, std::vector<T>& res, int ind, T cur) {\r\n\tif (ind == (int)v.size())\
    \ res.push_back(cur);\r\n\telse {\r\n\t\tT mul = 1;\r\n\t\tfor (int i = 0; i <\
    \ v[ind].second + 1; i++) {\r\n\t\t\ttour(v, res, ind + 1, cur * mul);\r\n\t\t\
    \tmul *= v[ind].first;\r\n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate <class T> std::vector<T>\
    \ get_divisor(T x) {\r\n\tauto v = factor(x);\r\n\tstd::vector<T> res; \r\n\t\
    tour(v, res, 0, (T) 1);\r\n\tsort(res.begin(), res.end());\r\n\treturn res;\r\n\
    }\r\n\r\n}\n\r\n// verified probably using SPOJ?\r\nint main() {\r\n\tusing namespace\
    \ FactorBasic;\r\n\tusing namespace std;\r\n\twhile (true) {\r\n\t\tlong long\
    \ n;\r\n\t\tcin >> n;\r\n\t\tif (n == 0) return 0;\r\n\t\tauto f = factor(n);\r\
    \n\t\tfor (auto x : f) {\r\n\t\t\tcout << x.first << \"^\" << x.second << \" \"\
    ;\r\n\t\t}\r\n\t\tcout << '\\n';\r\n\t}  \r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/FACT0/\"\r\n\r\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/number-theory/basic-factor.hpp\"\
    \r\n\r\n// verified probably using SPOJ?\r\nint main() {\r\n\tusing namespace\
    \ FactorBasic;\r\n\tusing namespace std;\r\n\twhile (true) {\r\n\t\tlong long\
    \ n;\r\n\t\tcin >> n;\r\n\t\tif (n == 0) return 0;\r\n\t\tauto f = factor(n);\r\
    \n\t\tfor (auto x : f) {\r\n\t\t\tcout << x.first << \"^\" << x.second << \" \"\
    ;\r\n\t\t}\r\n\t\tcout << '\\n';\r\n\t}  \r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/basic-factor.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-FACT0.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-FACT0.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-FACT0.test.cpp
- /verify/verify/spoj/spoj-FACT0.test.cpp.html
title: verify/spoj/spoj-FACT0.test.cpp
---
