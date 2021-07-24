#pragma once

/**
 * Another black box algorithm I don't understand
 * But I can use 
 * O(N^2M) for N jobs and M workers 
 * 0-indexed
 * Returns the cost, and the assignment
 * job stores the job each worker gets assigned to
 * In the example below, they wanted the worker each job got assigned to, so I inverted it
 */

template <class C> std::pair<C, std::vector<int>> hungarian(const std::vector<std::vector<C>>& a_) {
	const C INF = std::numeric_limits<C>::max();
	int n = (int)a_.size();
	int m = (int)a_[0].size();
	assert(n <= m);
	std::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i + 1][j + 1] = a_[i][j];
	std::vector<C> u(n + 1), v(m + 1);
	std::vector<int> job(m + 1);
	for (int i = 1; i <= n; i++) {
		int w = 0;
		job[w] = i;
		std::vector<C> dist(m + 1, INF);
		std::vector<int> pre(m + 1, -1);
		std::vector<bool> done(m + 1);
		while (job[w]) {
			done[w] = 1;
			int j = job[w], nxt;
			C delta = INF;
			for (int ww = 0; ww <= m; ww++) {
				if (!done[ww]) {
					if (dist[ww] > a[j][ww] - u[j] - v[ww]) {
						dist[ww] = a[j][ww] - u[j] - v[ww];
						pre[ww] = w; 
					}
					if (delta > dist[ww]) {
						delta = dist[ww];
						nxt = ww;
					}
				}
			}
			for (int ww = 0; ww <= m; ww++) {
				if (done[ww]) {
					u[job[ww]] += delta;
					v[ww] -= delta;
				} else {
					dist[ww] -= delta;
				}
			}
			w = nxt;
		}
		for (int ww; w; w = ww) 
			job[w] = job[ww = pre[w]];
	}
	job.erase(job.begin());
	for (int i = 0; i < m; i++)
		job[i]--;
	return {-v[0], job};
}

int main() {
	using namespace std;
	int n; cin >> n;
	vector<vector<long long>> a(n, vector<long long>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> a[i][j];
	auto res = hungarian(a);
	vector<int> loc(n);
	for (int i = 0; i < n; i++) {
		loc[res.second[i]] = i;
	}
	cout << res.first << '\n';
	for (int x : loc) 
		cout << x << " ";
	cout << '\n';
	return 0;
}