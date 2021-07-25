---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/affine-segment-tree.hpp
    title: library/data-structures/1d-range-queries/affine-segment-tree.hpp
  - icon: ':x:'
    path: library/numerical/mod-int.hpp
    title: library/numerical/mod-int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://atcoder.jp/contests/practice2/tasks/practice2_k
  bundledCode: "#define IGNORE\n// #define PROBLEM \"https://atcoder.jp/contests/practice2/tasks/practice2_k\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\nconst int\
    \ MOD = 1e9 + 7;\n\ntypedef std::decay<decltype(MOD)>::type mod_t; \nstruct mi\
    \ {\n\tmod_t val;\n\texplicit operator mod_t() const { return val; }\n\tmi() {\
    \ val = 0; }\n\tmi(const long long &v) {\n\t\tval = (-MOD <= v && v <= MOD) ?\
    \ v : v % MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend std::istream& operator>>(std::istream\
    \ &in, mi &a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\t\
    friend std::ostream& operator<<(std::ostream &os, const mi &a) { return os <<\
    \ a.val; }\n\tfriend bool operator==(const mi &a, const mi &b) { return a.val\
    \ == b.val; }\n\tfriend bool operator!=(const mi &a, const mi &b) { return !(a\
    \ == b); }    \n\tfriend bool operator<(const mi &a, const mi &b) { return a.val\
    \ < b.val; }\n\tfriend bool operator>(const mi &a, const mi &b) { return a.val\
    \ > b.val; }\n\tfriend bool operator<=(const mi &a, const mi &b) { return a.val\
    \ <= b.val; }\n\tfriend bool operator>=(const mi &a, const mi &b) { return a.val\
    \ >= b.val; }\n\tmi operator-() const { return mi(-val); }\n\tmi& operator+=(const\
    \ mi &m) {\n\t\tif ((val += m.val) >= MOD) val -= MOD;\n\t\treturn *this; }\n\t\
    mi& operator-=(const mi &m) {\n\t\tif ((val -= m.val) < 0) val += MOD;\n\t\treturn\
    \ *this; }\n\tmi& operator*=(const mi &m) { val = (long long)val * m.val % MOD;\n\
    \t\treturn *this; }\n\tfriend mi pow(mi a, long long p) {\n\t\tmi ans = 1; assert(p\
    \ >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans;\
    \ }\n\tfriend mi inv(const mi &a) { assert(a != 0); return pow(a, MOD - 2); }\n\
    \tmi& operator/=(const mi &m) { return (*this) *= inv(m); }\n\tfriend mi operator+(mi\
    \ a, const mi &b) { return a += b; }\n\tfriend mi operator-(mi a, const mi &b)\
    \ { return a -= b; }\n\tfriend mi operator*(mi a, const mi &b) { return a *= b;\
    \ }\n\tfriend mi operator/(mi a, const mi &b) { return a /= b; }\n};\n\ntemplate\
    \ <class T> struct AffineSegmentTree {\n\tint sz;\n\tstd::vector<T> sum, mult,\
    \ add;\n\n\tvoid push(int ind, int L, int R) { // modify values for current node\n\
    \t\tsum[ind] *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\n\t\tif (L != R)\
    \ {\n\t\t\tmult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\n\t\t\t\
    add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\n\t\t\tadd[2 * ind + 1] *=\
    \ mult[ind]; add[2 * ind + 1] += add[ind];\n\t\t}\n\t\tadd[ind] = 0; mult[ind]\
    \ = 1;\n\t}\n\n\tvoid init(int n) {\n\t\tsz = 1;\n\t\twhile (sz < n) sz *= 2;\n\
    \t\tmult.assign(2 * sz, 1);\n\t\tsum.assign(2 * sz, 0);\n\t\tadd.assign(2 * sz,\
    \ 0);\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind\
    \ + 1];\n\t}\n\n\t// t == 0 is add, t == 1 is for multiplying\n\tvoid upd(int\
    \ t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R ==\
    \ -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi < L || R < lo) return;\n\t\t\
    if (lo <= L && R <= hi) {\n\t\t\tif(t == 0) add[ind] = inc;  \n\t\t\telse mult[ind]\
    \ = inc;\n\t\t\tpush(ind, L, R); return;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\t\
    upd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1, M + 1, R);\n\
    \t\tpull(ind);\n\t}\n\t\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (lo > R ||\
    \ L > hi) return 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint M =\
    \ (L + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind\
    \ + 1, M + 1, R);\n\t}\n};\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    cin.tie(0);\n    AffineSegmentTree<mi> seg;\n    int n, q;\n    seg.init(n);\n\
    \    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++) {\n\
    \        cin >> a[i];\n        seg.upd(i, i, 0, a[i]);\n    }\n    while (q--)\
    \ {\t\n        int t;\n        cin >> t;\n        if (t == 0) {\n            int\
    \ l, r, b, c;\n            cin >> l >> r >> b >> c;\n            seg.upd(l, r\
    \ - 1, 1, b);\n            seg.upd(l, r - 1, 0, c);\n        } else {\n      \
    \      int l, r;\n            cin >> l >> r;\n            cout << seg.qsum(l,\
    \ r - 1) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define IGNORE\n// #define PROBLEM \"https://atcoder.jp/contests/practice2/tasks/practice2_k\"\
    \n\n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/numerical/mod-int.hpp\"\
    \n#include \"../library/data-structures/1d-range-queries/affine-segment-tree.hpp\"\
    \n\nint main() {\n    ios_base::sync_with_stdio(0);\n    cin.tie(0);\n    AffineSegmentTree<mi>\
    \ seg;\n    int n, q;\n    seg.init(n);\n    cin >> n >> q;\n    vector<int> a(n);\n\
    \    for (int i = 0; i < n; i++) {\n        cin >> a[i];\n        seg.upd(i, i,\
    \ 0, a[i]);\n    }\n    while (q--) {\t\n        int t;\n        cin >> t;\n \
    \       if (t == 0) {\n            int l, r, b, c;\n            cin >> l >> r\
    \ >> b >> c;\n            seg.upd(l, r - 1, 1, b);\n            seg.upd(l, r -\
    \ 1, 0, c);\n        } else {\n            int l, r;\n            cin >> l >>\
    \ r;\n            cout << seg.qsum(l, r - 1) << '\\n';\n        }\n    }\n   \
    \ return 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/mod-int.hpp
  - library/data-structures/1d-range-queries/affine-segment-tree.hpp
  isVerificationFile: true
  path: test/affine-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 20:23:37-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/affine-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/test/affine-segment-tree.test.cpp
- /verify/test/affine-segment-tree.test.cpp.html
title: test/affine-segment-tree.test.cpp
---
