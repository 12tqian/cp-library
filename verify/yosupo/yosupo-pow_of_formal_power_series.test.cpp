#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/numerical/polynomial.hpp"
#include "../../library/numerical/mod-int2.hpp"

using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	vector<mi> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	Poly<mi> p(a);
	auto b = p;
	Poly<mi> ans({1});
	while (m) {
		if (m & 1) {
			ans *= b;
			ans.resize(n);
		}
		b *= b;
		b.resize(n);
		m >>= 1;
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;	
}