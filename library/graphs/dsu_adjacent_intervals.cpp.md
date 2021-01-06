---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dsu_adjacent_intervals.cpp\"\n#include <bits/stdc++.h>\n\
    /**\n * Call unite to join interval with right endpoint x and left endpoint y\n\
    \ * It is assumed that x + 1 = y\n * get_interval finds the interval element x\
    \ is in\n */\nstruct IntervalJoin {\n    std::vector<int> e;\n    std::vector<std::pair<int,\
    \ int>> interval;\n    void init(int n) {\n        e = std::vector<int>(n, -1);\n\
    \        interval.resize(n);\n        for (int i = 0; i < n; i++) {\n        \
    \    interval[i].first = interval[i].second = i;\n        }\n    }\n    int get(int\
    \ x) {\n        return e[x] < 0 ? x : e[x] = get(e[x]);\n    }\n    bool same_set(int\
    \ a, int b) {\n        return get(a) == get(b);\n    }\n    int size(int x) {\n\
    \        return -e[get(x)];\n    }\n    bool unite(int x, int y) {\n        x\
    \ = get(x), y = get(y);\n        if (x == y) return false;\n        if (e[x] >\
    \ e[y]) std::swap(x, y);\n        interval[x].first = std::min(interval[x].first,\
    \ interval[y].first);\n        interval[x].second = std::max(interval[x].second,\
    \ interval[y].second);\n        e[x] += e[y]; e[y] = x;\n        return true;\n\
    \    }\n    std::pair<int, int> get_interval(int x) {\n        x = get(x);\n \
    \       return interval[x];\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n/**\n * Call unite to join interval with right\
    \ endpoint x and left endpoint y\n * It is assumed that x + 1 = y\n * get_interval\
    \ finds the interval element x is in\n */\nstruct IntervalJoin {\n    std::vector<int>\
    \ e;\n    std::vector<std::pair<int, int>> interval;\n    void init(int n) {\n\
    \        e = std::vector<int>(n, -1);\n        interval.resize(n);\n        for\
    \ (int i = 0; i < n; i++) {\n            interval[i].first = interval[i].second\
    \ = i;\n        }\n    }\n    int get(int x) {\n        return e[x] < 0 ? x :\
    \ e[x] = get(e[x]);\n    }\n    bool same_set(int a, int b) {\n        return\
    \ get(a) == get(b);\n    }\n    int size(int x) {\n        return -e[get(x)];\n\
    \    }\n    bool unite(int x, int y) {\n        x = get(x), y = get(y);\n    \
    \    if (x == y) return false;\n        if (e[x] > e[y]) std::swap(x, y);\n  \
    \      interval[x].first = std::min(interval[x].first, interval[y].first);\n \
    \       interval[x].second = std::max(interval[x].second, interval[y].second);\n\
    \        e[x] += e[y]; e[y] = x;\n        return true;\n    }\n    std::pair<int,\
    \ int> get_interval(int x) {\n        x = get(x);\n        return interval[x];\n\
    \    }\n};\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu_adjacent_intervals.cpp
  requiredBy: []
  timestamp: '2021-01-05 22:23:51-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dsu_adjacent_intervals.cpp
layout: document
redirect_from:
- /library/library/graphs/dsu_adjacent_intervals.cpp
- /library/library/graphs/dsu_adjacent_intervals.cpp.html
title: library/graphs/dsu_adjacent_intervals.cpp
---
