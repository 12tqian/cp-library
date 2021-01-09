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
    \n#include<bits/stdc++.h>\n\nconst long long INF = 1e18;\n\nstruct IntervalUnion\
    \ {\n    std::set<std::pair<long long, long long>> le, ri;\n\n    void reset()\
    \ {\n        le.clear();\n        ri.clear();\n    }\n\n    std::vector<std::pair<long\
    \ long, long long>> insert(std::pair<long long, long long> x) {\n        // inserts\
    \ an interval while returning the intervals it intersected with\n        std::set<std::pair<long\
    \ long, long long>> bad;\n        std::vector<std::pair<long long, long long>>\
    \ ret;\n        std::pair<long long, long long> use1 = std::make_pair(x.first,\
    \ -INF), use2 = std::make_pair(x.second, INF);\n        auto it1 = le.lower_bound(use1);\n\
    \        auto it2 = ri.lower_bound(use2);\n        if (it2 != ri.end()) {\n  \
    \          long long lo = (*it2).second, hi = (*it2).first;\n            if (lo\
    \ <= x.first && x.second <= hi) {\n                ret.emplace_back(std::make_pair(lo,\
    \ hi));\n                long long mn = x.first, mx = x.second;\n            \
    \    for (auto b: ret) {\n                    le.erase(b); ri.erase(std::make_pair(b.second,\
    \ b.first));\n                    mn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\n                }\n                le.insert(std::make_pair(mn,\
    \ mx)); ri.insert(std::make_pair(mx, mn));\n                return ret;\n    \
    \        }\n        }\n        if (it1 != le.end()) {\n            while (it1\
    \ != le.end()) {\n                auto val = (*it1);\n                if (val.first\
    \ <= x.second) bad.insert(val);\n                else break;\n               \
    \ it1 = next(it1);\n            }\n        }\n        if (it2 != ri.begin()) {\n\
    \            it2 = prev(it2);\n            while (true) {\n                auto\
    \ val = (*it2);\n                if (val.first >= x.first) bad.insert(std::make_pair(val.second,\
    \ val.first));\n                else break;\n                if (it2 == ri.begin())\
    \ break;\n                it2 = prev(it2);\n            }\n        }\n       \
    \ for (auto b: bad) ret.emplace_back(b);\n        long long mn = x.first, mx =\
    \ x.second;\n        for (auto b: ret){\n            le.erase(b); ri.erase(std::make_pair(b.second,\
    \ b.first));\n            mn = std::min(mn, b.first); mx = std::max(mx, b.second);\n\
    \        }\n        le.insert(std::make_pair(mn, mx)); ri.insert(std::make_pair(mx,\
    \ mn));\n        return ret;\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nconst long long INF = 1e18;\n\nstruct IntervalUnion\
    \ {\n    std::set<std::pair<long long, long long>> le, ri;\n\n    void reset()\
    \ {\n        le.clear();\n        ri.clear();\n    }\n\n    std::vector<std::pair<long\
    \ long, long long>> insert(std::pair<long long, long long> x) {\n        // inserts\
    \ an interval while returning the intervals it intersected with\n        std::set<std::pair<long\
    \ long, long long>> bad;\n        std::vector<std::pair<long long, long long>>\
    \ ret;\n        std::pair<long long, long long> use1 = std::make_pair(x.first,\
    \ -INF), use2 = std::make_pair(x.second, INF);\n        auto it1 = le.lower_bound(use1);\n\
    \        auto it2 = ri.lower_bound(use2);\n        if (it2 != ri.end()) {\n  \
    \          long long lo = (*it2).second, hi = (*it2).first;\n            if (lo\
    \ <= x.first && x.second <= hi) {\n                ret.emplace_back(std::make_pair(lo,\
    \ hi));\n                long long mn = x.first, mx = x.second;\n            \
    \    for (auto b: ret) {\n                    le.erase(b); ri.erase(std::make_pair(b.second,\
    \ b.first));\n                    mn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\n                }\n                le.insert(std::make_pair(mn,\
    \ mx)); ri.insert(std::make_pair(mx, mn));\n                return ret;\n    \
    \        }\n        }\n        if (it1 != le.end()) {\n            while (it1\
    \ != le.end()) {\n                auto val = (*it1);\n                if (val.first\
    \ <= x.second) bad.insert(val);\n                else break;\n               \
    \ it1 = next(it1);\n            }\n        }\n        if (it2 != ri.begin()) {\n\
    \            it2 = prev(it2);\n            while (true) {\n                auto\
    \ val = (*it2);\n                if (val.first >= x.first) bad.insert(std::make_pair(val.second,\
    \ val.first));\n                else break;\n                if (it2 == ri.begin())\
    \ break;\n                it2 = prev(it2);\n            }\n        }\n       \
    \ for (auto b: bad) ret.emplace_back(b);\n        long long mn = x.first, mx =\
    \ x.second;\n        for (auto b: ret){\n            le.erase(b); ri.erase(std::make_pair(b.second,\
    \ b.first));\n            mn = std::min(mn, b.first); mx = std::max(mx, b.second);\n\
    \        }\n        le.insert(std::make_pair(mn, mx)); ri.insert(std::make_pair(mx,\
    \ mn));\n        return ret;\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/interval_union.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/interval_union.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/interval_union.cpp
- /library/library/data-structures/1d-range-queries/interval_union.cpp.html
title: library/data-structures/1d-range-queries/interval_union.cpp
---
