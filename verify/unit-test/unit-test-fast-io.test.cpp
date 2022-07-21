#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <bits/stdc++.h>
#include "../../library/misc/fast-io.hpp"

Scanner sc(stdin);
Printer pr(stdout);

int main() {
	using namespace std;
	int tt;
	sc.read(tt);
	while (tt--) {
		long long a, b;
		sc.read(a, b);
		pr.writeln(a + b);
	}
	return 0;
}