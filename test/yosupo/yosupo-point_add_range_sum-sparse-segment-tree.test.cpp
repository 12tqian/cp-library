#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/sparse-segment-tree.hpp"

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	typedef long long ll;
	int n, q; 
	cin >> n >> q;
	vector<ll> a(n);
	Node<ll> seg;
	for (int i = 0; i < n; i++) 
		cin >> a[i], seg.upd(i, a[i]);
	while (q--) {
		int t; cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			seg.upd(p, x);
		} else {
			int l, r; cin >> l >> r;
			cout << seg.query(l, r - 1) << '\n';
		}
	}
	return 0;
}