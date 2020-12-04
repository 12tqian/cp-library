---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/max_deque.cpp\"\n#include<bits/stdc++.h>\n\
    const int MOD = 1e9 + 7;\nstruct MaxDeque {\n    std::deque<std::pair<int, int>>\
    \ mx;\n    std::deque<int> tmp;\n\n    int l = 0,r = -1;\n\n    int del() {\n\
    \        if (mx.front().second == l++) mx.pop_front();\n        int t = tmp.front();\n\
    \        tmp.pop_front();\n        return t;\n    }\n    int query() {\n     \
    \   if (mx.size() == 0) return -MOD;\n        return mx.front().first;\n    }\n\
    \    void ad(int x) {\n        while ((mx).size() && mx.back().first <= x) mx.pop_back();\n\
    \        mx.push_back({x, ++r});\n        tmp.push_back(x);\n    }\n};\nint main(){\n\
    \    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nconst int MOD = 1e9 + 7;\nstruct MaxDeque {\n  \
    \  std::deque<std::pair<int, int>> mx;\n    std::deque<int> tmp;\n\n    int l\
    \ = 0,r = -1;\n\n    int del() {\n        if (mx.front().second == l++) mx.pop_front();\n\
    \        int t = tmp.front();\n        tmp.pop_front();\n        return t;\n \
    \   }\n    int query() {\n        if (mx.size() == 0) return -MOD;\n        return\
    \ mx.front().first;\n    }\n    void ad(int x) {\n        while ((mx).size() &&\
    \ mx.back().first <= x) mx.pop_back();\n        mx.push_back({x, ++r});\n    \
    \    tmp.push_back(x);\n    }\n};\nint main(){\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/max_deque.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/max_deque.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/max_deque.cpp
- /library/library/dynamic-programming/max_deque.cpp.html
title: library/dynamic-programming/max_deque.cpp
---
