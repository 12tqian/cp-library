#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/bellman-ford.hpp"

// kattis
int main() {
	using namespace std;
	int n, m, r;
	cin >> n >> m >> r;
	BellmanFord<long long> B;
	B.init(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; 
		cin >> u >> v >> w;
		B.ae(u, v, w);
	}
	B.gen(r);
	for (int i = 0; i < n; ++i) {
		if (B.dist[i] == -B.INF) {
			cout << "NEGATIVE CYCLE" << '\n';
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		long long dist = B.dist[i];
		if (dist == B.INF) 
			cout << "INF\n";
		else if (dist == -B.INF)
			assert(false);
		else 
			cout << dist << '\n';
	}
	return 0;
}