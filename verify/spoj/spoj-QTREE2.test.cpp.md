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
  bundledCode: "#define PROBLEM \"https://www.spoj.com/problems/QTREE2/\"\n\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#define f1r(i, a, b) for (int i =\
    \ (a); i < (b); ++i)\n#define f0r(i, a) f1r(i, 0, a)\n#define each(t, a) for (auto&\
    \ t : a)\n\n#define mp make_pair\n#define f first\n#define s second\n#define pb\
    \ push_back\n#define eb emplace_back\n#define sz(x) (int)(x).size()\n#define all(x)\
    \ begin(x), end(x)\n\ntypedef long long ll;\ntypedef vector<int> vi;\ntypedef\
    \ vector<ll> vl;\ntypedef pair<int, int> pi;\ntypedef pair<ll, ll> pl;\ntypedef\
    \ vector<pi> vpi;\ntypedef vector<pl> vpl;\n\ntemplate <class T> bool ckmin(T&\
    \ a, const T& b) { return b < a ? a = b, 1 : 0; }\ntemplate <class T> bool ckmax(T&\
    \ a, const T& b) { return a < b ? a = b, 1 : 0; }\n\ntemplate<class T> struct\
    \ LCAJumpDistance {\n\tint n;\n\tstd::vector<std::vector<int>> par;\n\tstd::vector<std::vector<std::pair<int,\
    \ T>>> adj;\n\tstd::vector<int> depth;\n\tstd::vector<T> depth_dist;\n\n\tvoid\
    \ init(int _n) {\n\t\tn = _n;\n\t\tint d = 1;\n\t\twhile ((1 << d) < n) d++;\n\
    \t\tpar.assign(d, std::vector<int>(n));\n\t\tadj.resize(n);\n\t\tdepth.resize(n);\n\
    \t\tdepth_dist.resize(n);\n\t}\n\n\tvoid ae(int x, int y, T c = 1) {\n\t\tadj[x].emplace_back(y,\
    \ c);\n\t\tadj[y].emplace_back(x, c);\n\t}\n\n\tvoid gen(int root = 0) {\n\t\t\
    par[0][root] = root;\n\t\tdfs(root);\n\t}\n\n\tvoid dfs(int src = 0) {\n\t\tfor\
    \ (int i = 1; i < (int)par.size(); i++) {\n\t\t\tpar[i][src] = par[i - 1][par[i\
    \ - 1][src]];\n\t\t}\n\t\tfor (auto nxt: adj[src]) {\n\t\t\tif (nxt.first == par[0][src])\
    \ continue;\n\t\t\tdepth_dist[nxt.first] = depth_dist[par[0][nxt.first] = src]\
    \ + nxt.second;\n\t\t\tdepth[nxt.first] = depth[par[0][nxt.first] = src] + 1;\n\
    \t\t\tdfs(nxt.first);\n\t\t}\n\t}\n\n\tint jump(int x, int d) {\n\t\tfor (int\
    \ i = 0; i < (int)par.size(); i++) {\n\t\t\tif ((d >> i) & 1) {\n\t\t\t\tx = par[i][x];\n\
    \t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\n\tint lca(int x, int y) {\n\t\tif (depth[x]\
    \ < depth[y]) std::swap(x, y);\n\t\tx = jump(x, depth[x] - depth[y]);\n\t\tif\
    \ (x == y) return x;\n\t\tfor (int i = (int)par.size() - 1; i >= 0; i--) {\n\t\
    \t\tint nx = par[i][x];\n\t\t\tint ny = par[i][y];\n\t\t\tif (nx != ny) x = nx,\
    \ y = ny;\n\t\t}\n\t\treturn par[0][x];\n\t}\n\n\tT distance(int x, int y) {\n\
    \t\tint l = lca(x, y);\n\t\treturn depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];\n\
    \t}\n};\n\nvoid solve_case(int tc = 0) {\n\tint n;\n\tcin >> n;\n\tLCAJumpDistance<long\
    \ long> lca;\n\tlca.init(n);\n\tf0r(i, n - 1) {\n\t\tint u, v, w;\n\t\tcin >>\
    \ u >> v >> w;\n\t\t--u, --v;\n\t\tlca.ae(u, v, w);\n\t}\n\tlca.gen(0);\n\twhile\
    \ (true) {\n\t\tstring s;\n\t\tcin >> s;\n\t\tif (s == \"DIST\") {\n\t\t\tint\
    \ u, v;\n\t\t\tcin >> u >> v;\n\t\t\t--u, --v;\n\t\t\tcout << (lca.distance(u,\
    \ v)) << '\\n';\n\t\t} else if (s == \"KTH\") {\n\t\t\tint u, v, w;\n\t\t\tcin\
    \ >> u >> v >> w;\n\t\t\t--u, --v, --w;\n\t\t\tint up = lca.lca(u, v);\t\t\t\t\
    \t\t\n\t\t\tint d1 = lca.depth[u] - lca.depth[up];\n\t\t\tint d2 = lca.depth[v]\
    \ - lca.depth[up];\n\t\t\tif (d1 >= w) {\n\t\t\t\tcout << (lca.jump(u, w) + 1)\
    \ << '\\n';\n\t\t\t} else {\n\t\t\t\tw -= d1;\n\t\t\t\tw = d2 - w;\n\t\t\t\tcout\
    \ << (lca.jump(v, w) + 1) << '\\n';\n\t\t\t}\n\t\t} else {\n\t\t\tbreak;\n\t\t\
    }\n\t}\n}\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint tt = 1;\n\tcin >> tt;\n\tf1r(tc, 1, tt + 1) {\n\t\tsolve_case(tc);\n\t}\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://www.spoj.com/problems/QTREE2/\"\n\n#include \"\
    ../../library/contest/template-short.hpp\"\n#include \"../../library/graphs/lca-jump-distance.hpp\"\
    \n\nvoid solve_case(int tc = 0) {\n\tint n;\n\tcin >> n;\n\tLCAJumpDistance<long\
    \ long> lca;\n\tlca.init(n);\n\tf0r(i, n - 1) {\n\t\tint u, v, w;\n\t\tcin >>\
    \ u >> v >> w;\n\t\t--u, --v;\n\t\tlca.ae(u, v, w);\n\t}\n\tlca.gen(0);\n\twhile\
    \ (true) {\n\t\tstring s;\n\t\tcin >> s;\n\t\tif (s == \"DIST\") {\n\t\t\tint\
    \ u, v;\n\t\t\tcin >> u >> v;\n\t\t\t--u, --v;\n\t\t\tcout << (lca.distance(u,\
    \ v)) << '\\n';\n\t\t} else if (s == \"KTH\") {\n\t\t\tint u, v, w;\n\t\t\tcin\
    \ >> u >> v >> w;\n\t\t\t--u, --v, --w;\n\t\t\tint up = lca.lca(u, v);\t\t\t\t\
    \t\t\n\t\t\tint d1 = lca.depth[u] - lca.depth[up];\n\t\t\tint d2 = lca.depth[v]\
    \ - lca.depth[up];\n\t\t\tif (d1 >= w) {\n\t\t\t\tcout << (lca.jump(u, w) + 1)\
    \ << '\\n';\n\t\t\t} else {\n\t\t\t\tw -= d1;\n\t\t\t\tw = d2 - w;\n\t\t\t\tcout\
    \ << (lca.jump(v, w) + 1) << '\\n';\n\t\t\t}\n\t\t} else {\n\t\t\tbreak;\n\t\t\
    }\n\t}\n}\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint tt = 1;\n\tcin >> tt;\n\tf1r(tc, 1, tt + 1) {\n\t\tsolve_case(tc);\n\t}\n\
    \treturn 0;\n}"
  dependsOn:
  - library/contest/template-short.hpp
  - library/graphs/lca-jump-distance.hpp
  isVerificationFile: true
  path: verify/spoj/spoj-QTREE2.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 13:46:51-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/spoj/spoj-QTREE2.test.cpp
layout: document
redirect_from:
- /verify/verify/spoj/spoj-QTREE2.test.cpp
- /verify/verify/spoj/spoj-QTREE2.test.cpp.html
title: verify/spoj/spoj-QTREE2.test.cpp
---
