---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n\n/**\n * Handles point update in log(n),\
    \ and query in log(n)^2\n */\n\ntemplate <class T, int N, int M> struct QuadTree\
    \ {\n\tT sm[16 * N * M];\n\n\tQuadTree() { memset(sm, 0, sizeof(sm)); }\n\n\t\
    void upd(int x, int y, T inc, int n = 1, int x1 = 0, int y1 = 0, int x2 = N -\
    \ 1, int y2 = M - 1) {\n\t\tif (x1 == x2 && y1 == y2) \n\t\t\tsm[n] = inc;\n\t\
    \telse {\n\t\t\tint xm = (x1 + x2) >> 1;\n\t\t\tint ym = (y1 + y2) >> 1;\n\t\t\
    \tif (x <= xm && y <= ym) \n\t\t\t\tupd(x, y, inc, 4 * n, x1, y1, xm, ym);\n\t\
    \t\telse if (x <= xm && y > ym) \n\t\t\t\tupd(x, y, inc, 4 * n + 1, x1, ym + 1,\
    \ xm, y2);\n\t\t\telse if (x > xm && y > ym) \n\t\t\t\tupd(x, y, inc, 4 * n +\
    \ 2, xm + 1, ym + 1, x2, y2);\n\t\t\telse \n\t\t\t\tupd(x, y, inc, 4 * n + 3,\
    \ xm + 1, y1, x2, ym);\n\t\t\tsm[n] = sm[4 * n] + sm[4 * n + 1] + sm[4 * n + 2]\
    \ + sm[4 * n + 3];\n\t\t}\n\t}\n\n\tT query(int qx1, int qy1, int qx2, int qy2,\
    \ int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1, int y2 = M - 1) {\n\t\tif\
    \ (qx2 < x1 || qy1 > y2 || qx1 > x2 || qy2 < y1) \n\t\t\treturn 0;\n\t\telse if\
    \ (qx1 <= x1 && x2 <= qx2 && qy1 <= y1 && y2 <= qy2) \n\t\t\treturn sm[n];\n\t\
    \tint xm = (x1 + x2) >> 1;\n\t\tint ym = (y1 + y2) >> 1;\n\t\treturn query(qx1,\
    \ qy1, qx2, qy2, 4 * n, x1, y1, xm, ym) \n\t\t\t\t+ query(qx1, qy1, qx2, qy2,\
    \ 4 * n + 1, x1, ym + 1, xm, y2) \n\t\t\t\t+ query(qx1, qy1, qx2, qy2, 4 * n +\
    \ 2, xm + 1, ym + 1, x2, y2) \n\t\t\t\t+ query(qx1, qy1, qx2, qy2, 4 * n + 3,\
    \ xm + 1, y1, x2, ym);\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Handles point update in log(n), and query\
    \ in log(n)^2\n */\n\ntemplate <class T, int N, int M> struct QuadTree {\n\tT\
    \ sm[16 * N * M];\n\n\tQuadTree() { memset(sm, 0, sizeof(sm)); }\n\n\tvoid upd(int\
    \ x, int y, T inc, int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1, int y2 =\
    \ M - 1) {\n\t\tif (x1 == x2 && y1 == y2) \n\t\t\tsm[n] = inc;\n\t\telse {\n\t\
    \t\tint xm = (x1 + x2) >> 1;\n\t\t\tint ym = (y1 + y2) >> 1;\n\t\t\tif (x <= xm\
    \ && y <= ym) \n\t\t\t\tupd(x, y, inc, 4 * n, x1, y1, xm, ym);\n\t\t\telse if\
    \ (x <= xm && y > ym) \n\t\t\t\tupd(x, y, inc, 4 * n + 1, x1, ym + 1, xm, y2);\n\
    \t\t\telse if (x > xm && y > ym) \n\t\t\t\tupd(x, y, inc, 4 * n + 2, xm + 1, ym\
    \ + 1, x2, y2);\n\t\t\telse \n\t\t\t\tupd(x, y, inc, 4 * n + 3, xm + 1, y1, x2,\
    \ ym);\n\t\t\tsm[n] = sm[4 * n] + sm[4 * n + 1] + sm[4 * n + 2] + sm[4 * n + 3];\n\
    \t\t}\n\t}\n\n\tT query(int qx1, int qy1, int qx2, int qy2, int n = 1, int x1\
    \ = 0, int y1 = 0, int x2 = N - 1, int y2 = M - 1) {\n\t\tif (qx2 < x1 || qy1\
    \ > y2 || qx1 > x2 || qy2 < y1) \n\t\t\treturn 0;\n\t\telse if (qx1 <= x1 && x2\
    \ <= qx2 && qy1 <= y1 && y2 <= qy2) \n\t\t\treturn sm[n];\n\t\tint xm = (x1 +\
    \ x2) >> 1;\n\t\tint ym = (y1 + y2) >> 1;\n\t\treturn query(qx1, qy1, qx2, qy2,\
    \ 4 * n, x1, y1, xm, ym) \n\t\t\t\t+ query(qx1, qy1, qx2, qy2, 4 * n + 1, x1,\
    \ ym + 1, xm, y2) \n\t\t\t\t+ query(qx1, qy1, qx2, qy2, 4 * n + 2, xm + 1, ym\
    \ + 1, x2, y2) \n\t\t\t\t+ query(qx1, qy1, qx2, qy2, 4 * n + 3, xm + 1, y1, x2,\
    \ ym);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/quadtree.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:26:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/quadtree.hpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/quadtree.hpp
- /library/library/data-structures/2d-range-queries/quadtree.hpp.html
title: library/data-structures/2d-range-queries/quadtree.hpp
---
