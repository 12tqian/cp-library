#pragma once

namespace NTT {

int bsf(unsigned int x) { return __builtin_ctz(x); }
int bsf(unsigned long long x) { return __builtin_ctzll(x); }

template <class Mint> void nft(bool type, std::vector<Mint>& a) {
	int n = int(a.size()), s = 0;
	while ((1 << s) < n) s++;
	assert(1 << s == n);
	static std::vector<Mint> ep, iep;
	while (int(ep.size()) <= s) {
		ep.push_back(pow(Mint::rt(), Mint(-1).v / (1 << ep.size())));
		iep.push_back(1 / ep.back());
	}
	std::vector<Mint> b(n);
	for (int i = 1; i <= s; i++) {
		int w = 1 << (s - i);
		Mint base = type ? iep[i] : ep[i], now = 1;
		for (int y = 0; y < n / 2; y += w) {
			for (int x = 0; x < w; x++) {
				auto l = a[y << 1 | x];
				auto r = now * a[y << 1 | x | w];
				b[y | x] = l + r;
				b[y | x | n >> 1] = l - r;
			}
			now *= base;
		}
		swap(a, b);
	}
}

template <class Mint> std::vector<Mint> multiply_nft(const std::vector<Mint>& a, const std::vector<Mint>& b) {
	int n = int(a.size()), m = int(b.size());
	if (!n || !m) return {};
	if (std::min(n, m) <= 8) {
		std::vector<Mint> ans(n + m - 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];
		return ans;
	}
	int lg = 0;
	while ((1 << lg) < n + m - 1) lg++;
	int z = 1 << lg;
	auto a2 = a, b2 = b;
	a2.resize(z);
	b2.resize(z);
	nft(false, a2);
	nft(false, b2);
	for (int i = 0; i < z; i++) a2[i] *= b2[i];
	nft(true, a2);
	a2.resize(n + m - 1);
	Mint iz = 1 / Mint(z);
	for (int i = 0; i < n + m - 1; i++) a2[i] *= iz;
	return a2;
}

// Cooley-Tukey: input -> butterfly -> bit reversing -> output 
// bit reversing
template <class Mint> void butterfly(bool type, std::vector<Mint>& a) {
	int n = int(a.size()), h = 0;
	while ((1 << h) < n) h++;
	assert(1 << h == n);
	if (n == 1) return;
	static std::vector<Mint> snow, sinow;
	if (snow.empty()) {
		Mint sep = Mint(1), siep = Mint(1);
		unsigned int mod = Mint(-1).v;
		unsigned int di = 4;
		while (mod % di == 0) {
			Mint ep = pow(Mint::rt(), mod / di);
			Mint iep = 1 / ep;
			snow.push_back(siep * ep);
			sinow.push_back(sep * iep);
			sep *= ep;
			siep *= iep;
			di *= 2;
		}
	}
	if (!type) {
		// fft
		for (int ph = 1; ph <= h; ph++) {
			int w = 1 << (ph - 1), p = 1 << (h - ph);
			Mint now = Mint(1);
			for (int s = 0; s < w; s++) {
				int offset = s << (h - ph + 1);
				for (int i = 0; i < p; i++) {
					auto l = a[i + offset];
					auto r = a[i + offset + p] * now;
					a[i + offset] = l + r;
					a[i + offset + p] = l - r;
				}
				int u = bsf(~(unsigned int)(s));
				now *= snow[u];
			}
		}
	} else {
		// ifft
		for (int ph = h; ph >= 1; ph--) {
			int w = 1 << (ph - 1), p = 1 << (h - ph);
			Mint inow = Mint(1);
			for (int s = 0; s < w; s++) {
				int offset = s << (h - ph + 1);
				for (int i = 0; i < p; i++) {
					auto l = a[i + offset];
					auto r = a[i + offset + p];
					a[i + offset] = l + r;
					a[i + offset + p] = (l - r) * inow;
				}
				int u = bsf(~(unsigned int)(s));
				inow *= sinow[u];
			}
		}
	}
}

template <class Mint> std::vector<Mint> multiply(const std::vector<Mint>& a, const std::vector<Mint>& b) {
	int n = int(a.size()), m = int(b.size());
	if (!n || !m) return {};
	if (std::min(n, m) < 8) {
		std::vector<Mint> ans(n + m - 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];
		return ans;
	}
	int lg = 0;
	while ((1 << lg) < n + m - 1) lg++;
	int z = 1 << lg;
	auto a2 = a;
	a2.resize(z);
	butterfly(false, a2);
	if (a == b) {
		for (int i = 0; i < z; i++) a2[i] *= a2[i];
	} else {
		auto b2 = b;
		b2.resize(z);
		butterfly(false, b2);
		for (int i = 0; i < z; i++) a2[i] *= b2[i];
	}
	butterfly(true, a2);
	a2.resize(n + m - 1);
	Mint iz = 1 / Mint(z);
	for (int i = 0; i < n + m - 1; i++) a2[i] *= iz;
	return a2;
}

}