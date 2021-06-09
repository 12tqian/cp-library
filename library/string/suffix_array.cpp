#include <bits/stdc++.h>

/**
 * sa stores sorted suffixes
 * isa is inverse of sa
 * lcp is longest common prefix between consecutive elements
 * Indexing has been fixed so that everything is 0-indexed by the end
 */

template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<int>> jump;

	int level(int x) {
		return 31 - __builtin_clz(x);
	}

	int comb(int a, int b) {
		return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);
	}

	void init(const std::vector<T>& _v) {
		v = _v;
		jump = {std::vector<int>((int)v.size())};
		iota(jump[0].begin(), jump[0].end(), 0);
		for (int j = 1; (1 << j) <= (int)v.size(); j++) {
			jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
			for (int i = 0; i < (int)jump[j].size(); i++) {
				jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	int index(int l, int r) {
		assert(l <= r);
		int d = level(r - l + 1);
		return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
	}

	T query(int l, int r) {
		return v[index(l, r)];
	}
};

struct SuffixArray {
	std::string s;
	int n;
	std::vector<int> sa, isa, lcp;
	SparseTable<int> S;

	void init(std::string _s) {
		n = (int)(s = _s).size() + 1;
		gen_suffix_array();
		gen_lcp_array();
		gen_finish();
	}

	void gen_suffix_array() {
		sa = isa = std::vector<int>(n);
		sa[0] = n - 1;
		iota(1 + sa.begin(), sa.end(), 0);
		sort(1 + sa.begin(), sa.end(), [&](int a, int b) {
			return s[a] < s[b];
		});
		for (int i = 1; i < n; i++) {
			int a = sa[i - 1], b = sa[i];
			isa[b] = i > 1 && s[a] == s[b] ? isa[a] : i;
		}
		for (int len = 1; len < n; len *= 2) {
			std::vector<int> ss(sa), is(isa), pos(n);
			iota(pos.begin(), pos.end(), 0);
			for (auto& t : ss) {
				int tt = t - len;
				if (tt >= 0) 
					sa[pos[isa[tt]]++] = tt;
			}
			for (int i = 1; i < n; i++) {
				int a = sa[i - 1], b = sa[i];
				isa[b] = is[a] == is[b] && is[a + len] == is[b + len] ? isa[a] : i;
			}
		}
	}

	void gen_lcp_array() {
		lcp = std::vector<int>(n - 1);
		int h = 0;
		for (int b = 0; b < n - 1; b++) {
			int a = sa[isa[b] - 1];
			while (a + h < (int)s.size() && s[a + h] == s[b + h]) 
				h++;
			lcp[isa[b] - 1] = h;
			if (h) h--;
		}
	}

	void gen_finish() {
		lcp.erase(lcp.begin());
		sa.erase(sa.begin());
		for (int i = 0; i < (int)isa.size(); i++) 
			isa[i]--;
		n--; 
		isa.pop_back();
		S.init(lcp);
	}
	
	int get_lcp(int a, int b) {
		if (a == b) {
			return (int)s.size() - a;
		}
		int l = isa[a], r = isa[b]; 
		if (l > r) std::swap(l, r);
		return S.query(l, r - 1);
	}
};
 
int main() {
	using namespace std;
	ios_base::sync_with_stdio(0);
	string s; cin >> s;
	int n = (int)s.size();
	SuffixArray S;
	S.init(s);
	for (int i = 0; i < n; i++)
		cout << S.sa[i] << " ";
	cout << '\n';
	return 0;
}