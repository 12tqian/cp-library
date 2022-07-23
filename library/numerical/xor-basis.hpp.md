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
  bundledCode: "\r\nvoid full_reduce(std::vector<int>& b) {\r\n\tint n = (int)b.size();\r\
    \n\tfor (int i = n - 1; i >= 0; i--) {\r\n\t\tfor (int j = i - 1; j >= 0; j--)\
    \ {\r\n\t\t\tb[j] = std::min(b[j], b[j] ^ b[i]);\r\n\t\t}\r\n\t}\r\n}\r\n\r\n\
    template <class T> T reduce(std::vector<T>& b, T x) {\r\n\tfor (auto& t : b) {\r\
    \n\t\tx = std::min(x, x ^ t);\r\n\t}\r\n\treturn x;\r\n}\r\n\r\ntemplate <class\
    \ T> bool add(std::vector<T>& b, T x) {\r\n\tif (!(x = reduce(b, x))) return false;\r\
    \n\tint ind = 0;\r\n\twhile (ind < (int)b.size() && b[ind] > x) ind++;\r\n\tb.insert(b.begin()\
    \ + ind, x);\r\n\treturn true;\r\n}\n"
  code: "#pragma once\r\n\r\nvoid full_reduce(std::vector<int>& b) {\r\n\tint n =\
    \ (int)b.size();\r\n\tfor (int i = n - 1; i >= 0; i--) {\r\n\t\tfor (int j = i\
    \ - 1; j >= 0; j--) {\r\n\t\t\tb[j] = std::min(b[j], b[j] ^ b[i]);\r\n\t\t}\r\n\
    \t}\r\n}\r\n\r\ntemplate <class T> T reduce(std::vector<T>& b, T x) {\r\n\tfor\
    \ (auto& t : b) {\r\n\t\tx = std::min(x, x ^ t);\r\n\t}\r\n\treturn x;\r\n}\r\n\
    \r\ntemplate <class T> bool add(std::vector<T>& b, T x) {\r\n\tif (!(x = reduce(b,\
    \ x))) return false;\r\n\tint ind = 0;\r\n\twhile (ind < (int)b.size() && b[ind]\
    \ > x) ind++;\r\n\tb.insert(b.begin() + ind, x);\r\n\treturn true;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/xor-basis.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
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
