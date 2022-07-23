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
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\
    \r\n#include <bits/stdc++.h>\r\n\r\ntemplate <class C> std::vector<int> z_algorithm(C\
    \ s) {\r\n\tint n = (int)s.size();\r\n\tstd::vector<int> a(n);\r\n\ta[0] = n;\r\
    \n\tint i = 1, j = 0;\r\n\twhile (i < n) {\r\n\t\twhile (i + j < n && s[j] ==\
    \ s[i + j]) ++j;\r\n\t\ta[i] = j;\r\n\t\tif (j == 0) {\r\n\t\t\t++i;\r\n\t\t\t\
    continue;\r\n\t\t}\r\n\t\tint k = 1;\r\n\t\twhile (i + k < n && k + a[k] < j)\
    \ a[i + k] = a[k], ++k;\r\n\t\ti += k;\r\n\t\tj -= k;\r\n\t}\r\n\treturn a;\r\n\
    }\r\n\r\nusing namespace std;\r\n\r\nint main() {\r\n\tstring s;\r\n\tcin >> s;\r\
    \n\tauto a = z_algorithm(s);\r\n\tfor (int x : a) {\r\n\t\tcout << x << ' ';\r\
    \n\t}\r\n\tcout << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#include\
    \ <bits/stdc++.h>\r\n#include \"../../library/string/z-algorithm.hpp\"\r\n\r\n\
    using namespace std;\r\n\r\nint main() {\r\n\tstring s;\r\n\tcin >> s;\r\n\tauto\
    \ a = z_algorithm(s);\r\n\tfor (int x : a) {\r\n\t\tcout << x << ' ';\r\n\t}\r\
    \n\tcout << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/string/z-algorithm.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-zalgorithm.test.cpp
- /verify/verify/yosupo/yosupo-zalgorithm.test.cpp.html
title: verify/yosupo/yosupo-zalgorithm.test.cpp
---
