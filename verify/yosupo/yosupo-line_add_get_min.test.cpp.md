---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/dynamic-programming/line-container.hpp
    title: Line Container
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> struct\
    \ Line {\r\n\tmutable T k, m, p;\r\n\t\r\n\tbool operator<(const Line<T>& o) const\
    \ { return k < o.k; }\r\n\tbool operator<(T x) const { return p < x; }\r\n};\r\
    \n\r\ntemplate <class T> struct LineContainer : std::multiset<Line<T>, std::less<>>\
    \ {\r\n\t// (for doubles, use INF = 1/.0, div(a,b) = a/b)\r\n\tconst T INF = std::numeric_limits<T>::max();\r\
    \n\r\n\tT div(T a, T b) { // floored division\r\n\t\treturn a / b - ((a ^ b) <\
    \ 0 && a % b); \r\n\t}\r\n\r\n\tusing super = std::multiset<Line<T>, std::less<>>;\r\
    \n\tusing iterator = typename LineContainer<T>::iterator;\r\n\t\r\n\tbool isect(iterator\
    \ x, iterator y) {\r\n\t\tif (y == super::end()) \r\n\t\t\treturn x->p = INF,\
    \ 0;\r\n\t\tif (x->k == y->k) \r\n\t\t\tx->p = x->m > y->m ? INF : -INF;\r\n\t\
    \telse \r\n\t\t\tx->p = div(y->m - x->m, x->k - y->k);\r\n\t\treturn x->p >= y->p;\r\
    \n\t}\r\n\t\r\n\tvoid add_line(T k, T m) {\r\n\t\tk = -k, m = -m;\r\n\t\tauto\
    \ z = super::insert({k, m, 0}), y = z++, x = y;\r\n\t\twhile (isect(y, z)) \r\n\
    \t\t\tz = super::erase(z);\r\n\t\tif (x != super::begin() && isect(--x, y)) \r\
    \n\t\t\tisect(x, y = super::erase(y));\r\n\t\twhile ((y = x) != super::begin()\
    \ && (--x)->p >= y->p)\r\n\t\t\tisect(x, super::erase(y));\r\n\t}\r\n\t\r\n\t\
    T query(T x) {\r\n\t\tassert(!super::empty());\r\n\t\tauto l = *super::lower_bound(x);\r\
    \n\t\treturn -(l.k * x + l.m);\r\n\t}\r\n};\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tLineContainer<long\
    \ long> cht;\t\r\n\twhile (n--) {\r\n\t\tint a;\r\n\t\tlong long b;\r\n\t\tcin\
    \ >> a >> b;\r\n\t\tcht.add_line(a, b);\r\n\t} \r\n\twhile (q--) {\r\n\t\tint\
    \ t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint a;\r\n\t\t\tlong long\
    \ b;\r\n\t\t\tcin >> a >> b;\r\n\t\t\tcht.add_line(a, b);\r\n\t\t} else {\r\n\t\
    \t\tint p;\r\n\t\t\tcin >> p;\r\n\t\t\tcout << cht.query(p) << '\\n';\r\n\t\t\
    }\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\
    \n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/dynamic-programming/line-container.hpp\"\
    \r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, q;\r\n\tcin >> n >> q;\r\n\tLineContainer<long long> cht;\t\r\n\twhile\
    \ (n--) {\r\n\t\tint a;\r\n\t\tlong long b;\r\n\t\tcin >> a >> b;\r\n\t\tcht.add_line(a,\
    \ b);\r\n\t} \r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t ==\
    \ 0) {\r\n\t\t\tint a;\r\n\t\t\tlong long b;\r\n\t\t\tcin >> a >> b;\r\n\t\t\t\
    cht.add_line(a, b);\r\n\t\t} else {\r\n\t\t\tint p;\r\n\t\t\tcin >> p;\r\n\t\t\
    \tcout << cht.query(p) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/dynamic-programming/line-container.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-line_add_get_min.test.cpp
- /verify/verify/yosupo/yosupo-line_add_get_min.test.cpp.html
title: verify/yosupo/yosupo-line_add_get_min.test.cpp
---
