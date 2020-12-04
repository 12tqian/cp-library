---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/max_deque.cpp\"\n#include<bits/stdc++.h>\r\
    \nconst int MOD = 1e9 + 7;\r\nstruct MaxDeque {\r\n    std::deque<std::pair<int,\
    \ int>> mx;\r\n    std::deque<int> tmp;\r\n\r\n    int l = 0,r = -1;\r\n\r\n \
    \   int del() {\r\n        if (mx.front().second == l++) mx.pop_front();\r\n \
    \       int t = tmp.front();\r\n        tmp.pop_front();\r\n        return t;\r\
    \n    }\r\n    int query() {\r\n        if (mx.size() == 0) return -MOD;\r\n \
    \       return mx.front().first;\r\n    }\r\n    void ad(int x) {\r\n        while\
    \ ((mx).size() && mx.back().first <= x) mx.pop_back();\r\n        mx.push_back({x,\
    \ ++r});\r\n        tmp.push_back(x);\r\n    }\r\n};\r\nint main(){\r\n    return\
    \ 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\nconst int MOD = 1e9 + 7;\r\nstruct MaxDeque {\r\
    \n    std::deque<std::pair<int, int>> mx;\r\n    std::deque<int> tmp;\r\n\r\n\
    \    int l = 0,r = -1;\r\n\r\n    int del() {\r\n        if (mx.front().second\
    \ == l++) mx.pop_front();\r\n        int t = tmp.front();\r\n        tmp.pop_front();\r\
    \n        return t;\r\n    }\r\n    int query() {\r\n        if (mx.size() ==\
    \ 0) return -MOD;\r\n        return mx.front().first;\r\n    }\r\n    void ad(int\
    \ x) {\r\n        while ((mx).size() && mx.back().first <= x) mx.pop_back();\r\
    \n        mx.push_back({x, ++r});\r\n        tmp.push_back(x);\r\n    }\r\n};\r\
    \nint main(){\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/max_deque.cpp
  requiredBy: []
  timestamp: '2020-11-24 21:07:46-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/max_deque.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/max_deque.cpp
- /library/library/dynamic-programming/max_deque.cpp.html
title: library/dynamic-programming/max_deque.cpp
---
