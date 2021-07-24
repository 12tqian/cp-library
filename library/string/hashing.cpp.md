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
  bundledCode: "#line 1 \"library/string/hashing.cpp\"\n#include <bits/stdc++.h>\n\
    \nnamespace Hashing {\n\nconst int MOD = 1e9 + 7;\n\nstd::mt19937 rng((uint32_t)\
    \ std::chrono::steady_clock::now().time_since_epoch().count());\nstd::uniform_int_distribution<int>\
    \ BDIST(0.1 * MOD, 0.9 * MOD);\nconst std::array<int, 2> base = {BDIST(rng), BDIST(rng)};\n\
    std::vector<std::array<int, 2>> pows = {{1, 1}};\n\nstd::array<int, 2> operator+(std::array<int,\
    \ 2> l, std::array<int, 2> r) {\n\tfor (int i = 0; i < 2; i++)\n\t\tif ((l[i]\
    \ += r[i]) >= MOD)\n\t\t\tl[i] -= MOD;\n\treturn l;\n}\n\nstd::array<int, 2> operator-(std::array<int,\
    \ 2> l, std::array<int, 2> r) {\n\tfor (int i = 0; i < 2; i++)\n\t\tif ((l[i]\
    \ -= r[i]) < 0)\n\t\t\tl[i] += MOD;\n\treturn l;\n}\n\nstd::array<int, 2> operator*(std::array<int,\
    \ 2> l, std::array<int, 2> r) {\n\tfor (int i = 0; i < 2; i++)\n\t\tl[i] = (long\
    \ long) l[i] * r[i] % MOD;\n\treturn l;\n}\n\nstd::array<int, 2> make_hash(char\
    \ c) {\n\treturn {c, c};\n}\n\nstruct HashRange {\n\tstd::vector<std::array<int,\
    \ 2>> pre = {{0, 0}};\n\tstd::string s;\n\n\tvoid add(char c) {\n\t\ts += c;\n\
    \t\tpre.push_back(base * pre.back() + make_hash(c));\n\t}\n\n\tvoid add(std::string\
    \ t) {\n\t\tfor (auto &c : t)\n\t\t\tadd(c);\n\t}\n\n\tvoid extend(int len) {\n\
    \t\twhile ((int)pows.size() <= len)\n\t\t\tpows.push_back(base * pows.back());\n\
    \t}\n\t\n\tstd::array<int, 2> hash(int l, int r) {\n\t\tint len = r + 1 - l;\n\
    \t\textend(len);\n\t\treturn pre[r + 1] - pows[len] * pre[l];\n\t}\n};\n\n} //\
    \ Hashing\n\nint main() {\n\tusing namespace std;\n\tusing namespace Hashing;\n\
    \tHashRange H;\n\tH.add(\"ababab\");\n\tfor (int i = 0; i < 6; i++) \n\t\tfor\
    \ (int j = i; j < 6; j++) {\n\t\t\tauto val = H.hash(i, j);\n\t\t\tcout << i <<\
    \ \" \" << j << \" \" << val[0] << \" \" << val[1] << '\\n';\n\t\t}\n}\n"
  code: "#include <bits/stdc++.h>\n\nnamespace Hashing {\n\nconst int MOD = 1e9 +\
    \ 7;\n\nstd::mt19937 rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\n\
    std::uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);\nconst std::array<int,\
    \ 2> base = {BDIST(rng), BDIST(rng)};\nstd::vector<std::array<int, 2>> pows =\
    \ {{1, 1}};\n\nstd::array<int, 2> operator+(std::array<int, 2> l, std::array<int,\
    \ 2> r) {\n\tfor (int i = 0; i < 2; i++)\n\t\tif ((l[i] += r[i]) >= MOD)\n\t\t\
    \tl[i] -= MOD;\n\treturn l;\n}\n\nstd::array<int, 2> operator-(std::array<int,\
    \ 2> l, std::array<int, 2> r) {\n\tfor (int i = 0; i < 2; i++)\n\t\tif ((l[i]\
    \ -= r[i]) < 0)\n\t\t\tl[i] += MOD;\n\treturn l;\n}\n\nstd::array<int, 2> operator*(std::array<int,\
    \ 2> l, std::array<int, 2> r) {\n\tfor (int i = 0; i < 2; i++)\n\t\tl[i] = (long\
    \ long) l[i] * r[i] % MOD;\n\treturn l;\n}\n\nstd::array<int, 2> make_hash(char\
    \ c) {\n\treturn {c, c};\n}\n\nstruct HashRange {\n\tstd::vector<std::array<int,\
    \ 2>> pre = {{0, 0}};\n\tstd::string s;\n\n\tvoid add(char c) {\n\t\ts += c;\n\
    \t\tpre.push_back(base * pre.back() + make_hash(c));\n\t}\n\n\tvoid add(std::string\
    \ t) {\n\t\tfor (auto &c : t)\n\t\t\tadd(c);\n\t}\n\n\tvoid extend(int len) {\n\
    \t\twhile ((int)pows.size() <= len)\n\t\t\tpows.push_back(base * pows.back());\n\
    \t}\n\t\n\tstd::array<int, 2> hash(int l, int r) {\n\t\tint len = r + 1 - l;\n\
    \t\textend(len);\n\t\treturn pre[r + 1] - pows[len] * pre[l];\n\t}\n};\n\n} //\
    \ Hashing\n\nint main() {\n\tusing namespace std;\n\tusing namespace Hashing;\n\
    \tHashRange H;\n\tH.add(\"ababab\");\n\tfor (int i = 0; i < 6; i++) \n\t\tfor\
    \ (int j = i; j < 6; j++) {\n\t\t\tauto val = H.hash(i, j);\n\t\t\tcout << i <<\
    \ \" \" << j << \" \" << val[0] << \" \" << val[1] << '\\n';\n\t\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/string/hashing.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/hashing.cpp
layout: document
redirect_from:
- /library/library/string/hashing.cpp
- /library/library/string/hashing.cpp.html
title: library/string/hashing.cpp
---
