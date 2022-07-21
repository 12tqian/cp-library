#pragma once

template <class D, class L, class OpDD, class OpDL, class OpLL> struct LazySegmentTree {
	D e_d;
	L e_l;
	OpDD op_dd; 
	OpDL op_dl;
	OpLL op_ll;
	int sz, lg;  
	std::vector<D> d;
	std::vector<L> lz;

	void init(const std::vector<D>& v) {
		int n = int(v.size());
		lg = 1;
		while ((1 << lg) < n) lg++;
		sz = 1 << lg;
		d = std::vector<D>(2 * sz, e_d);
		lz = std::vector<L>(2 * sz, e_l);
		for (int i = 0; i < n; i++) d[sz + i] = v[i];
		for (int i = sz - 1; i >= 0; i--) {
			update(i);
		}
	}

	LazySegmentTree(const std::vector<D>& v,
			D _e_d,
			L _e_l,
			OpDD _op_dd,
			OpDL _op_dl,
			OpLL _op_ll)
		: e_d(_e_d), e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl), op_ll(_op_ll) {
		init(v);
	}

	void all_add(int k, L x) {
		d[k] = op_dl(d[k], x);
		if (k < sz) lz[k] = op_ll(lz[k], x);
	}

	void push(int k) {
		all_add(2 * k, lz[k]);
		all_add(2 * k + 1, lz[k]);
		lz[k] = e_l;
	}

	void update(int k) { d[k] = op_dd(d[2 * k], d[2 * k + 1]); }

	void set(int p, D x) {
		p += sz;
		for (int i = lg; i >= 1; i--) push(p >> i);
		d[p] = x;
		for (int i = 1; i <= lg; i++) update(p >> i);
	}

	void add(int a, int b, L x, int l, int r, int k) {
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			all_add(k, x);
			return;
		}
		push(k);
		int mid = (l + r) / 2;
		add(a, b, x, l, mid, 2 * k);
		add(a, b, x, mid, r, 2 * k + 1);
		update(k);
	}

	void add(int a, int b, L x) {
		++b;
		a += sz;
		b += sz;
		for (int i = lg; i >= 1; i--) {
			if (((a >> i) << i) != a) push(a >> i);
			if (((b >> i) << i) != b) push((b - 1) >> i);
		}
		{
			int a2 = a, b2 = b;
			while (a < b) {
				if (a & 1) all_add(a++, x);
				if (b & 1) all_add(--b, x);
				a >>= 1;
				b >>= 1;
			}
			a = a2;
			b = b2;
		}
		for (int i = 1; i <= lg; i++) {
			if (((a >> i) << i) != a) update(a >> i);
			if (((b >> i) << i) != b) update((b - 1) >> i);
		}
	}

	D single(int p) {
		p += sz;
		for (int i = lg; i >= 1; i--) push(p >> i);
		return d[p];
	}

	D sum(int a, int b, int l, int r, int k) {
		if (b <= l || r <= a) return e_d;
		if (a <= l && r <= b) return d[k];
		push(k);
		int mid = (l + r) / 2;
		return op_dd(sum(a, b, l, mid, 2 * k), sum(a, b, mid, r, 2 * k + 1));
	}

	D sum(int a, int b) {
		++b;
		if (a == b) return e_d;
		a += sz;
		b += sz;
		for (int i = lg; i >= 1; i--) {
			if (((a >> i) << i) != a) push(a >> i);
			if (((b >> i) << i) != b) push((b - 1) >> i);
		}
		D sml = e_d, smr = e_d;
		while (a < b) {
			if (a & 1) sml = op_dd(sml, d[a++]);
			if (b & 1) smr = op_dd(d[--b], smr);
			a >>= 1;
			b >>= 1;
		}
		return op_dd(sml, smr);
	}

	D all_sum() const { return d[1]; }
};

template <class D, class L, class OpDD, class OpDL, class OpLL>
LazySegmentTree<D, L, OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D> v,
										D e_d,
										L e_l,
										OpDD op_dd,
										OpDL op_dl,
										OpLL op_ll) {
	return LazySegmentTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl, op_ll);
}
