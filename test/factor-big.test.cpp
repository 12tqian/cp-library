#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../library/contest/template-minimal.hpp"
#include "../library/number-theory/factor-big.hpp"

int main() {
	using namespace FactorBig;
	int q;
	scanf("%d", &q);
	map<long long, vector<long long>> cache;
	for (int i = 0; i < q; i++) {
		long long a;
		scanf("%lld", &a);
		if (!cache.count(a)) {
			auto v = pollard(a);
			sort(v.begin(), v.end());
			cache[a] = v;
		}
		auto v = cache[a];
		printf("%d", (int)v.size());
		for (auto d: v) printf(" %lld", d);
		printf("\n");
	}
	return 0;
}