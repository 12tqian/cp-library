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
  bundledCode: "\ntemplate <class T> struct MinDeque {\n\tint lo = 0, hi = -1;\n\n\
    \tstd::deque<std::pair<T, int>> d;\n\tvoid push_back(T x) { // add to back\n\t\
    \twhile ((int)d.size() && d.back().first >= x) d.pop_back();\n\t\td.push_back({x,\
    \ ++hi});\n\t}\n\n\tvoid pop_front() { // delete from front\n\t\tif (d.front().second\
    \ == lo++) d.pop_front();\n\t}\n\n\tT get() {\n\t\treturn (int)d.size() ? d.front().first\
    \ : std::numeric_limits<T>::max();\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct MinDeque {\n\tint lo = 0, hi =\
    \ -1;\n\n\tstd::deque<std::pair<T, int>> d;\n\tvoid push_back(T x) { // add to\
    \ back\n\t\twhile ((int)d.size() && d.back().first >= x) d.pop_back();\n\t\td.push_back({x,\
    \ ++hi});\n\t}\n\n\tvoid pop_front() { // delete from front\n\t\tif (d.front().second\
    \ == lo++) d.pop_front();\n\t}\n\n\tT get() {\n\t\treturn (int)d.size() ? d.front().first\
    \ : std::numeric_limits<T>::max();\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/min-deque.hpp
  requiredBy: []
  timestamp: '2021-07-28 19:32:19-04:00'
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
