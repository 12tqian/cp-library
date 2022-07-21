#pragma once 

#include <immintrin.h>

struct bit_vector {
	using u32 = uint32_t;
	using i64 = int64_t;
	using u64 = uint64_t;

	static constexpr u32 w = 64;
	std::vector<u64> block;
	std::vector<u32> count;
	u32 n, zeros;

	inline u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u; }
	inline void set(u32 i) { block[i / w] |= 1LL << (i % w); }

	bit_vector() {}
	bit_vector(int _n) { init(_n); }
	__attribute__((optimize("O3,unroll-loops"))) void init(int _n) {
		n = zeros = _n;
		block.resize(n / w + 1, 0);
		count.resize(block.size(), 0);
	}

	__attribute__((target("popcnt"))) void build() {
		for (u32 i = 1; i < block.size(); ++i)
			count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);
		zeros = rank0(n);
	}

	inline u32 rank0(u32 i) const { return i - rank1(i); }

	__attribute__((target("bmi2,popcnt"))) inline u32 rank1(u32 i) const {
		return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));
	}
};

template <typename S, typename T>
struct WaveletMatrix {
	using u32 = uint32_t;
	using i64 = int64_t;
	using u64 = uint64_t;

	struct BIT {
		u32 N;
		std::vector<T> data;

		BIT() = default;
		BIT(int size) { init(size); }

		void init(int size) {
			N = size;
			data.assign(N + 1, 0);
		}

		__attribute__((target("bmi"))) void add(u32 k, T x) {
			for (++k; k <= N; k += _blsi_u32(k)) data[k] += x;
		}

		__attribute__((target("bmi"))) T sum(u32 k) const {
			T ret = T();
			for (; k; k = _blsr_u32(k)) ret += data[k];
			return ret;
		}

		__attribute__((target("bmi"))) T sum(int l, int r) const {
			T ret = T();
			while (l != r) {
				if (l < r) {
					ret += data[r];
					r = _blsr_u32(r);
				} else {
					ret -= data[l];
					l = _blsr_u32(l);
				}
			}
			return ret;
		}
	};

	using P = std::pair<S, S>;
	int n, lg;
	std::vector<bit_vector> bv;
	std::vector<BIT> bit;
	std::vector<P> ps;
	std::vector<S> ys;

	WaveletMatrix() {}

	void add_point(S x, S y) {
		ps.emplace_back(x, y);
		ys.emplace_back(y);
	}

	__attribute__((optimize("O3"))) void build() {
		sort(begin(ps), end(ps));
		ps.erase(unique(begin(ps), end(ps)), end(ps));
		n = ps.size();
		sort(begin(ys), end(ys));
		ys.erase(unique(begin(ys), end(ys)), end(ys));
		std::vector<u32> cur(n), nxt(n);
		for (int i = 0; i < n; ++i) cur[i] = yid(ps[i].second);
		lg = std::__lg(std::max(n, 1)) + 1;
		bv.assign(lg, n);
		bit.assign(lg, n);
		for (int h = lg - 1; h >= 0; --h) {
			for (int i = 0; i < n; ++i)
				if ((cur[i] >> h) & 1) bv[h].set(i);
			bv[h].build();
			std::array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
			for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
			swap(cur, nxt);
		}
	}

	int xid(S x) const {
		return lower_bound(
							 begin(ps), end(ps), std::make_pair(x, S()),
							 [](const P& a, const P& b) { return a.first < b.first; }) -
					 begin(ps);
	}

	int yid(S y) const { return lower_bound(begin(ys), end(ys), y) - begin(ys); }

	void add(S x, S y, T val) {
		int i = lower_bound(begin(ps), end(ps), P{x, y}) - begin(ps);
		for (int h = lg - 1; h >= 0; --h) {
			int i0 = bv[h].rank0(i);
			if (bv[h].get(i))
				i += bv[h].zeros - i0;
			else
				i = i0;
			bit[h].add(i, val);
		}
	}

	T sum(int l, int r, u32 upper) const {
		T res = 0;
		for (int h = lg; h--;) {
			int l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
			if ((upper >> h) & 1) {
				res += bit[h].sum(l0, r0);
				l += bv[h].zeros - l0;
				r += bv[h].zeros - r0;
			} else {
				l = l0, r = r0;
			}
		}
		return res;
	}

	T sum(S lx, S rx, S ly, S ry) const {
		++rx, ++ry;
		int l = xid(lx), r = xid(rx);
		return sum(l, r, yid(ry)) - sum(l, r, yid(ly));
	}
};
