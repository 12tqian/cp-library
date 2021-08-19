#pragma once

template <class C> std::vector<int> z_algorithm(C s) {
	int n = (int)s.size();
	std::vector<int> a(n);
	a[0] = n;
	int i = 1, j = 0;
	while (i < n) {
		while (i + j < n && s[j] == s[i + j]) ++j;
		a[i] = j;
		if (j == 0) {
			++i;
			continue;
		}
		int k = 1;
		while (i + k < n && k + a[k] < j) a[i + k] = a[k], ++k;
		i += k;
		j -= k;
	}
	return a;
}
