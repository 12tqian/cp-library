#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"
#include "../../library/data-structures/1d-range-queries/affine-segment-tree.hpp"

using mi = Mint<998244353, 5>;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, q;
	AffineSegmentTree<mi> seg;
	cin >> n >> q;
	seg.init(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		seg.upd(0, i, i, a[i]);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int l, r, b, c;
			cin >> l >> r >> b >> c;
			seg.upd(1, l, r - 1, b);
			seg.upd(0, l, r - 1, c);
		} else {
			int l, r;
			cin >> l >> r;
			cout << seg.qsum(l, r - 1) << '\n';
		}
	}
	return 0;
}