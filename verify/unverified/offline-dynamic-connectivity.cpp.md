---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ideone.com/J3R7nb
  bundledCode: "#define IGNORE\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <deque>\n#include <iostream>\n#include <iomanip>\n#include\
    \ <list>\n#include <map>\n#include <numeric>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <vector>\n\nusing namespace std;\n\n/** \n * Example of use: https://ideone.com/J3R7nb\n\
    \ * Solves SPOJ DYNACON2\n */\n\nstruct DSURollBack {\n    std::vector<int> e;\n\
    \    void init(int n) {\n        e = std::vector<int>(n, -1);\n    }\n    int\
    \ get(int x) {\n        return e[x] < 0 ? x : get(e[x]);\n    }\n    bool same_set(int\
    \ a, int b) {\n        return get(a) == get(b);\n    }\n    int size(int x) {\n\
    \        return -e[get(x)];\n    }\n    std::vector<std::array<int, 4>> mod;\n\
    \    bool unite(int x, int y) {\n        x = get(x), y = get(y);\n        if (x\
    \ == y) {\n            mod.push_back({-1, -1, -1, -1});\n            return 0;\n\
    \        }\n        if (e[x] > e[y]) std::swap(x, y);\n        mod.push_back({x,\
    \ y, e[x], e[y]});\n        e[x] += e[y], e[y] = x;\n        return true;\n  \
    \  }\n    void rollback() {\n        auto a = mod.back();\n        mod.pop_back();\n\
    \        if (a[0] != -1) {\n            e[a[0]] = a[2];\n            e[a[1]] =\
    \ a[3];\n        }\n    }\n};\n\nstruct OfflineDynamicConnectivity {\n    DSURollBack\
    \ D;\n    int sz;\n    std::vector<std::vector<std::pair<int, int>>> seg;\n  \
    \  std::vector<std::vector<std::pair<int, int>>> queries;\n    std::vector<int>\
    \ ans;\n    void upd(int l, int r, std::pair<int, int> p) {\n        // add edge\
    \ p from time [l, r]\n        for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2)\
    \ {\n            if (l & 1) seg[l++].push_back(p);\n            if (r & 1) seg[--r].push_back(p);\n\
    \        }\n    }\n    void process(int ind) {\n        for (auto& t : seg[ind])\
    \ {\n            D.unite(t.first, t.second);\n        }\n        if (ind >= sz)\
    \ {\n            // Process the queries at time ti\n            // Do stuff with\
    \ D\n            int ti = ind - sz; \n            for (auto& qq : queries[ti])\
    \ {\n                ans.push_back(D.same_set(qq.first, qq.second));\n       \
    \     }\n        } else {\n            process(2 * ind); process(2 * ind + 1);\n\
    \        }\n        for (auto& t : seg[ind]) {\n            D.rollback();\n  \
    \      }\n    }\n    void add_query(int ti, int u, int v) {\n        queries[ti].emplace_back(u,\
    \ v);\n    }\n    void init(int max_time) {\n        sz = 1;\n        while (sz\
    \ < max_time) sz *= 2;\n        seg.assign(2 * sz, {});\n        queries.assign(sz,\
    \ {});\n        D.init(2 * sz);\n    }\n    std::vector<int> solve() {\n     \
    \   process(1);\n        return ans;\n    }\n};\n\nint main() {\n    using namespace\
    \ std;\n    int n, m; cin >> n >> m;\n    OfflineDynamicConnectivity O;\n    O.init(m\
    \ + 1);\n    set<array<int, 3>> edges;\n    for (int i = 0; i < m; i++) {\n  \
    \      string s; cin >> s;\n        if (s == \"add\") {\n            int u, v;\
    \ cin >> u >> v;\n            u--, v--;\n            if (u > v) swap(u, v);\n\
    \            edges.insert({u, v, i});\n        } else if (s == \"rem\") {\n  \
    \          int u, v; cin >> u >> v; \n            u--, v--;\n            if (u\
    \ > v) swap(u, v);\n            auto e = *edges.lower_bound({u, v, -1});\n   \
    \         O.upd(e[2], i, {u, v});\n            edges.erase(e);\n        } else\
    \ {\n            int u, v; cin >> u >> v;\n            u--, v--;\n           \
    \ O.add_query(i, u, v);\n        }\n    }\n    for (auto e : edges) {\n      \
    \  O.upd(e[2], m, {e[0], e[1]});\n    }\n    auto ans = O.solve();\n    for (auto\
    \ x : ans) {\n        cout << (x ? \"YES\" : \"NO\") << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  code: "#define IGNORE\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n\n/** \n * Example of use: https://ideone.com/J3R7nb\n * Solves SPOJ DYNACON2\n\
    \ */\n\nstruct DSURollBack {\n    std::vector<int> e;\n    void init(int n) {\n\
    \        e = std::vector<int>(n, -1);\n    }\n    int get(int x) {\n        return\
    \ e[x] < 0 ? x : get(e[x]);\n    }\n    bool same_set(int a, int b) {\n      \
    \  return get(a) == get(b);\n    }\n    int size(int x) {\n        return -e[get(x)];\n\
    \    }\n    std::vector<std::array<int, 4>> mod;\n    bool unite(int x, int y)\
    \ {\n        x = get(x), y = get(y);\n        if (x == y) {\n            mod.push_back({-1,\
    \ -1, -1, -1});\n            return 0;\n        }\n        if (e[x] > e[y]) std::swap(x,\
    \ y);\n        mod.push_back({x, y, e[x], e[y]});\n        e[x] += e[y], e[y]\
    \ = x;\n        return true;\n    }\n    void rollback() {\n        auto a = mod.back();\n\
    \        mod.pop_back();\n        if (a[0] != -1) {\n            e[a[0]] = a[2];\n\
    \            e[a[1]] = a[3];\n        }\n    }\n};\n\nstruct OfflineDynamicConnectivity\
    \ {\n    DSURollBack D;\n    int sz;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> seg;\n    std::vector<std::vector<std::pair<int, int>>> queries;\n  \
    \  std::vector<int> ans;\n    void upd(int l, int r, std::pair<int, int> p) {\n\
    \        // add edge p from time [l, r]\n        for (l += sz, r += sz + 1; l\
    \ < r; l /= 2, r /= 2) {\n            if (l & 1) seg[l++].push_back(p);\n    \
    \        if (r & 1) seg[--r].push_back(p);\n        }\n    }\n    void process(int\
    \ ind) {\n        for (auto& t : seg[ind]) {\n            D.unite(t.first, t.second);\n\
    \        }\n        if (ind >= sz) {\n            // Process the queries at time\
    \ ti\n            // Do stuff with D\n            int ti = ind - sz; \n      \
    \      for (auto& qq : queries[ti]) {\n                ans.push_back(D.same_set(qq.first,\
    \ qq.second));\n            }\n        } else {\n            process(2 * ind);\
    \ process(2 * ind + 1);\n        }\n        for (auto& t : seg[ind]) {\n     \
    \       D.rollback();\n        }\n    }\n    void add_query(int ti, int u, int\
    \ v) {\n        queries[ti].emplace_back(u, v);\n    }\n    void init(int max_time)\
    \ {\n        sz = 1;\n        while (sz < max_time) sz *= 2;\n        seg.assign(2\
    \ * sz, {});\n        queries.assign(sz, {});\n        D.init(2 * sz);\n    }\n\
    \    std::vector<int> solve() {\n        process(1);\n        return ans;\n  \
    \  }\n};\n\nint main() {\n    using namespace std;\n    int n, m; cin >> n >>\
    \ m;\n    OfflineDynamicConnectivity O;\n    O.init(m + 1);\n    set<array<int,\
    \ 3>> edges;\n    for (int i = 0; i < m; i++) {\n        string s; cin >> s;\n\
    \        if (s == \"add\") {\n            int u, v; cin >> u >> v;\n         \
    \   u--, v--;\n            if (u > v) swap(u, v);\n            edges.insert({u,\
    \ v, i});\n        } else if (s == \"rem\") {\n            int u, v; cin >> u\
    \ >> v; \n            u--, v--;\n            if (u > v) swap(u, v);\n        \
    \    auto e = *edges.lower_bound({u, v, -1});\n            O.upd(e[2], i, {u,\
    \ v});\n            edges.erase(e);\n        } else {\n            int u, v; cin\
    \ >> u >> v;\n            u--, v--;\n            O.add_query(i, u, v);\n     \
    \   }\n    }\n    for (auto e : edges) {\n        O.upd(e[2], m, {e[0], e[1]});\n\
    \    }\n    auto ans = O.solve();\n    for (auto x : ans) {\n        cout << (x\
    \ ? \"YES\" : \"NO\") << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  isVerificationFile: false
  path: verify/unverified/offline-dynamic-connectivity.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:56:26-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/unverified/offline-dynamic-connectivity.cpp
layout: document
redirect_from:
- /library/verify/unverified/offline-dynamic-connectivity.cpp
- /library/verify/unverified/offline-dynamic-connectivity.cpp.html
title: verify/unverified/offline-dynamic-connectivity.cpp
---
