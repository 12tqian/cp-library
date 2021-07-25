#define IGNORE

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/bellman-ford.hpp"

// kattis
int main() {
	using namespace std;
	while (true) {
		int n, m, q, s; cin >> n >> m >> q >> s;
		if (n == 0)
			exit(0);
		BellmanFord<long long> B;
		B.init(n);
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			B.ae(u, v, w);
		}
		B.gen(s);
		while (q--) {
			int x; cin >> x;
			long long dist = B.dist[x];
			if (dist == B.INF) 
				cout << "Impossible\n";
			else if (dist == -B.INF)
				cout << "-Infinity\n";
			else 
				cout << B.dist[x] << '\n';
		}
	}
	return 0;
}