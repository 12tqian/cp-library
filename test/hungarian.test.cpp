#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163"

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/flows/hungarian.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n;
	while (cin >> m >> n, m) {
		vector<int> b(m);
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
		}
		vector<int> r(n);
		for (int i = 0; i < n; ++i) {
			cin >> r[i];
		}
		if (m > n) {
			swap(m, n);
			swap(b, r);
		}
		vector<vector<int>> v(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (gcd(b[i], r[j]) > 1) {
					v[i][j] = -1;
				}
			}
		}
		cout << -hungarian(v).first << '\n';
	}
}

// another instance of use below

// int main() {
// 	using namespace std;
// 	int n; cin >> n;
// 	vector<vector<long long>> a(n, vector<long long>(n));
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++) cin >> a[i][j];
// 	auto res = hungarian(a);
// 	vector<int> loc(n);
// 	for (int i = 0; i < n; i++) {
// 		loc[res.second[i]] = i;
// 	}
// 	cout << res.first << '\n';
// 	for (int x : loc) 
// 		cout << x << " ";
// 	cout << '\n';
// 	return 0;
// }