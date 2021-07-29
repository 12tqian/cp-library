#pragma once

struct CentroidDecomposition {
	int n;
	std::vector<std::vector<int>> g, cg; // cg is directed tree for centroids
	std::vector<bool> vis;
	std::vector<int> size;
	std::vector<int> parent;
	int root;

	void init(int n_) {
		n = n_;
		g.assign(n, std::vector<int>());
		cg.assign(n, std::vector<int>());
		vis.assign(n, false);
		parent.assign(n, 0);
		size.assign(n, 0);
	}

	void ae(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void dfs_size(int src, int par = -1) {
		size[src] = 1;
		for (int nxt : g[src]) {
			if (nxt == par || vis[nxt]) 
				continue;
			dfs_size(nxt, src);
			size[src] += size[nxt];
		}
	}

	int get_centroid(int src) {
		dfs_size(src);
		int num = size[src];
		int par = -1;
		do {    	
			int go = -1;
			for (int nxt : g[src]) {
				if (nxt == par || vis[nxt])
					continue;
				if (2 * size[nxt] > num) 
					go = nxt;
			}
			par = src;
			src = go;
		} while (src != -1);
		return par;
	}

	int build_dfs(int src, int par = -1) {
		int c = get_centroid(src);
		vis[c] = true;
		parent[c] = par;
		for (int nxt : g[c]) {
			if (vis[nxt]) 
				continue;
			cg[c].push_back(nxt);
			build_dfs(nxt, c);
		}
		return c;
	}

	void build() {
		root = build_dfs(0);
	}
};  
