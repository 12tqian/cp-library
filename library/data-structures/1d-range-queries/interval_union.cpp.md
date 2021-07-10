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
    \n#include <bits/stdc++.h>\n\ntemplate <class T> struct IntervalUnion {\n\tconst\
    \ T INF = std::numeric_limits<T>::max();\n\tstd::set<std::pair<T, T>> le, ri;\n\
    \n\tvoid reset() {\n\t\tle.clear();\n\t\tri.clear();\n\t}\n\n\t// inserts an interval\
    \ while returning the intervals it intersected with\n\tstd::vector<std::pair<T,\
    \ T>> insert(std::pair<T, T> x) {\n\t\tstd::set<std::pair<T, T>> bad;\n\t\tstd::vector<std::pair<T,\
    \ T>> ret;\n\t\tstd::pair<T, T> use1 = {x.first, -INF}, use2 = {x.second, INF};\n\
    \t\tauto it1 = le.lower_bound(use1);\n\t\tauto it2 = ri.lower_bound(use2);\n\t\
    \tif (it2 != ri.end()) {\n\t\t\tT lo = (*it2).second, hi = (*it2).first;\n\t\t\
    \tif (lo <= x.first && x.second <= hi) {\n\t\t\t\tret.emplace_back(lo, hi);\n\t\
    \t\t\tT mn = x.first, mx = x.second;\n\t\t\t\tfor (auto& b : ret) {\n\t\t\t\t\t\
    le.erase(b); ri.erase({b.second, b.first});\n\t\t\t\t\tmn = std::min(mn, b.first);\
    \ mx = std::max(mx, b.second);\n\t\t\t\t}\n\t\t\t\tle.emplace(mn, mx); ri.emplace(mx,\
    \ mn);\n\t\t\t\treturn ret;\n\t\t\t}\n\t\t}\n\t\tif (it1 != le.end()) {\n\t\t\t\
    while (it1 != le.end()) {\n\t\t\t\tauto val = (*it1);\n\t\t\t\tif (val.first <=\
    \ x.second) bad.insert(val);\n\t\t\t\telse break;\n\t\t\t\tit1 = next(it1);\n\t\
    \t\t}\n\t\t}\n\t\tif (it2 != ri.begin()) {\n\t\t\tit2 = prev(it2);\n\t\t\twhile\
    \ (true) {\n\t\t\t\tauto val = (*it2);\n\t\t\t\tif (val.first >= x.first) bad.emplace(val.second,\
    \ val.first);\n\t\t\t\telse break;\n\t\t\t\tif (it2 == ri.begin()) break;\n\t\t\
    \t\tit2 = prev(it2);\n\t\t\t}\n\t\t}\n\t\tfor (auto& b : bad) ret.emplace_back(b);\n\
    \t\tT mn = x.first, mx = x.second;\n\t\tfor (auto& b : ret) {\n\t\t\tle.erase(b);\
    \ ri.erase({b.second, b.first});\n\t\t\tmn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\n\t\t}\n\t\tle.emplace(mn, mx); ri.emplace(mx, mn);\n\t\treturn ret;\n\
    \t}\n};\n\nint main() {\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct IntervalUnion {\n\t\
    const T INF = std::numeric_limits<T>::max();\n\tstd::set<std::pair<T, T>> le,\
    \ ri;\n\n\tvoid reset() {\n\t\tle.clear();\n\t\tri.clear();\n\t}\n\n\t// inserts\
    \ an interval while returning the intervals it intersected with\n\tstd::vector<std::pair<T,\
    \ T>> insert(std::pair<T, T> x) {\n\t\tstd::set<std::pair<T, T>> bad;\n\t\tstd::vector<std::pair<T,\
    \ T>> ret;\n\t\tstd::pair<T, T> use1 = {x.first, -INF}, use2 = {x.second, INF};\n\
    \t\tauto it1 = le.lower_bound(use1);\n\t\tauto it2 = ri.lower_bound(use2);\n\t\
    \tif (it2 != ri.end()) {\n\t\t\tT lo = (*it2).second, hi = (*it2).first;\n\t\t\
    \tif (lo <= x.first && x.second <= hi) {\n\t\t\t\tret.emplace_back(lo, hi);\n\t\
    \t\t\tT mn = x.first, mx = x.second;\n\t\t\t\tfor (auto& b : ret) {\n\t\t\t\t\t\
    le.erase(b); ri.erase({b.second, b.first});\n\t\t\t\t\tmn = std::min(mn, b.first);\
    \ mx = std::max(mx, b.second);\n\t\t\t\t}\n\t\t\t\tle.emplace(mn, mx); ri.emplace(mx,\
    \ mn);\n\t\t\t\treturn ret;\n\t\t\t}\n\t\t}\n\t\tif (it1 != le.end()) {\n\t\t\t\
    while (it1 != le.end()) {\n\t\t\t\tauto val = (*it1);\n\t\t\t\tif (val.first <=\
    \ x.second) bad.insert(val);\n\t\t\t\telse break;\n\t\t\t\tit1 = next(it1);\n\t\
    \t\t}\n\t\t}\n\t\tif (it2 != ri.begin()) {\n\t\t\tit2 = prev(it2);\n\t\t\twhile\
    \ (true) {\n\t\t\t\tauto val = (*it2);\n\t\t\t\tif (val.first >= x.first) bad.emplace(val.second,\
    \ val.first);\n\t\t\t\telse break;\n\t\t\t\tif (it2 == ri.begin()) break;\n\t\t\
    \t\tit2 = prev(it2);\n\t\t\t}\n\t\t}\n\t\tfor (auto& b : bad) ret.emplace_back(b);\n\
    \t\tT mn = x.first, mx = x.second;\n\t\tfor (auto& b : ret) {\n\t\t\tle.erase(b);\
    \ ri.erase({b.second, b.first});\n\t\t\tmn = std::min(mn, b.first); mx = std::max(mx,\
    \ b.second);\n\t\t}\n\t\tle.emplace(mn, mx); ri.emplace(mx, mn);\n\t\treturn ret;\n\
    \t}\n};\n\nint main() {\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/interval_union.cpp
  requiredBy: []
  timestamp: '2021-07-10 12:34:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/interval_union.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/interval_union.cpp
- /library/library/data-structures/1d-range-queries/interval_union.cpp.html
title: library/data-structures/1d-range-queries/interval_union.cpp
---
