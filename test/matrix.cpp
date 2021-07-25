#define IGNORE

#include "../library/contest/template-minimal.hpp"
#include "../library/numerical/matrix.hpp"

// katis
int main() {
	using namespace std;
	using namespace MatrixOperations;
	using Mat = Matrix<long double>;
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		Mat a = make_matrix<long double>(n, n + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i][n];
		}
		auto res = gauss(a);
		vector<long double> ans;
		bool inf = false;
		bool sol = true;
		for (int i = 0; i < n; i++) {  
			bool one = false;
			for (int j = 0; j < n; j++) {
				if (abs(a[i][j] - 1) < EPS) {
					one = true;
					break;
				}
			}
			if (one) {
				ans.push_back(a[i].back());
				continue;
			}
			if (abs(a[i].back()) >= EPS) {
				sol = false;
				break;
			} 
			if (abs(a[i].back()) < EPS) {
				inf = true;
			}
		}
		if (!sol) {
			cout << "inconsistent\n";
		} else if (inf) {
			cout << "multiple\n";
		} else {
			for (auto& t : ans) 
				cout << t << " ";
			cout << '\n';
		}
	}
	return 0;
}