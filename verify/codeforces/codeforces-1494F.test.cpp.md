---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-short.hpp
    title: library/contest/template-short.hpp
  - icon: ':x:'
    path: library/graphs/dsu.hpp
    title: library/graphs/dsu.hpp
  - icon: ':x:'
    path: library/graphs/euler-path.hpp
    title: Euler Path
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/1494/problem/F
    links:
    - https://codeforces.com/contest/1494/problem/F
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1494/problem/F\"\r\
    \n\r\n\r\n#include <bits/stdc++.h>\r\n\r\nusing namespace std;\r\n\r\n#define\
    \ f1r(i, a, b) for (int i = (a); i < (b); ++i)\r\n#define f0r(i, a) f1r(i, 0,\
    \ a)\r\n#define each(t, a) for (auto& t : a)\r\n\r\n#define mp make_pair\r\n#define\
    \ f first\r\n#define s second\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define sz(x) (int)(x).size()\r\n#define all(x) begin(x), end(x)\r\n\r\ntypedef\
    \ long long ll;\r\ntypedef vector<int> vi;\r\ntypedef vector<ll> vl;\r\ntypedef\
    \ pair<int, int> pi;\r\ntypedef pair<ll, ll> pl;\r\ntypedef vector<pi> vpi;\r\n\
    typedef vector<pl> vpl;\r\n\r\ntemplate <class T> bool ckmin(T& a, const T& b)\
    \ { return b < a ? a = b, 1 : 0; }\r\ntemplate <class T> bool ckmax(T& a, const\
    \ T& b) { return a < b ? a = b, 1 : 0; }\n\r\nstruct DSU {\r\n  std::vector<int>\
    \ e;\r\n\r\n  DSU(int n) { init(n); }\r\n\r\n  void init(int n) { e = std::vector<int>(n,\
    \ -1); }\r\n\r\n  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }\r\
    \n\r\n  bool same_set(int a, int b) { return get(a) == get(b); }\r\n\r\n  int\
    \ size(int x) { return -e[get(x)]; }\r\n\r\n  bool unite(int x, int y) {\r\n \
    \   x = get(x), y = get(y);\r\n    if (x == y) return false;\r\n    if (e[x] >\
    \ e[y]) std::swap(x, y);\r\n    e[x] += e[y];\r\n    e[y] = x;\r\n    return true;\r\
    \n  }\r\n};\r\n\r\ntemplate <bool directed> struct Euler {\r\n\tint n;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> adj;\r\n\tstd::vector<std::vector<std::pair<int, int>>::iterator> its;\r\
    \n\tstd::vector<bool> used;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\t\
    adj.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tint m = (int)used.size();\r\
    \n\t\tused.push_back(false);\r\n\t\tadj[u].emplace_back(v, m);\r\n\t\tif (!directed)\
    \ {\r\n\t\t\tadj[v].emplace_back(u, m);\r\n\t\t}\r\n\t}\r\n\r\n\tstd::vector<std::pair<int,\
    \ int>> euler_path() {\r\n\t\tint cnt = 0;\r\n\t\tfor (int i = 0; i < n; i++)\
    \ \r\n\t\t\tcnt += (int)adj[i].size() % 2;\r\n\t\tif (cnt == 2) {\r\n\t\t\tfor\
    \ (int i = 0; i < n; i++) \r\n\t\t\t\tif ((int)adj[i].size() % 2) \r\n\t\t\t\t\
    \treturn get_path(i);\r\n\t\t} else if (cnt == 0) {\r\n\t\t\treturn get_path(0);\r\
    \n\t\t}\r\n\t\treturn {};\r\n\t}\r\n\t\r\n\tstd::vector<std::pair<int, int>> get_path(int\
    \ src = 0) {\r\n\t\tits.resize(n);\r\n\t\tstd::vector<std::pair<int, int>> ans,\
    \ s{{src, -1}};\r\n\t\tfor (int i = 0; i < n; i++) {\r\n\t\t\tits[i] = adj[i].begin();\r\
    \n\t\t}\r\n\t\tint lst = -1;\r\n\t\twhile ((int)s.size()) {\r\n\t\t\tint x = s.back().first;\r\
    \n\t\t\tauto& it = its[x];\r\n\t\t\tauto en = adj[x].end();\r\n\t\t\twhile (it\
    \ != en && used[it->second]) {\r\n\t\t\t\t++it;\r\n\t\t\t}\r\n\t\t\tif (it ==\
    \ en) {\r\n\t\t\t\tif (lst != -1 && lst != x) {\r\n\t\t\t\t\treturn {};\r\n\t\t\
    \t\t}\r\n\t\t\t\tans.push_back(s.back());\r\n\t\t\t\ts.pop_back();\r\n\t\t\t\t\
    if ((int)s.size()) {\r\n\t\t\t\t\tlst = s.back().first;\r\n\t\t\t\t}\r\n\t\t\t\
    } else {\r\n\t\t\t\ts.push_back(*it);\r\n\t\t\t\tused[it->second] = 1;\r\n\t\t\
    \t}\r\n\t\t}\r\n\t\tif ((int)ans.size() != (int)used.size() + 1) {\r\n\t\t\treturn\
    \ {};\r\n\t\t}\r\n\t\treverse(ans.begin(), ans.end());\r\n\t\treturn ans;\r\n\t\
    }\r\n};\r\n\r\nint main() {\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n, m;\
    \ cin >> n >> m;\r\n\tvector<vi> g(n);\r\n\tvpi ed;\r\n\tf0r(i, m) {\r\n\t\tint\
    \ u, v; cin >> u >> v;\r\n\t\tu--, v--;\r\n\t\tg[u].pb(v);\r\n\t\tg[v].pb(u);\r\
    \n\t\ted.eb(u, v);\r\n\t}\r\n\tint odd = 0;\r\n\tf0r(i, n) odd += (sz(g[i]) %\
    \ 2 == 1);\r\n\tDSU D; \r\n\tauto finish = [&](int c, vi bad) {\r\n\t\tvi mark(n);\r\
    \n\t\teach(x, bad) mark[x] = 1;\r\n\t\tvector<vi> ng(n);\r\n\t\tEuler<false> E;\
    \ E.init(n);\r\n\t\tf0r(i, n) {\r\n\t\t\teach(j, g[i]) {\r\n\t\t\t\tif (i == c\
    \ && mark[j]) continue;\r\n\t\t\t\tif (mark[i] && j == c) continue;\r\n\t\t\t\t\
    if (i < j) E.ae(i, j);\r\n\t\t\t}\r\n\t\t}\r\n\t\tauto path = E.get_path(c);\r\
    \n\t\tvi res;\r\n\t\teach(x, bad) {\r\n\t\t\tres.pb(c);\r\n\t\t\tres.pb(x);\r\n\
    \t\t}\r\n\t\tres.pb(-1);\r\n\t\teach(e, path) {\r\n\t\t\tres.pb(e.f);\r\n\t\t\
    }\r\n\t\treverse(all(res));\r\n\t\tcout << sz(res) << '\\n';\r\n\t\teach(x, res)\
    \ {\r\n\t\t\tif (x < 0) cout << x << \" \";\r\n\t\t\telse cout << x + 1 << \"\
    \ \";\r\n\t\t}\r\n\t\tcout << '\\n';\r\n\t\texit(0);\r\n\t};\r\n\tauto check =\
    \ [&](int c) {\r\n\t\tD.init(n);\r\n\t\teach(e, ed) {\r\n\t\t\tif (e.f == c ||\
    \ e.s == c) continue;\r\n\t\t\tD.unite(e.f, e.s);\r\n\t\t}\r\n\t\tvector<vi> lead(n);\r\
    \n\t\teach(v, g[c]) {\r\n\t\t\tlead[D.get(v)].pb(v);\r\n\t\t}\r\n\t\t{ // center\
    \ is even\r\n\t\t\tvi bad;\r\n\t\t\tbool ok = true;\r\n\t\t\tf0r(i, n) {\r\n\t\
    \t\t\tif (sz(lead[i]) == 0) continue;\r\n\t\t\t\tint cnt = 0;\r\n\t\t\t\teach(j,\
    \ lead[i]) {\r\n\t\t\t\t\tif (sz(g[j]) % 2 == 1) {\r\n\t\t\t\t\t\tcnt++;  \r\n\
    \t\t\t\t\t\tbad.pb(j);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tif (cnt == sz(lead[i])\
    \ && D.size(i) > 1) {\r\n\t\t\t\t\tok = false;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t\tint num_odd = odd;\r\n\t\t\tif (sz(bad) % 2 == 1) {\r\n\t\
    \t\t\tif (sz(g[c]) % 2 == 1) num_odd--;\r\n\t\t\t\telse num_odd++;\r\n\t\t\t}\r\
    \n\t\t\tnum_odd -= sz(bad);\r\n\t\t\tif (ok && num_odd == 0) { // delete everything\
    \ in bad\r\n\t\t\t\tfinish(c, bad);\r\n\t\t\t}\r\n\t\t}\r\n\t\t{ // center is\
    \ odd\r\n\t\t\tvi bad;\r\n\t\t\tvi all_done(n);\r\n\t\t\tint num = 0;\r\n\t\t\t\
    f0r(i, n) {\r\n\t\t\t\tif (sz(lead[i]) == 0) continue;\r\n\t\t\t\tint cnt = 0;\r\
    \n\t\t\t\teach(j, lead[i]) {\r\n\t\t\t\t\t\r\n\t\t\t\t\tif (sz(g[j]) % 2 == 1)\
    \ {\r\n\t\t\t\t\t\tcnt++;\r\n\t\t\t\t\t\tbad.pb(j);\r\n\t\t\t\t\t}\r\n\t\t\t\t\
    }\r\n\t\t\t\tif (cnt == sz(lead[i]) && D.size(i) > 1) {\r\n\t\t\t\t\tall_done[i]\
    \ = 1;\r\n\t\t\t\t\tnum++;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tint num_odd = odd;\r\
    \n\t\t\tif (sz(bad) % 2 == 1) {\r\n\t\t\t\tif (sz(g[c]) % 2 == 1) num_odd--;\r\
    \n\t\t\t\telse num_odd++;\r\n\t\t\t}\r\n\t\t\tnum_odd -= sz(bad);\r\n\t\t\tif\
    \ (num <= 1 && num_odd == 0) { // check if one of bad can be not used\r\n\t\t\t\
    \teach(x, bad) {\r\n\t\t\t\t\tif (num) {\r\n\t\t\t\t\t\tif (all_done[D.get(x)])\
    \ { // delete everything in bad except for this\r\n\t\t\t\t\t\t\tvi nbad;\r\n\t\
    \t\t\t\t\t\teach(y, bad) {\r\n\t\t\t\t\t\t\t\tif (y == x) continue;\r\n\t\t\t\t\
    \t\t\t\tnbad.pb(y);\r\n\t\t\t\t\t\t\t}\r\n\t\t\t\t\t\t\tfinish(c, nbad);\r\n\t\
    \t\t\t\t\t}\r\n\t\t\t\t\t} else { // delete everything in bad except for this\r\
    \n\t\t\t\t\t\tfinish(c, bad);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t} else if (num_odd\
    \ == 2 && num == 0) {\r\n\t\t\t\tif (sz(bad) % 2 != sz(g[c]) % 2) {\r\n\t\t\t\t\
    \tfinish(c, bad);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t};\r\n\tEuler<false> E;\
    \ E.init(n);\r\n\tf0r(i, n) { \r\n\t\teach(j, g[i]) {\r\n\t\t\tif (j < i) E.ae(i,\
    \ j);\r\n\t\t}\r\n\t}\r\n\tauto res = E.euler_path();\r\n\tif (sz(res)) {\r\n\t\
    \tcout << sz(res) << '\\n';\r\n\t\teach(e, res) cout << e.f + 1 << \" \";\r\n\t\
    \tcout << '\\n';\r\n\t\texit(0);\r\n\t}\r\n\tf0r(i, n) check(i);\r\n\tcout <<\
    \ 0 << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1494/problem/F\"\r\n\r\n\
    #include \"../../library/contest/template-short.hpp\"\r\n#include \"../../library/graphs/dsu.hpp\"\
    \r\n#include \"../../library/graphs/euler-path.hpp\"\r\n\r\nint main() {\r\n\t\
    cin.tie(0)->sync_with_stdio(0);\r\n\tint n, m; cin >> n >> m;\r\n\tvector<vi>\
    \ g(n);\r\n\tvpi ed;\r\n\tf0r(i, m) {\r\n\t\tint u, v; cin >> u >> v;\r\n\t\t\
    u--, v--;\r\n\t\tg[u].pb(v);\r\n\t\tg[v].pb(u);\r\n\t\ted.eb(u, v);\r\n\t}\r\n\
    \tint odd = 0;\r\n\tf0r(i, n) odd += (sz(g[i]) % 2 == 1);\r\n\tDSU D; \r\n\tauto\
    \ finish = [&](int c, vi bad) {\r\n\t\tvi mark(n);\r\n\t\teach(x, bad) mark[x]\
    \ = 1;\r\n\t\tvector<vi> ng(n);\r\n\t\tEuler<false> E; E.init(n);\r\n\t\tf0r(i,\
    \ n) {\r\n\t\t\teach(j, g[i]) {\r\n\t\t\t\tif (i == c && mark[j]) continue;\r\n\
    \t\t\t\tif (mark[i] && j == c) continue;\r\n\t\t\t\tif (i < j) E.ae(i, j);\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\tauto path = E.get_path(c);\r\n\t\tvi res;\r\n\t\teach(x,\
    \ bad) {\r\n\t\t\tres.pb(c);\r\n\t\t\tres.pb(x);\r\n\t\t}\r\n\t\tres.pb(-1);\r\
    \n\t\teach(e, path) {\r\n\t\t\tres.pb(e.f);\r\n\t\t}\r\n\t\treverse(all(res));\r\
    \n\t\tcout << sz(res) << '\\n';\r\n\t\teach(x, res) {\r\n\t\t\tif (x < 0) cout\
    \ << x << \" \";\r\n\t\t\telse cout << x + 1 << \" \";\r\n\t\t}\r\n\t\tcout <<\
    \ '\\n';\r\n\t\texit(0);\r\n\t};\r\n\tauto check = [&](int c) {\r\n\t\tD.init(n);\r\
    \n\t\teach(e, ed) {\r\n\t\t\tif (e.f == c || e.s == c) continue;\r\n\t\t\tD.unite(e.f,\
    \ e.s);\r\n\t\t}\r\n\t\tvector<vi> lead(n);\r\n\t\teach(v, g[c]) {\r\n\t\t\tlead[D.get(v)].pb(v);\r\
    \n\t\t}\r\n\t\t{ // center is even\r\n\t\t\tvi bad;\r\n\t\t\tbool ok = true;\r\
    \n\t\t\tf0r(i, n) {\r\n\t\t\t\tif (sz(lead[i]) == 0) continue;\r\n\t\t\t\tint\
    \ cnt = 0;\r\n\t\t\t\teach(j, lead[i]) {\r\n\t\t\t\t\tif (sz(g[j]) % 2 == 1) {\r\
    \n\t\t\t\t\t\tcnt++;  \r\n\t\t\t\t\t\tbad.pb(j);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\
    \n\t\t\t\tif (cnt == sz(lead[i]) && D.size(i) > 1) {\r\n\t\t\t\t\tok = false;\r\
    \n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tint num_odd = odd;\r\n\t\t\
    \tif (sz(bad) % 2 == 1) {\r\n\t\t\t\tif (sz(g[c]) % 2 == 1) num_odd--;\r\n\t\t\
    \t\telse num_odd++;\r\n\t\t\t}\r\n\t\t\tnum_odd -= sz(bad);\r\n\t\t\tif (ok &&\
    \ num_odd == 0) { // delete everything in bad\r\n\t\t\t\tfinish(c, bad);\r\n\t\
    \t\t}\r\n\t\t}\r\n\t\t{ // center is odd\r\n\t\t\tvi bad;\r\n\t\t\tvi all_done(n);\r\
    \n\t\t\tint num = 0;\r\n\t\t\tf0r(i, n) {\r\n\t\t\t\tif (sz(lead[i]) == 0) continue;\r\
    \n\t\t\t\tint cnt = 0;\r\n\t\t\t\teach(j, lead[i]) {\r\n\t\t\t\t\t\r\n\t\t\t\t\
    \tif (sz(g[j]) % 2 == 1) {\r\n\t\t\t\t\t\tcnt++;\r\n\t\t\t\t\t\tbad.pb(j);\r\n\
    \t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tif (cnt == sz(lead[i]) && D.size(i) > 1) {\r\
    \n\t\t\t\t\tall_done[i] = 1;\r\n\t\t\t\t\tnum++;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t\tint num_odd = odd;\r\n\t\t\tif (sz(bad) % 2 == 1) {\r\n\t\t\t\tif (sz(g[c])\
    \ % 2 == 1) num_odd--;\r\n\t\t\t\telse num_odd++;\r\n\t\t\t}\r\n\t\t\tnum_odd\
    \ -= sz(bad);\r\n\t\t\tif (num <= 1 && num_odd == 0) { // check if one of bad\
    \ can be not used\r\n\t\t\t\teach(x, bad) {\r\n\t\t\t\t\tif (num) {\r\n\t\t\t\t\
    \t\tif (all_done[D.get(x)]) { // delete everything in bad except for this\r\n\t\
    \t\t\t\t\t\tvi nbad;\r\n\t\t\t\t\t\t\teach(y, bad) {\r\n\t\t\t\t\t\t\t\tif (y\
    \ == x) continue;\r\n\t\t\t\t\t\t\t\tnbad.pb(y);\r\n\t\t\t\t\t\t\t}\r\n\t\t\t\t\
    \t\t\tfinish(c, nbad);\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t} else { // delete everything\
    \ in bad except for this\r\n\t\t\t\t\t\tfinish(c, bad);\r\n\t\t\t\t\t}\r\n\t\t\
    \t\t}\r\n\t\t\t} else if (num_odd == 2 && num == 0) {\r\n\t\t\t\tif (sz(bad) %\
    \ 2 != sz(g[c]) % 2) {\r\n\t\t\t\t\tfinish(c, bad);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\
    \t\t}\r\n\t};\r\n\tEuler<false> E; E.init(n);\r\n\tf0r(i, n) { \r\n\t\teach(j,\
    \ g[i]) {\r\n\t\t\tif (j < i) E.ae(i, j);\r\n\t\t}\r\n\t}\r\n\tauto res = E.euler_path();\r\
    \n\tif (sz(res)) {\r\n\t\tcout << sz(res) << '\\n';\r\n\t\teach(e, res) cout <<\
    \ e.f + 1 << \" \";\r\n\t\tcout << '\\n';\r\n\t\texit(0);\r\n\t}\r\n\tf0r(i, n)\
    \ check(i);\r\n\tcout << 0 << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-short.hpp
  - library/graphs/dsu.hpp
  - library/graphs/euler-path.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1494F.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 14:07:45-05:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1494F.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1494F.test.cpp
- /verify/verify/codeforces/codeforces-1494F.test.cpp.html
title: verify/codeforces/codeforces-1494F.test.cpp
---
