#pragma once

const int MOD = 998244353;

int main() {
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
	int n, m; std::cin >> n >> m;
	std::vector<long long> x(n);
	for (int i = 0; i < n; i++) std::cin >> x[i];
	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std::vector<int> vert(n);
	std::vector<bool> good(n);
	std::vector<bool> done(n);
	iota(vert.begin(), vert.end(), 0);
	sort(vert.begin(), vert.end(), [&](int i, int j) { return adj[i].size() < adj[j].size(); });
	int ans = 0;
	for (int u : vert) {
		done[u] = true;
		for (int v : adj[u]) good[v] = true;
		for (int v : adj[u]) {
			if (done[v]) {
				for (int w : adj[v]) {
					if (!good[w]) continue;
					long long add = (x[u] * x[v]) % MOD;
					add = (add * x[w]) % MOD;
					ans += add;
					if (ans >= MOD) ans -= MOD;
				}
			}
		}
		for (int v: adj[u]) good[v] = false;
	}
	auto mod_pow = [&](long long base, long long exp) -> long long {
		long long res = 1;
		while (exp) {
			if (exp & 1) {
				res *= base;
				res %= MOD;
			}
			base *= base;
			base %= MOD;
			exp >>= 1;
		}
		return res;
	};
	ans = (mod_pow(3, MOD - 2) * ans) % MOD;
	std::cout << ans << '\n';
	return 0;
}
