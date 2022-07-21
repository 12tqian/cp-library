#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"
#include "../../library/polynomial/multipoint-evaluation.hpp"


using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<mi> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector<mi> p(m);
	for (int i = 0; i < m; ++i) {
		cin >> p[i];
	}
	Poly<mi> poly(c);
	MultiEval<mi> multi(p);
	auto ans = multi.query(c);
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;	
}