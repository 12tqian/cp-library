#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include <bits/stdc++.h>
#include "../../library/set-function/walsh-hadamard-transform.hpp"
#include "../../library/modular-arithmetic/mod-int2.hpp"

using mi = Mint<998244353, 5>;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<mi> a(1 << n);
	vector<mi> b(1 << n);
	for (int i = 0; i < 1 << n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 1 << n; ++i) {
		cin >> b[i];
	}
	walsh_hadamard_transformation(a);
	walsh_hadamard_transformation(b);
	vector<mi> c(1 << n);
	for (int i = 0; i < 1 << n; ++i) {
		c[i] = a[i] * b[i];
	}
	walsh_hadamard_transformation(c, true);
	for (int i = 0; i < 1 << n; ++i) {
		cout << c[i] << ' ';
	}
	cout << '\n';
	return 0;
}