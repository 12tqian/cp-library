#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/polynomial/polynomial.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"

using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<mi> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	Poly<mi> p(a);
	auto ans = p.exp(n);
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;	
}