---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-1163.test.cpp
    title: verify/aizu/aizu-1163.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-assignment.test.cpp
    title: verify/yosupo/yosupo-assignment.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class C> std::pair<C, std::vector<int>> hungarian(const\
    \ std::vector<std::vector<C>>& a_) {\n\tconst C INF = std::numeric_limits<C>::max();\n\
    \tint n = (int)a_.size();\n\tint m = (int)a_[0].size();\n\tassert(n <= m);\n\t\
    std::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));\n\tfor (int i\
    \ = 0; i < n; i++)\n\t\tfor (int j = 0; j < m; j++)\n\t\t\ta[i + 1][j + 1] = a_[i][j];\n\
    \tstd::vector<C> u(n + 1), v(m + 1);\n\tstd::vector<int> job(m + 1);\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tint w = 0;\n\t\tjob[w] = i;\n\t\tstd::vector<C> dist(m\
    \ + 1, INF);\n\t\tstd::vector<int> pre(m + 1, -1);\n\t\tstd::vector<bool> done(m\
    \ + 1);\n\t\twhile (job[w]) {\n\t\t\tdone[w] = 1;\n\t\t\tint j = job[w], nxt;\n\
    \t\t\tC delta = INF;\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\n\t\t\t\tif (!done[ww])\
    \ {\n\t\t\t\t\tif (dist[ww] > a[j][ww] - u[j] - v[ww]) {\n\t\t\t\t\t\tdist[ww]\
    \ = a[j][ww] - u[j] - v[ww];\n\t\t\t\t\t\tpre[ww] = w; \n\t\t\t\t\t}\n\t\t\t\t\
    \tif (delta > dist[ww]) {\n\t\t\t\t\t\tdelta = dist[ww];\n\t\t\t\t\t\tnxt = ww;\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\n\t\t\
    \t\tif (done[ww]) {\n\t\t\t\t\tu[job[ww]] += delta;\n\t\t\t\t\tv[ww] -= delta;\n\
    \t\t\t\t} else {\n\t\t\t\t\tdist[ww] -= delta;\n\t\t\t\t}\n\t\t\t}\n\t\t\tw =\
    \ nxt;\n\t\t}\n\t\tfor (int ww; w; w = ww) \n\t\t\tjob[w] = job[ww = pre[w]];\n\
    \t}\n\tjob.erase(job.begin());\n\tfor (int i = 0; i < m; i++)\n\t\tjob[i]--;\n\
    \treturn {-v[0], job};\n}\n"
  code: "#pragma once\n\ntemplate <class C> std::pair<C, std::vector<int>> hungarian(const\
    \ std::vector<std::vector<C>>& a_) {\n\tconst C INF = std::numeric_limits<C>::max();\n\
    \tint n = (int)a_.size();\n\tint m = (int)a_[0].size();\n\tassert(n <= m);\n\t\
    std::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));\n\tfor (int i\
    \ = 0; i < n; i++)\n\t\tfor (int j = 0; j < m; j++)\n\t\t\ta[i + 1][j + 1] = a_[i][j];\n\
    \tstd::vector<C> u(n + 1), v(m + 1);\n\tstd::vector<int> job(m + 1);\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tint w = 0;\n\t\tjob[w] = i;\n\t\tstd::vector<C> dist(m\
    \ + 1, INF);\n\t\tstd::vector<int> pre(m + 1, -1);\n\t\tstd::vector<bool> done(m\
    \ + 1);\n\t\twhile (job[w]) {\n\t\t\tdone[w] = 1;\n\t\t\tint j = job[w], nxt;\n\
    \t\t\tC delta = INF;\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\n\t\t\t\tif (!done[ww])\
    \ {\n\t\t\t\t\tif (dist[ww] > a[j][ww] - u[j] - v[ww]) {\n\t\t\t\t\t\tdist[ww]\
    \ = a[j][ww] - u[j] - v[ww];\n\t\t\t\t\t\tpre[ww] = w; \n\t\t\t\t\t}\n\t\t\t\t\
    \tif (delta > dist[ww]) {\n\t\t\t\t\t\tdelta = dist[ww];\n\t\t\t\t\t\tnxt = ww;\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\n\t\t\
    \t\tif (done[ww]) {\n\t\t\t\t\tu[job[ww]] += delta;\n\t\t\t\t\tv[ww] -= delta;\n\
    \t\t\t\t} else {\n\t\t\t\t\tdist[ww] -= delta;\n\t\t\t\t}\n\t\t\t}\n\t\t\tw =\
    \ nxt;\n\t\t}\n\t\tfor (int ww; w; w = ww) \n\t\t\tjob[w] = job[ww = pre[w]];\n\
    \t}\n\tjob.erase(job.begin());\n\tfor (int i = 0; i < m; i++)\n\t\tjob[i]--;\n\
    \treturn {-v[0], job};\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/hungarian.hpp
  requiredBy: []
  timestamp: '2021-08-13 01:34:54-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-1163.test.cpp
  - verify/yosupo/yosupo-assignment.test.cpp
documentation_of: library/graphs/flows/hungarian.hpp
layout: document
title: Hungarian Algorithm
---

## Hungarian Algorithm

### Assumptions
- $0$-indexed

### Functions
- `hungarian(a)`: Solves the problem if `a[i][j]` indicates the `i`th job's cost for the `j`th worker. Returns the cost and the assignment. 
	- `job` ends up storing the job each worker gets assign. 
	- Works in $\mathcal O(N^2 M)$. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Matching/Hungarian.h)