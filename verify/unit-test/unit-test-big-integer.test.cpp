#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../library/contest/template-full.hpp"
#include "../../library/numerical/big-integer.hpp"

void test() {
	const int D = 1000;
	const int T = 100;
	auto convert = [&](BigInt x) {
		mi res = 0;
		mi run = 1;
		f0r(i, sz(x.z)) {
			res += x.z[i] * run;
			run *= base;
		}
		if (x.sign == -1) {
			res *= -1;
		}
		return res;
	};
	f0r(t, T) {
		BigInt a = random_big_int(D) * ((rng() % 2) * 2 - 1) ;
		BigInt b = random_big_int(D) * ((rng() % 2) * 2 - 1);
		mi c = convert(a);
		mi d = convert(b);
		assert(convert(a + b) == c + d);
		assert(convert(a * b) == c * d);
		assert(convert(a - b) == c - d);
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