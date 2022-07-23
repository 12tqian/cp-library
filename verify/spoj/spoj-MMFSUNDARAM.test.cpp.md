---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/number-theory/sieve.hpp
    title: library/number-theory/sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.spoj.com/problems/MMFSUNDARAM/
    links:
    - https://www.spoj.com/problems/MMFSUNDARAM/
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/MMFSUNDARAM/\"\r\n\
    \r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <int SZ> struct\
    \ Sieve {\r\n\tstd::bitset<SZ> pri;\r\n\tstd::vector<int> pr;\r\n\t\r\n\tSieve()\
    \ {\r\n\t\tpri.set();\r\n\t\tpri[0] = pri[1] = 0;\r\n\t\tfor (int i = 4; i < SZ;\
    \ i += 2) {\r\n\t\t\tpri[i] = 0;\r\n\t\t}\r\n\t\tfor (int i = 3; i * i < SZ; i\
    \ += 2) {\r\n\t\t\tif (pri[i]) {\r\n\t\t\t\tfor (int j = i * i; j < SZ; j += 2\
    \ * i) {\r\n\t\t\t\t\tpri[j] = 0;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor\
    \ (int i = 0; i < SZ; i++) {\r\n\t\t\tif (pri[i]) {\r\n\t\t\t\tpr.push_back(i);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\n\r\nconst int N = 1e5 + 5;\r\n\r\nSieve<N> sieve;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\
    \tint n;\r\n\tcin >> n;\r\n\tfor (int x : sieve.pr) {\r\n\t\tif (x <= n) {\r\n\
    \t\t\tcout << x << ' ';\r\n\t\t} else {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t}\r\n\t\
    cout << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/MMFSUNDARAM/\"\r\n\r\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/number-theory/sieve.hpp\"\
    \r\n\r\nconst int N = 1e5 + 5;\r\n\r\nSieve<N> sieve;\r\n\r\nint main() {\r\n\t\
    ios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n;\r\n\tcin >> n;\r\
    \n\tfor (int x : sieve.pr) {\r\n\t\tif (x <= n) {\r\n\t\t\tcout << x << ' ';\r\
    \n\t\t} else {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t}\r\n\tcout << '\\n';\r\n\treturn\
    \ 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/sieve.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-MMFSUNDARAM.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-MMFSUNDARAM.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-MMFSUNDARAM.test.cpp
- /verify/verify/spoj/spoj-MMFSUNDARAM.test.cpp.html
title: verify/spoj/spoj-MMFSUNDARAM.test.cpp
---
