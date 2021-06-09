---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/li_chao_tree_online.cpp\"\
    \n#include <bits/stdc++.h>\n\n// Currently set to get the max of things, use negatives\
    \ for minimum\n\nstruct Line {\n\tint k; long long m;\n\n\tLine(int _k, long long\
    \ _m) { k = _k, m = _m; }\n\tLine() : Line(0, std::numeric_limits<long long>::min())\
    \ { }\n\n\tlong long get(long long x) { return k * x + m; }\n\n\tbool majorize(Line\
    \ X, long long L, long long R) { \n\t\treturn get(L) >= X.get(L) && get(R) >=\
    \ X.get(R); \n\t}\n};\n\nstruct Node {\n\tNode* c[2]; Line S;\n\n\tNode() { c[0]\
    \ = c[1] = NULL; S = Line(); }\n\t~Node() { for (int i = 0; i < 2; i++) delete\
    \ c[i]; }\n\n\tvoid mc(int i) { if (!c[i]) c[i] = new Node(); }\n\tlong long mid(long\
    \ long x) { return x & 1 ? (x - 1) / 2 : x / 2; }\n\n\tlong long query(long long\
    \ X, long long L, long long R) {\n\t\tlong long ans = S.get(X);\n\t\tlong long\
    \ M = mid(L + R);\n\t\tif (X <= M) {\n\t\t\tif (c[0]) ans = std::max(ans, c[0]->query(X,\
    \ L, M));\n\t\t} else {\n\t\t\tif (c[1]) ans = std::max(ans, c[1]->query(X, M\
    \ + 1, R));\n\t\t}\n\t\treturn ans;\n\t}\n\n\tvoid modify(Line X, long long L,\
    \ long long R) {\n\t\tif (X.majorize(S, L, R)) std::swap(X, S);\n\t\tif (S.majorize(X,\
    \ L, R)) return;\n\t\tif (S.get(L) < X.get(L)) std::swap(X, S);\n\t\tlong long\
    \ M = mid(L + R);\n\t\tif (X.get(M) >= S.get(M)) std::swap(X, S), mc(0), c[0]->modify(X,\
    \ L, M);\n\t\telse mc(1), c[1]->modify(X, M + 1, R);\n\t}\n\t\n\tvoid upd(Line\
    \ X, long long lo, long long hi, long long L, long long R) {\n\t\tif (R < lo ||\
    \ hi < L) return;\n\t\tif (lo <= L && R <= hi) return modify(X, L, R);\n\t\tlong\
    \ long M = mid(L + R);\n\t\tif (lo <= M) mc(0), c[0]->upd(X, lo, hi, L, M);\n\t\
    \tif (hi > M) mc(1), c[1]->upd(X, lo, hi, M + 1, R);\n\t}\n};\n\nint main() {\n\
    \tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tconst int INF = 1e9;\n\
    \tint n, q; cin >> n >> q;\n\tNode L;\n\tfor (int i = 0; i < n; i++) {\n\t\tint\
    \ l, r, a; long long b;\n\t\tcin >> l >> r >> a >> b;\n\t\tL.upd({-a, -b}, l,\
    \ r - 1, -INF, INF);\n\t}\n\tfor (int i = 0; i < q; i++) {\n\t\tint t; cin >>\
    \ t;\n\t\tif (t == 0) {\n\t\t\tint l, r, a; long long b; \n\t\t\tcin >> l >> r\
    \ >> a >> b;\n\t\t\tL.upd({-a, -b}, l, r - 1, -INF, INF);\n\t\t} else {\n\t\t\t\
    int p; cin >> p;\n\t\t\tlong long ans = L.query(p, -INF, INF);\n\t\t\tif (ans\
    \ == numeric_limits<long long>::min()) {\n\t\t\t\tcout << \"INFINITY\" << '\\\
    n';\n\t\t\t} else {\n\t\t\t\tcout << -ans << '\\n';\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n// Currently set to get the max of things, use\
    \ negatives for minimum\n\nstruct Line {\n\tint k; long long m;\n\n\tLine(int\
    \ _k, long long _m) { k = _k, m = _m; }\n\tLine() : Line(0, std::numeric_limits<long\
    \ long>::min()) { }\n\n\tlong long get(long long x) { return k * x + m; }\n\n\t\
    bool majorize(Line X, long long L, long long R) { \n\t\treturn get(L) >= X.get(L)\
    \ && get(R) >= X.get(R); \n\t}\n};\n\nstruct Node {\n\tNode* c[2]; Line S;\n\n\
    \tNode() { c[0] = c[1] = NULL; S = Line(); }\n\t~Node() { for (int i = 0; i <\
    \ 2; i++) delete c[i]; }\n\n\tvoid mc(int i) { if (!c[i]) c[i] = new Node(); }\n\
    \tlong long mid(long long x) { return x & 1 ? (x - 1) / 2 : x / 2; }\n\n\tlong\
    \ long query(long long X, long long L, long long R) {\n\t\tlong long ans = S.get(X);\n\
    \t\tlong long M = mid(L + R);\n\t\tif (X <= M) {\n\t\t\tif (c[0]) ans = std::max(ans,\
    \ c[0]->query(X, L, M));\n\t\t} else {\n\t\t\tif (c[1]) ans = std::max(ans, c[1]->query(X,\
    \ M + 1, R));\n\t\t}\n\t\treturn ans;\n\t}\n\n\tvoid modify(Line X, long long\
    \ L, long long R) {\n\t\tif (X.majorize(S, L, R)) std::swap(X, S);\n\t\tif (S.majorize(X,\
    \ L, R)) return;\n\t\tif (S.get(L) < X.get(L)) std::swap(X, S);\n\t\tlong long\
    \ M = mid(L + R);\n\t\tif (X.get(M) >= S.get(M)) std::swap(X, S), mc(0), c[0]->modify(X,\
    \ L, M);\n\t\telse mc(1), c[1]->modify(X, M + 1, R);\n\t}\n\t\n\tvoid upd(Line\
    \ X, long long lo, long long hi, long long L, long long R) {\n\t\tif (R < lo ||\
    \ hi < L) return;\n\t\tif (lo <= L && R <= hi) return modify(X, L, R);\n\t\tlong\
    \ long M = mid(L + R);\n\t\tif (lo <= M) mc(0), c[0]->upd(X, lo, hi, L, M);\n\t\
    \tif (hi > M) mc(1), c[1]->upd(X, lo, hi, M + 1, R);\n\t}\n};\n\nint main() {\n\
    \tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tconst int INF = 1e9;\n\
    \tint n, q; cin >> n >> q;\n\tNode L;\n\tfor (int i = 0; i < n; i++) {\n\t\tint\
    \ l, r, a; long long b;\n\t\tcin >> l >> r >> a >> b;\n\t\tL.upd({-a, -b}, l,\
    \ r - 1, -INF, INF);\n\t}\n\tfor (int i = 0; i < q; i++) {\n\t\tint t; cin >>\
    \ t;\n\t\tif (t == 0) {\n\t\t\tint l, r, a; long long b; \n\t\t\tcin >> l >> r\
    \ >> a >> b;\n\t\t\tL.upd({-a, -b}, l, r - 1, -INF, INF);\n\t\t} else {\n\t\t\t\
    int p; cin >> p;\n\t\t\tlong long ans = L.query(p, -INF, INF);\n\t\t\tif (ans\
    \ == numeric_limits<long long>::min()) {\n\t\t\t\tcout << \"INFINITY\" << '\\\
    n';\n\t\t\t} else {\n\t\t\t\tcout << -ans << '\\n';\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/li_chao_tree_online.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/li_chao_tree_online.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/li_chao_tree_online.cpp
- /library/library/data-structures/1d-range-queries/li_chao_tree_online.cpp.html
title: library/data-structures/1d-range-queries/li_chao_tree_online.cpp
---
