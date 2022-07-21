#pragma once

template <class T> struct Line {
	mutable T k, m, p;
	
	bool operator<(const Line<T>& o) const { return k < o.k; }
	bool operator<(T x) const { return p < x; }
};

template <class T> struct LineContainer : std::multiset<Line<T>, std::less<>> {
	// (for doubles, use INF = 1/.0, div(a,b) = a/b)
	const T INF = std::numeric_limits<T>::max();

	T div(T a, T b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); 
	}

	using super = std::multiset<Line<T>, std::less<>>;
	using iterator = typename LineContainer<T>::iterator;
	
	bool isect(iterator x, iterator y) {
		if (y == super::end()) 
			return x->p = INF, 0;
		if (x->k == y->k) 
			x->p = x->m > y->m ? INF : -INF;
		else 
			x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	
	void add_line(T k, T m) {
		k = -k, m = -m;
		auto z = super::insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) 
			z = super::erase(z);
		if (x != super::begin() && isect(--x, y)) 
			isect(x, y = super::erase(y));
		while ((y = x) != super::begin() && (--x)->p >= y->p)
			isect(x, super::erase(y));
	}
	
	T query(T x) {
		assert(!super::empty());
		auto l = *super::lower_bound(x);
		return -(l.k * x + l.m);
	}
};
