#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/number-theory/counting-primes.hpp"

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long n; cin >> n;
	cout << count_primes(n) << '\n';
	return 0;
}