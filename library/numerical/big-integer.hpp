#pragma once
/**
 * Description: Big Integer
 * Source: https://github.com/indy256/codelibrary/
			blob/master/cpp/numbertheory/BigInt.cpp
 * Verification: https://oj.uz/problem/view/IOI11_parrots
 */

// base and base_digits must be consistent
constexpr int base = 1000000000;
constexpr int base_digits = 9;

struct BigInt {
	// value == 0 is represented by empty z
	std::vector<int> z; // digits

	// sign == 1 <==> value >= 0
	// sign == -1 <==> value < 0
	int sign;

	BigInt() : sign(1) {}
	BigInt(long long v) { *this = v; }

	BigInt &operator=(long long v) {
		sign = v < 0 ? -1 : 1; v *= sign;
		z.clear(); for (; v > 0; v = v / base) z.push_back((int) (v % base));
		return *this;
	}

	BigInt(const std::string &s) { read(s); }

	BigInt &operator+=(const BigInt &other) {
		if (sign == other.sign) {
			for (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {
				if (i == z.size())
					z.push_back(0);
				z[i] += carry + (i < other.z.size() ? other.z[i] : 0);
				carry = z[i] >= base;
				if (carry)
					z[i] -= base;
			}
		} else if (other != 0 /* prevent infinite loop */) {
			*this -= -other;
		}
		return *this;
	}

	friend BigInt operator+(BigInt a, const BigInt &b) { return a += b; }

	BigInt &operator-=(const BigInt &other) {
		if (sign == other.sign) {
			if (sign == 1 && *this >= other || sign == -1 && *this <= other) {
				for (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {
					z[i] -= carry + (i < other.z.size() ? other.z[i] : 0);
					carry = z[i] < 0;
					if (carry)
						z[i] += base;
				}
				trim();
			} else {
				*this = other - *this;
				this->sign = -this->sign;
			}
		} else {
			*this += -other;
		}
		return *this;
	}

	friend BigInt operator-(BigInt a, const BigInt &b) { return a -= b; }

	BigInt &operator*=(int v) {
		if (v < 0) sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < z.size() || carry; ++i) {
			if (i == z.size())
				z.push_back(0);
			long long cur = (long long) z[i] * v + carry;
			carry = (int) (cur / base);
			z[i] = (int) (cur % base);
		}
		trim();
		return *this;
	}

	BigInt operator*(int v) const { return BigInt(*this) *= v; }

	friend std::pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) {
		int norm = base / (b1.z.back() + 1);
		BigInt a = a1.abs() * norm;
		BigInt b = b1.abs() * norm;
		BigInt q, r;
		q.z.resize(a.z.size());

		for (int i = (int) a.z.size() - 1; i >= 0; i--) {
			r *= base;
			r += a.z[i];
			int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;
			int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;
			int d = (int) (((long long) s1 * base + s2) / b.z.back());
			r -= b * d;
			while (r < 0)
				r += b, --d;
			q.z[i] = d;
		}

		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return {q, r / norm};
	}

