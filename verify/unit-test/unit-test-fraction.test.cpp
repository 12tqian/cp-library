#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../library/contest/template-full.hpp"
#include "../../library/numerical/fraction.hpp"

const int L = 1e2;

pi random() {
	return mp(rng() % L + 1, rng() % L + 1);
}

Frac f(pi x) {
	return Frac(x.f, x.s);
}

ld d(pi x) {
	return (ld)x.f / x.s;
}

void test() {
	const ld EPS = 1e-9;
	const int T = 100;
	auto check = [&](ld x, ld y) {
		assert(abs(x - y) < EPS);
	};
	f0r(t, T) {
		auto a = random();
		auto b = random();
		check((f(a) + f(b)).eval(), d(a) + d(b));
		check((f(a) * f(b)).eval(), d(a) * d(b));
		check((f(a) - f(b)).eval(), d(a) - d(b));
		check((f(a) / f(b)).eval(), d(a) / d(b));
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