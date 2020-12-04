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
    const int MOD = 1e9 + 7;\nstruct MinDeque {\n    int lo = 0, hi = -1;\n    std::deque<std::pair<int,\
    \ int>> d;\n    void ins(int x) { // add to back\n        while ((d).size() &&\
    \ d.back().first >= x) d.pop_back();\n        d.push_back({x, ++hi});\n    }\n\
    \    void del() { // delete from front\n        if (d.front().second == lo++)\
    \ d.pop_front();\n    }\n    int get() {\n        return (d).size() ? d.front().first\
    \ : MOD;\n    }\n};\nint main(){\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nconst int MOD = 1e9 + 7;\nstruct MinDeque {\n \
    \   int lo = 0, hi = -1;\n    std::deque<std::pair<int, int>> d;\n    void ins(int\
    \ x) { // add to back\n        while ((d).size() && d.back().first >= x) d.pop_back();\n\
    \        d.push_back({x, ++hi});\n    }\n    void del() { // delete from front\n\
    \        if (d.front().second == lo++) d.pop_front();\n    }\n    int get() {\n\
    \        return (d).size() ? d.front().first : MOD;\n    }\n};\nint main(){\n\
    \    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/min_deque.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/min_deque.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/min_deque.cpp
- /library/library/dynamic-programming/min_deque.cpp.html
title: library/dynamic-programming/min_deque.cpp
---
