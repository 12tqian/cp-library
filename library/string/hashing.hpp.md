---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-hashing.test.cpp
    title: verify/unit-test/unit-test-hashing.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nnamespace Hashing {\r\n\r\nconst int MOD = 1e9 + 7;\r\n\r\nstd::mt19937\
    \ rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\r\
    \nstd::uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);\r\nconst std::array<int,\
    \ 2> base = {BDIST(rng), BDIST(rng)};\r\nstd::vector<std::array<int, 2>> pows\
    \ = {{1, 1}};\r\n\r\nstd::array<int, 2> operator+(std::array<int, 2> l, std::array<int,\
    \ 2> r) {\r\n\tfor (int i = 0; i < 2; i++)\r\n\t\tif ((l[i] += r[i]) >= MOD)\r\
    \n\t\t\tl[i] -= MOD;\r\n\treturn l;\r\n}\r\n\r\nstd::array<int, 2> operator-(std::array<int,\
    \ 2> l, std::array<int, 2> r) {\r\n\tfor (int i = 0; i < 2; i++)\r\n\t\tif ((l[i]\
    \ -= r[i]) < 0)\r\n\t\t\tl[i] += MOD;\r\n\treturn l;\r\n}\r\n\r\nstd::array<int,\
    \ 2> operator*(std::array<int, 2> l, std::array<int, 2> r) {\r\n\tfor (int i =\
    \ 0; i < 2; i++)\r\n\t\tl[i] = (long long) l[i] * r[i] % MOD;\r\n\treturn l;\r\
    \n}\r\n\r\nstd::array<int, 2> make_hash(char c) {\r\n\treturn {c, c};\r\n}\r\n\
    \r\nstruct HashRange {\r\n\tstd::vector<std::array<int, 2>> pre = {{0, 0}};\r\n\
    \tstd::string s;\r\n\r\n\tvoid add(char c) {\r\n\t\ts += c;\r\n\t\tpre.push_back(base\
    \ * pre.back() + make_hash(c));\r\n\t}\r\n\r\n\tvoid add(std::string t) {\r\n\t\
    \tfor (auto& c : t)\r\n\t\t\tadd(c);\r\n\t}\r\n\r\n\tvoid extend(int len) {\r\n\
    \t\twhile ((int)pows.size() <= len)\r\n\t\t\tpows.push_back(base * pows.back());\r\
    \n\t}\r\n\t\r\n\tstd::array<int, 2> hash(int l, int r) {\r\n\t\tint len = r +\
    \ 1 - l;\r\n\t\textend(len);\r\n\t\treturn pre[r + 1] - pows[len] * pre[l];\r\n\
    \t}\r\n};\r\n\r\n} // Hashing\n"
  code: "#pragma once\r\n\r\nnamespace Hashing {\r\n\r\nconst int MOD = 1e9 + 7;\r\
    \n\r\nstd::mt19937 rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\r\
    \nstd::uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);\r\nconst std::array<int,\
    \ 2> base = {BDIST(rng), BDIST(rng)};\r\nstd::vector<std::array<int, 2>> pows\
    \ = {{1, 1}};\r\n\r\nstd::array<int, 2> operator+(std::array<int, 2> l, std::array<int,\
    \ 2> r) {\r\n\tfor (int i = 0; i < 2; i++)\r\n\t\tif ((l[i] += r[i]) >= MOD)\r\
    \n\t\t\tl[i] -= MOD;\r\n\treturn l;\r\n}\r\n\r\nstd::array<int, 2> operator-(std::array<int,\
    \ 2> l, std::array<int, 2> r) {\r\n\tfor (int i = 0; i < 2; i++)\r\n\t\tif ((l[i]\
    \ -= r[i]) < 0)\r\n\t\t\tl[i] += MOD;\r\n\treturn l;\r\n}\r\n\r\nstd::array<int,\
    \ 2> operator*(std::array<int, 2> l, std::array<int, 2> r) {\r\n\tfor (int i =\
    \ 0; i < 2; i++)\r\n\t\tl[i] = (long long) l[i] * r[i] % MOD;\r\n\treturn l;\r\
    \n}\r\n\r\nstd::array<int, 2> make_hash(char c) {\r\n\treturn {c, c};\r\n}\r\n\
    \r\nstruct HashRange {\r\n\tstd::vector<std::array<int, 2>> pre = {{0, 0}};\r\n\
    \tstd::string s;\r\n\r\n\tvoid add(char c) {\r\n\t\ts += c;\r\n\t\tpre.push_back(base\
    \ * pre.back() + make_hash(c));\r\n\t}\r\n\r\n\tvoid add(std::string t) {\r\n\t\
    \tfor (auto& c : t)\r\n\t\t\tadd(c);\r\n\t}\r\n\r\n\tvoid extend(int len) {\r\n\
    \t\twhile ((int)pows.size() <= len)\r\n\t\t\tpows.push_back(base * pows.back());\r\
    \n\t}\r\n\t\r\n\tstd::array<int, 2> hash(int l, int r) {\r\n\t\tint len = r +\
    \ 1 - l;\r\n\t\textend(len);\r\n\t\treturn pre[r + 1] - pows[len] * pre[l];\r\n\
    \t}\r\n};\r\n\r\n} // Hashing"
  dependsOn: []
  isVerificationFile: false
  path: library/string/hashing.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit-test/unit-test-hashing.test.cpp
documentation_of: library/string/hashing.hpp
layout: document
redirect_from:
- /library/library/string/hashing.hpp
- /library/library/string/hashing.hpp.html
title: library/string/hashing.hpp
---
