#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
#include "../../library/string/z-algorithm.hpp"

using namespace std;

int main() {
	string s;
	cin >> s;
	auto a = z_algorithm(s);
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}