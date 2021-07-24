---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n\n/**\n * full_reduce() does complete Gaussian\
    \ reduction\n * reduce() just does the things that are necessary, should be sufficient\n\
    \ */\n\nvoid full_reduce(std::vector<int> &b) {\n\tint n = (int)b.size();\n\t\
    for (int i = n - 1; i >= 0; i--) {\n\t\tfor (int j = i - 1; j >= 0; j--) {\n\t\
    \t\tb[j] = std::min(b[j], b[j] ^ b[i]);\n\t\t}\n\t}\n}\n\ntemplate <class T> T\
    \ reduce(std::vector<T> &b, T x) {\n\tfor (auto &t : b) {\n\t\tx = std::min(x,\
    \ x ^ t);\n\t}\n\treturn x;\n}\n\ntemplate <class T> bool add(std::vector<T> &b,\
    \ T x) {\n\tif (!(x = reduce(b, x))) return false;\n\tint ind = 0;\n\twhile (ind\
    \ < (int)b.size() && b[ind] > x) ind++;\n\tb.insert(b.begin() + ind, x);\n\treturn\
    \ true;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * full_reduce() does complete Gaussian\
    \ reduction\n * reduce() just does the things that are necessary, should be sufficient\n\
    \ */\n\nvoid full_reduce(std::vector<int> &b) {\n\tint n = (int)b.size();\n\t\
    for (int i = n - 1; i >= 0; i--) {\n\t\tfor (int j = i - 1; j >= 0; j--) {\n\t\
    \t\tb[j] = std::min(b[j], b[j] ^ b[i]);\n\t\t}\n\t}\n}\n\ntemplate <class T> T\
    \ reduce(std::vector<T> &b, T x) {\n\tfor (auto &t : b) {\n\t\tx = std::min(x,\
    \ x ^ t);\n\t}\n\treturn x;\n}\n\ntemplate <class T> bool add(std::vector<T> &b,\
    \ T x) {\n\tif (!(x = reduce(b, x))) return false;\n\tint ind = 0;\n\twhile (ind\
    \ < (int)b.size() && b[ind] > x) ind++;\n\tb.insert(b.begin() + ind, x);\n\treturn\
    \ true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/xor_basis.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/xor_basis.cpp
layout: document
redirect_from:
- /library/library/numerical/xor_basis.cpp
- /library/library/numerical/xor_basis.cpp.html
title: library/numerical/xor_basis.cpp
---
