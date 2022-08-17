---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/polynomial/berlekamp-massey.hpp
    title: library/polynomial/berlekamp-massey.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/multipoint-evaluation.hpp
    title: library/polynomial/multipoint-evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/polynomial-sqrt.hpp
    title: library/polynomial/polynomial-sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/polynomial.hpp
    title: Formal Power Series
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-division_of_polynomials.test.cpp
    title: verify/yosupo/yosupo-division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-find_linear_recurrence.test.cpp
    title: verify/yosupo/yosupo-find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
    title: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nnamespace NTT {\r\n\r\nint bsf(unsigned int x) { return __builtin_ctz(x);\
    \ }\r\nint bsf(unsigned long long x) { return __builtin_ctzll(x); }\r\n\r\ntemplate\
    \ <class Mint> void nft(bool type, std::vector<Mint>& a) {\r\n\tint n = int(a.size()),\
    \ s = 0;\r\n\twhile ((1 << s) < n) s++;\r\n\tassert(1 << s == n);\r\n\tstatic\
    \ std::vector<Mint> ep, iep;\r\n\twhile (int(ep.size()) <= s) {\r\n\t\tep.push_back(pow(Mint::rt(),\
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
    \ = 0; i < n + m - 1; i++) a2[i] *= iz;\r\n\treturn a2;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\nnamespace NTT {\r\n\r\nint bsf(unsigned int x) { return\
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
    \ a2[i] *= iz;\r\n\treturn a2;\r\n}\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/polynomial/number-theoretic-transform.hpp
  requiredBy:
  - library/polynomial/polynomial-sqrt.hpp
  - library/polynomial/multipoint-evaluation.hpp
  - library/polynomial/polynomial.hpp
  - library/polynomial/berlekamp-massey.hpp
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-find_linear_recurrence.test.cpp
  - verify/yosupo/yosupo-division_of_polynomials.test.cpp
  - verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-multipoint_evaluation.test.cpp
documentation_of: library/polynomial/number-theoretic-transform.hpp
layout: document
redirect_from:
- /library/library/polynomial/number-theoretic-transform.hpp
- /library/library/polynomial/number-theoretic-transform.hpp.html
title: library/polynomial/number-theoretic-transform.hpp
---
