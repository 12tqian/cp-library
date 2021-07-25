#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../library/contest/template-minimal.hpp"
#include "../library/numerical/karatsuba.hpp"

int main() {
	const int MOD = 1e9 + 7;
	using namespace Karatsuba;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int sa, sb;
	cin >> sa >> sb;
	vector<long long> a(sa);
	for (int i = 0; i < sa; i++)
		cin >> a[i];
	vector<long long> b(sb);
	for (int i = 0; i < sb; i++)
		cin >> b[i];
	vector<long long> c = convolution<long long>(a, b);
	for (int i = 0; i < (int)c.size(); i++)
		cout << c[i] % MOD << " ";
	cout << '\n';
	return 0;
}