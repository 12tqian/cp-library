#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/flows/hungarian.hpp"

int main() {
	int n; cin >> n;
	vector<vector<long long>> a(n, vector<long long>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> a[i][j];
	auto res = hungarian(a);
	vector<int> loc(n);
	for (int i = 0; i < n; i++) {
		loc[res.second[i]] = i;
	}
	cout << res.first << '\n';
	for (int x : loc) 
		cout << x << " ";
	cout << '\n';
	return 0;
}