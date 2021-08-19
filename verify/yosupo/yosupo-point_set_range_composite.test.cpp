#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/general-full-segment-tree.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"
#include "../../library/math/affine.hpp"

using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	const Affine<mi> ID = {1, 0};
	auto comb = [&](Affine<mi> x, Affine<mi> y) {
		return x * y;
	};
	vector<Affine<mi>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].a >> v[i].b;
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
			cout << res(x) << '\n';
		}
	}
	return 0;
}