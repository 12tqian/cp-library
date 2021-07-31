#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/general-full-segment-tree.hpp"
#include "../../library/numerical/mod-int2.hpp"

using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	const array<mi, 2> ID = {1, 0};
	auto comb = [&](array<mi, 2> x, array<mi, 2> y) {
		return array<mi, 2>{x[0] * y[0], x[1] * y[0] + y[1]};
	};
	vector<array<mi, 2>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1];
	}
	auto seg = get_lazy_segment_tree(
		v, ID, ID, comb, comb, comb
	);
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, c, d;
			cin >> p >> c >> d;
			seg.set(p, {c, d});
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			--r;
			auto res = seg.sum(l, r);
			mi ans = res[0] * x + res[1];
			cout << ans << '\n';
		}
	}
	return 0;
}