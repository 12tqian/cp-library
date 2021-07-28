#define IGNORE

#include "../library/contest/template-minimal.hpp"

/** 
 * Example of use: https://ideone.com/J3R7nb
 * Solves SPOJ DYNACON2
 */

struct DSURollBack {
    std::vector<int> e;
    void init(int n) {
        e = std::vector<int>(n, -1);
    }
    int get(int x) {
        return e[x] < 0 ? x : get(e[x]);
    }
    bool same_set(int a, int b) {
        return get(a) == get(b);
    }
    int size(int x) {
        return -e[get(x)];
    }
    std::vector<std::array<int, 4>> mod;
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) {
            mod.push_back({-1, -1, -1, -1});
            return 0;
        }
        if (e[x] > e[y]) std::swap(x, y);
        mod.push_back({x, y, e[x], e[y]});
        e[x] += e[y], e[y] = x;
        return true;
    }
    void rollback() {
        auto a = mod.back();
        mod.pop_back();
        if (a[0] != -1) {
            e[a[0]] = a[2];
            e[a[1]] = a[3];
        }
    }
};

struct OfflineDynamicConnectivity {
    DSURollBack D;
    int sz;
    std::vector<std::vector<std::pair<int, int>>> seg;
    std::vector<std::vector<std::pair<int, int>>> queries;
    std::vector<int> ans;
    void upd(int l, int r, std::pair<int, int> p) {
        // add edge p from time [l, r]
        for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) seg[l++].push_back(p);
            if (r & 1) seg[--r].push_back(p);
        }
    }
    void process(int ind) {
        for (auto& t : seg[ind]) {
            D.unite(t.first, t.second);
        }
        if (ind >= sz) {
            // Process the queries at time ti
            // Do stuff with D
            int ti = ind - sz; 
            for (auto& qq : queries[ti]) {
                ans.push_back(D.same_set(qq.first, qq.second));
            }
        } else {
            process(2 * ind); process(2 * ind + 1);
        }
        for (auto& t : seg[ind]) {
            D.rollback();
        }
    }
    void add_query(int ti, int u, int v) {
        queries[ti].emplace_back(u, v);
    }
    void init(int max_time) {
        sz = 1;
        while (sz < max_time) sz *= 2;
        seg.assign(2 * sz, {});
        queries.assign(sz, {});
        D.init(2 * sz);
    }
    std::vector<int> solve() {
        process(1);
        return ans;
    }
};

int main() {
    using namespace std;
    int n, m; cin >> n >> m;
    OfflineDynamicConnectivity O;
    O.init(m + 1);
    set<array<int, 3>> edges;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (s == "add") {
            int u, v; cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            edges.insert({u, v, i});
        } else if (s == "rem") {
            int u, v; cin >> u >> v; 
            u--, v--;
            if (u > v) swap(u, v);
            auto e = *edges.lower_bound({u, v, -1});
            O.upd(e[2], i, {u, v});
            edges.erase(e);
        } else {
            int u, v; cin >> u >> v;
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