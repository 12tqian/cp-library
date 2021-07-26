---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/4/problem/A
    links:
    - https://codeforces.com/contest/4/problem/A
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/4/problem/A\"\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\t\n\tint\
    \ n;\n\tcin >> n;\n\n\tif (n > 2 && n % 2 == 0) {\n\t\tcout << \"YES\" << '\\\
    n';\n\t} else {\n\t\tcout << \"NO\" << '\\n';\n\t}\n\t\n\treturn 0; \n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/4/problem/A\"\n\n#include\
    \ \"../library/contest/template-minimal.hpp\"\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\t\n\tint n;\n\tcin >> n;\n\n\tif (n > 2 && n % 2 == 0) {\n\
    \t\tcout << \"YES\" << '\\n';\n\t} else {\n\t\tcout << \"NO\" << '\\n';\n\t}\n\
    \t\n\treturn 0; \n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  isVerificationFile: true
  path: test/watermelon.test.cpp
  requiredBy: []
  timestamp: '2021-07-25 21:09:56-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/watermelon.test.cpp
layout: document
redirect_from:
- /verify/test/watermelon.test.cpp
- /verify/test/watermelon.test.cpp.html
title: test/watermelon.test.cpp
---
