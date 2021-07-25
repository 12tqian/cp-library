---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n\tint n; cin >> n;\n\tvector<int> s(n);\n\
    \tREP (i, n) {\n\t\tcin >> s[i];\n\t}\n\tint q; cin >> q;\n\tint cnt = 0;\n\t\
    while (q --) {\n\t\tint t_i; cin >> t_i;\n\t\tcnt += binary_search(ALL(s), t_i);\n\
    \t}\n\tcout << cnt << endl;\n\treturn 0;\n}    \n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n\tint n; cin >> n;\n\tvector<int> s(n);\n\
    \tREP (i, n) {\n\t\tcin >> s[i];\n\t}\n\tint q; cin >> q;\n\tint cnt = 0;\n\t\
    while (q --) {\n\t\tint t_i; cin >> t_i;\n\t\tcnt += binary_search(ALL(s), t_i);\n\
    \t}\n\tcout << cnt << endl;\n\treturn 0;\n}    "
  dependsOn: []
  isVerificationFile: true
  path: test/example.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 21:44:19-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/example.test.cpp
layout: document
redirect_from:
- /verify/test/example.test.cpp
- /verify/test/example.test.cpp.html
title: test/example.test.cpp
---
