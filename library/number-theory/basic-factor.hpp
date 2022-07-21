#pragma once

namespace FactorBasic {

template <class T> std::vector<std::pair<T, int>> factor(T x) {
	std::vector<std::pair<T, int>> pri;
	for (T i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			int t = 0;
			while (x % i == 0) x /= i, t++;
			pri.push_back({i, t});
		}
	}
	if (x > 1) pri.push_back({x, 1});
	return pri;
}

template <class T> T phi(T x) {
	for (auto& a : factor(x)) x -= x / a.first;
	return x;
}

template <class T> void tour(std::vector<std::pair<T, int>>& v, std::vector<T>& res, int ind, T cur) {
	if (ind == (int)v.size()) res.push_back(cur);
	else {
		T mul = 1;
		for (int i = 0; i < v[ind].second + 1; i++) {
			tour(v, res, ind + 1, cur * mul);
			mul *= v[ind].first;
		}
	}
}

template <class T> std::vector<T> get_divisor(T x) {
	auto v = factor(x);
	std::vector<T> res; 
	tour(v, res, 0, (T) 1);
	sort(res.begin(), res.end());
	return res;
}

}