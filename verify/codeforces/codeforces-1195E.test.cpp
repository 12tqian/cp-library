#define PROBLEM "https://codeforces.com/problemset/problem/1195/E"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/dynamic-programming/min-deque.hpp"
#include "../../library/dynamic-programming/max-deque.hpp"

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	long long g, x, y, z;
	cin >> g >> x >> y >> z;
	vector<vector<int>> grid(n + 1, vector<int>(m + 1));
	vector<vector<int>> row_min(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			grid[i][j] = g;
			g = (g * x + y) % z;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		MinDeque<int> d;
		for (int j = 0; j < b; ++j) {
			d.push_back(grid[i][j]);
		}
		for (int j = 0; j <= m - b; ++j) {
			row_min[i][j] = d.get();
			d.pop_front();
			d.push_back(grid[i][j + b]);
		}
	}
	for (int j = 0; j <= m - b; ++j) {
		MinDeque<int> d;
		for (int i = 0; i < a; ++i) {
			d.push_back(row_min[i][j]);
		}
		for (int i = 0; i <= n - a; ++i) {
			ans += d.get();
			d.pop_front();
			d.push_back(row_min[i + a][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}