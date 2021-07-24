#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include <bits/stdc++.h>
#include "../library/data-structures/1d-range-queries/associative-range-query.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	RangeQuery<long long> R; 
	R.init(a);
	while (q--) {
		int l, r; cin >> l >> r;
		r--;
		cout << R.query(l, r) << '\n';
	}
	return 0;
}