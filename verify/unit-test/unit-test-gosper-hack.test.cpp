#define IGNORE "self tested"

#include "../../library/contest/template-full.hpp"
#include "../../library/dynamic-programming/gosper-hack.hpp"

void test_n(int n) {
	vi res = gosper_generate(n);
	f0r(i, sz(res) - 1) {
		assert(__builtin_popcount(res[i]) <= __builtin_popcount(res[i + 1]));
	}
	sort(all(res));
	f0r(i, (1 << n)) {
		assert(res[i] == i);
	}
	assert(res.size() == (1 << n));
}

void test() {
	const int L = 17;
	f1r(i, 1, L) {
		test_n(i);
	}
}

int main() {
	setIO("");
	test();
	int a, b;
	re(a, b);
	ps(a + b);
	return 0;
}