#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/lazy-segment-tree.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, q; 
	cin >> n >> q;
	LazySeg<long long> seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		seg.upd(i, i, x);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			seg.upd(p, p, x);
		} else {
			int l, r;
			cin >> l >> r;
			--r;
			cout << seg.qsum(l, r) << '\n';
		}
	}
	return 0;
}