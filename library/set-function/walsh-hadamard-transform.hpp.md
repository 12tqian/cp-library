---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
    title: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> \r\nvoid walsh_hadamard_transformation(std::vector<T>&\
    \ f, bool inverse = false) {\r\n\tint n = (int)f.size();\r\n\tfor (int i = 1;\
    \ i < n; i <<= 1) {\r\n\t\tfor (int j = 0; j < n; ++j) {\r\n\t\t\tif ((j & i)\
    \ == 0) {\r\n\t\t\t\tT x = f[j], y = f[j | i];\r\n\t\t\t\tf[j] = x + y;\r\n\t\t\
    \t\tf[j | i] = x - y;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tif (inverse) {\r\n\t\tif\
    \ constexpr(std::is_integral<T>::value) {\r\n\t\t\tfor (auto& x : f) x /= n;\r\
    \n\t\t} else {\r\n\t\t\tT divide = T(1) / T(f.size());\r\n\t\t\tfor (auto& x :\
    \ f) x *= divide;\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate <class T> \r\nvoid walsh_hadamard_transformation(std::vector<T>&\
    \ f, bool inverse = false) {\r\n\tint n = (int)f.size();\r\n\tfor (int i = 1;\
    \ i < n; i <<= 1) {\r\n\t\tfor (int j = 0; j < n; ++j) {\r\n\t\t\tif ((j & i)\
    \ == 0) {\r\n\t\t\t\tT x = f[j], y = f[j | i];\r\n\t\t\t\tf[j] = x + y;\r\n\t\t\
    \t\tf[j | i] = x - y;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tif (inverse) {\r\n\t\tif\
    \ constexpr(std::is_integral<T>::value) {\r\n\t\t\tfor (auto& x : f) x /= n;\r\
    \n\t\t} else {\r\n\t\t\tT divide = T(1) / T(f.size());\r\n\t\t\tfor (auto& x :\
    \ f) x *= divide;\r\n\t\t}\r\n\t}\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/set-function/walsh-hadamard-transform.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
documentation_of: library/set-function/walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/library/set-function/walsh-hadamard-transform.hpp
- /library/library/set-function/walsh-hadamard-transform.hpp.html
title: library/set-function/walsh-hadamard-transform.hpp
---
