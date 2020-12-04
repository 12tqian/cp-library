---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/min_deque.cpp\"\n#include <bits/stdc++.h>\r\
    \nconst int MOD = 1e9 + 7;\r\nstruct MinDeque {\r\n    int lo = 0, hi = -1;\r\n\
    \    std::deque<std::pair<int, int>> d;\r\n    void ins(int x) { // add to back\r\
    \n        while ((d).size() && d.back().first >= x) d.pop_back();\r\n        d.push_back({x,\
    \ ++hi});\r\n    }\r\n    void del() { // delete from front\r\n        if (d.front().second\
    \ == lo++) d.pop_front();\r\n    }\r\n    int get() {\r\n        return (d).size()\
    \ ? d.front().first : MOD;\r\n    }\r\n};\r\nint main(){\r\n    return 0;\r\n\
    }\r\n"
  code: "#include <bits/stdc++.h>\r\nconst int MOD = 1e9 + 7;\r\nstruct MinDeque {\r\
    \n    int lo = 0, hi = -1;\r\n    std::deque<std::pair<int, int>> d;\r\n    void\
    \ ins(int x) { // add to back\r\n        while ((d).size() && d.back().first >=\
    \ x) d.pop_back();\r\n        d.push_back({x, ++hi});\r\n    }\r\n    void del()\
    \ { // delete from front\r\n        if (d.front().second == lo++) d.pop_front();\r\
    \n    }\r\n    int get() {\r\n        return (d).size() ? d.front().first : MOD;\r\
    \n    }\r\n};\r\nint main(){\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/min_deque.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:54:59-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/min_deque.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/min_deque.cpp
- /library/library/dynamic-programming/min_deque.cpp.html
title: library/dynamic-programming/min_deque.cpp
---
