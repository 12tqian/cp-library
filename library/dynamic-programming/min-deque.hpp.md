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
  bundledCode: "\r\ntemplate <class T> struct MinDeque {\r\n\tint lo = 0, hi = -1;\r\
    \n\r\n\tstd::deque<std::pair<T, int>> d;\r\n\tvoid push_back(T x) { // add to\
    \ back\r\n\t\twhile ((int)d.size() && d.back().first >= x) d.pop_back();\r\n\t\
    \td.push_back({x, ++hi});\r\n\t}\r\n\r\n\tvoid pop_front() { // delete from front\r\
    \n\t\tif (d.front().second == lo++) d.pop_front();\r\n\t}\r\n\r\n\tT get() {\r\
    \n\t\treturn (int)d.size() ? d.front().first : std::numeric_limits<T>::max();\r\
    \n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct MinDeque {\r\n\tint lo = 0,\
    \ hi = -1;\r\n\r\n\tstd::deque<std::pair<T, int>> d;\r\n\tvoid push_back(T x)\
    \ { // add to back\r\n\t\twhile ((int)d.size() && d.back().first >= x) d.pop_back();\r\
    \n\t\td.push_back({x, ++hi});\r\n\t}\r\n\r\n\tvoid pop_front() { // delete from\
    \ front\r\n\t\tif (d.front().second == lo++) d.pop_front();\r\n\t}\r\n\r\n\tT\
    \ get() {\r\n\t\treturn (int)d.size() ? d.front().first : std::numeric_limits<T>::max();\r\
    \n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/min-deque.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1195E.test.cpp
documentation_of: library/dynamic-programming/min-deque.hpp
layout: document
redirect_from:
- /library/library/dynamic-programming/min-deque.hpp
- /library/library/dynamic-programming/min-deque.hpp.html
title: library/dynamic-programming/min-deque.hpp
---
