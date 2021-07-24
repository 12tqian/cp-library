---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/max_deque.cpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <class T> struct MaxDeque {\n\tstd::deque<std::pair<T, int>> mx;\n\t\
    std::deque<int> tmp;\n\n\tint l = 0,r = -1;\n\n\tint del() {\n\t\tif (mx.front().second\
    \ == l++) mx.pop_front();\n\t\tint t = tmp.front();\n\t\ttmp.pop_front();\n\t\t\
    return t;\n\t}\n\n\tT get() {\n\t\tif ((int)mx.size() == 0) return std::numeric_limits<T>::min();\n\
    \t\treturn mx.front().first;\n\t}\n\n\tvoid ad(T x) {\n\t\twhile ((int)mx.size()\
    \ && mx.back().first <= x) mx.pop_back();\n\t\tmx.push_back({x, ++r});\n\t\ttmp.push_back(x);\n\
    \t}\n};\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct MaxDeque {\n\tstd::deque<std::pair<T,\
    \ int>> mx;\n\tstd::deque<int> tmp;\n\n\tint l = 0,r = -1;\n\n\tint del() {\n\t\
    \tif (mx.front().second == l++) mx.pop_front();\n\t\tint t = tmp.front();\n\t\t\
    tmp.pop_front();\n\t\treturn t;\n\t}\n\n\tT get() {\n\t\tif ((int)mx.size() ==\
    \ 0) return std::numeric_limits<T>::min();\n\t\treturn mx.front().first;\n\t}\n\
    \n\tvoid ad(T x) {\n\t\twhile ((int)mx.size() && mx.back().first <= x) mx.pop_back();\n\
    \t\tmx.push_back({x, ++r});\n\t\ttmp.push_back(x);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/max_deque.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/max_deque.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/max_deque.cpp
- /library/library/dynamic-programming/max_deque.cpp.html
title: library/dynamic-programming/max_deque.cpp
---
