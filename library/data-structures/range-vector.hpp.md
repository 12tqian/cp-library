---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1542E2.test.cpp
    title: verify/codeforces/codeforces-1542E2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> class range_vector : public std::vector<T>\
    \ {\r\npublic:\r\n\tint min_index;\r\n\r\n\trange_vector() : min_index(0) {}\r\
    \n\r\n\trange_vector(int _min_index, int _max_index, T&& values = T())\r\n\t\t\
    : std::vector<T>(_max_index - _min_index + 1, values), min_index(_min_index) {\r\
    \n\t\tassert(_min_index <= _max_index + 1);\r\n\t}\r\n\t\r\n\trange_vector(int\
    \ _max_index, T&& values = T())\r\n\t\t: std::vector<T>(_max_index + 1, values),\
    \ min_index(0) {\r\n\t\tassert(0 <= _max_index + 1);\r\n\t}\r\n\t\r\n\tT& operator[](int\
    \ i) { std::vector<T>& self = *this; return self[i - min_index]; }\r\n};\r\n"
  code: "#pragma once \r\n\r\ntemplate <class T> class range_vector : public std::vector<T>\
    \ {\r\npublic:\r\n\tint min_index;\r\n\r\n\trange_vector() : min_index(0) {}\r\
    \n\r\n\trange_vector(int _min_index, int _max_index, T&& values = T())\r\n\t\t\
    : std::vector<T>(_max_index - _min_index + 1, values), min_index(_min_index) {\r\
    \n\t\tassert(_min_index <= _max_index + 1);\r\n\t}\r\n\t\r\n\trange_vector(int\
    \ _max_index, T&& values = T())\r\n\t\t: std::vector<T>(_max_index + 1, values),\
    \ min_index(0) {\r\n\t\tassert(0 <= _max_index + 1);\r\n\t}\r\n\t\r\n\tT& operator[](int\
    \ i) { std::vector<T>& self = *this; return self[i - min_index]; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/range-vector.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1542E2.test.cpp
documentation_of: library/data-structures/range-vector.hpp
layout: document
redirect_from:
- /library/library/data-structures/range-vector.hpp
- /library/library/data-structures/range-vector.hpp.html
title: library/data-structures/range-vector.hpp
---
