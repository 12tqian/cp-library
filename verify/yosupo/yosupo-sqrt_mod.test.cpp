#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/number-theory/mod-sqrt.hpp"

int main() {
	using namespace std;
	int tt; cin >> tt;
	while (tt--) {
		long long y, p;
		cin >> y >> p;
		auto res = mod_sqrt(y, p);
		if (res.empty()) cout << -1 << '\n';
		else cout << res[0] << '\n';
	}
	return 0;
}