---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/fenwick-tree.hpp
    title: library/data-structures/1d-range-queries/fenwick-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\ntemplate\
    \ <class T> struct FenwickTree {\n\tstd::vector<T> fwt;\n\tint n;\n\n\tvoid init(int\
    \ n_) {\n\t\tn = n_;\n\t\tfwt.assign(n, 0);\n\t}\n\n\tvoid init(std::vector<T>\
    \ &a) {\n\t\tn = (int)a.size();\n\t\tfwt.assign(n, 0);\n\t\tfor (int i = 0; i\
    \ < (int)a.size(); i++) {\n\t\t\tadd(i, a[i]);\n\t\t}\n\t}\n\n\tT sum(int r) {\n\
    \t\tT ret = 0;\n\t\tfor (; r >= 0; r = (r & (r + 1)) - 1) \n\t\t\tret += fwt[r];\n\
    \t\treturn ret;\n\t}\n\n\tT query(int l, int r) {\n\t\treturn sum(r) - sum(l -\
    \ 1);\n\t}\n\t\n\tvoid add(int idx, T delta) {\n\t\tfor (; idx < n; idx = idx\
    \ | (idx + 1)) \n\t\t\tfwt[idx] += delta;\n\t}\n};\n\nint main() {\n\tusing namespace\
    \ std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n, q; \n    cin >> n >> q;\n\t\
    vector<long long> a(n);\n\tfor (int i = 0; i < n; i++) \n\t\tcin >> a[i];\n\t\
    FenwickTree<long long> F; \n\tF.init(a);\n\twhile (q--) {\n        int t;\n  \
    \      cin >> t;\n        if (t == 0) {\n            int p, x;\n            cin\
    \ >> p >> x;\n            F.add(p, x);\n        } else {\n            int l, r;\n\
    \            cin >> l >> r;\n            --r;\n            cout << F.query(l,\
    \ r) << '\\n';\n        }\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../library/contest/template-minimal.hpp\"\n#include \"../library/data-structures/1d-range-queries/fenwick-tree.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, q; \n    cin >> n >> q;\n\tvector<long long> a(n);\n\tfor (int i = 0; i\
    \ < n; i++) \n\t\tcin >> a[i];\n\tFenwickTree<long long> F; \n\tF.init(a);\n\t\
    while (q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n    \
    \        int p, x;\n            cin >> p >> x;\n            F.add(p, x);\n   \
    \     } else {\n            int l, r;\n            cin >> l >> r;\n          \
    \  --r;\n            cout << F.query(l, r) << '\\n';\n        }\n\t}\n\treturn\
    \ 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/fenwick-tree.hpp
  isVerificationFile: true
  path: test/fenwick-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 21:14:38-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/fenwick-tree.test.cpp
layout: document
redirect_from:
- /verify/test/fenwick-tree.test.cpp
- /verify/test/fenwick-tree.test.cpp.html
title: test/fenwick-tree.test.cpp
---
