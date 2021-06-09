#include <bits/stdc++.h>

namespace Karatsuba {

int size(int s) {
	return s > 1 ? 32 - __builtin_clz(s - 1) : 0;
}

template <class T> void karatsuba(T* a, T* b, T* c, T* t, int n) {
	int ca = 0, cb = 0;
	for (int i = 0; i < n; i++)
		ca += (a[i] != 0), cb += (b[i] != 0);
	if (std::min(ca, cb) <= 1500 / n) { // not many multiplications
		if (ca > cb) 
			std::swap(ca, cb);
		for (int i = 0; i < n; i++) 
			if (a[i] != 0)
				for (int j = 0; j < n; j++)
					c[i + j] += a[i] * b[j];

	} else {
		int h = n >> 1;
		karatsuba(a, b, c, t, h); // a0 * b0
		karatsuba(a + h, b + h, c + n, t, h); // a1 * b1
		for (int i = 0; i < h; i++)
			a[i] += a[i + h], b[i] += b[i + h];
		karatsuba(a, b, t, t + n, h); // (a0 + a1) * (b0 + b1)
		for (int i = 0; i < h; i++)
			a[i] -= a[i + h], b[i] -= b[i + h];
		for (int i = 0; i < n; i++)
			t[i] -= c[i] + c[i + n];
		for (int i = 0; i < n; i++)
			c[i + h] += t[i], t[i] = 0;
	}
}

template <class T> std::vector<T> convolution(std::vector<T> a, std::vector<T> b) {
	int sa = (int)a.size(), sb = (int)b.size();
	if (!sa || !sb) 
		return {};
	int n = (1 << size(std::max(sa, sb)));
	a.resize(n);
	b.resize(n);
	std::vector<T> c(2 * n), t(2 * n);
	karatsuba(&a[0], &b[0], &c[0], &t[0], n);
	c.resize(sa + sb - 1);
	return c;
}

}

int main() {
	using namespace std;
	using namespace Karatsuba;
	ios_base::sync_with_stdio(0);
	int tt; 
	cin >> tt;
	while (tt--) {
		int sa, sb;
		cin >> sa;
		vector<long long> a(sa + 1);
		for (int i = 0; i < sa + 1; i++)
			cin >> a[i];
		cin >> sb;
		vector<long long> b(sb + 1);
		for (int i = 0; i < sb + 1; i++)
			cin >> b[i];
		vector<long long> c = convolution<long long>(a, b);
		cout << (int)c.size() - 1 << '\n';
		for (int i = 0; i < (int)c.size(); i++)
			cout << c[i] << " ";
		cout << '\n';
	}
	return 0;
}