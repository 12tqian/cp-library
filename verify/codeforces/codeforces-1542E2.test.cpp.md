---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/range-vector.hpp
    title: library/data-structures/range-vector.hpp
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
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> class\
    \ range_vector : public std::vector<T> {\r\npublic:\r\n\tint min_index;\r\n\r\n\
    \trange_vector() : min_index(0) {}\r\n\r\n\trange_vector(int _min_index, int _max_index,\
    \ T&& values = T())\r\n\t\t: std::vector<T>(_max_index - _min_index + 1, values),\
    \ min_index(_min_index) {\r\n\t\tassert(_min_index <= _max_index + 1);\r\n\t}\r\
    \n\t\r\n\trange_vector(int _max_index, T&& values = T())\r\n\t\t: std::vector<T>(_max_index\
    \ + 1, values), min_index(0) {\r\n\t\tassert(0 <= _max_index + 1);\r\n\t}\r\n\t\
    \r\n\tT& operator[](int i) { std::vector<T>& self = *this; return self[i - min_index];\
    \ }\r\n};\r\n\r\nstruct FastMod {\r\n\tunsigned long long b, m;\r\n\tFastMod(unsigned\
    \ long long b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}\r\
    \n\tunsigned long long reduce(unsigned long long a) {\r\n\t\tunsigned long long\
    \ q = (unsigned long long)((__uint128_t(m) * a) >> 64);\r\n\t\tunsigned long long\
    \ r = a - q * b; // can be proven that 0 <= r < 2*b\r\n\t\treturn r >= b ? r -\
    \ b : r;\r\n\t}\r\n};\r\n\r\nFastMod F(2);\r\n\r\nint MOD = 2;\r\n\r\ntypedef\
    \ decay<decltype(MOD)>::type mod_t;\r\n\r\nstruct mi {\r\n\tmod_t val;\r\n\texplicit\
    \ operator mod_t() const { return val; }\r\n\tmi() { val = 0; }\r\n\tmi(const\
    \ long long& v) {\r\n\t\tval = (-MOD <= v && v < MOD) ? v : v % MOD;\r\n\t\tif\
    \ (val < 0) val += MOD; }\r\n\tfriend istream& operator>>(istream& in, mi& a)\
    \ { \r\n\t\tlong long x; cin >> x; a = mi(x); return in; }\r\n\tfriend ostream&\
    \ operator<<(ostream& os, const mi& a) { return os << a.val; }\r\n\tfriend bool\
    \ operator==(const mi& a, const mi& b) { return a.val == b.val; }\r\n\tfriend\
    \ bool operator!=(const mi& a, const mi& b) { return !(a == b); }    \r\n\tfriend\
    \ bool operator<(const mi& a, const mi& b) { return a.val < b.val; }\r\n\tfriend\
    \ bool operator>(const mi& a, const mi& b) { return a.val > b.val; }\r\n\tfriend\
    \ bool operator<=(const mi& a, const mi& b) { return a.val <= b.val; }\r\n\tfriend\
    \ bool operator>=(const mi& a, const mi& b) { return a.val >= b.val; }\r\n\tmi\
    \ operator-() const { return mi(-val); }\r\n\tmi& operator+=(const mi& m) {\r\n\
    \t\tif ((val += m.val) >= MOD) val -= MOD;\r\n\t\treturn *this; }\r\n\tmi& operator-=(const\
    \ mi& m) {\r\n\t\tif ((val -= m.val) < 0) val += MOD;\r\n\t\treturn *this; }\r\
    \n\tmi& operator*=(const mi& m) { \r\n\t\tval = F.reduce((long long)val * m.val);\r\
    \n\t\treturn *this; }\r\n\tfriend mi pow(mi a, long long p) {\r\n\t\tmi ans =\
    \ 1; assert(p >= 0);\r\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n\
    \t\treturn ans; }\r\n\tfriend mi inv(const mi& a) { assert(a != 0); return pow(a,\
    \ MOD - 2); }\r\n\tmi& operator/=(const mi& m) { return (*this) *= inv(m); }\r\
    \n\tfriend mi operator+(mi a, const mi& b) { return a += b; }\r\n\tfriend mi operator-(mi\
    \ a, const mi& b) { return a -= b; }\r\n\tfriend mi operator*(mi a, const mi&\
    \ b) { return a *= b; }\r\n\tfriend mi operator/(mi a, const mi& b) { return a\
    \ /= b; }\r\n};\r\n\r\nconst int N = 505;\r\nconst int I = N * (N - 1) / 2;\r\n\
    \r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\t\
    int n; \r\n\tcin >> n >> MOD;\r\n\tF = FastMod(MOD);\r\n\tint c2 = n * (n - 1)\
    \ / 2;\r\n\tvector<vector<mi>> C(n + 1, vector<mi>(n + 1));\r\n\tvector<mi> fact(n\
    \ + 1);\r\n\tvector<vector<mi>> dp(n, vector<mi>(c2 + 1));\r\n\trange_vector<mi>\
    \ diff, pdiff, p1, p2, use;\r\n\tC[0][0] = 1;\r\n\tfor (int i = 1; i <= n; ++i)\
    \ {\r\n\t\tfor (int j = 0; j <= n; ++j) {\r\n\t\t\tC[i][j] = C[i - 1][j] + (j\
    \ ? C[i - 1][j - 1] : 0);\r\n\t\t}\r\n\t}\r\n\tmi ans = 0;\r\n\tfact[0] = 1;\r\
    \n\tfor (int i = 1; i <= n; ++i) {\r\n\t\tfact[i] = fact[i - 1] * i;\r\n\t}\r\n\
    \tp1 = p2 = diff = pdiff = range_vector<mi>(-c2 - 1, c2 + 1, 0);\r\n\tuse.resize(c2\
    \ + 1);\r\n\tfor (int i = 4; i <= n; ++i) {\r\n\t\tint m = i - 1;\r\n\t\tint inv\
    \ = m * (m - 1) / 2;\r\n\t\tif (m == 3) {\r\n\t\t\tfunction<mi(int, int)> solve\
    \ = [&](int n, int k) {\r\n\t\t\t\tvector<int> a(n);\r\n\t\t\t\tiota(a.begin(),\
    \ a.end(), 0);\r\n\t\t\t\tmi res = 0;\r\n\t\t\t\tdo {\r\n\t\t\t\t\tint cnt = 0;\r\
    \n\t\t\t\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\t\t\t\tfor (int j = i + 1; j\
    \ < n; ++j) {\r\n\t\t\t\t\t\t\tif (a[i] > a[j]) {\r\n\t\t\t\t\t\t\t\t++cnt;\r\n\
    \t\t\t\t\t\t\t}\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\tif (cnt == k) {\r\
    \n\t\t\t\t\t\tres += 1;\r\n\t\t\t\t\t}\r\n\t\t\t\t} while (next_permutation(a.begin(),\
    \ a.end()));\r\n\t\t\t\treturn res;\r\n\t\t\t};\r\n\t\t\tfor (int jj = 0; jj <=\
    \ inv; ++jj) {\r\n\t\t\t\tfor (int kk = 0; kk <= inv; ++kk) {\r\n\t\t\t\t\tdiff[kk\
    \ - jj] += solve(m, jj) * solve(m, kk);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t} else\
    \ {\r\n\t\t\tfor (int j = -inv - 1; j <= inv; ++j) {\r\n\t\t\t\tp1[j] = p2[j]\
    \ = 0;\r\n\t\t\t}\r\n\t\t\tfor (int ii = -inv; ii <= inv; ++ii) {\r\n\t\t\t\t\
    p1[ii] = p1[ii - 1] + pdiff[ii];\r\n\t\t\t\tp2[ii] = p2[ii - 1] + ii * pdiff[ii];\t\
    \t\r\n\t\t\t}\r\n\t\t\tfor (int ii = -inv; ii <= inv; ++ii) {\r\n\t\t\t\tint st\
    \ = max(ii - m, -inv);\r\n\t\t\t\tint coeff = m - (ii - st);\r\n\t\t\t\tdiff[ii]\
    \ = p2[ii] - p2[st - 1] + (coeff - st) * (p1[ii] - p1[st - 1]);\r\n\t\t\t\tint\
    \ ed = min(ii + m, inv);\r\n\t\t\t\tcoeff = m - 1;\r\n\t\t\t\tdiff[ii] += p2[ii]\
    \ - p2[ed] + (coeff + (ii + 1)) * (p1[ed] - p1[ii]);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tfor (int j = -inv; j <= inv; ++j) {\r\n\t\t\tpdiff[j] = diff[j];\r\n\t\t}\r\n\
    \t\tfor (int j = 0; j <= inv; ++j) {\r\n\t\t\tuse[j] = diff[j];\r\n\t\t}\r\n\t\
    \tfor (int j = max(inv, i); j >= 1; --j) {\r\n\t\t\tuse[j - 1] += use[j];\r\n\t\
    \t}\r\n\t\tfor (int j = 1; j <= i; ++j) {\r\n\t\t\tfor (int k = j + 1; k <= i;\
    \ ++k) {\r\n\t\t\t\tmi ways = C[n][n - i] * fact[n - i];\r\n\t\t\t\tmi res = ways\
    \ * use[k - j + 1];\r\n\t\t\t\tans += res;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tcout\
    \ << ans << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1542/problem/E2\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/range-vector.hpp\"\
    \r\n\r\nstruct FastMod {\r\n\tunsigned long long b, m;\r\n\tFastMod(unsigned long\
    \ long b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}\r\n\t\
    unsigned long long reduce(unsigned long long a) {\r\n\t\tunsigned long long q\
    \ = (unsigned long long)((__uint128_t(m) * a) >> 64);\r\n\t\tunsigned long long\
    \ r = a - q * b; // can be proven that 0 <= r < 2*b\r\n\t\treturn r >= b ? r -\
    \ b : r;\r\n\t}\r\n};\r\n\r\nFastMod F(2);\r\n\r\nint MOD = 2;\r\n\r\ntypedef\
    \ decay<decltype(MOD)>::type mod_t;\r\n\r\nstruct mi {\r\n\tmod_t val;\r\n\texplicit\
    \ operator mod_t() const { return val; }\r\n\tmi() { val = 0; }\r\n\tmi(const\
    \ long long& v) {\r\n\t\tval = (-MOD <= v && v < MOD) ? v : v % MOD;\r\n\t\tif\
    \ (val < 0) val += MOD; }\r\n\tfriend istream& operator>>(istream& in, mi& a)\
    \ { \r\n\t\tlong long x; cin >> x; a = mi(x); return in; }\r\n\tfriend ostream&\
    \ operator<<(ostream& os, const mi& a) { return os << a.val; }\r\n\tfriend bool\
    \ operator==(const mi& a, const mi& b) { return a.val == b.val; }\r\n\tfriend\
    \ bool operator!=(const mi& a, const mi& b) { return !(a == b); }    \r\n\tfriend\
    \ bool operator<(const mi& a, const mi& b) { return a.val < b.val; }\r\n\tfriend\
    \ bool operator>(const mi& a, const mi& b) { return a.val > b.val; }\r\n\tfriend\
    \ bool operator<=(const mi& a, const mi& b) { return a.val <= b.val; }\r\n\tfriend\
    \ bool operator>=(const mi& a, const mi& b) { return a.val >= b.val; }\r\n\tmi\
    \ operator-() const { return mi(-val); }\r\n\tmi& operator+=(const mi& m) {\r\n\
    \t\tif ((val += m.val) >= MOD) val -= MOD;\r\n\t\treturn *this; }\r\n\tmi& operator-=(const\
    \ mi& m) {\r\n\t\tif ((val -= m.val) < 0) val += MOD;\r\n\t\treturn *this; }\r\
    \n\tmi& operator*=(const mi& m) { \r\n\t\tval = F.reduce((long long)val * m.val);\r\
    \n\t\treturn *this; }\r\n\tfriend mi pow(mi a, long long p) {\r\n\t\tmi ans =\
    \ 1; assert(p >= 0);\r\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n\
    \t\treturn ans; }\r\n\tfriend mi inv(const mi& a) { assert(a != 0); return pow(a,\
    \ MOD - 2); }\r\n\tmi& operator/=(const mi& m) { return (*this) *= inv(m); }\r\
    \n\tfriend mi operator+(mi a, const mi& b) { return a += b; }\r\n\tfriend mi operator-(mi\
    \ a, const mi& b) { return a -= b; }\r\n\tfriend mi operator*(mi a, const mi&\
    \ b) { return a *= b; }\r\n\tfriend mi operator/(mi a, const mi& b) { return a\
    \ /= b; }\r\n};\r\n\r\nconst int N = 505;\r\nconst int I = N * (N - 1) / 2;\r\n\
    \r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\t\
    int n; \r\n\tcin >> n >> MOD;\r\n\tF = FastMod(MOD);\r\n\tint c2 = n * (n - 1)\
    \ / 2;\r\n\tvector<vector<mi>> C(n + 1, vector<mi>(n + 1));\r\n\tvector<mi> fact(n\
    \ + 1);\r\n\tvector<vector<mi>> dp(n, vector<mi>(c2 + 1));\r\n\trange_vector<mi>\
    \ diff, pdiff, p1, p2, use;\r\n\tC[0][0] = 1;\r\n\tfor (int i = 1; i <= n; ++i)\
    \ {\r\n\t\tfor (int j = 0; j <= n; ++j) {\r\n\t\t\tC[i][j] = C[i - 1][j] + (j\
    \ ? C[i - 1][j - 1] : 0);\r\n\t\t}\r\n\t}\r\n\tmi ans = 0;\r\n\tfact[0] = 1;\r\
    \n\tfor (int i = 1; i <= n; ++i) {\r\n\t\tfact[i] = fact[i - 1] * i;\r\n\t}\r\n\
    \tp1 = p2 = diff = pdiff = range_vector<mi>(-c2 - 1, c2 + 1, 0);\r\n\tuse.resize(c2\
    \ + 1);\r\n\tfor (int i = 4; i <= n; ++i) {\r\n\t\tint m = i - 1;\r\n\t\tint inv\
    \ = m * (m - 1) / 2;\r\n\t\tif (m == 3) {\r\n\t\t\tfunction<mi(int, int)> solve\
    \ = [&](int n, int k) {\r\n\t\t\t\tvector<int> a(n);\r\n\t\t\t\tiota(a.begin(),\
    \ a.end(), 0);\r\n\t\t\t\tmi res = 0;\r\n\t\t\t\tdo {\r\n\t\t\t\t\tint cnt = 0;\r\
    \n\t\t\t\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\t\t\t\tfor (int j = i + 1; j\
    \ < n; ++j) {\r\n\t\t\t\t\t\t\tif (a[i] > a[j]) {\r\n\t\t\t\t\t\t\t\t++cnt;\r\n\
    \t\t\t\t\t\t\t}\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\tif (cnt == k) {\r\
    \n\t\t\t\t\t\tres += 1;\r\n\t\t\t\t\t}\r\n\t\t\t\t} while (next_permutation(a.begin(),\
    \ a.end()));\r\n\t\t\t\treturn res;\r\n\t\t\t};\r\n\t\t\tfor (int jj = 0; jj <=\
    \ inv; ++jj) {\r\n\t\t\t\tfor (int kk = 0; kk <= inv; ++kk) {\r\n\t\t\t\t\tdiff[kk\
    \ - jj] += solve(m, jj) * solve(m, kk);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t} else\
    \ {\r\n\t\t\tfor (int j = -inv - 1; j <= inv; ++j) {\r\n\t\t\t\tp1[j] = p2[j]\
    \ = 0;\r\n\t\t\t}\r\n\t\t\tfor (int ii = -inv; ii <= inv; ++ii) {\r\n\t\t\t\t\
    p1[ii] = p1[ii - 1] + pdiff[ii];\r\n\t\t\t\tp2[ii] = p2[ii - 1] + ii * pdiff[ii];\t\
    \t\r\n\t\t\t}\r\n\t\t\tfor (int ii = -inv; ii <= inv; ++ii) {\r\n\t\t\t\tint st\
    \ = max(ii - m, -inv);\r\n\t\t\t\tint coeff = m - (ii - st);\r\n\t\t\t\tdiff[ii]\
    \ = p2[ii] - p2[st - 1] + (coeff - st) * (p1[ii] - p1[st - 1]);\r\n\t\t\t\tint\
    \ ed = min(ii + m, inv);\r\n\t\t\t\tcoeff = m - 1;\r\n\t\t\t\tdiff[ii] += p2[ii]\
    \ - p2[ed] + (coeff + (ii + 1)) * (p1[ed] - p1[ii]);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tfor (int j = -inv; j <= inv; ++j) {\r\n\t\t\tpdiff[j] = diff[j];\r\n\t\t}\r\n\
    \t\tfor (int j = 0; j <= inv; ++j) {\r\n\t\t\tuse[j] = diff[j];\r\n\t\t}\r\n\t\
    \tfor (int j = max(inv, i); j >= 1; --j) {\r\n\t\t\tuse[j - 1] += use[j];\r\n\t\
    \t}\r\n\t\tfor (int j = 1; j <= i; ++j) {\r\n\t\t\tfor (int k = j + 1; k <= i;\
    \ ++k) {\r\n\t\t\t\tmi ways = C[n][n - i] * fact[n - i];\r\n\t\t\t\tmi res = ways\
    \ * use[k - j + 1];\r\n\t\t\t\tans += res;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tcout\
    \ << ans << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/range-vector.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1542E2.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1542E2.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1542E2.test.cpp
- /verify/verify/codeforces/codeforces-1542E2.test.cpp.html
title: verify/codeforces/codeforces-1542E2.test.cpp
---
