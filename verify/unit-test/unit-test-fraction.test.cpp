#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../library/contest/template-full.hpp"
#include "../../library/numerical/fraction.hpp"

const int L = 1e2;

pi random_pair() {
	return mp(rng() % L + 1, rng() % L + 1);
}

Frac frac_convert(pi x) {
	return Frac(x.f, x.s);
}

ld decimal_convert(pi x) {
	return (ld)x.f / x.s;
}

void test() {
	const ld EPS = 1e-9;
	const int T = 100;
	auto check = [&](ld x, ld y) {
		assert(abs(x - y) < EPS);
	};
	f0r(t, T) {
		auto a = random_pair();
		auto b = random_pair();
		check((frac_convert(a) + frac_convert(b)).eval(), decimal_convert(a) + decimal_convert(b));
		check((frac_convert(a) * frac_convert(b)).eval(), decimal_convert(a) * decimal_convert(b));
		check((frac_convert(a) - frac_convert(b)).eval(), decimal_convert(a) - decimal_convert(b));
		check((frac_convert(a) / frac_convert(b)).eval(), decimal_convert(a) / decimal_convert(b));
	}
}

int main() {
	set_io("");
	test();
	int a, b;
	re(a, b);
	ps(a + b);
	return 0;
}