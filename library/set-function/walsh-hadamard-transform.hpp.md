---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class T> \nvoid walsh_hadamard_transformation(std::vector<T>&\
    \ f, bool inverse = false) {\n\tint n = (int)f.size();\n\tfor (int i = 1; i <\
    \ n; i <<= 1) {\n\t\tfor (int j = 0; j < n; ++j) {\n\t\t\tif ((j & i) == 0) {\n\
    \t\t\t\tT x = f[j], y = f[j | i];\n\t\t\t\tf[j] = x + y;\n\t\t\t\tf[j | i] = x\
    \ - y;\n\t\t\t}\n\t\t}\n\t}\n\tif (inverse) {\n\t\tif constexpr(std::is_integral<T>::value)\
    \ {\n\t\t\tfor (auto& x : f) x /= n;\n\t\t} else {\n\t\t\tT divide = T(1) / T(f.size());\n\
    \t\t\tfor (auto& x : f) x *= divide;\n\t\t}\n\t}\n}\n"
  code: "#pragma once\n\ntemplate <class T> \nvoid walsh_hadamard_transformation(std::vector<T>&\
    \ f, bool inverse = false) {\n\tint n = (int)f.size();\n\tfor (int i = 1; i <\
    \ n; i <<= 1) {\n\t\tfor (int j = 0; j < n; ++j) {\n\t\t\tif ((j & i) == 0) {\n\
    \t\t\t\tT x = f[j], y = f[j | i];\n\t\t\t\tf[j] = x + y;\n\t\t\t\tf[j | i] = x\
    \ - y;\n\t\t\t}\n\t\t}\n\t}\n\tif (inverse) {\n\t\tif constexpr(std::is_integral<T>::value)\
    \ {\n\t\t\tfor (auto& x : f) x /= n;\n\t\t} else {\n\t\t\tT divide = T(1) / T(f.size());\n\
    \t\t\tfor (auto& x : f) x *= divide;\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/set-function/walsh-hadamard-transform.hpp
  requiredBy: []
  timestamp: '2021-08-05 23:40:55-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/set-function/walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/library/set-function/walsh-hadamard-transform.hpp
- /library/library/set-function/walsh-hadamard-transform.hpp.html
title: library/set-function/walsh-hadamard-transform.hpp
---
