#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/general-simple-segment-tree.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, q; 
	cin >> n >> q;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	auto seg = get_segment_tree(a, 0LL, [&](long long x, long long y) { return x + y; });
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
			cout << seg.sum(l, r) << '\n';
		}
	}
	return 0;
}