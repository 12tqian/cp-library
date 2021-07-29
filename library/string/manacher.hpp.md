---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-enumerate_palindromes.test.cpp
    title: verify/yosupo/yosupo-enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\n/**\n * Example use:\n * Call: manacher(\"abacaba\")\n * Return:\
    \ {1 0 3 0 1 0 7 0 1 0 3 0 1}\n */\n\nstd::vector<int> manacher(std::string s)\
    \ {\n\tstd::string t = \"@\";\n\tfor (auto &c : s) \n\t\tt += c, t += '#';\n\t\
    t.back() = '&';\n\tstd::vector<int> res((int)t.size() - 1);\n\tint lo = 0, hi\
    \ = 0;\n\tfor (int i = 1; i < (int)t.size() - 1; i++) {\n\t\tif (i != 1)\n\t\t\
    \tres[i] = std::min(hi - i, res[hi - i + lo]);\n\t\twhile (t[i - res[i] - 1] ==\
    \ t[i + res[i] + 1])\n\t\t\tres[i]++;\n\t\tif (i + res[i] > hi)\n\t\t\tlo = i\
    \ - res[i], hi = i + res[i];\n\t}\n\tres.erase(res.begin());\n\tfor (int i = 0;\
    \ i < (int)res.size(); i++)\n\t\tif ((i & 1) == (res[i] & 1))\n\t\t\tres[i]++;\n\
    \treturn res;\n}\n"
  code: "#pragma once\n\n/**\n * Example use:\n * Call: manacher(\"abacaba\")\n *\
    \ Return: {1 0 3 0 1 0 7 0 1 0 3 0 1}\n */\n\nstd::vector<int> manacher(std::string\
    \ s) {\n\tstd::string t = \"@\";\n\tfor (auto &c : s) \n\t\tt += c, t += '#';\n\
    \tt.back() = '&';\n\tstd::vector<int> res((int)t.size() - 1);\n\tint lo = 0, hi\
    \ = 0;\n\tfor (int i = 1; i < (int)t.size() - 1; i++) {\n\t\tif (i != 1)\n\t\t\
    \tres[i] = std::min(hi - i, res[hi - i + lo]);\n\t\twhile (t[i - res[i] - 1] ==\
    \ t[i + res[i] + 1])\n\t\t\tres[i]++;\n\t\tif (i + res[i] > hi)\n\t\t\tlo = i\
    \ - res[i], hi = i + res[i];\n\t}\n\tres.erase(res.begin());\n\tfor (int i = 0;\
    \ i < (int)res.size(); i++)\n\t\tif ((i & 1) == (res[i] & 1))\n\t\t\tres[i]++;\n\
    \treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/string/manacher.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:46:46-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-enumerate_palindromes.test.cpp
documentation_of: library/string/manacher.hpp
layout: document
redirect_from:
- /library/library/string/manacher.hpp
- /library/library/string/manacher.hpp.html
title: library/string/manacher.hpp
---
