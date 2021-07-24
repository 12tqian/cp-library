#pragma once

std::string binary(unsigned long long n ) { //long long to binary string
	std::string result;
	do result.push_back('0' + (n & 1));
	while (n >>= 1);
	reverse(result.begin(), result.end());
	return result;
}

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
