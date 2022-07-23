---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-981G.test.cpp
    title: verify/codeforces/codeforces-981G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct IntervalUnion {\r\n\tconst T INF = std::numeric_limits<T>::max();\r\
    \n\tstd::set<std::pair<T, T>> le, ri;\r\n\r\n\tvoid reset() {\r\n\t\tle.clear();\r\
    \n\t\tri.clear();\r\n\t}\r\n\r\n\t// inserts an interval while returning the intervals\
    \ it intersected with\r\n\tstd::vector<std::pair<T, T>> insert(std::pair<T, T>\
    \ x) {\r\n\t\tstd::set<std::pair<T, T>> bad;\r\n\t\tstd::vector<std::pair<T, T>>\
    \ ret;\r\n\t\tstd::pair<T, T> use1 = {x.first, -INF}, use2 = {x.second, INF};\r\
    \n\t\tauto it1 = le.lower_bound(use1);\r\n\t\tauto it2 = ri.lower_bound(use2);\r\
    \n\t\tif (it2 != ri.end()) {\r\n\t\t\tT lo = it2->second, hi = it2->first;\r\n\
    \t\t\tif (lo <= x.first && x.second <= hi) {\r\n\t\t\t\tret.emplace_back(lo, hi);\r\
    \n\t\t\t\tT mn = x.first, mx = x.second;\r\n\t\t\t\tfor (auto& b : ret) {\r\n\t\
    \t\t\t\tle.erase(b); ri.erase({b.second, b.first});\r\n\t\t\t\t\tmn = std::min(mn,\
    \ b.first); mx = std::max(mx, b.second);\r\n\t\t\t\t}\r\n\t\t\t\tle.emplace(mn,\
    \ mx); ri.emplace(mx, mn);\r\n\t\t\t\treturn ret;\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    if (it1 != le.end()) {\r\n\t\t\twhile (it1 != le.end()) {\r\n\t\t\t\tauto val\
    \ = (*it1);\r\n\t\t\t\tif (val.first <= x.second) bad.insert(val);\r\n\t\t\t\t\
    else break;\r\n\t\t\t\tit1 = next(it1);\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (it2 !=\
    \ ri.begin()) {\r\n\t\t\tit2 = prev(it2);\r\n\t\t\twhile (true) {\r\n\t\t\t\t\
    auto val = *it2;\r\n\t\t\t\tif (val.first >= x.first) bad.emplace(val.second,\
    \ val.first);\r\n\t\t\t\telse break;\r\n\t\t\t\tif (it2 == ri.begin()) break;\r\
    \n\t\t\t\tit2 = prev(it2);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (auto& b : bad) ret.emplace_back(b);\r\
    \n\t\tT mn = x.first, mx = x.second;\r\n\t\tfor (auto& b : ret) {\r\n\t\t\tle.erase(b);\
    \ ri.erase({b.second, b.first});\r\n\t\t\tmn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\r\n\t\t}\r\n\t\tle.emplace(mn, mx); ri.emplace(mx, mn);\r\n\t\treturn\
    \ ret;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct IntervalUnion {\r\n\tconst\
    \ T INF = std::numeric_limits<T>::max();\r\n\tstd::set<std::pair<T, T>> le, ri;\r\
    \n\r\n\tvoid reset() {\r\n\t\tle.clear();\r\n\t\tri.clear();\r\n\t}\r\n\r\n\t\
    // inserts an interval while returning the intervals it intersected with\r\n\t\
    std::vector<std::pair<T, T>> insert(std::pair<T, T> x) {\r\n\t\tstd::set<std::pair<T,\
    \ T>> bad;\r\n\t\tstd::vector<std::pair<T, T>> ret;\r\n\t\tstd::pair<T, T> use1\
    \ = {x.first, -INF}, use2 = {x.second, INF};\r\n\t\tauto it1 = le.lower_bound(use1);\r\
    \n\t\tauto it2 = ri.lower_bound(use2);\r\n\t\tif (it2 != ri.end()) {\r\n\t\t\t\
    T lo = it2->second, hi = it2->first;\r\n\t\t\tif (lo <= x.first && x.second <=\
    \ hi) {\r\n\t\t\t\tret.emplace_back(lo, hi);\r\n\t\t\t\tT mn = x.first, mx = x.second;\r\
    \n\t\t\t\tfor (auto& b : ret) {\r\n\t\t\t\t\tle.erase(b); ri.erase({b.second,\
    \ b.first});\r\n\t\t\t\t\tmn = std::min(mn, b.first); mx = std::max(mx, b.second);\r\
    \n\t\t\t\t}\r\n\t\t\t\tle.emplace(mn, mx); ri.emplace(mx, mn);\r\n\t\t\t\treturn\
    \ ret;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (it1 != le.end()) {\r\n\t\t\twhile (it1 !=\
    \ le.end()) {\r\n\t\t\t\tauto val = (*it1);\r\n\t\t\t\tif (val.first <= x.second)\
    \ bad.insert(val);\r\n\t\t\t\telse break;\r\n\t\t\t\tit1 = next(it1);\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\tif (it2 != ri.begin()) {\r\n\t\t\tit2 = prev(it2);\r\n\t\t\t\
    while (true) {\r\n\t\t\t\tauto val = *it2;\r\n\t\t\t\tif (val.first >= x.first)\
    \ bad.emplace(val.second, val.first);\r\n\t\t\t\telse break;\r\n\t\t\t\tif (it2\
    \ == ri.begin()) break;\r\n\t\t\t\tit2 = prev(it2);\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    for (auto& b : bad) ret.emplace_back(b);\r\n\t\tT mn = x.first, mx = x.second;\r\
    \n\t\tfor (auto& b : ret) {\r\n\t\t\tle.erase(b); ri.erase({b.second, b.first});\r\
    \n\t\t\tmn = std::min(mn, b.first); mx = std::max(mx, b.second);\r\n\t\t}\r\n\t\
    \tle.emplace(mn, mx); ri.emplace(mx, mn);\r\n\t\treturn ret;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/interval-union.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-981G.test.cpp
documentation_of: library/data-structures/1d-range-queries/interval-union.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/interval-union.hpp
- /library/library/data-structures/1d-range-queries/interval-union.hpp.html
title: library/data-structures/1d-range-queries/interval-union.hpp
---
