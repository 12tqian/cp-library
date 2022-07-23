---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/two-sat.hpp
    title: library/graphs/two-sat.hpp
  - icon: ':heavy_check_mark:'
    path: library/number-theory/fast-factor-sieve.hpp
    title: library/number-theory/fast-factor-sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc210/tasks/abc210_f
    links:
    - https://atcoder.jp/contests/abc210/tasks/abc210_f
  bundledCode: "#define PROBLEM \"https://atcoder.jp/contests/abc210/tasks/abc210_f\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nstruct SCC {\r\n\tint n,\
    \ ti;\r\n\t\r\n\tstd::vector<std::vector<int>> g;\r\n\t\r\n\tstd::vector<int>\
    \ disc, comp, stk, comps;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\t\
    ti = 0;\r\n\t\tg.resize(n);\r\n\t\tdisc.resize(n);\r\n\t\tcomp.assign(n, -1);\r\
    \n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tg[u].push_back(v);\r\n\t}\r\n\r\n\
    \tint dfs(int u) {\r\n\t\tint low = disc[u] = ++ti;\r\n\t\tstk.push_back(u);\r\
    \n\t\tfor (int v : g[u]) {\r\n\t\t\tif (comp[v] == -1) {\r\n\t\t\t\tlow = std::min(low,\
    \ disc[v] ? : dfs(v));\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (low == disc[u]) {\r\n\t\t\
    \tcomps.push_back(u);\r\n\t\t\tfor (int v  = -1; v != u; ) {\r\n\t\t\t\tcomp[v\
    \ = stk.back()] = u;\r\n\t\t\t\tstk.pop_back();\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ low;\r\n\t}\r\n\r\n\tvoid gen() {\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\
    \t\tif (disc[i] == 0) {\r\n\t\t\t\tdfs(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\treverse(comps.begin(),\
    \ comps.end());\r\n\t}\r\n};\r\n\r\nstruct TwoSat {\r\n\tint n = 0;\r\n\t\r\n\t\
    std::vector<std::array<int, 2>> edges;\r\n\r\n\tvoid init(int n_) { n = n_; }\r\
    \n\t\r\n\tint add_var() { return n++; }\r\n\t\r\n\tvoid either(int x, int y) {\r\
    \n\t\tx = std::max(2 * x, -1 - 2 * x);\r\n\t\ty = std::max(2 * y, -1 - 2 * y);\r\
    \n\t\tedges.push_back({x, y});\r\n\t}\r\n\r\n\tvoid implies(int x, int y) { either(~x,\
    \ y); }\r\n\t\r\n\tvoid must(int x) { either(x, x); }\r\n\t\r\n\tvoid at_most_one(const\
    \ std::vector<int>& v) {\r\n\t\tif ((int)v.size() <= 1) {\r\n\t\t\treturn;\r\n\
    \t\t}\r\n\t\tint cur = ~v[0];\r\n\t\tfor (int i = 2; i < (int)v.size(); ++i) {\r\
    \n\t\t\tint nxt = add_var();\r\n\t\t\teither(cur, ~v[i]);\r\n\t\t\teither(cur,\
    \ nxt);\r\n\t\t\teither(~v[i], nxt);\r\n\t\t\tcur = ~nxt;\r\n\t\t}\r\n\t\teither(cur,\
    \ ~v[1]);\r\n\t}\r\n\t\r\n\tstd::vector<bool> solve(int n_ = -1) {\r\n\t\tif (n_\
    \ != -1) {\r\n\t\t\tn = n_;\r\n\t\t}\r\n\t\tSCC S;\r\n\t\tS.init(2 * n);\r\n\t\
    \tfor (auto [u, v] : edges) {\r\n\t\t\tS.ae(u ^ 1, v);\r\n\t\t\tS.ae(v ^ 1, u);\r\
    \n\t\t}\r\n\t\tS.gen();\r\n\t\treverse(S.comps.begin(), S.comps.end());\r\n\t\t\
    for (int i = 0; i < 2 * n; i += 2) {\r\n\t\t\tif (S.comp[i] == S.comp[i ^ 1])\
    \ {\r\n\t\t\t\treturn {};\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int> tmp(2 *\
    \ n);\r\n\t\tfor (int i : S.comps) {\r\n\t\t\tif (tmp[i] == 0) {\r\n\t\t\t\ttmp[i]\
    \ = 1;\r\n\t\t\t\ttmp[S.comp[i ^ 1]] = -1;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<bool>\
    \ ans(n);\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tans[i] = tmp[S.comp[2\
    \ * i]] == 1;\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n};\n\r\ntemplate <int SZ>\
    \ struct Sieve {\r\n\tint spf[SZ];\r\n\t\r\n\tSieve() {\r\n\t\tspf[1] = 1;\r\n\
    \t\tfor (int i = 2; i < SZ; i++) \r\n\t\t\tspf[i] = i;\r\n\t\tfor (int i = 4;\
    \ i < SZ; i += 2) \r\n\t\t\tspf[i] = 2;\r\n\t\tfor (int i = 3; i * i < SZ; i++)\
    \ \r\n\t\t\tif (spf[i] == i) \r\n\t\t\t\tfor (int j = i * i; j < SZ; j += i) \r\
    \n\t\t\t\t\tif (spf[j] == j) \r\n\t\t\t\t\t\tspf[j] = i;\r\n\t}\r\n\r\n\tstd::vector<std::pair<int,\
    \ int>> factor(int x) {\r\n\t\tstd::vector<std::pair<int, int>> ret;\r\n\t\twhile\
    \ (x != 1) {\r\n\t\t\tif ((int)ret.size() == 0) \r\n\t\t\t\tret.emplace_back(spf[x],\
    \ 1);\r\n\t\t\telse {\r\n\t\t\t\tif (ret.back().first == spf[x]) \r\n\t\t\t\t\t\
    ret.back().second++;\r\n\t\t\t\telse \r\n\t\t\t\t\tret.emplace_back(spf[x], 1);\r\
    \n\t\t\t}\r\n\t\t\tx /= spf[x];\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\r\n\r\
    \nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\t\
    const int V = 2e6 + 5;\r\n\tSieve<V> sieve;\r\n\tvector<vector<int>> primes(V);\r\
    \n\tint n;\r\n\tcin >> n;\r\n\tvector<array<int, 2>> v(n);\r\n\tfor (int i = 0;\
    \ i < n; ++i) {\r\n\t\tfor (int j = 0; j < 2; ++j) {\r\n\t\t\tcin >> v[i][j];\r\
    \n\t\t\tauto f = sieve.factor(v[i][j]);\r\n\t\t\tfor (auto [p, e] : f) {\r\n\t\
    \t\t\tprimes[p].push_back(j == 0 ? i : ~i);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tTwoSat\
    \ two_sat;\r\n\ttwo_sat.init(n);\r\n\tfor (auto& v : primes) {\r\n\t\ttwo_sat.at_most_one(v);\r\
    \n\t}\r\n\tauto ans = two_sat.solve();\r\n\tif (ans.empty()) {\r\n\t\tcout <<\
    \ \"No\";\r\n\t} else {\r\n\t\tcout << \"Yes\";\r\n\t}\r\n\tcout << '\\n';\r\n\
    \treturn 0;\r\n}\r\n\r\n\r\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc210/tasks/abc210_f\"\r\n\
    \r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/two-sat.hpp\"\
    \r\n#include \"../../library/number-theory/fast-factor-sieve.hpp\"\r\n\r\nint\
    \ main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tconst\
    \ int V = 2e6 + 5;\r\n\tSieve<V> sieve;\r\n\tvector<vector<int>> primes(V);\r\n\
    \tint n;\r\n\tcin >> n;\r\n\tvector<array<int, 2>> v(n);\r\n\tfor (int i = 0;\
    \ i < n; ++i) {\r\n\t\tfor (int j = 0; j < 2; ++j) {\r\n\t\t\tcin >> v[i][j];\r\
    \n\t\t\tauto f = sieve.factor(v[i][j]);\r\n\t\t\tfor (auto [p, e] : f) {\r\n\t\
    \t\t\tprimes[p].push_back(j == 0 ? i : ~i);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tTwoSat\
    \ two_sat;\r\n\ttwo_sat.init(n);\r\n\tfor (auto& v : primes) {\r\n\t\ttwo_sat.at_most_one(v);\r\
    \n\t}\r\n\tauto ans = two_sat.solve();\r\n\tif (ans.empty()) {\r\n\t\tcout <<\
    \ \"No\";\r\n\t} else {\r\n\t\tcout << \"Yes\";\r\n\t}\r\n\tcout << '\\n';\r\n\
    \treturn 0;\r\n}\r\n\r\n\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/two-sat.hpp
  - library/number-theory/fast-factor-sieve.hpp
  isVerificationFile: true
  path: verify/atcoder/atcoder-abc210_f.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/atcoder/atcoder-abc210_f.test.cpp
layout: document
redirect_from:
- /verify/verify/atcoder/atcoder-abc210_f.test.cpp
- /verify/verify/atcoder/atcoder-abc210_f.test.cpp.html
title: verify/atcoder/atcoder-abc210_f.test.cpp
---
