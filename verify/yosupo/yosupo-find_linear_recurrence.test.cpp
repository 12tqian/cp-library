#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"
#include "../../library/polynomial/berlekamp-massey.hpp"

using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<mi> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	auto b = berlekamp_massey<mi>(a);
	cout << (int)b.size() - 1 << '\n';
	for (int i = 1; i < (int)b.size(); ++i) {
		cout << b[i] << ' ';
	}
	cout << '\n';
	return 0;
}