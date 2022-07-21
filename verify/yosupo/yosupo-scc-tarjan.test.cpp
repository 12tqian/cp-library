#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/strongly-connected-components-tarjan.hpp"

int main() {
	using namespace std;
	int n, m; cin >> n >> m;
	SCC S;
	S.init(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		S.ae(u, v);
	}
	S.build();
	cout << S.num_comps << '\n';
	for (auto &comp : S.comps) {
		cout << (int)comp.size() << " ";
		for (int &x : comp)
			cout << x << " ";
		cout << '\n';
	}
	return 0;
}