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
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/TDKPRIME/\"\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n\ntemplate <int N> struct LinearSieve\
    \ {\n\tstd::bitset<N> pri;\n\tstd::vector<int> pr;\n\t\n\tLinearSieve() {\n\t\t\
    pri.set();\n\t\tpri[0] = pri[1] = 0;\n\t\tfor (int i = 2; i < N; ++i) {\n\t\t\t\
    if (pri[i]) \n\t\t\t\tpr.push_back(i);\n\t\t\tfor (int j = 0; j < (int)pr.size()\
    \ && i * pr[j] < N; ++j) {\n\t\t\t\tpri[i * pr[j]] = 0;\n\t\t\t\tif (i % pr[j]\
    \ == 0) \n\t\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n};\n\nconst int N = 1e8;\n\n\
    LinearSieve<N> sieve;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint n;\n\t\tcin >> n;\n\t\tcout <<\
    \ sieve.pr[n - 1] << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/TDKPRIME/\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#include \"../../library/number-theory/linear-sieve.hpp\"\
    \n\nconst int N = 1e8;\n\nLinearSieve<N> sieve;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint n;\n\t\t\
    cin >> n;\n\t\tcout << sieve.pr[n - 1] << '\\n';\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/number-theory/linear-sieve.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-TDKPRIME.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 14:40:22-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-TDKPRIME.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-TDKPRIME.test.cpp
- /verify/verify/spoj/spoj-TDKPRIME.test.cpp.html
title: verify/spoj/spoj-TDKPRIME.test.cpp
---
