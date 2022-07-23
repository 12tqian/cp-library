---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/li-chao-tree-online.hpp
    title: library/data-structures/1d-range-queries/li-chao-tree-online.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n// Currently set to get the\
    \ max of things, use negatives for minimum\r\n\r\nstruct Line {\r\n\tint k; long\
    \ long m;\r\n\r\n\tLine(int _k, long long _m) { k = _k, m = _m; }\r\n\tLine()\
    \ : Line(0, std::numeric_limits<long long>::min()) { }\r\n\r\n\tlong long get(long\
    \ long x) { return k * x + m; }\r\n\r\n\tbool majorize(Line X, long long L, long\
    \ long R) { \r\n\t\treturn get(L) >= X.get(L) && get(R) >= X.get(R); \r\n\t}\r\
    \n};\r\n\r\nstruct Node {\r\n\tNode* c[2]; Line S;\r\n\r\n\tNode() { c[0] = c[1]\
    \ = NULL; S = Line(); }\r\n\t~Node() { for (int i = 0; i < 2; i++) delete c[i];\
    \ }\r\n\r\n\tvoid mc(int i) { if (!c[i]) c[i] = new Node(); }\r\n\tlong long mid(long\
    \ long x) { return x & 1 ? (x - 1) / 2 : x / 2; }\r\n\r\n\tlong long query(long\
    \ long X, long long L, long long R) {\r\n\t\tlong long ans = S.get(X);\r\n\t\t\
    long long M = mid(L + R);\r\n\t\tif (X <= M) {\r\n\t\t\tif (c[0]) ans = std::max(ans,\
    \ c[0]->query(X, L, M));\r\n\t\t} else {\r\n\t\t\tif (c[1]) ans = std::max(ans,\
    \ c[1]->query(X, M + 1, R));\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tvoid\
    \ modify(Line X, long long L, long long R) {\r\n\t\tif (X.majorize(S, L, R)) std::swap(X,\
    \ S);\r\n\t\tif (S.majorize(X, L, R)) return;\r\n\t\tif (S.get(L) < X.get(L))\
    \ std::swap(X, S);\r\n\t\tlong long M = mid(L + R);\r\n\t\tif (X.get(M) >= S.get(M))\
    \ std::swap(X, S), mc(0), c[0]->modify(X, L, M);\r\n\t\telse mc(1), c[1]->modify(X,\
    \ M + 1, R);\r\n\t}\r\n\t\r\n\tvoid upd(Line X, long long lo, long long hi, long\
    \ long L, long long R) {\r\n\t\tif (R < lo || hi < L) return;\r\n\t\tif (lo <=\
    \ L && R <= hi) return modify(X, L, R);\r\n\t\tlong long M = mid(L + R);\r\n\t\
    \tif (lo <= M) mc(0), c[0]->upd(X, lo, hi, L, M);\r\n\t\tif (hi > M) mc(1), c[1]->upd(X,\
    \ lo, hi, M + 1, R);\r\n\t}\r\n};\n\r\nint main() {\r\n\tusing namespace std;\r\
    \n\tcin.tie(0)->sync_with_stdio(0);\r\n\tconst int INF = 1e9;\r\n\tint n, q; cin\
    \ >> n >> q;\r\n\tNode L; \r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tint l, r,\
    \ a; long long b;\r\n\t\tcin >> l >> r >> a >> b;\r\n\t\tL.upd({-a, -b}, l, r\
    \ - 1, -INF, INF);\r\n\t}\r\n\tfor (int i = 0; i < q; i++) {\r\n\t\tint t; cin\
    \ >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint l, r, a; long long b; \r\n\t\t\tcin\
    \ >> l >> r >> a >> b;\r\n\t\t\tL.upd({-a, -b}, l, r - 1, -INF, INF);\r\n\t\t\
    } else {\r\n\t\t\tint p; cin >> p;\r\n\t\t\tlong long ans = L.query(p, -INF, INF);\r\
    \n\t\t\tif (ans == numeric_limits<long long>::min()) {\r\n\t\t\t\tcout << \"INFINITY\"\
    \ << '\\n';\r\n\t\t\t} else {\r\n\t\t\t\tcout << -ans << '\\n';\r\n\t\t\t}\r\n\
    \t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/li-chao-tree-online.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tconst int INF = 1e9;\r\n\tint n, q; cin >> n >> q;\r\n\tNode L; \r\n\tfor\
    \ (int i = 0; i < n; i++) {\r\n\t\tint l, r, a; long long b;\r\n\t\tcin >> l >>\
    \ r >> a >> b;\r\n\t\tL.upd({-a, -b}, l, r - 1, -INF, INF);\r\n\t}\r\n\tfor (int\
    \ i = 0; i < q; i++) {\r\n\t\tint t; cin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\t\
    int l, r, a; long long b; \r\n\t\t\tcin >> l >> r >> a >> b;\r\n\t\t\tL.upd({-a,\
    \ -b}, l, r - 1, -INF, INF);\r\n\t\t} else {\r\n\t\t\tint p; cin >> p;\r\n\t\t\
    \tlong long ans = L.query(p, -INF, INF);\r\n\t\t\tif (ans == numeric_limits<long\
    \ long>::min()) {\r\n\t\t\t\tcout << \"INFINITY\" << '\\n';\r\n\t\t\t} else {\r\
    \n\t\t\t\tcout << -ans << '\\n';\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/li-chao-tree-online.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-online.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-online.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-online.test.cpp
- /verify/verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-online.test.cpp.html
title: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-online.test.cpp
---
