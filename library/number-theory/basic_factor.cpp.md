---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/basic_factor.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * Factors in O(sqrt(n))\n * Divisors in O(sqrt(n))\n * phi in O(sqrt(n))\n\
    \ */\n\nnamespace FactorBasic {\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factor(T x) {\n    std::vector<std::pair<T, int>> pri;\n    for (T i =\
    \ 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n            int t = 0;\n \
    \           while (x % i == 0) x /= i, t++;\n            pri.push_back({i, t});\n\
    \        }\n    }\n    if (x > 1) pri.push_back({x, 1});\n    return pri;\n}\n\
    \ntemplate <class T> T phi(T x) {\n    for (auto& a : factor(x)) x -= x / a.first;\n\
    \    return x;\n}\n\ntemplate <class T> void tour(std::vector<std::pair<T, int>>&\
    \ v, std::vector<T>& res, int ind, T cur) {\n    if (ind == int(v.size())) res.push_back(cur);\n\
    \    else {\n        T mul = 1;\n        for (int i = 0; i < v[ind].second + 1;\
    \ i++) {\n            tour(v, res, ind + 1, cur * mul);\n            mul *= v[ind].first;\n\
    \        }\n    }\n}\n\ntemplate <class T> std::vector<T> get_divisor(T x) {\n\
    \    auto v = factor(x);\n    std::vector<T> res; \n    tour(v, res, 0, (T) 1);\n\
    \    sort(res.begin(), res.end());\n    return res;\n}\n\n}\n\nint main() {\n\
    \    using namespace FactorBasic;\n    using namespace std;\n    while (true)\
    \ {\n        long long n;\n        cin >> n;\n        if (n == 0) return 0;\n\
    \        auto f = factor(n);\n        for (auto x : f) {\n            cout <<\
    \ x.first << \"^\" << x.second << \" \";\n        }\n        cout << '\\n';\n\
    \    }  \n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Factors in O(sqrt(n))\n * Divisors in\
    \ O(sqrt(n))\n * phi in O(sqrt(n))\n */\n\nnamespace FactorBasic {\n\ntemplate\
    \ <class T> std::vector<std::pair<T, int>> factor(T x) {\n    std::vector<std::pair<T,\
    \ int>> pri;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n\
    \            int t = 0;\n            while (x % i == 0) x /= i, t++;\n       \
    \     pri.push_back({i, t});\n        }\n    }\n    if (x > 1) pri.push_back({x,\
    \ 1});\n    return pri;\n}\n\ntemplate <class T> T phi(T x) {\n    for (auto&\
    \ a : factor(x)) x -= x / a.first;\n    return x;\n}\n\ntemplate <class T> void\
    \ tour(std::vector<std::pair<T, int>>& v, std::vector<T>& res, int ind, T cur)\
    \ {\n    if (ind == int(v.size())) res.push_back(cur);\n    else {\n        T\
    \ mul = 1;\n        for (int i = 0; i < v[ind].second + 1; i++) {\n          \
    \  tour(v, res, ind + 1, cur * mul);\n            mul *= v[ind].first;\n     \
    \   }\n    }\n}\n\ntemplate <class T> std::vector<T> get_divisor(T x) {\n    auto\
    \ v = factor(x);\n    std::vector<T> res; \n    tour(v, res, 0, (T) 1);\n    sort(res.begin(),\
    \ res.end());\n    return res;\n}\n\n}\n\nint main() {\n    using namespace FactorBasic;\n\
    \    using namespace std;\n    while (true) {\n        long long n;\n        cin\
    \ >> n;\n        if (n == 0) return 0;\n        auto f = factor(n);\n        for\
    \ (auto x : f) {\n            cout << x.first << \"^\" << x.second << \" \";\n\
    \        }\n        cout << '\\n';\n    }  \n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/basic_factor.cpp
  requiredBy: []
  timestamp: '2021-01-07 19:46:40-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/basic_factor.cpp
layout: document
redirect_from:
- /library/library/number-theory/basic_factor.cpp
- /library/library/number-theory/basic_factor.cpp.html
title: library/number-theory/basic_factor.cpp
---
