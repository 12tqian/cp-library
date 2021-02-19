---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/matrix.cpp\"\n#include <bits/stdc++.h>\n\
    \nnamespace MatrixOperations {\n\ntemplate <class T> using Matrix = std::vector<std::vector<T>>;\n\
    \ntemplate <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r,\
    \ std::vector<T>(c)); }\n\ntemplate <class T> Matrix<T>& operator += (Matrix<T>&\
    \ a, const Matrix<T>& b) {\n    for (int i = 0; i < (int)a.size(); i++) {\n  \
    \      for (int j = 0; j < (int)a[0].size(); j++) {\n            a[i][j] += b[i][j];\n\
    \        }\n    }\n    return a;\n}\n\ntemplate <class T> Matrix<T>& operator\
    \ -= (Matrix<T>& a, const Matrix<T>& b) {\n    for (int i = 0; i < (int)a.size();\
    \ i++) {\n        for (int j = 0; j < (int)a[0].size(); j++) {\n            a[i][j]\
    \ -= b[i][j];\n        }\n    }\n    return a;\n}\n\ntemplate <class T> Matrix<T>\
    \ operator * (const Matrix<T>& a, const Matrix<T>& b) {\n    assert(a[0].size()\
    \ == b.size());\n    int x = (int)a.size();\n    int y = (int)a[0].size();\n \
    \   int z = (int)b[0].size();\n    Matrix<T> c = make_matrix<T>(x, z);\n    for\
    \ (int i = 0; i < x; i++) {\n        for (int j = 0; j < y; j++) {\n         \
    \   for (int k = 0; k < z; k++) {\n                c[i][k] += a[i][j] * b[j][k];\n\
    \            }\n        }\n    }\n    return c;\n}\n\ntemplate <class T> Matrix<T>\
    \ operator + (Matrix<T> a, const Matrix<T>& b) { return a += b; }\ntemplate <class\
    \ T> Matrix<T> operator - (Matrix<T> a, const Matrix<T>& b) { return a -= b; }\n\
    template <class T> Matrix<T>& operator *= (Matrix<T>& a, const Matrix<T>& b) {\
    \ return a = a * b; }\n\ntemplate <class T> Matrix<T> pow(Matrix<T> m, long long\
    \ p) {\n    int n = (int)m.size();\n    assert(n == (int)m[0].size() && p >= 0);\n\
    \    Matrix<T> res = make_matrix<T>(n, n);\n    for (int i = 0; i < n; i++) \n\
    \        res[i][i] = 1;\n    for (; p; p >>= 1, m *= m) {\n        if (p & 1)\
    \ {\n            res *= m;\n        }\n    }\n    return res;\n}\n\ntemplate <class\
    \ T> int get_row(Matrix<T>& m, int r, int i, int nxt) {\n    for (int j = nxt;\
    \ j < r; j++) {\n        if (m[j][i] != 0) {\n            return j;\n        }\n\
    \    }\n    return -1;\n}\n\nconst long double EPS = 1e-12;\n\ntemplate <> int\
    \ get_row<long double>(Matrix<long double>& m, int r, int i, int nxt) {\n    std::pair<long\
    \ double, int> best = {0, -1};\n    for (int j = nxt; j < r; j++) {\n        best\
    \ = std::max(best, {abs(m[j][i]), j});\n    }\n    return best.first < EPS ? -1\
    \ : best.second;\n}\n\n// returns a pair of determinant, rank, while doing Gaussian\
    \ elimination to m\ntemplate <class T> std::pair<T, int> gauss(Matrix<T>& m) {\n\
    \    int r = (int)m.size();\n    int c = (int)m[0].size();\n    int rank = 0,\
    \ nxt = 0;\n    T prod = 1;\n    for (int i = 0; i < r; i++) {\n        int row\
    \ = get_row(m, r, i, nxt);\n        if (row == -1) {\n            prod = 0;\n\
    \            continue;\n        }\n        if (row != nxt) {\n            prod\
    \ *= -1;\n            m[row].swap(m[nxt]);\n        }\n        prod *= m[nxt][i];\n\
    \        rank++;\n        T x = 1 / m[nxt][i];\n        for (int k = i; k < c;\
    \ k++) \n            m[nxt][k] *= x;\n        for (int j = 0; j < r; j++) {\n\
    \            if (j != nxt) {\n                T v = m[j][i];\n               \
    \ if (v == 0) continue;\n                for (int k = i; k < c; k++) {\n     \
    \               m[j][k] -= v * m[nxt][k];\n                }\n            }\n\
    \        }\n        nxt++;\n    }\n    return {prod, rank};\n}\n\ntemplate <class\
    \ T> Matrix<T> inv(Matrix<T> m) {\n    int r = (int)m.size();\n    assert(r ==\
    \ (int)m[0].size());\n    Matrix<T> x = make_matrix<T>(r, 2 * r);\n    for (int\
    \ i = 0; i < r; i++) {\n        x[i][i + r] = 1;\n        for (int j = 0; j <\
    \ r; j++) {\n            x[i][j] = m[i][j];\n        }\n    }\n    if (gauss(x).second\
    \ != r) return Matrix<T>();\n    Matrix<T> res = make_matrix<T>(r, r);\n    for\
    \ (int i = 0; i < r; i++) {\n        for (int j = 0; j < r; j++) {\n         \
    \   res[i][j] = x[i][j + r];\n        }\n    }\n    return res;\n}\n\n} // namespace\
    \ MatrixOperations\n\nint main() {\n    using namespace std;\n    using namespace\
    \ MatrixOperations;\n    using Mat = Matrix<long double>;\n    while (true) {\n\
    \        int n; cin >> n;\n        if (n == 0) break;\n        Mat a = make_matrix<long\
    \ double>(n, n + 1);\n        for (int i = 0; i < n; i++) {\n            for (int\
    \ j = 0; j < n; j++) {\n                cin >> a[i][j];\n            }\n     \
    \   }\n        for (int i = 0; i < n; i++) {\n            cin >> a[i][n];\n  \
    \      }\n        auto res = gauss(a);\n        vector<long double> ans;\n   \
    \     bool inf = false;\n        bool sol = true;\n        for (int i = 0; i <\
    \ n; i++) {  \n            bool one = false;\n            for (int j = 0; j <\
    \ n; j++) {\n                if (abs(a[i][j] - 1) < EPS) {\n                 \
    \   one = true;\n                    break;\n                }\n            }\n\
    \            if (one) {\n                ans.push_back(a[i].back());\n       \
    \         continue;\n            }\n            if (abs(a[i].back()) >= EPS) {\n\
    \                sol = false;\n                break;\n            } \n      \
    \      if (abs(a[i].back()) < EPS) {\n                inf = true;\n          \
    \  }\n        }\n        if (!sol) {\n            cout << \"inconsistent\\n\"\
    ;\n        } else if (inf) {\n            cout << \"multiple\\n\";\n        }\
    \ else {\n            for (auto& t : ans) \n                cout << t << \" \"\
    ;\n            cout << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nnamespace MatrixOperations {\n\ntemplate <class\
    \ T> using Matrix = std::vector<std::vector<T>>;\n\ntemplate <class T> Matrix<T>\
    \ make_matrix(int r, int c) { return Matrix<T>(r, std::vector<T>(c)); }\n\ntemplate\
    \ <class T> Matrix<T>& operator += (Matrix<T>& a, const Matrix<T>& b) {\n    for\
    \ (int i = 0; i < (int)a.size(); i++) {\n        for (int j = 0; j < (int)a[0].size();\
    \ j++) {\n            a[i][j] += b[i][j];\n        }\n    }\n    return a;\n}\n\
    \ntemplate <class T> Matrix<T>& operator -= (Matrix<T>& a, const Matrix<T>& b)\
    \ {\n    for (int i = 0; i < (int)a.size(); i++) {\n        for (int j = 0; j\
    \ < (int)a[0].size(); j++) {\n            a[i][j] -= b[i][j];\n        }\n   \
    \ }\n    return a;\n}\n\ntemplate <class T> Matrix<T> operator * (const Matrix<T>&\
    \ a, const Matrix<T>& b) {\n    assert(a[0].size() == b.size());\n    int x =\
    \ (int)a.size();\n    int y = (int)a[0].size();\n    int z = (int)b[0].size();\n\
    \    Matrix<T> c = make_matrix<T>(x, z);\n    for (int i = 0; i < x; i++) {\n\
    \        for (int j = 0; j < y; j++) {\n            for (int k = 0; k < z; k++)\
    \ {\n                c[i][k] += a[i][j] * b[j][k];\n            }\n        }\n\
    \    }\n    return c;\n}\n\ntemplate <class T> Matrix<T> operator + (Matrix<T>\
    \ a, const Matrix<T>& b) { return a += b; }\ntemplate <class T> Matrix<T> operator\
    \ - (Matrix<T> a, const Matrix<T>& b) { return a -= b; }\ntemplate <class T> Matrix<T>&\
    \ operator *= (Matrix<T>& a, const Matrix<T>& b) { return a = a * b; }\n\ntemplate\
    \ <class T> Matrix<T> pow(Matrix<T> m, long long p) {\n    int n = (int)m.size();\n\
    \    assert(n == (int)m[0].size() && p >= 0);\n    Matrix<T> res = make_matrix<T>(n,\
    \ n);\n    for (int i = 0; i < n; i++) \n        res[i][i] = 1;\n    for (; p;\
    \ p >>= 1, m *= m) {\n        if (p & 1) {\n            res *= m;\n        }\n\
    \    }\n    return res;\n}\n\ntemplate <class T> int get_row(Matrix<T>& m, int\
    \ r, int i, int nxt) {\n    for (int j = nxt; j < r; j++) {\n        if (m[j][i]\
    \ != 0) {\n            return j;\n        }\n    }\n    return -1;\n}\n\nconst\
    \ long double EPS = 1e-12;\n\ntemplate <> int get_row<long double>(Matrix<long\
    \ double>& m, int r, int i, int nxt) {\n    std::pair<long double, int> best =\
    \ {0, -1};\n    for (int j = nxt; j < r; j++) {\n        best = std::max(best,\
    \ {abs(m[j][i]), j});\n    }\n    return best.first < EPS ? -1 : best.second;\n\
    }\n\n// returns a pair of determinant, rank, while doing Gaussian elimination\
    \ to m\ntemplate <class T> std::pair<T, int> gauss(Matrix<T>& m) {\n    int r\
    \ = (int)m.size();\n    int c = (int)m[0].size();\n    int rank = 0, nxt = 0;\n\
    \    T prod = 1;\n    for (int i = 0; i < r; i++) {\n        int row = get_row(m,\
    \ r, i, nxt);\n        if (row == -1) {\n            prod = 0;\n            continue;\n\
    \        }\n        if (row != nxt) {\n            prod *= -1;\n            m[row].swap(m[nxt]);\n\
    \        }\n        prod *= m[nxt][i];\n        rank++;\n        T x = 1 / m[nxt][i];\n\
    \        for (int k = i; k < c; k++) \n            m[nxt][k] *= x;\n        for\
    \ (int j = 0; j < r; j++) {\n            if (j != nxt) {\n                T v\
    \ = m[j][i];\n                if (v == 0) continue;\n                for (int\
    \ k = i; k < c; k++) {\n                    m[j][k] -= v * m[nxt][k];\n      \
    \          }\n            }\n        }\n        nxt++;\n    }\n    return {prod,\
    \ rank};\n}\n\ntemplate <class T> Matrix<T> inv(Matrix<T> m) {\n    int r = (int)m.size();\n\
    \    assert(r == (int)m[0].size());\n    Matrix<T> x = make_matrix<T>(r, 2 * r);\n\
    \    for (int i = 0; i < r; i++) {\n        x[i][i + r] = 1;\n        for (int\
    \ j = 0; j < r; j++) {\n            x[i][j] = m[i][j];\n        }\n    }\n   \
    \ if (gauss(x).second != r) return Matrix<T>();\n    Matrix<T> res = make_matrix<T>(r,\
    \ r);\n    for (int i = 0; i < r; i++) {\n        for (int j = 0; j < r; j++)\
    \ {\n            res[i][j] = x[i][j + r];\n        }\n    }\n    return res;\n\
    }\n\n} // namespace MatrixOperations\n\nint main() {\n    using namespace std;\n\
    \    using namespace MatrixOperations;\n    using Mat = Matrix<long double>;\n\
    \    while (true) {\n        int n; cin >> n;\n        if (n == 0) break;\n  \
    \      Mat a = make_matrix<long double>(n, n + 1);\n        for (int i = 0; i\
    \ < n; i++) {\n            for (int j = 0; j < n; j++) {\n                cin\
    \ >> a[i][j];\n            }\n        }\n        for (int i = 0; i < n; i++) {\n\
    \            cin >> a[i][n];\n        }\n        auto res = gauss(a);\n      \
    \  vector<long double> ans;\n        bool inf = false;\n        bool sol = true;\n\
    \        for (int i = 0; i < n; i++) {  \n            bool one = false;\n    \
    \        for (int j = 0; j < n; j++) {\n                if (abs(a[i][j] - 1) <\
    \ EPS) {\n                    one = true;\n                    break;\n      \
    \          }\n            }\n            if (one) {\n                ans.push_back(a[i].back());\n\
    \                continue;\n            }\n            if (abs(a[i].back()) >=\
    \ EPS) {\n                sol = false;\n                break;\n            }\
    \ \n            if (abs(a[i].back()) < EPS) {\n                inf = true;\n \
    \           }\n        }\n        if (!sol) {\n            cout << \"inconsistent\\\
    n\";\n        } else if (inf) {\n            cout << \"multiple\\n\";\n      \
    \  } else {\n            for (auto& t : ans) \n                cout << t << \"\
    \ \";\n            cout << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/matrix.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/matrix.cpp
layout: document
redirect_from:
- /library/library/numerical/matrix.cpp
- /library/library/numerical/matrix.cpp.html
title: library/numerical/matrix.cpp
---
