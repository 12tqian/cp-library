#pragma once

#include "../data-structures/1d-range-queries/sparse-table.hpp"

struct SuffixArray {
	string s;
	int n;
	vector<int> sa, isa, lcp;
	SparseTable<int> spr;
 
	vector<int> suffix_array(vector<int> st, int upper) {
		int sz = (int)st.size();
		if (sz == 0)
			return {};
		vector<int> res(sz);
		vector<bool> ls(sz);
		for (int i = sz - 2; i >= 0; i--) 
			ls[i] = st[i] == st[i + 1] ? ls[i + 1] : st[i] < st[i + 1];
		vector<int> sum_l(upper), sum_s(upper);
		for (int i = 0; i < sz; i++)
			(ls[i] ? sum_l[st[i] + 1] : sum_s[st[i]])++;
		for (int i = 0; i < upper; i++) {
			if (i)
				sum_l[i] += sum_s[i - 1];
			sum_s[i] += sum_l[i];
		}
		auto induce = [&](const vector<int> &lms) {
			fill(res.begin(), res.end(), -1);
			vector<int> buf = sum_s;
			for (int d : lms) 
				if (d != sz)
					res[buf[st[d]]++] = d;
			buf = sum_l;
			res[buf[st[sz - 1]]++] = sz - 1;
			for (int i = 0; i < sz; i++) {
				int v = res[i] - 1;
				if (v >= 0 && !ls[v])
					res[buf[st[v]]++] = v;
			}
			buf =  sum_l;
			for (int i = sz - 1; i >= 0; i--) {
				int v = res[i] - 1;
				if (v >= 0 && ls[v])
					res[--buf[st[v] + 1]] = v;
			}
		};  
		vector<int> lms_map(sz + 1, -1), lms;
		int m = 0;
		for (int i = 1; i < sz; i++) 
			if (!ls[i - 1] && ls[i])
				lms_map[i] = m++, lms.push_back(i);
		induce(lms);
		vector<int> sorted_lms;
		for (auto& v : res)
			if (lms_map[v] != -1)
				sorted_lms.push_back(v);
		vector<int> rec_s(m);
		int rec_upper = 0;
		for (int i = 1; i < m; i++) {
			int l = sorted_lms[i - 1];
			int r = sorted_lms[i];
			int end_l = lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n;
			int end_r = lms_map[r] + 1 < m ? lms[lms_map[r] + 1] : n;
			bool same = false;
			if (end_l - l == end_r - r) {
				for (; l < end_l && st[l] == st[r]; ++l, ++r);
				if (l != n && st[l] == st[r])
					same = true;
			}
			rec_s[lms_map[sorted_lms[i]]] = (rec_upper += !same);
		}
		vector<int> rec_sa = suffix_array(rec_s, rec_upper
			 + 1);
		for (int i = 0; i < m; i++)
			sorted_lms[i] = lms[rec_sa[i]];
		induce(sorted_lms);
		return res;
	}
	
	void generate_suffix_array(string _s) {
		n = (int)(s = _s).size() + 1;
		vector<int> tmp;
		for (int i = 0; i < (int)s.size(); ++i) {
			tmp.push_back(s[i] - 'a');
		}
		sa = suffix_array(tmp, 26);
	}

	void generate_lcp_array() {
		sa.insert(sa.begin(), -1);
		isa.resize(sa.size());
		for (int i = 1; i < (int)sa.size(); ++i) {
			isa[sa[i]] = i;
		}	
		gen_lcp_array();
		gen_finish();
	}
 
	void gen_lcp_array() {
		lcp = vector<int>(n - 1);
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
		spr.init(lcp);
	}
	
	int get_lcp(int a, int b) {
		if (a == b) {
			return (int)s.size() - a;
		}
		int l = isa[a], r = isa[b]; 
		if (l > r) swap(l, r);
		return spr.query(l, r - 1);
	}
};