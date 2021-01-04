---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/2d-range-queries/offline_2d_bit.cpp\"\
    \n#include <bits/stdc++.h>\n\n/**\n * x \\in [0, sz)\n * y \\in [0, sz)\n * First\
    \ do all the updates, then call init\n * Afterwards, do the updates again, and\
    \ now you can mix in the queries too\n */\n\ntemplate<class T> struct Offline2DBIT\
    \ { \n    bool mode = 0; // mode = 1 -> initialized\n    int sz;\n    std::vector<std::pair<int,\
    \ int>> todo;\n    std::vector<int> cnt, st, val;\n    std::vector<T> bit;\n \
    \   void init(int sz_) {\n        sz = sz_;\n        sz++;\n        cnt.assign(sz,\
    \ 0);\n        st.assign(sz, 0);\n        assert(!mode); mode = 1;\n        std::vector<int>\
    \ lst(sz, 0);\n        cnt.assign(sz, 0);\n        sort(todo.begin(), todo.end(),\
    \ [](const std::pair<int, int>& a, const std::pair<int, int>& b) { \n        \
    \    return a.second < b.second; });\n        for (auto& t : todo) \n        \
    \    for (int x = t.first; x < sz; x += x & -x)\n                if (lst[x] !=\
    \ t.second)\n                    lst[x] = t.second, cnt[x]++;\n        int sum\
    \ = 0; \n        for (int i = 0; i < sz; i++)\n            lst[i] = 0, st[i] =\
    \ (sum += cnt[i]);\n        val.resize(sum); bit.resize(sum);\n        reverse(todo.begin(),\
    \ todo.end());\n        for (auto& t : todo) \n            for (int x = t.first;\
    \ x < sz; x += x & -x)\n                if (lst[x] != t.second)\n            \
    \        lst[x] = t.second, val[--st[x]] = t.second;\n    }\n    int rank(int\
    \ y, int l, int r) {\n        return std::upper_bound(val.begin() + l, val.begin()\
    \ + r, y) - val.begin() - l;\n    }\n    void inner_update(int x, int y, T t)\
    \ {\n        for (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x]; y += y & -y)\n\
    \            bit[st[x] + y - 1] += t;\n    }\n    void update(int x, int y, T\
    \ t) {\n        x++, y++;\n        if (!mode) todo.push_back({x, y});\n      \
    \  else \n            for (; x < sz; x += x & -x)\n                inner_update(x,\
    \ y, t);\n    }\n    int inner_query(int x, int y) {\n        T res = 0;\n   \
    \     for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y)\n            res\
    \ += bit[st[x] + y - 1];\n        return res;\n    }\n    T query(int x, int y)\
    \ {\n        x++, y++;\n        assert(mode);\n        T res = 0;\n        for\
    \ (; x; x -= x & -x) \n            res += inner_query(x, y);\n        return res;\n\
    \    }\n    T query(int xl, int xr, int yl, int yr) {\n        return query(xr,\
    \ yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);\n    }\n\
    };\n\nint main() {\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * x \\in [0, sz)\n * y \\in [0, sz)\n *\
    \ First do all the updates, then call init\n * Afterwards, do the updates again,\
    \ and now you can mix in the queries too\n */\n\ntemplate<class T> struct Offline2DBIT\
    \ { \n    bool mode = 0; // mode = 1 -> initialized\n    int sz;\n    std::vector<std::pair<int,\
    \ int>> todo;\n    std::vector<int> cnt, st, val;\n    std::vector<T> bit;\n \
    \   void init(int sz_) {\n        sz = sz_;\n        sz++;\n        cnt.assign(sz,\
    \ 0);\n        st.assign(sz, 0);\n        assert(!mode); mode = 1;\n        std::vector<int>\
    \ lst(sz, 0);\n        cnt.assign(sz, 0);\n        sort(todo.begin(), todo.end(),\
    \ [](const std::pair<int, int>& a, const std::pair<int, int>& b) { \n        \
    \    return a.second < b.second; });\n        for (auto& t : todo) \n        \
    \    for (int x = t.first; x < sz; x += x & -x)\n                if (lst[x] !=\
    \ t.second)\n                    lst[x] = t.second, cnt[x]++;\n        int sum\
    \ = 0; \n        for (int i = 0; i < sz; i++)\n            lst[i] = 0, st[i] =\
    \ (sum += cnt[i]);\n        val.resize(sum); bit.resize(sum);\n        reverse(todo.begin(),\
    \ todo.end());\n        for (auto& t : todo) \n            for (int x = t.first;\
    \ x < sz; x += x & -x)\n                if (lst[x] != t.second)\n            \
    \        lst[x] = t.second, val[--st[x]] = t.second;\n    }\n    int rank(int\
    \ y, int l, int r) {\n        return std::upper_bound(val.begin() + l, val.begin()\
    \ + r, y) - val.begin() - l;\n    }\n    void inner_update(int x, int y, T t)\
    \ {\n        for (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x]; y += y & -y)\n\
    \            bit[st[x] + y - 1] += t;\n    }\n    void update(int x, int y, T\
    \ t) {\n        x++, y++;\n        if (!mode) todo.push_back({x, y});\n      \
    \  else \n            for (; x < sz; x += x & -x)\n                inner_update(x,\
    \ y, t);\n    }\n    int inner_query(int x, int y) {\n        T res = 0;\n   \
    \     for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y)\n            res\
    \ += bit[st[x] + y - 1];\n        return res;\n    }\n    T query(int x, int y)\
    \ {\n        x++, y++;\n        assert(mode);\n        T res = 0;\n        for\
    \ (; x; x -= x & -x) \n            res += inner_query(x, y);\n        return res;\n\
    \    }\n    T query(int xl, int xr, int yl, int yr) {\n        return query(xr,\
    \ yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);\n    }\n\
    };\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/offline_2d_bit.cpp
  requiredBy: []
  timestamp: '2021-01-03 22:42:47-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/offline_2d_bit.cpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/offline_2d_bit.cpp
- /library/library/data-structures/2d-range-queries/offline_2d_bit.cpp.html
title: library/data-structures/2d-range-queries/offline_2d_bit.cpp
---
