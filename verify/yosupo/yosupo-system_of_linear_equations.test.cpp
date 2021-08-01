#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <bits/stdc++.h>
#include "../../library/numerical/matrix.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"

using mi = Mint<998244353, 5>;

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	using namespace MatrixOperations;
	int n, m;
	cin >> n >> m;
	Matrix<mi> a = make_matrix<mi>(n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	vector<mi> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	auto ans = solve_linear(a, b);
	if (ans.empty()) {
		cout << -1 << '\n';
	} else {
		cout << (int)ans.size() - 1 << '\n';	
		for (auto x : ans) {
			for (auto y : x) cout << y << ' ';
			cout << '\n';
		}
	}
	return 0;
}