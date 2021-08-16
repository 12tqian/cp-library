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
  bundledCode: "\ntemplate <class T> struct Simplex {\n\tconst T EPS = 1e-8;\n\tconst\
    \ T INF = 1 / .0;\n\t\n\tint m, n; // constraints, variables\n\n\tstd::vector<int>\
    \ N, B;\n\n\tstd::vector<std::vector<T>> D;\n\n\tSimplex(const std::vector<std::vector<T>>&\
    \ A, const std::vector<T>& b, const std::vector<T>& c) : \n\tm(b.size()), n(c.size()),\
    \ N(n + 1), B(m), D(m + 2, std::vector<T>(n + 2)) {\n\t\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\t\tfor (int j = 0; j < n; ++j) {\n\t\t\t\tD[i][j] = A[i][j];\n\t\t\
    \t}\n\t\t}\n\t\tfor (int i = 0; i < m; ++i) {\n\t\t\tB[i] = n + i;\n\t\t\tD[i][n]\
    \ = -1;\n\t\t\tD[i][n + 1] = b[i];\n\t\t}\n\t\tfor (int j = 0; j < n; ++j) {\n\
    \t\t\tN[j] = j;\n\t\t\tD[m][j] = -c[j];\n\t\t}\n\t\tN[n] = -1;\n\t\tD[m + 1][n]\
    \ = 1;\n\t}\n\n\tvoid pivot(int r, int s) {\n\t\tT *a = D[r].data(), inv = 1 /\
    \ a[s];\n\t\tfor (int i = 0; i < m + 2; ++i) {\n\t\t\tif (i != r && std::abs(D[i][s])\
    \ > EPS) {\n\t\t\t\tT *b = D[i].data(), binv = b[s] * inv;\n\t\t\t\tfor (int j\
    \ = 0; j < n + 2; ++j) {\n\t\t\t\t\tb[j] -= a[j] * binv;\n\t\t\t\t}\n\t\t\t\t\
    b[s] = a[s] * binv;\n\t\t\t}\n\t\t}\n\t\tfor (int j = 0; j < n + 2; ++j) {\n\t\
    \t\tif (j != s) {\n\t\t\t\tD[r][j] *= inv;\n\t\t\t}\n\t\t}\n\t\tfor (int i = 0;\
    \ i < m + 2; ++i) {\n\t\t\tif (i != r) {\n\t\t\t\tD[i][s] *= -inv;\n\t\t\t}\n\t\
    \t}\n\t\tD[r][s] = inv;\n\t\tstd::swap(B[r], N[s]);\n\t}\n\n\tbool simplex(int\
    \ phase) {\n\t\tint x = m + phase - 1;\n\t\twhile (true) {\n\t\t\tint s = -1;\n\
    \t\t\tfor (int j = 0; j < n + 1; ++j) {\n\t\t\t\tif (N[j] != -phase) {\n\t\t\t\
    \t\tif (s == -1 || std::make_pair(D[x][j], N[j]) < std::make_pair(D[x][s], N[s]))\
    \ {\n\t\t\t\t\t\ts = j;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (D[x][s] >=\
    \ -EPS) {\n\t\t\t\treturn true;\n\t\t\t}\n\t\t\tint r = -1;\n\t\t\tfor (int i\
    \ = 0; i < m; ++i) {\n\t\t\t\tif (D[i][s] <= EPS) {\n\t\t\t\t\tcontinue;\n\t\t\
    \t\t}\n\t\t\t\tif (r == -1 || std::make_pair(D[i][n + 1] / D[i][s], B[i]) \n\t\
    \t\t\t\t< std::make_pair(D[r][n + 1] / D[r][s], B[r])) {\n\t\t\t\t\tr = i;\n\t\
    \t\t\t}\n\t\t\t}\n\t\t\tif (r == -1) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\t\
    pivot(r, s);\n\t\t}\n\t}\n\n\tT solve(std::vector<T>& x) {\n\t\tint r = 0;\n\t\
    \tfor (int i = 1; i < m; ++i) {\n\t\t\tif (D[i][n + 1] < D[r][n + 1]) {\n\t\t\t\
    \tr = i;\n\t\t\t}\n\t\t}\n\t\tif (D[r][n + 1] < -EPS) {\n\t\t\tpivot(r, n);\n\t\
    \t\tif (!simplex(2) || D[m + 1][n + 1] < -EPS) {\n\t\t\t\treturn -INF;\n\t\t\t\
    }\n\t\t\tfor (int i = 0; i < m; ++i) {\n\t\t\t\tif (B[i] == -1) {\n\t\t\t\t\t\
    int s = 0;\n\t\t\t\t\tfor (int j = 1; j < n + 1; ++j) {\n\t\t\t\t\t\tif (s ==\
    \ -1 || std::make_pair(D[i][j], N[j]) < std::make_pair(D[i][s], N[s])) {\n\t\t\
    \t\t\t\t\ts = j;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tpivot(i, s);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\tbool ok = simplex(1);\n\t\tx.assign(n, 0);\n\t\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\t\tif (B[i] < n) {\n\t\t\t\tx[B[i]] = D[i][n + 1];\n\
    \t\t\t}\n\t\t}\n\t\treturn ok ? D[m][n + 1] : INF;\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct Simplex {\n\tconst T EPS = 1e-8;\n\
    \tconst T INF = 1 / .0;\n\t\n\tint m, n; // constraints, variables\n\n\tstd::vector<int>\
    \ N, B;\n\n\tstd::vector<std::vector<T>> D;\n\n\tSimplex(const std::vector<std::vector<T>>&\
    \ A, const std::vector<T>& b, const std::vector<T>& c) : \n\tm(b.size()), n(c.size()),\
    \ N(n + 1), B(m), D(m + 2, std::vector<T>(n + 2)) {\n\t\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\t\tfor (int j = 0; j < n; ++j) {\n\t\t\t\tD[i][j] = A[i][j];\n\t\t\
    \t}\n\t\t}\n\t\tfor (int i = 0; i < m; ++i) {\n\t\t\tB[i] = n + i;\n\t\t\tD[i][n]\
    \ = -1;\n\t\t\tD[i][n + 1] = b[i];\n\t\t}\n\t\tfor (int j = 0; j < n; ++j) {\n\
    \t\t\tN[j] = j;\n\t\t\tD[m][j] = -c[j];\n\t\t}\n\t\tN[n] = -1;\n\t\tD[m + 1][n]\
    \ = 1;\n\t}\n\n\tvoid pivot(int r, int s) {\n\t\tT *a = D[r].data(), inv = 1 /\
    \ a[s];\n\t\tfor (int i = 0; i < m + 2; ++i) {\n\t\t\tif (i != r && std::abs(D[i][s])\
    \ > EPS) {\n\t\t\t\tT *b = D[i].data(), binv = b[s] * inv;\n\t\t\t\tfor (int j\
    \ = 0; j < n + 2; ++j) {\n\t\t\t\t\tb[j] -= a[j] * binv;\n\t\t\t\t}\n\t\t\t\t\
    b[s] = a[s] * binv;\n\t\t\t}\n\t\t}\n\t\tfor (int j = 0; j < n + 2; ++j) {\n\t\
    \t\tif (j != s) {\n\t\t\t\tD[r][j] *= inv;\n\t\t\t}\n\t\t}\n\t\tfor (int i = 0;\
    \ i < m + 2; ++i) {\n\t\t\tif (i != r) {\n\t\t\t\tD[i][s] *= -inv;\n\t\t\t}\n\t\
    \t}\n\t\tD[r][s] = inv;\n\t\tstd::swap(B[r], N[s]);\n\t}\n\n\tbool simplex(int\
    \ phase) {\n\t\tint x = m + phase - 1;\n\t\twhile (true) {\n\t\t\tint s = -1;\n\
    \t\t\tfor (int j = 0; j < n + 1; ++j) {\n\t\t\t\tif (N[j] != -phase) {\n\t\t\t\
    \t\tif (s == -1 || std::make_pair(D[x][j], N[j]) < std::make_pair(D[x][s], N[s]))\
    \ {\n\t\t\t\t\t\ts = j;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (D[x][s] >=\
    \ -EPS) {\n\t\t\t\treturn true;\n\t\t\t}\n\t\t\tint r = -1;\n\t\t\tfor (int i\
    \ = 0; i < m; ++i) {\n\t\t\t\tif (D[i][s] <= EPS) {\n\t\t\t\t\tcontinue;\n\t\t\
    \t\t}\n\t\t\t\tif (r == -1 || std::make_pair(D[i][n + 1] / D[i][s], B[i]) \n\t\
    \t\t\t\t< std::make_pair(D[r][n + 1] / D[r][s], B[r])) {\n\t\t\t\t\tr = i;\n\t\
    \t\t\t}\n\t\t\t}\n\t\t\tif (r == -1) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\t\
    pivot(r, s);\n\t\t}\n\t}\n\n\tT solve(std::vector<T>& x) {\n\t\tint r = 0;\n\t\
    \tfor (int i = 1; i < m; ++i) {\n\t\t\tif (D[i][n + 1] < D[r][n + 1]) {\n\t\t\t\
    \tr = i;\n\t\t\t}\n\t\t}\n\t\tif (D[r][n + 1] < -EPS) {\n\t\t\tpivot(r, n);\n\t\
    \t\tif (!simplex(2) || D[m + 1][n + 1] < -EPS) {\n\t\t\t\treturn -INF;\n\t\t\t\
    }\n\t\t\tfor (int i = 0; i < m; ++i) {\n\t\t\t\tif (B[i] == -1) {\n\t\t\t\t\t\
    int s = 0;\n\t\t\t\t\tfor (int j = 1; j < n + 1; ++j) {\n\t\t\t\t\t\tif (s ==\
    \ -1 || std::make_pair(D[i][j], N[j]) < std::make_pair(D[i][s], N[s])) {\n\t\t\
    \t\t\t\t\ts = j;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tpivot(i, s);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\tbool ok = simplex(1);\n\t\tx.assign(n, 0);\n\t\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\t\tif (B[i] < n) {\n\t\t\t\tx[B[i]] = D[i][n + 1];\n\
    \t\t\t}\n\t\t}\n\t\treturn ok ? D[m][n + 1] : INF;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/simplex.hpp
  requiredBy: []
  timestamp: '2021-08-16 13:31:52-04:00'
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

