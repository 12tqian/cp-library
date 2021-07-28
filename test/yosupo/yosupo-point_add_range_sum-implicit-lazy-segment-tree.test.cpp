#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, q; 
	cin >> n >> q;
	SegmentTree<long long> *seg = new SegmentTree<long long>(0, n - 1);
	for (int i = 0; i < n; ++i) {
		int a; 
		cin >> a;
		seg->update(i, i, a, 0, n - 1);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {  
			int p, x; 
			cin >> p >> x;
			seg->update(p, p, x, 0, n - 1);
		} else {
			int l, r; 
			cin >> l >> r;
			--r;
			cout << seg->query(l, r, 0, n - 1) << '\n';
		}
	}
	return 0;
}