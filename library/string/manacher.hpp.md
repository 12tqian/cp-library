---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \treturn res;\n}\n\nint main() {\n\tstd::ios_base::sync_with_stdio(0);\n\tstd::string\
    \ s; std::cin >> s;\n\tstd::vector<int> ans = manacher(s);\n\tfor (int &x : ans)\n\
    \t\tstd::cout << x << \" \";\n\tstd::cout << '\\n';\n\treturn 0;\n}   \n"
  code: "#pragma once\n\n/**\n * Example use:\n * Call: manacher(\"abacaba\")\n *\
    \ Return: {1 0 3 0 1 0 7 0 1 0 3 0 1}\n */\n\nstd::vector<int> manacher(std::string\
    \ s) {\n\tstd::string t = \"@\";\n\tfor (auto &c : s) \n\t\tt += c, t += '#';\n\
    \tt.back() = '&';\n\tstd::vector<int> res((int)t.size() - 1);\n\tint lo = 0, hi\
    \ = 0;\n\tfor (int i = 1; i < (int)t.size() - 1; i++) {\n\t\tif (i != 1)\n\t\t\
    \tres[i] = std::min(hi - i, res[hi - i + lo]);\n\t\twhile (t[i - res[i] - 1] ==\
    \ t[i + res[i] + 1])\n\t\t\tres[i]++;\n\t\tif (i + res[i] > hi)\n\t\t\tlo = i\
    \ - res[i], hi = i + res[i];\n\t}\n\tres.erase(res.begin());\n\tfor (int i = 0;\
    \ i < (int)res.size(); i++)\n\t\tif ((i & 1) == (res[i] & 1))\n\t\t\tres[i]++;\n\
    \treturn res;\n}\n\nint main() {\n\tstd::ios_base::sync_with_stdio(0);\n\tstd::string\
    \ s; std::cin >> s;\n\tstd::vector<int> ans = manacher(s);\n\tfor (int &x : ans)\n\
    \t\tstd::cout << x << \" \";\n\tstd::cout << '\\n';\n\treturn 0;\n}   "
  dependsOn: []
  isVerificationFile: false
  path: library/string/manacher.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/manacher.hpp
layout: document
redirect_from:
- /library/library/string/manacher.hpp
- /library/library/string/manacher.hpp.html
title: library/string/manacher.hpp
---
