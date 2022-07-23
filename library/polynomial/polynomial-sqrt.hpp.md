---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-sqrt.hpp
    title: library/modular-arithmetic/mod-sqrt.hpp
  - icon: ':question:'
    path: library/polynomial/number-theoretic-transform.hpp
    title: library/polynomial/number-theoretic-transform.hpp
  - icon: ':question:'
    path: library/polynomial/polynomial.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n\r\n\r\nnamespace NTT {\r\n\r\nint bsf(unsigned int x) { return\
    \ __builtin_ctz(x); }\r\nint bsf(unsigned long long x) { return __builtin_ctzll(x);\
    \ }\r\n\r\ntemplate <class Mint> void nft(bool type, std::vector<Mint>& a) {\r\
    \n\tint n = int(a.size()), s = 0;\r\n\twhile ((1 << s) < n) s++;\r\n\tassert(1\
    \ << s == n);\r\n\tstatic std::vector<Mint> ep, iep;\r\n\twhile (int(ep.size())\
    \ <= s) {\r\n\t\tep.push_back(pow(Mint::rt(), Mint(-1).v / (1 << ep.size())));\r\
    \n\t\tiep.push_back(1 / ep.back());\r\n\t}\r\n\tstd::vector<Mint> b(n);\r\n\t\
    for (int i = 1; i <= s; i++) {\r\n\t\tint w = 1 << (s - i);\r\n\t\tMint base =\
    \ type ? iep[i] : ep[i], now = 1;\r\n\t\tfor (int y = 0; y < n / 2; y += w) {\r\
    \n\t\t\tfor (int x = 0; x < w; x++) {\r\n\t\t\t\tauto l = a[y << 1 | x];\r\n\t\
    \t\t\tauto r = now * a[y << 1 | x | w];\r\n\t\t\t\tb[y | x] = l + r;\r\n\t\t\t\
    \tb[y | x | n >> 1] = l - r;\r\n\t\t\t}\r\n\t\t\tnow *= base;\r\n\t\t}\r\n\t\t\
    swap(a, b);\r\n\t}\r\n}\r\n\r\ntemplate <class Mint> std::vector<Mint> multiply_nft(const\
    \ std::vector<Mint>& a, const std::vector<Mint>& b) {\r\n\tint n = int(a.size()),\
    \ m = int(b.size());\r\n\tif (!n || !m) return {};\r\n\tif (std::min(n, m) <=\
    \ 8) {\r\n\t\tstd::vector<Mint> ans(n + m - 1);\r\n\t\tfor (int i = 0; i < n;\
    \ i++)\r\n\t\t\tfor (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];\r\n\t\t\
    return ans;\r\n\t}\r\n\tint lg = 0;\r\n\twhile ((1 << lg) < n + m - 1) lg++;\r\
    \n\tint z = 1 << lg;\r\n\tauto a2 = a, b2 = b;\r\n\ta2.resize(z);\r\n\tb2.resize(z);\r\
    \n\tnft(false, a2);\r\n\tnft(false, b2);\r\n\tfor (int i = 0; i < z; i++) a2[i]\
    \ *= b2[i];\r\n\tnft(true, a2);\r\n\ta2.resize(n + m - 1);\r\n\tMint iz = 1 /\
    \ Mint(z);\r\n\tfor (int i = 0; i < n + m - 1; i++) a2[i] *= iz;\r\n\treturn a2;\r\
    \n}\r\n\r\n// Cooley-Tukey: input -> butterfly -> bit reversing -> output \r\n\
    // bit reversing\r\ntemplate <class Mint> void butterfly(bool type, std::vector<Mint>&\
    \ a) {\r\n\tint n = int(a.size()), h = 0;\r\n\twhile ((1 << h) < n) h++;\r\n\t\
    assert(1 << h == n);\r\n\tif (n == 1) return;\r\n\tstatic std::vector<Mint> snow,\
    \ sinow;\r\n\tif (snow.empty()) {\r\n\t\tMint sep = Mint(1), siep = Mint(1);\r\
    \n\t\tunsigned int mod = Mint(-1).v;\r\n\t\tunsigned int di = 4;\r\n\t\twhile\
    \ (mod % di == 0) {\r\n\t\t\tMint ep = pow(Mint::rt(), mod / di);\r\n\t\t\tMint\
    \ iep = 1 / ep;\r\n\t\t\tsnow.push_back(siep * ep);\r\n\t\t\tsinow.push_back(sep\
    \ * iep);\r\n\t\t\tsep *= ep;\r\n\t\t\tsiep *= iep;\r\n\t\t\tdi *= 2;\r\n\t\t\
    }\r\n\t}\r\n\tif (!type) {\r\n\t\t// fft\r\n\t\tfor (int ph = 1; ph <= h; ph++)\
    \ {\r\n\t\t\tint w = 1 << (ph - 1), p = 1 << (h - ph);\r\n\t\t\tMint now = Mint(1);\r\
    \n\t\t\tfor (int s = 0; s < w; s++) {\r\n\t\t\t\tint offset = s << (h - ph + 1);\r\
    \n\t\t\t\tfor (int i = 0; i < p; i++) {\r\n\t\t\t\t\tauto l = a[i + offset];\r\
    \n\t\t\t\t\tauto r = a[i + offset + p] * now;\r\n\t\t\t\t\ta[i + offset] = l +\
    \ r;\r\n\t\t\t\t\ta[i + offset + p] = l - r;\r\n\t\t\t\t}\r\n\t\t\t\tint u = bsf(~(unsigned\
    \ int)(s));\r\n\t\t\t\tnow *= snow[u];\r\n\t\t\t}\r\n\t\t}\r\n\t} else {\r\n\t\
    \t// ifft\r\n\t\tfor (int ph = h; ph >= 1; ph--) {\r\n\t\t\tint w = 1 << (ph -\
    \ 1), p = 1 << (h - ph);\r\n\t\t\tMint inow = Mint(1);\r\n\t\t\tfor (int s = 0;\
    \ s < w; s++) {\r\n\t\t\t\tint offset = s << (h - ph + 1);\r\n\t\t\t\tfor (int\
    \ i = 0; i < p; i++) {\r\n\t\t\t\t\tauto l = a[i + offset];\r\n\t\t\t\t\tauto\
    \ r = a[i + offset + p];\r\n\t\t\t\t\ta[i + offset] = l + r;\r\n\t\t\t\t\ta[i\
    \ + offset + p] = (l - r) * inow;\r\n\t\t\t\t}\r\n\t\t\t\tint u = bsf(~(unsigned\
    \ int)(s));\r\n\t\t\t\tinow *= sinow[u];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\
    \ntemplate <class Mint> std::vector<Mint> multiply(const std::vector<Mint>& a,\
    \ const std::vector<Mint>& b) {\r\n\tint n = int(a.size()), m = int(b.size());\r\
    \n\tif (!n || !m) return {};\r\n\tif (std::min(n, m) < 8) {\r\n\t\tstd::vector<Mint>\
    \ ans(n + m - 1);\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tfor (int j = 0;\
    \ j < m; j++) ans[i + j] += a[i] * b[j];\r\n\t\treturn ans;\r\n\t}\r\n\tint lg\
    \ = 0;\r\n\twhile ((1 << lg) < n + m - 1) lg++;\r\n\tint z = 1 << lg;\r\n\tauto\
    \ a2 = a;\r\n\ta2.resize(z);\r\n\tbutterfly(false, a2);\r\n\tif (a == b) {\r\n\
    \t\tfor (int i = 0; i < z; i++) a2[i] *= a2[i];\r\n\t} else {\r\n\t\tauto b2 =\
    \ b;\r\n\t\tb2.resize(z);\r\n\t\tbutterfly(false, b2);\r\n\t\tfor (int i = 0;\
    \ i < z; i++) a2[i] *= b2[i];\r\n\t}\r\n\tbutterfly(true, a2);\r\n\ta2.resize(n\
    \ + m - 1);\r\n\tMint iz = 1 / Mint(z);\r\n\tfor (int i = 0; i < n + m - 1; i++)\
    \ a2[i] *= iz;\r\n\treturn a2;\r\n}\r\n\r\n}\n\r\ntemplate <class D> struct Poly\
    \ : std::vector<D> {\r\n\tusing std::vector<D>::vector;\r\n\r\n\tstatic const\
    \ int SMALL_DEGREE = 60;\r\n\r\n\tPoly(const std::vector<D>& _v = {}) { \r\n\t\
    \tfor (int i = 0; i < (int)_v.size(); ++i) {\r\n\t\t\tthis->push_back(_v[i]);\r\
    \n\t\t}\r\n\t\tshrink(); \r\n\t}\r\n\r\n\tvoid shrink() {\r\n\t\twhile (this->size()\
    \ && !this->back()) this->pop_back();\r\n\t}\r\n\r\n\tD freq(int p) const { return\
    \ (p < (int)this->size()) ? (*this)[p] : D(0); }\r\n\t\r\n\tPoly operator+(const\
    \ Poly& r) const {\r\n\t\tint n = std::max(this->size(), r.size());\r\n\t\tstd::vector<D>\
    \ res(n);\r\n\t\tfor (int i = 0; i < n; i++) res[i] = freq(i) + r.freq(i);\r\n\
    \t\treturn res;\r\n\t}\r\n\r\n\tPoly operator-(const Poly& r) const {\r\n\t\t\
    int n = std::max(this->size(), r.size());\r\n\t\tstd::vector<D> res(n);\r\n\t\t\
    for (int i = 0; i < n; i++) res[i] = freq(i) - r.freq(i);\r\n\t\treturn res;\r\
    \n\t}\r\n\r\n\tbool small(const Poly& r) const { return std::min((int)this->size(),\
    \ (int)r.size()) <= SMALL_DEGREE; }\r\n\r\n\tPoly operator*(const Poly& r) const\
    \ { \r\n\t\tif (!std::min((int)this->size(), (int)r.size())) return {};\r\n\t\t\
    if (small(r)){\r\n\t\t\tPoly res((int)this->size() + (int)r.size() - 1);\r\n\t\
    \t\tfor (int i = 0; i < (int)this->size(); ++i) {\r\n\t\t\t\tfor (int j = 0; j\
    \ < (int)r.size(); ++j) {\r\n\t\t\t\t\tres[i + j] += (*this)[i] * r[j];\r\n\t\t\
    \t\t}\r\n\t\t\t}\r\n\t\t\treturn res;\r\n\t\t} else {\r\n\t\t\treturn {NTT::multiply((*this),\
    \ r)}; \r\n\t\t}\r\n\t}\r\n\t\r\n\tPoly operator*(const D& r) const {\r\n\t\t\
    int n = this->size();\r\n\t\tstd::vector<D> res(n);\r\n\t\tfor (int i = 0; i <\
    \ n; i++) res[i] = (*this)[i] * r;\r\n\t\treturn res;\r\n\t}\r\n\r\n\tPoly operator/(const\
    \ D &r) const{ return *this * (1 / r); }\r\n\r\n\r\n\tPoly& operator+=(const D&\
    \ r) { \r\n\t\tif (this->empty()) this->resize(1);\r\n\t\t(*this)[0] += r;\r\n\
    \t\treturn *this;\r\n\t}\r\n\r\n\tPoly& operator-=(const D& r) {\r\n\t\t(*this)[0]\
    \ -= r;\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tPoly operator/(const Poly& r) const\
    \ {\r\n\t\tif (this->size() < r.size()) return {};\r\n\t\tif (small(r)) {\r\n\t\
    \t\tPoly a = (*this);\r\n\t\t\tPoly b = r;\r\n\t\t\ta.shrink(), b.shrink();\r\n\
    \t\t\tD lst = b.back();\r\n\t\t\tD ilst = 1 / lst;\r\n\t\t\tfor (auto& t : a)\
    \ t *= ilst;\r\n\t\t\tfor (auto& t : b) t *= ilst;\r\n\t\t\tPoly q(std::max((int)a.size()\
    \ - (int)b.size() + 1, 0));\r\n\t\t\tfor (int diff; (diff = (int)a.size() - (int)b.size())\
    \ >= 0; a.shrink()) {\r\n\t\t\t\tq[diff] = a.back();\r\n\t\t\t\tfor (int i = 0;\
    \ i < (int)b.size(); ++i) {\r\n\t\t\t\t\ta[i + diff] -= q[diff] * b[i];\r\n\t\t\
    \t\t}\r\n\t\t\t}\r\n\t\t\treturn q;\r\n\t\t} else {\r\n\t\t\tint n = (int)this->size()\
    \ - r.size() + 1;\r\n\t\t\treturn (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\tPoly operator%(const Poly& r) const { return *this -\
    \ *this / r * r; }\r\n\t\r\n\tPoly operator<<(int s) const {\r\n\t\tstd::vector<D>\
    \ res(this->size() + s);\r\n\t\tfor (int i = 0; i < (int)this->size(); i++) res[i\
    \ + s] = (*this)[i];\r\n\t\treturn res;\r\n\t}\r\n\r\n\tPoly operator>>(int s)\
    \ const {\r\n\t\tif ((int)this->size() <= s) return Poly();\r\n\t\tstd::vector<D>\
    \ res(this->size() - s);\r\n\t\tfor (int i = 0; i < (int)this->size() - s; i++)\
    \ res[i] = (*this)[i + s];\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tPoly operator+(const\
    \ D& r) { return Poly(*this) += r; }\r\n\tPoly operator-(const D& r) { return\
    \ Poly(*this) -= r; }\r\n\tPoly operator-() const { return (*this) * -1; } \r\n\
    \tPoly& operator+=(const Poly& r) { return *this = *this + r; }\r\n\tPoly& operator-=(const\
    \ Poly& r) { return *this = *this - r; }\r\n\tPoly& operator*=(const Poly& r)\
    \ { return *this = *this * r; }\r\n\tPoly& operator*=(const D& r) { return *this\
    \ = *this * r; }\r\n\tPoly& operator/=(const Poly& r) { return *this = *this /\
    \ r; }\r\n\tPoly& operator/=(const D &r) { return *this = *this / r; }\r\n\tPoly&\
    \ operator%=(const Poly& r) { return *this = *this % r; }\r\n\tPoly& operator<<=(const\
    \ size_t& n) { return *this = *this << n; }\r\n\tPoly& operator>>=(const size_t&\
    \ n) { return *this = *this >> n; }\r\n\tfriend Poly operator*(D const& l, Poly\
    \ r) { return r *= l; }\r\n\tfriend Poly operator/(D const& l, Poly r) { return\
    \ l * r.inv(); }\r\n\tfriend Poly operator+(D const& l, Poly r) { return r +=\
    \ l; }\r\n\tfriend Poly operator-(D const& l, Poly r) { return -r + l; }\r\n\r\
    \n\tPoly pre(int le) const { return Poly(this->begin(), this->begin() + std::min((int)this->size(),\
    \ le)); }\r\n\t\r\n\tPoly rev(int n = -1) const {\r\n\t\tPoly res = *this;\r\n\
    \t\tif (n != -1) res.resize(n);\r\n\t\treverse(res.begin(), res.end());\r\n\t\t\
    return res;\r\n\t}\r\n\t\r\n\tPoly diff() const {\r\n\t\tstd::vector<D> res(std::max(0,\
    \ (int)this->size() - 1));\r\n\t\tfor (int i = 1; i < (int)this->size(); i++)\
    \ res[i - 1] = freq(i) * i;\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tPoly inte() const\
    \ {\r\n\t\tstd::vector<D> res(this->size() + 1);\r\n\t\tfor (int i = 0; i < (int)this->size();\
    \ i++) res[i + 1] = freq(i) / (i + 1);\r\n\t\treturn res;\r\n\t}\r\n\r\n\t// f\
    \ * f.inv() = 1 + g(x)x^m\r\n\tPoly inv(int m = -1) const {\r\n\t\tif (m == -1)\
    \ m = (int)this->size();\r\n\t\tPoly res = Poly({D(1) / freq(0)});\r\n\t\tfor\
    \ (int i = 1; i < m; i *= 2) {\r\n\t\t\tres = (res * D(2) - res * res * pre(2\
    \ * i)).pre(2 * i);\r\n\t\t}\r\n\t\treturn res.pre(m);\r\n\t}\r\n\t\r\n\tPoly\
    \ exp(int n = -1) const {\r\n\t\tassert(freq(0) == 0);\r\n\t\tif (n == -1) n =\
    \ (int)this->size();\r\n\t\tPoly f({1}), g({1});\r\n\t\tfor (int i = 1; i < n;\
    \ i *= 2) {\r\n\t\t\tg = (g * 2 - f * g * g).pre(i);\r\n\t\t\tPoly q = diff().pre(i\
    \ - 1);\r\n\t\t\tPoly w = (q + g * (f.diff() - f * q)).pre(2 * i - 1);\r\n\t\t\
    \tf = (f + f * (*this - w.inte()).pre(2 * i)).pre(2 * i);\r\n\t\t}\r\n\t\treturn\
    \ f.pre(n);\r\n\t}\r\n\t\r\n\tPoly log(int n = -1) const {\r\n\t\tif (n == -1)\
    \ n = (int)this->size();\r\n\t\tassert(freq(0) == 1);\r\n\t\tauto f = pre(n);\r\
    \n\t\treturn (f.diff() * f.inv(n - 1)).pre(n - 1).inte();\r\n\t}\r\n\r\n\tPoly\
    \ pow_mod(const Poly& mod, long long n = -1) {\r\n\t\tif (n == -1) n = this->size();\r\
    \n\t\tPoly x = *this, r = {{1}};\r\n\t\twhile (n) {\r\n\t\t\tif (n & 1) r = r\
    \ * x % mod;\r\n\t\t\tx = x * x % mod;\r\n\t\t\tn >>= 1;\r\n\t\t}\r\n\t\treturn\
    \ r;\r\n\t}\r\n\r\n\tD _pow(D x, long long k) { \r\n\t\tD r = 1;\r\n\t\twhile\
    \ (k) {\r\n\t\t\tif (k & 1) {\r\n\t\t\t\tr *= x;\r\n\t\t\t}\r\n\t\t\tx *= x;\r\
    \n\t\t\tk >>= 1;\r\n\t\t}\r\n\t\treturn r;\r\n\t}\r\n\r\n\tPoly pow(long long\
    \ k, int n = -1) {\r\n\t\tif (n == -1) n = this->size();\r\n\t\tint sz = (int)this->size();\r\
    \n\t\tfor (int i = 0; i < sz; ++i) {\r\n\t\t\tif (freq(i) != 0) {\r\n\t\t\t\t\
    if (i * k > n) return Poly(n);\r\n\t\t\t\tD rev = 1 / (*this)[i];\r\n\t\t\t\t\
    Poly ret = (((*this * rev) >> i).log(n) * k).exp(n) * _pow((*this)[i], k);\r\n\
    \t\t\t\tret = (ret << (i * k)).pre(n);\r\n\t\t\t\tret.resize(n);\r\n\t\t\t\treturn\
    \ ret;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn Poly(n);\r\n\t}\r\n\r\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const Poly& p) {\r\n\t\tif (p.empty()) return os\
    \ << \"0\";\r\n\t\tfor (auto i = 0; i < (int)p.size(); i++) {\r\n\t\t\tif (p[i])\
    \ {\r\n\t\t\t\tos << p[i] << \"x^\" << i;\r\n\t\t\t\tif (i != (int)p.size() -\
    \ 1) os << \"+\";\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn os;\r\n\t}\r\n};\n\r\nunsigned\
    \ xrand() {\r\n\tstatic unsigned x = 314159265, y = 358979323, z = 846264338,\
    \ w = 327950288;\r\n\tunsigned t = x ^ x << 11; x = y; y = z; z = w; return w\
    \ = w ^ w >> 19 ^ t ^ t >> 8;\r\n}\r\n\r\nlong long mod_inverse(long long a, long\
    \ long m) {\r\n\tlong long b = m, x = 1, y = 0, t;\r\n\tfor (; ; ) {\r\n\t\tt\
    \ = a / b, a -= t * b;\r\n\t\tif (a == 0) {\r\n\t\t\tassert(b == 1 || b == -1);\r\
    \n\t\t\tif ( b== -1) y = -y;\r\n\t\t\treturn (y < 0) ? (y + m) : y;\r\n\t\t}\r\
    \n\t\tx -= t * y;\r\n\t\tt = b / a, b -= t * a;\r\n\t\tif (b == 0) {\r\n\t\t\t\
    assert (a == 1 || a == -1);\r\n\t\t\tif (a == -1) x = -x;\r\n\t\t\treturn (x <\
    \ 0) ? (x + m) : x;\r\n\t\t}\r\n\t\ty -= t * x;\r\n\t}\r\n}\r\n\r\nint jacobi(long\
    \ long a, long long m) {\r\n\tint s = 1;\r\n\tif (a < 0) a = a % m + m;\r\n\t\
    for (; m > 1; ) {\r\n\t\ta %= m;\r\n\t\tif (a == 0) return 0;\r\n\t\tconst int\
    \ r = __builtin_ctz(a);\r\n\t\tif ((r & 1) && ((m + 2) & 4)) s = -s;\r\n\t\ta\
    \ >>= r;\r\n\t\tif (a & m & 2) s = -s;\r\n\t\tstd::swap(a, m);\r\n\t}\r\n\treturn\
    \ s;\r\n}\r\n\r\nstd::vector<long long> mod_sqrt(long long a, long long p) {\r\
    \n\tif (p == 2) return {a & 1};\r\n\tconst int j = jacobi(a, p);\r\n\tif (j ==\
    \ 0) return {0};\r\n\tif (j == -1) return {};\r\n\tlong long b, d;\r\n\tfor (;\
    \ ; ) {\r\n\t\tb = xrand() % p;\r\n\t\td = (b * b - a) % p;\r\n\t\tif (d < 0)\
    \ d += p;\r\n\t\tif (jacobi(d, p) == -1) break;\r\n\t}\r\n\tlong long f0 = b,\
    \ f1 = 1, g0 = 1, g1 = 0, tmp;\r\n\tfor (long long e = (p + 1) >> 1; e; e >>=\
    \ 1) {\r\n\t\tif (e & 1) {\r\n\t\t\ttmp = (g0 * f0 + d * ((g1 * f1) % p)) % p;\r\
    \n\t\t\tg1 = (g0 * f1 + g1 * f0) % p;\r\n\t\t\tg0 = tmp;\r\n\t\t}\r\n\t\ttmp =\
    \ (f0 * f0 + d * ((f1 * f1) % p)) % p;\r\n\t\tf1 = (2 * f0 * f1) % p;\r\n\t\t\
    f0 = tmp;\r\n\t}\r\n\treturn (g0 < p - g0) ? std::vector<long long>{g0, p - g0}\
    \ : std::vector<long long>{p - g0, g0};\r\n}\n\r\ntemplate <class D> Poly<D> sqrt(const\
    \ Poly<D>& p, int n = -1) {\r\n\tif (n == -1) n = (int)p.size();\r\n\tif (p.empty())\
    \ return Poly<D>(n);\r\n\tif (p[0] == 0) {\r\n\t\tfor (int i = 1; i < (int)p.size();\
    \ ++i) {\r\n\t\t\tif (p[i] != 0) {\r\n\t\t\t\tif (i & 1) {\r\n\t\t\t\t\treturn\
    \ {};\r\n\t\t\t\t}\r\n\t\t\t\tif (n - i / 2 <= 0) break;\r\n\t\t\t\tauto ret =\
    \ sqrt(p >> i, n - i / 2);\r\n\t\t\t\tif (ret.empty()) return {};\r\n\t\t\t\t\
    ret = ret << (i / 2);\r\n\t\t\t\tif ((int)ret.size() < n) ret.resize(n);\r\n\t\
    \t\t\treturn ret;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn Poly<D>(n);\r\n\t}\r\n\tauto\
    \ v = mod_sqrt(p[0].v, D::md());\r\n\tif (v.empty()) return {};\r\n\tlong long\
    \ sqr = v[0];\r\n\tPoly<D> ret = {D(sqr)};\r\n\tD i2 = 1 / D(2);\r\n\tfor (int\
    \ i = 1; i < n; i <<= 1) {\r\n\t\tret = (ret + p.pre(i << 1) * ret.inv(i << 1))\
    \ * i2;\r\n\t}\r\n\treturn ret.pre(n);\r\n}\n"
  code: "#pragma once\r\n\r\n#include \"polynomial.hpp\"\r\n#include \"../modular-arithmetic/mod-sqrt.hpp\"\
    \r\n\r\ntemplate <class D> Poly<D> sqrt(const Poly<D>& p, int n = -1) {\r\n\t\
    if (n == -1) n = (int)p.size();\r\n\tif (p.empty()) return Poly<D>(n);\r\n\tif\
    \ (p[0] == 0) {\r\n\t\tfor (int i = 1; i < (int)p.size(); ++i) {\r\n\t\t\tif (p[i]\
    \ != 0) {\r\n\t\t\t\tif (i & 1) {\r\n\t\t\t\t\treturn {};\r\n\t\t\t\t}\r\n\t\t\
    \t\tif (n - i / 2 <= 0) break;\r\n\t\t\t\tauto ret = sqrt(p >> i, n - i / 2);\r\
    \n\t\t\t\tif (ret.empty()) return {};\r\n\t\t\t\tret = ret << (i / 2);\r\n\t\t\
    \t\tif ((int)ret.size() < n) ret.resize(n);\r\n\t\t\t\treturn ret;\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\treturn Poly<D>(n);\r\n\t}\r\n\tauto v = mod_sqrt(p[0].v, D::md());\r\
    \n\tif (v.empty()) return {};\r\n\tlong long sqr = v[0];\r\n\tPoly<D> ret = {D(sqr)};\r\
    \n\tD i2 = 1 / D(2);\r\n\tfor (int i = 1; i < n; i <<= 1) {\r\n\t\tret = (ret\
    \ + p.pre(i << 1) * ret.inv(i << 1)) * i2;\r\n\t}\r\n\treturn ret.pre(n);\r\n}"
  dependsOn:
  - library/polynomial/polynomial.hpp
  - library/polynomial/number-theoretic-transform.hpp
  - library/modular-arithmetic/mod-sqrt.hpp
  isVerificationFile: false
  path: library/polynomial/polynomial-sqrt.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
documentation_of: library/polynomial/polynomial-sqrt.hpp
layout: document
redirect_from:
- /library/library/polynomial/polynomial-sqrt.hpp
- /library/library/polynomial/polynomial-sqrt.hpp.html
title: library/polynomial/polynomial-sqrt.hpp
---
