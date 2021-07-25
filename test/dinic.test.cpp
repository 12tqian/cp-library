#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/flows/dinic.hpp"

int main() {
	using namespace std;
	ios_base::sync_with_stdio(0);
	int L, R; cin >> L >> R;
	int M; cin >> M;
	Dinic<int> D;
	D.init(L + R + 2);
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		int x = u + 1;
		int y = L + v + 1;
		D.ae(x, y, 1);
	}
	for (int i = 1; i <= L; i++) 
		D.ae(0, i, 1);
	for (int i = L + 1; i <= L + R; i++) 
		D.ae(i, L + R + 1, 1);
	cout << D.max_flow(0, L + R + 1) << '\n';
	for (int i = 1; i <= L; i++) {
		for (auto& eid : D.adj[i]) {
			if (eid & 1)
				continue;
			auto& e = D.edges[eid];
			if (e.cap == e.flow) {
				int u = i - 1;
				int v = e.to - L - 1;
				cout << u << " " << v << '\n';
			}
		}
	}
	return 0;
}