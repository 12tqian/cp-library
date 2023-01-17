#define PROBLEM "https://www.spoj.com/problems/DYNACON2/"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/online-dynamic-connectivity.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	LayerStructure layer(n + 1, m + 1);
	while (m--) {
		string s;
		cin >> s;
		int u, v;
		cin >> u >> v;
		if (s == "add") {
			layer.link(u, v);
		} else if (s == "conn") {
			string ans = layer.connected(u, v) ? "YES" : "NO";
			cout << ans << '\n';
		} else {
			layer.cut(u, v);
		}
	}
	return 0;
}