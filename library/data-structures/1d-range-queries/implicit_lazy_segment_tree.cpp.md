---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/implicit_lazy_segment_tree.cpp\"\
    \n#include <bits/stdc++.h>\n\ntemplate <class T> struct SegmentTree {\n    SegmentTree<T>\
    \ *left, *right;\n    T sum, lazy;\n\n    SegmentTree(int l, int r) {\n      \
    \  lazy = 0;\n        if (l == r) {\n            sum = 0;\n        } else {\n\
    \            int m = (l + r) >> 1;\n            left = new SegmentTree<T>(l, m);\n\
    \            right = new SegmentTree<T>(m + 1, r);\n            pull();\n    \
    \    }\n    }\n\n    void pull() {\n        sum = left->sum + right->sum;\n  \
    \  }\n\n    void push(int l, int r) {\n        sum += (r - l + 1) * lazy;\n  \
    \      if (l != r) {\n            left->lazy += lazy;\n            right->lazy\
    \ += lazy;\n        }\n        lazy = 0;\n    }\n\n    void update(int lo, int\
    \ hi, T inc, int l, int r) {\n        push(l, r);\n        if (r < lo || hi <\
    \ l) {\n            return;\n        } else if (lo <= l && r <= hi) {\n      \
    \      lazy = inc;\n            push(l, r);\n        } else {\n            int\
    \ m = (l + r) >> 1;\n            left->update(lo, hi, inc, l, m);\n          \
    \  right->update(lo, hi, inc, m + 1, r);\n            pull();\n        }\n   \
    \ }\n\n    T query(int lo, int hi, int l, int r) {\n        push(l, r);\n    \
    \    if (r < lo || hi < l) {\n            return 0;\n        } else if (lo <=\
    \ l && r <= hi) {\n            return sum;\n        } else {\n            int\
    \ m = (l + r) >> 1;\n            return left->query(lo, hi, l, m) + right->query(lo,\
    \ hi, m + 1, r);\n        }\n    }\n};\n\nint main() {\n    using namespace std;\n\
    \    cin.tie(0)->sync_with_stdio(0);\n    int n, q; \n    cin >> n >> q;\n   \
    \ SegmentTree<long long> *seg = new SegmentTree<long long>(0, n - 1);\n    for\
    \ (int i = 0; i < n; ++i) {\n        int a; \n        cin >> a;\n        seg->update(i,\
    \ i, a, 0, n - 1);\n    }\n    while (q--) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {  \n            int p, x; \n            cin >> p >> x;\n\
    \            seg->update(p, p, x, 0, n - 1);\n        } else {\n            int\
    \ l, r; \n            cin >> l >> r;\n            --r;\n            cout << seg->query(l,\
    \ r, 0, n - 1) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct SegmentTree {\n   \
    \ SegmentTree<T> *left, *right;\n    T sum, lazy;\n\n    SegmentTree(int l, int\
    \ r) {\n        lazy = 0;\n        if (l == r) {\n            sum = 0;\n     \
    \   } else {\n            int m = (l + r) >> 1;\n            left = new SegmentTree<T>(l,\
    \ m);\n            right = new SegmentTree<T>(m + 1, r);\n            pull();\n\
    \        }\n    }\n\n    void pull() {\n        sum = left->sum + right->sum;\n\
    \    }\n\n    void push(int l, int r) {\n        sum += (r - l + 1) * lazy;\n\
    \        if (l != r) {\n            left->lazy += lazy;\n            right->lazy\
    \ += lazy;\n        }\n        lazy = 0;\n    }\n\n    void update(int lo, int\
    \ hi, T inc, int l, int r) {\n        push(l, r);\n        if (r < lo || hi <\
    \ l) {\n            return;\n        } else if (lo <= l && r <= hi) {\n      \
    \      lazy = inc;\n            push(l, r);\n        } else {\n            int\
    \ m = (l + r) >> 1;\n            left->update(lo, hi, inc, l, m);\n          \
    \  right->update(lo, hi, inc, m + 1, r);\n            pull();\n        }\n   \
    \ }\n\n    T query(int lo, int hi, int l, int r) {\n        push(l, r);\n    \
    \    if (r < lo || hi < l) {\n            return 0;\n        } else if (lo <=\
    \ l && r <= hi) {\n            return sum;\n        } else {\n            int\
    \ m = (l + r) >> 1;\n            return left->query(lo, hi, l, m) + right->query(lo,\
    \ hi, m + 1, r);\n        }\n    }\n};\n\nint main() {\n    using namespace std;\n\
    \    cin.tie(0)->sync_with_stdio(0);\n    int n, q; \n    cin >> n >> q;\n   \
    \ SegmentTree<long long> *seg = new SegmentTree<long long>(0, n - 1);\n    for\
    \ (int i = 0; i < n; ++i) {\n        int a; \n        cin >> a;\n        seg->update(i,\
    \ i, a, 0, n - 1);\n    }\n    while (q--) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {  \n            int p, x; \n            cin >> p >> x;\n\
    \            seg->update(p, p, x, 0, n - 1);\n        } else {\n            int\
    \ l, r; \n            cin >> l >> r;\n            --r;\n            cout << seg->query(l,\
    \ r, 0, n - 1) << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/implicit_lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-06-04 22:59:38-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/implicit_lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/implicit_lazy_segment_tree.cpp
- /library/library/data-structures/1d-range-queries/implicit_lazy_segment_tree.cpp.html
title: library/data-structures/1d-range-queries/implicit_lazy_segment_tree.cpp
---
