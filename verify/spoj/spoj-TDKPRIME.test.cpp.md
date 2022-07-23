---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number-theory/linear-sieve.hpp
    title: Linear Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.spoj.com/problems/TDKPRIME/
    links:
    - https://www.spoj.com/problems/TDKPRIME/
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/TDKPRIME/\"\r\n\r\n\
    #include <bits/stdc++.h>\r\n\r\nusing namespace std;\r\n\r\n\r\ntemplate <int\
    \ N> struct LinearSieve {\r\n\tstd::bitset<N> pri;\r\n\tstd::vector<int> pr;\r\
    \n\t\r\n\tLinearSieve() {\r\n\t\tpri.set();\r\n\t\tpri[0] = pri[1] = 0;\r\n\t\t\
    for (int i = 2; i < N; ++i) {\r\n\t\t\tif (pri[i]) \r\n\t\t\t\tpr.push_back(i);\r\
    \n\t\t\tfor (int j = 0; j < (int)pr.size() && i * pr[j] < N; ++j) {\r\n\t\t\t\t\
    pri[i * pr[j]] = 0;\r\n\t\t\t\tif (i % pr[j] == 0) \r\n\t\t\t\t\tbreak;\r\n\t\t\
    \t}\r\n\t\t}\r\n\t}\r\n};\n\r\nconst int N = 1e8;\r\n\r\nLinearSieve<N> sieve;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\
    \tint q;\r\n\tcin >> q;\r\n\twhile (q--) {\r\n\t\tint n;\r\n\t\tcin >> n;\r\n\t\
    \tcout << sieve.pr[n - 1] << '\\n';\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/TDKPRIME/\"\r\n\r\n#include\
    \ <bits/stdc++.h>\r\n\r\nusing namespace std;\r\n\r\n#include \"../../library/number-theory/linear-sieve.hpp\"\
    \r\n\r\nconst int N = 1e8;\r\n\r\nLinearSieve<N> sieve;\r\n\r\nint main() {\r\n\
    \tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint q;\r\n\tcin >>\
    \ q;\r\n\twhile (q--) {\r\n\t\tint n;\r\n\t\tcin >> n;\r\n\t\tcout << sieve.pr[n\
    \ - 1] << '\\n';\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/number-theory/linear-sieve.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-TDKPRIME.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-TDKPRIME.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-TDKPRIME.test.cpp
- /verify/verify/spoj/spoj-TDKPRIME.test.cpp.html
title: verify/spoj/spoj-TDKPRIME.test.cpp
---
