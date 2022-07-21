#define PROBLEM "https://www.spoj.com/problems/DYNACON2/"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/offline-dynamic-connectivity.hpp"

int main() {
    using namespace std;
    int n, m; cin >> n >> m;
    OfflineDynamicConnectivity O;
    O.init(n, m + 1);
    set<array<int, 3>> edges;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (s == "add") {
            int u, v; 
            cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            edges.insert({u, v, i});
        } else if (s == "rem") {
            int u, v; 
            cin >> u >> v; 
            u--, v--;
            if (u > v) swap(u, v);
            auto e = *edges.lower_bound({u, v, -1});
            O.upd(e[2], i, {u, v});
            edges.erase(e);
        } else {
            int u, v; 
            cin >> u >> v;
            u--, v--;
            O.add_query(i, u, v);
        }
    }
    for (auto e : edges) {
        O.upd(e[2], m, {e[0], e[1]});
    }
    auto ans = O.solve();
    for (auto x : ans) {
        cout << (x ? "YES" : "NO") << '\n';
    }
    return 0;
}