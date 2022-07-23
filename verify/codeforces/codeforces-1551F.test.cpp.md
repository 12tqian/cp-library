---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/modular-arithmetic/mod-int.hpp
    title: library/modular-arithmetic/mod-int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/1551/problem/F
    links:
    - https://codeforces.com/contest/1551/problem/F
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1551/problem/F\"\r\
    \n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nconst int MOD = 1e9 + 7;\
    \ // 998244353\r\n\r\ntypedef std::decay<decltype(MOD)>::type mod_t; \r\nstruct\
    \ mi {\r\n\tmod_t v;\r\n\texplicit operator mod_t() const { return v; }\r\n\t\
    explicit operator bool() const { return v != 0; }\r\n\tmi() { v = 0; }\r\n\tmi(const\
    \ long long& _v) {\r\n\t\tv = (-MOD <= _v && _v < MOD) ? _v : _v % MOD;\r\n\t\t\
    if (v < 0) v += MOD; }\r\n\tfriend std::istream& operator>>(std::istream& in,\
    \ mi& a) { \r\n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\r\n\tfriend\
    \ std::ostream& operator<<(std::ostream& os, const mi& a) { return os << a.v;\
    \ }\r\n\tfriend bool operator==(const mi& a, const mi& b) { return a.v == b.v;\
    \ }\r\n\tfriend bool operator!=(const mi& a, const mi& b) { return !(a == b);\
    \ }    \r\n\tfriend bool operator<(const mi& a, const mi& b) { return a.v < b.v;\
    \ }\r\n\tfriend bool operator>(const mi& a, const mi& b) { return a.v > b.v; }\r\
    \n\tfriend bool operator<=(const mi& a, const mi& b) { return a.v <= b.v; }\r\n\
    \tfriend bool operator>=(const mi& a, const mi& b) { return a.v >= b.v; }\r\n\t\
    mi operator-() const { return mi(-v); }\r\n\tmi& operator+=(const mi& m) {\r\n\
    \t\tif ((v += m.v) >= MOD) v -= MOD;\r\n\t\treturn *this; }\r\n\tmi& operator-=(const\
    \ mi& m) {\r\n\t\tif ((v -= m.v) < 0) v += MOD;\r\n\t\treturn *this; }\r\n\tmi&\
    \ operator*=(const mi& m) { v = (long long)v * m.v % MOD;\r\n\t\treturn *this;\
    \ }\r\n\tfriend mi pow(mi a, long long p) {\r\n\t\tmi ans = 1; assert(p >= 0);\r\
    \n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n\t\treturn ans; }\r\n\t\
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }\r\n\tmi&\
    \ operator/=(const mi& m) { return (*this) *= inv(m); }\r\n\tfriend mi operator+(mi\
    \ a, const mi& b) { return a += b; }\r\n\tfriend mi operator-(mi a, const mi&\
    \ b) { return a -= b; }\r\n\tfriend mi operator*(mi a, const mi& b) { return a\
    \ *= b; }\r\n\tfriend mi operator/(mi a, const mi& b) { return a /= b; }\r\n};\n\
    \r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\t\
    int tt;\r\n\tcin >> tt;\r\n\tfor (int tc = 1; tc <= tt; ++tc) {\r\n\t\tint n,\
    \ k;\r\n\t\tcin >> n >> k;\r\n\t\tvector<mi> fact(n + 1);\r\n\t\tvector<mi> ifact(n\
    \ + 1);\r\n\t\tfact[0] = 1;\r\n\t\tfor (int i = 1; i <= n; ++i) {\r\n\t\t\tfact[i]\
    \ = fact[i - 1] * i;\r\n\t\t}\r\n\t\tifact[n] = 1 / fact[n];\r\n\t\tfor (int i\
    \ = n - 1; i >= 0; --i) {\r\n\t\t\tifact[i] = ifact[i + 1] * (i + 1);\r\n\t\t\
    }\r\n\t\tauto C = [&](int x, int y) {\r\n\t\t};\r\n\t\tvector<vector<int>> g(n);\r\
    \n\t\tfor (int i = 0; i < n - 1; ++i) {\r\n\t\t\tint u, v;\r\n\t\t\tcin >> u >>\
    \ v;\r\n\t\t\t--u, --v;\r\n\t\t\tg[u].push_back(v);\r\n\t\t\tg[v].push_back(u);\r\
    \n\t\t}\r\n\t\tif (k == 2) {\r\n\t\t\tcout << n * (n - 1) / 2 << '\\n';\r\n\t\t\
    \tcontinue;\r\n\t\t}\r\n\t\tmi ans = 0;\r\n\t\tfor (int r = 0; r < n; ++r) {\r\
    \n\t\t\tvector<vector<int>> store(n);\r\n\t\t\tvector<int> dep(n);\r\n\t\t\tfunction<void(int,\
    \ int, int)> dfs = [&](int u, int p, int s) {\r\n\t\t\t\t++store[dep[u]].back();\r\
    \n\t\t\t\tfor (int v : g[u]) {\r\n\t\t\t\t\tif (v != p) {\r\n\t\t\t\t\t\tdep[v]\
    \ = dep[u] + 1;\r\n\t\t\t\t\t\tdfs(v, u, s);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\
    \t\t};\r\n\t\t\tfor (int u : g[r]) {\r\n\t\t\t\tfor (int i = 0; i < n; ++i) {\r\
    \n\t\t\t\t\tstore[i].push_back(0);\r\n\t\t\t\t}\r\n\t\t\t\tdep[u] = 1;\r\n\t\t\
    \t\tdfs(u, r, u);\r\n\t\t\t}\r\n\t\t\tauto comb = [&](vector<mi> a, vector<mi>\
    \ b) {\r\n\t\t\t\tvector<mi> res(a.size() + b.size() - 1);\r\n\t\t\t\tfor (int\
    \ i = 0; i < a.size(); ++i) {\r\n\t\t\t\t\tfor (int j = 0; j < b.size(); ++j)\
    \ {\r\n\t\t\t\t\t\tres[i + j] += a[i] * b[j];\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\
    \t\t\treturn res;\r\n\t\t\t};\r\n\t\t\tfor (int d = 0; d < n; ++d) {\r\n\t\t\t\
    \tvector<mi> res = {1};\r\n\t\t\t\tfor (int x : store[d]) {\r\n\t\t\t\t\tres =\
    \ comb(res, vector<mi>{1, x});\r\n\t\t\t\t}\r\n\t\t\t\tif (res.size() > k) {\r\
    \n\t\t\t\t\tans += res[k];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tcout << ans\
    \ << '\\n';\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1551/problem/F\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/modular-arithmetic/mod-int.hpp\"\
    \r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint tt;\r\n\tcin >> tt;\r\n\tfor (int tc = 1; tc <= tt; ++tc) {\r\n\t\tint\
    \ n, k;\r\n\t\tcin >> n >> k;\r\n\t\tvector<mi> fact(n + 1);\r\n\t\tvector<mi>\
    \ ifact(n + 1);\r\n\t\tfact[0] = 1;\r\n\t\tfor (int i = 1; i <= n; ++i) {\r\n\t\
    \t\tfact[i] = fact[i - 1] * i;\r\n\t\t}\r\n\t\tifact[n] = 1 / fact[n];\r\n\t\t\
    for (int i = n - 1; i >= 0; --i) {\r\n\t\t\tifact[i] = ifact[i + 1] * (i + 1);\r\
    \n\t\t}\r\n\t\tauto C = [&](int x, int y) {\r\n\t\t};\r\n\t\tvector<vector<int>>\
    \ g(n);\r\n\t\tfor (int i = 0; i < n - 1; ++i) {\r\n\t\t\tint u, v;\r\n\t\t\t\
    cin >> u >> v;\r\n\t\t\t--u, --v;\r\n\t\t\tg[u].push_back(v);\r\n\t\t\tg[v].push_back(u);\r\
    \n\t\t}\r\n\t\tif (k == 2) {\r\n\t\t\tcout << n * (n - 1) / 2 << '\\n';\r\n\t\t\
    \tcontinue;\r\n\t\t}\r\n\t\tmi ans = 0;\r\n\t\tfor (int r = 0; r < n; ++r) {\r\
    \n\t\t\tvector<vector<int>> store(n);\r\n\t\t\tvector<int> dep(n);\r\n\t\t\tfunction<void(int,\
    \ int, int)> dfs = [&](int u, int p, int s) {\r\n\t\t\t\t++store[dep[u]].back();\r\
    \n\t\t\t\tfor (int v : g[u]) {\r\n\t\t\t\t\tif (v != p) {\r\n\t\t\t\t\t\tdep[v]\
    \ = dep[u] + 1;\r\n\t\t\t\t\t\tdfs(v, u, s);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\
    \t\t};\r\n\t\t\tfor (int u : g[r]) {\r\n\t\t\t\tfor (int i = 0; i < n; ++i) {\r\
    \n\t\t\t\t\tstore[i].push_back(0);\r\n\t\t\t\t}\r\n\t\t\t\tdep[u] = 1;\r\n\t\t\
    \t\tdfs(u, r, u);\r\n\t\t\t}\r\n\t\t\tauto comb = [&](vector<mi> a, vector<mi>\
    \ b) {\r\n\t\t\t\tvector<mi> res(a.size() + b.size() - 1);\r\n\t\t\t\tfor (int\
    \ i = 0; i < a.size(); ++i) {\r\n\t\t\t\t\tfor (int j = 0; j < b.size(); ++j)\
    \ {\r\n\t\t\t\t\t\tres[i + j] += a[i] * b[j];\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\
    \t\t\treturn res;\r\n\t\t\t};\r\n\t\t\tfor (int d = 0; d < n; ++d) {\r\n\t\t\t\
    \tvector<mi> res = {1};\r\n\t\t\t\tfor (int x : store[d]) {\r\n\t\t\t\t\tres =\
    \ comb(res, vector<mi>{1, x});\r\n\t\t\t\t}\r\n\t\t\t\tif (res.size() > k) {\r\
    \n\t\t\t\t\tans += res[k];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tcout << ans\
    \ << '\\n';\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/modular-arithmetic/mod-int.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1551F.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1551F.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1551F.test.cpp
- /verify/verify/codeforces/codeforces-1551F.test.cpp.html
title: verify/codeforces/codeforces-1551F.test.cpp
---
