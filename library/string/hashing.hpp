#pragma once

namespace Hashing {

const int MOD = 1e9 + 7;

std::mt19937 rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const std::array<int, 2> base = {BDIST(rng), BDIST(rng)};
std::vector<std::array<int, 2>> pows = {{1, 1}};

std::array<int, 2> operator+(std::array<int, 2> l, std::array<int, 2> r) {
	for (int i = 0; i < 2; i++)
		if ((l[i] += r[i]) >= MOD)
			l[i] -= MOD;
	return l;
}

std::array<int, 2> operator-(std::array<int, 2> l, std::array<int, 2> r) {
	for (int i = 0; i < 2; i++)
		if ((l[i] -= r[i]) < 0)
			l[i] += MOD;
	return l;
}

std::array<int, 2> operator*(std::array<int, 2> l, std::array<int, 2> r) {
	for (int i = 0; i < 2; i++)
		l[i] = (long long) l[i] * r[i] % MOD;
	return l;
}

std::array<int, 2> make_hash(char c) {
	return {c, c};
}

struct HashRange {
	std::vector<std::array<int, 2>> pre = {{0, 0}};
	std::string s;

	void add(char c) {
		s += c;
		pre.push_back(base * pre.back() + make_hash(c));
	}

	void add(std::string t) {
		for (auto& c : t)
			add(c);
	}

	void extend(int len) {
		while ((int)pows.size() <= len)
			pows.push_back(base * pows.back());
	}
	
	std::array<int, 2> hash(int l, int r) {
		int len = r + 1 - l;
		extend(len);
		return pre[r + 1] - pows[len] * pre[l];
	}
};

} // Hashing