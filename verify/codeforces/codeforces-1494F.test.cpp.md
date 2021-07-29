---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-short.hpp
    title: library/contest/template-short.hpp
  - icon: ':question:'
    path: library/graphs/dsu.hpp
    title: library/graphs/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/euler-path.hpp
    title: library/graphs/euler-path.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/1494/problem/F
    links:
    - https://codeforces.com/contest/1494/problem/F
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1494/problem/F\"\n\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define f1r(i, a, b) for\
    \ (int i = (a); i < (b); ++i)\n#define f0r(i, a) f1r(i, 0, a)\n#define each(t,\
    \ a) for (auto &t : a)\n\n#define mp make_pair\n#define f first\n#define s second\n\
    #define pb push_back\n#define eb emplace_back\n#define sz(x) (int)(x).size()\n\
    #define all(x) begin(x), end(x)\n\ntypedef long long ll;\ntypedef vector<int>\
    \ vi;\ntypedef vector<ll> vl;\ntypedef pair<int, int> pi;\ntypedef pair<ll, ll>\
    \ pl;\ntypedef vector<pi> vpi;\ntypedef vector<pl> vpl;\n\ntemplate <class T>\
    \ bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }\ntemplate <class\
    \ T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }\n\nstruct DSU\
    \ {\n\tstd::vector<int> e;\n\n\tvoid init(int n) {\n\t\te = std::vector<int>(n,\
    \ -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\n\
    \t}\n\n\tbool same_set(int a, int b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\t\
    int size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tbool unite(int x, int y) {\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ std::swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\n\t\treturn true;\n\t}\n};\n\n\
    \n/**\n * Finds Euler path in O(N + M) from a starting vertex\n * To find which\
    \ vertex to start, use parities\n */\n\ntemplate <bool directed> struct Euler\
    \ {\n\tint n;\n\tstd::vector<std::vector<std::pair<int, int>>> adj;\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>::iterator> its;\n\tstd::vector<bool> used;\n\n\tvoid init(int _n) {\n\t\
    \tn = _n;\n\t\tadj.resize(n);\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tint m = (int)used.size();\n\
    \t\tused.push_back(false);\n\t\tadj[u].emplace_back(v, m);\n\t\tif (!directed)\
    \ {\n\t\t\tadj[v].emplace_back(u, m);\n\t\t}\n\t}\n\n\tstd::vector<std::pair<int,\
    \ int>> euler_path() {\n\t\tint cnt = 0;\n\t\tfor (int i = 0; i < n; i++) \n\t\
    \t\tcnt += (int)adj[i].size() % 2;\n\t\tif (cnt == 2) {\n\t\t\tfor (int i = 0;\
    \ i < n; i++) \n\t\t\t\tif ((int)adj[i].size() % 2) \n\t\t\t\t\treturn get_path(i);\n\
    \t\t} else if (cnt == 0) {\n\t\t\treturn get_path(0);\n\t\t}\n\t\treturn {};\n\
    \t}\n\t\n\tstd::vector<std::pair<int, int>> get_path(int src = 0) {\n\t\tits.resize(n);\n\
    \t\tstd::vector<std::pair<int, int>> ans, s{{src, -1}};\n\t\tfor (int i = 0; i\
    \ < n; i++) {\n\t\t\tits[i] = adj[i].begin();\n\t\t}\n\t\tint lst = -1;\n\t\t\
    while ((int)s.size()) {\n\t\t\tint x = s.back().first;\n\t\t\tauto &it = its[x];\n\
    \t\t\tauto en = adj[x].end();\n\t\t\twhile (it != en && used[it->second]) {\n\t\
    \t\t\t++it;\n\t\t\t}\n\t\t\tif (it == en) {\n\t\t\t\tif (lst != -1 && lst != x)\
    \ {\n\t\t\t\t\treturn {};\n\t\t\t\t}\n\t\t\t\tans.push_back(s.back());\n\t\t\t\
    \ts.pop_back();\n\t\t\t\tif ((int)s.size()) {\n\t\t\t\t\tlst = s.back().first;\n\
    \t\t\t\t}\n\t\t\t} else {\n\t\t\t\ts.push_back(*it);\n\t\t\t\tused[it->second]\
    \ = 1;\n\t\t\t}\n\t\t}\n\t\tif ((int)ans.size() != (int)used.size() + 1) {\n\t\
    \t\treturn {};\n\t\t}\n\t\treverse(ans.begin(), ans.end());\n\t\treturn ans;\n\
    \t}\n};\n\nint main() {\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n, m; cin >>\
    \ n >> m;\n\tvector<vi> g(n);\n\tvpi ed;\n\tf0r(i, m) {\n\t\tint u, v; cin >>\
    \ u >> v;\n\t\tu--, v--;\n\t\tg[u].pb(v);\n\t\tg[v].pb(u);\n\t\ted.eb(u, v);\n\
    \t}\n\tint odd = 0;\n\tf0r(i, n) odd += (sz(g[i]) % 2 == 1);\n\tDSU D; \n\tauto\
    \ finish = [&](int c, vi bad) {\n\t\tvi mark(n);\n\t\teach(x, bad) mark[x] = 1;\n\
    \t\tvector<vi> ng(n);\n\t\tEuler<false> E; E.init(n);\n\t\tf0r(i, n) {\n\t\t\t\
    each(j, g[i]) {\n\t\t\t\tif (i == c && mark[j]) continue;\n\t\t\t\tif (mark[i]\
    \ && j == c) continue;\n\t\t\t\tif (i < j) E.ae(i, j);\n\t\t\t}\n\t\t}\n\t\tauto\
    \ path = E.get_path(c);\n\t\tvi res;\n\t\teach(x, bad) {\n\t\t\tres.pb(c);\n\t\
    \t\tres.pb(x);\n\t\t}\n\t\tres.pb(-1);\n\t\teach(e, path) {\n\t\t\tres.pb(e.f);\n\
    \t\t}\n\t\treverse(all(res));\n\t\tcout << sz(res) << '\\n';\n\t\teach(x, res)\
    \ {\n\t\t\tif (x < 0) cout << x << \" \";\n\t\t\telse cout << x + 1 << \" \";\n\
    \t\t}\n\t\tcout << '\\n';\n\t\texit(0);\n\t};\n\tauto check = [&](int c) {\n\t\
    \tD.init(n);\n\t\teach(e, ed) {\n\t\t\tif (e.f == c || e.s == c) continue;\n\t\
    \t\tD.unite(e.f, e.s);\n\t\t}\n\t\tvector<vi> lead(n);\n\t\teach(v, g[c]) {\n\t\
    \t\tlead[D.get(v)].pb(v);\n\t\t}\n\t\t{ // center is even\n\t\t\tvi bad;\n\t\t\
    \tbool ok = true;\n\t\t\tf0r(i, n) {\n\t\t\t\tif (sz(lead[i]) == 0) continue;\n\
    \t\t\t\tint cnt = 0;\n\t\t\t\teach(j, lead[i]) {\n\t\t\t\t\tif (sz(g[j]) % 2 ==\
    \ 1) {\n\t\t\t\t\t\tcnt++;  \n\t\t\t\t\t\tbad.pb(j);\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t\tif (cnt == sz(lead[i]) && D.size(i) > 1) {\n\t\t\t\t\tok = false;\n\t\t\
    \t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tint num_odd = odd;\n\t\t\tif (sz(bad)\
    \ % 2 == 1) {\n\t\t\t\tif (sz(g[c]) % 2 == 1) num_odd--;\n\t\t\t\telse num_odd++;\n\
    \t\t\t}\n\t\t\tnum_odd -= sz(bad);\n\t\t\tif (ok && num_odd == 0) { // delete\
    \ everything in bad\n\t\t\t\tfinish(c, bad);\n\t\t\t}\n\t\t}\n\t\t{ // center\
    \ is odd\n\t\t\tvi bad;\n\t\t\tvi all_done(n);\n\t\t\tint num = 0;\n\t\t\tf0r(i,\
    \ n) {\n\t\t\t\tif (sz(lead[i]) == 0) continue;\n\t\t\t\tint cnt = 0;\n\t\t\t\t\
    each(j, lead[i]) {\n\t\t\t\t\t\n\t\t\t\t\tif (sz(g[j]) % 2 == 1) {\n\t\t\t\t\t\
    \tcnt++;\n\t\t\t\t\t\tbad.pb(j);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif (cnt == sz(lead[i])\
    \ && D.size(i) > 1) {\n\t\t\t\t\tall_done[i] = 1;\n\t\t\t\t\tnum++;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\tint num_odd = odd;\n\t\t\tif (sz(bad) % 2 == 1) {\n\t\t\t\t\
    if (sz(g[c]) % 2 == 1) num_odd--;\n\t\t\t\telse num_odd++;\n\t\t\t}\n\t\t\tnum_odd\
    \ -= sz(bad);\n\t\t\tif (num <= 1 && num_odd == 0) { // check if one of bad can\
    \ be not used\n\t\t\t\teach(x, bad) {\n\t\t\t\t\tif (num) {\n\t\t\t\t\t\tif (all_done[D.get(x)])\
    \ { // delete everything in bad except for this\n\t\t\t\t\t\t\tvi nbad;\n\t\t\t\
    \t\t\t\teach(y, bad) {\n\t\t\t\t\t\t\t\tif (y == x) continue;\n\t\t\t\t\t\t\t\t\
    nbad.pb(y);\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\tfinish(c, nbad);\n\t\t\t\t\t\t}\n\t\
    \t\t\t\t} else { // delete everything in bad except for this\n\t\t\t\t\t\tfinish(c,\
    \ bad);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t} else if (num_odd == 2 && num == 0) {\n\
    \t\t\t\tif (sz(bad) % 2 != sz(g[c]) % 2) {\n\t\t\t\t\tfinish(c, bad);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t};\n\tEuler<false> E; E.init(n);\n\tf0r(i, n) { \n\t\teach(j,\
    \ g[i]) {\n\t\t\tif (j < i) E.ae(i, j);\n\t\t}\n\t}\n\tauto res = E.euler_path();\n\
    \tif (sz(res)) {\n\t\tcout << sz(res) << '\\n';\n\t\teach(e, res) cout << e.f\
    \ + 1 << \" \";\n\t\tcout << '\\n';\n\t\texit(0);\n\t}\n\tf0r(i, n) check(i);\n\
    \tcout << 0 << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1494/problem/F\"\n\n#include\
    \ \"../../library/contest/template-short.hpp\"\n#include \"../../library/graphs/dsu.hpp\"\
    \n#include \"../../library/graphs/euler-path.hpp\"\n\nint main() {\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tint n, m; cin >> n >> m;\n\tvector<vi> g(n);\n\tvpi ed;\n\tf0r(i, m) {\n\t\t\
    int u, v; cin >> u >> v;\n\t\tu--, v--;\n\t\tg[u].pb(v);\n\t\tg[v].pb(u);\n\t\t\
    ed.eb(u, v);\n\t}\n\tint odd = 0;\n\tf0r(i, n) odd += (sz(g[i]) % 2 == 1);\n\t\
    DSU D; \n\tauto finish = [&](int c, vi bad) {\n\t\tvi mark(n);\n\t\teach(x, bad)\
    \ mark[x] = 1;\n\t\tvector<vi> ng(n);\n\t\tEuler<false> E; E.init(n);\n\t\tf0r(i,\
    \ n) {\n\t\t\teach(j, g[i]) {\n\t\t\t\tif (i == c && mark[j]) continue;\n\t\t\t\
    \tif (mark[i] && j == c) continue;\n\t\t\t\tif (i < j) E.ae(i, j);\n\t\t\t}\n\t\
    \t}\n\t\tauto path = E.get_path(c);\n\t\tvi res;\n\t\teach(x, bad) {\n\t\t\tres.pb(c);\n\
    \t\t\tres.pb(x);\n\t\t}\n\t\tres.pb(-1);\n\t\teach(e, path) {\n\t\t\tres.pb(e.f);\n\
    \t\t}\n\t\treverse(all(res));\n\t\tcout << sz(res) << '\\n';\n\t\teach(x, res)\
    \ {\n\t\t\tif (x < 0) cout << x << \" \";\n\t\t\telse cout << x + 1 << \" \";\n\
    \t\t}\n\t\tcout << '\\n';\n\t\texit(0);\n\t};\n\tauto check = [&](int c) {\n\t\
    \tD.init(n);\n\t\teach(e, ed) {\n\t\t\tif (e.f == c || e.s == c) continue;\n\t\
    \t\tD.unite(e.f, e.s);\n\t\t}\n\t\tvector<vi> lead(n);\n\t\teach(v, g[c]) {\n\t\
    \t\tlead[D.get(v)].pb(v);\n\t\t}\n\t\t{ // center is even\n\t\t\tvi bad;\n\t\t\
    \tbool ok = true;\n\t\t\tf0r(i, n) {\n\t\t\t\tif (sz(lead[i]) == 0) continue;\n\
    \t\t\t\tint cnt = 0;\n\t\t\t\teach(j, lead[i]) {\n\t\t\t\t\tif (sz(g[j]) % 2 ==\
    \ 1) {\n\t\t\t\t\t\tcnt++;  \n\t\t\t\t\t\tbad.pb(j);\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t\tif (cnt == sz(lead[i]) && D.size(i) > 1) {\n\t\t\t\t\tok = false;\n\t\t\
    \t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tint num_odd = odd;\n\t\t\tif (sz(bad)\
    \ % 2 == 1) {\n\t\t\t\tif (sz(g[c]) % 2 == 1) num_odd--;\n\t\t\t\telse num_odd++;\n\
    \t\t\t}\n\t\t\tnum_odd -= sz(bad);\n\t\t\tif (ok && num_odd == 0) { // delete\
    \ everything in bad\n\t\t\t\tfinish(c, bad);\n\t\t\t}\n\t\t}\n\t\t{ // center\
    \ is odd\n\t\t\tvi bad;\n\t\t\tvi all_done(n);\n\t\t\tint num = 0;\n\t\t\tf0r(i,\
    \ n) {\n\t\t\t\tif (sz(lead[i]) == 0) continue;\n\t\t\t\tint cnt = 0;\n\t\t\t\t\
    each(j, lead[i]) {\n\t\t\t\t\t\n\t\t\t\t\tif (sz(g[j]) % 2 == 1) {\n\t\t\t\t\t\
    \tcnt++;\n\t\t\t\t\t\tbad.pb(j);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif (cnt == sz(lead[i])\
    \ && D.size(i) > 1) {\n\t\t\t\t\tall_done[i] = 1;\n\t\t\t\t\tnum++;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\tint num_odd = odd;\n\t\t\tif (sz(bad) % 2 == 1) {\n\t\t\t\t\
    if (sz(g[c]) % 2 == 1) num_odd--;\n\t\t\t\telse num_odd++;\n\t\t\t}\n\t\t\tnum_odd\
    \ -= sz(bad);\n\t\t\tif (num <= 1 && num_odd == 0) { // check if one of bad can\
    \ be not used\n\t\t\t\teach(x, bad) {\n\t\t\t\t\tif (num) {\n\t\t\t\t\t\tif (all_done[D.get(x)])\
    \ { // delete everything in bad except for this\n\t\t\t\t\t\t\tvi nbad;\n\t\t\t\
    \t\t\t\teach(y, bad) {\n\t\t\t\t\t\t\t\tif (y == x) continue;\n\t\t\t\t\t\t\t\t\
    nbad.pb(y);\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\tfinish(c, nbad);\n\t\t\t\t\t\t}\n\t\
    \t\t\t\t} else { // delete everything in bad except for this\n\t\t\t\t\t\tfinish(c,\
    \ bad);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t} else if (num_odd == 2 && num == 0) {\n\
    \t\t\t\tif (sz(bad) % 2 != sz(g[c]) % 2) {\n\t\t\t\t\tfinish(c, bad);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t};\n\tEuler<false> E; E.init(n);\n\tf0r(i, n) { \n\t\teach(j,\
    \ g[i]) {\n\t\t\tif (j < i) E.ae(i, j);\n\t\t}\n\t}\n\tauto res = E.euler_path();\n\
    \tif (sz(res)) {\n\t\tcout << sz(res) << '\\n';\n\t\teach(e, res) cout << e.f\
    \ + 1 << \" \";\n\t\tcout << '\\n';\n\t\texit(0);\n\t}\n\tf0r(i, n) check(i);\n\
    \tcout << 0 << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-short.hpp
  - library/graphs/dsu.hpp
  - library/graphs/euler-path.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1494F.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1494F.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1494F.test.cpp
- /verify/verify/codeforces/codeforces-1494F.test.cpp.html
title: verify/codeforces/codeforces-1494F.test.cpp
---
