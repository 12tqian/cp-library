#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/dijkstra.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, m, r;
	cin >> n >> m >> r;
	Dijkstra<long long, true> D;
	D.init(n);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		D.ae(u, v, w);
	}
	D.gen(r);
	for (int i = 0; i < n; ++i) {
		auto dist = D.dist[i];
		if (dist == numeric_limits<long long>::max()) {
			cout << "INF" << '\n';
		} else {
			cout << dist << '\n';
		}
	}
}
