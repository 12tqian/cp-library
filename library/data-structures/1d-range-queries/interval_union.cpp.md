---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/interval_union.cpp\"\
    \n#include<bits/stdc++.h>\n\ntemplate <class T> struct IntervalUnion {\n    const\
    \ T INF = std::numeric_limits<T>::max();\n    std::set<std::pair<T, T>> le, ri;\n\
    \n    void reset() {\n        le.clear();\n        ri.clear();\n    }\n\n    //\
    \ inserts an interval while returning the intervals it intersected with\n    std::vector<std::pair<T,\
    \ T>> insert(std::pair<T, T> x) {\n        std::set<std::pair<T, T>> bad;\n  \
    \      std::vector<std::pair<T, T>> ret;\n        std::pair<T, T> use1 = {x.first,\
    \ -INF}, use2 = {x.second, INF};\n        auto it1 = le.lower_bound(use1);\n \
    \       auto it2 = ri.lower_bound(use2);\n        if (it2 != ri.end()) {\n   \
    \         T lo = (*it2).second, hi = (*it2).first;\n            if (lo <= x.first\
    \ && x.second <= hi) {\n                ret.emplace_back(lo, hi);\n          \
    \      T mn = x.first, mx = x.second;\n                for (auto& b : ret) {\n\
    \                    le.erase(b); ri.erase({b.second, b.first});\n           \
    \         mn = std::min(mn, b.first); mx = std::max(mx, b.second);\n         \
    \       }\n                le.emplace(mn, mx); ri.emplace(mx, mn);\n         \
    \       return ret;\n            }\n        }\n        if (it1 != le.end()) {\n\
    \            while (it1 != le.end()) {\n                auto val = (*it1);\n \
    \               if (val.first <= x.second) bad.insert(val);\n                else\
    \ break;\n                it1 = next(it1);\n            }\n        }\n       \
    \ if (it2 != ri.begin()) {\n            it2 = prev(it2);\n            while (true)\
    \ {\n                auto val = (*it2);\n                if (val.first >= x.first)\
    \ bad.emplace(val.second, val.first);\n                else break;\n         \
    \       if (it2 == ri.begin()) break;\n                it2 = prev(it2);\n    \
    \        }\n        }\n        for (auto& b : bad) ret.emplace_back(b);\n    \
    \    T mn = x.first, mx = x.second;\n        for (auto& b : ret) {\n         \
    \   le.erase(b); ri.erase({b.second, b.first});\n            mn = std::min(mn,\
    \ b.first); mx = std::max(mx, b.second);\n        }\n        le.emplace(mn, mx);\
    \ ri.emplace(mx, mn);\n        return ret;\n    }\n};\n\nint main() {\n    return\
    \ 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <class T> struct IntervalUnion {\n  \
    \  const T INF = std::numeric_limits<T>::max();\n    std::set<std::pair<T, T>>\
    \ le, ri;\n\n    void reset() {\n        le.clear();\n        ri.clear();\n  \
    \  }\n\n    // inserts an interval while returning the intervals it intersected\
    \ with\n    std::vector<std::pair<T, T>> insert(std::pair<T, T> x) {\n       \
    \ std::set<std::pair<T, T>> bad;\n        std::vector<std::pair<T, T>> ret;\n\
    \        std::pair<T, T> use1 = {x.first, -INF}, use2 = {x.second, INF};\n   \
    \     auto it1 = le.lower_bound(use1);\n        auto it2 = ri.lower_bound(use2);\n\
    \        if (it2 != ri.end()) {\n            T lo = (*it2).second, hi = (*it2).first;\n\
    \            if (lo <= x.first && x.second <= hi) {\n                ret.emplace_back(lo,\
    \ hi);\n                T mn = x.first, mx = x.second;\n                for (auto&\
    \ b : ret) {\n                    le.erase(b); ri.erase({b.second, b.first});\n\
    \                    mn = std::min(mn, b.first); mx = std::max(mx, b.second);\n\
    \                }\n                le.emplace(mn, mx); ri.emplace(mx, mn);\n\
    \                return ret;\n            }\n        }\n        if (it1 != le.end())\
    \ {\n            while (it1 != le.end()) {\n                auto val = (*it1);\n\
    \                if (val.first <= x.second) bad.insert(val);\n               \
    \ else break;\n                it1 = next(it1);\n            }\n        }\n  \
    \      if (it2 != ri.begin()) {\n            it2 = prev(it2);\n            while\
    \ (true) {\n                auto val = (*it2);\n                if (val.first\
    \ >= x.first) bad.emplace(val.second, val.first);\n                else break;\n\
    \                if (it2 == ri.begin()) break;\n                it2 = prev(it2);\n\
    \            }\n        }\n        for (auto& b : bad) ret.emplace_back(b);\n\
    \        T mn = x.first, mx = x.second;\n        for (auto& b : ret) {\n     \
    \       le.erase(b); ri.erase({b.second, b.first});\n            mn = std::min(mn,\
    \ b.first); mx = std::max(mx, b.second);\n        }\n        le.emplace(mn, mx);\
    \ ri.emplace(mx, mn);\n        return ret;\n    }\n};\n\nint main() {\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/interval_union.cpp
  requiredBy: []
  timestamp: '2021-05-09 23:47:22-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/interval_union.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/interval_union.cpp
- /library/library/data-structures/1d-range-queries/interval_union.cpp.html
title: library/data-structures/1d-range-queries/interval_union.cpp
---
