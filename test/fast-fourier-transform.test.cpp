#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../library/contest/template-minimal.hpp"
#include "../library/numerical/fast-fourier-transform.hpp"

int main() {
	using namespace std;
	using namespace FFT;
	ios_base::sync_with_stdio(0);
	int n, m; 
	cin >> n >> m;
	const int MOD = 1e9 + 7;
	using mi = Mint<MOD, 5>;
	vector<mi> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	vector<mi> c = general_multiply(a, b);
	for (int i = 0; i < (int)c.size(); i++)
		cout << c[i] << " ";
	cout << '\n';
}