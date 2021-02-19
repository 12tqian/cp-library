---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/min_deque.cpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <class T> struct MinDeque {\n    int lo = 0, hi = -1;\n\n    std::deque<std::pair<T,\
    \ int>> d;\n    void ins(T x) { // add to back\n        while ((int)d.size() &&\
    \ d.back().first >= x) d.pop_back();\n        d.push_back({x, ++hi});\n    }\n\
    \n    void del() { // delete from front\n        if (d.front().second == lo++)\
    \ d.pop_front();\n    }\n\n    T get() {\n        return (int)d.size() ? d.front().first\
    \ : std::numeric_limits<T>::max();\n    }\n};\n\nint main() {\n    return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct MinDeque {\n    int\
    \ lo = 0, hi = -1;\n\n    std::deque<std::pair<T, int>> d;\n    void ins(T x)\
    \ { // add to back\n        while ((int)d.size() && d.back().first >= x) d.pop_back();\n\
    \        d.push_back({x, ++hi});\n    }\n\n    void del() { // delete from front\n\
    \        if (d.front().second == lo++) d.pop_front();\n    }\n\n    T get() {\n\
    \        return (int)d.size() ? d.front().first : std::numeric_limits<T>::max();\n\
    \    }\n};\n\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/min_deque.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/min_deque.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/min_deque.cpp
- /library/library/dynamic-programming/min_deque.cpp.html
title: library/dynamic-programming/min_deque.cpp
---
