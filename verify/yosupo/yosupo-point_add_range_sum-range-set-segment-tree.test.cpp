#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/range-set-segment-tree.hpp"
#include "../../library/misc/fast-io.hpp"

FastIO::Scanner sc;
FastIO::Printer pr;

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	sc.read(n, q);
	vector<long long> a(n);
	RangeSetSeg<long long> seg; 
	seg.init(n);
	for (int i = 0; i < n; i++) 
		sc.read(a[i]), seg.range_set(i, i, a[i]);
	while (q--) {
		int t;
		sc.read(t);
		if (t == 0) {
			int p, x;
			sc.read(p, x);
			seg.range_set(p, p, x + seg.qsum(p, p));
		} else {
			int l, r;
			sc.read(l, r);
			--r;
			pr.writeln(seg.qsum(l, r));
		}
	}
	return 0;
}