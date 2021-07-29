#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/range-set-segment-tree.hpp"

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<long long> a(n);
	RangeSetSeg<long long> seg; 
	seg.init(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i], seg.range_set(i, i, a[i]);
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			seg.range_set(p, p, x + seg.qsum(p, p));
		} else {
			int l, r;
			cin >> l >> r;
			--r;
			cout << seg.qsum(l, r) << '\n';
		}
	}
	return 0;
}