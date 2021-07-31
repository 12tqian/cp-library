#define PROBLEM "https://codeforces.com/contest/981/problem/G"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/affine-segment-tree.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"
#include "../../library/data-structures/1d-range-queries/interval-union.hpp"

using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, q;
	cin >> n >> q;
	vector<IntervalUnion<int>> iu(n);
	AffineSegmentTree<mi> seg;
	seg.init(n);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			--l, --r, --x;
			vector<pair<int, int>> use = iu[x].insert({l, r});
			for (auto &y : use) {
				seg.upd(1, max(l, y.first), min(r, y.second), 2);
			}
			if (!use.empty()) {
				for (int i = 0; i < use.size() + 1; ++i) {
					if (i == 0) {
						seg.upd(0, l, use[i].first - 1, 1);
					} else if (i != use.size()) {
						seg.upd(0, use[i - 1].second + 1, use[i].first - 1, 1);
					} else {
						seg.upd(0, use[i - 1].second + 1, r, 1);
					}
				}
			} else {
				seg.upd(0, l, r, 1);
			}
		} else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			cout << seg.qsum(l, r) << '\n';
		}
	}
	return 0;
}