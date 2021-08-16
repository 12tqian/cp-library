#pragma once

// Set to minimums, negate for maximums

template <class T> struct LiChaoTree {
	struct Line {
		T slope, intercept;
		Line(T slope, T intercept) : slope(slope), intercept(intercept) {}
		inline T get(T x) const { return slope * x + intercept; }
		inline bool over(const Line& other, const T& x) {
			return get(x) < other.get(x);
		}
	};

	std::vector<T> xset;
	std::vector<Line> seg;
	int sz;

	LiChaoTree(const std::vector<T>& x) : xset(x) {
		sort(xset.begin(), xset.end());
		xset.erase(unique(xset.begin(), xset.end()), xset.end());
		sz = 1;
		while (sz < (int) xset.size()) sz <<= 1;
		while ((int) xset.size() < sz) xset.push_back(xset.back());
		seg.assign(2 * sz, Line(0, std::numeric_limits<T>::max()));
	}

	int get_more_idx(T k) {
		return lower_bound(xset.begin(), xset.end(), k) - xset.begin();
	}

	int get_less_idx(T k) {
		int ret = upper_bound(xset.begin(), xset.end(), k) - xset.begin();
		return std::max(0, ret - 1);
	}

	void inner_update(T a, T b, int ind, int L, int R) {
		Line line(a, b);
		while (true) {
			int M = (L + R) >> 1;
			bool l_over = line.over(seg[ind], xset[L]);
			bool r_over = line.over(seg[ind], xset[R - 1]);
			if (l_over == r_over) {
				if (l_over) std::swap(seg[ind], line);
				return;
			}
			bool m_over = line.over(seg[ind], xset[M]);
			if (m_over) std::swap(seg[ind], line);
			if (l_over != m_over) 
				ind = (ind << 1), R = M;
			else 
				ind = (ind << 1) | 1, L = M;

		}
	}

	void inner_update(T a, T b, int ind) {
		int L, R;
		int up = 31 - __builtin_clz(ind);
		L = (sz >> up) * (ind - (1 << up));
		R = L + (sz >> up);
		inner_update(a, b, ind, L, R);
	}

	void update(T a, T b) { inner_update(a, b, 1, 0, sz); }

	void update_segment(T a, T b, T lo, T hi) {
		int L = get_more_idx(lo) + sz;
		int R = get_less_idx(hi) + sz + 1;
		for (; L < R; L >>= 1, R >>= 1) {
			if (L & 1) inner_update(a, b, L++);
			if (R & 1) inner_update(a, b, --R);
		}
	}

	T inner_query(T x, int ind) {
		T ret = seg[ind].get(x);
		while (ind > 1) {
			ind = ind >> 1;
			ret = std::min(ret, seg[ind].get(x));
		}
		return ret;
	}

	T query_idx(int k) {
		const T x = xset[k];
		k += sz;
		return inner_query(x, k);
	}
	
	T query(T x) { return query_idx(get_more_idx(x)); }
};