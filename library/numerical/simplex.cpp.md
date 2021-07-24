---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/simplex.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * Maximizes c^Tx given Ax <= b, x >= 0\n * Returns -INF if no solution\n\
    \ * INF if there are many good solutions\n * Maximum value of c^Tx otherwise\n\
    \ */\n\ntemplate <class T> struct Simplex {\n\tconst T EPS = 1e-8;\n\tconst T\
    \ INF = 1 / .0;\n\t\n\tint m, n; // constraints, variables\n\n\tstd::vector<int>\
    \ N, B;\n\n\tstd::vector<std::vector<T>> D;\n\n\tSimplex(const std::vector<std::vector<T>>\
    \ &A, const std::vector<T> &b, const std::vector<T> &c) : \n\tm(b.size()), n(c.size()),\
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
    pivot(r, s);\n\t\t}\n\t}\n\n\tT solve(std::vector<T> &x) {\n\t\tint r = 0;\n\t\
    \tfor (int i = 1; i < m; ++i) {\n\t\t\tif (D[i][n + 1] < D[r][n + 1]) {\n\t\t\t\
    \tr = i;\n\t\t\t}\n\t\t}\n\t\tif (D[r][n + 1] < -EPS) {\n\t\t\tpivot(r, n);\n\t\
    \t\tif (!simplex(2) || D[m + 1][n + 1] < -EPS) {\n\t\t\t\treturn -INF;\n\t\t\t\
    }\n\t\t\tfor (int i = 0; i < m; ++i) {\n\t\t\t\tif (B[i] == -1) {\n\t\t\t\t\t\
    int s = 0;\n\t\t\t\t\tfor (int j = 1; j < n + 1; ++j) {\n\t\t\t\t\t\tif (s ==\
    \ -1 || std::make_pair(D[i][j], N[j]) < std::make_pair(D[i][s], N[s])) {\n\t\t\
    \t\t\t\t\ts = j;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tpivot(i, s);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\tbool ok = simplex(1);\n\t\tx.assign(n, 0);\n\t\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\t\tif (B[i] < n) {\n\t\t\t\tx[B[i]] = D[i][n + 1];\n\
    \t\t\t}\n\t\t}\n\t\treturn ok ? D[m][n + 1] : INF;\n\t}\n};\n\nint main() {\n\t\
    using namespace std;\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\t\
    int n, m; \n\tcin >> n >> m;\n\tvector<vector<double>> A(n, vector<double>(m));\n\
    \tvector<double> c(m);\n\tvector<double> b(n);\n\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\tcin >> b[i];\n\t}\n\tfor (int i = 0; i < m; ++i) {\n\t\tfor (int j =\
    \ 0; j < n; ++j) {\n\t\t\tcin >> A[j][i];\n\t\t\tA[j][i] /= 100;\n\t\t}\n\t\t\
    cin >> c[i];\n\t}\n\tvector<double> x; \n\tdouble ans = Simplex<double>(A, b,\
    \ c).solve(x);\n\tcout << fixed << setprecision(2) << ans << '\\n';\n\treturn\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Maximizes c^Tx given Ax <= b, x >= 0\n\
    \ * Returns -INF if no solution\n * INF if there are many good solutions\n * Maximum\
    \ value of c^Tx otherwise\n */\n\ntemplate <class T> struct Simplex {\n\tconst\
    \ T EPS = 1e-8;\n\tconst T INF = 1 / .0;\n\t\n\tint m, n; // constraints, variables\n\
    \n\tstd::vector<int> N, B;\n\n\tstd::vector<std::vector<T>> D;\n\n\tSimplex(const\
    \ std::vector<std::vector<T>> &A, const std::vector<T> &b, const std::vector<T>\
    \ &c) : \n\tm(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, std::vector<T>(n\
    \ + 2)) {\n\t\tfor (int i = 0; i < m; ++i) {\n\t\t\tfor (int j = 0; j < n; ++j)\
    \ {\n\t\t\t\tD[i][j] = A[i][j];\n\t\t\t}\n\t\t}\n\t\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\t\tB[i] = n + i;\n\t\t\tD[i][n] = -1;\n\t\t\tD[i][n + 1] = b[i];\n\t\t\
    }\n\t\tfor (int j = 0; j < n; ++j) {\n\t\t\tN[j] = j;\n\t\t\tD[m][j] = -c[j];\n\
    \t\t}\n\t\tN[n] = -1;\n\t\tD[m + 1][n] = 1;\n\t}\n\n\tvoid pivot(int r, int s)\
    \ {\n\t\tT *a = D[r].data(), inv = 1 / a[s];\n\t\tfor (int i = 0; i < m + 2; ++i)\
    \ {\n\t\t\tif (i != r && std::abs(D[i][s]) > EPS) {\n\t\t\t\tT *b = D[i].data(),\
    \ binv = b[s] * inv;\n\t\t\t\tfor (int j = 0; j < n + 2; ++j) {\n\t\t\t\t\tb[j]\
    \ -= a[j] * binv;\n\t\t\t\t}\n\t\t\t\tb[s] = a[s] * binv;\n\t\t\t}\n\t\t}\n\t\t\
    for (int j = 0; j < n + 2; ++j) {\n\t\t\tif (j != s) {\n\t\t\t\tD[r][j] *= inv;\n\
    \t\t\t}\n\t\t}\n\t\tfor (int i = 0; i < m + 2; ++i) {\n\t\t\tif (i != r) {\n\t\
    \t\t\tD[i][s] *= -inv;\n\t\t\t}\n\t\t}\n\t\tD[r][s] = inv;\n\t\tstd::swap(B[r],\
    \ N[s]);\n\t}\n\n\tbool simplex(int phase) {\n\t\tint x = m + phase - 1;\n\t\t\
    while (true) {\n\t\t\tint s = -1;\n\t\t\tfor (int j = 0; j < n + 1; ++j) {\n\t\
    \t\t\tif (N[j] != -phase) {\n\t\t\t\t\tif (s == -1 || std::make_pair(D[x][j],\
    \ N[j]) < std::make_pair(D[x][s], N[s])) {\n\t\t\t\t\t\ts = j;\n\t\t\t\t\t}\n\t\
    \t\t\t}\n\t\t\t}\n\t\t\tif (D[x][s] >= -EPS) {\n\t\t\t\treturn true;\n\t\t\t}\n\
    \t\t\tint r = -1;\n\t\t\tfor (int i = 0; i < m; ++i) {\n\t\t\t\tif (D[i][s] <=\
    \ EPS) {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tif (r == -1 || std::make_pair(D[i][n\
    \ + 1] / D[i][s], B[i]) \n\t\t\t\t\t< std::make_pair(D[r][n + 1] / D[r][s], B[r]))\
    \ {\n\t\t\t\t\tr = i;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (r == -1) {\n\t\t\t\treturn\
    \ false;\n\t\t\t}\n\t\t\tpivot(r, s);\n\t\t}\n\t}\n\n\tT solve(std::vector<T>\
    \ &x) {\n\t\tint r = 0;\n\t\tfor (int i = 1; i < m; ++i) {\n\t\t\tif (D[i][n +\
    \ 1] < D[r][n + 1]) {\n\t\t\t\tr = i;\n\t\t\t}\n\t\t}\n\t\tif (D[r][n + 1] < -EPS)\
    \ {\n\t\t\tpivot(r, n);\n\t\t\tif (!simplex(2) || D[m + 1][n + 1] < -EPS) {\n\t\
    \t\t\treturn -INF;\n\t\t\t}\n\t\t\tfor (int i = 0; i < m; ++i) {\n\t\t\t\tif (B[i]\
    \ == -1) {\n\t\t\t\t\tint s = 0;\n\t\t\t\t\tfor (int j = 1; j < n + 1; ++j) {\n\
    \t\t\t\t\t\tif (s == -1 || std::make_pair(D[i][j], N[j]) < std::make_pair(D[i][s],\
    \ N[s])) {\n\t\t\t\t\t\t\ts = j;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tpivot(i,\
    \ s);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tbool ok = simplex(1);\n\t\tx.assign(n, 0);\n\
    \t\tfor (int i = 0; i < m; ++i) {\n\t\t\tif (B[i] < n) {\n\t\t\t\tx[B[i]] = D[i][n\
    \ + 1];\n\t\t\t}\n\t\t}\n\t\treturn ok ? D[m][n + 1] : INF;\n\t}\n};\n\nint main()\
    \ {\n\tusing namespace std;\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint n, m; \n\tcin >> n >> m;\n\tvector<vector<double>> A(n, vector<double>(m));\n\
    \tvector<double> c(m);\n\tvector<double> b(n);\n\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\tcin >> b[i];\n\t}\n\tfor (int i = 0; i < m; ++i) {\n\t\tfor (int j =\
    \ 0; j < n; ++j) {\n\t\t\tcin >> A[j][i];\n\t\t\tA[j][i] /= 100;\n\t\t}\n\t\t\
    cin >> c[i];\n\t}\n\tvector<double> x; \n\tdouble ans = Simplex<double>(A, b,\
    \ c).solve(x);\n\tcout << fixed << setprecision(2) << ans << '\\n';\n\treturn\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/simplex.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/simplex.cpp
layout: document
redirect_from:
- /library/library/numerical/simplex.cpp
- /library/library/numerical/simplex.cpp.html
title: library/numerical/simplex.cpp
---
