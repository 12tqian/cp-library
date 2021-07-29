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
  bundledCode: "#include <bits/extc++.h>\n\nstruct splitmix64_hash {\n\tstatic uint64_t\
    \ splitmix64(uint64_t x) {\n\t\tx += 0x9e3779b97f4a7c15;\n\t\tx = (x ^ (x >> 30))\
    \ * 0xbf58476d1ce4e5b9;\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\t\treturn\
    \ x ^ (x >> 31);\n\t}\n\n\tsize_t operator()(uint64_t x) const {\n\t\tstatic const\
    \ uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \t\treturn splitmix64(x + FIXED_RANDOM);\n\t}\n};\n\ntemplate <typename K, typename\
    \ V, typename Hash = splitmix64_hash>\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\n\ntemplate <typename K, typename Hash = splitmix64_hash>\nusing hash_set\
    \ = hash_map<K, __gnu_pbds::null_type, Hash>;\n"
  code: "#pragma once\n#include <bits/extc++.h>\n\nstruct splitmix64_hash {\n\tstatic\
    \ uint64_t splitmix64(uint64_t x) {\n\t\tx += 0x9e3779b97f4a7c15;\n\t\tx = (x\
    \ ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \t\treturn x ^ (x >> 31);\n\t}\n\n\tsize_t operator()(uint64_t x) const {\n\t\t\
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \t\treturn splitmix64(x + FIXED_RANDOM);\n\t}\n};\n\ntemplate <typename K, typename\
    \ V, typename Hash = splitmix64_hash>\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\n\ntemplate <typename K, typename Hash = splitmix64_hash>\nusing hash_set\
    \ = hash_map<K, __gnu_pbds::null_type, Hash>;"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast-hash-map.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
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
