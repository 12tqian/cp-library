---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/string/manacher.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * Example use:\n * Call: manacher(\"abacaba\")\n * Return: {1 0 3 0 1\
    \ 0 7 0 1 0 3 0 1}\n */\n\nstd::vector<int> manacher(std::string s) {\n    std::string\
    \ t = \"@\";\n    for (auto& c : s) \n        t += c, t += '#';\n    t.back()\
    \ = '&';\n    std::vector<int> res((int) t.size() - 1);\n    int lo = 0, hi =\
    \ 0;\n    for (int i = 1; i < (int) t.size() - 1; i++) {\n        if (i != 1)\n\
    \            res[i] = std::min(hi - i, res[hi - i + lo]);\n        while (t[i\
    \ - res[i] - 1] == t[i + res[i] + 1])\n            res[i]++;\n        if (i +\
    \ res[i] > hi)\n            lo = i - res[i], hi = i + res[i];\n    }\n    res.erase(res.begin());\n\
    \    for (int i = 0; i < (int) res.size(); i++)\n        if ((i & 1) == (res[i]\
    \ & 1))\n            res[i]++;\n    return res;\n}\n\nint main() {\n    std::ios_base::sync_with_stdio(0);\n\
    \    std::string s; std::cin >> s;\n    std::vector<int> ans = manacher(s);\n\
    \    for (int& x : ans)\n        std::cout << x << \" \";\n    std::cout << '\\\
    n';\n    return 0;\n}   \n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Example use:\n * Call: manacher(\"abacaba\"\
    )\n * Return: {1 0 3 0 1 0 7 0 1 0 3 0 1}\n */\n\nstd::vector<int> manacher(std::string\
    \ s) {\n    std::string t = \"@\";\n    for (auto& c : s) \n        t += c, t\
    \ += '#';\n    t.back() = '&';\n    std::vector<int> res((int) t.size() - 1);\n\
    \    int lo = 0, hi = 0;\n    for (int i = 1; i < (int) t.size() - 1; i++) {\n\
    \        if (i != 1)\n            res[i] = std::min(hi - i, res[hi - i + lo]);\n\
    \        while (t[i - res[i] - 1] == t[i + res[i] + 1])\n            res[i]++;\n\
    \        if (i + res[i] > hi)\n            lo = i - res[i], hi = i + res[i];\n\
    \    }\n    res.erase(res.begin());\n    for (int i = 0; i < (int) res.size();\
    \ i++)\n        if ((i & 1) == (res[i] & 1))\n            res[i]++;\n    return\
    \ res;\n}\n\nint main() {\n    std::ios_base::sync_with_stdio(0);\n    std::string\
    \ s; std::cin >> s;\n    std::vector<int> ans = manacher(s);\n    for (int& x\
    \ : ans)\n        std::cout << x << \" \";\n    std::cout << '\\n';\n    return\
    \ 0;\n}   "
  dependsOn: []
  isVerificationFile: false
  path: library/string/manacher.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/manacher.cpp
layout: document
redirect_from:
- /library/library/string/manacher.cpp
- /library/library/string/manacher.cpp.html
title: library/string/manacher.cpp
---
