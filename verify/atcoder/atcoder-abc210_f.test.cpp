#define PROBLEM "https://atcoder.jp/contests/abc210/tasks/abc210_f"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/two-sat.hpp"
#include "../../library/number-theory/fast-factor-sieve.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const int V = 2e6 + 5;
	Sieve<V> sieve;
	vector<vector<int>> primes(V);
	int n;
	cin >> n;
	vector<array<int, 2>> v(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> v[i][j];
			auto f = sieve.factor(v[i][j]);
			for (auto [p, e] : f) {
				primes[p].push_back(j == 0 ? i : ~i);
			}
		}
	}
	TwoSat two_sat;
	two_sat.init(n);
	for (auto& v : primes) {
		two_sat.at_most_one(v);
	}
	auto ans = two_sat.solve();
	if (ans.empty()) {
		cout << "No";
	} else {
		cout << "Yes";
	}
	cout << '\n';
	return 0;
}


