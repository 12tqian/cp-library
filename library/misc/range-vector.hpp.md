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
  bundledCode: "\ntemplate <class T> class range_vector : public std::vector<T> {\n\
    public:\n\tint min_index;\n\n\trange_vector() : min_index(0) {}\n\n\trange_vector(int\
    \ _min_index, int _max_index, T&& values = T())\n\t\t: std::vector<T>(_max_index\
    \ - _min_index + 1, values), min_index(_min_index) {\n\t\tassert(_min_index <=\
    \ _max_index + 1);\n\t}\n\t\n\trange_vector(int _max_index, T&& values = T())\n\
    \t\t: std::vector<T>(_max_index + 1, values), min_index(0) {\n\t\tassert(0 <=\
    \ _max_index + 1);\n\t}\n\t\n\tT& operator[](int i) { std::vector<T>& self = *this;\
    \ return self[i - min_index]; }\n};\n"
  code: "#pragma once \n\ntemplate <class T> class range_vector : public std::vector<T>\
    \ {\npublic:\n\tint min_index;\n\n\trange_vector() : min_index(0) {}\n\n\trange_vector(int\
    \ _min_index, int _max_index, T&& values = T())\n\t\t: std::vector<T>(_max_index\
    \ - _min_index + 1, values), min_index(_min_index) {\n\t\tassert(_min_index <=\
    \ _max_index + 1);\n\t}\n\t\n\trange_vector(int _max_index, T&& values = T())\n\
    \t\t: std::vector<T>(_max_index + 1, values), min_index(0) {\n\t\tassert(0 <=\
    \ _max_index + 1);\n\t}\n\t\n\tT& operator[](int i) { std::vector<T>& self = *this;\
    \ return self[i - min_index]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/range-vector.hpp
  requiredBy: []
  timestamp: '2021-08-16 13:31:52-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1542E2.test.cpp
documentation_of: library/misc/range-vector.hpp
layout: document
redirect_from:
- /library/library/misc/range-vector.hpp
- /library/library/misc/range-vector.hpp.html
title: library/misc/range-vector.hpp
---
