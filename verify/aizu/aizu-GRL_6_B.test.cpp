#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <bits/stdc++.h>
#include "../../library/graphs/flows/min-cost-flow.hpp"

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int v, e, f;
	cin >> v >> e >> f;
	MinCostFlow<long long, long long> mcf;
	mcf.init(v);
	while (e--) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		mcf.ae(u, v, c, d);
	}
	mcf.gen(0, v - 1);
	mcf.max_flow(f);
	if (mcf.cap_flow != f) {
		cout << -1 << '\n';
	} else {
		cout << mcf.dist_flow << '\n';
	}
	return 0;
}