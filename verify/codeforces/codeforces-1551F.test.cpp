#define PROBLEM "https://codeforces.com/contest/1551/problem/F"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/numerical/mod-int.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		int n, k;
		cin >> n >> k;
		vector<mi> fact(n + 1);
		vector<mi> ifact(n + 1);
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		ifact[n] = 1 / fact[n];
		for (int i = n - 1; i >= 0; --i) {
			ifact[i] = ifact[i + 1] * (i + 1);
		}
		auto C = [&](int x, int y) {
		};
		vector<vector<int>> g(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (k == 2) {
			cout << n * (n - 1) / 2 << '\n';
			continue;
		}
		mi ans = 0;
		for (int r = 0; r < n; ++r) {
			vector<vector<int>> store(n);
			vector<int> dep(n);
			function<void(int, int, int)> dfs = [&](int u, int p, int s) {
				++store[dep[u]].back();
				for (int v : g[u]) {
					if (v != p) {
						dep[v] = dep[u] + 1;
						dfs(v, u, s);
					}
				}
			};
			for (int u : g[r]) {
				for (int i = 0; i < n; ++i) {
					store[i].push_back(0);
				}
				dep[u] = 1;
				dfs(u, r, u);
			}
			auto comb = [&](vector<mi> a, vector<mi> b) {
				vector<mi> res(a.size() + b.size() - 1);
				for (int i = 0; i < a.size(); ++i) {
					for (int j = 0; j < b.size(); ++j) {
						res[i + j] += a[i] * b[j];
					}
				}
				return res;
			};
			for (int d = 0; d < n; ++d) {
				vector<mi> res = {1};
				for (int x : store[d]) {
					res = comb(res, vector<mi>{1, x});
				}
				if (res.size() > k) {
					ans += res[k];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}