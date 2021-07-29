#define PROBLEM "https://codeforces.com/contest/1553/problem/G"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/number-theory/fast-factor-sieve.hpp"
#include "../../library/graphs/dsu.hpp"
#include "../../library/misc/fast-hash-map.hpp"
#include "../../library/misc/fast-input.hpp"

const int N = 1e6 + 5;
const int B = 600;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Sieve<N> sieve;
	int n = read_int();
	int q = read_int();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = read_int();
	}
	vector<int> head(N, -1);
	DSU dsu;
	dsu.init(n);
	for (int i = 0; i < n; ++i) {
		auto f = sieve.factor(a[i]);
		for (auto [p, e] : f) {
			if (head[p] == -1) {
				head[p] = i;
			} else {
				dsu.unite(head[p], i);
			}
		}
	}
	vector<vector<int>> in(n);
	for (int i = 0; i < n; ++i) {
		auto f1 = sieve.factor(a[i] + 1);
		auto f2 = sieve.factor(a[i]);
		reverse(f1.begin(), f1.end());
		reverse(f2.begin(), f2.end());
		vector<int> f;
		while (!f1.empty() || !f2.empty()) {
			if (f1.empty()) {
				f.push_back(f2.back().first);
				f2.pop_back(); 
			} else if (f2.empty()) {
				f.push_back(f1.back().first);
				f1.pop_back();
			} else {
				if (f1.back().first == f2.back().first) {
					f1.pop_back();
				} else if (f1.back().first < f2.back().first) {
					f.push_back(f1.back().first);
					f1.pop_back();
				} else {
					f.push_back(f2.back().first);
					f2.pop_back();
				}
			}
		}
		vector<int> join;
		for (int p : f) {
			if (head[p] == -1) {
				continue;
			}
			join.push_back(dsu.get(head[p]));
		}
		sort(join.begin(), join.end());
		join.resize(unique(join.begin(), join.end()) - join.begin());
		for (int x : join) {
			in[x].push_back(i);
		}
	}
	vector<hash_set<int>> check(n);
	for (int i = 0; i < n; ++i) {
		for (int j : in[i]) {
			check[i].insert(j);
		}
	}
	vector<int> ans(q, 2);
	vector<bool> big(n);
	vector<int> big_sets;
	for (int i = 0; i < n; ++i) {
		if (in[i].size() >= B) {
			big[i] = true;
			big_sets.push_back(i);
		} else {
			big[i] = false;
		}
	}
	vector<vector<int>> table(n);
	for (int i : big_sets) {
		for (int j : in[i]) {
			table[j].push_back(i);
		}
	}
	set<array<int, 2>> good_pairs;
	for (vector<int> v : table) {
		for (int i : v) {
			for (int j : v) {
				if (i < j) {
					good_pairs.insert({i, j});
				}
			}
		}
	}
	auto overlap = [&](int u, int v) {
		if (u > v) {
			swap(u, v);
		}
		if (big[u] && big[v]) {
			if (good_pairs.count({u, v})) {
				return true;
			} else {
				return false;
			}
		}
		if (in[u].size() > in[v].size()) {
			swap(u, v);
		}
		for (int x : in[u]) {
			if (check[v].find(x) != check[v].end()) {
				return true;
			}
		}
		return false;
	};
	for (int qq = 0; qq < q; ++qq) {
		int s = read_int();
		int t = read_int();
		--s, --t;
		if (dsu.same_set(s, t)) {
			ans[qq] = 0;
		} else {
			int u = dsu.get(s);	
			int v = dsu.get(t);
			if (overlap(u, v)) {
				ans[qq] = 1;
			} else {
				ans[qq] = 2;
			}
		}
	}
	for (int qq = 0; qq < q; ++qq) {
		cout << ans[qq] << '\n';
	}
	return 0;
}

