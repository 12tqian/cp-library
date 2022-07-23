#pragma once

template <typename G>
struct LowLink {
	int N;
	const G& g;
	std::vector<int> ord, low, articulation;
	std::vector<std::pair<int, int>> bridge;

	LowLink(const G& _g) : g(_g) {
		N = (int)g.size();
		ord.resize(N, -1);
		low.resize(N, -1);
		int k = 0;
		for (int i = 0; i < N; i++)
			if (ord[i] == -1) k = dfs(i, k, -1);
	}

	int dfs(int idx, int k, int par) {
		low[idx] = (ord[idx] = k++);
		int cnt = 0;
		bool is_arti = false, flg = false;
		for (auto &to : g[idx]) {
			if (ord[to] == -1) {
				cnt++;
				k = dfs(to, k, idx);
				low[idx] = std::min(low[idx], low[to]);
				is_arti |= (par != -1) && (low[to] >= ord[idx]);
				if (ord[idx] < low[to]) {
					bridge.emplace_back(std::minmax(idx, (int)to));
				}
			} else if (to != par || std::exchange(flg, true)) {
				low[idx] = std::min(low[idx], ord[to]);
			}
		}
		is_arti |= par == -1 && cnt > 1;
		if (is_arti) articulation.push_back(idx);
		return k;
	}
};