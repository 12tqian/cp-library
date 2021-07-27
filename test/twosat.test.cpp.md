---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nstruct SCC {\n\tint n, ti;\n\t\n\tstd::vector<std::vector<int>> g;\n\t\n\tstd::vector<int>\
    \ disc, comp, stk, comps;\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tti = 0;\n\
    \t\tg.resize(n);\n\t\tdisc.resize(n);\n\t\tcomp.assign(n, -1);\n\t}\n\n\tvoid\
    \ ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t}\n\n\tint dfs(int u) {\n\t\t\
    int low = disc[u] = ++ti;\n\t\tstk.push_back(u);\n\t\tfor (int v : g[u]) {\n\t\
    \t\tif (comp[v] == -1) {\n\t\t\t\tlow = std::min(low, disc[v] ? : dfs(v));\n\t\
    \t\t}\n\t\t}\n\t\tif (low == disc[u]) {\n\t\t\tcomps.push_back(u);\n\t\t\tfor\
    \ (int v  = -1; v != u; ) {\n\t\t\t\tcomp[v = stk.back()] = u;\n\t\t\t\tstk.pop_back();\n\
    \t\t\t}\n\t\t}\n\t\treturn low;\n\t}\n\n\tvoid gen() {\n\t\tfor (int i = 0; i\
    \ < n; ++i) {\n\t\t\tif (disc[i] == 0) {\n\t\t\t\tdfs(i);\n\t\t\t}\n\t\t}\n\t\t\
    reverse(comps.begin(), comps.end());\n\t}\n};\n\nstruct TwoSat {\n\tint n = 0;\n\
    \t\n\tstd::vector<std::array<int, 2>> edges;\n\n\tvoid init(int n_) { n = n_;\
    \ }\n\t\n\tint add_var() { return n++; }\n\t\n\tvoid either(int x, int y) {\n\t\
    \tx = std::max(2 * x, -1 - 2 * x);\n\t\ty = std::max(2 * y, -1 - 2 * y);\n\t\t\
    edges.push_back({x, y});\n\t}\n\n\tvoid implies(int x, int y) { either(~x, y);\
    \ }\n\t\n\tvoid must(int x) { either(x, x); }\n\t\n\tvoid at_most_one(const std::vector<int>\
    \ &v) {\n\t\tif ((int)v.size() <= 1) {\n\t\t\treturn;\n\t\t}\n\t\tint cur = ~v[0];\n\
    \t\tfor (int i = 2; i < (int)v.size(); ++i) {\n\t\t\tint nxt = add_var();\n\t\t\
    \teither(cur, ~v[i]);\n\t\t\teither(cur, nxt);\n\t\t\teither(~v[i], nxt);\n\t\t\
    \tcur = ~nxt;\n\t\t}\n\t\teither(cur, ~v[1]);\n\t}\n\t\n\tstd::vector<bool> solve(int\
    \ n_ = -1) {\n\t\tif (n_ != -1) {\n\t\t\tn = n_;\n\t\t}\n\t\tSCC S;\n\t\tS.init(2\
    \ * n);\n\t\tfor (auto [u, v] : edges) {\n\t\t\tS.ae(u ^ 1, v);\n\t\t\tS.ae(v\
    \ ^ 1, u);\n\t\t}\n\t\tS.gen();\n\t\treverse(S.comps.begin(), S.comps.end());\n\
    \t\tfor (int i = 0; i < 2 * n; i += 2) {\n\t\t\tif (S.comp[i] == S.comp[i ^ 1])\
    \ {\n\t\t\t\treturn {};\n\t\t\t}\n\t\t}\n\t\tstd::vector<int> tmp(2 * n);\n\t\t\
    for (int i : S.comps) {\n\t\t\tif (tmp[i] == 0) {\n\t\t\t\ttmp[i] = 1;\n\t\t\t\
    \ttmp[S.comp[i ^ 1]] = -1;\n\t\t\t}\n\t\t}\n\t\tstd::vector<bool> ans(n);\n\t\t\
    for (int i = 0; i < n; ++i) {\n\t\t\tans[i] = tmp[S.comp[2 * i]] == 1;\n\t\t}\n\
    \t\treturn ans;\n\t}\n};\n\ntemplate <int SZ> struct Sieve {\n\tint spf[SZ];\n\
    \t\n\tSieve() {\n\t\tspf[1] = 1;\n\t\tfor (int i = 2; i < SZ; i++) \n\t\t\tspf[i]\
    \ = i;\n\t\tfor (int i = 4; i < SZ; i += 2) \n\t\t\tspf[i] = 2;\n\t\tfor (int\
    \ i = 3; i * i < SZ; i++) \n\t\t\tif (spf[i] == i) \n\t\t\t\tfor (int j = i *\
    \ i; j < SZ; j += i) \n\t\t\t\t\tif (spf[j] == j) \n\t\t\t\t\t\tspf[j] = i;\n\t\
    }\n\n\tstd::vector<std::pair<int, int>> factor(int x) {\n\t\tstd::vector<std::pair<int,\
    \ int>> ret;\n\t\twhile (x != 1) {\n\t\t\tif ((int)ret.size() == 0) \n\t\t\t\t\
    ret.emplace_back(spf[x], 1);\n\t\t\telse {\n\t\t\t\tif (ret.back().first == spf[x])\
    \ \n\t\t\t\t\tret.back().second++;\n\t\t\t\telse \n\t\t\t\t\tret.emplace_back(spf[x],\
    \ 1);\n\t\t\t}\n\t\t\tx /= spf[x];\n\t\t}\n\t\treturn ret;\n\t}\n};\n\nint main()\
    \ {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tconst int V = 2e6\
    \ + 5;\n\tSieve<V> sieve;\n\tvector<vector<int>> primes(V);\n\tint n;\n\tcin >>\
    \ n;\n\tvector<array<int, 2>> v(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor\
    \ (int j = 0; j < 2; ++j) {\n\t\t\tcin >> v[i][j];\n\t\t\tauto f = sieve.factor(v[i][j]);\n\
    \t\t\tfor (auto [p, e] : f) {\n\t\t\t\tprimes[p].push_back(j == 0 ? i : ~i);\n\
    \t\t\t}\n\t\t}\n\t}\n\tTwoSat two_sat;\n\ttwo_sat.init(n);\n\tfor (auto& v : primes)\
    \ {\n\t\ttwo_sat.at_most_one(v);\n\t}\n\tauto ans = two_sat.solve();\n\tif (ans.empty())\
    \ {\n\t\tcout << \"No\";\n\t} else {\n\t\tcout << \"Yes\";\n\t}\n\tcout << '\\\
    n';\n\treturn 0;\n}\n\n\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc210/tasks/abc210_f\"\n\n\
    #include \"../library/contest/template-minimal.hpp\"\n#include \"../library/graphs/two-sat.hpp\"\
    \n#include \"../library/number-theory/fast-factor-sieve.hpp\"\n\nint main() {\n\
    \tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tconst int V = 2e6 + 5;\n\
    \tSieve<V> sieve;\n\tvector<vector<int>> primes(V);\n\tint n;\n\tcin >> n;\n\t\
    vector<array<int, 2>> v(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j =\
    \ 0; j < 2; ++j) {\n\t\t\tcin >> v[i][j];\n\t\t\tauto f = sieve.factor(v[i][j]);\n\
    \t\t\tfor (auto [p, e] : f) {\n\t\t\t\tprimes[p].push_back(j == 0 ? i : ~i);\n\
    \t\t\t}\n\t\t}\n\t}\n\tTwoSat two_sat;\n\ttwo_sat.init(n);\n\tfor (auto& v : primes)\
    \ {\n\t\ttwo_sat.at_most_one(v);\n\t}\n\tauto ans = two_sat.solve();\n\tif (ans.empty())\
    \ {\n\t\tcout << \"No\";\n\t} else {\n\t\tcout << \"Yes\";\n\t}\n\tcout << '\\\
    n';\n\treturn 0;\n}\n\n\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/two-sat.hpp
  - library/number-theory/fast-factor-sieve.hpp
  isVerificationFile: true
  path: test/twosat.test.cpp
  requiredBy: []
  timestamp: '2021-07-26 20:36:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/twosat.test.cpp
layout: document
redirect_from:
- /verify/test/twosat.test.cpp
- /verify/test/twosat.test.cpp.html
title: test/twosat.test.cpp
---
