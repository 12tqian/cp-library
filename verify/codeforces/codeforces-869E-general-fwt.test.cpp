#define PROBLEM "https://codeforces.com/contest/1074/problem/F"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/2d-range-queries/general-fenwick-tree.hpp"
#include "../../library/numerical/mod-int2.hpp"

const int N = 2505;

const int P = 998244353;
const int B = 2;

using mi = Mint<998244353, 5>;

BIT<mi, N, N> bit;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> m >> m >> q;
	map<array<int, 4>, mi> rects;
	mi run = 1;
	while (q--) {
		int t, xl, xr, yl, yr;
		cin >> t >> xl >> yl >> xr >> yr;
		auto rect = [&]() {
			mi v;
			if (t == 1) {
				rects[{xl, xr, yl, yr}] = run;
				v = run;
				run *= 2;
			} else {
				v = rects[{xl, xr, yl, yr}];
				v *= -1;
			}
			bit.upd(xl, yl, v);
			bit.upd(xl, yr + 1, -v);
			bit.upd(xr + 1, yl, -v);
			bit.upd(xr + 1, yr + 1, v);
		};
		if (t <= 2) {
			rect();
		} else {	
			if (bit.query(1, xl, 1, yl) == bit.query(1, xr, 1, yr)) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
		}
	}
	return 0;
}