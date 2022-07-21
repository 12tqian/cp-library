#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/dynamic-programming/line-container.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	LineContainer<long long> cht;	
	while (n--) {
		int a;
		long long b;
		cin >> a >> b;
		cht.add_line(a, b);
	} 
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int a;
			long long b;
			cin >> a >> b;
			cht.add_line(a, b);
		} else {
			int p;
			cin >> p;
			cout << cht.query(p) << '\n';
		}
	}
	return 0;
}