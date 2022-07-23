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
  bundledCode: "\r\ntemplate <class C> std::pair<C, std::vector<int>> hungarian(const\
    \ std::vector<std::vector<C>>& a_) {\r\n\tconst C INF = std::numeric_limits<C>::max();\r\
    \n\tint n = (int)a_.size();\r\n\tint m = (int)a_[0].size();\r\n\tassert(n <= m);\r\
    \n\tstd::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));\r\n\tfor (int\
    \ i = 0; i < n; i++)\r\n\t\tfor (int j = 0; j < m; j++)\r\n\t\t\ta[i + 1][j +\
    \ 1] = a_[i][j];\r\n\tstd::vector<C> u(n + 1), v(m + 1);\r\n\tstd::vector<int>\
    \ job(m + 1);\r\n\tfor (int i = 1; i <= n; i++) {\r\n\t\tint w = 0;\r\n\t\tjob[w]\
    \ = i;\r\n\t\tstd::vector<C> dist(m + 1, INF);\r\n\t\tstd::vector<int> pre(m +\
    \ 1, -1);\r\n\t\tstd::vector<bool> done(m + 1);\r\n\t\twhile (job[w]) {\r\n\t\t\
    \tdone[w] = 1;\r\n\t\t\tint j = job[w], nxt;\r\n\t\t\tC delta = INF;\r\n\t\t\t\
    for (int ww = 0; ww <= m; ww++) {\r\n\t\t\t\tif (!done[ww]) {\r\n\t\t\t\t\tif\
    \ (dist[ww] > a[j][ww] - u[j] - v[ww]) {\r\n\t\t\t\t\t\tdist[ww] = a[j][ww] -\
    \ u[j] - v[ww];\r\n\t\t\t\t\t\tpre[ww] = w; \r\n\t\t\t\t\t}\r\n\t\t\t\t\tif (delta\
    \ > dist[ww]) {\r\n\t\t\t\t\t\tdelta = dist[ww];\r\n\t\t\t\t\t\tnxt = ww;\r\n\t\
    \t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\r\
    \n\t\t\t\tif (done[ww]) {\r\n\t\t\t\t\tu[job[ww]] += delta;\r\n\t\t\t\t\tv[ww]\
    \ -= delta;\r\n\t\t\t\t} else {\r\n\t\t\t\t\tdist[ww] -= delta;\r\n\t\t\t\t}\r\
    \n\t\t\t}\r\n\t\t\tw = nxt;\r\n\t\t}\r\n\t\tfor (int ww; w; w = ww) \r\n\t\t\t\
    job[w] = job[ww = pre[w]];\r\n\t}\r\n\tjob.erase(job.begin());\r\n\tfor (int i\
    \ = 0; i < m; i++)\r\n\t\tjob[i]--;\r\n\treturn {-v[0], job};\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate <class C> std::pair<C, std::vector<int>> hungarian(const\
    \ std::vector<std::vector<C>>& a_) {\r\n\tconst C INF = std::numeric_limits<C>::max();\r\
    \n\tint n = (int)a_.size();\r\n\tint m = (int)a_[0].size();\r\n\tassert(n <= m);\r\
    \n\tstd::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));\r\n\tfor (int\
    \ i = 0; i < n; i++)\r\n\t\tfor (int j = 0; j < m; j++)\r\n\t\t\ta[i + 1][j +\
    \ 1] = a_[i][j];\r\n\tstd::vector<C> u(n + 1), v(m + 1);\r\n\tstd::vector<int>\
    \ job(m + 1);\r\n\tfor (int i = 1; i <= n; i++) {\r\n\t\tint w = 0;\r\n\t\tjob[w]\
    \ = i;\r\n\t\tstd::vector<C> dist(m + 1, INF);\r\n\t\tstd::vector<int> pre(m +\
    \ 1, -1);\r\n\t\tstd::vector<bool> done(m + 1);\r\n\t\twhile (job[w]) {\r\n\t\t\
    \tdone[w] = 1;\r\n\t\t\tint j = job[w], nxt;\r\n\t\t\tC delta = INF;\r\n\t\t\t\
    for (int ww = 0; ww <= m; ww++) {\r\n\t\t\t\tif (!done[ww]) {\r\n\t\t\t\t\tif\
    \ (dist[ww] > a[j][ww] - u[j] - v[ww]) {\r\n\t\t\t\t\t\tdist[ww] = a[j][ww] -\
    \ u[j] - v[ww];\r\n\t\t\t\t\t\tpre[ww] = w; \r\n\t\t\t\t\t}\r\n\t\t\t\t\tif (delta\
    \ > dist[ww]) {\r\n\t\t\t\t\t\tdelta = dist[ww];\r\n\t\t\t\t\t\tnxt = ww;\r\n\t\
    \t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\r\
    \n\t\t\t\tif (done[ww]) {\r\n\t\t\t\t\tu[job[ww]] += delta;\r\n\t\t\t\t\tv[ww]\
    \ -= delta;\r\n\t\t\t\t} else {\r\n\t\t\t\t\tdist[ww] -= delta;\r\n\t\t\t\t}\r\
    \n\t\t\t}\r\n\t\t\tw = nxt;\r\n\t\t}\r\n\t\tfor (int ww; w; w = ww) \r\n\t\t\t\
    job[w] = job[ww = pre[w]];\r\n\t}\r\n\tjob.erase(job.begin());\r\n\tfor (int i\
    \ = 0; i < m; i++)\r\n\t\tjob[i]--;\r\n\treturn {-v[0], job};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/hungarian.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
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