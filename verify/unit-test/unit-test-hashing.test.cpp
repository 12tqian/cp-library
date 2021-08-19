#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../library/contest/template-full.hpp"
#include "../../library/string/hashing.hpp"

string random_string(int n) {
	string s;
	f0r(i, n) {
		s += (char)((rng() % 26) + 'a');
	}
	return s;
}

void test() {
	using namespace Hashing;
	HashRange H;
	const int N = 200;
	string s = random_string(N);
	H.add(s);
	f0r(i, N) {
		f1r(j, i + 1, N) {
			mi x = 0;
			mi y = 0;
			f1r(k, i, j + 1) {
				x += s[k] * pow(mi(base[0]), j - k);
				y += s[k] * pow(mi(base[1]), j - k);
			}
			array<int, 2> tmp = {x.v, y.v};
			assert(tmp == H.hash(i, j));
		}
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