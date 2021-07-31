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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class T> struct MinDeque {\n\tint lo = 0, hi = -1;\n\n\tstd::deque<std::pair<T,\
    \ int>> d;\n\tvoid push_back(T x) { // add to back\n\t\twhile ((int)d.size() &&\
    \ d.back().first >= x) d.pop_back();\n\t\td.push_back({x, ++hi});\n\t}\n\n\tvoid\
    \ pop_front() { // delete from front\n\t\tif (d.front().second == lo++) d.pop_front();\n\
    \t}\n\n\tT get() {\n\t\treturn (int)d.size() ? d.front().first : std::numeric_limits<T>::max();\n\
    \t}\n};\n\ntemplate <class T> struct MaxDeque {\n\tstd::deque<std::pair<T, int>>\
    \ mx;\n\tstd::deque<int> tmp;\n\n\tint l = 0,r = -1;\n\n\tint pop_front() {\n\t\
    \tif (mx.front().second == l++) mx.pop_front();\n\t\tint t = tmp.front();\n\t\t\
    tmp.pop_front();\n\t\treturn t;\n\t}\n\n\tT get() {\n\t\tif ((int)mx.size() ==\
    \ 0) return std::numeric_limits<T>::min();\n\t\treturn mx.front().first;\n\t}\n\
    \n\tvoid push_back(T x) {\n\t\twhile ((int)mx.size() && mx.back().first <= x)\
    \ mx.pop_back();\n\t\tmx.push_back({x, ++r});\n\t\ttmp.push_back(x);\n\t}\n};\n\
    \nint main(){\n\tios_base::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint\
    \ n, m, a, b;\n\tcin >> n >> m >> a >> b;\n\tlong long g, x, y, z;\n\tcin >> g\
    \ >> x >> y >> z;\n\tvector<vector<int>> grid(n + 1, vector<int>(m + 1));\n\t\
    vector<vector<int>> row_min(n + 1, vector<int>(m + 1));\n\tfor (int i = 0; i <\
    \ n; ++i) {\n\t\tfor (int j = 0; j < m; ++j) {\n\t\t\tgrid[i][j] = g;\n\t\t\t\
    g = (g * x + y) % z;\n\t\t}\n\t}\n\tlong long ans = 0;\n\tfor (int i = 0; i <\
    \ n; ++i) {\n\t\tMinDeque<int> d;\n\t\tfor (int j = 0; j < b; ++j) {\n\t\t\td.push_back(grid[i][j]);\n\
    \t\t}\n\t\tfor (int j = 0; j <= m - b; ++j) {\n\t\t\trow_min[i][j] = d.get();\n\
    \t\t\td.pop_front();\n\t\t\td.push_back(grid[i][j + b]);\n\t\t}\n\t}\n\tfor (int\
    \ j = 0; j <= m - b; ++j) {\n\t\tMinDeque<int> d;\n\t\tfor (int i = 0; i < a;\
    \ ++i) {\n\t\t\td.push_back(row_min[i][j]);\n\t\t}\n\t\tfor (int i = 0; i <= n\
    \ - a; ++i) {\n\t\t\tans += d.get();\n\t\t\td.pop_front();\n\t\t\td.push_back(row_min[i\
    \ + a][j]);\n\t\t}\n\t}\n\tcout << ans << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/problemset/problem/1195/E\"\n\n\
    #include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/dynamic-programming/min-deque.hpp\"\
    \n#include \"../../library/dynamic-programming/max-deque.hpp\"\n\nint main(){\n\
    \tios_base::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n, m, a, b;\n\t\
    cin >> n >> m >> a >> b;\n\tlong long g, x, y, z;\n\tcin >> g >> x >> y >> z;\n\
    \tvector<vector<int>> grid(n + 1, vector<int>(m + 1));\n\tvector<vector<int>>\
    \ row_min(n + 1, vector<int>(m + 1));\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor\
    \ (int j = 0; j < m; ++j) {\n\t\t\tgrid[i][j] = g;\n\t\t\tg = (g * x + y) % z;\n\
    \t\t}\n\t}\n\tlong long ans = 0;\n\tfor (int i = 0; i < n; ++i) {\n\t\tMinDeque<int>\
    \ d;\n\t\tfor (int j = 0; j < b; ++j) {\n\t\t\td.push_back(grid[i][j]);\n\t\t\
    }\n\t\tfor (int j = 0; j <= m - b; ++j) {\n\t\t\trow_min[i][j] = d.get();\n\t\t\
    \td.pop_front();\n\t\t\td.push_back(grid[i][j + b]);\n\t\t}\n\t}\n\tfor (int j\
    \ = 0; j <= m - b; ++j) {\n\t\tMinDeque<int> d;\n\t\tfor (int i = 0; i < a; ++i)\
    \ {\n\t\t\td.push_back(row_min[i][j]);\n\t\t}\n\t\tfor (int i = 0; i <= n - a;\
    \ ++i) {\n\t\t\tans += d.get();\n\t\t\td.pop_front();\n\t\t\td.push_back(row_min[i\
    \ + a][j]);\n\t\t}\n\t}\n\tcout << ans << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/dynamic-programming/min-deque.hpp
  - library/dynamic-programming/max-deque.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1195E.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1195E.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1195E.test.cpp
- /verify/verify/codeforces/codeforces-1195E.test.cpp.html
title: verify/codeforces/codeforces-1195E.test.cpp
---