	friend BigInt sqrt(const BigInt &a1) {
		BigInt a = a1;
		while (a.z.empty() || a.z.size() % 2 == 1)
			a.z.push_back(0);

		int n = a.z.size();

		int firstDigit = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
		int norm = base / (firstDigit + 1);
		a *= norm;
		a *= norm;
		while (a.z.empty() || a.z.size() % 2 == 1)
			a.z.push_back(0);

		BigInt r = (long long) a.z[n - 1] * base + a.z[n - 2];
		firstDigit = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
		int q = firstDigit;
		BigInt res;

		for (int j = n / 2 - 1; j >= 0; j--) {
			for (;; --q) {
				BigInt r1 = (r - (res * 2 * base + q) * q) * base * base +
							(j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
				if (r1 >= 0) {
					r = r1;
					break;
				}
			}
			res *= base;
			res += q;

			if (j > 0) {
				int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;
				int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;
				int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;
				q = (int) (((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2));
			}
		}

		res.trim();
		return res / norm;
	}

	BigInt operator/(const BigInt &v) const { return divmod(*this, v).first; }

	BigInt operator%(const BigInt &v) const { return divmod(*this, v).second; }

	BigInt &operator/=(int v) {
		if (v < 0) sign = -sign, v = -v;
		for (int i = (int) z.size() - 1, rem = 0; i >= 0; --i) {
			long long cur = z[i] + rem * (long long) base;
			z[i] = (int) (cur / v);
			rem = (int) (cur % v);
		}
		trim();
		return *this;
	}

	BigInt operator/(int v) const { return BigInt(*this) /= v; }

	int operator%(int v) const {
		if (v < 0) v = -v;
		int m = 0;
		for (int i = (int) z.size() - 1; i >= 0; --i)
			m = (int) ((z[i] + m * (long long) base) % v);
		return m * sign;
	}

	BigInt &operator*=(const BigInt &v) { return *this = *this * v; }
	BigInt &operator/=(const BigInt &v) { return *this = *this / v; }

	bool operator<(const BigInt &v) const {
		if (sign != v.sign)
			return sign < v.sign;
		if (z.size() != v.z.size())
			return z.size() * sign < v.z.size() * v.sign;
		for (int i = (int) z.size() - 1; i >= 0; i--)
			if (z[i] != v.z[i])
				return z[i] * sign < v.z[i] * sign;
		return false;
	}

	bool operator>(const BigInt &v) const { return v < *this; }
	bool operator<=(const BigInt &v) const { return !(v < *this); }
	bool operator>=(const BigInt &v) const { return !(*this < v); }
	bool operator==(const BigInt &v) const { return !(*this < v) && !(v < *this); }
	bool operator!=(const BigInt &v) const { return *this < v || v < *this; }

	void trim() {
		while (!z.empty() && z.back() == 0) z.pop_back();
		if (z.empty()) sign = 1;
	}

	bool is_zero() const { return z.empty(); }

	friend BigInt operator-(BigInt v) {
		if (!v.z.empty()) v.sign = -v.sign;
		return v;
	}

	BigInt abs() const { return sign == 1 ? *this : -*this; }

	long long longValue() const {
		long long res = 0;
		for (int i = (int) z.size() - 1; i >= 0; i--)
			res = res * base + z[i];
		return res * sign;
	}

	friend BigInt gcd(const BigInt &a, const BigInt &b) {
		return b.is_zero() ? a : gcd(b, a % b);
	}

	friend BigInt lcm(const BigInt &a, const BigInt &b) {
		return a / gcd(a, b) * b;
	}

	void read(const std::string &s) {
		sign = 1;
		z.clear();
		int pos = 0;
		while (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = (int) s.size() - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for (int j = std::max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			z.push_back(x);
		}
		trim();
	}

	friend std::istream &operator>>(std::istream &stream, BigInt &v) {
		std::string s; stream >> s;
		v.read(s);
		return stream;
	}

	friend std::ostream &operator<<(std::ostream &stream, const BigInt &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.z.empty() ? 0 : v.z.back());
		for (int i = (int) v.z.size() - 2; i >= 0; --i)
			stream << std::setw(base_digits) << std::setfill('0') << v.z[i];
		return stream;
	}

	static std::vector<int> convert_base(const std::vector<int> &a, int old_digits, int new_digits) {
		std::vector<long long> p(std::max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < p.size(); i++)
			p[i] = p[i - 1] * 10;
		std::vector<int> res;
		long long cur = 0;
		int cur_digits = 0;
		for (int v : a) {
			cur += v * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int) cur);
		while (!res.empty() && res.back() == 0)
			res.pop_back();
		return res;
	}

	static std::vector<long long> karatsubaMultiply(const std::vector<long long> &a, const std::vector<long long> &b) {
		int n = a.size();
		std::vector<long long> res(n + n);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}

		int k = n >> 1;
		std::vector<long long> a1(a.begin(), a.begin() + k);
		std::vector<long long> a2(a.begin() + k, a.end());
		std::vector<long long> b1(b.begin(), b.begin() + k);
		std::vector<long long> b2(b.begin() + k, b.end());

		std::vector<long long> a1b1 = karatsubaMultiply(a1, b1);
		std::vector<long long> a2b2 = karatsubaMultiply(a2, b2);

		for (int i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int i = 0; i < k; i++)
			b2[i] += b1[i];

		std::vector<long long> r = karatsubaMultiply(a2, b2);
		for (int i = 0; i < a1b1.size(); i++)
			r[i] -= a1b1[i];
		for (int i = 0; i < a2b2.size(); i++)
			r[i] -= a2b2[i];

		for (int i = 0; i < r.size(); i++)
			res[i + k] += r[i];
		for (int i = 0; i < a1b1.size(); i++)
			res[i] += a1b1[i];
		for (int i = 0; i < a2b2.size(); i++)
			res[i + n] += a2b2[i];
		return res;
	}

	BigInt operator*(const BigInt &v) const {
		std::vector<int> a6 = convert_base(this->z, base_digits, 6);
		std::vector<int> b6 = convert_base(v.z, base_digits, 6);
		std::vector<long long> a(a6.begin(), a6.end());
		std::vector<long long> b(b6.begin(), b6.end());
		while (a.size() < b.size())
			a.push_back(0);
		while (b.size() < a.size())
			b.push_back(0);
		while (a.size() & (a.size() - 1))
			a.push_back(0), b.push_back(0);
		std::vector<long long> c = karatsubaMultiply(a, b);
		BigInt res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < c.size(); i++) {
			long long cur = c[i] + carry;
			res.z.push_back((int) (cur % 1000000));
			carry = (int) (cur / 1000000);
		}
		res.z = convert_base(res.z, 6, base_digits);
		res.trim();
		return res;
	}
};

BigInt random_big_int(int n) {
	std::string s;
	for (int i = 0; i < n; i++) {
		s += rand() % 10 + '0';
	}
	return BigInt(s);
}