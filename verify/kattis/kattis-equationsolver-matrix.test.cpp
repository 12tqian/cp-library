#define PROBLEM "https://open.kattis.com/problems/equationsolver"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/numerical/matrix.hpp"

// kattis
int main() {
	using namespace std;
	using namespace MatrixOperations;
	using Mat = Matrix<long double>;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		Mat a = make_matrix<long double>(n, n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		vector<long double> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		const long double EPS = 1e-12;
		auto res = solve_linear(a, b, EPS);
		if (res.empty()) {
			cout << "inconsistent\n";
		} else if ((int)res.size() > 1) {
			cout << "multiple\n";
		} else {
			for (auto& t : res[0]) 
				cout << t << " ";
			cout << '\n';
		}
	}
	return 0;
}