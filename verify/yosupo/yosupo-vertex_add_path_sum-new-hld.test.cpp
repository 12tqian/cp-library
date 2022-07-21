#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/heavy-light-decomposition.hpp"
#include "../../library/data-structures/1d-range-queries/general-full-segment-tree.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(false);
	int n, q;
	struct Node {
		long long v;
		int size;
		
		Node() : v(0), size(1) {}
		Node(long long _v, int _size) : v(_v), size(_size) {}
	};
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	HeavyLightDecomposition H(graph);
	auto seg = get_lazy_segment_tree(
		vector<Node>(n),
		Node(), 0LL,
		[&](Node x, Node y) { return Node{x.v + y.v, x.size + y.size}; },
		[&](Node x, long long y) { return Node{x.v + y * x.size, x.size}; },
		[&](long long x, long long y) { return x + y; }
	);
	for (int i = 0; i < n; i++)
		H.path_query(i, i, true, [&](int l, int r) {
			seg.add(l, r, a[i]);
		});
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			H.path_query(p, p, true, [&](int l, int r) {
				seg.add(l, r, x);
			});
		} else	{
			int u, v;
			cin >> u >> v;
			long long ans = 0;
			H.path_query(u, v, true, [&](int l, int r) {
				ans += seg.sum(l, r).v;
			});
			cout << ans << '\n';
		}
	}
	return 0;
}
