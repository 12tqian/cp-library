---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/string/hashing.hpp
    title: library/string/hashing.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links: []
  bundledCode: "#define IGNORE \"self tested\"\n\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n#include <deque>\n#include <iostream>\n#include\
    \ <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <unordered_map>\n#include <vector>\n\nusing namespace std;\n\nnamespace Hashing\
    \ {\n\nconst int MOD = 1e9 + 7;\n\nstd::mt19937 rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ \" \" << j << \" \" << val[0] << \" \" << val[1] << '\\n';\n\t\t}\n}\n"
  code: "#define IGNORE \"self tested\"\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n#include \"../../library/string/hashing.hpp\"\n\nint main() {\n\tusing namespace\
    \ std;\n\tusing namespace Hashing;\n\tHashRange H;\n\tH.add(\"ababab\");\n\tfor\
    \ (int i = 0; i < 6; i++) \n\t\tfor (int j = i; j < 6; j++) {\n\t\t\tauto val\
    \ = H.hash(i, j);\n\t\t\tcout << i << \" \" << j << \" \" << val[0] << \" \" <<\
    \ val[1] << '\\n';\n\t\t}\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/string/hashing.hpp
  isVerificationFile: true
  path: verify/unit-test/unit-test-hashing.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-hashing.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-hashing.test.cpp
- /verify/verify/unit-test/unit-test-hashing.test.cpp.html
title: verify/unit-test/unit-test-hashing.test.cpp
---
