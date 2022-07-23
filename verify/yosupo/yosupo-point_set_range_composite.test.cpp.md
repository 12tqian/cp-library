---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
    title: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  - icon: ':x:'
    path: library/math/affine.hpp
    title: library/math/affine.hpp
  - icon: ':question:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class D, class\
    \ L, class OpDD, class OpDL, class OpLL> struct LazySegmentTree {\r\n\tD e_d;\r\
    \n\tL e_l;\r\n\tOpDD op_dd; \r\n\tOpDL op_dl;\r\n\tOpLL op_ll;\r\n\tint sz, lg;\
    \  \r\n\tstd::vector<D> d;\r\n\tstd::vector<L> lz;\r\n\r\n\tvoid init(const std::vector<D>&\
    \ v) {\r\n\t\tint n = int(v.size());\r\n\t\tlg = 1;\r\n\t\twhile ((1 << lg) <\
    \ n) lg++;\r\n\t\tsz = 1 << lg;\r\n\t\td = std::vector<D>(2 * sz, e_d);\r\n\t\t\
    lz = std::vector<L>(2 * sz, e_l);\r\n\t\tfor (int i = 0; i < n; i++) d[sz + i]\
    \ = v[i];\r\n\t\tfor (int i = sz - 1; i >= 0; i--) {\r\n\t\t\tupdate(i);\r\n\t\
    \t}\r\n\t}\r\n\r\n\tLazySegmentTree(const std::vector<D>& v,\r\n\t\t\tD _e_d,\r\
    \n\t\t\tL _e_l,\r\n\t\t\tOpDD _op_dd,\r\n\t\t\tOpDL _op_dl,\r\n\t\t\tOpLL _op_ll)\r\
    \n\t\t: e_d(_e_d), e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl), op_ll(_op_ll) {\r\n\
    \t\tinit(v);\r\n\t}\r\n\r\n\tvoid all_add(int k, L x) {\r\n\t\td[k] = op_dl(d[k],\
    \ x);\r\n\t\tif (k < sz) lz[k] = op_ll(lz[k], x);\r\n\t}\r\n\r\n\tvoid push(int\
    \ k) {\r\n\t\tall_add(2 * k, lz[k]);\r\n\t\tall_add(2 * k + 1, lz[k]);\r\n\t\t\
    lz[k] = e_l;\r\n\t}\r\n\r\n\tvoid update(int k) { d[k] = op_dd(d[2 * k], d[2 *\
    \ k + 1]); }\r\n\r\n\tvoid set(int p, D x) {\r\n\t\tp += sz;\r\n\t\tfor (int i\
    \ = lg; i >= 1; i--) push(p >> i);\r\n\t\td[p] = x;\r\n\t\tfor (int i = 1; i <=\
    \ lg; i++) update(p >> i);\r\n\t}\r\n\r\n\tvoid add(int a, int b, L x, int l,\
    \ int r, int k) {\r\n\t\tif (b <= l || r <= a) return;\r\n\t\tif (a <= l && r\
    \ <= b) {\r\n\t\t\tall_add(k, x);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tpush(k);\r\n\
    \t\tint mid = (l + r) / 2;\r\n\t\tadd(a, b, x, l, mid, 2 * k);\r\n\t\tadd(a, b,\
    \ x, mid, r, 2 * k + 1);\r\n\t\tupdate(k);\r\n\t}\r\n\r\n\tvoid add(int a, int\
    \ b, L x) {\r\n\t\t++b;\r\n\t\ta += sz;\r\n\t\tb += sz;\r\n\t\tfor (int i = lg;\
    \ i >= 1; i--) {\r\n\t\t\tif (((a >> i) << i) != a) push(a >> i);\r\n\t\t\tif\
    \ (((b >> i) << i) != b) push((b - 1) >> i);\r\n\t\t}\r\n\t\t{\r\n\t\t\tint a2\
    \ = a, b2 = b;\r\n\t\t\twhile (a < b) {\r\n\t\t\t\tif (a & 1) all_add(a++, x);\r\
    \n\t\t\t\tif (b & 1) all_add(--b, x);\r\n\t\t\t\ta >>= 1;\r\n\t\t\t\tb >>= 1;\r\
    \n\t\t\t}\r\n\t\t\ta = a2;\r\n\t\t\tb = b2;\r\n\t\t}\r\n\t\tfor (int i = 1; i\
    \ <= lg; i++) {\r\n\t\t\tif (((a >> i) << i) != a) update(a >> i);\r\n\t\t\tif\
    \ (((b >> i) << i) != b) update((b - 1) >> i);\r\n\t\t}\r\n\t}\r\n\r\n\tD single(int\
    \ p) {\r\n\t\tp += sz;\r\n\t\tfor (int i = lg; i >= 1; i--) push(p >> i);\r\n\t\
    \treturn d[p];\r\n\t}\r\n\r\n\tD sum(int a, int b, int l, int r, int k) {\r\n\t\
    \tif (b <= l || r <= a) return e_d;\r\n\t\tif (a <= l && r <= b) return d[k];\r\
    \n\t\tpush(k);\r\n\t\tint mid = (l + r) / 2;\r\n\t\treturn op_dd(sum(a, b, l,\
    \ mid, 2 * k), sum(a, b, mid, r, 2 * k + 1));\r\n\t}\r\n\r\n\tD sum(int a, int\
    \ b) {\r\n\t\t++b;\r\n\t\tif (a == b) return e_d;\r\n\t\ta += sz;\r\n\t\tb +=\
    \ sz;\r\n\t\tfor (int i = lg; i >= 1; i--) {\r\n\t\t\tif (((a >> i) << i) != a)\
    \ push(a >> i);\r\n\t\t\tif (((b >> i) << i) != b) push((b - 1) >> i);\r\n\t\t\
    }\r\n\t\tD sml = e_d, smr = e_d;\r\n\t\twhile (a < b) {\r\n\t\t\tif (a & 1) sml\
    \ = op_dd(sml, d[a++]);\r\n\t\t\tif (b & 1) smr = op_dd(d[--b], smr);\r\n\t\t\t\
    a >>= 1;\r\n\t\t\tb >>= 1;\r\n\t\t}\r\n\t\treturn op_dd(sml, smr);\r\n\t}\r\n\r\
    \n\tD all_sum() const { return d[1]; }\r\n};\r\n\r\ntemplate <class D, class L,\
    \ class OpDD, class OpDL, class OpLL>\r\nLazySegmentTree<D, L, OpDD, OpDL, OpLL>\
    \ get_lazy_segment_tree(std::vector<D> v,\r\n\t\t\t\t\t\t\t\t\t\tD e_d,\r\n\t\t\
    \t\t\t\t\t\t\t\tL e_l,\r\n\t\t\t\t\t\t\t\t\t\tOpDD op_dd,\r\n\t\t\t\t\t\t\t\t\t\
    \tOpDL op_dl,\r\n\t\t\t\t\t\t\t\t\t\tOpLL op_ll) {\r\n\treturn LazySegmentTree<D,\
    \ L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl, op_ll);\r\n}\r\n\r\n// 5 is\
    \ a root of both mods\r\ntemplate <int MOD, int RT> struct Mint {\r\n\tstatic\
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
    \ Mint& b) { return a /= b; }\r\n};\r\n\r\ntemplate <class T> struct Affine {\r\
    \n\tT a, b;\r\n\t\r\n\tconstexpr Affine() : a(1), b(0) {}\r\n\tconstexpr Affine(T\
    \ _a, T _b) : a(_a), b(_b) {}\r\n\tconstexpr Affine(T _b) : a(0), b(_b) {}\r\n\
    \r\n\tT operator()(T x) { return a * x + b; }\r\n\t\r\n\tAffine operator-() {\
    \ return Affine(-a, -b); }\r\n\t\r\n\tfriend Affine operator*(const Affine& l,\
    \ const Affine& r) {\r\n\t\treturn Affine(l.a * r.a, l.b * r.a + r.b); }\r\n\t\
    friend Affine operator-(const Affine& l, const Affine& r) { return Affine(l.a\
    \ - r.a, l.b - r.b); }\r\n\tfriend Affine operator+(const Affine& l, const Affine&\
    \ r) { return Affine(l.a + r.a, l.b + r.b); }\r\n\t\r\n\tfriend Affine operator+(const\
    \ Affine& l, const T& r) { return Affine(l.a, l.b + r); }\r\n\tfriend Affine operator-(const\
    \ Affine& l, const T& r) { return Affine(l.a, l.b - r); }\r\n\tfriend Affine operator*(const\
    \ Affine& l, const T& r) { return Affine(l.a * r, l.b * r); }\r\n\tfriend Affine\
    \ operator/(const Affine& l, const T& r) { return Affine(l.a / r, l.b / r); }\r\
    \n\r\n\tfriend Affine operator+(const T& l, Affine& r) { return r + l; }\r\n\t\
    friend Affine operator-(const T& l, Affine& r) { return -r + l; }\r\n\tfriend\
    \ Affine operator*(const T& l, Affine& r) { return r * l; }\r\n\t\r\n\tfriend\
    \ Affine& operator+=(Affine& l, const Affine& r) { return l = l + r; }\r\n\tfriend\
    \ Affine& operator-=(Affine& l, const Affine& r) { return l = l - r; }\r\n\tfriend\
    \ Affine& operator*=(Affine& l, const Affine& r) { return l = l * r; }\r\n\r\n\
    \tfriend Affine& operator+=(Affine& l, const T& r) { return l = l + r; }\r\n\t\
    friend Affine& operator-=(Affine& l, const T& r) { return l = l - r; }\r\n\tfriend\
    \ Affine& operator*=(Affine& l, const T& r) { return l = l * r; }\r\n\r\n\tbool\
    \ operator==(const Affine& r) const { return a == r.a && b == r.b; }\r\n\tbool\
    \ operator!=(const Affine& r) const { return a != r.a || b != r.b; }\r\n\r\n\t\
    friend ostream& operator<<(ostream& os, const Affine& r) {\r\n\t\tos << \"( \"\
    \ << r.a << \", \" << r.b << \" )\"; return os; }\r\n};\n\r\nusing mi = Mint<998244353,\
    \ 5>;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, q;\r\n\tcin >> n >> q;\r\n\tconst Affine<mi> ID = {1, 0};\r\n\tauto\
    \ comb = [&](Affine<mi> x, Affine<mi> y) {\r\n\t\treturn x * y;\r\n\t};\r\n\t\
    vector<Affine<mi>> v(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tcin >> v[i].a\
    \ >> v[i].b;\r\n\t}\r\n\tauto seg = get_lazy_segment_tree(\r\n\t\tv, ID, ID, comb,\
    \ comb, comb\r\n\t);\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\t\
    if (t == 0) {\r\n\t\t\tint p, c, d;\r\n\t\t\tcin >> p >> c >> d;\r\n\t\t\tseg.set(p,\
    \ {c, d});\r\n\t\t} else {\r\n\t\t\tint l, r, x;\r\n\t\t\tcin >> l >> r >> x;\r\
    \n\t\t\t--r;\r\n\t\t\tauto res = seg.sum(l, r);\r\n\t\t\tcout << res(x) << '\\\
    n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/data-structures/1d-range-queries/general-full-segment-tree.hpp\"\
    \r\n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\r\n#include \"\
    ../../library/math/affine.hpp\"\r\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\n\
    int main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint\
    \ n, q;\r\n\tcin >> n >> q;\r\n\tconst Affine<mi> ID = {1, 0};\r\n\tauto comb\
    \ = [&](Affine<mi> x, Affine<mi> y) {\r\n\t\treturn x * y;\r\n\t};\r\n\tvector<Affine<mi>>\
    \ v(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tcin >> v[i].a >> v[i].b;\r\n\
    \t}\r\n\tauto seg = get_lazy_segment_tree(\r\n\t\tv, ID, ID, comb, comb, comb\r\
    \n\t);\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\
    \n\t\t\tint p, c, d;\r\n\t\t\tcin >> p >> c >> d;\r\n\t\t\tseg.set(p, {c, d});\r\
    \n\t\t} else {\r\n\t\t\tint l, r, x;\r\n\t\t\tcin >> l >> r >> x;\r\n\t\t\t--r;\r\
    \n\t\t\tauto res = seg.sum(l, r);\r\n\t\t\tcout << res(x) << '\\n';\r\n\t\t}\r\
    \n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  - library/modular-arithmetic/mod-int2.hpp
  - library/math/affine.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_set_range_composite.test.cpp
- /verify/verify/yosupo/yosupo-point_set_range_composite.test.cpp.html
title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
---
