---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/string/hashing.cpp\"\n#include <bits/stdc++.h>\n\
    \nnamespace Hashing {\n\nconst int MOD = 1e9 + 7;\nstd::mt19937 rng((uint32_t)\
    \ std::chrono::steady_clock::now().time_since_epoch().count());\nstd::uniform_int_distribution<int>\
    \ BDIST(0.1 * MOD, 0.9 * MOD);\nconst std::array<int, 2> base = {BDIST(rng), BDIST(rng)};\n\
    std::vector<std::array<int, 2>> pows = {{1, 1}};\n\nstd::array<int, 2> operator\
    \ + (std::array<int, 2> l, std::array<int, 2> r) {\n    for (int i = 0; i < 2;\
    \ i++)\n        if ((l[i] += r[i]) >= MOD)\n            l[i] -= MOD;\n    return\
    \ l;\n}\nstd::array<int, 2> operator - (std::array<int, 2> l, std::array<int,\
    \ 2> r) {\n    for (int i = 0; i < 2; i++)\n        if ((l[i] -= r[i]) < 0)\n\
    \            l[i] += MOD;\n    return l;\n}\nstd::array<int, 2> operator * (std::array<int,\
    \ 2> l, std::array<int, 2> r) {\n    for (int i = 0; i < 2; i++)\n        l[i]\
    \ = (long long) l[i] * r[i] % MOD;\n    return l;\n}\nstd::array<int, 2> make_hash(char\
    \ c) {\n    return {c, c};\n}\nstruct HashRange {\n    std::vector<std::array<int,\
    \ 2>> pre = {{0, 0}};\n    std::string s;\n    void add(char c) {\n        s +=\
    \ c;\n        pre.push_back(base * pre.back() + make_hash(c));\n    }\n    void\
    \ add(std::string t) {\n        for (auto& c : t)\n            add(c);\n    }\n\
    \    void extend(int len) {\n        while ((int) pows.size() <= len)\n      \
    \      pows.push_back(base * pows.back());\n    }\n    std::array<int, 2> hash(int\
    \ l, int r) {\n        int len = r + 1 - l;\n        extend(len);\n        return\
    \ pre[r + 1] - pows[len] * pre[l];\n    }\n};\n\n} // Hashing\n\nint main() {\n\
    \    using namespace std;\n    using namespace Hashing;\n    HashRange H;\n  \
    \  H.add(\"ababab\");\n    for (int i = 0; i < 6; i++) \n        for (int j =\
    \ i; j < 6; j++) {\n            auto val = H.hash(i, j);\n            cout <<\
    \ i << \" \" << j << \" \" << val[0] << \" \" << val[1] << '\\n';\n        }\n\
    }\n"
  code: "#include <bits/stdc++.h>\n\nnamespace Hashing {\n\nconst int MOD = 1e9 +\
    \ 7;\nstd::mt19937 rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\n\
    std::uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);\nconst std::array<int,\
    \ 2> base = {BDIST(rng), BDIST(rng)};\nstd::vector<std::array<int, 2>> pows =\
    \ {{1, 1}};\n\nstd::array<int, 2> operator + (std::array<int, 2> l, std::array<int,\
    \ 2> r) {\n    for (int i = 0; i < 2; i++)\n        if ((l[i] += r[i]) >= MOD)\n\
    \            l[i] -= MOD;\n    return l;\n}\nstd::array<int, 2> operator - (std::array<int,\
    \ 2> l, std::array<int, 2> r) {\n    for (int i = 0; i < 2; i++)\n        if ((l[i]\
    \ -= r[i]) < 0)\n            l[i] += MOD;\n    return l;\n}\nstd::array<int, 2>\
    \ operator * (std::array<int, 2> l, std::array<int, 2> r) {\n    for (int i =\
    \ 0; i < 2; i++)\n        l[i] = (long long) l[i] * r[i] % MOD;\n    return l;\n\
    }\nstd::array<int, 2> make_hash(char c) {\n    return {c, c};\n}\nstruct HashRange\
    \ {\n    std::vector<std::array<int, 2>> pre = {{0, 0}};\n    std::string s;\n\
    \    void add(char c) {\n        s += c;\n        pre.push_back(base * pre.back()\
    \ + make_hash(c));\n    }\n    void add(std::string t) {\n        for (auto& c\
    \ : t)\n            add(c);\n    }\n    void extend(int len) {\n        while\
    \ ((int) pows.size() <= len)\n            pows.push_back(base * pows.back());\n\
    \    }\n    std::array<int, 2> hash(int l, int r) {\n        int len = r + 1 -\
    \ l;\n        extend(len);\n        return pre[r + 1] - pows[len] * pre[l];\n\
    \    }\n};\n\n} // Hashing\n\nint main() {\n    using namespace std;\n    using\
    \ namespace Hashing;\n    HashRange H;\n    H.add(\"ababab\");\n    for (int i\
    \ = 0; i < 6; i++) \n        for (int j = i; j < 6; j++) {\n            auto val\
    \ = H.hash(i, j);\n            cout << i << \" \" << j << \" \" << val[0] << \"\
    \ \" << val[1] << '\\n';\n        }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/string/hashing.cpp
  requiredBy: []
  timestamp: '2020-12-30 23:03:50-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/hashing.cpp
layout: document
redirect_from:
- /library/library/string/hashing.cpp
- /library/library/string/hashing.cpp.html
title: library/string/hashing.cpp
---
