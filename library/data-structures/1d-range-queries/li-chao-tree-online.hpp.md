---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-online.test.cpp
    title: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-online.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n// Currently set to get the max of things, use negatives for minimum\r\
    \n\r\nstruct Line {\r\n\tint k; long long m;\r\n\r\n\tLine(int _k, long long _m)\
    \ { k = _k, m = _m; }\r\n\tLine() : Line(0, std::numeric_limits<long long>::min())\
    \ { }\r\n\r\n\tlong long get(long long x) { return k * x + m; }\r\n\r\n\tbool\
    \ majorize(Line X, long long L, long long R) { \r\n\t\treturn get(L) >= X.get(L)\
    \ && get(R) >= X.get(R); \r\n\t}\r\n};\r\n\r\nstruct Node {\r\n\tNode* c[2]; Line\
    \ S;\r\n\r\n\tNode() { c[0] = c[1] = NULL; S = Line(); }\r\n\t~Node() { for (int\
    \ i = 0; i < 2; i++) delete c[i]; }\r\n\r\n\tvoid mc(int i) { if (!c[i]) c[i]\
    \ = new Node(); }\r\n\tlong long mid(long long x) { return x & 1 ? (x - 1) / 2\
    \ : x / 2; }\r\n\r\n\tlong long query(long long X, long long L, long long R) {\r\
    \n\t\tlong long ans = S.get(X);\r\n\t\tlong long M = mid(L + R);\r\n\t\tif (X\
    \ <= M) {\r\n\t\t\tif (c[0]) ans = std::max(ans, c[0]->query(X, L, M));\r\n\t\t\
    } else {\r\n\t\t\tif (c[1]) ans = std::max(ans, c[1]->query(X, M + 1, R));\r\n\
    \t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tvoid modify(Line X, long long L, long\
    \ long R) {\r\n\t\tif (X.majorize(S, L, R)) std::swap(X, S);\r\n\t\tif (S.majorize(X,\
    \ L, R)) return;\r\n\t\tif (S.get(L) < X.get(L)) std::swap(X, S);\r\n\t\tlong\
    \ long M = mid(L + R);\r\n\t\tif (X.get(M) >= S.get(M)) std::swap(X, S), mc(0),\
    \ c[0]->modify(X, L, M);\r\n\t\telse mc(1), c[1]->modify(X, M + 1, R);\r\n\t}\r\
    \n\t\r\n\tvoid upd(Line X, long long lo, long long hi, long long L, long long\
    \ R) {\r\n\t\tif (R < lo || hi < L) return;\r\n\t\tif (lo <= L && R <= hi) return\
    \ modify(X, L, R);\r\n\t\tlong long M = mid(L + R);\r\n\t\tif (lo <= M) mc(0),\
    \ c[0]->upd(X, lo, hi, L, M);\r\n\t\tif (hi > M) mc(1), c[1]->upd(X, lo, hi, M\
    \ + 1, R);\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\n// Currently set to get the max of things, use negatives\
    \ for minimum\r\n\r\nstruct Line {\r\n\tint k; long long m;\r\n\r\n\tLine(int\
    \ _k, long long _m) { k = _k, m = _m; }\r\n\tLine() : Line(0, std::numeric_limits<long\
    \ long>::min()) { }\r\n\r\n\tlong long get(long long x) { return k * x + m; }\r\
    \n\r\n\tbool majorize(Line X, long long L, long long R) { \r\n\t\treturn get(L)\
    \ >= X.get(L) && get(R) >= X.get(R); \r\n\t}\r\n};\r\n\r\nstruct Node {\r\n\t\
    Node* c[2]; Line S;\r\n\r\n\tNode() { c[0] = c[1] = NULL; S = Line(); }\r\n\t\
    ~Node() { for (int i = 0; i < 2; i++) delete c[i]; }\r\n\r\n\tvoid mc(int i) {\
    \ if (!c[i]) c[i] = new Node(); }\r\n\tlong long mid(long long x) { return x &\
    \ 1 ? (x - 1) / 2 : x / 2; }\r\n\r\n\tlong long query(long long X, long long L,\
    \ long long R) {\r\n\t\tlong long ans = S.get(X);\r\n\t\tlong long M = mid(L +\
    \ R);\r\n\t\tif (X <= M) {\r\n\t\t\tif (c[0]) ans = std::max(ans, c[0]->query(X,\
    \ L, M));\r\n\t\t} else {\r\n\t\t\tif (c[1]) ans = std::max(ans, c[1]->query(X,\
    \ M + 1, R));\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tvoid modify(Line X,\
    \ long long L, long long R) {\r\n\t\tif (X.majorize(S, L, R)) std::swap(X, S);\r\
    \n\t\tif (S.majorize(X, L, R)) return;\r\n\t\tif (S.get(L) < X.get(L)) std::swap(X,\
    \ S);\r\n\t\tlong long M = mid(L + R);\r\n\t\tif (X.get(M) >= S.get(M)) std::swap(X,\
    \ S), mc(0), c[0]->modify(X, L, M);\r\n\t\telse mc(1), c[1]->modify(X, M + 1,\
    \ R);\r\n\t}\r\n\t\r\n\tvoid upd(Line X, long long lo, long long hi, long long\
    \ L, long long R) {\r\n\t\tif (R < lo || hi < L) return;\r\n\t\tif (lo <= L &&\
    \ R <= hi) return modify(X, L, R);\r\n\t\tlong long M = mid(L + R);\r\n\t\tif\
    \ (lo <= M) mc(0), c[0]->upd(X, lo, hi, L, M);\r\n\t\tif (hi > M) mc(1), c[1]->upd(X,\
    \ lo, hi, M + 1, R);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/li-chao-tree-online.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-online.test.cpp
documentation_of: library/data-structures/1d-range-queries/li-chao-tree-online.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/li-chao-tree-online.hpp
- /library/library/data-structures/1d-range-queries/li-chao-tree-online.hpp.html
title: library/data-structures/1d-range-queries/li-chao-tree-online.hpp
---
