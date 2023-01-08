---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/matrix2.hpp
    title: library/numerical/matrix2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://open.kattis.com/problems/equationsolver
    links:
    - https://open.kattis.com/problems/equationsolver
  bundledCode: "#define PROBLEM \"https://open.kattis.com/problems/equationsolver\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nnamespace MatrixOperations\
    \ {\r\n\r\ntemplate <class T> using Matrix = std::vector<std::vector<T>>;\r\n\r\
    \ntemplate <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r,\
    \ std::vector<T>(c)); }\r\n\r\ntemplate <class T> Matrix<T>& operator+=(Matrix<T>&\
    \ a, const Matrix<T>& b) {\r\n\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\
    \tfor (int j = 0; j < (int)a[0].size(); j++) {\r\n\t\t\ta[i][j] += b[i][j];\r\n\
    \t\t}\r\n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate <class T> Matrix<T>& operator-=(Matrix<T>&\
    \ a, const Matrix<T>& b) {\r\n\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\
    \tfor (int j = 0; j < (int)a[0].size(); j++) {\r\n\t\t\ta[i][j] -= b[i][j];\r\n\
    \t\t}\r\n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate <class T> Matrix<T> operator*(const\
    \ Matrix<T>& a, const Matrix<T>& b) {\r\n\tassert(a[0].size() == b.size());\r\n\
    \tint x = (int)a.size();\r\n\tint y = (int)a[0].size();\r\n\tint z = (int)b[0].size();\r\
    \n\tMatrix<T> c = make_matrix<T>(x, z);\r\n\tfor (int i = 0; i < x; i++) {\r\n\
    \t\tfor (int j = 0; j < y; j++) {\r\n\t\t\tfor (int k = 0; k < z; k++) {\r\n\t\
    \t\t\tc[i][k] += a[i][j] * b[j][k];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn c;\r\
    \n}\r\n\r\ntemplate <class T> Matrix<T> operator+(Matrix<T> a, const Matrix<T>&\
    \ b) { return a += b; }\r\ntemplate <class T> Matrix<T> operator-(Matrix<T> a,\
    \ const Matrix<T>& b) { return a -= b; }\r\ntemplate <class T> Matrix<T>& operator*=(Matrix<T>&\
    \ a, const Matrix<T>& b) { return a = a * b; }\r\n\r\ntemplate <class T> Matrix<T>\
    \ pow(Matrix<T> m, long long p) {\r\n\tint n = (int)m.size();\r\n\tassert(n ==\
    \ (int)m[0].size() && p >= 0);\r\n\tMatrix<T> res = make_matrix<T>(n, n);\r\n\t\
    for (int i = 0; i < n; i++) \r\n\t\tres[i][i] = 1;\r\n\tfor (; p; p >>= 1, m *=\
    \ m) {\r\n\t\tif (p & 1) {\r\n\t\t\tres *= m;\r\n\t\t}\r\n\t}\r\n\treturn res;\r\
    \n}\r\n\r\ntemplate <class T> int get_row(Matrix<T>& m, int r, int i, int nxt)\
    \ {\r\n\tfor (int j = nxt; j < r; j++) {\r\n\t\tif (m[j][i] != 0) {\r\n\t\t\t\
    return j;\r\n\t\t}\r\n\t}\r\n\treturn -1;\r\n}\r\n\r\nconst long double EPS =\
    \ 1e-12;\r\n\r\ntemplate <> int get_row<long double>(Matrix<long double>& m, int\
    \ r, int i, int nxt) {\r\n\tstd::pair<long double, int> best = {0, -1};\r\n\t\
    for (int j = nxt; j < r; j++) {\r\n\t\tbest = std::max(best, {abs(m[j][i]), j});\r\
    \n\t}\r\n\treturn best.first < EPS ? -1 : best.second;\r\n}\r\n\r\n// returns\
    \ a pair of determinant, rank, while doing Gaussian elimination to m\r\ntemplate\
    \ <class T> std::pair<T, int> gauss(Matrix<T>& m) {\r\n\tint r = (int)m.size();\r\
    \n\tint c = (int)m[0].size();\r\n\tint rank = 0, nxt = 0;\r\n\tT prod = 1;\r\n\
    \tfor (int i = 0; i < r; i++) {\r\n\t\tint row = get_row(m, r, i, nxt);\r\n\t\t\
    if (row == -1) {\r\n\t\t\tprod = 0;\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tif (row\
    \ != nxt) {\r\n\t\t\tprod *= -1;\r\n\t\t\tm[row].swap(m[nxt]);\r\n\t\t}\r\n\t\t\
    prod *= m[nxt][i];\r\n\t\trank++;\r\n\t\tT x = 1 / m[nxt][i];\r\n\t\tfor (int\
    \ k = i; k < c; k++) \r\n\t\t\tm[nxt][k] *= x;\r\n\t\tfor (int j = 0; j < r; j++)\
    \ {\r\n\t\t\tif (j != nxt) {\r\n\t\t\t\tT v = m[j][i];\r\n\t\t\t\tif (v == 0)\
    \ continue;\r\n\t\t\t\tfor (int k = i; k < c; k++) {\r\n\t\t\t\t\tm[j][k] -= v\
    \ * m[nxt][k];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tnxt++;\r\n\t}\r\n\treturn\
    \ {prod, rank};\r\n}\r\n\r\ntemplate <class T> Matrix<T> inv(Matrix<T> m) {\r\n\
    \tint r = (int)m.size();\r\n\tassert(r == (int)m[0].size());\r\n\tMatrix<T> x\
    \ = make_matrix<T>(r, 2 * r);\r\n\tfor (int i = 0; i < r; i++) {\r\n\t\tx[i][i\
    \ + r] = 1;\r\n\t\tfor (int j = 0; j < r; j++) {\r\n\t\t\tx[i][j] = m[i][j];\r\
    \n\t\t}\r\n\t}\r\n\tif (gauss(x).second != r) return Matrix<T>();\r\n\tMatrix<T>\
    \ res = make_matrix<T>(r, r);\r\n\tfor (int i = 0; i < r; i++) {\r\n\t\tfor (int\
    \ j = 0; j < r; j++) {\r\n\t\t\tres[i][j] = x[i][j + r];\r\n\t\t}\r\n\t}\r\n\t\
    return res;\r\n}\r\n\r\n} // namespace MatrixOperations\n\r\n// kattis\r\nint\
    \ main() {\r\n\tusing namespace std;\r\n\tusing namespace MatrixOperations;\r\n\
    \tusing Mat = Matrix<long double>;\r\n\twhile (true) {\r\n\t\tint n; cin >> n;\r\
    \n\t\tif (n == 0) break;\r\n\t\tMat a = make_matrix<long double>(n, n + 1);\r\n\
    \t\tfor (int i = 0; i < n; i++) {\r\n\t\t\tfor (int j = 0; j < n; j++) {\r\n\t\
    \t\t\tcin >> a[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i = 0; i < n; i++) {\r\
    \n\t\t\tcin >> a[i][n];\r\n\t\t}\r\n\t\tauto res = gauss(a);\r\n\t\tvector<long\
    \ double> ans;\r\n\t\tbool inf = false;\r\n\t\tbool sol = true;\r\n\t\tfor (int\
    \ i = 0; i < n; i++) {  \r\n\t\t\tbool one = false;\r\n\t\t\tfor (int j = 0; j\
    \ < n; j++) {\r\n\t\t\t\tif (abs(a[i][j] - 1) < EPS) {\r\n\t\t\t\t\tone = true;\r\
    \n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (one) {\r\n\t\t\t\tans.push_back(a[i].back());\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tif (abs(a[i].back()) >= EPS) {\r\n\t\t\
    \t\tsol = false;\r\n\t\t\t\tbreak;\r\n\t\t\t} \r\n\t\t\tif (abs(a[i].back()) <\
    \ EPS) {\r\n\t\t\t\tinf = true;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (!sol) {\r\n\t\t\
    \tcout << \"inconsistent\\n\";\r\n\t\t} else if (inf) {\r\n\t\t\tcout << \"multiple\\\
    n\";\r\n\t\t} else {\r\n\t\t\tfor (auto& t : ans) \r\n\t\t\t\tcout << t << \"\
    \ \";\r\n\t\t\tcout << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/problems/equationsolver\"\r\n\r\
    \n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/numerical/matrix2.hpp\"\
    \r\n\r\n// kattis\r\nint main() {\r\n\tusing namespace std;\r\n\tusing namespace\
    \ MatrixOperations;\r\n\tusing Mat = Matrix<long double>;\r\n\twhile (true) {\r\
    \n\t\tint n; cin >> n;\r\n\t\tif (n == 0) break;\r\n\t\tMat a = make_matrix<long\
    \ double>(n, n + 1);\r\n\t\tfor (int i = 0; i < n; i++) {\r\n\t\t\tfor (int j\
    \ = 0; j < n; j++) {\r\n\t\t\t\tcin >> a[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor\
    \ (int i = 0; i < n; i++) {\r\n\t\t\tcin >> a[i][n];\r\n\t\t}\r\n\t\tauto res\
    \ = gauss(a);\r\n\t\tvector<long double> ans;\r\n\t\tbool inf = false;\r\n\t\t\
    bool sol = true;\r\n\t\tfor (int i = 0; i < n; i++) {  \r\n\t\t\tbool one = false;\r\
    \n\t\t\tfor (int j = 0; j < n; j++) {\r\n\t\t\t\tif (abs(a[i][j] - 1) < EPS) {\r\
    \n\t\t\t\t\tone = true;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\t\
    if (one) {\r\n\t\t\t\tans.push_back(a[i].back());\r\n\t\t\t\tcontinue;\r\n\t\t\
    \t}\r\n\t\t\tif (abs(a[i].back()) >= EPS) {\r\n\t\t\t\tsol = false;\r\n\t\t\t\t\
    break;\r\n\t\t\t} \r\n\t\t\tif (abs(a[i].back()) < EPS) {\r\n\t\t\t\tinf = true;\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif (!sol) {\r\n\t\t\tcout << \"inconsistent\\n\";\r\n\
    \t\t} else if (inf) {\r\n\t\t\tcout << \"multiple\\n\";\r\n\t\t} else {\r\n\t\t\
    \tfor (auto& t : ans) \r\n\t\t\t\tcout << t << \" \";\r\n\t\t\tcout << '\\n';\r\
    \n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/matrix2.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-equationsolver.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-equationsolver.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-equationsolver.test.cpp
- /verify/verify/kattis/kattis-equationsolver.test.cpp.html
title: verify/kattis/kattis-equationsolver.test.cpp
---
