---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/4/problem/A
    links:
    - https://codeforces.com/contest/4/problem/A
  bundledCode: "\t#define PROBLEM \"https://codeforces.com/contest/4/problem/A\"\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n\tint main() {\n\t\tios::sync_with_stdio(false);\n\t\tcin.tie(nullptr);\n\t\t\
    int n;\n\t\tcin >> n;\n\t\tif (n > 2 && n % 2 == 0) {\n\t\t\tcout << \"YES\" <<\
    \ '\\n';\n\t\t} else {\n\t\t\tcout << \"NO\" << '\\n';\n\t\t}\n\t\treturn 0; \n\
    \t}\n"
  code: "\t#define PROBLEM \"https://codeforces.com/contest/4/problem/A\"\n\n\t#include\
    \ \"../library/contest/template-minimal.hpp\"\n\n\tint main() {\n\t\tios::sync_with_stdio(false);\n\
    \t\tcin.tie(nullptr);\n\t\tint n;\n\t\tcin >> n;\n\t\tif (n > 2 && n % 2 == 0)\
    \ {\n\t\t\tcout << \"YES\" << '\\n';\n\t\t} else {\n\t\t\tcout << \"NO\" << '\\\
    n';\n\t\t}\n\t\treturn 0; \n\t}"
  dependsOn:
  - library/contest/template-minimal.hpp
  isVerificationFile: true
  path: test/watermelon.test.cpp
  requiredBy: []
  timestamp: '2021-07-25 20:47:37-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/watermelon.test.cpp
layout: document
redirect_from:
- /verify/test/watermelon.test.cpp
- /verify/test/watermelon.test.cpp.html
title: test/watermelon.test.cpp
---
