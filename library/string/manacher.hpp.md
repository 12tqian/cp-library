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
  bundledCode: "\r\nstd::vector<int> manacher(std::string s) {\r\n\tstd::string t\
    \ = \"@\";\r\n\tfor (auto& c : s) \r\n\t\tt += c, t += '#';\r\n\tt.back() = '&';\r\
    \n\tstd::vector<int> res((int)t.size() - 1);\r\n\tint lo = 0, hi = 0;\r\n\tfor\
    \ (int i = 1; i < (int)t.size() - 1; i++) {\r\n\t\tif (i != 1)\r\n\t\t\tres[i]\
    \ = std::min(hi - i, res[hi - i + lo]);\r\n\t\twhile (t[i - res[i] - 1] == t[i\
    \ + res[i] + 1])\r\n\t\t\tres[i]++;\r\n\t\tif (i + res[i] > hi)\r\n\t\t\tlo =\
    \ i - res[i], hi = i + res[i];\r\n\t}\r\n\tres.erase(res.begin());\r\n\tfor (int\
    \ i = 0; i < (int)res.size(); i++)\r\n\t\tif ((i & 1) == (res[i] & 1))\r\n\t\t\
    \tres[i]++;\r\n\treturn res;\r\n}\n"
  code: "#pragma once\r\n\r\nstd::vector<int> manacher(std::string s) {\r\n\tstd::string\
    \ t = \"@\";\r\n\tfor (auto& c : s) \r\n\t\tt += c, t += '#';\r\n\tt.back() =\
    \ '&';\r\n\tstd::vector<int> res((int)t.size() - 1);\r\n\tint lo = 0, hi = 0;\r\
    \n\tfor (int i = 1; i < (int)t.size() - 1; i++) {\r\n\t\tif (i != 1)\r\n\t\t\t\
    res[i] = std::min(hi - i, res[hi - i + lo]);\r\n\t\twhile (t[i - res[i] - 1] ==\
    \ t[i + res[i] + 1])\r\n\t\t\tres[i]++;\r\n\t\tif (i + res[i] > hi)\r\n\t\t\t\
    lo = i - res[i], hi = i + res[i];\r\n\t}\r\n\tres.erase(res.begin());\r\n\tfor\
    \ (int i = 0; i < (int)res.size(); i++)\r\n\t\tif ((i & 1) == (res[i] & 1))\r\n\
    \t\t\tres[i]++;\r\n\treturn res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/string/manacher.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
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
