---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\data-structures\\\\1d-range-queries\\\\interval_union.cpp\"\
    \n#include<bits/stdc++.h>\r\nconst long long INF = 1e18;\r\nstruct IntervalUnion\
    \ {\r\n    std::set<std::pair<long long, long long>> le, ri;\r\n    void reset(){\r\
    \n        le.clear();\r\n        ri.clear();\r\n    }\r\n    std::vector<std::pair<long\
    \ long, long long>> insert(std::pair<long long, long long> x){\r\n        // inserts\
    \ an interval while returning the intervals it intersected with\r\n        std::set<std::pair<long\
    \ long, long long>> bad;\r\n        std::vector<std::pair<long long, long long>>\
    \ ret;\r\n        std::pair<long long, long long> use1 = std::make_pair(x.first,\
    \ -INF), use2 = std::make_pair(x.second, INF);\r\n        auto it1 = le.lower_bound(use1);\r\
    \n        auto it2 = ri.lower_bound(use2);\r\n        if(it2 != ri.end()){\r\n\
    \            long long lo = (*it2).second, hi = (*it2).first;\r\n            if(lo\
    \ <= x.first && x.second <= hi){\r\n                ret.emplace_back(std::make_pair(lo,\
    \ hi));\r\n                long long mn = x.first, mx = x.second;\r\n        \
    \        for(auto b: ret){\r\n                    le.erase(b); ri.erase(std::make_pair(b.second,\
    \ b.first));\r\n                    mn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\r\n                }\r\n                le.insert(std::make_pair(mn,\
    \ mx)); ri.insert(std::make_pair(mx, mn));\r\n                return ret;\r\n\
    \            }\r\n        }\r\n        if(it1 != le.end()){\r\n            while(it1\
    \ != le.end()){\r\n                auto val = (*it1);\r\n                if(val.first\
    \ <= x.second) bad.insert(val);\r\n                else break;\r\n           \
    \     it1 = next(it1);\r\n            }\r\n        }\r\n        if(it2 != ri.begin()){\r\
    \n            it2 = prev(it2);\r\n            while(true){\r\n               \
    \ auto val = (*it2);\r\n                if(val.first >= x.first) bad.insert(std::make_pair(val.second,\
    \ val.first));\r\n                else break;\r\n                if(it2 == ri.begin())\
    \ break;\r\n                it2 = prev(it2);\r\n            }\r\n        }\r\n\
    \        for(auto b: bad) ret.emplace_back(b);\r\n        long long mn = x.first,\
    \ mx = x.second;\r\n        for(auto b: ret){\r\n            le.erase(b); ri.erase(std::make_pair(b.second,\
    \ b.first));\r\n            mn = std::min(mn, b.first); mx = std::max(mx, b.second);\r\
    \n        }\r\n        le.insert(std::make_pair(mn, mx)); ri.insert(std::make_pair(mx,\
    \ mn));\r\n        return ret;\r\n    }\r\n};\r\nint main(){\r\n    return 0;\r\
    \n}\r\n"
  code: "#include<bits/stdc++.h>\r\nconst long long INF = 1e18;\r\nstruct IntervalUnion\
    \ {\r\n    std::set<std::pair<long long, long long>> le, ri;\r\n    void reset(){\r\
    \n        le.clear();\r\n        ri.clear();\r\n    }\r\n    std::vector<std::pair<long\
    \ long, long long>> insert(std::pair<long long, long long> x){\r\n        // inserts\
    \ an interval while returning the intervals it intersected with\r\n        std::set<std::pair<long\
    \ long, long long>> bad;\r\n        std::vector<std::pair<long long, long long>>\
    \ ret;\r\n        std::pair<long long, long long> use1 = std::make_pair(x.first,\
    \ -INF), use2 = std::make_pair(x.second, INF);\r\n        auto it1 = le.lower_bound(use1);\r\
    \n        auto it2 = ri.lower_bound(use2);\r\n        if(it2 != ri.end()){\r\n\
    \            long long lo = (*it2).second, hi = (*it2).first;\r\n            if(lo\
    \ <= x.first && x.second <= hi){\r\n                ret.emplace_back(std::make_pair(lo,\
    \ hi));\r\n                long long mn = x.first, mx = x.second;\r\n        \
    \        for(auto b: ret){\r\n                    le.erase(b); ri.erase(std::make_pair(b.second,\
    \ b.first));\r\n                    mn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\r\n                }\r\n                le.insert(std::make_pair(mn,\
    \ mx)); ri.insert(std::make_pair(mx, mn));\r\n                return ret;\r\n\
    \            }\r\n        }\r\n        if(it1 != le.end()){\r\n            while(it1\
    \ != le.end()){\r\n                auto val = (*it1);\r\n                if(val.first\
    \ <= x.second) bad.insert(val);\r\n                else break;\r\n           \
    \     it1 = next(it1);\r\n            }\r\n        }\r\n        if(it2 != ri.begin()){\r\
    \n            it2 = prev(it2);\r\n            while(true){\r\n               \
    \ auto val = (*it2);\r\n                if(val.first >= x.first) bad.insert(std::make_pair(val.second,\
    \ val.first));\r\n                else break;\r\n                if(it2 == ri.begin())\
    \ break;\r\n                it2 = prev(it2);\r\n            }\r\n        }\r\n\
    \        for(auto b: bad) ret.emplace_back(b);\r\n        long long mn = x.first,\
    \ mx = x.second;\r\n        for(auto b: ret){\r\n            le.erase(b); ri.erase(std::make_pair(b.second,\
    \ b.first));\r\n            mn = std::min(mn, b.first); mx = std::max(mx, b.second);\r\
    \n        }\r\n        le.insert(std::make_pair(mn, mx)); ri.insert(std::make_pair(mx,\
    \ mn));\r\n        return ret;\r\n    }\r\n};\r\nint main(){\r\n    return 0;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\data-structures\1d-range-queries\interval_union.cpp
  requiredBy: []
  timestamp: '2020-11-24 21:03:23-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\data-structures\1d-range-queries\interval_union.cpp
layout: document
redirect_from:
- /library\library\data-structures\1d-range-queries\interval_union.cpp
- /library\library\data-structures\1d-range-queries\interval_union.cpp.html
title: library\data-structures\1d-range-queries\interval_union.cpp
---
