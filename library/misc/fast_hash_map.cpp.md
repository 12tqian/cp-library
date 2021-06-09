---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/misc/fast_hash_map.cpp\"\n#include<bits/stdc++.h>\n\
    #include<bits/extc++.h>\n\nstruct splitmix64_hash {\n\tstatic uint64_t splitmix64(uint64_t\
    \ x) {\n\t\tx += 0x9e3779b97f4a7c15;\n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\t\treturn x ^ (x >> 31);\n\t}\n\
    \n\tsize_t operator()(uint64_t x) const {\n\t\tstatic const uint64_t FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n\t\treturn splitmix64(x\
    \ + FIXED_RANDOM);\n\t}\n};\n\ntemplate <typename K, typename V, typename Hash\
    \ = splitmix64_hash>\nusing hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;\n\
    \ntemplate <typename K, typename Hash = splitmix64_hash>\nusing hash_set = hash_map<K,\
    \ __gnu_pbds::null_type, Hash>;\n"
  code: "#include<bits/stdc++.h>\n#include<bits/extc++.h>\n\nstruct splitmix64_hash\
    \ {\n\tstatic uint64_t splitmix64(uint64_t x) {\n\t\tx += 0x9e3779b97f4a7c15;\n\
    \t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \t\treturn x ^ (x >> 31);\n\t}\n\n\tsize_t operator()(uint64_t x) const {\n\t\t\
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \t\treturn splitmix64(x + FIXED_RANDOM);\n\t}\n};\n\ntemplate <typename K, typename\
    \ V, typename Hash = splitmix64_hash>\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\n\ntemplate <typename K, typename Hash = splitmix64_hash>\nusing hash_set\
    \ = hash_map<K, __gnu_pbds::null_type, Hash>;"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast_hash_map.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/fast_hash_map.cpp
layout: document
redirect_from:
- /library/library/misc/fast_hash_map.cpp
- /library/library/misc/fast_hash_map.cpp.html
title: library/misc/fast_hash_map.cpp
---
