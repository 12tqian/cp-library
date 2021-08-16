---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/range-vector.hpp
    title: library/misc/range-vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/1542/problem/E2
    links:
    - https://codeforces.com/contest/1542/problem/E2
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1542/problem/E2\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class T> class range_vector : public std::vector<T> {\npublic:\n\t\
    int min_index;\n\n\trange_vector() : min_index(0) {}\n\n\trange_vector(int _min_index,\
    \ int _max_index, T&& values = T())\n\t\t: std::vector<T>(_max_index - _min_index\
    \ + 1, values), min_index(_min_index) {\n\t\tassert(_min_index <= _max_index +\
    \ 1);\n\t}\n\t\n\trange_vector(int _max_index, T&& values = T())\n\t\t: std::vector<T>(_max_index\
    \ + 1, values), min_index(0) {\n\t\tassert(0 <= _max_index + 1);\n\t}\n\t\n\t\
    T& operator[](int i) { std::vector<T>& self = *this; return self[i - min_index];\
    \ }\n};\n\nstruct FastMod {\n\tunsigned long long b, m;\n\tFastMod(unsigned long\
    \ long b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}\n\tunsigned\
    \ long long reduce(unsigned long long a) {\n\t\tunsigned long long q = (unsigned\
    \ long long)((__uint128_t(m) * a) >> 64);\n\t\tunsigned long long r = a - q *\
    \ b; // can be proven that 0 <= r < 2*b\n\t\treturn r >= b ? r - b : r;\n\t}\n\
    };\n\nFastMod F(2);\n\nint MOD = 2;\n\ntypedef decay<decltype(MOD)>::type mod_t;\n\
    \nstruct mi {\n\tmod_t val;\n\texplicit operator mod_t() const { return val; }\n\
    \tmi() { val = 0; }\n\tmi(const long long& v) {\n\t\tval = (-MOD <= v && v < MOD)\
    \ ? v : v % MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend istream& operator>>(istream&\
    \ in, mi& a) { \n\t\tlong long x; cin >> x; a = mi(x); return in; }\n\tfriend\
    \ ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }\n\tfriend\
    \ bool operator==(const mi& a, const mi& b) { return a.val == b.val; }\n\tfriend\
    \ bool operator!=(const mi& a, const mi& b) { return !(a == b); }    \n\tfriend\
    \ bool operator<(const mi& a, const mi& b) { return a.val < b.val; }\n\tfriend\
    \ bool operator>(const mi& a, const mi& b) { return a.val > b.val; }\n\tfriend\
    \ bool operator<=(const mi& a, const mi& b) { return a.val <= b.val; }\n\tfriend\
    \ bool operator>=(const mi& a, const mi& b) { return a.val >= b.val; }\n\tmi operator-()\
    \ const { return mi(-val); }\n\tmi& operator+=(const mi& m) {\n\t\tif ((val +=\
    \ m.val) >= MOD) val -= MOD;\n\t\treturn *this; }\n\tmi& operator-=(const mi&\
    \ m) {\n\t\tif ((val -= m.val) < 0) val += MOD;\n\t\treturn *this; }\n\tmi& operator*=(const\
    \ mi& m) { \n\t\tval = F.reduce((long long)val * m.val);\n\t\treturn *this; }\n\
    \tfriend mi pow(mi a, long long p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\tfor\
    \ (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans; }\n\tfriend mi inv(const\
    \ mi& a) { assert(a != 0); return pow(a, MOD - 2); }\n\tmi& operator/=(const mi&\
    \ m) { return (*this) *= inv(m); }\n\tfriend mi operator+(mi a, const mi& b) {\
    \ return a += b; }\n\tfriend mi operator-(mi a, const mi& b) { return a -= b;\
    \ }\n\tfriend mi operator*(mi a, const mi& b) { return a *= b; }\n\tfriend mi\
    \ operator/(mi a, const mi& b) { return a /= b; }\n};\n\nconst int N = 505;\n\
    const int I = N * (N - 1) / 2;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n; \n\tcin >> n >> MOD;\n\tF = FastMod(MOD);\n\tint\
    \ c2 = n * (n - 1) / 2;\n\tvector<vector<mi>> C(n + 1, vector<mi>(n + 1));\n\t\
    vector<mi> fact(n + 1);\n\tvector<vector<mi>> dp(n, vector<mi>(c2 + 1));\n\trange_vector<mi>\
    \ diff, pdiff, p1, p2, use;\n\tC[0][0] = 1;\n\tfor (int i = 1; i <= n; ++i) {\n\
    \t\tfor (int j = 0; j <= n; ++j) {\n\t\t\tC[i][j] = C[i - 1][j] + (j ? C[i - 1][j\
    \ - 1] : 0);\n\t\t}\n\t}\n\tmi ans = 0;\n\tfact[0] = 1;\n\tfor (int i = 1; i <=\
    \ n; ++i) {\n\t\tfact[i] = fact[i - 1] * i;\n\t}\n\tp1 = p2 = diff = pdiff = range_vector<mi>(-c2\
    \ - 1, c2 + 1, 0);\n\tuse.resize(c2 + 1);\n\tfor (int i = 4; i <= n; ++i) {\n\t\
    \tint m = i - 1;\n\t\tint inv = m * (m - 1) / 2;\n\t\tif (m == 3) {\n\t\t\tfunction<mi(int,\
    \ int)> solve = [&](int n, int k) {\n\t\t\t\tvector<int> a(n);\n\t\t\t\tiota(a.begin(),\
    \ a.end(), 0);\n\t\t\t\tmi res = 0;\n\t\t\t\tdo {\n\t\t\t\t\tint cnt = 0;\n\t\t\
    \t\t\tfor (int i = 0; i < n; ++i) {\n\t\t\t\t\t\tfor (int j = i + 1; j < n; ++j)\
    \ {\n\t\t\t\t\t\t\tif (a[i] > a[j]) {\n\t\t\t\t\t\t\t\t++cnt;\n\t\t\t\t\t\t\t\
    }\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tif (cnt == k) {\n\t\t\t\t\t\tres += 1;\n\
    \t\t\t\t\t}\n\t\t\t\t} while (next_permutation(a.begin(), a.end()));\n\t\t\t\t\
    return res;\n\t\t\t};\n\t\t\tfor (int jj = 0; jj <= inv; ++jj) {\n\t\t\t\tfor\
    \ (int kk = 0; kk <= inv; ++kk) {\n\t\t\t\t\tdiff[kk - jj] += solve(m, jj) * solve(m,\
    \ kk);\n\t\t\t\t}\n\t\t\t}\n\t\t} else {\n\t\t\tfor (int j = -inv - 1; j <= inv;\
    \ ++j) {\n\t\t\t\tp1[j] = p2[j] = 0;\n\t\t\t}\n\t\t\tfor (int ii = -inv; ii <=\
    \ inv; ++ii) {\n\t\t\t\tp1[ii] = p1[ii - 1] + pdiff[ii];\n\t\t\t\tp2[ii] = p2[ii\
    \ - 1] + ii * pdiff[ii];\t\t\n\t\t\t}\n\t\t\tfor (int ii = -inv; ii <= inv; ++ii)\
    \ {\n\t\t\t\tint st = max(ii - m, -inv);\n\t\t\t\tint coeff = m - (ii - st);\n\
    \t\t\t\tdiff[ii] = p2[ii] - p2[st - 1] + (coeff - st) * (p1[ii] - p1[st - 1]);\n\
    \t\t\t\tint ed = min(ii + m, inv);\n\t\t\t\tcoeff = m - 1;\n\t\t\t\tdiff[ii] +=\
    \ p2[ii] - p2[ed] + (coeff + (ii + 1)) * (p1[ed] - p1[ii]);\n\t\t\t}\n\t\t}\n\t\
    \tfor (int j = -inv; j <= inv; ++j) {\n\t\t\tpdiff[j] = diff[j];\n\t\t}\n\t\t\
    for (int j = 0; j <= inv; ++j) {\n\t\t\tuse[j] = diff[j];\n\t\t}\n\t\tfor (int\
    \ j = max(inv, i); j >= 1; --j) {\n\t\t\tuse[j - 1] += use[j];\n\t\t}\n\t\tfor\
    \ (int j = 1; j <= i; ++j) {\n\t\t\tfor (int k = j + 1; k <= i; ++k) {\n\t\t\t\
    \tmi ways = C[n][n - i] * fact[n - i];\n\t\t\t\tmi res = ways * use[k - j + 1];\n\
    \t\t\t\tans += res;\n\t\t\t}\n\t\t}\n\t}\n\tcout << ans << '\\n';\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1542/problem/E2\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/misc/range-vector.hpp\"\
    \n\nstruct FastMod {\n\tunsigned long long b, m;\n\tFastMod(unsigned long long\
    \ b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}\n\tunsigned\
    \ long long reduce(unsigned long long a) {\n\t\tunsigned long long q = (unsigned\
    \ long long)((__uint128_t(m) * a) >> 64);\n\t\tunsigned long long r = a - q *\
    \ b; // can be proven that 0 <= r < 2*b\n\t\treturn r >= b ? r - b : r;\n\t}\n\
    };\n\nFastMod F(2);\n\nint MOD = 2;\n\ntypedef decay<decltype(MOD)>::type mod_t;\n\
    \nstruct mi {\n\tmod_t val;\n\texplicit operator mod_t() const { return val; }\n\
    \tmi() { val = 0; }\n\tmi(const long long& v) {\n\t\tval = (-MOD <= v && v < MOD)\
    \ ? v : v % MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend istream& operator>>(istream&\
    \ in, mi& a) { \n\t\tlong long x; cin >> x; a = mi(x); return in; }\n\tfriend\
    \ ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }\n\tfriend\
    \ bool operator==(const mi& a, const mi& b) { return a.val == b.val; }\n\tfriend\
    \ bool operator!=(const mi& a, const mi& b) { return !(a == b); }    \n\tfriend\
    \ bool operator<(const mi& a, const mi& b) { return a.val < b.val; }\n\tfriend\
    \ bool operator>(const mi& a, const mi& b) { return a.val > b.val; }\n\tfriend\
    \ bool operator<=(const mi& a, const mi& b) { return a.val <= b.val; }\n\tfriend\
    \ bool operator>=(const mi& a, const mi& b) { return a.val >= b.val; }\n\tmi operator-()\
    \ const { return mi(-val); }\n\tmi& operator+=(const mi& m) {\n\t\tif ((val +=\
    \ m.val) >= MOD) val -= MOD;\n\t\treturn *this; }\n\tmi& operator-=(const mi&\
    \ m) {\n\t\tif ((val -= m.val) < 0) val += MOD;\n\t\treturn *this; }\n\tmi& operator*=(const\
    \ mi& m) { \n\t\tval = F.reduce((long long)val * m.val);\n\t\treturn *this; }\n\
    \tfriend mi pow(mi a, long long p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\tfor\
    \ (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans; }\n\tfriend mi inv(const\
    \ mi& a) { assert(a != 0); return pow(a, MOD - 2); }\n\tmi& operator/=(const mi&\
    \ m) { return (*this) *= inv(m); }\n\tfriend mi operator+(mi a, const mi& b) {\
    \ return a += b; }\n\tfriend mi operator-(mi a, const mi& b) { return a -= b;\
    \ }\n\tfriend mi operator*(mi a, const mi& b) { return a *= b; }\n\tfriend mi\
    \ operator/(mi a, const mi& b) { return a /= b; }\n};\n\nconst int N = 505;\n\
    const int I = N * (N - 1) / 2;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n; \n\tcin >> n >> MOD;\n\tF = FastMod(MOD);\n\tint\
    \ c2 = n * (n - 1) / 2;\n\tvector<vector<mi>> C(n + 1, vector<mi>(n + 1));\n\t\
    vector<mi> fact(n + 1);\n\tvector<vector<mi>> dp(n, vector<mi>(c2 + 1));\n\trange_vector<mi>\
    \ diff, pdiff, p1, p2, use;\n\tC[0][0] = 1;\n\tfor (int i = 1; i <= n; ++i) {\n\
    \t\tfor (int j = 0; j <= n; ++j) {\n\t\t\tC[i][j] = C[i - 1][j] + (j ? C[i - 1][j\
    \ - 1] : 0);\n\t\t}\n\t}\n\tmi ans = 0;\n\tfact[0] = 1;\n\tfor (int i = 1; i <=\
    \ n; ++i) {\n\t\tfact[i] = fact[i - 1] * i;\n\t}\n\tp1 = p2 = diff = pdiff = range_vector<mi>(-c2\
    \ - 1, c2 + 1, 0);\n\tuse.resize(c2 + 1);\n\tfor (int i = 4; i <= n; ++i) {\n\t\
    \tint m = i - 1;\n\t\tint inv = m * (m - 1) / 2;\n\t\tif (m == 3) {\n\t\t\tfunction<mi(int,\
    \ int)> solve = [&](int n, int k) {\n\t\t\t\tvector<int> a(n);\n\t\t\t\tiota(a.begin(),\
    \ a.end(), 0);\n\t\t\t\tmi res = 0;\n\t\t\t\tdo {\n\t\t\t\t\tint cnt = 0;\n\t\t\
    \t\t\tfor (int i = 0; i < n; ++i) {\n\t\t\t\t\t\tfor (int j = i + 1; j < n; ++j)\
    \ {\n\t\t\t\t\t\t\tif (a[i] > a[j]) {\n\t\t\t\t\t\t\t\t++cnt;\n\t\t\t\t\t\t\t\
    }\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tif (cnt == k) {\n\t\t\t\t\t\tres += 1;\n\
    \t\t\t\t\t}\n\t\t\t\t} while (next_permutation(a.begin(), a.end()));\n\t\t\t\t\
    return res;\n\t\t\t};\n\t\t\tfor (int jj = 0; jj <= inv; ++jj) {\n\t\t\t\tfor\
    \ (int kk = 0; kk <= inv; ++kk) {\n\t\t\t\t\tdiff[kk - jj] += solve(m, jj) * solve(m,\
    \ kk);\n\t\t\t\t}\n\t\t\t}\n\t\t} else {\n\t\t\tfor (int j = -inv - 1; j <= inv;\
    \ ++j) {\n\t\t\t\tp1[j] = p2[j] = 0;\n\t\t\t}\n\t\t\tfor (int ii = -inv; ii <=\
    \ inv; ++ii) {\n\t\t\t\tp1[ii] = p1[ii - 1] + pdiff[ii];\n\t\t\t\tp2[ii] = p2[ii\
    \ - 1] + ii * pdiff[ii];\t\t\n\t\t\t}\n\t\t\tfor (int ii = -inv; ii <= inv; ++ii)\
    \ {\n\t\t\t\tint st = max(ii - m, -inv);\n\t\t\t\tint coeff = m - (ii - st);\n\
    \t\t\t\tdiff[ii] = p2[ii] - p2[st - 1] + (coeff - st) * (p1[ii] - p1[st - 1]);\n\
    \t\t\t\tint ed = min(ii + m, inv);\n\t\t\t\tcoeff = m - 1;\n\t\t\t\tdiff[ii] +=\
    \ p2[ii] - p2[ed] + (coeff + (ii + 1)) * (p1[ed] - p1[ii]);\n\t\t\t}\n\t\t}\n\t\
    \tfor (int j = -inv; j <= inv; ++j) {\n\t\t\tpdiff[j] = diff[j];\n\t\t}\n\t\t\
    for (int j = 0; j <= inv; ++j) {\n\t\t\tuse[j] = diff[j];\n\t\t}\n\t\tfor (int\
    \ j = max(inv, i); j >= 1; --j) {\n\t\t\tuse[j - 1] += use[j];\n\t\t}\n\t\tfor\
    \ (int j = 1; j <= i; ++j) {\n\t\t\tfor (int k = j + 1; k <= i; ++k) {\n\t\t\t\
    \tmi ways = C[n][n - i] * fact[n - i];\n\t\t\t\tmi res = ways * use[k - j + 1];\n\
    \t\t\t\tans += res;\n\t\t\t}\n\t\t}\n\t}\n\tcout << ans << '\\n';\n\treturn 0;\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/misc/range-vector.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1542E2.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 13:31:52-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1542E2.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1542E2.test.cpp
- /verify/verify/codeforces/codeforces-1542E2.test.cpp.html
title: verify/codeforces/codeforces-1542E2.test.cpp
---
