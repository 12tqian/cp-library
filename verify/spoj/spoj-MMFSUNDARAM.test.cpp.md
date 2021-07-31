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
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/MMFSUNDARAM/\"\n\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <int SZ> struct Sieve {\n\tstd::bitset<SZ> pri;\n\tstd::vector<int>\
    \ pr;\n\t\n\tSieve() {\n\t\tpri.set();\n\t\tpri[0] = pri[1] = 0;\n\t\tfor (int\
    \ i = 4; i < SZ; i += 2) {\n\t\t\tpri[i] = 0;\n\t\t}\n\t\tfor (int i = 3; i *\
    \ i < SZ; i += 2) {\n\t\t\tif (pri[i]) {\n\t\t\t\tfor (int j = i * i; j < SZ;\
    \ j += 2 * i) {\n\t\t\t\t\tpri[j] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (int\
    \ i = 0; i < SZ; i++) {\n\t\t\tif (pri[i]) {\n\t\t\t\tpr.push_back(i);\n\t\t\t\
    }\n\t\t}\n\t}\n};\n\nconst int N = 1e5 + 5;\n\nSieve<N> sieve;\n\nint main() {\n\
    \tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n;\n\tcin >> n;\n\t\
    for (int x : sieve.pr) {\n\t\tif (x <= n) {\n\t\t\tcout << x << ' ';\n\t\t} else\
    \ {\n\t\t\tbreak;\n\t\t}\n\t}\n\tcout << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/MMFSUNDARAM/\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/number-theory/sieve.hpp\"\
    \n\nconst int N = 1e5 + 5;\n\nSieve<N> sieve;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n;\n\tcin >> n;\n\tfor (int x : sieve.pr) {\n\t\tif\
    \ (x <= n) {\n\t\t\tcout << x << ' ';\n\t\t} else {\n\t\t\tbreak;\n\t\t}\n\t}\n\
    \tcout << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/sieve.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-MMFSUNDARAM.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-MMFSUNDARAM.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-MMFSUNDARAM.test.cpp
- /verify/verify/spoj/spoj-MMFSUNDARAM.test.cpp.html
title: verify/spoj/spoj-MMFSUNDARAM.test.cpp
---
