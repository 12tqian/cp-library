#define PROBLEM "https://www.spoj.com/problems/MMFSUNDARAM/"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/number-theory/sieve.hpp"

const int N = 1e5 + 5;

Sieve<N> sieve;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int x : sieve.pr) {
		if (x <= n) {
			cout << x << ' ';
		} else {
			break;
		}
	}
	cout << '\n';
	return 0;
}