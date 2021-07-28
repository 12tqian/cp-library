#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/flows/dinic.hpp"

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	Dinic<long long> P;
	P.init(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; 
		cin >> u >> v >> w;
		P.ae(u, v, w);
	}
	cout << P.max_flow(0, n - 1) << '\n';
	return 0;
}
