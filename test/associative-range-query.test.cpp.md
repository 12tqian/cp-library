---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/associative-range-query.hpp
    title: library/data-structures/1d-range-queries/associative-range-query.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/practice2/tasks/practice2_k
    links:
    - https://atcoder.jp/contests/practice2/tasks/practice2_k
  bundledCode: "#define PROBLEM \"https://atcoder.jp/contests/practice2/tasks/practice2_k\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\ntemplate\
    \ <class T> struct RangeQuery {\n\tint sz; \n\tstd::vector<std::vector<T>> st;\n\
    \tT id = 0;\n\tstd::vector<T> a;\n\n\tT comb(T a, T b) { return a + b; }  \n\n\
    \tvoid fill(int l, int r, int ind) {\n\t\tif (ind < 0) return;\n\t\tint m = (l\
    \ + r) >> 1;\n\t\tT prod = id;\n\t\tfor (int i = m - 1; i >= l; i--) \n\t\t\t\
    st[i][ind] = prod = comb(a[i], prod);\n\t\tprod = id;\n\t\tfor (int i = m; i <\
    \ r; i++) \n\t\t\tst[i][ind] = prod = comb(prod, a[i]);\n\t\tfill(l, m, ind -\
    \ 1);\n\t\tfill(m, r, ind - 1);\n\t}\n\n\tvoid init(std::vector<T> a_) {\n\t\t\
    a = a_;\n\t\tsz = 1;\n\t\twhile ((1 << sz) < (int)a.size()) sz++;\n\t\tst = std::vector<std::vector<T>>((1\
    \ << sz), std::vector<T>(sz));\n\t\ta.resize(1 << sz);\n\t\tfill(0, (1 << sz),\
    \ sz - 1);\n\t}\n\n\tT query(int l, int r) {\n\t\tif (l == r) return a[l];\n\t\
    \tint t = 31 - __builtin_clz(r ^ l);\n\t\treturn comb(st[l][t], st[r][t]);\n\t\
    }\n};\n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tint n, q; cin >> n >> q;\n\tvector<long long> a(n);\n\tfor (int i = 0; i < n;\
    \ i++) \n\t\tcin >> a[i];\n\tRangeQuery<long long> R; \n\tR.init(a);\n\twhile\
    \ (q--) {\n\t\tint l, r; cin >> l >> r;\n\t\tr--;\n\t\tcout << R.query(l, r) <<\
    \ '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/practice2/tasks/practice2_k\"\
    \n\n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/data-structures/1d-range-queries/associative-range-query.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, q; cin >> n >> q;\n\tvector<long long> a(n);\n\tfor (int i = 0; i < n;\
    \ i++) \n\t\tcin >> a[i];\n\tRangeQuery<long long> R; \n\tR.init(a);\n\twhile\
    \ (q--) {\n\t\tint l, r; cin >> l >> r;\n\t\tr--;\n\t\tcout << R.query(l, r) <<\
    \ '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/associative-range-query.hpp
  isVerificationFile: true
  path: test/associative-range-query.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 20:00:47-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/associative-range-query.test.cpp
layout: document
redirect_from:
- /verify/test/associative-range-query.test.cpp
- /verify/test/associative-range-query.test.cpp.html
title: test/associative-range-query.test.cpp
---
