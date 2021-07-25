#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/biconnected-components.hpp"

int main() {
	using namespace std;
	ios_base::sync_with_stdio(0);
	int n, m; 
	cin >> n >> m;
	BCC B; B.init(n);
	for (int i = 0; i < m ;i++) {
		int u, v; cin >> u >> v;
		B.ae(u, v);
	}
	B.build();
	cout << B.num_comps << '\n';
	for (int i = 0; i < B.num_comps; i++) {
		cout << (int)B.comps[i].size() << " ";
		for (int v : B.comps[i]) 
			cout << v << " ";
		cout << '\n';
	}
}