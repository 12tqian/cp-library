#include <bits/stdc++.h>

/**
 * full_reduce() does complete Gaussian reduction
 * reduce() just does the things that are necessary, should be sufficient
 */

void full_reduce(std::vector<int>& b) {
	int n = (int)b.size();
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			b[j] = std::min(b[j], b[j] ^ b[i]);
		}
	}
}

template <class T> T reduce(std::vector<T>& b, T x) {
	for (auto& t : b) {
		x = std::min(x, x ^ t);
	}
	return x;
}

template <class T> bool add(std::vector<T>& b, T x) {
	if (!(x = reduce(b, x))) return false;
	int ind = 0;
	while (ind < (int)b.size() && b[ind] > x) ind++;
	b.insert(b.begin() + ind, x);
	return true;
}

int main() {
	return 0;
}