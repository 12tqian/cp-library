---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/simplex.hpp
    title: Simplex LP Solver
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://open.kattis.com/contests/ecna19open/problems/cheeseifyouplease
    links:
    - https://open.kattis.com/contests/ecna19open/problems/cheeseifyouplease
  bundledCode: "#define PROBLEM \"https://open.kattis.com/contests/ecna19open/problems/cheeseifyouplease\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> struct\
    \ Simplex {\r\n\tconst T EPS = 1e-8;\r\n\tconst T INF = 1 / .0;\r\n\t\r\n\tint\
    \ m, n; // constraints, variables\r\n\r\n\tstd::vector<int> N, B;\r\n\r\n\tstd::vector<std::vector<T>>\
    \ D;\r\n\r\n\tSimplex(const std::vector<std::vector<T>>& A, const std::vector<T>&\
    \ b, const std::vector<T>& c) : \r\n\tm(b.size()), n(c.size()), N(n + 1), B(m),\
    \ D(m + 2, std::vector<T>(n + 2)) {\r\n\t\tfor (int i = 0; i < m; ++i) {\r\n\t\
    \t\tfor (int j = 0; j < n; ++j) {\r\n\t\t\t\tD[i][j] = A[i][j];\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\tfor (int i = 0; i < m; ++i) {\r\n\t\t\tB[i] = n + i;\r\n\t\t\tD[i][n]\
    \ = -1;\r\n\t\t\tD[i][n + 1] = b[i];\r\n\t\t}\r\n\t\tfor (int j = 0; j < n; ++j)\
    \ {\r\n\t\t\tN[j] = j;\r\n\t\t\tD[m][j] = -c[j];\r\n\t\t}\r\n\t\tN[n] = -1;\r\n\
    \t\tD[m + 1][n] = 1;\r\n\t}\r\n\r\n\tvoid pivot(int r, int s) {\r\n\t\tT *a =\
    \ D[r].data(), inv = 1 / a[s];\r\n\t\tfor (int i = 0; i < m + 2; ++i) {\r\n\t\t\
    \tif (i != r && std::abs(D[i][s]) > EPS) {\r\n\t\t\t\tT *b = D[i].data(), binv\
    \ = b[s] * inv;\r\n\t\t\t\tfor (int j = 0; j < n + 2; ++j) {\r\n\t\t\t\t\tb[j]\
    \ -= a[j] * binv;\r\n\t\t\t\t}\r\n\t\t\t\tb[s] = a[s] * binv;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\tfor (int j = 0; j < n + 2; ++j) {\r\n\t\t\tif (j != s) {\r\n\t\t\t\t\
    D[r][j] *= inv;\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i = 0; i < m + 2; ++i) {\r\
    \n\t\t\tif (i != r) {\r\n\t\t\t\tD[i][s] *= -inv;\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    D[r][s] = inv;\r\n\t\tstd::swap(B[r], N[s]);\r\n\t}\r\n\r\n\tbool simplex(int\
    \ phase) {\r\n\t\tint x = m + phase - 1;\r\n\t\twhile (true) {\r\n\t\t\tint s\
    \ = -1;\r\n\t\t\tfor (int j = 0; j < n + 1; ++j) {\r\n\t\t\t\tif (N[j] != -phase)\
    \ {\r\n\t\t\t\t\tif (s == -1 || std::make_pair(D[x][j], N[j]) < std::make_pair(D[x][s],\
    \ N[s])) {\r\n\t\t\t\t\t\ts = j;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\
    \tif (D[x][s] >= -EPS) {\r\n\t\t\t\treturn true;\r\n\t\t\t}\r\n\t\t\tint r = -1;\r\
    \n\t\t\tfor (int i = 0; i < m; ++i) {\r\n\t\t\t\tif (D[i][s] <= EPS) {\r\n\t\t\
    \t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\tif (r == -1 || std::make_pair(D[i][n +\
    \ 1] / D[i][s], B[i]) \r\n\t\t\t\t\t< std::make_pair(D[r][n + 1] / D[r][s], B[r]))\
    \ {\r\n\t\t\t\t\tr = i;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (r == -1) {\r\n\t\t\
    \t\treturn false;\r\n\t\t\t}\r\n\t\t\tpivot(r, s);\r\n\t\t}\r\n\t}\r\n\r\n\tT\
    \ solve(std::vector<T>& x) {\r\n\t\tint r = 0;\r\n\t\tfor (int i = 1; i < m; ++i)\
    \ {\r\n\t\t\tif (D[i][n + 1] < D[r][n + 1]) {\r\n\t\t\t\tr = i;\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\tif (D[r][n + 1] < -EPS) {\r\n\t\t\tpivot(r, n);\r\n\t\t\tif (!simplex(2)\
    \ || D[m + 1][n + 1] < -EPS) {\r\n\t\t\t\treturn -INF;\r\n\t\t\t}\r\n\t\t\tfor\
    \ (int i = 0; i < m; ++i) {\r\n\t\t\t\tif (B[i] == -1) {\r\n\t\t\t\t\tint s =\
    \ 0;\r\n\t\t\t\t\tfor (int j = 1; j < n + 1; ++j) {\r\n\t\t\t\t\t\tif (s == -1\
    \ || std::make_pair(D[i][j], N[j]) < std::make_pair(D[i][s], N[s])) {\r\n\t\t\t\
    \t\t\t\ts = j;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\tpivot(i, s);\r\n\t\
    \t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tbool ok = simplex(1);\r\n\t\tx.assign(n, 0);\r\
    \n\t\tfor (int i = 0; i < m; ++i) {\r\n\t\t\tif (B[i] < n) {\r\n\t\t\t\tx[B[i]]\
    \ = D[i][n + 1];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ok ? D[m][n + 1] : INF;\r\n\
    \t}\r\n};\n\r\n// kattis cheese\r\nint main() {\r\n\tusing namespace std;\r\n\t\
    ios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n, m; \r\n\tcin >>\
    \ n >> m;\r\n\tvector<vector<double>> A(n, vector<double>(m));\r\n\tvector<double>\
    \ c(m);\r\n\tvector<double> b(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tcin\
    \ >> b[i];\r\n\t}\r\n\tfor (int i = 0; i < m; ++i) {\r\n\t\tfor (int j = 0; j\
    \ < n; ++j) {\r\n\t\t\tcin >> A[j][i];\r\n\t\t\tA[j][i] /= 100;\r\n\t\t}\r\n\t\
    \tcin >> c[i];\r\n\t}\r\n\tvector<double> x; \r\n\tdouble ans = Simplex<double>(A,\
    \ b, c).solve(x);\r\n\tcout << fixed << setprecision(2) << ans << '\\n';\r\n\t\
    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/contests/ecna19open/problems/cheeseifyouplease\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/numerical/simplex.hpp\"\r\n\r\n// kattis cheese\r\nint main() {\r\
    \n\tusing namespace std;\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, m; \r\n\tcin >> n >> m;\r\n\tvector<vector<double>> A(n, vector<double>(m));\r\
    \n\tvector<double> c(m);\r\n\tvector<double> b(n);\r\n\tfor (int i = 0; i < n;\
    \ ++i) {\r\n\t\tcin >> b[i];\r\n\t}\r\n\tfor (int i = 0; i < m; ++i) {\r\n\t\t\
    for (int j = 0; j < n; ++j) {\r\n\t\t\tcin >> A[j][i];\r\n\t\t\tA[j][i] /= 100;\r\
    \n\t\t}\r\n\t\tcin >> c[i];\r\n\t}\r\n\tvector<double> x; \r\n\tdouble ans = Simplex<double>(A,\
    \ b, c).solve(x);\r\n\tcout << fixed << setprecision(2) << ans << '\\n';\r\n\t\
    return 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/simplex.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-cheeseifyouplease.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-cheeseifyouplease.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-cheeseifyouplease.test.cpp
- /verify/verify/kattis/kattis-cheeseifyouplease.test.cpp.html
title: verify/kattis/kattis-cheeseifyouplease.test.cpp
---
