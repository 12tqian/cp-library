---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-short.hpp
    title: library/contest/template-short.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/lca-jump-distance.hpp
    title: library/graphs/lca-jump-distance.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.spoj.com/problems/QTREE2/
    links:
    - https://www.spoj.com/problems/QTREE2/
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/QTREE2/\"\r\n\r\n\r\
    \n#include <bits/stdc++.h>\r\n\r\nusing namespace std;\r\n\r\n#define f1r(i, a,\
    \ b) for (int i = (a); i < (b); ++i)\r\n#define f0r(i, a) f1r(i, 0, a)\r\n#define\
    \ each(t, a) for (auto& t : a)\r\n\r\n#define mp make_pair\r\n#define f first\r\
    \n#define s second\r\n#define pb push_back\r\n#define eb emplace_back\r\n#define\
    \ sz(x) (int)(x).size()\r\n#define all(x) begin(x), end(x)\r\n\r\ntypedef long\
    \ long ll;\r\ntypedef vector<int> vi;\r\ntypedef vector<ll> vl;\r\ntypedef pair<int,\
    \ int> pi;\r\ntypedef pair<ll, ll> pl;\r\ntypedef vector<pi> vpi;\r\ntypedef vector<pl>\
    \ vpl;\r\n\r\ntemplate <class T> bool ckmin(T& a, const T& b) { return b < a ?\
    \ a = b, 1 : 0; }\r\ntemplate <class T> bool ckmax(T& a, const T& b) { return\
    \ a < b ? a = b, 1 : 0; }\n\r\ntemplate<class T> struct LCAJumpDistance {\r\n\t\
    int n;\r\n\tstd::vector<std::vector<int>> par;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ T>>> adj;\r\n\tstd::vector<int> depth;\r\n\tstd::vector<T> depth_dist;\r\n\r\
    \n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\tint d = 1;\r\n\t\twhile ((1 << d)\
    \ < n) d++;\r\n\t\tpar.assign(d, std::vector<int>(n));\r\n\t\tadj.resize(n);\r\
    \n\t\tdepth.resize(n);\r\n\t\tdepth_dist.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int\
    \ x, int y, T c = 1) {\r\n\t\tadj[x].emplace_back(y, c);\r\n\t\tadj[y].emplace_back(x,\
    \ c);\r\n\t}\r\n\r\n\tvoid gen(int root = 0) {\r\n\t\tpar[0][root] = root;\r\n\
    \t\tdfs(root);\r\n\t}\r\n\r\n\tvoid dfs(int src = 0) {\r\n\t\tfor (int i = 1;\
    \ i < (int)par.size(); i++) {\r\n\t\t\tpar[i][src] = par[i - 1][par[i - 1][src]];\r\
    \n\t\t}\r\n\t\tfor (auto nxt: adj[src]) {\r\n\t\t\tif (nxt.first == par[0][src])\
    \ continue;\r\n\t\t\tdepth_dist[nxt.first] = depth_dist[par[0][nxt.first] = src]\
    \ + nxt.second;\r\n\t\t\tdepth[nxt.first] = depth[par[0][nxt.first] = src] + 1;\r\
    \n\t\t\tdfs(nxt.first);\r\n\t\t}\r\n\t}\r\n\r\n\tint jump(int x, int d) {\r\n\t\
    \tfor (int i = 0; i < (int)par.size(); i++) {\r\n\t\t\tif ((d >> i) & 1) {\r\n\
    \t\t\t\tx = par[i][x];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn x;\r\n\t}\r\n\r\n\tint\
    \ lca(int x, int y) {\r\n\t\tif (depth[x] < depth[y]) std::swap(x, y);\r\n\t\t\
    x = jump(x, depth[x] - depth[y]);\r\n\t\tif (x == y) return x;\r\n\t\tfor (int\
    \ i = (int)par.size() - 1; i >= 0; i--) {\r\n\t\t\tint nx = par[i][x];\r\n\t\t\
    \tint ny = par[i][y];\r\n\t\t\tif (nx != ny) x = nx, y = ny;\r\n\t\t}\r\n\t\t\
    return par[0][x];\r\n\t}\r\n\r\n\tT distance(int x, int y) {\r\n\t\tint l = lca(x,\
    \ y);\r\n\t\treturn depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];\r\n\t}\r\
    \n};\r\n\r\nvoid solve_case(int tc = 0) {\r\n\tint n;\r\n\tcin >> n;\r\n\tLCAJumpDistance<long\
    \ long> lca;\r\n\tlca.init(n);\r\n\tf0r(i, n - 1) {\r\n\t\tint u, v, w;\r\n\t\t\
    cin >> u >> v >> w;\r\n\t\t--u, --v;\r\n\t\tlca.ae(u, v, w);\r\n\t}\r\n\tlca.gen(0);\r\
    \n\twhile (true) {\r\n\t\tstring s;\r\n\t\tcin >> s;\r\n\t\tif (s == \"DIST\"\
    ) {\r\n\t\t\tint u, v;\r\n\t\t\tcin >> u >> v;\r\n\t\t\t--u, --v;\r\n\t\t\tcout\
    \ << (lca.distance(u, v)) << '\\n';\r\n\t\t} else if (s == \"KTH\") {\r\n\t\t\t\
    int u, v, w;\r\n\t\t\tcin >> u >> v >> w;\r\n\t\t\t--u, --v, --w;\r\n\t\t\tint\
    \ up = lca.lca(u, v);\t\t\t\t\t\t\r\n\t\t\tint d1 = lca.depth[u] - lca.depth[up];\r\
    \n\t\t\tint d2 = lca.depth[v] - lca.depth[up];\r\n\t\t\tif (d1 >= w) {\r\n\t\t\
    \t\tcout << (lca.jump(u, w) + 1) << '\\n';\r\n\t\t\t} else {\r\n\t\t\t\tw -= d1;\r\
    \n\t\t\t\tw = d2 - w;\r\n\t\t\t\tcout << (lca.jump(v, w) + 1) << '\\n';\r\n\t\t\
    \t}\r\n\t\t} else {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t}\r\n}\r\n\r\nint main() {\r\
    \n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint tt = 1;\r\n\t\
    cin >> tt;\r\n\tf1r(tc, 1, tt + 1) {\r\n\t\tsolve_case(tc);\r\n\t}\r\n\treturn\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/QTREE2/\"\r\n\r\n#include\
    \ \"../../library/contest/template-short.hpp\"\r\n#include \"../../library/graphs/lca-jump-distance.hpp\"\
    \r\n\r\nvoid solve_case(int tc = 0) {\r\n\tint n;\r\n\tcin >> n;\r\n\tLCAJumpDistance<long\
    \ long> lca;\r\n\tlca.init(n);\r\n\tf0r(i, n - 1) {\r\n\t\tint u, v, w;\r\n\t\t\
    cin >> u >> v >> w;\r\n\t\t--u, --v;\r\n\t\tlca.ae(u, v, w);\r\n\t}\r\n\tlca.gen(0);\r\
    \n\twhile (true) {\r\n\t\tstring s;\r\n\t\tcin >> s;\r\n\t\tif (s == \"DIST\"\
    ) {\r\n\t\t\tint u, v;\r\n\t\t\tcin >> u >> v;\r\n\t\t\t--u, --v;\r\n\t\t\tcout\
    \ << (lca.distance(u, v)) << '\\n';\r\n\t\t} else if (s == \"KTH\") {\r\n\t\t\t\
    int u, v, w;\r\n\t\t\tcin >> u >> v >> w;\r\n\t\t\t--u, --v, --w;\r\n\t\t\tint\
    \ up = lca.lca(u, v);\t\t\t\t\t\t\r\n\t\t\tint d1 = lca.depth[u] - lca.depth[up];\r\
    \n\t\t\tint d2 = lca.depth[v] - lca.depth[up];\r\n\t\t\tif (d1 >= w) {\r\n\t\t\
    \t\tcout << (lca.jump(u, w) + 1) << '\\n';\r\n\t\t\t} else {\r\n\t\t\t\tw -= d1;\r\
    \n\t\t\t\tw = d2 - w;\r\n\t\t\t\tcout << (lca.jump(v, w) + 1) << '\\n';\r\n\t\t\
    \t}\r\n\t\t} else {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t}\r\n}\r\n\r\nint main() {\r\
    \n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint tt = 1;\r\n\t\
    cin >> tt;\r\n\tf1r(tc, 1, tt + 1) {\r\n\t\tsolve_case(tc);\r\n\t}\r\n\treturn\
    \ 0;\r\n}"
  dependsOn:
  - library/contest/template-short.hpp
  - library/graphs/lca-jump-distance.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-QTREE2.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-QTREE2.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-QTREE2.test.cpp
- /verify/verify/spoj/spoj-QTREE2.test.cpp.html
title: verify/spoj/spoj-QTREE2.test.cpp
---
