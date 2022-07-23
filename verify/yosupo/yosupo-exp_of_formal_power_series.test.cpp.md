---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/number-theoretic-transform.hpp
    title: library/polynomial/number-theoretic-transform.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/polynomial.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n\r\nnamespace NTT {\r\n\r\
    \nint bsf(unsigned int x) { return __builtin_ctz(x); }\r\nint bsf(unsigned long\
    \ long x) { return __builtin_ctzll(x); }\r\n\r\ntemplate <class Mint> void nft(bool\
    \ type, std::vector<Mint>& a) {\r\n\tint n = int(a.size()), s = 0;\r\n\twhile\
    \ ((1 << s) < n) s++;\r\n\tassert(1 << s == n);\r\n\tstatic std::vector<Mint>\
    \ ep, iep;\r\n\twhile (int(ep.size()) <= s) {\r\n\t\tep.push_back(pow(Mint::rt(),\
    \ Mint(-1).v / (1 << ep.size())));\r\n\t\tiep.push_back(1 / ep.back());\r\n\t\
    }\r\n\tstd::vector<Mint> b(n);\r\n\tfor (int i = 1; i <= s; i++) {\r\n\t\tint\
    \ w = 1 << (s - i);\r\n\t\tMint base = type ? iep[i] : ep[i], now = 1;\r\n\t\t\
    for (int y = 0; y < n / 2; y += w) {\r\n\t\t\tfor (int x = 0; x < w; x++) {\r\n\
    \t\t\t\tauto l = a[y << 1 | x];\r\n\t\t\t\tauto r = now * a[y << 1 | x | w];\r\
    \n\t\t\t\tb[y | x] = l + r;\r\n\t\t\t\tb[y | x | n >> 1] = l - r;\r\n\t\t\t}\r\
    \n\t\t\tnow *= base;\r\n\t\t}\r\n\t\tswap(a, b);\r\n\t}\r\n}\r\n\r\ntemplate <class\
    \ Mint> std::vector<Mint> multiply_nft(const std::vector<Mint>& a, const std::vector<Mint>&\
    \ b) {\r\n\tint n = int(a.size()), m = int(b.size());\r\n\tif (!n || !m) return\
    \ {};\r\n\tif (std::min(n, m) <= 8) {\r\n\t\tstd::vector<Mint> ans(n + m - 1);\r\
    \n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tfor (int j = 0; j < m; j++) ans[i +\
    \ j] += a[i] * b[j];\r\n\t\treturn ans;\r\n\t}\r\n\tint lg = 0;\r\n\twhile ((1\
    \ << lg) < n + m - 1) lg++;\r\n\tint z = 1 << lg;\r\n\tauto a2 = a, b2 = b;\r\n\
    \ta2.resize(z);\r\n\tb2.resize(z);\r\n\tnft(false, a2);\r\n\tnft(false, b2);\r\
    \n\tfor (int i = 0; i < z; i++) a2[i] *= b2[i];\r\n\tnft(true, a2);\r\n\ta2.resize(n\
    \ + m - 1);\r\n\tMint iz = 1 / Mint(z);\r\n\tfor (int i = 0; i < n + m - 1; i++)\
    \ a2[i] *= iz;\r\n\treturn a2;\r\n}\r\n\r\n// Cooley-Tukey: input -> butterfly\
    \ -> bit reversing -> output \r\n// bit reversing\r\ntemplate <class Mint> void\
    \ butterfly(bool type, std::vector<Mint>& a) {\r\n\tint n = int(a.size()), h =\
    \ 0;\r\n\twhile ((1 << h) < n) h++;\r\n\tassert(1 << h == n);\r\n\tif (n == 1)\
    \ return;\r\n\tstatic std::vector<Mint> snow, sinow;\r\n\tif (snow.empty()) {\r\
    \n\t\tMint sep = Mint(1), siep = Mint(1);\r\n\t\tunsigned int mod = Mint(-1).v;\r\
    \n\t\tunsigned int di = 4;\r\n\t\twhile (mod % di == 0) {\r\n\t\t\tMint ep = pow(Mint::rt(),\
    \ mod / di);\r\n\t\t\tMint iep = 1 / ep;\r\n\t\t\tsnow.push_back(siep * ep);\r\
    \n\t\t\tsinow.push_back(sep * iep);\r\n\t\t\tsep *= ep;\r\n\t\t\tsiep *= iep;\r\
    \n\t\t\tdi *= 2;\r\n\t\t}\r\n\t}\r\n\tif (!type) {\r\n\t\t// fft\r\n\t\tfor (int\
    \ ph = 1; ph <= h; ph++) {\r\n\t\t\tint w = 1 << (ph - 1), p = 1 << (h - ph);\r\
    \n\t\t\tMint now = Mint(1);\r\n\t\t\tfor (int s = 0; s < w; s++) {\r\n\t\t\t\t\
    int offset = s << (h - ph + 1);\r\n\t\t\t\tfor (int i = 0; i < p; i++) {\r\n\t\
    \t\t\t\tauto l = a[i + offset];\r\n\t\t\t\t\tauto r = a[i + offset + p] * now;\r\
    \n\t\t\t\t\ta[i + offset] = l + r;\r\n\t\t\t\t\ta[i + offset + p] = l - r;\r\n\
    \t\t\t\t}\r\n\t\t\t\tint u = bsf(~(unsigned int)(s));\r\n\t\t\t\tnow *= snow[u];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t} else {\r\n\t\t// ifft\r\n\t\tfor (int ph = h; ph >=\
    \ 1; ph--) {\r\n\t\t\tint w = 1 << (ph - 1), p = 1 << (h - ph);\r\n\t\t\tMint\
    \ inow = Mint(1);\r\n\t\t\tfor (int s = 0; s < w; s++) {\r\n\t\t\t\tint offset\
    \ = s << (h - ph + 1);\r\n\t\t\t\tfor (int i = 0; i < p; i++) {\r\n\t\t\t\t\t\
    auto l = a[i + offset];\r\n\t\t\t\t\tauto r = a[i + offset + p];\r\n\t\t\t\t\t\
    a[i + offset] = l + r;\r\n\t\t\t\t\ta[i + offset + p] = (l - r) * inow;\r\n\t\t\
    \t\t}\r\n\t\t\t\tint u = bsf(~(unsigned int)(s));\r\n\t\t\t\tinow *= sinow[u];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate <class Mint> std::vector<Mint>\
    \ multiply(const std::vector<Mint>& a, const std::vector<Mint>& b) {\r\n\tint\
    \ n = int(a.size()), m = int(b.size());\r\n\tif (!n || !m) return {};\r\n\tif\
    \ (std::min(n, m) < 8) {\r\n\t\tstd::vector<Mint> ans(n + m - 1);\r\n\t\tfor (int\
    \ i = 0; i < n; i++)\r\n\t\t\tfor (int j = 0; j < m; j++) ans[i + j] += a[i] *\
    \ b[j];\r\n\t\treturn ans;\r\n\t}\r\n\tint lg = 0;\r\n\twhile ((1 << lg) < n +\
    \ m - 1) lg++;\r\n\tint z = 1 << lg;\r\n\tauto a2 = a;\r\n\ta2.resize(z);\r\n\t\
    butterfly(false, a2);\r\n\tif (a == b) {\r\n\t\tfor (int i = 0; i < z; i++) a2[i]\
    \ *= a2[i];\r\n\t} else {\r\n\t\tauto b2 = b;\r\n\t\tb2.resize(z);\r\n\t\tbutterfly(false,\
    \ b2);\r\n\t\tfor (int i = 0; i < z; i++) a2[i] *= b2[i];\r\n\t}\r\n\tbutterfly(true,\
    \ a2);\r\n\ta2.resize(n + m - 1);\r\n\tMint iz = 1 / Mint(z);\r\n\tfor (int i\
    \ = 0; i < n + m - 1; i++) a2[i] *= iz;\r\n\treturn a2;\r\n}\r\n\r\n}\n\r\ntemplate\
    \ <class D> struct Poly : std::vector<D> {\r\n\tusing std::vector<D>::vector;\r\
    \n\r\n\tstatic const int SMALL_DEGREE = 60;\r\n\r\n\tPoly(const std::vector<D>&\
    \ _v = {}) { \r\n\t\tfor (int i = 0; i < (int)_v.size(); ++i) {\r\n\t\t\tthis->push_back(_v[i]);\r\
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
    \ k, int n = -1) {\r\n\t\tif (n == -1) n = this->size();\r\n\t\tif (k == 0) {\r\
    \n\t\t\tPoly ret(n);\r\n\t\t\tif (n == 0) return ret;\r\n\t\t\tret[0] = 1;\r\n\
    \t\t\treturn ret;\r\n\t\t}\r\n\t\tint sz = (int)this->size();\r\n\t\tfor (int\
    \ i = 0; i < sz; ++i) {\r\n\t\t\tif (freq(i) != 0) {\r\n\t\t\t\tif ((i && k >\
    \ n) || i * k > n) return Poly(n);\r\n\t\t\t\tD rev = 1 / (*this)[i];\r\n\t\t\t\
    \tPoly ret = (((*this * rev) >> i).log(n) * k).exp(n) * _pow((*this)[i], k);\r\
    \n\t\t\t\tret = (ret << (i * k)).pre(n);\r\n\t\t\t\tret.resize(n);\r\n\t\t\t\t\
    return ret;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn Poly(n);\r\n\t}\r\n\r\n\tfriend\
    \ std::ostream& operator<<(std::ostream& os, const Poly& p) {\r\n\t\tif (p.empty())\
    \ return os << \"0\";\r\n\t\tfor (auto i = 0; i < (int)p.size(); i++) {\r\n\t\t\
    \tif (p[i]) {\r\n\t\t\t\tos << p[i] << \"x^\" << i;\r\n\t\t\t\tif (i != (int)p.size()\
    \ - 1) os << \"+\";\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn os;\r\n\t}\r\n};\n\r\n//\
    \ 5 is a root of both mods\r\ntemplate <int MOD, int RT> struct Mint {\r\n\tstatic\
    \ const int mod = MOD;\r\n\tstatic constexpr Mint rt() { return RT; } // primitive\
    \ root for FFT\r\n\tstatic constexpr int md() { return MOD; } // primitive root\
    \ for FFT\r\n\tint v; \r\n\texplicit operator int() const { return v; } // explicit\
    \ -> don't silently convert to int\r\n\texplicit operator bool() const { return\
    \ v != 0; }\r\n\tMint() { v = 0; }\r\n\tMint(long long _v) { v = int((-MOD <=\
    \ _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\r\n\tfriend bool operator==(const\
    \ Mint& a, const Mint& b) { return a.v == b.v; }\r\n\tfriend bool operator!=(const\
    \ Mint& a, const Mint& b) { return !(a == b); }\r\n\tfriend bool operator<(const\
    \ Mint& a, const Mint& b) { return a.v < b.v; }\r\n\tfriend bool operator>(const\
    \ Mint& a, const Mint& b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const\
    \ Mint& a, const Mint& b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const\
    \ Mint& a, const Mint& b) { return a.v >= b.v; }\r\n\tfriend std::istream& operator\
    \ >> (std::istream& in, Mint& a) { \r\n\t\tlong long x; std::cin >> x; a = Mint(x);\
    \ return in; }\r\n\tfriend std::ostream& operator << (std::ostream& os, const\
    \ Mint& a) { return os << a.v; }\r\n\tMint& operator+=(const Mint& m) { \r\n\t\
    \tif ((v += m.v) >= MOD) v -= MOD; \r\n\t\treturn *this; }\r\n\tMint& operator-=(const\
    \ Mint& m) { \r\n\t\tif ((v -= m.v) < 0) v += MOD; \r\n\t\treturn *this; }\r\n\
    \tMint& operator*=(const Mint& m) { \r\n\t\tv = (long long)v * m.v % MOD; return\
    \ *this; }\r\n\tMint& operator/=(const Mint& m) { return (*this) *= inv(m); }\r\
    \n\tfriend Mint pow(Mint a, long long p) {\r\n\t\tMint ans = 1; assert(p >= 0);\r\
    \n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n\t\treturn ans; \r\n\t\
    }\r\n\tfriend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD -\
    \ 2); }\r\n\tMint operator-() const { return Mint(-v); }\r\n\tMint& operator++()\
    \ { return *this += 1; }\r\n\tMint& operator--() { return *this -= 1; }\r\n\t\
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }\r\n\tfriend Mint\
    \ operator-(Mint a, const Mint& b) { return a -= b; }\r\n\tfriend Mint operator*(Mint\
    \ a, const Mint& b) { return a *= b; }\r\n\tfriend Mint operator/(Mint a, const\
    \ Mint& b) { return a /= b; }\r\n};\r\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\
    \nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n;\r\
    \n\tcin >> n;\r\n\tvector<mi> a(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\t\
    cin >> a[i];\r\n\t}\r\n\tPoly<mi> p(a);\r\n\tauto ans = p.exp(n);\r\n\tans.resize(n);\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tcout << ans[i] << ' ';\r\n\t}\r\n\tcout\
    \ << '\\n';\r\n\treturn 0;\t\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/polynomial/polynomial.hpp\"\r\n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\
    \r\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tvector<mi> a(n);\r\n\tfor (int\
    \ i = 0; i < n; ++i) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tPoly<mi> p(a);\r\n\tauto\
    \ ans = p.exp(n);\r\n\tans.resize(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\
    \tcout << ans[i] << ' ';\r\n\t}\r\n\tcout << '\\n';\r\n\treturn 0;\t\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/polynomial/polynomial.hpp
  - library/polynomial/number-theoretic-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2022-07-23 01:30:39-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
- /verify/verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp.html
title: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
---
