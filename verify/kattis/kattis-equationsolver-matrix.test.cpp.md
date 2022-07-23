---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/matrix.hpp
    title: library/numerical/matrix.hpp
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
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class D> struct\
    \ Matrix : std::vector<std::vector<D>> {\r\n\tusing std::vector<std::vector<D>>::vector;\r\
    \n\r\n\tint h() const { return int(this->size()); }\r\n\tint w() const { return\
    \ int((*this)[0].size()); }\r\n\r\n\tMatrix operator*(const Matrix& r) const {\r\
    \n\t\tassert(w() == r.h());\r\n\t\tMatrix res(h(), std::vector<D>(r.w()));\r\n\
    \t\tfor (int i = 0; i < h(); i++) {\r\n\t\t\tfor (int j = 0; j < r.w(); j++) {\r\
    \n\t\t\t\tfor (int k = 0; k < w(); k++) {\r\n\t\t\t\t\tres[i][j] += (*this)[i][k]\
    \ * r[k][j];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\
    \tMatrix<D>& operator+=(const Matrix& r) {\r\n\t\tassert(h() == r.h() && w() ==\
    \ r.w());\r\n\t\tfor (int i = 0; i < h(); i++) {\r\n\t\t\tfor (int j = 0; j <\
    \ h(); j++) {\r\n\t\t\t\t(*this)[i][j] += r[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    return *this;\r\n\t}\r\n\r\n\tMatrix& operator-=(const Matrix& r) {\r\n\t\tassert(h()\
    \ == r.h() && w() == r.w());\r\n\t\tfor (int i = 0; i < h(); i++) {\r\n\t\t\t\
    for (int j = 0; j < h(); j++) {\r\n\t\t\t\t(*this)[i][j] -= r[i][j];\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix operator*(const D& r) const\
    \ {\r\n\t\tMatrix res = (*this);\r\n\t\tfor (int i = 0; i < h(); ++i) {\r\n\t\t\
    \tfor (int j = 0; j < w(); ++j) {\r\n\t\t\t\tres[i][j] *= r;\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\treturn res;\r\n\t}\r\n\r\n\tMatrix operator/(const D &r) const{ return\
    \ *this * (1 / r); }\r\n\tMatrix& operator*=(const Matrix& r) { return *this =\
    \ *this * r; }\r\n\tMatrix operator+(const Matrix& r) { return *this += r; }\r\
    \n\tMatrix operator-(const Matrix& r) { return *this -= r; }\r\n\tMatrix& operator*=(const\
    \ D& r) { return *this = *this * r; }\r\n\tMatrix& operator/=(const D &r) { return\
    \ *this = *this / r; }\r\n\tfriend Matrix operator*(const D& r, Matrix m) { return\
    \ m *= r; }\r\n\r\n\tMatrix pow(long long n) const {\r\n\t\tassert(h() == w());\r\
    \n\t\tMatrix x = *this, r(h(), std::vector<D>(w()));\r\n\t\tfor (int i = 0; i\
    \ < h(); i++) r[i][i] = D(1);\r\n\t\twhile (n) {\r\n\t\t\tif (n & 1) r *= x;\r\
    \n\t\t\tx *= x;\r\n\t\t\tn >>= 1;\r\n\t\t}\r\n\t\treturn r;\r\n\t}\r\n};\r\n\r\
    \nnamespace MatrixOperations {\r\n\r\ntemplate <class T> Matrix<T> make_matrix(int\
    \ r, int c) { return Matrix<T>(r, std::vector<T>(c)); }\r\n\r\ntemplate <class\
    \ D> int get_row(Matrix<D>& m, int r, int i, int nxt, const D& EPS = -1) {\r\n\
    \tstd::pair<D, int> best = {0, -1};\r\n\tfor (int j = nxt; j < r; j++) {\r\n\t\
    \tif (EPS == D(-1) && m[j][i] != 0) {\r\n\t\t\treturn j;\r\n\t\t}\r\n\t\tauto\
    \ v = m[j][i];\r\n\t\tif (v < 0) v = -v;\r\n\t\tbest = std::max(best, std::make_pair(v,\
    \ j));\r\n\t}\r\n\treturn best.first < EPS ? -1 : best.second;\r\n}\r\n\r\n//\
    \ returns a pair of determinant, rank, while doing Gaussian elimination to m\r\
    \ntemplate <class D> std::pair<D, int> gauss(Matrix<D>& m, const D& EPS = -1)\
    \ {\r\n\tint r = m.h();\r\n\tint c = m.w();\r\n\tint rank = 0, nxt = 0;\r\n\t\
    D prod = 1;\r\n\tfor (int i = 0; i < r; i++) {\r\n\t\tint row = get_row(m, r,\
    \ i, nxt, EPS);\r\n\t\tif (row == -1) {\r\n\t\t\tprod = 0;\r\n\t\t\tcontinue;\r\
    \n\t\t}\r\n\t\tif (row != nxt) {\r\n\t\t\tprod *= -1;\r\n\t\t\tm[row].swap(m[nxt]);\r\
    \n\t\t}\r\n\t\tprod *= m[nxt][i];\r\n\t\trank++;\r\n\t\tD x = 1 / m[nxt][i];\r\
    \n\t\tfor (int k = i; k < c; k++) \r\n\t\t\tm[nxt][k] *= x;\r\n\t\tfor (int j\
    \ = 0; j < r; j++) {\r\n\t\t\tif (j != nxt) {\r\n\t\t\t\tD v = m[j][i];\r\n\t\t\
    \t\tif (v == 0) continue;\r\n\t\t\t\tfor (int k = i; k < c; k++) {\r\n\t\t\t\t\
    \tm[j][k] -= v * m[nxt][k];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tnxt++;\r\n\
    \t}\r\n\treturn {prod, rank};\r\n}\r\n\r\ntemplate <class D> Matrix<D> inv(Matrix<D>\
    \ m, const D& EPS = -1) {\r\n\tint r = m.h();\r\n\tassert(m.h() == m.w());\r\n\
    \tMatrix<D> x = make_matrix<D>(r, 2 * r);\r\n\tfor (int i = 0; i < r; i++) {\r\
    \n\t\tx[i][i + r] = 1;\r\n\t\tfor (int j = 0; j < r; j++) {\r\n\t\t\tx[i][j] =\
    \ m[i][j];\r\n\t\t}\r\n\t}\r\n\tif (gauss(x, EPS).second != r) return Matrix<D>();\r\
    \n\tMatrix<D> res = make_matrix<D>(r, r);\r\n\tfor (int i = 0; i < r; i++) {\r\
    \n\t\tfor (int j = 0; j < r; j++) {\r\n\t\t\tres[i][j] = x[i][j + r];\r\n\t\t\
    }\r\n\t}\r\n\treturn res;\r\n}\r\n\r\ntemplate <class D> int calc_rank(Matrix<D>\
    \ a, const D& EPS = -1) { return gauss(a, EPS).second; }\r\ntemplate <class D>\
    \ D calc_det(Matrix<D> a, const D& EPS = -1) { return gauss(a, EPS).first; }\r\
    \n\r\ntemplate <class D> std::vector<std::vector<D>> solve_linear(Matrix<D> a,\
    \ std::vector<D> b, const D& EPS = -1) {\r\n\tint h = a.h(), w = a.w();\r\n\t\
    assert(int(b.size()) == h);\r\n\tint r = 0;\r\n\tstd::vector<bool> used(w);\r\n\
    \tstd::vector<int> idxs;\r\n\tfor (int x = 0; x < w; x++) {\r\n\t\tint my = get_row(a,\
    \ h, x, r, EPS);\r\n\t\tif (my == -1) continue;\r\n\t\tif (r != my) std::swap(a[r],\
    \ a[my]);\r\n\t\tstd::swap(b[r], b[my]);\r\n\t\tfor (int y = r + 1; y < h; y++)\
    \ {\r\n\t\t\tif (!a[y][x]) continue;\r\n\t\t\tauto freq = a[y][x] / a[r][x];\r\
    \n\t\t\tfor (int k = x; k < w; k++) a[y][k] -= freq * a[r][k];\r\n\t\t\tb[y] -=\
    \ freq * b[r];\r\n\t\t}\r\n\t\tr++;\r\n\t\tused[x] = true;\r\n\t\tidxs.push_back(x);\r\
    \n\t\tif (r == h) break;\r\n\t}\r\n\tauto zero = [&](const D& x) {\r\n\t\treturn\
    \ EPS == D(-1) ? x == 0 : -EPS < x && x < EPS;\r\n\t};\r\n\tfor (int y = r; y\
    \ < h; y++) {\r\n\t\tif (!zero(b[y])) return {};\r\n\t}\r\n\tstd::vector<std::vector<D>>\
    \ sols;\r\n\t{ // initial solution\r\n\t\tstd::vector<D> v(w);\r\n\t\tfor (int\
    \ y = r - 1; y >= 0; y--) {\r\n\t\t\tint f = idxs[y];\r\n\t\t\tv[f] = b[y];\r\n\
    \t\t\tfor (int x = f + 1; x < w; x++) {\r\n\t\t\t\tv[f] -= a[y][x] * v[x];\r\n\
    \t\t\t}\r\n\t\t\tv[f] /= a[y][f];\r\n\t\t}\r\n\t\tsols.push_back(v);\r\n\t}\r\n\
    \tfor (int s = 0; s < w; s++) {\r\n\t\tif (used[s]) continue;\r\n\t\tstd::vector<D>\
    \ v(w);\r\n\t\tv[s] = D(1);\r\n\t\tfor (int y = r - 1; y >= 0; y--) {\r\n\t\t\t\
    int f = idxs[y];\r\n\t\t\tfor (int x = f + 1; x < w; x++) {\r\n\t\t\t\tv[f] -=\
    \ a[y][x] * v[x];\r\n\t\t\t}\r\n\t\t\tv[f] /= a[y][f];\r\n\t\t}\r\n\t\tsols.push_back(v);\r\
    \n\t}\r\n\treturn sols;\r\n}\r\n\r\n} // MatrixOperations\n\r\n// kattis\r\nint\
    \ main() {\r\n\tusing namespace std;\r\n\tusing namespace MatrixOperations;\r\n\
    \tusing Mat = Matrix<long double>;\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\twhile (true) {\r\n\t\tint n; cin >> n;\r\n\t\tif (n == 0) break;\r\n\t\tMat\
    \ a = make_matrix<long double>(n, n);\r\n\t\tfor (int i = 0; i < n; i++) {\r\n\
    \t\t\tfor (int j = 0; j < n; j++) {\r\n\t\t\t\tcin >> a[i][j];\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\tvector<long double> b(n);\r\n\t\tfor (int i = 0; i < n; i++) {\r\n\t\
    \t\tcin >> b[i];\r\n\t\t}\r\n\t\tconst long double EPS = 1e-12;\r\n\t\tauto res\
    \ = solve_linear(a, b, EPS);\r\n\t\tif (res.empty()) {\r\n\t\t\tcout << \"inconsistent\\\
    n\";\r\n\t\t} else if ((int)res.size() > 1) {\r\n\t\t\tcout << \"multiple\\n\"\
    ;\r\n\t\t} else {\r\n\t\t\tfor (auto& t : res[0]) \r\n\t\t\t\tcout << t << \"\
    \ \";\r\n\t\t\tcout << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/problems/equationsolver\"\r\n\r\
    \n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/numerical/matrix.hpp\"\
    \r\n\r\n// kattis\r\nint main() {\r\n\tusing namespace std;\r\n\tusing namespace\
    \ MatrixOperations;\r\n\tusing Mat = Matrix<long double>;\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\twhile (true) {\r\n\t\tint n; cin >> n;\r\n\t\tif (n\
    \ == 0) break;\r\n\t\tMat a = make_matrix<long double>(n, n);\r\n\t\tfor (int\
    \ i = 0; i < n; i++) {\r\n\t\t\tfor (int j = 0; j < n; j++) {\r\n\t\t\t\tcin >>\
    \ a[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\tvector<long double> b(n);\r\n\t\tfor (int\
    \ i = 0; i < n; i++) {\r\n\t\t\tcin >> b[i];\r\n\t\t}\r\n\t\tconst long double\
    \ EPS = 1e-12;\r\n\t\tauto res = solve_linear(a, b, EPS);\r\n\t\tif (res.empty())\
    \ {\r\n\t\t\tcout << \"inconsistent\\n\";\r\n\t\t} else if ((int)res.size() >\
    \ 1) {\r\n\t\t\tcout << \"multiple\\n\";\r\n\t\t} else {\r\n\t\t\tfor (auto& t\
    \ : res[0]) \r\n\t\t\t\tcout << t << \" \";\r\n\t\t\tcout << '\\n';\r\n\t\t}\r\
    \n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/matrix.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-equationsolver-matrix.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-equationsolver-matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-equationsolver-matrix.test.cpp
- /verify/verify/kattis/kattis-equationsolver-matrix.test.cpp.html
title: verify/kattis/kattis-equationsolver-matrix.test.cpp
---
