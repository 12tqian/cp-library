---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1195E.test.cpp
    title: verify/codeforces/codeforces-1195E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct MaxDeque {\r\n\tstd::deque<std::pair<T,\
    \ int>> mx;\r\n\tstd::deque<int> tmp;\r\n\r\n\tint l = 0,r = -1;\r\n\r\n\tint\
    \ pop_front() {\r\n\t\tif (mx.front().second == l++) mx.pop_front();\r\n\t\tint\
    \ t = tmp.front();\r\n\t\ttmp.pop_front();\r\n\t\treturn t;\r\n\t}\r\n\r\n\tT\
    \ get() {\r\n\t\tif ((int)mx.size() == 0) return std::numeric_limits<T>::min();\r\
    \n\t\treturn mx.front().first;\r\n\t}\r\n\r\n\tvoid push_back(T x) {\r\n\t\twhile\
    \ ((int)mx.size() && mx.back().first <= x) mx.pop_back();\r\n\t\tmx.push_back({x,\
    \ ++r});\r\n\t\ttmp.push_back(x);\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct MaxDeque {\r\n\tstd::deque<std::pair<T,\
    \ int>> mx;\r\n\tstd::deque<int> tmp;\r\n\r\n\tint l = 0,r = -1;\r\n\r\n\tint\
    \ pop_front() {\r\n\t\tif (mx.front().second == l++) mx.pop_front();\r\n\t\tint\
    \ t = tmp.front();\r\n\t\ttmp.pop_front();\r\n\t\treturn t;\r\n\t}\r\n\r\n\tT\
    \ get() {\r\n\t\tif ((int)mx.size() == 0) return std::numeric_limits<T>::min();\r\
    \n\t\treturn mx.front().first;\r\n\t}\r\n\r\n\tvoid push_back(T x) {\r\n\t\twhile\
    \ ((int)mx.size() && mx.back().first <= x) mx.pop_back();\r\n\t\tmx.push_back({x,\
    \ ++r});\r\n\t\ttmp.push_back(x);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/max-deque.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1195E.test.cpp
documentation_of: library/dynamic-programming/max-deque.hpp
layout: document
redirect_from:
- /library/library/dynamic-programming/max-deque.hpp
- /library/library/dynamic-programming/max-deque.hpp.html
title: library/dynamic-programming/max-deque.hpp
---
