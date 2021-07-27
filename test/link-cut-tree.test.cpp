#define IGNORE "https://dmoj.ca/problem/ds5"

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/link-cut-tree.hpp"


/**
 * Benq's code made without macros and nicer
 * Does everything a link cut tree could possibly want to
 */

// // dmoj dynamic tree test
int main() {
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
	int n, m, root;
	std::cin >> n >> m;
	std::vector<sn> lct(n);
	std::vector<std::pair<int, int>> ed(n - 1);
	for (int i = 0; i < n - 1; i++) {
		std::cin >> ed[i].first >> ed[i].second;
	}
	for (int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		lct[i] = new snode(i, x);
	}
	for (int i = 0; i < n - 1; i++) {
		int x = ed[i].first, y = ed[i].second;
		link(lct[x], lct[y]);
	}
	std::cin >> root;
	while (m--) {
		int k; std::cin >> k;
		if (k == 0 || k == 5) {
			int x, y; std::cin >> x >> y;
			lct[root]->make_root();
			lct[x]->access();
			auto c = lct[x]->c[4];
			if (k == 0) { // set weights in subtree of x to y
				if (c) c->prop(), c->next_num[0] = c->next_num[1] = y;
				lct[x]->val = y;

			} else { // add y to subtree of x vertices
				if (c) c->prop(), c->lazy[0] = c->lazy[1] = y;
				lct[x]->val += y;
			}
			lct[x]->calc();
		} else if (k == 1) { // change root
			int x; std::cin >> x;
			root = x;
		} else if (k == 2 || k == 6) {
			int x, y, z; std::cin >> x >> y >> z;
			lct[x]->make_root();
			if (k == 2) { // sets path x to y to weight z
				lct[y]->access();
				lct[y]->next_num[0] = z;
			}
			else { // add z to vertices on path from x to y
				lct[y]->access();
				lct[y]->lazy[0] = z;
			}
		} else if (k == 3 || k == 4 || k == 11) {
			int x; std::cin >> x;
			lct[root]->make_root();
			lct[x]->access();
			auto ans = info(lct[x]->val);
			sn c = lct[x]->c[4];
			if (c) c->prop(), ans += c->data[0], ans += c->data[1];
			if (k == 3) std::cout << ans.mn << '\n'; // x subtree min
			else if (k == 4) std::cout << ans.mx << '\n'; // x subtree max
			else if (k == 11) std::cout << ans.sum << '\n'; // x subtree sum
		} else if (k == 7 || k == 8 || k == 10) {
			int x, y;
			std::cin >> x >> y;
			lct[x]->make_root();
			lct[y]->access();
			auto ans = lct[y]->data[0];
			if (k == 7) std::cout << ans.mn << '\n'; // x, y path min
			else if (k == 8) std::cout << ans.mx << '\n'; // x, y path max
			else std::cout << ans.sum << '\n'; // x, y path sum
		} else if (k == 9) { // change parent of x to y
			int x, y;
			std::cin >> x >> y;
			lct[root]->make_root();
			if (lca(lct[x], lct[y]) == lct[x]) {
				continue;
			}
			cut(get_par(lct[x]), lct[x]);
			link(lct[x], lct[y]);
		} else exit(5);
	}
	return 0;
}
