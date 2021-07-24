#include <bits/stdc++.h>

/**
 * 0 is ckmin, 1 is ckmax, 2 is range add
 */
template <class C> struct SegmentTreeBeats {
	using T = std::pair<std::pair<C, C>, int>;
	const C INF = std::numeric_limits<C>::max();
	std::vector<C> mx_mod, mn_mod, mod, sum;
	std::vector<T> mx, mn;
	int sz; 

	void init(int sz_) {
		sz = 1; 
		while (sz < sz_) sz *= 2;
		mx_mod.assign(2 * sz, 0);
		mn_mod.assign(2 * sz, 0);
		mod.assign(2 * sz, 0);
		sum.assign(2 * sz, 0);
		mx.assign(2 * sz, {{0, 0}, 0});
		mn.assign(2 * sz, {{0, 0}, 0});
		build();
	}

	void build(int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		mx_mod[ind] = INF, mn_mod[ind] = -INF, mod[ind] = 0;
		if (L == R) {
			mx[ind] = {{0, -INF}, 1};
			mn[ind] = {{0, INF}, 1};
			sum[ind] = 0;
			return;
		}
		int M = (L + R) / 2;
		build(2 * ind, L, M); build(2 * ind + 1, M + 1, R);
		pull(ind);
	}

	T comb_mn(T a, T b) {
		if (a > b) 
			std::swap(a, b);
		if (a.first.first == b.first.first) 
			return  {{a.first.first, 
				std::min(a.first.second, b.first.second)}, 
				a.second + b.second};
		return {{a.first.first, std::min(a.first.second, b.first.first)}, a.second};
	}

	T comb_mx(T a, T b) {
		if (a < b) std::swap(a, b);
		if (a.first.first == b.first.first) 
			return  {{a.first.first, 
				std::max(a.first.second, b.first.second)}, 
				a.second + b.second};
		return {{a.first.first, std::max(a.first.second, b.first.first)}, 
			a.second};
	}

	void pull(int ind) {
		sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
		mn[ind] = comb_mn(mn[2 * ind], mn[2 * ind + 1]);
		mx[ind] = comb_mx(mx[2 * ind], mx[2 * ind + 1]);
	}

	void push(int ind, int L, int R) {
		auto chk = [](C &a, C b, C c) {
			if (a == b)
				a = c;
		};
		if (mn_mod[ind] != -INF) {
			if (mn_mod[ind] > mn[ind].first.first) {
				sum[ind] += (mn_mod[ind] - mn[ind].first.first) * mn[ind].second;
				chk(mx[ind].first.first, mn[ind].first.first, mn_mod[ind]);
				chk(mx[ind].first.second, mn[ind].first.first, mn_mod[ind]);
				mn[ind].first.first = mn_mod[ind];
				if (L != R) {
					for (int i = 0; i < 2; i++) {
						int pos = 2 * ind + i;
						mn_mod[pos] = std::max(mn_mod[pos], mn_mod[ind] - mod[pos]);
						mx_mod[pos] = std::max(mx_mod[pos], mn_mod[pos]);
					}
				}
			}
			mn_mod[ind] = -INF;
		}
		if (mx_mod[ind] != INF) {
			if (mx_mod[ind] < mx[ind].first.first) {
				sum[ind] += (mx_mod[ind] - mx[ind].first.first) * mx[ind].second;
				chk(mn[ind].first.first, mx[ind].first.first, mx_mod[ind]);
				chk(mn[ind].first.second, mx[ind].first.first, mx_mod[ind]);
				mx[ind].first.first = mx_mod[ind];
				if (L != R) {
					for (int i = 0; i < 2; i++) {
						int pos = 2 * ind + i;
						mx_mod[pos] = std::min(mx_mod[pos], mx_mod[ind] - mod[pos]);
						mn_mod[pos] = std::min(mn_mod[pos], mx_mod[pos]);
					}
				}
			}
			mx_mod[ind] = INF;
		}
		if (mod[ind] != 0) {
			sum[ind] += mod[ind] * (R - L + 1);
			auto inc = [&](T &a, C b) {
				if (std::abs(a.first.first) != INF) 
					a.first.first += b;
				if (std::abs(a.first.second) != INF)
					a.first.second += b;
			};
			inc(mx[ind], mod[ind]); inc(mn[ind], mod[ind]);
			if (L != R) {
				for (int i = 0; i < 2; i++) {
					int pos = 2 * ind + i;
					mod[pos] += mod[ind];
				}
			}
			mod[ind] = 0;
		}
	}

	C qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (R < lo || hi < L)
			return 0;
		if (lo <= L && R <= hi)     
			return sum[ind];
		int M = (L + R) / 2;
		return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
	}

	C qmax(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (R < lo || hi < L)
			return -INF;
		if (lo <= L && R <= hi)     
			return mx[ind].first.first;
		int M = (L + R) / 2;
		return std::max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind + 1, M + 1, R));
	}

	C qmin(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (R < lo || hi < L)
			return INF;
		if (lo <= L && R <= hi)     
			return mn[ind].first.first;
		int M = (L + R) / 2;
		return std::min(qmin(lo, hi, 2 * ind, L, M), qmin(lo, hi, 2 * ind + 1, M + 1, R));
	}
	
	void upd(int t, int lo, int hi, C b, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (R < lo || hi < L) 
			return;
		if (t == 0) 
			if (b >= mx[ind].first.first)
				return;
		else if (t == 1)
			if (b <= mn[ind].first.first)
				return;
		if (lo <= L && R <= hi) {
			if (t == 0) {
				if (b  > mx[ind].first.second) {
					mx_mod[ind] = b;
					push(ind, L, R);
					return;
				}
			} else if (t == 1) {
				if (b < mn[ind].first.second) {
					mn_mod[ind] = b;
					push(ind, L, R);
					return;
				}
			} else if (t == 2) {
				mod[ind] = b;
				push(ind, L, R);
				return;
			} else assert(false);
		}
		assert(L != R);
		int M = (L + R) / 2;
		upd(t, lo, hi, b, 2 * ind, L, M); upd(t, lo, hi, b, 2 * ind + 1, M + 1, R);
		pull(ind);
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(0);
	int n, q; cin >> n >> q;
	SegmentTreeBeats<long long> S;
	S.init(n);
	std::vector<long long> a(n);
	for (int i = 0; i < n; i++)
	   
		cin >> a[i], S.upd(2, i, i, a[i]);
	while (q--) {
		int t, l, r; cin >> t >> l >> r;
		r--;
		if (t <= 2) {
			long long b; cin >> b;
			S.upd(t, l, r, b);
		} else {
			cout << S.qsum(l, r) << '\n';
		}
	}
}