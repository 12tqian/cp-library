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
  bundledCode: "\ntemplate <class T> struct MaxDeque {\n\tstd::deque<std::pair<T,\
    \ int>> mx;\n\tstd::deque<int> tmp;\n\n\tint l = 0,r = -1;\n\n\tint pop_front()\
    \ {\n\t\tif (mx.front().second == l++) mx.pop_front();\n\t\tint t = tmp.front();\n\
    \t\ttmp.pop_front();\n\t\treturn t;\n\t}\n\n\tT get() {\n\t\tif ((int)mx.size()\
    \ == 0) return std::numeric_limits<T>::min();\n\t\treturn mx.front().first;\n\t\
    }\n\n\tvoid push_back(T x) {\n\t\twhile ((int)mx.size() && mx.back().first <=\
    \ x) mx.pop_back();\n\t\tmx.push_back({x, ++r});\n\t\ttmp.push_back(x);\n\t}\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T> struct MaxDeque {\n\tstd::deque<std::pair<T,\
    \ int>> mx;\n\tstd::deque<int> tmp;\n\n\tint l = 0,r = -1;\n\n\tint pop_front()\
    \ {\n\t\tif (mx.front().second == l++) mx.pop_front();\n\t\tint t = tmp.front();\n\
    \t\ttmp.pop_front();\n\t\treturn t;\n\t}\n\n\tT get() {\n\t\tif ((int)mx.size()\
    \ == 0) return std::numeric_limits<T>::min();\n\t\treturn mx.front().first;\n\t\
    }\n\n\tvoid push_back(T x) {\n\t\twhile ((int)mx.size() && mx.back().first <=\
    \ x) mx.pop_back();\n\t\tmx.push_back({x, ++r});\n\t\ttmp.push_back(x);\n\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/max-deque.hpp
  requiredBy: []
  timestamp: '2021-07-28 19:32:19-04:00'
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
