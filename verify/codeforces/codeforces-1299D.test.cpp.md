---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-short.hpp
    title: library/contest/template-short.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-operations.hpp
    title: library/modular-arithmetic/mod-operations.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/xor-basis.hpp
    title: XOR Basis
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/1299/problem/D
    links:
    - https://codeforces.com/contest/1299/problem/D
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1299/problem/D\"\r\
    \n\r\n\r\n#include <bits/stdc++.h>\r\n\r\nusing namespace std;\r\n\r\n#define\
    \ f1r(i, a, b) for (int i = (a); i < (b); ++i)\r\n#define f0r(i, a) f1r(i, 0,\
    \ a)\r\n#define each(t, a) for (auto& t : a)\r\n\r\n#define mp make_pair\r\n#define\
    \ f first\r\n#define s second\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define sz(x) (int)(x).size()\r\n#define all(x) begin(x), end(x)\r\n\r\ntypedef\
    \ long long ll;\r\ntypedef vector<int> vi;\r\ntypedef vector<ll> vl;\r\ntypedef\
    \ pair<int, int> pi;\r\ntypedef pair<ll, ll> pl;\r\ntypedef vector<pi> vpi;\r\n\
    typedef vector<pl> vpl;\r\n\r\ntemplate <class T> bool ckmin(T& a, const T& b)\
    \ { return b < a ? a = b, 1 : 0; }\r\ntemplate <class T> bool ckmax(T& a, const\
    \ T& b) { return a < b ? a = b, 1 : 0; }\n\r\nnamespace ModOperations {\r\n\r\n\
    const int MOD = 1e9 + 7;\r\n\r\nint mpow(long long b, long long e) {\r\n\tlong\
    \ long r = 1;\r\n\twhile (e) {\r\n\t\tif (e & 1) {\r\n\t\t\tr *= b; \r\n\t\t\t\
    r %= MOD;\r\n\t\t}\r\n\t\tb *= b; \r\n\t\tb %= MOD;\r\n\t\te >>= 1;\r\n\t}\r\n\
    \treturn r;\r\n}\r\n\r\nint minv(int a) { assert(a); return mpow(a, MOD - 2);\
    \ }\r\nint add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }\r\n\
    int sub(int a, int b) { a -= b; if (a < 0) a += MOD; return a; }\r\nint mul(int\
    \ a, int b) { return 1LL * a * b % MOD; }\r\nint divi(int a, int b) { return mul(a,\
    \ minv(b)); }\r\nint neg(int a) { return a == 0 ? 0 : MOD - a; }\r\nint mod(long\
    \ long v) { \r\n\tv = int((-MOD < v && v < MOD) ? v : v % MOD); if (v < 0) v +=\
    \ MOD; return v; }\r\n\t\r\nint madd(int& a, int b) { return a = add(a, b); }\r\
    \nint msub(int& a, int b) { return a = sub(a, b); }\r\nint mmul(int& a, int b)\
    \ { return a = mul(a, b); }\r\nint mdivi(int& a, int b) { return a = divi(a, b);\
    \ }\r\n\r\n} // ModOperations\n\r\nvoid full_reduce(std::vector<int>& b) {\r\n\
    \tint n = (int)b.size();\r\n\tfor (int i = n - 1; i >= 0; i--) {\r\n\t\tfor (int\
    \ j = i - 1; j >= 0; j--) {\r\n\t\t\tb[j] = std::min(b[j], b[j] ^ b[i]);\r\n\t\
    \t}\r\n\t}\r\n}\r\n\r\ntemplate <class T> T reduce(std::vector<T>& b, T x) {\r\
    \n\tfor (auto& t : b) {\r\n\t\tx = std::min(x, x ^ t);\r\n\t}\r\n\treturn x;\r\
    \n}\r\n\r\ntemplate <class T> bool add(std::vector<T>& b, T x) {\r\n\tif (!(x\
    \ = reduce(b, x))) return false;\r\n\tint ind = 0;\r\n\twhile (ind < (int)b.size()\
    \ && b[ind] > x) ind++;\r\n\tb.insert(b.begin() + ind, x);\r\n\treturn true;\r\
    \n}\n\r\nusing namespace ModOperations;\r\n\r\nconst int N = 1e5 + 5;\r\nconst\
    \ int B = 400;\r\n \r\nint n, m;\r\n \r\nvector<vi> store;\r\n \r\nint comb[B][B];\r\
    \n \r\nvi add_basis(vi &a, vi &b) {\r\n    vi res;\r\n    each(t, a) {\r\n   \
    \     add(res, t);\r\n    }\r\n    each(t, b) {\r\n        add(res, t);\r\n  \
    \  }\r\n    return res;\r\n}\r\n \r\nbool valid(vector<vi> bs) {\r\n    vi basis;\r\
    \n    each(b, bs) {\r\n        each(x, b) {\r\n            if (!add(basis, x))\
    \ return true;\r\n        }\r\n    }\r\n    return false;\r\n}\r\n\r\ntemplate\
    \ <class T> int get_pos(vector<T>& v, T x) { \r\n    return lower_bound(all(v),\
    \ x) - v.begin();\r\n}\r\n \r\nvoid gen() {\r\n    vector<vi> base = {{}}; //\
    \ empty basis first\r\n    each(t, base) store.pb(t);\r\n    f1r(i, 1, 6) {\r\n\
    \        vector<vi> nbase;\r\n        f0r(j, 32) {\r\n            for (auto t\
    \ : base) {\r\n                if (add(t, j)) {\r\n                    full_reduce(t);\r\
    \n                    nbase.pb(t);\r\n                }\r\n            }\r\n \
    \       }\r\n        base.swap(nbase);\r\n        sort(all(base));\r\n       \
    \ base.erase(unique(all(base)), base.end());\r\n        each(t, base) {\r\n  \
    \          store.pb(t);\r\n        }\r\n    }\r\n    sort(all(store));\r\n   \
    \ f0r(i, sz(store)) {\r\n        auto& x = store[i];\r\n        f0r(j, sz(store))\
    \ {\r\n            auto& y = store[j];\r\n            auto z = add_basis(x, y);\r\
    \n            full_reduce(z);\r\n            if (sz(z) != sz(x) + sz(y)) {\r\n\
    \                comb[i][j] = -1;\r\n            } else {\r\n                comb[i][j]\
    \ = get_pos(store, z);\r\n            }\r\n        }\r\n    }\r\n}\r\n \r\nint\
    \ main() {\r\n    cin.tie(0)->sync_with_stdio(0);\r\n    gen();\r\n    cin >>\
    \ n >> m;\r\n    vector<vpi> adj(n);\r\n    vi base(n);\r\n    vi head(n);\r\n\
    \    f0r(i, m) {\r\n        int u, v, w; cin >> u >> v >> w;\r\n        u--, v--;\r\
    \n        adj[u].eb(v, w);\r\n        adj[v].eb(u, w);\r\n    }\r\n    vi direct;\r\
    \n    each(t, adj[0]) direct.pb(t.f);\r\n    sort(all(direct));\r\n    vi vis(n);\r\
    \n    vi in(n);\r\n    vi down(n);\r\n    each(go, adj[0]) {\r\n        vis[0]\
    \ = 1;\r\n        in[0] = -1;\r\n        int x = go.f;\r\n        head[x] = go.s;\r\
    \n        direct.pb(x);\r\n        vi basis;\r\n        int path = 0;\r\n    \
    \    bool bad = false;\r\n        vi comp;\r\n        int ti = 0;\r\n        function<void(int,\
    \ int)> dfs = [&](int u, int p) {\r\n            vis[u] = 1;\r\n            comp.pb(u);\r\
    \n            in[u] = ti++;\r\n            down[u] = path;\r\n            each(v,\
    \ adj[u]) {\r\n                if (v.f == p) continue;\r\n                if (v.f\
    \ == 0) continue;\r\n                if (vis[v.f]) {\r\n                    if\
    \ (in[v.f] < in[u]) {\r\n                        if (!add(basis, down[u] ^ down[v.f]\
    \ ^ v.s)) {\r\n                            bad = true;\r\n                   \
    \     }\r\n                    }\r\n                    continue;\r\n        \
    \        }\r\n                path ^= v.s;\r\n                dfs(v.f, u);\r\n\
    \                path ^= v.s;\r\n            }\r\n        };\r\n        dfs(x,\
    \ 0);\r\n        each(t, comp) vis[t] = 0;\r\n        if (bad) base[x] = -1;\r\
    \n        else {\r\n            full_reduce(basis);\r\n            base[x] = get_pos(store,\
    \ basis);\r\n        } \r\n    }\r\n    sort(all(direct));\r\n    int sz = sz(direct);\r\
    \n    set<int> rem;\r\n    each(t, direct) {\r\n        rem.insert(t);\r\n   \
    \ }\r\n    vector<vi> use;\r\n    while (sz(rem)) {\r\n        int x = *rem.begin();\r\
    \n        int ot = -1;\r\n        int w;\r\n        rem.erase(x);\r\n        each(y,\
    \ adj[x]) {\r\n            if (rem.count(y.f)) {\r\n                ot = y.f;\r\
    \n                w = y.s;\r\n                rem.erase(y.f);\r\n            \
    \    break;\r\n            }\r\n        }\r\n        vi tmp;\r\n        tmp.pb(0);\r\
    \n        if (ot == -1) {\r\n            if (base[x] != -1) {\r\n            \
    \    tmp.pb(base[x]);\r\n            }\r\n        } else {\r\n            if (base[x]\
    \ != -1) {\r\n                tmp.pb(base[x]);\r\n            }\r\n          \
    \  if (base[ot] != -1) {\r\n                tmp.pb(base[ot]);\r\n            }\r\
    \n            if (base[x] != -1 && base[ot] != -1) {\r\n                int val\
    \ = head[x] ^ head[ot] ^ w;\r\n                if (val != 0) {\r\n           \
    \         int i1 = get_pos(store, {val});\r\n                    int i2 = base[x];\r\
    \n                    int res = comb[i1][i2];\r\n                    if (res !=\
    \ -1) {\r\n                        tmp.pb(res);\r\n                    }\r\n \
    \               }\r\n            }\r\n        }\r\n        use.pb(tmp);\r\n  \
    \  }\r\n    int spaces = sz(store);\r\n    vi dp(spaces);\r\n    vi ndp(spaces);\r\
    \n    dp[0] = 1; \r\n    each(t, use) {\r\n        each(c, t) {\r\n          \
    \  f0r(p, spaces) {\r\n                if (comb[c][p] != -1) {\r\n           \
    \         madd(ndp[comb[c][p]], dp[p]);\r\n                }\r\n            }\r\
    \n        }\r\n        dp.swap(ndp);\r\n        ndp.assign(spaces, 0);\r\n   \
    \ }\r\n    int ans = 0;\r\n    each(t, dp) madd(ans, t);\r\n    cout << ans <<\
    \ '\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1299/problem/D\"\r\n\r\n\
    #include \"../../library/contest/template-short.hpp\"\r\n#include \"../../library/modular-arithmetic/mod-operations.hpp\"\
    \r\n#include \"../../library/numerical/xor-basis.hpp\"\r\n\r\nusing namespace\
    \ ModOperations;\r\n\r\nconst int N = 1e5 + 5;\r\nconst int B = 400;\r\n \r\n\
    int n, m;\r\n \r\nvector<vi> store;\r\n \r\nint comb[B][B];\r\n \r\nvi add_basis(vi\
    \ &a, vi &b) {\r\n    vi res;\r\n    each(t, a) {\r\n        add(res, t);\r\n\
    \    }\r\n    each(t, b) {\r\n        add(res, t);\r\n    }\r\n    return res;\r\
    \n}\r\n \r\nbool valid(vector<vi> bs) {\r\n    vi basis;\r\n    each(b, bs) {\r\
    \n        each(x, b) {\r\n            if (!add(basis, x)) return true;\r\n   \
    \     }\r\n    }\r\n    return false;\r\n}\r\n\r\ntemplate <class T> int get_pos(vector<T>&\
    \ v, T x) { \r\n    return lower_bound(all(v), x) - v.begin();\r\n}\r\n \r\nvoid\
    \ gen() {\r\n    vector<vi> base = {{}}; // empty basis first\r\n    each(t, base)\
    \ store.pb(t);\r\n    f1r(i, 1, 6) {\r\n        vector<vi> nbase;\r\n        f0r(j,\
    \ 32) {\r\n            for (auto t : base) {\r\n                if (add(t, j))\
    \ {\r\n                    full_reduce(t);\r\n                    nbase.pb(t);\r\
    \n                }\r\n            }\r\n        }\r\n        base.swap(nbase);\r\
    \n        sort(all(base));\r\n        base.erase(unique(all(base)), base.end());\r\
    \n        each(t, base) {\r\n            store.pb(t);\r\n        }\r\n    }\r\n\
    \    sort(all(store));\r\n    f0r(i, sz(store)) {\r\n        auto& x = store[i];\r\
    \n        f0r(j, sz(store)) {\r\n            auto& y = store[j];\r\n         \
    \   auto z = add_basis(x, y);\r\n            full_reduce(z);\r\n            if\
    \ (sz(z) != sz(x) + sz(y)) {\r\n                comb[i][j] = -1;\r\n         \
    \   } else {\r\n                comb[i][j] = get_pos(store, z);\r\n          \
    \  }\r\n        }\r\n    }\r\n}\r\n \r\nint main() {\r\n    cin.tie(0)->sync_with_stdio(0);\r\
    \n    gen();\r\n    cin >> n >> m;\r\n    vector<vpi> adj(n);\r\n    vi base(n);\r\
    \n    vi head(n);\r\n    f0r(i, m) {\r\n        int u, v, w; cin >> u >> v >>\
    \ w;\r\n        u--, v--;\r\n        adj[u].eb(v, w);\r\n        adj[v].eb(u,\
    \ w);\r\n    }\r\n    vi direct;\r\n    each(t, adj[0]) direct.pb(t.f);\r\n  \
    \  sort(all(direct));\r\n    vi vis(n);\r\n    vi in(n);\r\n    vi down(n);\r\n\
    \    each(go, adj[0]) {\r\n        vis[0] = 1;\r\n        in[0] = -1;\r\n    \
    \    int x = go.f;\r\n        head[x] = go.s;\r\n        direct.pb(x);\r\n   \
    \     vi basis;\r\n        int path = 0;\r\n        bool bad = false;\r\n    \
    \    vi comp;\r\n        int ti = 0;\r\n        function<void(int, int)> dfs =\
    \ [&](int u, int p) {\r\n            vis[u] = 1;\r\n            comp.pb(u);\r\n\
    \            in[u] = ti++;\r\n            down[u] = path;\r\n            each(v,\
    \ adj[u]) {\r\n                if (v.f == p) continue;\r\n                if (v.f\
    \ == 0) continue;\r\n                if (vis[v.f]) {\r\n                    if\
    \ (in[v.f] < in[u]) {\r\n                        if (!add(basis, down[u] ^ down[v.f]\
    \ ^ v.s)) {\r\n                            bad = true;\r\n                   \
    \     }\r\n                    }\r\n                    continue;\r\n        \
    \        }\r\n                path ^= v.s;\r\n                dfs(v.f, u);\r\n\
    \                path ^= v.s;\r\n            }\r\n        };\r\n        dfs(x,\
    \ 0);\r\n        each(t, comp) vis[t] = 0;\r\n        if (bad) base[x] = -1;\r\
    \n        else {\r\n            full_reduce(basis);\r\n            base[x] = get_pos(store,\
    \ basis);\r\n        } \r\n    }\r\n    sort(all(direct));\r\n    int sz = sz(direct);\r\
    \n    set<int> rem;\r\n    each(t, direct) {\r\n        rem.insert(t);\r\n   \
    \ }\r\n    vector<vi> use;\r\n    while (sz(rem)) {\r\n        int x = *rem.begin();\r\
    \n        int ot = -1;\r\n        int w;\r\n        rem.erase(x);\r\n        each(y,\
    \ adj[x]) {\r\n            if (rem.count(y.f)) {\r\n                ot = y.f;\r\
    \n                w = y.s;\r\n                rem.erase(y.f);\r\n            \
    \    break;\r\n            }\r\n        }\r\n        vi tmp;\r\n        tmp.pb(0);\r\
    \n        if (ot == -1) {\r\n            if (base[x] != -1) {\r\n            \
    \    tmp.pb(base[x]);\r\n            }\r\n        } else {\r\n            if (base[x]\
    \ != -1) {\r\n                tmp.pb(base[x]);\r\n            }\r\n          \
    \  if (base[ot] != -1) {\r\n                tmp.pb(base[ot]);\r\n            }\r\
    \n            if (base[x] != -1 && base[ot] != -1) {\r\n                int val\
    \ = head[x] ^ head[ot] ^ w;\r\n                if (val != 0) {\r\n           \
    \         int i1 = get_pos(store, {val});\r\n                    int i2 = base[x];\r\
    \n                    int res = comb[i1][i2];\r\n                    if (res !=\
    \ -1) {\r\n                        tmp.pb(res);\r\n                    }\r\n \
    \               }\r\n            }\r\n        }\r\n        use.pb(tmp);\r\n  \
    \  }\r\n    int spaces = sz(store);\r\n    vi dp(spaces);\r\n    vi ndp(spaces);\r\
    \n    dp[0] = 1; \r\n    each(t, use) {\r\n        each(c, t) {\r\n          \
    \  f0r(p, spaces) {\r\n                if (comb[c][p] != -1) {\r\n           \
    \         madd(ndp[comb[c][p]], dp[p]);\r\n                }\r\n            }\r\
    \n        }\r\n        dp.swap(ndp);\r\n        ndp.assign(spaces, 0);\r\n   \
    \ }\r\n    int ans = 0;\r\n    each(t, dp) madd(ans, t);\r\n    cout << ans <<\
    \ '\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - library/contest/template-short.hpp
  - library/modular-arithmetic/mod-operations.hpp
  - library/numerical/xor-basis.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1299D.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1299D.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1299D.test.cpp
- /verify/verify/codeforces/codeforces-1299D.test.cpp.html
title: verify/codeforces/codeforces-1299D.test.cpp
---
