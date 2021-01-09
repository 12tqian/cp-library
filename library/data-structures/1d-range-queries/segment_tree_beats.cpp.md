---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/segment_tree_beats.cpp\"\
    \n#include <bits/stdc++.h>\n\ntemplate <class C> struct SegmentTreeBeats {\n \
    \   using T = std::pair<std::pair<C, C>, int>;\n    const C INF = std::numeric_limits<C>::max();\n\
    \    std::vector<C> mx_mod, mn_mod, mod, sum;\n    std::vector<T> mx, mn;\n  \
    \  int sz; \n\n    void init(int sz_) {\n        sz = 1; \n        while (sz <\
    \ sz_) sz *= 2;\n        mx_mod.resize(2 * sz);\n        mn_mod.resize(2 * sz);\n\
    \        mod.resize(2 * sz);\n        sum.resize(2 * sz);\n        mx.resize(2\
    \ * sz);\n        mn.resize(2 * sz);\n        build();\n    }\n\n    void build(int\
    \ ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        mx_mod[ind]\
    \ = INF, mn_mod[ind] = -INF, mod[ind] = 0;\n        if (L == R) {\n          \
    \  mx[ind] = {{0, -INF}, 1};\n            mn[ind] = {{0, INF}, 1};\n         \
    \   sum[ind] = 0;\n            return;\n        }\n        int M = (L + R) / 2;\n\
    \        build(2 * ind, L, M); build(2 * ind + 1, M + 1, R);\n        pull(ind);\n\
    \    }\n\n    T comb_mn(T a, T b) {\n        if (a > b) \n            std::swap(a,\
    \ b);\n        if (a.first.first == b.first.first) \n            return  {{a.first.first,\
    \ \n                std::min(a.first.second, b.first.second)}, \n            \
    \    a.second + b.second};\n        return {{a.first.first, std::min(a.first.second,\
    \ b.first.first)}, a.second};\n    }\n\n    T comb_mx(T a, T b) {\n        if\
    \ (a < b) std::swap(a, b);\n        if (a.first.first == b.first.first) \n   \
    \         return  {{a.first.first, \n                std::max(a.first.second,\
    \ b.first.second)}, \n                a.second + b.second};\n        return {{a.first.first,\
    \ std::max(a.first.second, b.first.first)}, \n            a.second};\n    }\n\n\
    \    void pull(int ind) {\n        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n\
    \        mn[ind] = comb_mn(mn[2 * ind], mn[2 * ind + 1]);\n        mx[ind] = comb_mx(mx[2\
    \ * ind], mx[2 * ind + 1]);\n    }\n\n    void push(int ind, int L, int R) {\n\
    \        auto chk = [](C& a, C b, C c) {\n            if (a == b)\n          \
    \      a = c;\n        };\n        if (mn_mod[ind] != -INF) {\n            if\
    \ (mn_mod[ind] > mn[ind].first.first) {\n                sum[ind] += (mn_mod[ind]\
    \ - mn[ind].first.first) * mn[ind].second;\n                chk(mx[ind].first.first,\
    \ mn[ind].first.first, mn_mod[ind]);\n                chk(mx[ind].first.second,\
    \ mn[ind].first.first, mn_mod[ind]);\n                mn[ind].first.first = mn_mod[ind];\n\
    \                if (L != R) {\n                    for (int i = 0; i < 2; i++)\
    \ {\n                        int pos = 2 * ind + i;\n                        mn_mod[pos]\
    \ = std::max(mn_mod[pos], mn_mod[ind] - mod[pos]);\n                        mx_mod[pos]\
    \ = std::max(mx_mod[pos], mn_mod[pos]);\n                    }\n             \
    \   }\n            }\n            mn_mod[ind] = -INF;\n        }\n        if (mx_mod[ind]\
    \ != INF) {\n            if (mx_mod[ind] < mx[ind].first.first) {\n          \
    \      sum[ind] += (mx_mod[ind] - mx[ind].first.first) * mx[ind].second;\n   \
    \             chk(mn[ind].first.first, mx[ind].first.first, mx_mod[ind]);\n  \
    \              chk(mn[ind].first.second, mx[ind].first.first, mx_mod[ind]);\n\
    \                mx[ind].first.first = mx_mod[ind];\n                if (L !=\
    \ R) {\n                    for (int i = 0; i < 2; i++) {\n                  \
    \      int pos = 2 * ind + i;\n                        mx_mod[pos] = std::min(mx_mod[pos],\
    \ mx_mod[ind] - mod[pos]);\n                        mn_mod[pos] = std::min(mn_mod[pos],\
    \ mx_mod[pos]);\n                    }\n                }\n            }\n   \
    \         mx_mod[ind] = INF;\n        }\n        if (mod[ind] != 0) {\n      \
    \      sum[ind] += mod[ind] * (R - L + 1);\n            auto inc = [&](T& a, C\
    \ b) {\n                if (std::abs(a.first.first) != INF) \n               \
    \     a.first.first += b;\n                if (std::abs(a.first.second) != INF)\n\
    \                    a.first.second += b;\n            };\n            inc(mx[ind],\
    \ mod[ind]); inc(mn[ind], mod[ind]);\n            if (L != R) {\n            \
    \    for (int i = 0; i < 2; i++) {\n                    int pos = 2 * ind + i;\n\
    \                    mod[pos] += mod[ind];\n                }\n            }\n\
    \            mod[ind] = 0;\n        }\n    }\n\n    C qsum(int lo, int hi, int\
    \ ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        push(ind,\
    \ L, R);\n        if (R < lo || hi < L)\n            return 0;\n        if (lo\
    \ <= L && R <= hi)     \n            return sum[ind];\n        int M = (L + R)\
    \ / 2;\n        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1,\
    \ M + 1, R);\n    }\n\n    C qmax(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\n        if (R == -1) R += sz;\n        push(ind, L, R);\n       \
    \ if (R < lo || hi < L)\n            return -INF;\n        if (lo <= L && R <=\
    \ hi)     \n            return mx[ind].first.first;\n        int M = (L + R) /\
    \ 2;\n        return std::max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind\
    \ + 1, M + 1, R));\n    }\n\n    C qmin(int lo, int hi, int ind = 1, int L = 0,\
    \ int R = -1) {\n        if (R == -1) R += sz;\n        push(ind, L, R);\n   \
    \     if (R < lo || hi < L)\n            return INF;\n        if (lo <= L && R\
    \ <= hi)     \n            return mn[ind].first.first;\n        int M = (L + R)\
    \ / 2;\n        return std::min(qmin(lo, hi, 2 * ind, L, M), qmin(lo, hi, 2 *\
    \ ind + 1, M + 1, R));\n    }\n    \n    void upd(int t, int lo, int hi, C b,\
    \ int ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n     \
    \   push(ind, L, R);\n        if (R < lo || hi < L) \n            return;\n  \
    \      if (t == 0) \n            if (b >= mx[ind].first.first)\n             \
    \   return;\n        else if (t == 1)\n            if (b <= mn[ind].first.first)\n\
    \                return;\n        if (lo <= L && R <= hi) {\n            if (t\
    \ == 0) {\n                if (b  > mx[ind].first.second) {\n                \
    \    mx_mod[ind] = b;\n                    push(ind, L, R);\n                \
    \    return;\n                }\n            } else if (t == 1) {\n          \
    \      if (b < mn[ind].first.second) {\n                    mn_mod[ind] = b;\n\
    \                    push(ind, L, R);\n                    return;\n         \
    \       }\n            } else if (t == 2) {\n                mod[ind] = b;\n \
    \               push(ind, L, R);\n                return;\n            } else\
    \ assert(false);\n        }\n        assert(L != R);\n        int M = (L + R)\
    \ / 2;\n        upd(t, lo, hi, b, 2 * ind, L, M); upd(t, lo, hi, b, 2 * ind +\
    \ 1, M + 1, R);\n        pull(ind);\n    }\n};\n\nint main() {\n    using namespace\
    \ std;\n    ios_base::sync_with_stdio(0);\n    int n, q; cin >> n >> q;\n    SegmentTreeBeats<long\
    \ long> S;\n    S.init(n);\n    std::vector<long long> a(n);\n    for (int i =\
    \ 0; i < n; i++)\n        cin >> a[i], S.upd(2, i, i, a[i]);\n    while (q--)\
    \ {\n        int t, l, r; cin >> t >> l >> r;\n        r--;\n        if (t <=\
    \ 2) {\n            long long b; cin >> b;\n            S.upd(t, l, r, b);\n \
    \       } else {\n            cout << S.qsum(l, r) << '\\n';\n        }\n    }\n\
    }\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class C> struct SegmentTreeBeats {\n\
    \    using T = std::pair<std::pair<C, C>, int>;\n    const C INF = std::numeric_limits<C>::max();\n\
    \    std::vector<C> mx_mod, mn_mod, mod, sum;\n    std::vector<T> mx, mn;\n  \
    \  int sz; \n\n    void init(int sz_) {\n        sz = 1; \n        while (sz <\
    \ sz_) sz *= 2;\n        mx_mod.resize(2 * sz);\n        mn_mod.resize(2 * sz);\n\
    \        mod.resize(2 * sz);\n        sum.resize(2 * sz);\n        mx.resize(2\
    \ * sz);\n        mn.resize(2 * sz);\n        build();\n    }\n\n    void build(int\
    \ ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        mx_mod[ind]\
    \ = INF, mn_mod[ind] = -INF, mod[ind] = 0;\n        if (L == R) {\n          \
    \  mx[ind] = {{0, -INF}, 1};\n            mn[ind] = {{0, INF}, 1};\n         \
    \   sum[ind] = 0;\n            return;\n        }\n        int M = (L + R) / 2;\n\
    \        build(2 * ind, L, M); build(2 * ind + 1, M + 1, R);\n        pull(ind);\n\
    \    }\n\n    T comb_mn(T a, T b) {\n        if (a > b) \n            std::swap(a,\
    \ b);\n        if (a.first.first == b.first.first) \n            return  {{a.first.first,\
    \ \n                std::min(a.first.second, b.first.second)}, \n            \
    \    a.second + b.second};\n        return {{a.first.first, std::min(a.first.second,\
    \ b.first.first)}, a.second};\n    }\n\n    T comb_mx(T a, T b) {\n        if\
    \ (a < b) std::swap(a, b);\n        if (a.first.first == b.first.first) \n   \
    \         return  {{a.first.first, \n                std::max(a.first.second,\
    \ b.first.second)}, \n                a.second + b.second};\n        return {{a.first.first,\
    \ std::max(a.first.second, b.first.first)}, \n            a.second};\n    }\n\n\
    \    void pull(int ind) {\n        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n\
    \        mn[ind] = comb_mn(mn[2 * ind], mn[2 * ind + 1]);\n        mx[ind] = comb_mx(mx[2\
    \ * ind], mx[2 * ind + 1]);\n    }\n\n    void push(int ind, int L, int R) {\n\
    \        auto chk = [](C& a, C b, C c) {\n            if (a == b)\n          \
    \      a = c;\n        };\n        if (mn_mod[ind] != -INF) {\n            if\
    \ (mn_mod[ind] > mn[ind].first.first) {\n                sum[ind] += (mn_mod[ind]\
    \ - mn[ind].first.first) * mn[ind].second;\n                chk(mx[ind].first.first,\
    \ mn[ind].first.first, mn_mod[ind]);\n                chk(mx[ind].first.second,\
    \ mn[ind].first.first, mn_mod[ind]);\n                mn[ind].first.first = mn_mod[ind];\n\
    \                if (L != R) {\n                    for (int i = 0; i < 2; i++)\
    \ {\n                        int pos = 2 * ind + i;\n                        mn_mod[pos]\
    \ = std::max(mn_mod[pos], mn_mod[ind] - mod[pos]);\n                        mx_mod[pos]\
    \ = std::max(mx_mod[pos], mn_mod[pos]);\n                    }\n             \
    \   }\n            }\n            mn_mod[ind] = -INF;\n        }\n        if (mx_mod[ind]\
    \ != INF) {\n            if (mx_mod[ind] < mx[ind].first.first) {\n          \
    \      sum[ind] += (mx_mod[ind] - mx[ind].first.first) * mx[ind].second;\n   \
    \             chk(mn[ind].first.first, mx[ind].first.first, mx_mod[ind]);\n  \
    \              chk(mn[ind].first.second, mx[ind].first.first, mx_mod[ind]);\n\
    \                mx[ind].first.first = mx_mod[ind];\n                if (L !=\
    \ R) {\n                    for (int i = 0; i < 2; i++) {\n                  \
    \      int pos = 2 * ind + i;\n                        mx_mod[pos] = std::min(mx_mod[pos],\
    \ mx_mod[ind] - mod[pos]);\n                        mn_mod[pos] = std::min(mn_mod[pos],\
    \ mx_mod[pos]);\n                    }\n                }\n            }\n   \
    \         mx_mod[ind] = INF;\n        }\n        if (mod[ind] != 0) {\n      \
    \      sum[ind] += mod[ind] * (R - L + 1);\n            auto inc = [&](T& a, C\
    \ b) {\n                if (std::abs(a.first.first) != INF) \n               \
    \     a.first.first += b;\n                if (std::abs(a.first.second) != INF)\n\
    \                    a.first.second += b;\n            };\n            inc(mx[ind],\
    \ mod[ind]); inc(mn[ind], mod[ind]);\n            if (L != R) {\n            \
    \    for (int i = 0; i < 2; i++) {\n                    int pos = 2 * ind + i;\n\
    \                    mod[pos] += mod[ind];\n                }\n            }\n\
    \            mod[ind] = 0;\n        }\n    }\n\n    C qsum(int lo, int hi, int\
    \ ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        push(ind,\
    \ L, R);\n        if (R < lo || hi < L)\n            return 0;\n        if (lo\
    \ <= L && R <= hi)     \n            return sum[ind];\n        int M = (L + R)\
    \ / 2;\n        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1,\
    \ M + 1, R);\n    }\n\n    C qmax(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\n        if (R == -1) R += sz;\n        push(ind, L, R);\n       \
    \ if (R < lo || hi < L)\n            return -INF;\n        if (lo <= L && R <=\
    \ hi)     \n            return mx[ind].first.first;\n        int M = (L + R) /\
    \ 2;\n        return std::max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind\
    \ + 1, M + 1, R));\n    }\n\n    C qmin(int lo, int hi, int ind = 1, int L = 0,\
    \ int R = -1) {\n        if (R == -1) R += sz;\n        push(ind, L, R);\n   \
    \     if (R < lo || hi < L)\n            return INF;\n        if (lo <= L && R\
    \ <= hi)     \n            return mn[ind].first.first;\n        int M = (L + R)\
    \ / 2;\n        return std::min(qmin(lo, hi, 2 * ind, L, M), qmin(lo, hi, 2 *\
    \ ind + 1, M + 1, R));\n    }\n    \n    void upd(int t, int lo, int hi, C b,\
    \ int ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n     \
    \   push(ind, L, R);\n        if (R < lo || hi < L) \n            return;\n  \
    \      if (t == 0) \n            if (b >= mx[ind].first.first)\n             \
    \   return;\n        else if (t == 1)\n            if (b <= mn[ind].first.first)\n\
    \                return;\n        if (lo <= L && R <= hi) {\n            if (t\
    \ == 0) {\n                if (b  > mx[ind].first.second) {\n                \
    \    mx_mod[ind] = b;\n                    push(ind, L, R);\n                \
    \    return;\n                }\n            } else if (t == 1) {\n          \
    \      if (b < mn[ind].first.second) {\n                    mn_mod[ind] = b;\n\
    \                    push(ind, L, R);\n                    return;\n         \
    \       }\n            } else if (t == 2) {\n                mod[ind] = b;\n \
    \               push(ind, L, R);\n                return;\n            } else\
    \ assert(false);\n        }\n        assert(L != R);\n        int M = (L + R)\
    \ / 2;\n        upd(t, lo, hi, b, 2 * ind, L, M); upd(t, lo, hi, b, 2 * ind +\
    \ 1, M + 1, R);\n        pull(ind);\n    }\n};\n\nint main() {\n    using namespace\
    \ std;\n    ios_base::sync_with_stdio(0);\n    int n, q; cin >> n >> q;\n    SegmentTreeBeats<long\
    \ long> S;\n    S.init(n);\n    std::vector<long long> a(n);\n    for (int i =\
    \ 0; i < n; i++)\n        cin >> a[i], S.upd(2, i, i, a[i]);\n    while (q--)\
    \ {\n        int t, l, r; cin >> t >> l >> r;\n        r--;\n        if (t <=\
    \ 2) {\n            long long b; cin >> b;\n            S.upd(t, l, r, b);\n \
    \       } else {\n            cout << S.qsum(l, r) << '\\n';\n        }\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/segment_tree_beats.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/segment_tree_beats.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/segment_tree_beats.cpp
- /library/library/data-structures/1d-range-queries/segment_tree_beats.cpp.html
title: library/data-structures/1d-range-queries/segment_tree_beats.cpp
---
