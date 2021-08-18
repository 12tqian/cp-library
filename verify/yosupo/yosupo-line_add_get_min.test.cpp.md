---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/dynamic-programming/line-container.hpp
    title: Line Container
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class T> struct Line {\n\tmutable T k, m, p;\n\t\n\tbool operator<(const\
    \ Line<T>& o) const { return k < o.k; }\n\tbool operator<(T x) const { return\
    \ p < x; }\n};\n\ntemplate <class T> struct LineContainer : std::multiset<Line<T>,\
    \ std::less<>> {\n\t// (for doubles, use INF = 1/.0, div(a,b) = a/b)\n\tconst\
    \ T INF = std::numeric_limits<T>::max();\n\n\tT div(T a, T b) { // floored division\n\
    \t\treturn a / b - ((a ^ b) < 0 && a % b); \n\t}\n\n\tusing super = std::multiset<Line<T>,\
    \ std::less<>>;\n\tusing iterator = typename LineContainer<T>::iterator;\n\t\n\
    \tbool isect(iterator x, iterator y) {\n\t\tif (y == super::end()) \n\t\t\treturn\
    \ x->p = INF, 0;\n\t\tif (x->k == y->k) \n\t\t\tx->p = x->m > y->m ? INF : -INF;\n\
    \t\telse \n\t\t\tx->p = div(y->m - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\
    \t}\n\t\n\tvoid add_line(T k, T m) {\n\t\tk = -k, m = -m;\n\t\tauto z = super::insert({k,\
    \ m, 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) \n\t\t\tz = super::erase(z);\n\
    \t\tif (x != super::begin() && isect(--x, y)) \n\t\t\tisect(x, y = super::erase(y));\n\
    \t\twhile ((y = x) != super::begin() && (--x)->p >= y->p)\n\t\t\tisect(x, super::erase(y));\n\
    \t}\n\t\n\tT query(T x) {\n\t\tassert(!super::empty());\n\t\tauto l = *super::lower_bound(x);\n\
    \t\treturn -(l.k * x + l.m);\n\t}\n};\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tLineContainer<long long>\
    \ cht;\t\n\twhile (n--) {\n\t\tint a;\n\t\tlong long b;\n\t\tcin >> a >> b;\n\t\
    \tcht.add_line(a, b);\n\t} \n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\t\
    if (t == 0) {\n\t\t\tint a;\n\t\t\tlong long b;\n\t\t\tcin >> a >> b;\n\t\t\t\
    cht.add_line(a, b);\n\t\t} else {\n\t\t\tint p;\n\t\t\tcin >> p;\n\t\t\tcout <<\
    \ cht.query(p) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/dynamic-programming/line-container.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tLineContainer<long long> cht;\t\n\twhile (n--) {\n\t\
    \tint a;\n\t\tlong long b;\n\t\tcin >> a >> b;\n\t\tcht.add_line(a, b);\n\t} \n\
    \twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint a;\n\t\
    \t\tlong long b;\n\t\t\tcin >> a >> b;\n\t\t\tcht.add_line(a, b);\n\t\t} else\
    \ {\n\t\t\tint p;\n\t\t\tcin >> p;\n\t\t\tcout << cht.query(p) << '\\n';\n\t\t\
    }\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/dynamic-programming/line-container.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2021-08-13 00:37:31-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-line_add_get_min.test.cpp
- /verify/verify/yosupo/yosupo-line_add_get_min.test.cpp.html
title: verify/yosupo/yosupo-line_add_get_min.test.cpp
---
