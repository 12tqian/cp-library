#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"

#include <bits/stdc++.h>
#include "../../library/graphs/blossom-matching.hpp"

int main() {
	using namespace std;
	int n, m;
	cin >> n >> m;
	MaxMatching mm;
	mm.init(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		mm.ae(u, v);
	}
	int ans = mm.solve();
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		if (mm.res[i] > i) {
			cout << i << ' ' << mm.res[i] << '\n';
		}
	}
	return 0;
}