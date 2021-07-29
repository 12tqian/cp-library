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
	function<vi(int)> dfs = [&](int u) { // return how many at dist x
		vi verts;
		vector<vl> polys;
		polys.pb({1});
		vl tmp;
		each(v, cd.cg[u]) {	
			auto res = dfs(v);
			each(x, res) verts.pb(x);
			tmp.assign(res.size() + 1, 0);
			each(x, res) {
				++tmp[lca.dist(x, u)];
			}
			while (tmp.back() == 0) tmp.pop_back();
			polys.pb(tmp);
		}	
		vl sum;
		each(x, polys) sum += x;
		vl res = sum * sum;
		each(x, polys) res -= x * x;
		res /= 2;
		f0r(i, sz(res)) {
			ans[i] += res[i];
		}
		verts.pb(u);
		return verts;
	};
	dfs(cd.root);
	f1r(i, 1, n) {
		pr(ans[i], ' ');
	}
	ps();
	return 0;
}