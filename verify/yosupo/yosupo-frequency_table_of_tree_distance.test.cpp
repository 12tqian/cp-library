#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../../library/contest/template-full.hpp"
#include "../../library/graphs/centroid-decomposition.hpp"
#include "../../library/graphs/lca-rmq.hpp"
#include "../../library/numerical/fast-fourier-transform.hpp"
#include "../../library/numerical/polynomial.hpp"

int main() {
	using namespace FFT;
	using namespace Polynomial;
	setIO("");
	int n;
	re(n);
	CentroidDecomposition cd;
	cd.init(n);
	LCARMQ lca;
	lca.init(n);
	vector<vi> g(n);
	f0r(i, n - 1) {
		int u, v;
		re(u, v);
		g[u].pb(v);
		g[v].pb(u);
		lca.ae(u, v);
		cd.ae(u, v);
	}
	lca.gen();
	cd.build();
	vl ans(n);
	function<vl(int)> dfs = [&](int u) { // return how many at dist x
		vector<vl> polys;
		polys.pb({1});
		dbg(u);
		each(v, cd.cg[u]) {	
			auto res = dfs(v);
			res.insert(res.begin(), 0);
			polys.pb(res);
		}	
		vl sum;
		each(x, polys) sum += x;
		vl res = sum * sum;
		each(x, polys) res -= x * x;
		res /= 2;
		f0r(i, sz(res)) {
			ans[i] += res[i];
		}
		return sum;
	};
	dfs(cd.root);
	f1r(i, 1, n) {
		pr(ans[i], ' ');
	}
	ps();
	return 0;
}