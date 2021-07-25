#define IGNORE

#include "../library/contest/template-minimal.hpp"
#include "../library/numerical/simplex.hpp"

// kattis cheese
int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; 
	cin >> n >> m;
	vector<vector<double>> A(n, vector<double>(m));
	vector<double> c(m);
	vector<double> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> A[j][i];
			A[j][i] /= 100;
		}
		cin >> c[i];
	}
	vector<double> x; 
	double ans = Simplex<double>(A, b, c).solve(x);
	cout << fixed << setprecision(2) << ans << '\n';
	return 0;
}