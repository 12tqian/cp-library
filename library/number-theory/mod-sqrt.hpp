#pragma once

unsigned xrand() {
	static unsigned x = 314159265, y = 358979323, z = 846264338, w = 327950288;
	unsigned t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}

long long mod_inverse(long long a, long long m) {
	long long b = m, x = 1, y = 0, t;
	for (; ; ) {
		t = a / b, a -= t * b;
		if (a == 0) {
			assert(b == 1 || b == -1);
			if ( b== -1) y = -y;
			return (y < 0) ? (y + m) : y;
		}
		x -= t * y;
		t = b / a, b -= t * a;
		if (b == 0) {
			assert (a == 1 || a == -1);
			if (a == -1) x = -x;
			return (x < 0) ? (x + m) : x;
		}
		y -= t * x;
	}
}

int jacobi(long long a, long long m) {
	int s = 1;
	if (a < 0) a = a % m + m;
	for (; m > 1; ) {
		a %= m;
		if (a == 0) return 0;
		const int r = __builtin_ctz(a);
		if ((r & 1) && ((m + 2) & 4)) s = -s;
		a >>= r;
		if (a & m & 2) s = -s;
		std::swap(a, m);
	}
	return s;
}

std::vector<long long> mod_sqrt(long long a, long long p) {
	if (p == 2) return {a & 1};
	const int j = jacobi(a, p);
	if (j == 0) return {0};
	if (j == -1) return {};
	long long b, d;
	for (; ; ) {
		b = xrand() % p;
		d = (b * b - a) % p;
		if (d < 0) d += p;
		if (jacobi(d, p) == -1) break;
	}
	long long f0 = b, f1 = 1, g0 = 1, g1 = 0, tmp;
	for (long long e = (p + 1) >> 1; e; e >>= 1) {
		if (e & 1) {
			tmp = (g0 * f0 + d * ((g1 * f1) % p)) % p;
			g1 = (g0 * f1 + g1 * f0) % p;
			g0 = tmp;
		}
		tmp = (f0 * f0 + d * ((f1 * f1) % p)) % p;
		f1 = (2 * f0 * f1) % p;
		f0 = tmp;
	}
	return (g0 < p - g0) ? std::vector<long long>{g0, p - g0} : std::vector<long long>{p - g0, g0};
}

int main() {
	using namespace std;
	int tt; cin >> tt;
	while (tt--) {
		long long y, p;
		cin >> y >> p;
		auto res = mod_sqrt(y, p);
		if (res.empty()) cout << -1 << '\n';
		else cout << res[0] << '\n';
	}
	return 0;
}