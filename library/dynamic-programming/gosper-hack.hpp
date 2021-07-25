#pragma once

std::string binary(unsigned long long n ) { //long long to binary string
	std::string result;
	do result.push_back('0' + (n & 1));
	while (n >>= 1);
	reverse(result.begin(), result.end());
	return result;
}
