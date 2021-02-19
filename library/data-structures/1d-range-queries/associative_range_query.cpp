#include <bits/stdc++.h>

template <class T> struct RangeQuery {
    int sz; 
    std::vector<std::vector<T>> st;
    T id = 0;
    std::vector<T> a;

    T comb(T a, T b) { return a + b; }  

    void fill(int l, int r, int ind) {
        if (ind < 0) return;
        int m = (l + r) >> 1;
        T prod = id;
        for (int i = m - 1; i >= l; i--) 
            st[i][ind] = prod = comb(a[i], prod);
        prod = id;
        for (int i = m; i < r; i++) 
            st[i][ind] = prod = comb(prod, a[i]);
        fill(l, m, ind - 1);
        fill(m, r, ind - 1);
    }

    void init(std::vector<T> a_) {
        a = a_;
        sz = 1;
        while ((1 << sz) < (int)a.size()) sz++;
        st = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));
        a.resize(1 << sz);
        fill(0, (1 << sz), sz - 1);
    }

    T query(int l, int r) {
        if (l == r) return a[l];
        int t = 31 - __builtin_clz(r ^ l);
        return comb(st[l][t], st[r][t]);
    }
};

int main() {
    using namespace std;
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    RangeQuery<long long> R; 
    R.init(a);
    while (q--) {
        int l, r; cin >> l >> r;
        r--;
        cout << R.query(l, r) << '\n';

    }
    return 0;
}