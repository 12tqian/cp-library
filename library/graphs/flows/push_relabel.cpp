#include <bits/stdc++.h>

/**
 * Treat this as a black box xD
 * Calculates max flow
 * You can probably add stuff to recover it
 * Most cases, Dinic is better since you understand it
 */

template <class F> struct PushRelabel {

    struct Edge { int to, rev; F flow; };

    const F INF = std::numeric_limits<F>::max();  

    int n, s, t, highest, work;
    std::vector<std::vector<Edge>> adj;
    std::vector<std::vector<int>> lst, gap;
    std::vector<int> height, cnt;
    std::vector<F> excess;

    void init(int n_) {
        n = n_;
        adj.clear(); adj.resize(2 * n);
        lst.clear(); lst.resize(2 * n);
        gap.clear(); gap.resize(2 * n);
        height.assign(2 * n, 0);
        cnt.assign(2 * n, 0);
        excess.assign(2 * n, 0);
        work = highest = 0;
        s = 0;
        t = n - 1;
    }

    void ae(int u, int v, F cap) {
        assert(cap >= 0);
        Edge a{v, (int)adj[v].size(), cap};
        Edge b{u, (int)adj[u].size(), 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    void update_height(int v, int nh) {
        work++;
        if (height[v] != n)
            cnt[height[v]]--;
        height[v] = nh;
        if (nh == n)
            return;
        cnt[nh]++;
        highest = nh;
        gap[nh].push_back(v);
        if (excess[v] > 0)
            lst[nh].push_back(v);
    }

    void global_relabel() {
        work = 0;
        for (int i = 0; i < n; i++)
            height[i] = n, cnt[i] = 0;
        for (int i = 0; i < highest; i++) 
            lst[i].clear(), gap[i].clear();
        height[t] = 0;
        std::queue<int> q({t});
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : adj[v]) 
                if (height[e.to] == n && adj[e.to][e.rev].flow > 0)
                    q.push(e.to), update_height(e.to, height[v] + 1);
            highest = height[v];
        }
    }

    void push(int v, Edge& e) {
        if (excess[e.to] == 0)
            lst[height[e.to]].push_back(e.to);
        F df = std::min(excess[v], e.flow);
        e.flow -= df, adj[e.to][e.rev].flow += df;
        excess[v] -= df, excess[e.to] += df;
    }

    void discharge(int v) {
        int nh = n;
        for (auto& e : adj[v]) 
            if (e.flow > 0)
                if (height[v] == height[e.to] + 1) {
                    push(v, e);
                    if (excess[v] <= 0)
                        return;
                } else {
                    nh = std::min(nh, height[e.to] + 1);
                }
        if (cnt[height[v]] > 1) 
            update_height(v, nh);
        else {
            for (int i = height[v]; i <= highest; i++) {
                for (auto& j : gap[i])
                    update_height(j, n);
                gap[i].clear();
            }
        }
    }
    
    F max_flow(int s_, int t_) {
        s = s_, t = t_;
        if (s == t)
            return -1;
        for (int i = 0; i < n; i++)
            excess[i] = 0;
        excess[s] = INF, excess[t] = -INF;
        global_relabel();
        for (auto& e : adj[s]) 
            push(s, e);
        for (; highest >= 0; highest--)
            while (!lst[highest].empty()) {
                int v = lst[highest].back();
                lst[highest].pop_back();
                discharge(v);
                if (work > 4 * n)
                    global_relabel();
            }
        return excess[t] + INF;
    }
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    PushRelabel<long long> P;
    P.init(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        P.ae(u, v, w);
        P.ae(v, u, w);
    }
    cout << P.max_flow(0, n - 1) << '\n';
    return 0;
}
