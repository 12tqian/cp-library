---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1299D.test.cpp
    title: verify/codeforces/codeforces-1299D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nvoid full_reduce(std::vector<int>& b) {\n\tint n = (int)b.size();\n\
    \tfor (int i = n - 1; i >= 0; i--) {\n\t\tfor (int j = i - 1; j >= 0; j--) {\n\
    \t\t\tb[j] = std::min(b[j], b[j] ^ b[i]);\n\t\t}\n\t}\n}\n\ntemplate <class T>\
    \ T reduce(std::vector<T>& b, T x) {\n\tfor (auto& t : b) {\n\t\tx = std::min(x,\
    \ x ^ t);\n\t}\n\treturn x;\n}\n\ntemplate <class T> bool add(std::vector<T>&\
    \ b, T x) {\n\tif (!(x = reduce(b, x))) return false;\n\tint ind = 0;\n\twhile\
    \ (ind < (int)b.size() && b[ind] > x) ind++;\n\tb.insert(b.begin() + ind, x);\n\
    \treturn true;\n}\n"
  code: "#pragma once\n\nvoid full_reduce(std::vector<int>& b) {\n\tint n = (int)b.size();\n\
    \tfor (int i = n - 1; i >= 0; i--) {\n\t\tfor (int j = i - 1; j >= 0; j--) {\n\
    \t\t\tb[j] = std::min(b[j], b[j] ^ b[i]);\n\t\t}\n\t}\n}\n\ntemplate <class T>\
    \ T reduce(std::vector<T>& b, T x) {\n\tfor (auto& t : b) {\n\t\tx = std::min(x,\
    \ x ^ t);\n\t}\n\treturn x;\n}\n\ntemplate <class T> bool add(std::vector<T>&\
    \ b, T x) {\n\tif (!(x = reduce(b, x))) return false;\n\tint ind = 0;\n\twhile\
    \ (ind < (int)b.size() && b[ind] > x) ind++;\n\tb.insert(b.begin() + ind, x);\n\
    \treturn true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/xor-basis.hpp
  requiredBy: []
  timestamp: '2021-08-13 01:29:17-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1299D.test.cpp
documentation_of: library/numerical/xor-basis.hpp
layout: document
title: XOR Basis
---

## XOR Basis

### Functions
- `full_reduce(b)`: Full Gaussian elimination on everything. 
- `reduce(b)`: Just reduces enough to work. 
- `add(b, x)`: Adds $x$ to a basis $b$. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/numerical/Matrix%20(11.3)/XorBasis.h)
