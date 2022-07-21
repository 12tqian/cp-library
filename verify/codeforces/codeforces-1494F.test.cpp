#define PROBLEM "https://codeforces.com/contest/1494/problem/F"

#include "../../library/contest/template-short.hpp"
#include "../../library/graphs/dsu.hpp"
#include "../../library/graphs/euler-path.hpp"

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<vi> g(n);
	vpi ed;
	f0r(i, m) {
		int u, v; cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.eb(u, v);
	}
	int odd = 0;
	f0r(i, n) odd += (sz(g[i]) % 2 == 1);
	DSU D; 
	auto finish = [&](int c, vi bad) {
		vi mark(n);
		each(x, bad) mark[x] = 1;
		vector<vi> ng(n);
		Euler<false> E; E.init(n);
		f0r(i, n) {
			each(j, g[i]) {
				if (i == c && mark[j]) continue;
				if (mark[i] && j == c) continue;
				if (i < j) E.ae(i, j);
			}
		}
		auto path = E.get_path(c);
		vi res;
		each(x, bad) {
			res.pb(c);
			res.pb(x);
		}
		res.pb(-1);
		each(e, path) {
			res.pb(e.f);
		}
		reverse(all(res));
		cout << sz(res) << '\n';
		each(x, res) {
			if (x < 0) cout << x << " ";
			else cout << x + 1 << " ";
		}
		cout << '\n';
		exit(0);
	};
	auto check = [&](int c) {
		D.init(n);
		each(e, ed) {
			if (e.f == c || e.s == c) continue;
			D.unite(e.f, e.s);
		}
		vector<vi> lead(n);
		each(v, g[c]) {
			lead[D.get(v)].pb(v);
		}
		{ // center is even
			vi bad;
			bool ok = true;
			f0r(i, n) {
				if (sz(lead[i]) == 0) continue;
				int cnt = 0;
				each(j, lead[i]) {
					if (sz(g[j]) % 2 == 1) {
						cnt++;  
						bad.pb(j);
					}
				}
				if (cnt == sz(lead[i]) && D.size(i) > 1) {
					ok = false;
					break;
				}
			}
			int num_odd = odd;
			if (sz(bad) % 2 == 1) {
				if (sz(g[c]) % 2 == 1) num_odd--;
				else num_odd++;
			}
			num_odd -= sz(bad);
			if (ok && num_odd == 0) { // delete everything in bad
				finish(c, bad);
			}
		}
		{ // center is odd
			vi bad;
			vi all_done(n);
			int num = 0;
			f0r(i, n) {
				if (sz(lead[i]) == 0) continue;
				int cnt = 0;
				each(j, lead[i]) {
					
					if (sz(g[j]) % 2 == 1) {
						cnt++;
						bad.pb(j);
					}
				}
				if (cnt == sz(lead[i]) && D.size(i) > 1) {
					all_done[i] = 1;
					num++;
				}
			}
			int num_odd = odd;
			if (sz(bad) % 2 == 1) {
				if (sz(g[c]) % 2 == 1) num_odd--;
				else num_odd++;
			}
			num_odd -= sz(bad);
			if (num <= 1 && num_odd == 0) { // check if one of bad can be not used
				each(x, bad) {
					if (num) {
						if (all_done[D.get(x)]) { // delete everything in bad except for this
							vi nbad;
							each(y, bad) {
								if (y == x) continue;
								nbad.pb(y);
							}
							finish(c, nbad);
						}
					} else { // delete everything in bad except for this
						finish(c, bad);
					}
				}
			} else if (num_odd == 2 && num == 0) {
				if (sz(bad) % 2 != sz(g[c]) % 2) {
					finish(c, bad);
				}
			}
		}
	};
	Euler<false> E; E.init(n);
	f0r(i, n) { 
		each(j, g[i]) {
			if (j < i) E.ae(i, j);
		}
	}
	auto res = E.euler_path();
	if (sz(res)) {
		cout << sz(res) << '\n';
		each(e, res) cout << e.f + 1 << " ";
		cout << '\n';
		exit(0);
	}
	f0r(i, n) check(i);
	cout << 0 << '\n';
	return 0;
}