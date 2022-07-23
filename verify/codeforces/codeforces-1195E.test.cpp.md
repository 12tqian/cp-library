---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/dynamic-programming/max-deque.hpp
    title: library/dynamic-programming/max-deque.hpp
  - icon: ':heavy_check_mark:'
    path: library/dynamic-programming/min-deque.hpp
    title: library/dynamic-programming/min-deque.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/problemset/problem/1195/E
    links:
    - https://codeforces.com/problemset/problem/1195/E
  bundledCode: "#define PROBLEM \"https://codeforces.com/problemset/problem/1195/E\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> struct\
    \ MinDeque {\r\n\tint lo = 0, hi = -1;\r\n\r\n\tstd::deque<std::pair<T, int>>\
    \ d;\r\n\tvoid push_back(T x) { // add to back\r\n\t\twhile ((int)d.size() &&\
    \ d.back().first >= x) d.pop_back();\r\n\t\td.push_back({x, ++hi});\r\n\t}\r\n\
    \r\n\tvoid pop_front() { // delete from front\r\n\t\tif (d.front().second == lo++)\
    \ d.pop_front();\r\n\t}\r\n\r\n\tT get() {\r\n\t\treturn (int)d.size() ? d.front().first\
    \ : std::numeric_limits<T>::max();\r\n\t}\r\n};\r\n\r\ntemplate <class T> struct\
    \ MaxDeque {\r\n\tstd::deque<std::pair<T, int>> mx;\r\n\tstd::deque<int> tmp;\r\
    \n\r\n\tint l = 0,r = -1;\r\n\r\n\tint pop_front() {\r\n\t\tif (mx.front().second\
    \ == l++) mx.pop_front();\r\n\t\tint t = tmp.front();\r\n\t\ttmp.pop_front();\r\
    \n\t\treturn t;\r\n\t}\r\n\r\n\tT get() {\r\n\t\tif ((int)mx.size() == 0) return\
    \ std::numeric_limits<T>::min();\r\n\t\treturn mx.front().first;\r\n\t}\r\n\r\n\
    \tvoid push_back(T x) {\r\n\t\twhile ((int)mx.size() && mx.back().first <= x)\
    \ mx.pop_back();\r\n\t\tmx.push_back({x, ++r});\r\n\t\ttmp.push_back(x);\r\n\t\
    }\r\n};\r\n\r\nint main(){\r\n\tios_base::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, m, a, b;\r\n\tcin >> n >> m >> a >> b;\r\n\tlong long g, x, y, z;\r\
    \n\tcin >> g >> x >> y >> z;\r\n\tvector<vector<int>> grid(n + 1, vector<int>(m\
    \ + 1));\r\n\tvector<vector<int>> row_min(n + 1, vector<int>(m + 1));\r\n\tfor\
    \ (int i = 0; i < n; ++i) {\r\n\t\tfor (int j = 0; j < m; ++j) {\r\n\t\t\tgrid[i][j]\
    \ = g;\r\n\t\t\tg = (g * x + y) % z;\r\n\t\t}\r\n\t}\r\n\tlong long ans = 0;\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tMinDeque<int> d;\r\n\t\tfor (int j =\
    \ 0; j < b; ++j) {\r\n\t\t\td.push_back(grid[i][j]);\r\n\t\t}\r\n\t\tfor (int\
    \ j = 0; j <= m - b; ++j) {\r\n\t\t\trow_min[i][j] = d.get();\r\n\t\t\td.pop_front();\r\
    \n\t\t\td.push_back(grid[i][j + b]);\r\n\t\t}\r\n\t}\r\n\tfor (int j = 0; j <=\
    \ m - b; ++j) {\r\n\t\tMinDeque<int> d;\r\n\t\tfor (int i = 0; i < a; ++i) {\r\
    \n\t\t\td.push_back(row_min[i][j]);\r\n\t\t}\r\n\t\tfor (int i = 0; i <= n - a;\
    \ ++i) {\r\n\t\t\tans += d.get();\r\n\t\t\td.pop_front();\r\n\t\t\td.push_back(row_min[i\
    \ + a][j]);\r\n\t\t}\r\n\t}\r\n\tcout << ans << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/problemset/problem/1195/E\"\r\n\r\
    \n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/dynamic-programming/min-deque.hpp\"\
    \r\n#include \"../../library/dynamic-programming/max-deque.hpp\"\r\n\r\nint main(){\r\
    \n\tios_base::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n, m, a,\
    \ b;\r\n\tcin >> n >> m >> a >> b;\r\n\tlong long g, x, y, z;\r\n\tcin >> g >>\
    \ x >> y >> z;\r\n\tvector<vector<int>> grid(n + 1, vector<int>(m + 1));\r\n\t\
    vector<vector<int>> row_min(n + 1, vector<int>(m + 1));\r\n\tfor (int i = 0; i\
    \ < n; ++i) {\r\n\t\tfor (int j = 0; j < m; ++j) {\r\n\t\t\tgrid[i][j] = g;\r\n\
    \t\t\tg = (g * x + y) % z;\r\n\t\t}\r\n\t}\r\n\tlong long ans = 0;\r\n\tfor (int\
    \ i = 0; i < n; ++i) {\r\n\t\tMinDeque<int> d;\r\n\t\tfor (int j = 0; j < b; ++j)\
    \ {\r\n\t\t\td.push_back(grid[i][j]);\r\n\t\t}\r\n\t\tfor (int j = 0; j <= m -\
    \ b; ++j) {\r\n\t\t\trow_min[i][j] = d.get();\r\n\t\t\td.pop_front();\r\n\t\t\t\
    d.push_back(grid[i][j + b]);\r\n\t\t}\r\n\t}\r\n\tfor (int j = 0; j <= m - b;\
    \ ++j) {\r\n\t\tMinDeque<int> d;\r\n\t\tfor (int i = 0; i < a; ++i) {\r\n\t\t\t\
    d.push_back(row_min[i][j]);\r\n\t\t}\r\n\t\tfor (int i = 0; i <= n - a; ++i) {\r\
    \n\t\t\tans += d.get();\r\n\t\t\td.pop_front();\r\n\t\t\td.push_back(row_min[i\
    \ + a][j]);\r\n\t\t}\r\n\t}\r\n\tcout << ans << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/dynamic-programming/min-deque.hpp
  - library/dynamic-programming/max-deque.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1195E.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1195E.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1195E.test.cpp
- /verify/verify/codeforces/codeforces-1195E.test.cpp.html
title: verify/codeforces/codeforces-1195E.test.cpp
---
