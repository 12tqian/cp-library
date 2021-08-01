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
    title: library/polynomial/polynomial.hpp
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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n\nnamespace NTT {\n\nint bsf(unsigned int x) { return __builtin_ctz(x); }\n\
    int bsf(unsigned long long x) { return __builtin_ctzll(x); }\n\ntemplate <class\
    \ Mint> void nft(bool type, std::vector<Mint>& a) {\n\tint n = int(a.size()),\
    \ s = 0;\n\twhile ((1 << s) < n) s++;\n\tassert(1 << s == n);\n\tstatic std::vector<Mint>\
    \ ep, iep;\n\twhile (int(ep.size()) <= s) {\n\t\tep.push_back(pow(Mint::rt(),\
    \ Mint(-1).v / (1 << ep.size())));\n\t\tiep.push_back(1 / ep.back());\n\t}\n\t\
    std::vector<Mint> b(n);\n\tfor (int i = 1; i <= s; i++) {\n\t\tint w = 1 << (s\
    \ - i);\n\t\tMint base = type ? iep[i] : ep[i], now = 1;\n\t\tfor (int y = 0;\
    \ y < n / 2; y += w) {\n\t\t\tfor (int x = 0; x < w; x++) {\n\t\t\t\tauto l =\
    \ a[y << 1 | x];\n\t\t\t\tauto r = now * a[y << 1 | x | w];\n\t\t\t\tb[y | x]\
    \ = l + r;\n\t\t\t\tb[y | x | n >> 1] = l - r;\n\t\t\t}\n\t\t\tnow *= base;\n\t\
    \t}\n\t\tswap(a, b);\n\t}\n}\n\ntemplate <class Mint> std::vector<Mint> multiply_nft(const\
    \ std::vector<Mint>& a, const std::vector<Mint>& b) {\n\tint n = int(a.size()),\
    \ m = int(b.size());\n\tif (!n || !m) return {};\n\tif (min(n, m) <= 8) {\n\t\t\
    std::vector<Mint> ans(n + m - 1);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor\
    \ (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];\n\t\treturn ans;\n\t}\n\t\
    int lg = 0;\n\twhile ((1 << lg) < n + m - 1) lg++;\n\tint z = 1 << lg;\n\tauto\
    \ a2 = a, b2 = b;\n\ta2.resize(z);\n\tb2.resize(z);\n\tnft(false, a2);\n\tnft(false,\
    \ b2);\n\tfor (int i = 0; i < z; i++) a2[i] *= b2[i];\n\tnft(true, a2);\n\ta2.resize(n\
    \ + m - 1);\n\tMint iz = 1 / Mint(z);\n\tfor (int i = 0; i < n + m - 1; i++) a2[i]\
    \ *= iz;\n\treturn a2;\n}\n\n// Cooley-Tukey: input -> butterfly -> bit reversing\
    \ -> output \n// bit reversing\ntemplate <class Mint> void butterfly(bool type,\
    \ std::vector<Mint>& a) {\n\tint n = int(a.size()), h = 0;\n\twhile ((1 << h)\
    \ < n) h++;\n\tassert(1 << h == n);\n\tif (n == 1) return;\n\n\tstatic std::vector<Mint>\
    \ snow, sinow;\n\tif (snow.empty()) {\n\t\tMint sep = Mint(1), siep = Mint(1);\n\
    \t\tunsigned int mod = Mint(-1).v;\n\t\tunsigned int di = 4;\n\t\twhile (mod %\
    \ di == 0) {\n\t\t\tMint ep = pow(Mint::rt(), mod / di);\n\t\t\tMint iep = 1 /\
    \ ep;\n\t\t\tsnow.push_back(siep * ep);\n\t\t\tsinow.push_back(sep * iep);\n\t\
    \t\tsep *= ep;\n\t\t\tsiep *= iep;\n\t\t\tdi *= 2;\n\t\t}\n\t}\n\tif (!type) {\n\
    \t\t// fft\n\t\tfor (int ph = 1; ph <= h; ph++) {\n\t\t\tint w = 1 << (ph - 1),\
    \ p = 1 << (h - ph);\n\t\t\tMint now = Mint(1);\n\t\t\tfor (int s = 0; s < w;\
    \ s++) {\n\t\t\t\tint offset = s << (h - ph + 1);\n\t\t\t\tfor (int i = 0; i <\
    \ p; i++) {\n\t\t\t\t\tauto l = a[i + offset];\n\t\t\t\t\tauto r = a[i + offset\
    \ + p] * now;\n\t\t\t\t\ta[i + offset] = l + r;\n\t\t\t\t\ta[i + offset + p] =\
    \ l - r;\n\t\t\t\t}\n\t\t\t\tint u = bsf(~(unsigned int)(s));\n\t\t\t\tnow *=\
    \ snow[u];\n\t\t\t}\n\t\t}\n\t} else {\n\t\t// ifft\n\t\tfor (int ph = h; ph >=\
    \ 1; ph--) {\n\t\t\tint w = 1 << (ph - 1), p = 1 << (h - ph);\n\t\t\tMint inow\
    \ = Mint(1);\n\t\t\tfor (int s = 0; s < w; s++) {\n\t\t\t\tint offset = s << (h\
    \ - ph + 1);\n\t\t\t\tfor (int i = 0; i < p; i++) {\n\t\t\t\t\tauto l = a[i +\
    \ offset];\n\t\t\t\t\tauto r = a[i + offset + p];\n\t\t\t\t\ta[i + offset] = l\
    \ + r;\n\t\t\t\t\ta[i + offset + p] = (l - r) * inow;\n\t\t\t\t}\n\t\t\t\tint\
    \ u = bsf(~(unsigned int)(s));\n\t\t\t\tinow *= sinow[u];\n\t\t\t}\n\t\t}\n\t\
    }\n}\n\ntemplate <class Mint> std::vector<Mint> multiply(const std::vector<Mint>&\
    \ a, const std::vector<Mint>& b) {\n\tint n = int(a.size()), m = int(b.size());\n\
    \tif (!n || !m) return {};\n\tif (min(n, m) < 8) {\n\t\tstd::vector<Mint> ans(n\
    \ + m - 1);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j < m; j++)\
    \ ans[i + j] += a[i] * b[j];\n\t\treturn ans;\n\t}\n\tint lg = 0;\n\twhile ((1\
    \ << lg) < n + m - 1) lg++;\n\tint z = 1 << lg;\n\tauto a2 = a;\n\ta2.resize(z);\n\
    \tbutterfly(false, a2);\n\tif (a == b) {\n\t\tfor (int i = 0; i < z; i++) a2[i]\
    \ *= a2[i];\n\t} else {\n\t\tauto b2 = b;\n\t\tb2.resize(z);\n\t\tbutterfly(false,\
    \ b2);\n\t\tfor (int i = 0; i < z; i++) a2[i] *= b2[i];\n\t}\n\tbutterfly(true,\
    \ a2);\n\ta2.resize(n + m - 1);\n\tMint iz = 1 / Mint(z);\n\tfor (int i = 0; i\
    \ < n + m - 1; i++) a2[i] *= iz;\n\treturn a2;\n}\n\n}\n\ntemplate <class D> struct\
    \ Poly : std::vector<D> {\n\tusing vector<D>::vector;\n\tPoly(const std::vector<D>&\
    \ _v = {}) { \n\t\tfor (int i = 0; i < (int)_v.size(); ++i) {\n\t\t\tthis->push_back(_v[i]);\n\
    \t\t}\n\t\tshrink(); \n\t}\n\n\tvoid shrink() {\n\t\twhile (this->size() && !this->back())\
    \ this->pop_back();\n\t}\n\n\tD freq(int p) const { return (p < (int)this->size())\
    \ ? (*this)[p] : D(0); }\n\t\n\tPoly operator+(const Poly& r) const {\n\t\tint\
    \ n = max(this->size(), r.size());\n\t\tstd::vector<D> res(n);\n\t\tfor (int i\
    \ = 0; i < n; i++) res[i] = freq(i) + r.freq(i);\n\t\treturn res;\n\t}\n\t\n\t\
    Poly operator-(const Poly& r) const {\n\t\tint n = max(this->size(), r.size());\n\
    \t\tstd::vector<D> res(n);\n\t\tfor (int i = 0; i < n; i++) res[i] = freq(i) -\
    \ r.freq(i);\n\t\treturn res;\n\t}\n\t\n\tPoly operator*(const Poly& r) const\
    \ { return {NTT::multiply((*this), r)}; }\n\t\n\tPoly operator*(const D& r) const\
    \ {\n\t\tint n = this->size();\n\t\tstd::vector<D> res(n);\n\t\tfor (int i = 0;\
    \ i < n; i++) res[i] = (*this)[i] * r;\n\t\treturn res;\n\t}\n\n\tPoly operator/(const\
    \ D &r) const{ return *this * (1 / r); }\n\t\n\tPoly operator/(const Poly& r)\
    \ const {\n\t\tif (this->size() < r.size()) return {{}};\n\t\tint n = (int)this->size()\
    \ - r.size() + 1;\n\t\treturn (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \t}\n\t\n\tPoly operator%(const Poly& r) const { return *this - *this / r * r;\
    \ }\n\t\n\tPoly operator<<(int s) const {\n\t\tstd::vector<D> res(this->size()\
    \ + s);\n\t\tfor (int i = 0; i < (int)this->size(); i++) res[i + s] = (*this)[i];\n\
    \t\treturn res;\n\t}\n\n\tPoly operator>>(int s) const {\n\t\tif ((int)this->size()\
    \ <= s) return Poly();\n\t\tstd::vector<D> res(this->size() - s);\n\t\tfor (int\
    \ i = 0; i < (int)this->size() - s; i++) res[i] = (*this)[i + s];\n\t\treturn\
    \ res;\n\t}\n\t\n\tPoly& operator+=(const Poly& r) { return *this = *this + r;\
    \ }\n\tPoly& operator-=(const Poly& r) { return *this = *this - r; }\n\tPoly&\
    \ operator*=(const Poly& r) { return *this = *this * r; }\n\tPoly& operator*=(const\
    \ D& r) { return *this = *this * r; }\n\tPoly& operator/=(const Poly& r) { return\
    \ *this = *this / r; }\n\tPoly& operator/=(const D &r) { return *this = *this\
    \ / r; }\n\tPoly& operator%=(const Poly& r) { return *this = *this % r; }\n\t\
    Poly& operator<<=(const size_t& n) { return *this = *this << n; }\n\tPoly& operator>>=(const\
    \ size_t& n) { return *this = *this >> n; }\n\tfriend Poly operator*(D const&\
    \ l, Poly r) { return r *= l; }\n\n\tPoly pre(int le) const { return Poly(this->begin(),\
    \ this->begin() + min((int)this->size(), le)); }\n\t\n\tPoly rev(int n = -1) const\
    \ {\n\t\tPoly res = *this;\n\t\tif (n != -1) res.resize(n);\n\t\treverse(res.begin(),\
    \ res.end());\n\t\treturn res;\n\t}\n\t\n\tPoly diff() const {\n\t\tstd::vector<D>\
    \ res(max(0, (int)this->size() - 1));\n\t\tfor (int i = 1; i < (int)this->size();\
    \ i++) res[i - 1] = freq(i) * i;\n\t\treturn res;\n\t}\n\t\n\tPoly inte() const\
    \ {\n\t\tstd::vector<D> res(this->size() + 1);\n\t\tfor (int i = 0; i < (int)this->size();\
    \ i++) res[i + 1] = freq(i) / (i + 1);\n\t\treturn res;\n\t}\n\n\t// f * f.inv()\
    \ = 1 + g(x)x^m\n\tPoly inv(int m = -1) const {\n\t\tif (m == -1) m = (int)this->size();\n\
    \t\tPoly res = Poly({D(1) / freq(0)});\n\t\tfor (int i = 1; i < m; i *= 2) {\n\
    \t\t\tres = (res * D(2) - res * res * pre(2 * i)).pre(2 * i);\n\t\t}\n\t\treturn\
    \ res.pre(m);\n\t}\n\t\n\tPoly exp(int n = -1) const {\n\t\tassert(freq(0) ==\
    \ 0);\n\t\tif (n == -1) n = (int)this->size();\n\t\tPoly f({1}), g({1});\n\t\t\
    for (int i = 1; i < n; i *= 2) {\n\t\t\tg = (g * 2 - f * g * g).pre(i);\n\t\t\t\
    Poly q = diff().pre(i - 1);\n\t\t\tPoly w = (q + g * (f.diff() - f * q)).pre(2\
    \ * i - 1);\n\t\t\tf = (f + f * (*this - w.inte()).pre(2 * i)).pre(2 * i);\n\t\
    \t}\n\t\treturn f.pre(n);\n\t}\n\t\n\tPoly log(int n = -1) const {\n\t\tif (n\
    \ == -1) n = (int)this->size();\n\t\tassert(freq(0) == 1);\n\t\tauto f = pre(n);\n\
    \t\treturn (f.diff() * f.inv(n - 1)).pre(n - 1).inte();\n\t}\n\n\tPoly pow_mod(const\
    \ Poly& mod, int n = -1) {\n\t\tif (n == -1) n = this->size();\n\t\tPoly x = *this,\
    \ r = {{1}};\n\t\twhile (n) {\n\t\t\tif (n & 1) r = r * x % mod;\n\t\t\tx = x\
    \ * x % mod;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn r;\n\t}\n\n\tD _pow(D x, long\
    \ long k) { \n\t\tD r = 1;\n\t\twhile (k) {\n\t\t\tif (k & 1) {\n\t\t\t\tr *=\
    \ x;\n\t\t\t}\n\t\t\tx *= x;\n\t\t\tk >>= 1;\n\t\t}\n\t\treturn r;\n\t}\n\n\t\
    Poly pow(long long k, int n = -1) {\n\t\tif (n == -1) n = this->size();\n\t\t\
    int sz = (int)this->size();\n\t\tfor (int i = 0; i < sz; ++i) {\n\t\t\tif (freq(i)\
    \ != 0) {\n\t\t\t\tif (i * k > n) return Poly(n);\n\t\t\t\tD rev = 1 / (*this)[i];\n\
    \t\t\t\tPoly ret = (((*this * rev) >> i).log(n) * k).exp(n) * _pow((*this)[i],\
    \ k);\n\t\t\t\tret = (ret << (i * k)).pre(n);\n\t\t\t\tret.resize(n);\n\t\t\t\t\
    return ret;\n\t\t\t}\n\t\t}\n\t\treturn Poly(n);\n\t}\n\n\tfriend ostream& operator<<(ostream&\
    \ os, const Poly& p) {\n\t\tif (p.empty()) return os << \"0\";\n\t\tfor (auto\
    \ i = 0; i < (int)p.size(); i++) {\n\t\t\tif (p[i]) {\n\t\t\t\tos << p[i] << \"\
    x^\" << i;\n\t\t\t\tif (i != (int)p.size() - 1) os << \"+\";\n\t\t\t}\n\t\t}\n\
    \t\treturn os;\n\t}\n};\n\n// 5 is a root of both mods\ntemplate <int MOD, int\
    \ RT> struct Mint {\n\tstatic const int mod = MOD;\n\tstatic constexpr Mint rt()\
    \ { return RT; } // primitive root for FFT\n\tstatic constexpr int md() { return\
    \ MOD; } // primitive root for FFT\n\tint v; \n\texplicit operator int() const\
    \ { return v; } // explicit -> don't silently convert to int\n\texplicit operator\
    \ bool() const { return v != 0; }\n\tMint() { v = 0; }\n\tMint(long long _v) {\
    \ v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\t\
    friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }\n\t\
    friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }\n\t\
    friend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }\n\t\
    friend bool operator>(const Mint &a, const Mint &b) { return a.v > b.v; }\n\t\
    friend bool operator<=(const Mint &a, const Mint &b) { return a.v <= b.v; }\n\t\
    friend bool operator>=(const Mint &a, const Mint &b) { return a.v >= b.v; }\n\t\
    friend std::istream& operator >> (std::istream &in, Mint &a) { \n\t\tlong long\
    \ x; std::cin >> x; a = Mint(x); return in; }\n\tfriend std::ostream& operator\
    \ << (std::ostream &os, const Mint &a) { return os << a.v; }\n\tMint& operator+=(const\
    \ Mint &m) { \n\t\tif ((v += m.v) >= MOD) v -= MOD; \n\t\treturn *this; }\n\t\
    Mint& operator-=(const Mint &m) { \n\t\tif ((v -= m.v) < 0) v += MOD; \n\t\treturn\
    \ *this; }\n\tMint& operator*=(const Mint &m) { \n\t\tv = (long long)v * m.v %\
    \ MOD; return *this; }\n\tMint& operator/=(const Mint &m) { return (*this) *=\
    \ inv(m); }\n\tfriend Mint pow(Mint a, long long p) {\n\t\tMint ans = 1; assert(p\
    \ >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans;\
    \ \n\t}\n\tfriend Mint inv(const Mint &a) { assert(a.v != 0); return pow(a, MOD\
    \ - 2); }\n\tMint operator-() const { return Mint(-v); }\n\tMint& operator++()\
    \ { return *this += 1; }\n\tMint& operator--() { return *this -= 1; }\n\tfriend\
    \ Mint operator+(Mint a, const Mint &b) { return a += b; }\n\tfriend Mint operator-(Mint\
    \ a, const Mint &b) { return a -= b; }\n\tfriend Mint operator*(Mint a, const\
    \ Mint &b) { return a *= b; }\n\tfriend Mint operator/(Mint a, const Mint &b)\
    \ { return a /= b; }\n};\n\nusing mi = Mint<998244353, 5>;\n\nint main() {\n\t\
    ios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n;\n\tcin >> n;\n\tvector<mi>\
    \ a(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tcin >> a[i];\n\t}\n\tPoly<mi> p(a);\n\
    \tauto ans = p.exp(n);\n\tans.resize(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\t\
    cout << ans[i] << ' ';\n\t}\n\tcout << '\\n';\n\treturn 0;\t\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/polynomial/polynomial.hpp\"\
    \n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n;\n\
    \tcin >> n;\n\tvector<mi> a(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tcin >> a[i];\n\
    \t}\n\tPoly<mi> p(a);\n\tauto ans = p.exp(n);\n\tans.resize(n);\n\tfor (int i\
    \ = 0; i < n; ++i) {\n\t\tcout << ans[i] << ' ';\n\t}\n\tcout << '\\n';\n\treturn\
    \ 0;\t\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/polynomial/polynomial.hpp
  - library/polynomial/number-theoretic-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2021-07-31 15:51:45-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
- /verify/verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp.html
title: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
---