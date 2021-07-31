#pragma once

#include "polynomial.hpp"

template <class Mint> struct MultiEval {
	using NP = MultiEval*;
	NP l, r;
	std::vector<Mint> que;
	int sz;
	Poly<Mint> mul;

	MultiEval(const std::vector<Mint>& _que, int off, int _sz) : sz(_sz) {
		if (sz <= 100) {
			que = {_que.begin() + off, _que.begin() + off + sz};
			mul = {{1}};
			for (auto x : que) mul *= {{-x, 1}};
			return;
		}
		l = new MultiEval(_que, off, sz / 2);
		r = new MultiEval(_que, off + sz / 2, sz - sz / 2);
		mul = l->mul * r->mul;
	}

	MultiEval(const std::vector<Mint>& _que) : MultiEval(_que, 0, int(_que.size())) {}

	void query(const Poly<Mint>& _pol, std::vector<Mint>& res) const {
		if (sz <= 100) {
			for (auto x : que) {
				Mint sm = 0, base = 1;
				for (int i = 0; i < _pol.size(); i++) {
					sm += base * _pol.freq(i);
					base *= x;
				}
				res.push_back(sm);
			}
			return;
		}
		auto pol = _pol % mul;
		l->query(pol, res);
		r->query(pol, res);
	}
	
	std::vector<Mint> query(const Poly<Mint>& pol) const {
		std::vector<Mint> res;
		query(pol, res);
		return res;
	}
};
