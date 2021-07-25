#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../library/contest/template-minimal.hpp"
#include "../library/misc/easy-io.hpp"
#include "../library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	int n, q;
	cin >> n >> q;
	vector<int> xs, ys;
	dbg(n, q);
	vector<array<int, 3>> pts(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> pts[i][j];
		}
		xs.push_back(pts[i][0]);
		ys.push_back(pts[i][1]);
	}
	vector<array<int, 4>> qs(q);
	for (int i = 0; i < q; ++i) {
		cin >> qs[i][0] >> qs[i][2] >> qs[i][1] >> qs[i][3];
		--qs[i][1];
		--qs[i][3];
		xs.push_back(qs[i][0]);
		xs.push_back(qs[i][1]);
		ys.push_back(qs[i][2]);
		ys.push_back(qs[i][3]);
	}
	auto duplicates = [&](vector<int>& v) {
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
	};
	duplicates(xs);
	duplicates(ys);
	auto get = [&](vector<int> &v, int x) {
		return lower_bound(v.begin(), v.end(), x) - v.begin();
	};	
	Node2D<int> O;
	for (int i = 0; i < n; ++i) {
		O.upd(get(xs, pts[i][0]), get(ys, pts[i][1]), pts[i][2]);
	}
	for (int i = 0; i < q; ++i) {
		cout << O.query(get(xs, qs[i][0]), get(xs, qs[i][1]), get(ys, qs[i][2]), get(ys, qs[i][3])) << '\n';
	}
	return 0;
}