#pragma once

struct MaxMatching {
	int n;
	std::vector<std::vector<int>> adj;
	std::vector<int> mate, first, res;
	std::vector<bool> white;
	std::vector<std::pair<int, int>> label;

	void init(int _n) {
		n = _n;
		adj = std::vector<std::vector<int>>(n + 1);
		mate = first = std::vector<int>(n + 1);
		label = std::vector<std::pair<int, int>>(n + 1);
		white = std::vector<bool>(n + 1);
		res = std::vector<int>(n, -1);
	}

	void ae(int u, int v) { 
		++u, ++v;
		adj.at(u).push_back(v), adj.at(v).push_back(u); 
	}

	int group(int x) {
		if (white[first[x]]) first[x] = group(first[x]);
		return first[x];
	}

	void match(int p, int b) {
		std::swap(b, mate[p]);
		if (mate[b] != p) return;
		if (!label[p].second)
			mate[b] = label[p].first, match(label[p].first, b);	 // vertex label
		else
			match(label[p].first, label[p].second), match(label[p].second, label[p].first);	 // edge label
	}

	bool augment(int st) {
		assert(st);
		white[st] = 1;
		first[st] = 0;
		label[st] = {0, 0};
		std::queue<int> q;
		q.push(st);
		while (!q.empty()) {
			int a = q.front();
			q.pop();	// outer vertex
			for (auto& b : adj[a]) {
				assert(b);
				if (white[b]) {	 // two outer vertices, form blossom
					int x = group(a), y = group(b), lca = 0;
					while (x || y) {
						if (y) std::swap(x, y);
						if (label[x] == std::pair<int, int>{a, b}) {
							lca = x;
							break;
						}
						label[x] = {a, b};
						x = group(label[mate[x]].first);
					}
					for (int v : {group(a), group(b)})
						while (v != lca) {
							assert(!white[v]);	// make everything along path white
							q.push(v);
							white[v] = true;
							first[v] = lca;
							v = group(label[mate[v]].first);
						}
				} else if (!mate[b]) {	// found augmenting path
					mate[b] = a;
					match(a, b);
					white = std::vector<bool>(n + 1);	// reset
					return true;
				} else if (!white[mate[b]]) {
					white[mate[b]] = true;
					first[mate[b]] = b;
					label[b] = {0, 0};
					label[mate[b]] = std::pair<int, int>{a, 0};
					q.push(mate[b]);
				}
			}
		}
		return false;
	}

	int solve() {
		int ans = 0;
		for (int st = 1; st <= n; ++st) {
			if (!mate[st]) {
				ans += augment(st);
			}
		}
		for (int st = 1; st <= n; ++st) {
			if (!mate[st] && !white[st]) {
				assert(!augment(st));
			}
		}
		for (int i = 1; i <= n; ++i) {
			res[i - 1] = mate[i] - 1;
		}
		return ans;
	}
};
