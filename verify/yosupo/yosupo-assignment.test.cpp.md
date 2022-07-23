---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/flows/hungarian.hpp
    title: Hungarian Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\r\n\
    \r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class C> std::pair<C,\
    \ std::vector<int>> hungarian(const std::vector<std::vector<C>>& a_) {\r\n\tconst\
    \ C INF = std::numeric_limits<C>::max();\r\n\tint n = (int)a_.size();\r\n\tint\
    \ m = (int)a_[0].size();\r\n\tassert(n <= m);\r\n\tstd::vector<std::vector<C>>\
    \ a(n + 1, std::vector<C>(m + 1, 0));\r\n\tfor (int i = 0; i < n; i++)\r\n\t\t\
    for (int j = 0; j < m; j++)\r\n\t\t\ta[i + 1][j + 1] = a_[i][j];\r\n\tstd::vector<C>\
    \ u(n + 1), v(m + 1);\r\n\tstd::vector<int> job(m + 1);\r\n\tfor (int i = 1; i\
    \ <= n; i++) {\r\n\t\tint w = 0;\r\n\t\tjob[w] = i;\r\n\t\tstd::vector<C> dist(m\
    \ + 1, INF);\r\n\t\tstd::vector<int> pre(m + 1, -1);\r\n\t\tstd::vector<bool>\
    \ done(m + 1);\r\n\t\twhile (job[w]) {\r\n\t\t\tdone[w] = 1;\r\n\t\t\tint j =\
    \ job[w], nxt;\r\n\t\t\tC delta = INF;\r\n\t\t\tfor (int ww = 0; ww <= m; ww++)\
    \ {\r\n\t\t\t\tif (!done[ww]) {\r\n\t\t\t\t\tif (dist[ww] > a[j][ww] - u[j] -\
    \ v[ww]) {\r\n\t\t\t\t\t\tdist[ww] = a[j][ww] - u[j] - v[ww];\r\n\t\t\t\t\t\t\
    pre[ww] = w; \r\n\t\t\t\t\t}\r\n\t\t\t\t\tif (delta > dist[ww]) {\r\n\t\t\t\t\t\
    \tdelta = dist[ww];\r\n\t\t\t\t\t\tnxt = ww;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\r\n\t\t\t\tif (done[ww]) {\r\n\
    \t\t\t\t\tu[job[ww]] += delta;\r\n\t\t\t\t\tv[ww] -= delta;\r\n\t\t\t\t} else\
    \ {\r\n\t\t\t\t\tdist[ww] -= delta;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tw = nxt;\r\
    \n\t\t}\r\n\t\tfor (int ww; w; w = ww) \r\n\t\t\tjob[w] = job[ww = pre[w]];\r\n\
    \t}\r\n\tjob.erase(job.begin());\r\n\tfor (int i = 0; i < m; i++)\r\n\t\tjob[i]--;\r\
    \n\treturn {-v[0], job};\r\n}\n\r\nint main() {\r\n\tint n; cin >> n;\r\n\tvector<vector<long\
    \ long>> a(n, vector<long long>(n));\r\n\tfor (int i = 0; i < n; i++)\r\n\t\t\
    for (int j = 0; j < n; j++) cin >> a[i][j];\r\n\tauto res = hungarian(a);\r\n\t\
    vector<int> loc(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tloc[res.second[i]]\
    \ = i;\r\n\t}\r\n\tcout << res.first << '\\n';\r\n\tfor (int x : loc) \r\n\t\t\
    cout << x << \" \";\r\n\tcout << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\r\n\r\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/flows/hungarian.hpp\"\
    \r\n\r\nint main() {\r\n\tint n; cin >> n;\r\n\tvector<vector<long long>> a(n,\
    \ vector<long long>(n));\r\n\tfor (int i = 0; i < n; i++)\r\n\t\tfor (int j =\
    \ 0; j < n; j++) cin >> a[i][j];\r\n\tauto res = hungarian(a);\r\n\tvector<int>\
    \ loc(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tloc[res.second[i]] = i;\r\n\
    \t}\r\n\tcout << res.first << '\\n';\r\n\tfor (int x : loc) \r\n\t\tcout << x\
    \ << \" \";\r\n\tcout << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/flows/hungarian.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-assignment.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-assignment.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-assignment.test.cpp
- /verify/verify/yosupo/yosupo-assignment.test.cpp.html
title: verify/yosupo/yosupo-assignment.test.cpp
---