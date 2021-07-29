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
	const int N = 100;
	string s = random_string(N);
	H.add(s);
	f0r(i, N) {
		f1r(j, i + 1, N) {
			mi x = 0;
			mi y = 0;
			f1r(k, i, j + 1) {
				x += s[i] * pow(mi(base[0]), k - i);
				y += s[i] * pow(mi(base[1]), k - i);
			}
			array<int, 2> tmp = {x.val, y.val};
			assert(tmp == H.hash(i, j));
		}
	}
	for (int i = 0; i < 6; i++) 
		for (int j = i; j < 6; j++) {
			auto val = H.hash(i, j);
			cout << i << " " << j << " " << val[0] << " " << val[1] << '\n';
		}
}

int main() {
	setIO("");
	int a, b;
	re(a, b);
	ps(a + b);
	return 0;
}