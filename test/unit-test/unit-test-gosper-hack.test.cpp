#define IGNORE "self tested"

#include "../library/contest/template-minimal.hpp"
#include "../library/dynamic-programming/gosper-hack.hpp"

int main() {
	int n = 4;
	for (int sz = 1; sz <= n; sz++) {
		long long c = (1 << sz) - 1;
		while (c < (1 << n)) {
			std::cout << binary(c) << std::endl; // do stuff to binary string with sz 1's
			long long a = c & -c;
			long long b = c + a;
			c = (c ^ b) / 4 / a | b;
		}
	}
	return 0;
}