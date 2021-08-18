---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/DYNACON2/\"\n\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n\nstruct DSURollBack {\n\tstd::vector<int> e;\n\t\n\tvoid init(int n) {\n\t\t\
    e = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0 ?\
    \ x : get(e[x]);\n\t}\n\n\tbool same_set(int a, int b) {\n\t\treturn get(a) ==\
    \ get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tstd::vector<std::array<int,\
    \ 4>> mod;\n\t\n\tbool unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\t\
    if (x == y) {\n\t\t\tmod.push_back({-1, -1, -1, -1});\n\t\t\treturn 0;\n\t\t}\n\
    \t\tif (e[x] > e[y]) std::swap(x, y);\n\t\tmod.push_back({x, y, e[x], e[y]});\n\
    \t\te[x] += e[y], e[y] = x;\n\t\treturn true;\n\t}\n\n\tvoid rollback() {\n\t\t\
    auto a = mod.back();\n\t\tmod.pop_back();\n\t\tif (a[0] != -1) {\n\t\t\te[a[0]]\
    \ = a[2];\n\t\t\te[a[1]] = a[3];\n\t\t}\n\t}\n};\n\nstruct OfflineDynamicConnectivity\
    \ {\n\tDSURollBack dsu;\n\tint sz;\n\tstd::vector<std::vector<std::pair<int, int>>>\
    \ seg;\n\tstd::vector<std::vector<std::pair<int, int>>> queries;\n\tstd::vector<int>\
    \ ans;\n\n\tvoid upd(int l, int r, std::pair<int, int> p) {\n\t\t// add edge p\
    \ from time [l, r]\n\t\tfor (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {\n\t\
    \t\tif (l & 1) seg[l++].push_back(p);\n\t\t\tif (r & 1) seg[--r].push_back(p);\n\
    \t\t}\n\t}\n\n\tvoid process(int ind) {\n\t\tfor (auto& t : seg[ind]) {\n\t\t\t\
    dsu.unite(t.first, t.second);\n\t\t}\n\t\tif (ind >= sz) {\n\t\t\t// Process the\
    \ queries at time ti\n\t\t\t// Do stuff with D\n\t\t\tint ti = ind - sz; \n\t\t\
    \tfor (auto& qq : queries[ti]) {\n\t\t\t\tans.push_back(dsu.same_set(qq.first,\
    \ qq.second));\n\t\t\t}\n\t\t} else {\n\t\t\tprocess(2 * ind); process(2 * ind\
    \ + 1);\n\t\t}\n\t\tfor (auto& t : seg[ind]) {\n\t\t\tdsu.rollback();\n\t\t}\n\
    \t}\n\n\tvoid init(int n, int max_time) {\n\t\tsz = 1;\n\t\twhile (sz < max_time)\
    \ sz *= 2;\n\t\tseg.assign(2 * sz, {});\n\t\tqueries.assign(sz, {});\n\t\tdsu.init(n);\n\
    \t}\n\n\tvoid add_query(int ti, int u, int v) {\n\t\tqueries[ti].emplace_back(u,\
    \ v);\n\t}\n\t\n\tstd::vector<int> solve() {\n\t\tprocess(1);\n\t\treturn ans;\n\
    \t}\n};\n\nint main() {\n    using namespace std;\n    int n, m; cin >> n >> m;\n\
    \    OfflineDynamicConnectivity O;\n    O.init(n, m + 1);\n    set<array<int,\
    \ 3>> edges;\n    for (int i = 0; i < m; i++) {\n        string s; cin >> s;\n\
    \        if (s == \"add\") {\n            int u, v; \n            cin >> u >>\
    \ v;\n            u--, v--;\n            if (u > v) swap(u, v);\n            edges.insert({u,\
    \ v, i});\n        } else if (s == \"rem\") {\n            int u, v; \n      \
    \      cin >> u >> v; \n            u--, v--;\n            if (u > v) swap(u,\
    \ v);\n            auto e = *edges.lower_bound({u, v, -1});\n            O.upd(e[2],\
    \ i, {u, v});\n            edges.erase(e);\n        } else {\n            int\
    \ u, v; \n            cin >> u >> v;\n            u--, v--;\n            O.add_query(i,\
    \ u, v);\n        }\n    }\n    for (auto e : edges) {\n        O.upd(e[2], m,\
    \ {e[0], e[1]});\n    }\n    auto ans = O.solve();\n    for (auto x : ans) {\n\
    \        cout << (x ? \"YES\" : \"NO\") << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/DYNACON2/\"\n\n#include \"\
    ../../library/contest/template-minimal.hpp\"\n#include \"../../library/graphs/offline-dynamic-connectivity.hpp\"\
    \n\nint main() {\n    using namespace std;\n    int n, m; cin >> n >> m;\n   \
    \ OfflineDynamicConnectivity O;\n    O.init(n, m + 1);\n    set<array<int, 3>>\
    \ edges;\n    for (int i = 0; i < m; i++) {\n        string s; cin >> s;\n   \
    \     if (s == \"add\") {\n            int u, v; \n            cin >> u >> v;\n\
    \            u--, v--;\n            if (u > v) swap(u, v);\n            edges.insert({u,\
    \ v, i});\n        } else if (s == \"rem\") {\n            int u, v; \n      \
    \      cin >> u >> v; \n            u--, v--;\n            if (u > v) swap(u,\
    \ v);\n            auto e = *edges.lower_bound({u, v, -1});\n            O.upd(e[2],\
    \ i, {u, v});\n            edges.erase(e);\n        } else {\n            int\
    \ u, v; \n            cin >> u >> v;\n            u--, v--;\n            O.add_query(i,\
    \ u, v);\n        }\n    }\n    for (auto e : edges) {\n        O.upd(e[2], m,\
    \ {e[0], e[1]});\n    }\n    auto ans = O.solve();\n    for (auto x : ans) {\n\
    \        cout << (x ? \"YES\" : \"NO\") << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/offline-dynamic-connectivity.hpp
  - library/graphs/dsu-rollback.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-DYNACON2.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 13:31:52-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-DYNACON2.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-DYNACON2.test.cpp
- /verify/verify/spoj/spoj-DYNACON2.test.cpp.html
title: verify/spoj/spoj-DYNACON2.test.cpp
---
