#pragma once

#include "point.hpp"

namespace ConvexHull {

template <class T>
std::pair<std::vector<int>, std::vector<int>> upper_lower_hull(const std::vector<Point<T>> &v) {
	std::vector<int> p((int)v.size()), upper, lower;
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&v](int a, int b) { return v[a] < v[b]; });
	for (int &i : p) {
		while ((int)upper.size() > 1 && 
			area(v[upper[(int)upper.size() - 2]], v[upper.back()], v[i]) >= 0) 
			upper.pop_back();
		upper.push_back(i);
		while ((int)lower.size() > 1 && 
			area(v[lower[(int)lower.size() - 2]], v[lower.back()], v[i]) <= 0) 
			lower.pop_back();
		lower.push_back(i);
	}
	return {upper, lower};
}

template <class T> std::vector<int> hull_index(const std::vector<Point<T>> &v) {
	std::vector<int> upper, lower;
	tie(upper, lower) = upper_lower_hull(v);
	if ((int)lower.size() <= 1) 
		return lower;
	if (v[lower[0]] == v[lower[1]])
		return {0};
	lower.insert(lower.end(), 1 + upper.rbegin(), upper.rend() - 1);
	return lower;
}

template <class T> std::vector<Point<T>> convex_hull(const std::vector<Point<T>> &v) {
	std::vector<int> w = hull_index(v);
	std::vector<Point<T>> res;
	for (auto &t : w)
		res.push_back(v[t]);
	return res;
}

} // ConvexHull