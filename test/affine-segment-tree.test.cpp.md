---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/affine-segment-tree.hpp
    title: library/data-structures/1d-range-queries/affine-segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#include <bits/stdc++.h>\n\n\ntemplate <class T> struct AffineSegmentTree\
    \ {\n\tint sz;\n\tstd::vector<T> sum, mult, add;\n\n\tvoid push(int ind, int L,\
    \ int R) { // modify values for current node\n\t\tsum[ind] *= mult[ind]; sum[ind]\
    \ += (R - L + 1) * add[ind];\n\t\tif (L != R) {\n\t\t\tmult[2 * ind] *= mult[ind];\
    \ mult[2 * ind + 1] *= mult[ind];\n\t\t\tadd[2 * ind] *= mult[ind]; add[2 * ind]\
    \ += add[ind];\n\t\t\tadd[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n\
    \t\t}\n\t\tadd[ind] = 0; mult[ind] = 1;\n\t}\n\n\tvoid init(int n) {\n\t\tsz =\
    \ 1;\n\t\twhile (sz < n) sz *= 2;\n\t\tmult.assign(2 * sz, 1);\n\t\tsum.assign(2\
    \ * sz, 0);\n\t\tadd.assign(2 * sz, 0);\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind]\
    \ = sum[2 * ind] + sum[2 * ind + 1];\n\t}\n\n\t// t == 0 is add, t == 1 is for\
    \ multiplying\n\tvoid upd(int t, int lo, int hi, T inc, int ind = 1, int L = 0,\
    \ int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi <\
    \ L || R < lo) return;\n\t\tif (lo <= L && R <= hi) {\n\t\t\tif(t == 0) add[ind]\
    \ = inc;  \n\t\t\telse mult[ind] = inc;\n\t\t\tpush(ind, L, R); return;\n\t\t\
    }\n\t\tint M = (L + R) / 2;\n\t\tupd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo,\
    \ hi, inc, 2 * ind + 1, M + 1, R);\n\t\tpull(ind);\n\t}\n\t\n\tT qsum(int lo,\
    \ int hi, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\
    \tpush(ind, L, R);\n\t\tif (lo > R || L > hi) return 0;\n\t\tif (lo <= L && R\
    \ <= hi) return sum[ind];\n\t\tint M = (L + R) / 2;\n\t\treturn qsum(lo, hi, 2\
    \ * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n\t}\n};\n\nint main() {\n\
    \    ios_base::sync_with_stdio(0);\n    cin.tie(0);\n    AffineSeg<mi, (1 << 19)>\
    \ seg;\n    seg.init();\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n\
    \    for (int i = 0; i < n; i++) {\n        cin >> a[i];\n        seg.upd(i, i,\
    \ 0, a[i]);\n    }\n    while (q--) {\n        int t;\n        cin >> t;\n   \
    \     if (t == 0) {\n            int l, r, b, c;\n            cin >> l >> r >>\
    \ b >> c;\n            seg.upd(l, r - 1, 1, b);\n            seg.upd(l, r - 1,\
    \ 0, c);\n        } else {\n            int l, r;\n            cin >> l >> r;\n\
    \            cout << seg.qsum(l, r - 1) << '\\n';\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n#include \"../library/data-structures/1d-range-queries/affine-segment-tree.hpp\"\
    \n\nint main() {\n    ios_base::sync_with_stdio(0);\n    cin.tie(0);\n    AffineSeg<mi,\
    \ (1 << 19)> seg;\n    seg.init();\n    int n, q;\n    cin >> n >> q;\n    vector<int>\
    \ a(n);\n    for (int i = 0; i < n; i++) {\n        cin >> a[i];\n        seg.upd(i,\
    \ i, 0, a[i]);\n    }\n    while (q--) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int l, r, b, c;\n            cin >> l >> r\
    \ >> b >> c;\n            seg.upd(l, r - 1, 1, b);\n            seg.upd(l, r -\
    \ 1, 0, c);\n        } else {\n            int l, r;\n            cin >> l >>\
    \ r;\n            cout << seg.qsum(l, r - 1) << '\\n';\n        }\n    }\n   \
    \ return 0;\n}"
  dependsOn:
  - library/data-structures/1d-range-queries/affine-segment-tree.hpp
  isVerificationFile: true
  path: test/affine-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 20:00:47-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/affine-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/test/affine-segment-tree.test.cpp
- /verify/test/affine-segment-tree.test.cpp.html
title: test/affine-segment-tree.test.cpp
---
