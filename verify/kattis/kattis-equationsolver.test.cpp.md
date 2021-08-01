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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nnamespace MatrixOperations {\n\ntemplate <class T> using Matrix = std::vector<std::vector<T>>;\n\
    \ntemplate <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r,\
    \ std::vector<T>(c)); }\n\ntemplate <class T> Matrix<T>& operator+=(Matrix<T>&\
    \ a, const Matrix<T>& b) {\n\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\
    for (int j = 0; j < (int)a[0].size(); j++) {\n\t\t\ta[i][j] += b[i][j];\n\t\t\
    }\n\t}\n\treturn a;\n}\n\ntemplate <class T> Matrix<T>& operator-=(Matrix<T>&\
    \ a, const Matrix<T>& b) {\n\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\
    for (int j = 0; j < (int)a[0].size(); j++) {\n\t\t\ta[i][j] -= b[i][j];\n\t\t\
    }\n\t}\n\treturn a;\n}\n\ntemplate <class T> Matrix<T> operator*(const Matrix<T>&\
    \ a, const Matrix<T>& b) {\n\tassert(a[0].size() == b.size());\n\tint x = (int)a.size();\n\
    \tint y = (int)a[0].size();\n\tint z = (int)b[0].size();\n\tMatrix<T> c = make_matrix<T>(x,\
    \ z);\n\tfor (int i = 0; i < x; i++) {\n\t\tfor (int j = 0; j < y; j++) {\n\t\t\
    \tfor (int k = 0; k < z; k++) {\n\t\t\t\tc[i][k] += a[i][j] * b[j][k];\n\t\t\t\
    }\n\t\t}\n\t}\n\treturn c;\n}\n\ntemplate <class T> Matrix<T> operator+(Matrix<T>\
    \ a, const Matrix<T>& b) { return a += b; }\ntemplate <class T> Matrix<T> operator-(Matrix<T>\
    \ a, const Matrix<T>& b) { return a -= b; }\ntemplate <class T> Matrix<T>& operator*=(Matrix<T>&\
    \ a, const Matrix<T>& b) { return a = a * b; }\n\ntemplate <class T> Matrix<T>\
    \ pow(Matrix<T> m, long long p) {\n\tint n = (int)m.size();\n\tassert(n == (int)m[0].size()\
    \ && p >= 0);\n\tMatrix<T> res = make_matrix<T>(n, n);\n\tfor (int i = 0; i <\
    \ n; i++) \n\t\tres[i][i] = 1;\n\tfor (; p; p >>= 1, m *= m) {\n\t\tif (p & 1)\
    \ {\n\t\t\tres *= m;\n\t\t}\n\t}\n\treturn res;\n}\n\ntemplate <class T> int get_row(Matrix<T>&\
    \ m, int r, int i, int nxt) {\n\tfor (int j = nxt; j < r; j++) {\n\t\tif (m[j][i]\
    \ != 0) {\n\t\t\treturn j;\n\t\t}\n\t}\n\treturn -1;\n}\n\nconst long double EPS\
    \ = 1e-12;\n\ntemplate <> int get_row<long double>(Matrix<long double>& m, int\
    \ r, int i, int nxt) {\n\tstd::pair<long double, int> best = {0, -1};\n\tfor (int\
    \ j = nxt; j < r; j++) {\n\t\tbest = std::max(best, {abs(m[j][i]), j});\n\t}\n\
    \treturn best.first < EPS ? -1 : best.second;\n}\n\n// returns a pair of determinant,\
    \ rank, while doing Gaussian elimination to m\ntemplate <class T> std::pair<T,\
    \ int> gauss(Matrix<T>& m) {\n\tint r = (int)m.size();\n\tint c = (int)m[0].size();\n\
    \tint rank = 0, nxt = 0;\n\tT prod = 1;\n\tfor (int i = 0; i < r; i++) {\n\t\t\
    int row = get_row(m, r, i, nxt);\n\t\tif (row == -1) {\n\t\t\tprod = 0;\n\t\t\t\
    continue;\n\t\t}\n\t\tif (row != nxt) {\n\t\t\tprod *= -1;\n\t\t\tm[row].swap(m[nxt]);\n\
    \t\t}\n\t\tprod *= m[nxt][i];\n\t\trank++;\n\t\tT x = 1 / m[nxt][i];\n\t\tfor\
    \ (int k = i; k < c; k++) \n\t\t\tm[nxt][k] *= x;\n\t\tfor (int j = 0; j < r;\
    \ j++) {\n\t\t\tif (j != nxt) {\n\t\t\t\tT v = m[j][i];\n\t\t\t\tif (v == 0) continue;\n\
    \t\t\t\tfor (int k = i; k < c; k++) {\n\t\t\t\t\tm[j][k] -= v * m[nxt][k];\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t\tnxt++;\n\t}\n\treturn {prod, rank};\n}\n\ntemplate\
    \ <class T> Matrix<T> inv(Matrix<T> m) {\n\tint r = (int)m.size();\n\tassert(r\
    \ == (int)m[0].size());\n\tMatrix<T> x = make_matrix<T>(r, 2 * r);\n\tfor (int\
    \ i = 0; i < r; i++) {\n\t\tx[i][i + r] = 1;\n\t\tfor (int j = 0; j < r; j++)\
    \ {\n\t\t\tx[i][j] = m[i][j];\n\t\t}\n\t}\n\tif (gauss(x).second != r) return\
    \ Matrix<T>();\n\tMatrix<T> res = make_matrix<T>(r, r);\n\tfor (int i = 0; i <\
    \ r; i++) {\n\t\tfor (int j = 0; j < r; j++) {\n\t\t\tres[i][j] = x[i][j + r];\n\
    \t\t}\n\t}\n\treturn res;\n}\n\n} // namespace MatrixOperations\n\n// kattis\n\
    int main() {\n\tusing namespace std;\n\tusing namespace MatrixOperations;\n\t\
    using Mat = Matrix<long double>;\n\twhile (true) {\n\t\tint n; cin >> n;\n\t\t\
    if (n == 0) break;\n\t\tMat a = make_matrix<long double>(n, n + 1);\n\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tcin >> a[i][j];\n\
    \t\t\t}\n\t\t}\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tcin >> a[i][n];\n\t\t\
    }\n\t\tauto res = gauss(a);\n\t\tvector<long double> ans;\n\t\tbool inf = false;\n\
    \t\tbool sol = true;\n\t\tfor (int i = 0; i < n; i++) {  \n\t\t\tbool one = false;\n\
    \t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tif (abs(a[i][j] - 1) < EPS) {\n\t\
    \t\t\t\tone = true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (one) {\n\t\
    \t\t\tans.push_back(a[i].back());\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tif (abs(a[i].back())\
    \ >= EPS) {\n\t\t\t\tsol = false;\n\t\t\t\tbreak;\n\t\t\t} \n\t\t\tif (abs(a[i].back())\
    \ < EPS) {\n\t\t\t\tinf = true;\n\t\t\t}\n\t\t}\n\t\tif (!sol) {\n\t\t\tcout <<\
    \ \"inconsistent\\n\";\n\t\t} else if (inf) {\n\t\t\tcout << \"multiple\\n\";\n\
    \t\t} else {\n\t\t\tfor (auto& t : ans) \n\t\t\t\tcout << t << \" \";\n\t\t\t\
    cout << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/problems/equationsolver\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/numerical/matrix2.hpp\"\
    \n\n// kattis\nint main() {\n\tusing namespace std;\n\tusing namespace MatrixOperations;\n\
    \tusing Mat = Matrix<long double>;\n\twhile (true) {\n\t\tint n; cin >> n;\n\t\
    \tif (n == 0) break;\n\t\tMat a = make_matrix<long double>(n, n + 1);\n\t\tfor\
    \ (int i = 0; i < n; i++) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tcin\
    \ >> a[i][j];\n\t\t\t}\n\t\t}\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tcin >>\
    \ a[i][n];\n\t\t}\n\t\tauto res = gauss(a);\n\t\tvector<long double> ans;\n\t\t\
    bool inf = false;\n\t\tbool sol = true;\n\t\tfor (int i = 0; i < n; i++) {  \n\
    \t\t\tbool one = false;\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tif (abs(a[i][j]\
    \ - 1) < EPS) {\n\t\t\t\t\tone = true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\tif (one) {\n\t\t\t\tans.push_back(a[i].back());\n\t\t\t\tcontinue;\n\t\t\
    \t}\n\t\t\tif (abs(a[i].back()) >= EPS) {\n\t\t\t\tsol = false;\n\t\t\t\tbreak;\n\
    \t\t\t} \n\t\t\tif (abs(a[i].back()) < EPS) {\n\t\t\t\tinf = true;\n\t\t\t}\n\t\
    \t}\n\t\tif (!sol) {\n\t\t\tcout << \"inconsistent\\n\";\n\t\t} else if (inf)\
    \ {\n\t\t\tcout << \"multiple\\n\";\n\t\t} else {\n\t\t\tfor (auto& t : ans) \n\
    \t\t\t\tcout << t << \" \";\n\t\t\tcout << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/matrix2.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-equationsolver.test.cpp
  requiredBy: []
  timestamp: '2021-07-31 14:30:12-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-equationsolver.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-equationsolver.test.cpp
- /verify/verify/kattis/kattis-equationsolver.test.cpp.html
title: verify/kattis/kattis-equationsolver.test.cpp
---
