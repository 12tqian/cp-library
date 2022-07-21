#define PROBLEM "https://www.spoj.com/problems/TDKPRIME/"

#include <bits/stdc++.h>

using namespace std;

#include "../../library/number-theory/linear-sieve.hpp"

const int N = 1e8;

LinearSieve<N> sieve;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		cout << sieve.pr[n - 1] << '\n';
	}
	return 0;
}
