---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
    title: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/affine.hpp
    title: library/math/affine.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class D, class L, class OpDD, class OpDL, class OpLL> struct LazySegmentTree\
    \ {\n\tD e_d;\n\tL e_l;\n\tOpDD op_dd; \n\tOpDL op_dl;\n\tOpLL op_ll;\n\tint sz,\
    \ lg;  \n\tstd::vector<D> d;\n\tstd::vector<L> lz;\n\n\tvoid init(const std::vector<D>&\
    \ v) {\n\t\tint n = int(v.size());\n\t\tlg = 1;\n\t\twhile ((1 << lg) < n) lg++;\n\
    \t\tsz = 1 << lg;\n\t\td = std::vector<D>(2 * sz, e_d);\n\t\tlz = std::vector<L>(2\
    \ * sz, e_l);\n\t\tfor (int i = 0; i < n; i++) d[sz + i] = v[i];\n\t\tfor (int\
    \ i = sz - 1; i >= 0; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\n\tLazySegmentTree(const\
    \ std::vector<D>& v,\n\t\t\tD _e_d,\n\t\t\tL _e_l,\n\t\t\tOpDD _op_dd,\n\t\t\t\
    OpDL _op_dl,\n\t\t\tOpLL _op_ll)\n\t\t: e_d(_e_d), e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl),\
    \ op_ll(_op_ll) {\n\t\tinit(v);\n\t}\n\n\tvoid all_add(int k, L x) {\n\t\td[k]\
    \ = op_dl(d[k], x);\n\t\tif (k < sz) lz[k] = op_ll(lz[k], x);\n\t}\n\n\tvoid push(int\
    \ k) {\n\t\tall_add(2 * k, lz[k]);\n\t\tall_add(2 * k + 1, lz[k]);\n\t\tlz[k]\
    \ = e_l;\n\t}\n\n\tvoid update(int k) { d[k] = op_dd(d[2 * k], d[2 * k + 1]);\
    \ }\n\n\tvoid set(int p, D x) {\n\t\tp += sz;\n\t\tfor (int i = lg; i >= 1; i--)\
    \ push(p >> i);\n\t\td[p] = x;\n\t\tfor (int i = 1; i <= lg; i++) update(p >>\
    \ i);\n\t}\n\n\tvoid add(int a, int b, L x, int l, int r, int k) {\n\t\tif (b\
    \ <= l || r <= a) return;\n\t\tif (a <= l && r <= b) {\n\t\t\tall_add(k, x);\n\
    \t\t\treturn;\n\t\t}\n\t\tpush(k);\n\t\tint mid = (l + r) / 2;\n\t\tadd(a, b,\
    \ x, l, mid, 2 * k);\n\t\tadd(a, b, x, mid, r, 2 * k + 1);\n\t\tupdate(k);\n\t\
    }\n\n\tvoid add(int a, int b, L x) {\n\t\t++b;\n\t\ta += sz;\n\t\tb += sz;\n\t\
    \tfor (int i = lg; i >= 1; i--) {\n\t\t\tif (((a >> i) << i) != a) push(a >> i);\n\
    \t\t\tif (((b >> i) << i) != b) push((b - 1) >> i);\n\t\t}\n\t\t{\n\t\t\tint a2\
    \ = a, b2 = b;\n\t\t\twhile (a < b) {\n\t\t\t\tif (a & 1) all_add(a++, x);\n\t\
    \t\t\tif (b & 1) all_add(--b, x);\n\t\t\t\ta >>= 1;\n\t\t\t\tb >>= 1;\n\t\t\t\
    }\n\t\t\ta = a2;\n\t\t\tb = b2;\n\t\t}\n\t\tfor (int i = 1; i <= lg; i++) {\n\t\
    \t\tif (((a >> i) << i) != a) update(a >> i);\n\t\t\tif (((b >> i) << i) != b)\
    \ update((b - 1) >> i);\n\t\t}\n\t}\n\n\tD single(int p) {\n\t\tp += sz;\n\t\t\
    for (int i = lg; i >= 1; i--) push(p >> i);\n\t\treturn d[p];\n\t}\n\n\tD sum(int\
    \ a, int b, int l, int r, int k) {\n\t\tif (b <= l || r <= a) return e_d;\n\t\t\
    if (a <= l && r <= b) return d[k];\n\t\tpush(k);\n\t\tint mid = (l + r) / 2;\n\
    \t\treturn op_dd(sum(a, b, l, mid, 2 * k), sum(a, b, mid, r, 2 * k + 1));\n\t\
    }\n\n\tD sum(int a, int b) {\n\t\t++b;\n\t\tif (a == b) return e_d;\n\t\ta +=\
    \ sz;\n\t\tb += sz;\n\t\tfor (int i = lg; i >= 1; i--) {\n\t\t\tif (((a >> i)\
    \ << i) != a) push(a >> i);\n\t\t\tif (((b >> i) << i) != b) push((b - 1) >> i);\n\
    \t\t}\n\t\tD sml = e_d, smr = e_d;\n\t\twhile (a < b) {\n\t\t\tif (a & 1) sml\
    \ = op_dd(sml, d[a++]);\n\t\t\tif (b & 1) smr = op_dd(d[--b], smr);\n\t\t\ta >>=\
    \ 1;\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn op_dd(sml, smr);\n\t}\n\n\tD all_sum()\
    \ const { return d[1]; }\n};\n\ntemplate <class D, class L, class OpDD, class\
    \ OpDL, class OpLL>\nLazySegmentTree<D, L, OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D>\
    \ v,\n\t\t\t\t\t\t\t\t\t\tD e_d,\n\t\t\t\t\t\t\t\t\t\tL e_l,\n\t\t\t\t\t\t\t\t\
    \t\tOpDD op_dd,\n\t\t\t\t\t\t\t\t\t\tOpDL op_dl,\n\t\t\t\t\t\t\t\t\t\tOpLL op_ll)\
    \ {\n\treturn LazySegmentTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl,\
    \ op_ll);\n}\n\n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct\
    \ Mint {\n\tstatic const int mod = MOD;\n\tstatic constexpr Mint rt() { return\
    \ RT; } // primitive root for FFT\n\tstatic constexpr int md() { return MOD; }\
    \ // primitive root for FFT\n\tint v; \n\texplicit operator int() const { return\
    \ v; } // explicit -> don't silently convert to int\n\texplicit operator bool()\
    \ const { return v != 0; }\n\tMint() { v = 0; }\n\tMint(long long _v) { v = int((-MOD\
    \ <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const\
    \ Mint& a, const Mint& b) { return a.v == b.v; }\n\tfriend bool operator!=(const\
    \ Mint& a, const Mint& b) { return !(a == b); }\n\tfriend bool operator<(const\
    \ Mint& a, const Mint& b) { return a.v < b.v; }\n\tfriend bool operator>(const\
    \ Mint& a, const Mint& b) { return a.v > b.v; }\n\tfriend bool operator<=(const\
    \ Mint& a, const Mint& b) { return a.v <= b.v; }\n\tfriend bool operator>=(const\
    \ Mint& a, const Mint& b) { return a.v >= b.v; }\n\tfriend std::istream& operator\
    \ >> (std::istream& in, Mint& a) { \n\t\tlong long x; std::cin >> x; a = Mint(x);\
    \ return in; }\n\tfriend std::ostream& operator << (std::ostream& os, const Mint&\
    \ a) { return os << a.v; }\n\tMint& operator+=(const Mint& m) { \n\t\tif ((v +=\
    \ m.v) >= MOD) v -= MOD; \n\t\treturn *this; }\n\tMint& operator-=(const Mint&\
    \ m) { \n\t\tif ((v -= m.v) < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const\
    \ Mint& m) { \n\t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const\
    \ Mint& m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long\
    \ p) {\n\t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint& a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint& b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint& b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint& b) { return a /= b; }\n};\n\ntemplate <class T>\
    \ struct Affine {\n\tT a, b;\n\t\n\tconstexpr Affine() : a(1), b(0) {}\n\tconstexpr\
    \ Affine(T _a, T _b) : a(_a), b(_b) {}\n\tconstexpr Affine(T _b) : a(0), b(_b)\
    \ {}\n\n\tT operator()(T x) { return a * x + b; }\n\t\n\tAffine operator-() {\
    \ return Affine(-a, -b); }\n\t\n\tfriend Affine operator*(const Affine& l, const\
    \ Affine& r) {\n\t\treturn Affine(l.a * r.a, l.b * r.a + r.b); }\n\tfriend Affine\
    \ operator-(const Affine& l, const Affine& r) { return Affine(l.a - r.a, l.b -\
    \ r.b); }\n\tfriend Affine operator+(const Affine& l, const Affine& r) { return\
    \ Affine(l.a + r.a, l.b + r.b); }\n\t\n\tfriend Affine operator+(const Affine&\
    \ l, const T& r) { return Affine(l.a, l.b + r); }\n\tfriend Affine operator-(const\
    \ Affine& l, const T& r) { return Affine(l.a, l.b - r); }\n\tfriend Affine operator*(const\
    \ Affine& l, const T& r) { return Affine(l.a * r, l.b * r); }\n\tfriend Affine\
    \ operator/(const Affine& l, const T& r) { return Affine(l.a / r, l.b / r); }\n\
    \n\tfriend Affine operator+(const T& l, Affine& r) { return r + l; }\n\tfriend\
    \ Affine operator-(const T& l, Affine& r) { return -r + l; }\n\tfriend Affine\
    \ operator*(const T& l, Affine& r) { return r * l; }\n\t\n\tfriend Affine& operator+=(Affine&\
    \ l, const Affine& r) { return l = l + r; }\n\tfriend Affine& operator-=(Affine&\
    \ l, const Affine& r) { return l = l - r; }\n\tfriend Affine& operator*=(Affine&\
    \ l, const Affine& r) { return l = l * r; }\n\n\tfriend Affine& operator+=(Affine&\
    \ l, const T& r) { return l = l + r; }\n\tfriend Affine& operator-=(Affine& l,\
    \ const T& r) { return l = l - r; }\n\tfriend Affine& operator*=(Affine& l, const\
    \ T& r) { return l = l * r; }\n\n\tbool operator==(const Affine& r) const { return\
    \ a == r.a && b == r.b; }\n\tbool operator!=(const Affine& r) const { return a\
    \ != r.a || b != r.b; }\n\n\tfriend ostream& operator<<(ostream& os, const Affine&\
    \ r) {\n\t\tos << \"( \" << r.a << \", \" << r.b << \" )\"; return os; }\n};\n\
    \nusing mi = Mint<998244353, 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tconst Affine<mi> ID = {1,\
    \ 0};\n\tauto comb = [&](Affine<mi> x, Affine<mi> y) {\n\t\treturn x * y;\n\t\
    };\n\tvector<Affine<mi>> v(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tcin >> v[i].a\
    \ >> v[i].b;\n\t}\n\tauto seg = get_lazy_segment_tree(\n\t\tv, ID, ID, comb, comb,\
    \ comb\n\t);\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\
    \t\tint p, c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\tseg.set(p, {c, d});\n\t\t}\
    \ else {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\t--r;\n\t\t\tauto\
    \ res = seg.sum(l, r);\n\t\t\tcout << res(x) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/general-full-segment-tree.hpp\"\
    \n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\n#include \"../../library/math/affine.hpp\"\
    \n\nusing mi = Mint<998244353, 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tconst Affine<mi> ID = {1,\
    \ 0};\n\tauto comb = [&](Affine<mi> x, Affine<mi> y) {\n\t\treturn x * y;\n\t\
    };\n\tvector<Affine<mi>> v(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tcin >> v[i].a\
    \ >> v[i].b;\n\t}\n\tauto seg = get_lazy_segment_tree(\n\t\tv, ID, ID, comb, comb,\
    \ comb\n\t);\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\
    \t\tint p, c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\tseg.set(p, {c, d});\n\t\t}\
    \ else {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\t--r;\n\t\t\tauto\
    \ res = seg.sum(l, r);\n\t\t\tcout << res(x) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  - library/modular-arithmetic/mod-int2.hpp
  - library/math/affine.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2021-08-18 22:34:30-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_set_range_composite.test.cpp
- /verify/verify/yosupo/yosupo-point_set_range_composite.test.cpp.html
title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
---
