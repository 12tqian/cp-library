#define PROBLEM "https://codeforces.com/contest/1299/problem/D"

#include "../../library/contest/template-short.hpp"
#include "../../library/numerical/mod-operations.hpp"
#include "../../library/numerical/xor-basis.hpp"

using namespace ModOperations;

const int N = 1e5 + 5;
const int B = 400;
 
int n, m;
 
vector<vi> store;
 
int comb[B][B];
 
vi add_basis(vi &a, vi &b) {
    vi res;
    each(t, a) {
        add(res, t);
    }
    each(t, b) {
        add(res, t);
    }
    return res;
}
 
bool valid(vector<vi> bs) {
    vi basis;
    each(b, bs) {
        each(x, b) {
            if (!add(basis, x)) return true;
        }
    }
    return false;
}

template <class T> int get_pos(vector<T>& v, T x) { 
    return lower_bound(all(v), x) - v.begin();
}
 
void gen() {
    vector<vi> base = {{}}; // empty basis first
    each(t, base) store.pb(t);
    f1r(i, 1, 6) {
        vector<vi> nbase;
        f0r(j, 32) {
            for (auto t : base) {
                if (add(t, j)) {
                    full_reduce(t);
                    nbase.pb(t);
                }
            }
        }
        base.swap(nbase);
        sort(all(base));
        base.erase(unique(all(base)), base.end());
        each(t, base) {
            store.pb(t);
        }
    }
    sort(all(store));
    f0r(i, sz(store)) {
        auto& x = store[i];
        f0r(j, sz(store)) {
            auto& y = store[j];
            auto z = add_basis(x, y);
            full_reduce(z);
            if (sz(z) != sz(x) + sz(y)) {
                comb[i][j] = -1;
            } else {
                comb[i][j] = get_pos(store, z);
            }
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    gen();
    cin >> n >> m;
    vector<vpi> adj(n);
    vi base(n);
    vi head(n);
    f0r(i, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    vi direct;
    each(t, adj[0]) direct.pb(t.f);
    sort(all(direct));
    vi vis(n);
    vi in(n);
    vi down(n);
    each(go, adj[0]) {
        vis[0] = 1;
        in[0] = -1;
        int x = go.f;
        head[x] = go.s;
        direct.pb(x);
        vi basis;
        int path = 0;
        bool bad = false;
        vi comp;
        int ti = 0;
        function<void(int, int)> dfs = [&](int u, int p) {
            vis[u] = 1;
            comp.pb(u);
            in[u] = ti++;
            down[u] = path;
            each(v, adj[u]) {
                if (v.f == p) continue;
                if (v.f == 0) continue;
                if (vis[v.f]) {
                    if (in[v.f] < in[u]) {
                        if (!add(basis, down[u] ^ down[v.f] ^ v.s)) {
                            bad = true;
                        }
                    }
                    continue;
                }
                path ^= v.s;
                dfs(v.f, u);
                path ^= v.s;
            }
        };
        dfs(x, 0);
        each(t, comp) vis[t] = 0;
        if (bad) base[x] = -1;
        else {
            full_reduce(basis);
            base[x] = get_pos(store, basis);
        } 
    }
    sort(all(direct));
    int sz = sz(direct);
    set<int> rem;
    each(t, direct) {
        rem.insert(t);
    }
    vector<vi> use;
    while (sz(rem)) {
        int x = *rem.begin();
        int ot = -1;
        int w;
        rem.erase(x);
        each(y, adj[x]) {
            if (rem.count(y.f)) {
                ot = y.f;
                w = y.s;
                rem.erase(y.f);
                break;
            }
        }
        vi tmp;
        tmp.pb(0);
        if (ot == -1) {
            if (base[x] != -1) {
                tmp.pb(base[x]);
            }
        } else {
            if (base[x] != -1) {
                tmp.pb(base[x]);
            }
            if (base[ot] != -1) {
                tmp.pb(base[ot]);
            }
            if (base[x] != -1 && base[ot] != -1) {
                int val = head[x] ^ head[ot] ^ w;
                if (val != 0) {
                    int i1 = get_pos(store, {val});
                    int i2 = base[x];
                    int res = comb[i1][i2];
                    if (res != -1) {
                        tmp.pb(res);
                    }
                }
            }
        }
        use.pb(tmp);
    }
    int spaces = sz(store);
    vi dp(spaces);
    vi ndp(spaces);
    dp[0] = 1; 
    each(t, use) {
        each(c, t) {
            f0r(p, spaces) {
                if (comb[c][p] != -1) {
                    madd(ndp[comb[c][p]], dp[p]);
                }
            }
        }
        dp.swap(ndp);
        ndp.assign(spaces, 0);
    }
    int ans = 0;
    each(t, dp) madd(ans, t);
    cout << ans << '\n';
    return 0;
}