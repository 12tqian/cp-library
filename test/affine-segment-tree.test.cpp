#include <bits/stdc++.h>

#include "../library/data-structures/1d-range-queries/affine-segment-tree.hpp"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    AffineSeg<mi, (1 << 19)> seg;
    seg.init();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seg.upd(i, i, 0, a[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.upd(l, r - 1, 1, b);
            seg.upd(l, r - 1, 0, c);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.qsum(l, r - 1) << '\n';
        }
    }
    return 0;
}