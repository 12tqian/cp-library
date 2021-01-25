---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/2d-range-queries/quadtree.cpp\"\n\
    #include <bits/stdc++.h>\n\n/**\n * Handles point update in log(n), and query\
    \ in log(n)^2\n */\n\ntemplate <class T, int N, int M> struct QuadTree {\n   \
    \ T sm[16 * N * M];\n\n    QuadTree() { memset(sm, 0, sizeof(sm)); }\n\n    void\
    \ upd(int x, int y, T inc, int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1,\
    \ int y2 = M - 1) {\n        if (x1 == x2 && y1 == y2) \n            sm[n] = inc;\n\
    \        else {\n            int xm = (x1 + x2) >> 1;\n            int ym = (y1\
    \ + y2) >> 1;\n            if (x <= xm && y <= ym) \n                upd(x, y,\
    \ inc, 4 * n, x1, y1, xm, ym);\n            else if (x <= xm && y > ym) \n   \
    \             upd(x, y, inc, 4 * n + 1, x1, ym + 1, xm, y2);\n            else\
    \ if (x > xm && y > ym) \n                upd(x, y, inc, 4 * n + 2, xm + 1, ym\
    \ + 1, x2, y2);\n            else \n                upd(x, y, inc, 4 * n + 3,\
    \ xm + 1, y1, x2, ym);\n            sm[n] = sm[4 * n] + sm[4 * n + 1] + sm[4 *\
    \ n + 2] + sm[4 * n + 3];\n        }\n    }\n\n    T query(int qx1, int qy1, int\
    \ qx2, int qy2, int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1, int y2 = M\
    \ - 1) {\n        if (qx2 < x1 || qy1 > y2 || qx1 > x2 || qy2 < y1) \n       \
    \     return 0;\n        else if (qx1 <= x1 && x2 <= qx2 && qy1 <= y1 && y2 <=\
    \ qy2) \n            return sm[n];\n        int xm = (x1 + x2) >> 1;\n       \
    \ int ym = (y1 + y2) >> 1;\n        return query(qx1, qy1, qx2, qy2, 4 * n, x1,\
    \ y1, xm, ym) \n                + query(qx1, qy1, qx2, qy2, 4 * n + 1, x1, ym\
    \ + 1, xm, y2) \n                + query(qx1, qy1, qx2, qy2, 4 * n + 2, xm + 1,\
    \ ym + 1, x2, y2) \n                + query(qx1, qy1, qx2, qy2, 4 * n + 3, xm\
    \ + 1, y1, x2, ym);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Handles point update in log(n), and query\
    \ in log(n)^2\n */\n\ntemplate <class T, int N, int M> struct QuadTree {\n   \
    \ T sm[16 * N * M];\n\n    QuadTree() { memset(sm, 0, sizeof(sm)); }\n\n    void\
    \ upd(int x, int y, T inc, int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1,\
    \ int y2 = M - 1) {\n        if (x1 == x2 && y1 == y2) \n            sm[n] = inc;\n\
    \        else {\n            int xm = (x1 + x2) >> 1;\n            int ym = (y1\
    \ + y2) >> 1;\n            if (x <= xm && y <= ym) \n                upd(x, y,\
    \ inc, 4 * n, x1, y1, xm, ym);\n            else if (x <= xm && y > ym) \n   \
    \             upd(x, y, inc, 4 * n + 1, x1, ym + 1, xm, y2);\n            else\
    \ if (x > xm && y > ym) \n                upd(x, y, inc, 4 * n + 2, xm + 1, ym\
    \ + 1, x2, y2);\n            else \n                upd(x, y, inc, 4 * n + 3,\
    \ xm + 1, y1, x2, ym);\n            sm[n] = sm[4 * n] + sm[4 * n + 1] + sm[4 *\
    \ n + 2] + sm[4 * n + 3];\n        }\n    }\n\n    T query(int qx1, int qy1, int\
    \ qx2, int qy2, int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1, int y2 = M\
    \ - 1) {\n        if (qx2 < x1 || qy1 > y2 || qx1 > x2 || qy2 < y1) \n       \
    \     return 0;\n        else if (qx1 <= x1 && x2 <= qx2 && qy1 <= y1 && y2 <=\
    \ qy2) \n            return sm[n];\n        int xm = (x1 + x2) >> 1;\n       \
    \ int ym = (y1 + y2) >> 1;\n        return query(qx1, qy1, qx2, qy2, 4 * n, x1,\
    \ y1, xm, ym) \n                + query(qx1, qy1, qx2, qy2, 4 * n + 1, x1, ym\
    \ + 1, xm, y2) \n                + query(qx1, qy1, qx2, qy2, 4 * n + 2, xm + 1,\
    \ ym + 1, x2, y2) \n                + query(qx1, qy1, qx2, qy2, 4 * n + 3, xm\
    \ + 1, y1, x2, ym);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/quadtree.cpp
  requiredBy: []
  timestamp: '2021-01-25 13:56:14-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/quadtree.cpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/quadtree.cpp
- /library/library/data-structures/2d-range-queries/quadtree.cpp.html
title: library/data-structures/2d-range-queries/quadtree.cpp
---
