---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n\n/**\n * Factors in O(sqrt(n))\n * Divisors\
    \ in O(sqrt(n))\n * phi in O(sqrt(n))\n */\n\nnamespace FactorBasic {\n\ntemplate\
    \ <class T> std::vector<std::pair<T, int>> factor(T x) {\n\tstd::vector<std::pair<T,\
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
    \treturn res;\n}\n\n}\n\nint main() {\n\tusing namespace FactorBasic;\n\tusing\
    \ namespace std;\n\twhile (true) {\n\t\tlong long n;\n\t\tcin >> n;\n\t\tif (n\
    \ == 0) return 0;\n\t\tauto f = factor(n);\n\t\tfor (auto x : f) {\n\t\t\tcout\
    \ << x.first << \"^\" << x.second << \" \";\n\t\t}\n\t\tcout << '\\n';\n\t}  \n\
    \treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Factors in O(sqrt(n))\n * Divisors in\
    \ O(sqrt(n))\n * phi in O(sqrt(n))\n */\n\nnamespace FactorBasic {\n\ntemplate\
    \ <class T> std::vector<std::pair<T, int>> factor(T x) {\n\tstd::vector<std::pair<T,\
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
    \treturn res;\n}\n\n}\n\nint main() {\n\tusing namespace FactorBasic;\n\tusing\
    \ namespace std;\n\twhile (true) {\n\t\tlong long n;\n\t\tcin >> n;\n\t\tif (n\
    \ == 0) return 0;\n\t\tauto f = factor(n);\n\t\tfor (auto x : f) {\n\t\t\tcout\
    \ << x.first << \"^\" << x.second << \" \";\n\t\t}\n\t\tcout << '\\n';\n\t}  \n\
    \treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/basic-factor.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:26:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/basic-factor.hpp
layout: document
redirect_from:
- /library/library/number-theory/basic-factor.hpp
- /library/library/number-theory/basic-factor.hpp.html
title: library/number-theory/basic-factor.hpp
---
