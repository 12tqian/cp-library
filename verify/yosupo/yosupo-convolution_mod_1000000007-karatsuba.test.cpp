#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/numerical/karatsuba.hpp"
#include "../../library/numerical/mod-int2.hpp"

int main() {
	const int MOD = 1e9 + 7;
	using mi = Mint<MOD, 5>;
	using namespace Karatsuba;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int sa, sb;
	cin >> sa >> sb;
	vector<mi> a(sa);
	for (int i = 0; i < sa; i++)
		cin >> a[i];
	vector<mi> b(sb);
	for (int i = 0; i < sb; i++)
		cin >> b[i];
	vector<mi> c = convolution<mi>(a, b);
	for (int i = 0; i < (int)c.size(); i++)
		cout << c[i] << " ";
	cout << '\n';
	return 0;
}