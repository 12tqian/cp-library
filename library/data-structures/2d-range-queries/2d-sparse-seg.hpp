#pragma once

// bump allocator

static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const int SZ = (1 << 17);

template <class T> struct Node {
	T val = 0; 
	Node<T> *c[2];
	Node() { c[0] = c[1] = NULL; }

	void upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v
		if (L == ind && R == ind) { val += v; return; }
		int M = (L + R) / 2;
		if (ind <= M) {
			if (!c[0]) c[0] = new Node();
			c[0]->upd(ind, v, L, M);
		} else {
			if (!c[1]) c[1] = new Node();
			c[1]->upd(ind, v, M + 1, R);
		}
		val = 0; 
		for (int i = 0; i < 2; i++)
			if (c[i]) val += c[i]->val;
	}

	T query(int lo, int hi, int L = 0, int R = SZ - 1) { // query sum of segment
		if (hi < L || R < lo) return 0;
		if (lo <= L && R <= hi) return val;
		int M = (L + R) / 2; 
		T res = 0;
		if (c[0]) res += c[0]->query(lo, hi, L, M);
		if (c[1]) res += c[1]->query(lo, hi, M + 1, R);
		return res;
	}

	void update_2d(int ind, Node *c0, Node *c1, int L = 0, int R = SZ - 1) { // for 2D segtree
		if (L != R) {
			int M = (L + R) / 2;
			if (ind <= M) {
				if (!c[0]) c[0] = new Node();
				c[0]->update_2d(ind, (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL), L, M);
			} else {
				if (!c[1]) c[1] = new Node();
				c[1]->update_2d(ind, (c0 ? c0->c[1] : NULL), (c1 ? c1->c[1] : NULL), M + 1, R);
			}
		} 
		val = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);
	}
};

template <class T> struct Node2D {
	Node<T> seg; 
	Node2D *c[2];

	Node2D() { c[0] = c[1] = NULL; }

	void upd(int x, int y, T v, int L = 0, int R = SZ - 1) { // add v
		if (L == x && R == x) { seg.upd(y, v); return; }
		int M = (L + R) / 2;
		if (x <= M) {
			if (!c[0]) c[0] = new Node2D();
			c[0]->upd(x, y, v, L, M);
		} else {
			if (!c[1]) c[1] = new Node2D();
			c[1]->upd(x, y, v, M + 1, R);
		}
		seg.upd(y, v); // only for addition
		// seg.update_2d(y, (c[0] ? & c[0]->seg : NULL), (c[1] ? & c[1]->seg : NULL));
	}

	T query(int x1, int x2, int y1, int y2, int L = 0, int R = SZ - 1) { // query sum of rectangle
		if (x1 <= L && R <= x2) return seg.query(y1, y2);
		if (x2 < L || R < x1) return 0;
		int M = (L + R) / 2; 
		T res = 0;
		if (c[0]) res += c[0]->query(x1, x2, y1, y2, L, M);
		if (c[1]) res += c[1]->query(x1, x2, y1, y2, M + 1, R);
		return res;
	}
};
