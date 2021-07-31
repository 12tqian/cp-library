#pragma once

template <class D, class Op> struct SegmentTree {
	D e;
	Op op;
	int n, sz, lg;  
	std::vector<D> d;

	SegmentTree(const std::vector<D>& v, D _e, Op _op) : e(_e), op(_op) {
		n = int(v.size());
		lg = 1;
		while ((1 << lg) < n) lg++;
		sz = 1 << lg;
		d = std::vector<D>(2 * sz, e);
		for (int i = 0; i < n; i++) d[sz + i] = v[i];
		for (int i = sz - 1; i >= 0; i--) {
			update(i);
		}
	}

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

	void set(int p, D x) {
		assert(0 <= p && p < n);
		p += sz;
		d[p] = x;
		for (int i = 1; i <= lg; i++) update(p >> i);
	}

	D single(int p) const {
		assert(0 <= p && p < n);
		return d[p + sz];
	}

	D all_sum() const { return d[1]; }
	
	D sum(int a, int b) const {
		++b;
		assert(a <= b);
		D sml = e, smr = e;
		a += sz;
		b += sz;
		while (a < b) {
			if (a & 1) sml = op(sml, d[a++]);
			if (b & 1) smr = op(d[--b], smr);
			a >>= 1;
			b >>= 1;
		}
		return op(sml, smr);
	}


	// min i s.t. f(d[a] + d[a+1] + ... d[i]) == true (or return n + 1)
	template <class Comp> int search_left(int a, Comp f) {
		a += sz;
		D sm = e;
		if (f(e)) return a;
		while (true) {
			if (f(op(sm, d[a]))) {
				while (a < sz) {
					a *= 2;
					if (!f(op(sm, d[a]))) {
						sm = op(sm, d[a]);
						a++;
					}
				}
				a = a + 1 - sz;
				return a;
			}
			if (a & 1) {
				sm = op(sm, d[a]);
				a++;
				if ((a & -a) == a) break;
			}
			a >>= 1;
		}
		return n + 1;
	}
};

template <class D, class Op>
SegmentTree<D, Op> get_segment_tree(std::vector<D> v, D e, Op op) {
	return SegmentTree<D, Op>(v, e, op);
}
