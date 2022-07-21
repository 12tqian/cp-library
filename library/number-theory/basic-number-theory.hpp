#pragma once

namespace BasicNumberTheory { 

// find solution to a * x + b * y = gcd(a, b)
// |a * x|, |b * y| <= lcm(a, b)
std::pair<long long, long long> euclid(long long a, long long b) {
	if (!b) 
		return {1, 0};
	std::pair<long long, long long> p = euclid(b, a % b);
	return {p.second, p.first - a / b * p.second};
}

long long mod_inverse(long long a, long long b) {
	auto p = euclid(a, b);
	assert(p.first * a + p.second * b == 1); // gcd is 1
	return p.first + (p.first < 0) * b;
}

std::pair<long long, long long> CRT(std::pair<long long, long long> a, 
	std::pair<long long, long long> b) {
	if (a.second < b.second)
		std::swap(a, b);
	long long x, y;
	std::tie(x, y) = euclid(a.second, b.second);
	long long g = a.second * x + b.second * y;
	long long l = a.second / g * b.second;
	if ((b.first - a.first) % g)
		return {-1, -1}; // no solution
	x = (b.first - a.first) % b.second * x % b.second / g * a.second + a.first;
	return {x + (x < 0) * l, l};
}

long long cdiv(long long a, long long b) { // a / b rounded up
	return a / b + ((a ^ b) > 0 && a % b);
}

long long fdiv(long long a, long long b) { // a / b rounded down
	return a / b - ((a ^ b) < 0 && a % b);
}

// minimum x such that there is a y such that l <= a * x + b * y <= r
long long between(long long a, long long b, long long l, long long r) {
	a %= b;
	if (a == 0)
		return l == 0 ? 0 : -1;
	long long k = cdiv(l, a);
	if (a * k <= r)
		return k;
	long long x = between(b, a, a - r % a, a - l % a);
	return x == -1 ? x : cdiv(b * x + l, a);
}

// sum from i = 0 to i = n - 1 of floor(a * i + b / m), works for positive and negative m, a, b
long long floor_sum(long long n, long long m, long  long a, long long b) {
	if (m < 0) 
		a *= -1, b *= -1, m *= -1;
	long long na = a % m;
	if (na < 0) na += m;
	long long nb = b % m;
	if (nb < 0) nb += m;
	long long ans = 0;
	ans += n * (n - 1) / 2 * ((a - na) / m);
	ans += n * ((b - nb) / m);
	std::swap(a, na);
	std::swap(b, nb);
	long long y_max = (a * n + b) / m;
	long long x_max = (y_max * m - b);
	if (y_max == 0) return ans;
	ans += (n - (x_max + a - 1) / a) * y_max;
	ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
	return ans;
}

} // BasicNumberTheory