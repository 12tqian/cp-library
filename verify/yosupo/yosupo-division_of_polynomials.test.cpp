#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"
#include "../../library/polynomial/polynomial.hpp"

using mi = Mint<998244353, 5>;

int main() {
	int n, m;
	cin >> n >> m;
	Poly<mi> f(n), g(m);
	for (int i = 0; i < n; ++i) {
		cin >> f[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> g[i];
	}
	auto q = f / g;
	auto r = f - q * g;
	cout << q.size() << ' ' << r.size() << '\n';
	for (auto t : q) {
		cout << t << ' ';
	}
	cout << '\n';
	for (auto t : r) {
		cout << t << ' ';
	}
	cout << '\n';
	return 0;
}