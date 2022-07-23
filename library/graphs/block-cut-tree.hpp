#pragma once

#include "biconnected-components.hpp"

template <typename G>
struct BlockCutTree {
	const G& g;
	BiConnectedComponents<G> bcc;
	std::vector<std::vector<int>> aux;
	std::vector<int> idar, idcc;

	BlockCutTree(const G& _g) : g(_g), bcc(g) { build(); }

	void build() {
		auto ar = bcc.articulation;
		idar.resize(g.size(), -1);
		idcc.resize(g.size(), -1);
		for (int i = 0; i < (int)ar.size(); i++) idar[ar[i]] = i;

		aux.resize(ar.size() + bcc.bc.size());
		std::vector<int> last(g.size(), -1);
		for (int i = 0; i < (int)bcc.bc.size(); i++) {
			std::vector<int> st;
			for (auto& [u, v] : bcc.bc[i]) st.push_back(u), st.push_back(v);
			for (auto& u : st) {
				if (idar[u] == -1)
					idcc[u] = i + (int)ar.size();
				else if (last[u] != i) {
					add(i + (int)ar.size(), idar[u]);
					last[u] = i;
				}
			}
		}
	}

	std::vector<int>& operator[](int i) { return aux[i]; }

	int size() const { return (int)aux.size(); }

	int id(int i) { return idar[i] == -1 ? idcc[i] : idar[i]; }

	bool is_arti(int i) { return idar[i] != -1; }

	int arti() const { return bcc.articulation.size(); }

private:
	void add(int i, int j) {
		if (i == -1 or j == -1) return;
		aux[i].push_back(j);
		aux[j].push_back(i);
	};
};