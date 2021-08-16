---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1299/problem/D\"\n\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define f1r(i, a, b) for\
    \ (int i = (a); i < (b); ++i)\n#define f0r(i, a) f1r(i, 0, a)\n#define each(t,\
    \ a) for (auto& t : a)\n\n#define mp make_pair\n#define f first\n#define s second\n\
    #define pb push_back\n#define eb emplace_back\n#define sz(x) (int)(x).size()\n\
    #define all(x) begin(x), end(x)\n\ntypedef long long ll;\ntypedef vector<int>\
    \ vi;\ntypedef vector<ll> vl;\ntypedef pair<int, int> pi;\ntypedef pair<ll, ll>\
    \ pl;\ntypedef vector<pi> vpi;\ntypedef vector<pl> vpl;\n\ntemplate <class T>\
    \ bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }\ntemplate <class\
    \ T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }\n\nnamespace\
    \ ModOperations {\n\nconst int MOD = 1e9 + 7;\n\nint mpow(long long b, long long\
    \ e) {\n\tlong long r = 1;\n\twhile (e) {\n\t\tif (e & 1) {\n\t\t\tr *= b; \n\t\
    \t\tr %= MOD;\n\t\t}\n\t\tb *= b; \n\t\tb %= MOD;\n\t\te >>= 1;\n\t}\n\treturn\
    \ r;\n}\n\nint minv(int a) { assert(a); return mpow(a, MOD - 2); }\nint add(int\
    \ a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }\nint sub(int a, int\
    \ b) { a -= b; if (a < 0) a += MOD; return a; }\nint mul(int a, int b) { return\
    \ 1LL * a * b % MOD; }\nint divi(int a, int b) { return mul(a, minv(b)); }\nint\
    \ neg(int a) { return a == 0 ? 0 : MOD - a; }\nint mod(long long v) { \n\tv =\
    \ int((-MOD < v && v < MOD) ? v : v % MOD); if (v < 0) v += MOD; return v; }\n\
    \t\nint madd(int& a, int b) { return a = add(a, b); }\nint msub(int& a, int b)\
    \ { return a = sub(a, b); }\nint mmul(int& a, int b) { return a = mul(a, b); }\n\
    int mdivi(int& a, int b) { return a = divi(a, b); }\n\n} // ModOperations\n\n\
    void full_reduce(std::vector<int>& b) {\n\tint n = (int)b.size();\n\tfor (int\
    \ i = n - 1; i >= 0; i--) {\n\t\tfor (int j = i - 1; j >= 0; j--) {\n\t\t\tb[j]\
    \ = std::min(b[j], b[j] ^ b[i]);\n\t\t}\n\t}\n}\n\ntemplate <class T> T reduce(std::vector<T>&\
    \ b, T x) {\n\tfor (auto& t : b) {\n\t\tx = std::min(x, x ^ t);\n\t}\n\treturn\
    \ x;\n}\n\ntemplate <class T> bool add(std::vector<T>& b, T x) {\n\tif (!(x =\
    \ reduce(b, x))) return false;\n\tint ind = 0;\n\twhile (ind < (int)b.size() &&\
    \ b[ind] > x) ind++;\n\tb.insert(b.begin() + ind, x);\n\treturn true;\n}\n\nusing\
    \ namespace ModOperations;\n\nconst int N = 1e5 + 5;\nconst int B = 400;\n \n\
    int n, m;\n \nvector<vi> store;\n \nint comb[B][B];\n \nvi add_basis(vi &a, vi\
    \ &b) {\n    vi res;\n    each(t, a) {\n        add(res, t);\n    }\n    each(t,\
    \ b) {\n        add(res, t);\n    }\n    return res;\n}\n \nbool valid(vector<vi>\
    \ bs) {\n    vi basis;\n    each(b, bs) {\n        each(x, b) {\n            if\
    \ (!add(basis, x)) return true;\n        }\n    }\n    return false;\n}\n\ntemplate\
    \ <class T> int get_pos(vector<T>& v, T x) { \n    return lower_bound(all(v),\
    \ x) - v.begin();\n}\n \nvoid gen() {\n    vector<vi> base = {{}}; // empty basis\
    \ first\n    each(t, base) store.pb(t);\n    f1r(i, 1, 6) {\n        vector<vi>\
    \ nbase;\n        f0r(j, 32) {\n            for (auto t : base) {\n          \
    \      if (add(t, j)) {\n                    full_reduce(t);\n               \
    \     nbase.pb(t);\n                }\n            }\n        }\n        base.swap(nbase);\n\
    \        sort(all(base));\n        base.erase(unique(all(base)), base.end());\n\
    \        each(t, base) {\n            store.pb(t);\n        }\n    }\n    sort(all(store));\n\
    \    f0r(i, sz(store)) {\n        auto& x = store[i];\n        f0r(j, sz(store))\
    \ {\n            auto& y = store[j];\n            auto z = add_basis(x, y);\n\
    \            full_reduce(z);\n            if (sz(z) != sz(x) + sz(y)) {\n    \
    \            comb[i][j] = -1;\n            } else {\n                comb[i][j]\
    \ = get_pos(store, z);\n            }\n        }\n    }\n}\n \nint main() {\n\
    \    cin.tie(0)->sync_with_stdio(0);\n    gen();\n    cin >> n >> m;\n    vector<vpi>\
    \ adj(n);\n    vi base(n);\n    vi head(n);\n    f0r(i, m) {\n        int u, v,\
    \ w; cin >> u >> v >> w;\n        u--, v--;\n        adj[u].eb(v, w);\n      \
    \  adj[v].eb(u, w);\n    }\n    vi direct;\n    each(t, adj[0]) direct.pb(t.f);\n\
    \    sort(all(direct));\n    vi vis(n);\n    vi in(n);\n    vi down(n);\n    each(go,\
    \ adj[0]) {\n        vis[0] = 1;\n        in[0] = -1;\n        int x = go.f;\n\
    \        head[x] = go.s;\n        direct.pb(x);\n        vi basis;\n        int\
    \ path = 0;\n        bool bad = false;\n        vi comp;\n        int ti = 0;\n\
    \        function<void(int, int)> dfs = [&](int u, int p) {\n            vis[u]\
    \ = 1;\n            comp.pb(u);\n            in[u] = ti++;\n            down[u]\
    \ = path;\n            each(v, adj[u]) {\n                if (v.f == p) continue;\n\
    \                if (v.f == 0) continue;\n                if (vis[v.f]) {\n  \
    \                  if (in[v.f] < in[u]) {\n                        if (!add(basis,\
    \ down[u] ^ down[v.f] ^ v.s)) {\n                            bad = true;\n   \
    \                     }\n                    }\n                    continue;\n\
    \                }\n                path ^= v.s;\n                dfs(v.f, u);\n\
    \                path ^= v.s;\n            }\n        };\n        dfs(x, 0);\n\
    \        each(t, comp) vis[t] = 0;\n        if (bad) base[x] = -1;\n        else\
    \ {\n            full_reduce(basis);\n            base[x] = get_pos(store, basis);\n\
    \        } \n    }\n    sort(all(direct));\n    int sz = sz(direct);\n    set<int>\
    \ rem;\n    each(t, direct) {\n        rem.insert(t);\n    }\n    vector<vi> use;\n\
    \    while (sz(rem)) {\n        int x = *rem.begin();\n        int ot = -1;\n\
    \        int w;\n        rem.erase(x);\n        each(y, adj[x]) {\n          \
    \  if (rem.count(y.f)) {\n                ot = y.f;\n                w = y.s;\n\
    \                rem.erase(y.f);\n                break;\n            }\n    \
    \    }\n        vi tmp;\n        tmp.pb(0);\n        if (ot == -1) {\n       \
    \     if (base[x] != -1) {\n                tmp.pb(base[x]);\n            }\n\
    \        } else {\n            if (base[x] != -1) {\n                tmp.pb(base[x]);\n\
    \            }\n            if (base[ot] != -1) {\n                tmp.pb(base[ot]);\n\
    \            }\n            if (base[x] != -1 && base[ot] != -1) {\n         \
    \       int val = head[x] ^ head[ot] ^ w;\n                if (val != 0) {\n \
    \                   int i1 = get_pos(store, {val});\n                    int i2\
    \ = base[x];\n                    int res = comb[i1][i2];\n                  \
    \  if (res != -1) {\n                        tmp.pb(res);\n                  \
    \  }\n                }\n            }\n        }\n        use.pb(tmp);\n    }\n\
    \    int spaces = sz(store);\n    vi dp(spaces);\n    vi ndp(spaces);\n    dp[0]\
    \ = 1; \n    each(t, use) {\n        each(c, t) {\n            f0r(p, spaces)\
    \ {\n                if (comb[c][p] != -1) {\n                    madd(ndp[comb[c][p]],\
    \ dp[p]);\n                }\n            }\n        }\n        dp.swap(ndp);\n\
    \        ndp.assign(spaces, 0);\n    }\n    int ans = 0;\n    each(t, dp) madd(ans,\
    \ t);\n    cout << ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1299/problem/D\"\n\n#include\
    \ \"../../library/contest/template-short.hpp\"\n#include \"../../library/modular-arithmetic/mod-operations.hpp\"\
    \n#include \"../../library/numerical/xor-basis.hpp\"\n\nusing namespace ModOperations;\n\
    \nconst int N = 1e5 + 5;\nconst int B = 400;\n \nint n, m;\n \nvector<vi> store;\n\
    \ \nint comb[B][B];\n \nvi add_basis(vi &a, vi &b) {\n    vi res;\n    each(t,\
    \ a) {\n        add(res, t);\n    }\n    each(t, b) {\n        add(res, t);\n\
    \    }\n    return res;\n}\n \nbool valid(vector<vi> bs) {\n    vi basis;\n  \
    \  each(b, bs) {\n        each(x, b) {\n            if (!add(basis, x)) return\
    \ true;\n        }\n    }\n    return false;\n}\n\ntemplate <class T> int get_pos(vector<T>&\
    \ v, T x) { \n    return lower_bound(all(v), x) - v.begin();\n}\n \nvoid gen()\
    \ {\n    vector<vi> base = {{}}; // empty basis first\n    each(t, base) store.pb(t);\n\
    \    f1r(i, 1, 6) {\n        vector<vi> nbase;\n        f0r(j, 32) {\n       \
    \     for (auto t : base) {\n                if (add(t, j)) {\n              \
    \      full_reduce(t);\n                    nbase.pb(t);\n                }\n\
    \            }\n        }\n        base.swap(nbase);\n        sort(all(base));\n\
    \        base.erase(unique(all(base)), base.end());\n        each(t, base) {\n\
    \            store.pb(t);\n        }\n    }\n    sort(all(store));\n    f0r(i,\
    \ sz(store)) {\n        auto& x = store[i];\n        f0r(j, sz(store)) {\n   \
    \         auto& y = store[j];\n            auto z = add_basis(x, y);\n       \
    \     full_reduce(z);\n            if (sz(z) != sz(x) + sz(y)) {\n           \
    \     comb[i][j] = -1;\n            } else {\n                comb[i][j] = get_pos(store,\
    \ z);\n            }\n        }\n    }\n}\n \nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    gen();\n    cin >> n >> m;\n    vector<vpi> adj(n);\n    vi base(n);\n  \
    \  vi head(n);\n    f0r(i, m) {\n        int u, v, w; cin >> u >> v >> w;\n  \
    \      u--, v--;\n        adj[u].eb(v, w);\n        adj[v].eb(u, w);\n    }\n\
    \    vi direct;\n    each(t, adj[0]) direct.pb(t.f);\n    sort(all(direct));\n\
    \    vi vis(n);\n    vi in(n);\n    vi down(n);\n    each(go, adj[0]) {\n    \
    \    vis[0] = 1;\n        in[0] = -1;\n        int x = go.f;\n        head[x]\
    \ = go.s;\n        direct.pb(x);\n        vi basis;\n        int path = 0;\n \
    \       bool bad = false;\n        vi comp;\n        int ti = 0;\n        function<void(int,\
    \ int)> dfs = [&](int u, int p) {\n            vis[u] = 1;\n            comp.pb(u);\n\
    \            in[u] = ti++;\n            down[u] = path;\n            each(v, adj[u])\
    \ {\n                if (v.f == p) continue;\n                if (v.f == 0) continue;\n\
    \                if (vis[v.f]) {\n                    if (in[v.f] < in[u]) {\n\
    \                        if (!add(basis, down[u] ^ down[v.f] ^ v.s)) {\n     \
    \                       bad = true;\n                        }\n             \
    \       }\n                    continue;\n                }\n                path\
    \ ^= v.s;\n                dfs(v.f, u);\n                path ^= v.s;\n      \
    \      }\n        };\n        dfs(x, 0);\n        each(t, comp) vis[t] = 0;\n\
    \        if (bad) base[x] = -1;\n        else {\n            full_reduce(basis);\n\
    \            base[x] = get_pos(store, basis);\n        } \n    }\n    sort(all(direct));\n\
    \    int sz = sz(direct);\n    set<int> rem;\n    each(t, direct) {\n        rem.insert(t);\n\
    \    }\n    vector<vi> use;\n    while (sz(rem)) {\n        int x = *rem.begin();\n\
    \        int ot = -1;\n        int w;\n        rem.erase(x);\n        each(y,\
    \ adj[x]) {\n            if (rem.count(y.f)) {\n                ot = y.f;\n  \
    \              w = y.s;\n                rem.erase(y.f);\n                break;\n\
    \            }\n        }\n        vi tmp;\n        tmp.pb(0);\n        if (ot\
    \ == -1) {\n            if (base[x] != -1) {\n                tmp.pb(base[x]);\n\
    \            }\n        } else {\n            if (base[x] != -1) {\n         \
    \       tmp.pb(base[x]);\n            }\n            if (base[ot] != -1) {\n \
    \               tmp.pb(base[ot]);\n            }\n            if (base[x] != -1\
    \ && base[ot] != -1) {\n                int val = head[x] ^ head[ot] ^ w;\n  \
    \              if (val != 0) {\n                    int i1 = get_pos(store, {val});\n\
    \                    int i2 = base[x];\n                    int res = comb[i1][i2];\n\
    \                    if (res != -1) {\n                        tmp.pb(res);\n\
    \                    }\n                }\n            }\n        }\n        use.pb(tmp);\n\
    \    }\n    int spaces = sz(store);\n    vi dp(spaces);\n    vi ndp(spaces);\n\
    \    dp[0] = 1; \n    each(t, use) {\n        each(c, t) {\n            f0r(p,\
    \ spaces) {\n                if (comb[c][p] != -1) {\n                    madd(ndp[comb[c][p]],\
    \ dp[p]);\n                }\n            }\n        }\n        dp.swap(ndp);\n\
    \        ndp.assign(spaces, 0);\n    }\n    int ans = 0;\n    each(t, dp) madd(ans,\
    \ t);\n    cout << ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - library/contest/template-short.hpp
  - library/modular-arithmetic/mod-operations.hpp
  - library/numerical/xor-basis.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1299D.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 13:46:51-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1299D.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1299D.test.cpp
- /verify/verify/codeforces/codeforces-1299D.test.cpp.html
title: verify/codeforces/codeforces-1299D.test.cpp
---
