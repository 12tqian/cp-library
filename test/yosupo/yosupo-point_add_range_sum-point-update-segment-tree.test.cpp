#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/point-update-segment-tree.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, q; 
	cin >> n >> q;
	vector<long long> a(n);
	SegmentTree<long long> seg; 
	seg.init(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i], seg.add(i, a[i]);
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			seg.add(p, x);
		} else {
			int l, r;
			cin >> l >> r;
			--r;
			cout << seg.query(l, r) << '\n';
		}
	}
	return 0;
}