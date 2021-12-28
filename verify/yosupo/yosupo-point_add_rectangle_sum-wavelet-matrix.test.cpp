#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/2d-range-queries/wavelet-matrix.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	WaveletMatrix<int, long long> wm;
	vector<int> x(n), y(n), w(n), c(q), s(q), t(q), u(q), v(q);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> w[i];
		wm.add_point(x[i], y[i]);
	}
	for (int i = 0; i < q; ++i) { 
		cin >> c[i] >> s[i] >> t[i] >> u[i];
		if (c[i]) {
			cin >> v[i];
		} else {
			wm.add_point(s[i], t[i]);
		}
	}
	wm.build();
	for (int i = 0; i < n; ++i) {
		wm.add(x[i], y[i], w[i]);
	}
	for (int i = 0; i < q; ++i) {
		if (c[i]) {
			cout << wm.sum(s[i], u[i] - 1, t[i], v[i] - 1) << '\n';
		} else {
			wm.add(s[i], t[i], u[i]);
		}
	}
	return 0;
}