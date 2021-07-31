#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/numerical/matrix2.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"

using mi = Mint<998244353, 5>;

int main() {
	using namespace MatrixOperations;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	auto a = make_matrix<mi>(n, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	auto tmp = a;
	mi det = gauss(tmp).first;
	if (det == 0) {
		cout << -1 << '\n';
	} else {
		auto ans = inv(a);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}