---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/kattis/kattis-cheeseifyouplease.test.cpp
    title: verify/kattis/kattis-cheeseifyouplease.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct Simplex {\r\n\tconst T EPS = 1e-8;\r\
    \n\tconst T INF = 1 / .0;\r\n\t\r\n\tint m, n; // constraints, variables\r\n\r\
    \n\tstd::vector<int> N, B;\r\n\r\n\tstd::vector<std::vector<T>> D;\r\n\r\n\tSimplex(const\
    \ std::vector<std::vector<T>>& A, const std::vector<T>& b, const std::vector<T>&\
    \ c) : \r\n\tm(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, std::vector<T>(n\
    \ + 2)) {\r\n\t\tfor (int i = 0; i < m; ++i) {\r\n\t\t\tfor (int j = 0; j < n;\
    \ ++j) {\r\n\t\t\t\tD[i][j] = A[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i =\
    \ 0; i < m; ++i) {\r\n\t\t\tB[i] = n + i;\r\n\t\t\tD[i][n] = -1;\r\n\t\t\tD[i][n\
    \ + 1] = b[i];\r\n\t\t}\r\n\t\tfor (int j = 0; j < n; ++j) {\r\n\t\t\tN[j] = j;\r\
    \n\t\t\tD[m][j] = -c[j];\r\n\t\t}\r\n\t\tN[n] = -1;\r\n\t\tD[m + 1][n] = 1;\r\n\
    \t}\r\n\r\n\tvoid pivot(int r, int s) {\r\n\t\tT *a = D[r].data(), inv = 1 / a[s];\r\
    \n\t\tfor (int i = 0; i < m + 2; ++i) {\r\n\t\t\tif (i != r && std::abs(D[i][s])\
    \ > EPS) {\r\n\t\t\t\tT *b = D[i].data(), binv = b[s] * inv;\r\n\t\t\t\tfor (int\
    \ j = 0; j < n + 2; ++j) {\r\n\t\t\t\t\tb[j] -= a[j] * binv;\r\n\t\t\t\t}\r\n\t\
    \t\t\tb[s] = a[s] * binv;\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int j = 0; j < n + 2;\
    \ ++j) {\r\n\t\t\tif (j != s) {\r\n\t\t\t\tD[r][j] *= inv;\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\tfor (int i = 0; i < m + 2; ++i) {\r\n\t\t\tif (i != r) {\r\n\t\t\t\t\
    D[i][s] *= -inv;\r\n\t\t\t}\r\n\t\t}\r\n\t\tD[r][s] = inv;\r\n\t\tstd::swap(B[r],\
    \ N[s]);\r\n\t}\r\n\r\n\tbool simplex(int phase) {\r\n\t\tint x = m + phase -\
    \ 1;\r\n\t\twhile (true) {\r\n\t\t\tint s = -1;\r\n\t\t\tfor (int j = 0; j < n\
    \ + 1; ++j) {\r\n\t\t\t\tif (N[j] != -phase) {\r\n\t\t\t\t\tif (s == -1 || std::make_pair(D[x][j],\
    \ N[j]) < std::make_pair(D[x][s], N[s])) {\r\n\t\t\t\t\t\ts = j;\r\n\t\t\t\t\t\
    }\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (D[x][s] >= -EPS) {\r\n\t\t\t\treturn true;\r\
    \n\t\t\t}\r\n\t\t\tint r = -1;\r\n\t\t\tfor (int i = 0; i < m; ++i) {\r\n\t\t\t\
    \tif (D[i][s] <= EPS) {\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\tif (r ==\
    \ -1 || std::make_pair(D[i][n + 1] / D[i][s], B[i]) \r\n\t\t\t\t\t< std::make_pair(D[r][n\
    \ + 1] / D[r][s], B[r])) {\r\n\t\t\t\t\tr = i;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\
    \tif (r == -1) {\r\n\t\t\t\treturn false;\r\n\t\t\t}\r\n\t\t\tpivot(r, s);\r\n\
    \t\t}\r\n\t}\r\n\r\n\tT solve(std::vector<T>& x) {\r\n\t\tint r = 0;\r\n\t\tfor\
    \ (int i = 1; i < m; ++i) {\r\n\t\t\tif (D[i][n + 1] < D[r][n + 1]) {\r\n\t\t\t\
    \tr = i;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (D[r][n + 1] < -EPS) {\r\n\t\t\tpivot(r,\
    \ n);\r\n\t\t\tif (!simplex(2) || D[m + 1][n + 1] < -EPS) {\r\n\t\t\t\treturn\
    \ -INF;\r\n\t\t\t}\r\n\t\t\tfor (int i = 0; i < m; ++i) {\r\n\t\t\t\tif (B[i]\
    \ == -1) {\r\n\t\t\t\t\tint s = 0;\r\n\t\t\t\t\tfor (int j = 1; j < n + 1; ++j)\
    \ {\r\n\t\t\t\t\t\tif (s == -1 || std::make_pair(D[i][j], N[j]) < std::make_pair(D[i][s],\
    \ N[s])) {\r\n\t\t\t\t\t\t\ts = j;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\
    \tpivot(i, s);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tbool ok = simplex(1);\r\
    \n\t\tx.assign(n, 0);\r\n\t\tfor (int i = 0; i < m; ++i) {\r\n\t\t\tif (B[i] <\
    \ n) {\r\n\t\t\t\tx[B[i]] = D[i][n + 1];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ok\
    \ ? D[m][n + 1] : INF;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct Simplex {\r\n\tconst T EPS\
    \ = 1e-8;\r\n\tconst T INF = 1 / .0;\r\n\t\r\n\tint m, n; // constraints, variables\r\
    \n\r\n\tstd::vector<int> N, B;\r\n\r\n\tstd::vector<std::vector<T>> D;\r\n\r\n\
    \tSimplex(const std::vector<std::vector<T>>& A, const std::vector<T>& b, const\
    \ std::vector<T>& c) : \r\n\tm(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2,\
    \ std::vector<T>(n + 2)) {\r\n\t\tfor (int i = 0; i < m; ++i) {\r\n\t\t\tfor (int\
    \ j = 0; j < n; ++j) {\r\n\t\t\t\tD[i][j] = A[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tfor (int i = 0; i < m; ++i) {\r\n\t\t\tB[i] = n + i;\r\n\t\t\tD[i][n] = -1;\r\
    \n\t\t\tD[i][n + 1] = b[i];\r\n\t\t}\r\n\t\tfor (int j = 0; j < n; ++j) {\r\n\t\
    \t\tN[j] = j;\r\n\t\t\tD[m][j] = -c[j];\r\n\t\t}\r\n\t\tN[n] = -1;\r\n\t\tD[m\
    \ + 1][n] = 1;\r\n\t}\r\n\r\n\tvoid pivot(int r, int s) {\r\n\t\tT *a = D[r].data(),\
    \ inv = 1 / a[s];\r\n\t\tfor (int i = 0; i < m + 2; ++i) {\r\n\t\t\tif (i != r\
    \ && std::abs(D[i][s]) > EPS) {\r\n\t\t\t\tT *b = D[i].data(), binv = b[s] * inv;\r\
    \n\t\t\t\tfor (int j = 0; j < n + 2; ++j) {\r\n\t\t\t\t\tb[j] -= a[j] * binv;\r\
    \n\t\t\t\t}\r\n\t\t\t\tb[s] = a[s] * binv;\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int\
    \ j = 0; j < n + 2; ++j) {\r\n\t\t\tif (j != s) {\r\n\t\t\t\tD[r][j] *= inv;\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i = 0; i < m + 2; ++i) {\r\n\t\t\tif (i !=\
    \ r) {\r\n\t\t\t\tD[i][s] *= -inv;\r\n\t\t\t}\r\n\t\t}\r\n\t\tD[r][s] = inv;\r\
    \n\t\tstd::swap(B[r], N[s]);\r\n\t}\r\n\r\n\tbool simplex(int phase) {\r\n\t\t\
    int x = m + phase - 1;\r\n\t\twhile (true) {\r\n\t\t\tint s = -1;\r\n\t\t\tfor\
    \ (int j = 0; j < n + 1; ++j) {\r\n\t\t\t\tif (N[j] != -phase) {\r\n\t\t\t\t\t\
    if (s == -1 || std::make_pair(D[x][j], N[j]) < std::make_pair(D[x][s], N[s]))\
    \ {\r\n\t\t\t\t\t\ts = j;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (D[x][s]\
    \ >= -EPS) {\r\n\t\t\t\treturn true;\r\n\t\t\t}\r\n\t\t\tint r = -1;\r\n\t\t\t\
    for (int i = 0; i < m; ++i) {\r\n\t\t\t\tif (D[i][s] <= EPS) {\r\n\t\t\t\t\tcontinue;\r\
    \n\t\t\t\t}\r\n\t\t\t\tif (r == -1 || std::make_pair(D[i][n + 1] / D[i][s], B[i])\
    \ \r\n\t\t\t\t\t< std::make_pair(D[r][n + 1] / D[r][s], B[r])) {\r\n\t\t\t\t\t\
    r = i;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (r == -1) {\r\n\t\t\t\treturn false;\r\
    \n\t\t\t}\r\n\t\t\tpivot(r, s);\r\n\t\t}\r\n\t}\r\n\r\n\tT solve(std::vector<T>&\
    \ x) {\r\n\t\tint r = 0;\r\n\t\tfor (int i = 1; i < m; ++i) {\r\n\t\t\tif (D[i][n\
    \ + 1] < D[r][n + 1]) {\r\n\t\t\t\tr = i;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (D[r][n\
    \ + 1] < -EPS) {\r\n\t\t\tpivot(r, n);\r\n\t\t\tif (!simplex(2) || D[m + 1][n\
    \ + 1] < -EPS) {\r\n\t\t\t\treturn -INF;\r\n\t\t\t}\r\n\t\t\tfor (int i = 0; i\
    \ < m; ++i) {\r\n\t\t\t\tif (B[i] == -1) {\r\n\t\t\t\t\tint s = 0;\r\n\t\t\t\t\
    \tfor (int j = 1; j < n + 1; ++j) {\r\n\t\t\t\t\t\tif (s == -1 || std::make_pair(D[i][j],\
    \ N[j]) < std::make_pair(D[i][s], N[s])) {\r\n\t\t\t\t\t\t\ts = j;\r\n\t\t\t\t\
    \t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\tpivot(i, s);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\tbool ok = simplex(1);\r\n\t\tx.assign(n, 0);\r\n\t\tfor (int i = 0; i\
    \ < m; ++i) {\r\n\t\t\tif (B[i] < n) {\r\n\t\t\t\tx[B[i]] = D[i][n + 1];\r\n\t\
    \t\t}\r\n\t\t}\r\n\t\treturn ok ? D[m][n + 1] : INF;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/simplex.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/kattis/kattis-cheeseifyouplease.test.cpp
documentation_of: library/numerical/simplex.hpp
layout: document
title: Simplex LP Solver
---

## Simplex LP Solver

Solves linear programming problems using simplex method. 

## Functions
- `Simplex(A, b, c)`: Maximizes $\vec{c}^T \vec x$ given $A \vec x \leq \vec b$ and $\vec x \geq \vec 0$. Returns `INF` if there are many good solutions, and `-INF` if there is no good solution, and the maximum value otherwise. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/numerical/Misc/Simplex.h)

