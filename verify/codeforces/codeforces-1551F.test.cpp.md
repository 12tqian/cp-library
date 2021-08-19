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
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1551/problem/F\"\n\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nconst int MOD = 1e9 + 7; // 998244353\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n\tmod_t v;\n\texplicit operator mod_t() const { return\
    \ v; }\n\texplicit operator bool() const { return v != 0; }\n\tmi() { v = 0; }\n\
    \tmi(const long long& _v) {\n\t\tv = (-MOD <= _v && _v < MOD) ? _v : _v % MOD;\n\
    \t\tif (v < 0) v += MOD; }\n\tfriend std::istream& operator>>(std::istream& in,\
    \ mi& a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\tfriend\
    \ std::ostream& operator<<(std::ostream& os, const mi& a) { return os << a.v;\
    \ }\n\tfriend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }\n\
    \tfriend bool operator!=(const mi& a, const mi& b) { return !(a == b); }    \n\
    \tfriend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }\n\tfriend\
    \ bool operator>(const mi& a, const mi& b) { return a.v > b.v; }\n\tfriend bool\
    \ operator<=(const mi& a, const mi& b) { return a.v <= b.v; }\n\tfriend bool operator>=(const\
    \ mi& a, const mi& b) { return a.v >= b.v; }\n\tmi operator-() const { return\
    \ mi(-v); }\n\tmi& operator+=(const mi& m) {\n\t\tif ((v += m.v) >= MOD) v -=\
    \ MOD;\n\t\treturn *this; }\n\tmi& operator-=(const mi& m) {\n\t\tif ((v -= m.v)\
    \ < 0) v += MOD;\n\t\treturn *this; }\n\tmi& operator*=(const mi& m) { v = (long\
    \ long)v * m.v % MOD;\n\t\treturn *this; }\n\tfriend mi pow(mi a, long long p)\
    \ {\n\t\tmi ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1)\
    \ ans *= a;\n\t\treturn ans; }\n\tfriend mi inv(const mi& a) { assert(a != 0);\
    \ return pow(a, MOD - 2); }\n\tmi& operator/=(const mi& m) { return (*this) *=\
    \ inv(m); }\n\tfriend mi operator+(mi a, const mi& b) { return a += b; }\n\tfriend\
    \ mi operator-(mi a, const mi& b) { return a -= b; }\n\tfriend mi operator*(mi\
    \ a, const mi& b) { return a *= b; }\n\tfriend mi operator/(mi a, const mi& b)\
    \ { return a /= b; }\n};\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint tt;\n\tcin >> tt;\n\tfor (int tc = 1; tc <= tt; ++tc) {\n\t\tint n, k;\n\
    \t\tcin >> n >> k;\n\t\tvector<mi> fact(n + 1);\n\t\tvector<mi> ifact(n + 1);\n\
    \t\tfact[0] = 1;\n\t\tfor (int i = 1; i <= n; ++i) {\n\t\t\tfact[i] = fact[i -\
    \ 1] * i;\n\t\t}\n\t\tifact[n] = 1 / fact[n];\n\t\tfor (int i = n - 1; i >= 0;\
    \ --i) {\n\t\t\tifact[i] = ifact[i + 1] * (i + 1);\n\t\t}\n\t\tauto C = [&](int\
    \ x, int y) {\n\t\t};\n\t\tvector<vector<int>> g(n);\n\t\tfor (int i = 0; i <\
    \ n - 1; ++i) {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\t--u, --v;\n\t\t\t\
    g[u].push_back(v);\n\t\t\tg[v].push_back(u);\n\t\t}\n\t\tif (k == 2) {\n\t\t\t\
    cout << n * (n - 1) / 2 << '\\n';\n\t\t\tcontinue;\n\t\t}\n\t\tmi ans = 0;\n\t\
    \tfor (int r = 0; r < n; ++r) {\n\t\t\tvector<vector<int>> store(n);\n\t\t\tvector<int>\
    \ dep(n);\n\t\t\tfunction<void(int, int, int)> dfs = [&](int u, int p, int s)\
    \ {\n\t\t\t\t++store[dep[u]].back();\n\t\t\t\tfor (int v : g[u]) {\n\t\t\t\t\t\
    if (v != p) {\n\t\t\t\t\t\tdep[v] = dep[u] + 1;\n\t\t\t\t\t\tdfs(v, u, s);\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t};\n\t\t\tfor (int u : g[r]) {\n\t\t\t\tfor (int i\
    \ = 0; i < n; ++i) {\n\t\t\t\t\tstore[i].push_back(0);\n\t\t\t\t}\n\t\t\t\tdep[u]\
    \ = 1;\n\t\t\t\tdfs(u, r, u);\n\t\t\t}\n\t\t\tauto comb = [&](vector<mi> a, vector<mi>\
    \ b) {\n\t\t\t\tvector<mi> res(a.size() + b.size() - 1);\n\t\t\t\tfor (int i =\
    \ 0; i < a.size(); ++i) {\n\t\t\t\t\tfor (int j = 0; j < b.size(); ++j) {\n\t\t\
    \t\t\t\tres[i + j] += a[i] * b[j];\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn res;\n\
    \t\t\t};\n\t\t\tfor (int d = 0; d < n; ++d) {\n\t\t\t\tvector<mi> res = {1};\n\
    \t\t\t\tfor (int x : store[d]) {\n\t\t\t\t\tres = comb(res, vector<mi>{1, x});\n\
    \t\t\t\t}\n\t\t\t\tif (res.size() > k) {\n\t\t\t\t\tans += res[k];\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\tcout << ans << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1551/problem/F\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/modular-arithmetic/mod-int.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint tt;\n\
    \tcin >> tt;\n\tfor (int tc = 1; tc <= tt; ++tc) {\n\t\tint n, k;\n\t\tcin >>\
    \ n >> k;\n\t\tvector<mi> fact(n + 1);\n\t\tvector<mi> ifact(n + 1);\n\t\tfact[0]\
    \ = 1;\n\t\tfor (int i = 1; i <= n; ++i) {\n\t\t\tfact[i] = fact[i - 1] * i;\n\
    \t\t}\n\t\tifact[n] = 1 / fact[n];\n\t\tfor (int i = n - 1; i >= 0; --i) {\n\t\
    \t\tifact[i] = ifact[i + 1] * (i + 1);\n\t\t}\n\t\tauto C = [&](int x, int y)\
    \ {\n\t\t};\n\t\tvector<vector<int>> g(n);\n\t\tfor (int i = 0; i < n - 1; ++i)\
    \ {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\t--u, --v;\n\t\t\tg[u].push_back(v);\n\
    \t\t\tg[v].push_back(u);\n\t\t}\n\t\tif (k == 2) {\n\t\t\tcout << n * (n - 1)\
    \ / 2 << '\\n';\n\t\t\tcontinue;\n\t\t}\n\t\tmi ans = 0;\n\t\tfor (int r = 0;\
    \ r < n; ++r) {\n\t\t\tvector<vector<int>> store(n);\n\t\t\tvector<int> dep(n);\n\
    \t\t\tfunction<void(int, int, int)> dfs = [&](int u, int p, int s) {\n\t\t\t\t\
    ++store[dep[u]].back();\n\t\t\t\tfor (int v : g[u]) {\n\t\t\t\t\tif (v != p) {\n\
    \t\t\t\t\t\tdep[v] = dep[u] + 1;\n\t\t\t\t\t\tdfs(v, u, s);\n\t\t\t\t\t}\n\t\t\
    \t\t}\n\t\t\t};\n\t\t\tfor (int u : g[r]) {\n\t\t\t\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\t\t\t\tstore[i].push_back(0);\n\t\t\t\t}\n\t\t\t\tdep[u] = 1;\n\t\t\t\t\
    dfs(u, r, u);\n\t\t\t}\n\t\t\tauto comb = [&](vector<mi> a, vector<mi> b) {\n\t\
    \t\t\tvector<mi> res(a.size() + b.size() - 1);\n\t\t\t\tfor (int i = 0; i < a.size();\
    \ ++i) {\n\t\t\t\t\tfor (int j = 0; j < b.size(); ++j) {\n\t\t\t\t\t\tres[i +\
    \ j] += a[i] * b[j];\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn res;\n\t\t\t};\n\t\
    \t\tfor (int d = 0; d < n; ++d) {\n\t\t\t\tvector<mi> res = {1};\n\t\t\t\tfor\
    \ (int x : store[d]) {\n\t\t\t\t\tres = comb(res, vector<mi>{1, x});\n\t\t\t\t\
    }\n\t\t\t\tif (res.size() > k) {\n\t\t\t\t\tans += res[k];\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\tcout << ans << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/modular-arithmetic/mod-int.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1551F.test.cpp
  requiredBy: []
  timestamp: '2021-08-18 20:05:50-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1551F.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1551F.test.cpp
- /verify/verify/codeforces/codeforces-1551F.test.cpp.html
title: verify/codeforces/codeforces-1551F.test.cpp
---
