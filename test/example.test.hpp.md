---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n; cin >> n;\n    vector<int> s(n);\n\
    \    REP (i, n) {\n        cin >> s[i];\n    }\n    int q; cin >> q;\n    int\
    \ cnt = 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n        cnt += binary_search(ALL(s),\
    \ t_i);\n    }\n    cout << cnt << endl;\n    return 0;\n}    \n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n; cin >> n;\n    vector<int> s(n);\n\
    \    REP (i, n) {\n        cin >> s[i];\n    }\n    int q; cin >> q;\n    int\
    \ cnt = 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n        cnt += binary_search(ALL(s),\
    \ t_i);\n    }\n    cout << cnt << endl;\n    return 0;\n}    "
  dependsOn: []
  isVerificationFile: true
  path: test/example.test.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:26:06-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/example.test.hpp
layout: document
redirect_from:
- /verify/test/example.test.hpp
- /verify/test/example.test.hpp.html
title: test/example.test.hpp
---
