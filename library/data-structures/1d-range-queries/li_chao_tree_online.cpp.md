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
    \ for minimum\n\nstruct Line {\n    int k; long long m;\n\n    Line(int _k, long\
    \ long _m) { k = _k, m = _m; }\n    Line() : Line(0, std::numeric_limits<long\
    \ long>::min()) { }\n\n    long long get(long long x) { return k * x + m; }\n\n\
    \    bool majorize(Line X, long long L, long long R) { \n        return get(L)\
    \ >= X.get(L) && get(R) >= X.get(R); \n    }\n};\n\nstruct Node {\n    Node* c[2];\
    \ Line S;\n\n    Node() { c[0] = c[1] = NULL; S = Line(); }\n    ~Node() { for\
    \ (int i = 0; i < 2; i++) delete c[i]; }\n\n    void mc(int i) { if (!c[i]) c[i]\
    \ = new Node(); }\n    long long mid(long long x) { return x & 1 ? (x - 1) / 2\
    \ : x / 2; }\n\n    long long query(long long X, long long L, long long R) {\n\
    \        long long ans = S.get(X);\n        long long M = mid(L + R);\n      \
    \  if (X <= M) {\n            if (c[0]) ans = std::max(ans, c[0]->query(X, L,\
    \ M));\n        } else {\n            if (c[1]) ans = std::max(ans, c[1]->query(X,\
    \ M + 1, R));\n        }\n        return ans;\n    }\n\n    void modify(Line X,\
    \ long long L, long long R) {\n        if (X.majorize(S, L, R)) std::swap(X, S);\n\
    \        if (S.majorize(X, L, R)) return;\n        if (S.get(L) < X.get(L)) std::swap(X,\
    \ S);\n        long long M = mid(L + R);\n        if (X.get(M) >= S.get(M)) std::swap(X,\
    \ S), mc(0), c[0]->modify(X, L, M);\n        else mc(1), c[1]->modify(X, M + 1,\
    \ R);\n    }\n    \n    void upd(Line X, long long lo, long long hi, long long\
    \ L, long long R) {\n        if (R < lo || hi < L) return;\n        if (lo <=\
    \ L && R <= hi) return modify(X, L, R);\n        long long M = mid(L + R);\n \
    \       if (lo <= M) mc(0), c[0]->upd(X, lo, hi, L, M);\n        if (hi > M) mc(1),\
    \ c[1]->upd(X, lo, hi, M + 1, R);\n    }\n};\n\nint main() {\n    using namespace\
    \ std;\n    cin.tie(0)->sync_with_stdio(0);\n    const int INF = 1e9;\n    int\
    \ n, q; cin >> n >> q;\n    Node L;\n    for (int i = 0; i < n; i++) {\n     \
    \   int l, r, a; long long b;\n        cin >> l >> r >> a >> b;\n        L.upd({-a,\
    \ -b}, l, r - 1, -INF, INF);\n    }\n    for (int i = 0; i < q; i++) {\n     \
    \   int t; cin >> t;\n        if (t == 0) {\n            int l, r, a; long long\
    \ b; \n            cin >> l >> r >> a >> b;\n            L.upd({-a, -b}, l, r\
    \ - 1, -INF, INF);\n        } else {\n            int p; cin >> p;\n         \
    \   long long ans = L.query(p, -INF, INF);\n            if (ans == numeric_limits<long\
    \ long>::min()) {\n                cout << \"INFINITY\" << '\\n';\n          \
    \  } else {\n                cout << -ans << '\\n';\n            }\n        }\n\
    \    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n// Currently set to get the max of things, use\
    \ negatives for minimum\n\nstruct Line {\n    int k; long long m;\n\n    Line(int\
    \ _k, long long _m) { k = _k, m = _m; }\n    Line() : Line(0, std::numeric_limits<long\
    \ long>::min()) { }\n\n    long long get(long long x) { return k * x + m; }\n\n\
    \    bool majorize(Line X, long long L, long long R) { \n        return get(L)\
    \ >= X.get(L) && get(R) >= X.get(R); \n    }\n};\n\nstruct Node {\n    Node* c[2];\
    \ Line S;\n\n    Node() { c[0] = c[1] = NULL; S = Line(); }\n    ~Node() { for\
    \ (int i = 0; i < 2; i++) delete c[i]; }\n\n    void mc(int i) { if (!c[i]) c[i]\
    \ = new Node(); }\n    long long mid(long long x) { return x & 1 ? (x - 1) / 2\
    \ : x / 2; }\n\n    long long query(long long X, long long L, long long R) {\n\
    \        long long ans = S.get(X);\n        long long M = mid(L + R);\n      \
    \  if (X <= M) {\n            if (c[0]) ans = std::max(ans, c[0]->query(X, L,\
    \ M));\n        } else {\n            if (c[1]) ans = std::max(ans, c[1]->query(X,\
    \ M + 1, R));\n        }\n        return ans;\n    }\n\n    void modify(Line X,\
    \ long long L, long long R) {\n        if (X.majorize(S, L, R)) std::swap(X, S);\n\
    \        if (S.majorize(X, L, R)) return;\n        if (S.get(L) < X.get(L)) std::swap(X,\
    \ S);\n        long long M = mid(L + R);\n        if (X.get(M) >= S.get(M)) std::swap(X,\
    \ S), mc(0), c[0]->modify(X, L, M);\n        else mc(1), c[1]->modify(X, M + 1,\
    \ R);\n    }\n    \n    void upd(Line X, long long lo, long long hi, long long\
    \ L, long long R) {\n        if (R < lo || hi < L) return;\n        if (lo <=\
    \ L && R <= hi) return modify(X, L, R);\n        long long M = mid(L + R);\n \
    \       if (lo <= M) mc(0), c[0]->upd(X, lo, hi, L, M);\n        if (hi > M) mc(1),\
    \ c[1]->upd(X, lo, hi, M + 1, R);\n    }\n};\n\nint main() {\n    using namespace\
    \ std;\n    cin.tie(0)->sync_with_stdio(0);\n    const int INF = 1e9;\n    int\
    \ n, q; cin >> n >> q;\n    Node L;\n    for (int i = 0; i < n; i++) {\n     \
    \   int l, r, a; long long b;\n        cin >> l >> r >> a >> b;\n        L.upd({-a,\
    \ -b}, l, r - 1, -INF, INF);\n    }\n    for (int i = 0; i < q; i++) {\n     \
    \   int t; cin >> t;\n        if (t == 0) {\n            int l, r, a; long long\
    \ b; \n            cin >> l >> r >> a >> b;\n            L.upd({-a, -b}, l, r\
    \ - 1, -INF, INF);\n        } else {\n            int p; cin >> p;\n         \
    \   long long ans = L.query(p, -INF, INF);\n            if (ans == numeric_limits<long\
    \ long>::min()) {\n                cout << \"INFINITY\" << '\\n';\n          \
    \  } else {\n                cout << -ans << '\\n';\n            }\n        }\n\
    \    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/li_chao_tree_online.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/li_chao_tree_online.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/li_chao_tree_online.cpp
- /library/library/data-structures/1d-range-queries/li_chao_tree_online.cpp.html
title: library/data-structures/1d-range-queries/li_chao_tree_online.cpp
---
