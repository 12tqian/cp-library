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
  bundledCode: "#include <bits/stdc++.h> \n\ntemplate <class T> class range_vector\
    \ : public std::vector<T> {\npublic:\n\tint min_index;\n\n\trange_vector() : min_index(0)\
    \ {}\n\n\trange_vector(int _min_index, int _max_index, T &&values = T())\n\t\t\
    : std::vector<T>(_max_index - _min_index + 1, values), min_index(_min_index) {\n\
    \t\tassert(_min_index <= _max_index + 1);\n\t}\n\t\n\trange_vector(int _max_index,\
    \ T &&values = T())\n\t\t: std::vector<T>(_max_index + 1, values), min_index(0)\
    \ {\n\t\tassert(0 <= _max_index + 1);\n\t}\n\t\n\tT& operator[](int i) { std::vector<T>\
    \ &self = *this; return self[i - min_index]; }\n};\n"
  code: "#include <bits/stdc++.h> \n\ntemplate <class T> class range_vector : public\
    \ std::vector<T> {\npublic:\n\tint min_index;\n\n\trange_vector() : min_index(0)\
    \ {}\n\n\trange_vector(int _min_index, int _max_index, T &&values = T())\n\t\t\
    : std::vector<T>(_max_index - _min_index + 1, values), min_index(_min_index) {\n\
    \t\tassert(_min_index <= _max_index + 1);\n\t}\n\t\n\trange_vector(int _max_index,\
    \ T &&values = T())\n\t\t: std::vector<T>(_max_index + 1, values), min_index(0)\
    \ {\n\t\tassert(0 <= _max_index + 1);\n\t}\n\t\n\tT& operator[](int i) { std::vector<T>\
    \ &self = *this; return self[i - min_index]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/range_vector.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/range_vector.cpp
layout: document
redirect_from:
- /library/library/misc/range_vector.cpp
- /library/library/misc/range_vector.cpp.html
title: library/misc/range_vector.cpp
---
