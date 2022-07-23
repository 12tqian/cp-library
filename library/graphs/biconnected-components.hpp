#pragma once 

#include "low-link.hpp"

template <typename G>
struct BiConnectedComponents : LowLink<G> {
	using LL = LowLink<G>;

	std::vector<int> used;
	std::vector<std::vector<std::pair<int, int>>> bc; // will not include BCC's of size 1!
	std::vector<std::pair<int, int>> tmp;

	BiConnectedComponents(const G& _g) : LL(_g) { build(); }

	void build() {
		used.assign(this->g.size(), 0);
		for (int i = 0; i < (int)used.size(); i++) {
			if (!used[i]) dfs(i, -1);
		}
	}

	void dfs(int idx, int par) {
		used[idx] = true;
		for (auto& to : this->g[idx]) {
			if (to == par) continue;
			if (!used[to] || this->ord[to] < this->ord[idx]) {
				tmp.emplace_back(std::minmax(idx, to));
			}
			if (!used[to]) {
				dfs(to, idx);
				if (this->low[to] >= this->ord[idx]) {
					bc.emplace_back();
					while (true) {
						auto e = tmp.back();
						bc.back().emplace_back(e);
						tmp.pop_back();
						if (e.first == std::min(idx, to) && e.second == std::max(idx, to)) {
							break;
						}
					}
				}
			}
		}
	}
};