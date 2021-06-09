---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/associative_range_query.cpp\"\
    \n#include <bits/stdc++.h>\n\ntemplate <class T> struct RangeQuery {\n\tint sz;\
    \ \n\tstd::vector<std::vector<T>> st;\n\tT id = 0;\n\tstd::vector<T> a;\n\n\t\
    T comb(T a, T b) { return a + b; }  \n\n\tvoid fill(int l, int r, int ind) {\n\
    \t\tif (ind < 0) return;\n\t\tint m = (l + r) >> 1;\n\t\tT prod = id;\n\t\tfor\
    \ (int i = m - 1; i >= l; i--) \n\t\t\tst[i][ind] = prod = comb(a[i], prod);\n\
    \t\tprod = id;\n\t\tfor (int i = m; i < r; i++) \n\t\t\tst[i][ind] = prod = comb(prod,\
    \ a[i]);\n\t\tfill(l, m, ind - 1);\n\t\tfill(m, r, ind - 1);\n\t}\n\n\tvoid init(std::vector<T>\
    \ a_) {\n\t\ta = a_;\n\t\tsz = 1;\n\t\twhile ((1 << sz) < (int)a.size()) sz++;\n\
    \t\tst = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\n\t\ta.resize(1\
    \ << sz);\n\t\tfill(0, (1 << sz), sz - 1);\n\t}\n\n\tT query(int l, int r) {\n\
    \t\tif (l == r) return a[l];\n\t\tint t = 31 - __builtin_clz(r ^ l);\n\t\treturn\
    \ comb(st[l][t], st[r][t]);\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\
    \tcin.tie(0)->sync_with_stdio(0);\n\tint n, q; cin >> n >> q;\n\tvector<long long>\
    \ a(n);\n\tfor (int i = 0; i < n; i++) \n\t\tcin >> a[i];\n\tRangeQuery<long long>\
    \ R; \n\tR.init(a);\n\twhile (q--) {\n\t\tint l, r; cin >> l >> r;\n\t\tr--;\n\
    \t\tcout << R.query(l, r) << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct RangeQuery {\n\tint\
    \ sz; \n\tstd::vector<std::vector<T>> st;\n\tT id = 0;\n\tstd::vector<T> a;\n\n\
    \tT comb(T a, T b) { return a + b; }  \n\n\tvoid fill(int l, int r, int ind) {\n\
    \t\tif (ind < 0) return;\n\t\tint m = (l + r) >> 1;\n\t\tT prod = id;\n\t\tfor\
    \ (int i = m - 1; i >= l; i--) \n\t\t\tst[i][ind] = prod = comb(a[i], prod);\n\
    \t\tprod = id;\n\t\tfor (int i = m; i < r; i++) \n\t\t\tst[i][ind] = prod = comb(prod,\
    \ a[i]);\n\t\tfill(l, m, ind - 1);\n\t\tfill(m, r, ind - 1);\n\t}\n\n\tvoid init(std::vector<T>\
    \ a_) {\n\t\ta = a_;\n\t\tsz = 1;\n\t\twhile ((1 << sz) < (int)a.size()) sz++;\n\
    \t\tst = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\n\t\ta.resize(1\
    \ << sz);\n\t\tfill(0, (1 << sz), sz - 1);\n\t}\n\n\tT query(int l, int r) {\n\
    \t\tif (l == r) return a[l];\n\t\tint t = 31 - __builtin_clz(r ^ l);\n\t\treturn\
    \ comb(st[l][t], st[r][t]);\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\
    \tcin.tie(0)->sync_with_stdio(0);\n\tint n, q; cin >> n >> q;\n\tvector<long long>\
    \ a(n);\n\tfor (int i = 0; i < n; i++) \n\t\tcin >> a[i];\n\tRangeQuery<long long>\
    \ R; \n\tR.init(a);\n\twhile (q--) {\n\t\tint l, r; cin >> l >> r;\n\t\tr--;\n\
    \t\tcout << R.query(l, r) << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/associative_range_query.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/associative_range_query.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/associative_range_query.cpp
- /library/library/data-structures/1d-range-queries/associative_range_query.cpp.html
title: library/data-structures/1d-range-queries/associative_range_query.cpp
---
