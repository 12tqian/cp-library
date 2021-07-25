#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/strongly-connected-components-kosaraju.hpp	"
int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, m; 
	cin >> n >> m;
	SCC S; S.init(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		S.ae(u, v);
	}
	S.gen();
	S.build_scc_graph();
	cout << S.roots.size() << '\n';
	for (auto &c : S.topo_ord) {
		cout << S.comps[c].size() << " ";
		for (auto &x : S.comps[c]) 
			cout << x << " ";
		cout << '\n';
	}
	return 0;
}
