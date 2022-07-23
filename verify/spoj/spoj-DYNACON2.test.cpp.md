---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/dsu-rollback.hpp
    title: library/graphs/dsu-rollback.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/offline-dynamic-connectivity.hpp
    title: library/graphs/offline-dynamic-connectivity.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.spoj.com/problems/DYNACON2/
    links:
    - https://www.spoj.com/problems/DYNACON2/
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/DYNACON2/\"\r\n\r\n\
    \r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n\r\nstruct DSURollBack {\r\
    \n\tstd::vector<int> e;\r\n\t\r\n\tvoid init(int n) {\r\n\t\te = std::vector<int>(n,\
    \ -1);\r\n\t}\r\n\r\n\tint get(int x) {\r\n\t\treturn e[x] < 0 ? x : get(e[x]);\r\
    \n\t}\r\n\r\n\tbool same_set(int a, int b) {\r\n\t\treturn get(a) == get(b);\r\
    \n\t}\r\n\r\n\tint size(int x) {\r\n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tstd::vector<std::array<int,\
    \ 4>> mod;\r\n\t\r\n\tbool unite(int x, int y) {\r\n\t\tx = get(x), y = get(y);\r\
    \n\t\tif (x == y) {\r\n\t\t\tmod.push_back({-1, -1, -1, -1});\r\n\t\t\treturn\
    \ 0;\r\n\t\t}\r\n\t\tif (e[x] > e[y]) std::swap(x, y);\r\n\t\tmod.push_back({x,\
    \ y, e[x], e[y]});\r\n\t\te[x] += e[y], e[y] = x;\r\n\t\treturn true;\r\n\t}\r\
    \n\r\n\tvoid rollback() {\r\n\t\tauto a = mod.back();\r\n\t\tmod.pop_back();\r\
    \n\t\tif (a[0] != -1) {\r\n\t\t\te[a[0]] = a[2];\r\n\t\t\te[a[1]] = a[3];\r\n\t\
    \t}\r\n\t}\r\n};\r\n\r\nstruct OfflineDynamicConnectivity {\r\n\tDSURollBack dsu;\r\
    \n\tint sz;\r\n\tstd::vector<std::vector<std::pair<int, int>>> seg;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> queries;\r\n\tstd::vector<int> ans;\r\n\r\n\tvoid upd(int l, int r, std::pair<int,\
    \ int> p) {\r\n\t\t// add edge p from time [l, r]\r\n\t\tfor (l += sz, r += sz\
    \ + 1; l < r; l /= 2, r /= 2) {\r\n\t\t\tif (l & 1) seg[l++].push_back(p);\r\n\
    \t\t\tif (r & 1) seg[--r].push_back(p);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid process(int\
    \ ind) {\r\n\t\tfor (auto& t : seg[ind]) {\r\n\t\t\tdsu.unite(t.first, t.second);\r\
    \n\t\t}\r\n\t\tif (ind >= sz) {\r\n\t\t\t// Process the queries at time ti\r\n\
    \t\t\t// Do stuff with D\r\n\t\t\tint ti = ind - sz; \r\n\t\t\tfor (auto& qq :\
    \ queries[ti]) {\r\n\t\t\t\tans.push_back(dsu.same_set(qq.first, qq.second));\r\
    \n\t\t\t}\r\n\t\t} else {\r\n\t\t\tprocess(2 * ind); process(2 * ind + 1);\r\n\
    \t\t}\r\n\t\tfor (auto& t : seg[ind]) {\r\n\t\t\tdsu.rollback();\r\n\t\t}\r\n\t\
    }\r\n\r\n\tvoid init(int n, int max_time) {\r\n\t\tsz = 1;\r\n\t\twhile (sz <\
    \ max_time) sz *= 2;\r\n\t\tseg.assign(2 * sz, {});\r\n\t\tqueries.assign(sz,\
    \ {});\r\n\t\tdsu.init(n);\r\n\t}\r\n\r\n\tvoid add_query(int ti, int u, int v)\
    \ {\r\n\t\tqueries[ti].emplace_back(u, v);\r\n\t}\r\n\t\r\n\tstd::vector<int>\
    \ solve() {\r\n\t\tprocess(1);\r\n\t\treturn ans;\r\n\t}\r\n};\n\r\nint main()\
    \ {\r\n    using namespace std;\r\n    int n, m; cin >> n >> m;\r\n    OfflineDynamicConnectivity\
    \ O;\r\n    O.init(n, m + 1);\r\n    set<array<int, 3>> edges;\r\n    for (int\
    \ i = 0; i < m; i++) {\r\n        string s; cin >> s;\r\n        if (s == \"add\"\
    ) {\r\n            int u, v; \r\n            cin >> u >> v;\r\n            u--,\
    \ v--;\r\n            if (u > v) swap(u, v);\r\n            edges.insert({u, v,\
    \ i});\r\n        } else if (s == \"rem\") {\r\n            int u, v; \r\n   \
    \         cin >> u >> v; \r\n            u--, v--;\r\n            if (u > v) swap(u,\
    \ v);\r\n            auto e = *edges.lower_bound({u, v, -1});\r\n            O.upd(e[2],\
    \ i, {u, v});\r\n            edges.erase(e);\r\n        } else {\r\n         \
    \   int u, v; \r\n            cin >> u >> v;\r\n            u--, v--;\r\n    \
    \        O.add_query(i, u, v);\r\n        }\r\n    }\r\n    for (auto e : edges)\
    \ {\r\n        O.upd(e[2], m, {e[0], e[1]});\r\n    }\r\n    auto ans = O.solve();\r\
    \n    for (auto x : ans) {\r\n        cout << (x ? \"YES\" : \"NO\") << '\\n';\r\
    \n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/DYNACON2/\"\r\n\r\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/offline-dynamic-connectivity.hpp\"\
    \r\n\r\nint main() {\r\n    using namespace std;\r\n    int n, m; cin >> n >>\
    \ m;\r\n    OfflineDynamicConnectivity O;\r\n    O.init(n, m + 1);\r\n    set<array<int,\
    \ 3>> edges;\r\n    for (int i = 0; i < m; i++) {\r\n        string s; cin >>\
    \ s;\r\n        if (s == \"add\") {\r\n            int u, v; \r\n            cin\
    \ >> u >> v;\r\n            u--, v--;\r\n            if (u > v) swap(u, v);\r\n\
    \            edges.insert({u, v, i});\r\n        } else if (s == \"rem\") {\r\n\
    \            int u, v; \r\n            cin >> u >> v; \r\n            u--, v--;\r\
    \n            if (u > v) swap(u, v);\r\n            auto e = *edges.lower_bound({u,\
    \ v, -1});\r\n            O.upd(e[2], i, {u, v});\r\n            edges.erase(e);\r\
    \n        } else {\r\n            int u, v; \r\n            cin >> u >> v;\r\n\
    \            u--, v--;\r\n            O.add_query(i, u, v);\r\n        }\r\n \
    \   }\r\n    for (auto e : edges) {\r\n        O.upd(e[2], m, {e[0], e[1]});\r\
    \n    }\r\n    auto ans = O.solve();\r\n    for (auto x : ans) {\r\n        cout\
    \ << (x ? \"YES\" : \"NO\") << '\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/offline-dynamic-connectivity.hpp
  - library/graphs/dsu-rollback.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-DYNACON2.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-DYNACON2.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-DYNACON2.test.cpp
- /verify/verify/spoj/spoj-DYNACON2.test.cpp.html
title: verify/spoj/spoj-DYNACON2.test.cpp
---
