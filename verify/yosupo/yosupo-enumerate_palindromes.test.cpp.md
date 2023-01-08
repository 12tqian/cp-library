---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/string/manacher.hpp
    title: library/string/manacher.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nstd::vector<int> manacher(std::string\
    \ s) {\r\n\tstd::string t = \"@\";\r\n\tfor (auto& c : s) \r\n\t\tt += c, t +=\
    \ '#';\r\n\tt.back() = '&';\r\n\tstd::vector<int> res((int)t.size() - 1);\r\n\t\
    int lo = 0, hi = 0;\r\n\tfor (int i = 1; i < (int)t.size() - 1; i++) {\r\n\t\t\
    if (i != 1)\r\n\t\t\tres[i] = std::min(hi - i, res[hi - i + lo]);\r\n\t\twhile\
    \ (t[i - res[i] - 1] == t[i + res[i] + 1])\r\n\t\t\tres[i]++;\r\n\t\tif (i + res[i]\
    \ > hi)\r\n\t\t\tlo = i - res[i], hi = i + res[i];\r\n\t}\r\n\tres.erase(res.begin());\r\
    \n\tfor (int i = 0; i < (int)res.size(); i++)\r\n\t\tif ((i & 1) == (res[i] &\
    \ 1))\r\n\t\t\tres[i]++;\r\n\treturn res;\r\n}\n\r\nint main() {\r\n\tstd::ios_base::sync_with_stdio(0);\r\
    \n\tstd::string s; std::cin >> s;\r\n\tstd::vector<int> ans = manacher(s);\r\n\
    \tfor (int &x : ans)\r\n\t\tstd::cout << x << \" \";\r\n\tstd::cout << '\\n';\r\
    \n\treturn 0;\r\n}   \n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/string/manacher.hpp\"\r\n\r\nint main() {\r\n\tstd::ios_base::sync_with_stdio(0);\r\
    \n\tstd::string s; std::cin >> s;\r\n\tstd::vector<int> ans = manacher(s);\r\n\
    \tfor (int &x : ans)\r\n\t\tstd::cout << x << \" \";\r\n\tstd::cout << '\\n';\r\
    \n\treturn 0;\r\n}   "
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/string/manacher.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-enumerate_palindromes.test.cpp
- /verify/verify/yosupo/yosupo-enumerate_palindromes.test.cpp.html
title: verify/yosupo/yosupo-enumerate_palindromes.test.cpp
---
