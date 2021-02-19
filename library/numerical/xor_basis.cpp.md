---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/xor_basis.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * full_reduce() does complete Gaussian reduction\n * reduce() just does\
    \ the things that are necessary, should be sufficient\n */\n\nvoid full_reduce(std::vector<int>&\
    \ b) {\n    int n = (int)b.size();\n    for (int i = n - 1; i >= 0; i--) {\n \
    \       for (int j = i - 1; j >= 0; j--) {\n            b[j] = std::min(b[j],\
    \ b[j] ^ b[i]);\n        }\n    }\n}\n\ntemplate <class T> T reduce(std::vector<T>&\
    \ b, T x) {\n    for (auto& t : b) {\n        x = std::min(x, x ^ t);\n    }\n\
    \    return x;\n}\n\ntemplate <class T> bool add(std::vector<T>& b, T x) {\n \
    \   if (!(x = reduce(b, x))) return false;\n    int ind = 0;\n    while (ind <\
    \ (int)b.size() && b[ind] > x) ind++;\n    b.insert(b.begin() + ind, x);\n   \
    \ return true;\n}\n\nint main() {\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * full_reduce() does complete Gaussian\
    \ reduction\n * reduce() just does the things that are necessary, should be sufficient\n\
    \ */\n\nvoid full_reduce(std::vector<int>& b) {\n    int n = (int)b.size();\n\
    \    for (int i = n - 1; i >= 0; i--) {\n        for (int j = i - 1; j >= 0; j--)\
    \ {\n            b[j] = std::min(b[j], b[j] ^ b[i]);\n        }\n    }\n}\n\n\
    template <class T> T reduce(std::vector<T>& b, T x) {\n    for (auto& t : b) {\n\
    \        x = std::min(x, x ^ t);\n    }\n    return x;\n}\n\ntemplate <class T>\
    \ bool add(std::vector<T>& b, T x) {\n    if (!(x = reduce(b, x))) return false;\n\
    \    int ind = 0;\n    while (ind < (int)b.size() && b[ind] > x) ind++;\n    b.insert(b.begin()\
    \ + ind, x);\n    return true;\n}\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/xor_basis.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/xor_basis.cpp
layout: document
redirect_from:
- /library/library/numerical/xor_basis.cpp
- /library/library/numerical/xor_basis.cpp.html
title: library/numerical/xor_basis.cpp
---
