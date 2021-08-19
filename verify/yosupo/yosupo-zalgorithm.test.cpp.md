---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/z-algorithm.hpp
    title: library/string/z-algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n\
    #include <bits/stdc++.h>\n\ntemplate <class C> std::vector<int> z_algorithm(C\
    \ s) {\n\tint n = (int)s.size();\n\tstd::vector<int> a(n);\n\ta[0] = n;\n\tint\
    \ i = 1, j = 0;\n\twhile (i < n) {\n\t\twhile (i + j < n && s[j] == s[i + j])\
    \ ++j;\n\t\ta[i] = j;\n\t\tif (j == 0) {\n\t\t\t++i;\n\t\t\tcontinue;\n\t\t}\n\
    \t\tint k = 1;\n\t\twhile (i + k < n && k + a[k] < j) a[i + k] = a[k], ++k;\n\t\
    \ti += k;\n\t\tj -= k;\n\t}\n\treturn a;\n}\n\nusing namespace std;\n\nint main()\
    \ {\n\tstring s;\n\tcin >> s;\n\tauto a = z_algorithm(s);\n\tfor (int x : a) {\n\
    \t\tcout << x << ' ';\n\t}\n\tcout << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"../../library/string/z-algorithm.hpp\"\n\nusing\
    \ namespace std;\n\nint main() {\n\tstring s;\n\tcin >> s;\n\tauto a = z_algorithm(s);\n\
    \tfor (int x : a) {\n\t\tcout << x << ' ';\n\t}\n\tcout << '\\n';\n\treturn 0;\n\
    }"
  dependsOn:
  - library/string/z-algorithm.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2021-08-19 11:01:30-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-zalgorithm.test.cpp
- /verify/verify/yosupo/yosupo-zalgorithm.test.cpp.html
title: verify/yosupo/yosupo-zalgorithm.test.cpp
---
