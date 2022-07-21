#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/segment-tree-beats.hpp"

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q; cin >> n >> q;
	SegmentTreeBeats<long long> S;
	S.init(n);
	std::vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i], S.upd(2, i, i, a[i]);
	while (q--) {
		int t, l, r; cin >> t >> l >> r;
		r--;
		if (t <= 2) {
			long long b; cin >> b;
			S.upd(t, l, r, b);
		} else {
			cout << S.qsum(l, r) << '\n';
		}
	}
}