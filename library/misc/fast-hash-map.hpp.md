---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1553G.test.cpp
    title: verify/codeforces/codeforces-1553G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <bits/extc++.h>\r\n\r\nstruct splitmix64_hash {\r\n\tstatic\
    \ uint64_t splitmix64(uint64_t x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\tx =\
    \ (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n\t\treturn x ^ (x >> 31);\r\n\t}\r\n\r\n\tsize_t operator()(uint64_t x) const\
    \ {\r\n\t\tstatic const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\ntemplate <typename\
    \ K, typename V, typename Hash = splitmix64_hash>\r\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\r\n\r\ntemplate <typename K, typename Hash = splitmix64_hash>\r\n\
    using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;\n"
  code: "#pragma once\r\n#include <bits/extc++.h>\r\n\r\nstruct splitmix64_hash {\r\
    \n\tstatic uint64_t splitmix64(uint64_t x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\
    \n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n\t\treturn x ^ (x >> 31);\r\n\t}\r\n\r\n\tsize_t operator()(uint64_t x) const\
    \ {\r\n\t\tstatic const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\ntemplate <typename\
    \ K, typename V, typename Hash = splitmix64_hash>\r\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\r\n\r\ntemplate <typename K, typename Hash = splitmix64_hash>\r\n\
    using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast-hash-map.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1553G.test.cpp
documentation_of: library/misc/fast-hash-map.hpp
layout: document
redirect_from:
- /library/library/misc/fast-hash-map.hpp
- /library/library/misc/fast-hash-map.hpp.html
title: library/misc/fast-hash-map.hpp
---
