#define PROBLEM "https://open.kattis.com/problems/mincostmaxflow"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/flows/min-cost-max-flow.hpp"

int main() {
	using namespace std;
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	MCMF<int, int> M;
	M.init(n);
	for (int i = 0; i < m; i++) {
		int u, v, c, w;
		cin >> u >> v >> c >> w;
		M.ae(u, v, c, w);
	}
	auto res = M.calc(s, t);
	cout << res.first << " " << res.second << '\n';
	return 0;
}