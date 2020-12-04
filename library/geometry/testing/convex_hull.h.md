---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/geometry/testing/convex_hull.h\"\n#include <point_geometry.h>\n\
    \nnamespace ConvexHull {\n\ntemplate <class T>\nstd::pair<std::vector<int>, std::vector<int>>\
    \ upper_lower_hull(const std::vector<Point<T>>& v) {\n    std::vector<int> p((int)\
    \ v.size()), upper, lower;\n    iota(p.begin(), p.end(), 0);\n    sort(p.begin(),\
    \ p.end(), [&v](int a, int b) { return v[a] < v[b]; });\n    for (int& i : p)\
    \ {\n        while ((int) upper.size() > 1 && \n            area(v[upper[(int)\
    \ upper.size() - 2]], v[upper.back()], v[i]) >= 0) \n            upper.pop_back();\n\
    \        upper.push_back(i);\n        while ((int) lower.size() > 1 && \n    \
    \        area(v[lower[(int) lower.size() - 2]], v[lower.back()], v[i]) <= 0) \n\
    \            lower.pop_back();\n        lower.push_back(i);\n    }\n    return\
    \ {upper, lower};\n}\ntemplate <class T> std::vector<int> hull_index(const std::vector<Point<T>>&\
    \ v) {\n    std::vector<int> upper, lower;\n    tie(upper, lower) = upper_lower_hull(v);\n\
    \    if ((int) lower.size() <= 1) \n        return lower;\n    if (v[lower[0]]\
    \ == v[lower[1]])\n        return {0};\n    lower.insert(lower.end(), 1 + upper.rbegin(),\
    \ upper.rend() - 1);\n    return lower;\n}\ntemplate <class T> std::vector<Point<T>>\
    \ convex_hull(const std::vector<Point<T>>& v) {\n    std::vector<int> w = hull_index(v);\n\
    \    std::vector<Point<T>> res;\n    for (auto& t : w)\n        res.push_back(v[t]);\n\
    \    return res;\n}\n\n} // ConvexHull\n"
  code: "#include <point_geometry.h>\n\nnamespace ConvexHull {\n\ntemplate <class\
    \ T>\nstd::pair<std::vector<int>, std::vector<int>> upper_lower_hull(const std::vector<Point<T>>&\
    \ v) {\n    std::vector<int> p((int) v.size()), upper, lower;\n    iota(p.begin(),\
    \ p.end(), 0);\n    sort(p.begin(), p.end(), [&v](int a, int b) { return v[a]\
    \ < v[b]; });\n    for (int& i : p) {\n        while ((int) upper.size() > 1 &&\
    \ \n            area(v[upper[(int) upper.size() - 2]], v[upper.back()], v[i])\
    \ >= 0) \n            upper.pop_back();\n        upper.push_back(i);\n       \
    \ while ((int) lower.size() > 1 && \n            area(v[lower[(int) lower.size()\
    \ - 2]], v[lower.back()], v[i]) <= 0) \n            lower.pop_back();\n      \
    \  lower.push_back(i);\n    }\n    return {upper, lower};\n}\ntemplate <class\
    \ T> std::vector<int> hull_index(const std::vector<Point<T>>& v) {\n    std::vector<int>\
    \ upper, lower;\n    tie(upper, lower) = upper_lower_hull(v);\n    if ((int) lower.size()\
    \ <= 1) \n        return lower;\n    if (v[lower[0]] == v[lower[1]])\n       \
    \ return {0};\n    lower.insert(lower.end(), 1 + upper.rbegin(), upper.rend()\
    \ - 1);\n    return lower;\n}\ntemplate <class T> std::vector<Point<T>> convex_hull(const\
    \ std::vector<Point<T>>& v) {\n    std::vector<int> w = hull_index(v);\n    std::vector<Point<T>>\
    \ res;\n    for (auto& t : w)\n        res.push_back(v[t]);\n    return res;\n\
    }\n\n} // ConvexHull"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/testing/convex_hull.h
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/testing/convex_hull.h
layout: document
redirect_from:
- /library/library/geometry/testing/convex_hull.h
- /library/library/geometry/testing/convex_hull.h.html
title: library/geometry/testing/convex_hull.h
---
