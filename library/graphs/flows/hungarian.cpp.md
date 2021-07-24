---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n\n/**\n * Another black box algorithm I\
    \ don't understand\n * But I can use \n * O(N^2M) for N jobs and M workers \n\
    \ * 0-indexed\n * Returns the cost, and the assignment\n * job stores the job\
    \ each worker gets assigned to\n * In the example below, they wanted the worker\
    \ each job got assigned to, so I inverted it\n */\n\ntemplate <class C> std::pair<C,\
    \ std::vector<int>> hungarian(const std::vector<std::vector<C>>& a_) {\n\tconst\
    \ C INF = std::numeric_limits<C>::max();\n\tint n = (int)a_.size();\n\tint m =\
    \ (int)a_[0].size();\n\tassert(n <= m);\n\tstd::vector<std::vector<C>> a(n + 1,\
    \ std::vector<C>(m + 1, 0));\n\tfor (int i = 0; i < n; i++)\n\t\tfor (int j =\
    \ 0; j < m; j++)\n\t\t\ta[i + 1][j + 1] = a_[i][j];\n\tstd::vector<C> u(n + 1),\
    \ v(m + 1);\n\tstd::vector<int> job(m + 1);\n\tfor (int i = 1; i <= n; i++) {\n\
    \t\tint w = 0;\n\t\tjob[w] = i;\n\t\tstd::vector<C> dist(m + 1, INF);\n\t\tstd::vector<int>\
    \ pre(m + 1, -1);\n\t\tstd::vector<bool> done(m + 1);\n\t\twhile (job[w]) {\n\t\
    \t\tdone[w] = 1;\n\t\t\tint j = job[w], nxt;\n\t\t\tC delta = INF;\n\t\t\tfor\
    \ (int ww = 0; ww <= m; ww++) {\n\t\t\t\tif (!done[ww]) {\n\t\t\t\t\tif (dist[ww]\
    \ > a[j][ww] - u[j] - v[ww]) {\n\t\t\t\t\t\tdist[ww] = a[j][ww] - u[j] - v[ww];\n\
    \t\t\t\t\t\tpre[ww] = w; \n\t\t\t\t\t}\n\t\t\t\t\tif (delta > dist[ww]) {\n\t\t\
    \t\t\t\tdelta = dist[ww];\n\t\t\t\t\t\tnxt = ww;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\n\t\t\t\tif (done[ww]) {\n\t\t\t\t\
    \tu[job[ww]] += delta;\n\t\t\t\t\tv[ww] -= delta;\n\t\t\t\t} else {\n\t\t\t\t\t\
    dist[ww] -= delta;\n\t\t\t\t}\n\t\t\t}\n\t\t\tw = nxt;\n\t\t}\n\t\tfor (int ww;\
    \ w; w = ww) \n\t\t\tjob[w] = job[ww = pre[w]];\n\t}\n\tjob.erase(job.begin());\n\
    \tfor (int i = 0; i < m; i++)\n\t\tjob[i]--;\n\treturn {-v[0], job};\n}\n\nint\
    \ main() {\n\tusing namespace std;\n\tint n; cin >> n;\n\tvector<vector<long long>>\
    \ a(n, vector<long long>(n));\n\tfor (int i = 0; i < n; i++)\n\t\tfor (int j =\
    \ 0; j < n; j++) cin >> a[i][j];\n\tauto res = hungarian(a);\n\tvector<int> loc(n);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tloc[res.second[i]] = i;\n\t}\n\tcout << res.first\
    \ << '\\n';\n\tfor (int x : loc) \n\t\tcout << x << \" \";\n\tcout << '\\n';\n\
    \treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Another black box algorithm I don't understand\n\
    \ * But I can use \n * O(N^2M) for N jobs and M workers \n * 0-indexed\n * Returns\
    \ the cost, and the assignment\n * job stores the job each worker gets assigned\
    \ to\n * In the example below, they wanted the worker each job got assigned to,\
    \ so I inverted it\n */\n\ntemplate <class C> std::pair<C, std::vector<int>> hungarian(const\
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
    \treturn {-v[0], job};\n}\n\nint main() {\n\tusing namespace std;\n\tint n; cin\
    \ >> n;\n\tvector<vector<long long>> a(n, vector<long long>(n));\n\tfor (int i\
    \ = 0; i < n; i++)\n\t\tfor (int j = 0; j < n; j++) cin >> a[i][j];\n\tauto res\
    \ = hungarian(a);\n\tvector<int> loc(n);\n\tfor (int i = 0; i < n; i++) {\n\t\t\
    loc[res.second[i]] = i;\n\t}\n\tcout << res.first << '\\n';\n\tfor (int x : loc)\
    \ \n\t\tcout << x << \" \";\n\tcout << '\\n';\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/hungarian.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/flows/hungarian.cpp
layout: document
redirect_from:
- /library/library/graphs/flows/hungarian.cpp
- /library/library/graphs/flows/hungarian.cpp.html
title: library/graphs/flows/hungarian.cpp
---
