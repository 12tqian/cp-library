---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/string/manacher.hpp
    title: library/string/manacher.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n/**\n * Example use:\n * Call: manacher(\"abacaba\")\n * Return: {1 0 3 0 1\
    \ 0 7 0 1 0 3 0 1}\n */\n\nstd::vector<int> manacher(std::string s) {\n\tstd::string\
    \ t = \"@\";\n\tfor (auto &c : s) \n\t\tt += c, t += '#';\n\tt.back() = '&';\n\
    \tstd::vector<int> res((int)t.size() - 1);\n\tint lo = 0, hi = 0;\n\tfor (int\
    \ i = 1; i < (int)t.size() - 1; i++) {\n\t\tif (i != 1)\n\t\t\tres[i] = std::min(hi\
    \ - i, res[hi - i + lo]);\n\t\twhile (t[i - res[i] - 1] == t[i + res[i] + 1])\n\
    \t\t\tres[i]++;\n\t\tif (i + res[i] > hi)\n\t\t\tlo = i - res[i], hi = i + res[i];\n\
    \t}\n\tres.erase(res.begin());\n\tfor (int i = 0; i < (int)res.size(); i++)\n\t\
    \tif ((i & 1) == (res[i] & 1))\n\t\t\tres[i]++;\n\treturn res;\n}\n\nint main()\
    \ {\n\tstd::ios_base::sync_with_stdio(0);\n\tstd::string s; std::cin >> s;\n\t\
    std::vector<int> ans = manacher(s);\n\tfor (int &x : ans)\n\t\tstd::cout << x\
    \ << \" \";\n\tstd::cout << '\\n';\n\treturn 0;\n}   \n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/string/manacher.hpp\"\
    \n\nint main() {\n\tstd::ios_base::sync_with_stdio(0);\n\tstd::string s; std::cin\
    \ >> s;\n\tstd::vector<int> ans = manacher(s);\n\tfor (int &x : ans)\n\t\tstd::cout\
    \ << x << \" \";\n\tstd::cout << '\\n';\n\treturn 0;\n}   "
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/string/manacher.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-enumerate_palindromes.test.cpp
- /verify/verify/yosupo/yosupo-enumerate_palindromes.test.cpp.html
title: verify/yosupo/yosupo-enumerate_palindromes.test.cpp
---
