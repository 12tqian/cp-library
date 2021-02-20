---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ideone.com/J3R7nb
  bundledCode: "#line 1 \"library/graphs/offline_dynamic_connectivity.cpp\"\n#include\
    \ <bits/stdc++.h>\n\n/** \n * Example of use: https://ideone.com/J3R7nb\n * Solves\
    \ SPOJ DYNACON2\n */\n\nstruct DSURollBack {\n    std::vector<int> e;\n\n    void\
    \ init(int n) {\n        e = std::vector<int>(n, -1);\n    }\n\n    int get(int\
    \ x) {\n        return e[x] < 0 ? x : get(e[x]);\n    }\n\n    bool same_set(int\
    \ a, int b) {\n        return get(a) == get(b);\n    }\n\n    int size(int x)\
    \ {\n        return -e[get(x)];\n    }\n\n    std::vector<std::array<int, 4>>\
    \ mod;\n\n    bool unite(int x, int y) {\n        x = get(x), y = get(y);\n  \
    \      if (x == y) {\n            mod.push_back({-1, -1, -1, -1});\n         \
    \   return 0;\n        }\n        if (e[x] > e[y]) std::swap(x, y);\n        mod.push_back({x,\
    \ y, e[x], e[y]});\n        e[x] += e[y], e[y] = x;\n        return true;\n  \
    \  }\n\n    void rollback() {\n        auto a = mod.back();\n        mod.pop_back();\n\
    \        if (a[0] != -1) {\n            e[a[0]] = a[2];\n            e[a[1]] =\
    \ a[3];\n        }\n    }\n};\n\nstruct OfflineDynamicConnectivity {\n    DSURollBack\
    \ D;\n    int sz;\n    std::vector<std::vector<std::pair<int, int>>> seg;\n\n\
    \    void upd(int l, int r, std::pair<int, int> p) {\n        // add edge p from\
    \ time [l, r]\n        for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {\n \
    \           if (l & 1) seg[l++].push_back(p);\n            if (r & 1) seg[--r].push_back(p);\n\
    \        }\n    }\n\n    void process(int ind) {\n        for (auto& t : seg[ind])\
    \ {\n            D.unite(t.first, t.second);\n        }\n        if (ind >= sz)\
    \ {\n            // Process the queries at time ti\n            // Do stuff with\
    \ D\n            int ti = ind - sz; \n        } else {\n            process(2\
    \ * ind); process(2 * ind + 1);\n        }\n        for (auto& t : seg[ind]) {\n\
    \            D.rollback();\n        }\n    }\n\n    void init(int n, int max_time)\
    \ {\n        sz = 1;\n        while (sz < max_time) sz *= 2;\n        seg.assign(2\
    \ * sz, {});\n        D.init(n);\n    }\n    \n    void solve() {\n        process(1);\n\
    \    }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/** \n * Example of use: https://ideone.com/J3R7nb\n\
    \ * Solves SPOJ DYNACON2\n */\n\nstruct DSURollBack {\n    std::vector<int> e;\n\
    \n    void init(int n) {\n        e = std::vector<int>(n, -1);\n    }\n\n    int\
    \ get(int x) {\n        return e[x] < 0 ? x : get(e[x]);\n    }\n\n    bool same_set(int\
    \ a, int b) {\n        return get(a) == get(b);\n    }\n\n    int size(int x)\
    \ {\n        return -e[get(x)];\n    }\n\n    std::vector<std::array<int, 4>>\
    \ mod;\n\n    bool unite(int x, int y) {\n        x = get(x), y = get(y);\n  \
    \      if (x == y) {\n            mod.push_back({-1, -1, -1, -1});\n         \
    \   return 0;\n        }\n        if (e[x] > e[y]) std::swap(x, y);\n        mod.push_back({x,\
    \ y, e[x], e[y]});\n        e[x] += e[y], e[y] = x;\n        return true;\n  \
    \  }\n\n    void rollback() {\n        auto a = mod.back();\n        mod.pop_back();\n\
    \        if (a[0] != -1) {\n            e[a[0]] = a[2];\n            e[a[1]] =\
    \ a[3];\n        }\n    }\n};\n\nstruct OfflineDynamicConnectivity {\n    DSURollBack\
    \ D;\n    int sz;\n    std::vector<std::vector<std::pair<int, int>>> seg;\n\n\
    \    void upd(int l, int r, std::pair<int, int> p) {\n        // add edge p from\
    \ time [l, r]\n        for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {\n \
    \           if (l & 1) seg[l++].push_back(p);\n            if (r & 1) seg[--r].push_back(p);\n\
    \        }\n    }\n\n    void process(int ind) {\n        for (auto& t : seg[ind])\
    \ {\n            D.unite(t.first, t.second);\n        }\n        if (ind >= sz)\
    \ {\n            // Process the queries at time ti\n            // Do stuff with\
    \ D\n            int ti = ind - sz; \n        } else {\n            process(2\
    \ * ind); process(2 * ind + 1);\n        }\n        for (auto& t : seg[ind]) {\n\
    \            D.rollback();\n        }\n    }\n\n    void init(int n, int max_time)\
    \ {\n        sz = 1;\n        while (sz < max_time) sz *= 2;\n        seg.assign(2\
    \ * sz, {});\n        D.init(n);\n    }\n    \n    void solve() {\n        process(1);\n\
    \    }\n};\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/offline_dynamic_connectivity.cpp
  requiredBy: []
  timestamp: '2021-02-20 15:38:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/offline_dynamic_connectivity.cpp
layout: document
redirect_from:
- /library/library/graphs/offline_dynamic_connectivity.cpp
- /library/library/graphs/offline_dynamic_connectivity.cpp.html
title: library/graphs/offline_dynamic_connectivity.cpp
---
