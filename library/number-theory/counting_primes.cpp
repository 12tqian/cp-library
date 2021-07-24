#include <bits/stdc++.h>

template <class T> struct FenwickTree {
	std::vector<T> fwt;
	int n;

	void init(int n_) {
		n = n_;
		fwt.resize(n);
	}

	void init(std::vector<T> &a) {
		n = (int)a.size();
		a.assign(n, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			add(i, a[i]);
		}
	}

	T sum(int r) {
		T ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) 
			ret += fwt[r];
		return ret;
	}

	T query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	
	void add(int idx, T delta) {
		for (; idx < n; idx = idx | (idx + 1)) 
			fwt[idx] += delta;
	}
};

const int RL = 1010101;
const int CL = 10101;

std::bitset<RL + 1> isp;
std::vector<int> ps, cs;

void init(int c) {
	ps.clear(); cs.clear();
	isp[0] = isp[1] = 1;
	for (int p = 2; p * p <= RL; p++) 
		if (!isp[p]) 
			for (int q = p * p; q <= RL; q += p) 
				isp[q] = 1;
	for (int i = 2; i <= RL; i++) {
		if (!isp[i]) {
			ps.push_back(i);
			if (i <= c) cs.push_back(i);
		}
	}
}

long long phi(long long x, long long a, long long cnt) {
	long long res = 0;
	std::vector<int> mu(a + 1, 1), minp(a + 1, a);
	for (int i = 1; i <= a; i++) {
		if (!isp[i]) {
			for (long long j = i; j <= a; j += i) {
				mu[j] *= -1;
				minp[j] = std::min(minp[j], i);
			}
			for (long long j = i * i, k = j; k <= a; k += j) 
				mu[k] = 0;
		}
		res += mu[i] * (x / i);
	}
	std::vector<long long> sum(cnt);
	for (long long lo = 1; lo < x / a; lo += a) {
		long long hi = std::min(lo + a, x / a);
		FenwickTree<long long> F;
		F.init(a + 2);
		std::bitset<CL> is_one;
		for (int b = 0; b < cnt; b++) {
			int p = cs[b];
			int mi = std::max(x / p / hi, a / p);
			int ma = std::min(x / p / lo, a);
			if (p < ma) 
				for (int m = ma; m > mi; m--) 
					if (mu[m] != 0 && minp[m] > p) 
						res -= mu[m] * (sum[b] + x / p / m - lo + 1 - F.sum(x / p / m - lo));            
			sum[b] += a - F.sum(a - 1);
			for (int q = (p - lo % p) % p; q < a; q += p) {
				if (!is_one[q]) {
					F.add(q, 1);
					is_one[q] = 1;
				}
			}
		}
	}
	return res;
}

long long count_primes(long long x) {
	int r = sqrt(x);
	int c = cbrt(x);
	init(c);
	if (x <= RL) 
		return upper_bound(ps.begin(), ps.end(), x) - ps.begin();
	long long a = upper_bound(ps.begin(), ps.end(), c) - ps.begin();
	long long b = upper_bound(ps.begin(), ps.end(), r) - ps.begin();
	long long res = phi(x, c, a) + (b + a - 2) * (b - a + 1) / 2;
	int idx = b - 1;
	for (int s = r; s <= x && idx >= a; s += c) {
		std::vector<long long> cur(c + 1);
		std::bitset<CL> val;
		cur[0] = b;
		for (int i = 0; i < CL; i++) val[i] = 1;
		for (int p : cs) 
			for (int q = (p - s % p) % p; q <= c; q += p) 
				val[q] = 0;
		for (int i = 1; i <= c; i++) cur[i] = cur[i - 1] + val[i];
			b = cur[c];
		while (s <= x / ps[idx] && x / ps[idx] < s + c && idx >= a) {
			res -= cur[x / ps[idx] - s];
			idx--;
		}
	}
	return res;
}

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	long long n; cin >> n;
	cout << count_primes(n) << '\n';
	return 0;
}