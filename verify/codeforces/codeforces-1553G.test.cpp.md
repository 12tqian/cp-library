---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/dsu.hpp
    title: library/graphs/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/fast-hash-map.hpp
    title: library/misc/fast-hash-map.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/fast-input.hpp
    title: library/misc/fast-input.hpp
  - icon: ':heavy_check_mark:'
    path: library/number-theory/fast-factor-sieve.hpp
    title: library/number-theory/fast-factor-sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/1553/problem/G
    links:
    - https://codeforces.com/contest/1553/problem/G
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1553/problem/G\"\r\
    \n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <int SZ> struct\
    \ Sieve {\r\n\tint spf[SZ];\r\n\t\r\n\tSieve() {\r\n\t\tspf[1] = 1;\r\n\t\tfor\
    \ (int i = 2; i < SZ; i++) \r\n\t\t\tspf[i] = i;\r\n\t\tfor (int i = 4; i < SZ;\
    \ i += 2) \r\n\t\t\tspf[i] = 2;\r\n\t\tfor (int i = 3; i * i < SZ; i++) \r\n\t\
    \t\tif (spf[i] == i) \r\n\t\t\t\tfor (int j = i * i; j < SZ; j += i) \r\n\t\t\t\
    \t\tif (spf[j] == j) \r\n\t\t\t\t\t\tspf[j] = i;\r\n\t}\r\n\r\n\tstd::vector<std::pair<int,\
    \ int>> factor(int x) {\r\n\t\tstd::vector<std::pair<int, int>> ret;\r\n\t\twhile\
    \ (x != 1) {\r\n\t\t\tif ((int)ret.size() == 0) \r\n\t\t\t\tret.emplace_back(spf[x],\
    \ 1);\r\n\t\t\telse {\r\n\t\t\t\tif (ret.back().first == spf[x]) \r\n\t\t\t\t\t\
    ret.back().second++;\r\n\t\t\t\telse \r\n\t\t\t\t\tret.emplace_back(spf[x], 1);\r\
    \n\t\t\t}\r\n\t\t\tx /= spf[x];\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\r\n\r\
    \nstruct DSU {\r\n\tstd::vector<int> e;\r\n\r\n\tvoid init(int n) {\r\n\t\te =\
    \ std::vector<int>(n, -1);\r\n\t}\r\n\r\n\tint get(int x) {\r\n\t\treturn e[x]\
    \ < 0 ? x : e[x] = get(e[x]);\r\n\t}\r\n\r\n\tbool same_set(int a, int b) {\r\n\
    \t\treturn get(a) == get(b);\r\n\t}\r\n\r\n\tint size(int x) {\r\n\t\treturn -e[get(x)];\r\
    \n\t}\r\n\r\n\tbool unite(int x, int y) {\r\n\t\tx = get(x), y = get(y);\r\n\t\
    \tif (x == y) return false;\r\n\t\tif (e[x] > e[y]) std::swap(x, y);\r\n\t\te[x]\
    \ += e[y]; e[y] = x;\r\n\t\treturn true;\r\n\t}\r\n};\r\n\r\n#include <bits/extc++.h>\r\
    \n\r\nstruct splitmix64_hash {\r\n\tstatic uint64_t splitmix64(uint64_t x) {\r\
    \n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\
    \n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n\t\treturn x ^ (x >> 31);\r\
    \n\t}\r\n\r\n\tsize_t operator()(uint64_t x) const {\r\n\t\tstatic const uint64_t\
    \ FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\ntemplate <typename\
    \ K, typename V, typename Hash = splitmix64_hash>\r\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\r\n\r\ntemplate <typename K, typename Hash = splitmix64_hash>\r\n\
    using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;\n\r\ninline char gc()\
    \ { // like getchar()\r\n\tstatic char buf[1 << 16];\r\n\tstatic size_t bc, be;\r\
    \n\tif (bc >= be) {\r\n\t\tbuf[0] = 0, bc = 0;\r\n\t\tbe = fread(buf, 1, sizeof(buf),\
    \ stdin);\r\n\t}\r\n\treturn buf[bc++]; // returns 0 on EOF\r\n}\r\n\r\nint read_int()\
    \ {\r\n\tint a, c;\r\n\twhile ((a = gc()) < 40);\r\n\tif (a == '-') return -read_int();\r\
    \n\twhile ((c = gc()) >= 48) a = a * 10 + c - 480;\r\n\treturn a - 48;\r\n}\n\r\
    \nconst int N = 1e6 + 5;\r\nconst int B = 600;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tSieve<N> sieve;\r\n\tint n = read_int();\r\n\tint q\
    \ = read_int();\r\n\tvector<int> a(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\
    \ta[i] = read_int();\r\n\t}\r\n\tvector<int> head(N, -1);\r\n\tDSU dsu;\r\n\t\
    dsu.init(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tauto f = sieve.factor(a[i]);\r\
    \n\t\tfor (auto [p, e] : f) {\r\n\t\t\tif (head[p] == -1) {\r\n\t\t\t\thead[p]\
    \ = i;\r\n\t\t\t} else {\r\n\t\t\t\tdsu.unite(head[p], i);\r\n\t\t\t}\r\n\t\t\
    }\r\n\t}\r\n\tvector<vector<int>> in(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\
    \t\tauto f1 = sieve.factor(a[i] + 1);\r\n\t\tauto f2 = sieve.factor(a[i]);\r\n\
    \t\treverse(f1.begin(), f1.end());\r\n\t\treverse(f2.begin(), f2.end());\r\n\t\
    \tvector<int> f;\r\n\t\twhile (!f1.empty() || !f2.empty()) {\r\n\t\t\tif (f1.empty())\
    \ {\r\n\t\t\t\tf.push_back(f2.back().first);\r\n\t\t\t\tf2.pop_back(); \r\n\t\t\
    \t} else if (f2.empty()) {\r\n\t\t\t\tf.push_back(f1.back().first);\r\n\t\t\t\t\
    f1.pop_back();\r\n\t\t\t} else {\r\n\t\t\t\tif (f1.back().first == f2.back().first)\
    \ {\r\n\t\t\t\t\tf1.pop_back();\r\n\t\t\t\t} else if (f1.back().first < f2.back().first)\
    \ {\r\n\t\t\t\t\tf.push_back(f1.back().first);\r\n\t\t\t\t\tf1.pop_back();\r\n\
    \t\t\t\t} else {\r\n\t\t\t\t\tf.push_back(f2.back().first);\r\n\t\t\t\t\tf2.pop_back();\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tvector<int> join;\r\n\t\tfor (int p : f)\
    \ {\r\n\t\t\tif (head[p] == -1) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tjoin.push_back(dsu.get(head[p]));\r\
    \n\t\t}\r\n\t\tsort(join.begin(), join.end());\r\n\t\tjoin.resize(unique(join.begin(),\
    \ join.end()) - join.begin());\r\n\t\tfor (int x : join) {\r\n\t\t\tin[x].push_back(i);\r\
    \n\t\t}\r\n\t}\r\n\tvector<hash_set<int>> check(n);\r\n\tfor (int i = 0; i < n;\
    \ ++i) {\r\n\t\tfor (int j : in[i]) {\r\n\t\t\tcheck[i].insert(j);\r\n\t\t}\r\n\
    \t}\r\n\tvector<int> ans(q, 2);\r\n\tvector<bool> big(n);\r\n\tvector<int> big_sets;\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tif (in[i].size() >= B) {\r\n\t\t\tbig[i]\
    \ = true;\r\n\t\t\tbig_sets.push_back(i);\r\n\t\t} else {\r\n\t\t\tbig[i] = false;\r\
    \n\t\t}\r\n\t}\r\n\tvector<vector<int>> table(n);\r\n\tfor (int i : big_sets)\
    \ {\r\n\t\tfor (int j : in[i]) {\r\n\t\t\ttable[j].push_back(i);\r\n\t\t}\r\n\t\
    }\r\n\tset<array<int, 2>> good_pairs;\r\n\tfor (vector<int> v : table) {\r\n\t\
    \tfor (int i : v) {\r\n\t\t\tfor (int j : v) {\r\n\t\t\t\tif (i < j) {\r\n\t\t\
    \t\t\tgood_pairs.insert({i, j});\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\
    auto overlap = [&](int u, int v) {\r\n\t\tif (u > v) {\r\n\t\t\tswap(u, v);\r\n\
    \t\t}\r\n\t\tif (big[u] && big[v]) {\r\n\t\t\tif (good_pairs.count({u, v})) {\r\
    \n\t\t\t\treturn true;\r\n\t\t\t} else {\r\n\t\t\t\treturn false;\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\tif (in[u].size() > in[v].size()) {\r\n\t\t\tswap(u, v);\r\n\t\t\
    }\r\n\t\tfor (int x : in[u]) {\r\n\t\t\tif (check[v].find(x) != check[v].end())\
    \ {\r\n\t\t\t\treturn true;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn false;\r\n\t};\r\
    \n\tfor (int qq = 0; qq < q; ++qq) {\r\n\t\tint s = read_int();\r\n\t\tint t =\
    \ read_int();\r\n\t\t--s, --t;\r\n\t\tif (dsu.same_set(s, t)) {\r\n\t\t\tans[qq]\
    \ = 0;\r\n\t\t} else {\r\n\t\t\tint u = dsu.get(s);\t\r\n\t\t\tint v = dsu.get(t);\r\
    \n\t\t\tif (overlap(u, v)) {\r\n\t\t\t\tans[qq] = 1;\r\n\t\t\t} else {\r\n\t\t\
    \t\tans[qq] = 2;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tfor (int qq = 0; qq < q; ++qq)\
    \ {\r\n\t\tcout << ans[qq] << '\\n';\r\n\t}\r\n\treturn 0;\r\n}\r\n\r\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1553/problem/G\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/number-theory/fast-factor-sieve.hpp\"\
    \r\n#include \"../../library/graphs/dsu.hpp\"\r\n#include \"../../library/misc/fast-hash-map.hpp\"\
    \r\n#include \"../../library/misc/fast-input.hpp\"\r\n\r\nconst int N = 1e6 +\
    \ 5;\r\nconst int B = 600;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tSieve<N> sieve;\r\n\tint n = read_int();\r\n\tint q\
    \ = read_int();\r\n\tvector<int> a(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\
    \ta[i] = read_int();\r\n\t}\r\n\tvector<int> head(N, -1);\r\n\tDSU dsu;\r\n\t\
    dsu.init(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tauto f = sieve.factor(a[i]);\r\
    \n\t\tfor (auto [p, e] : f) {\r\n\t\t\tif (head[p] == -1) {\r\n\t\t\t\thead[p]\
    \ = i;\r\n\t\t\t} else {\r\n\t\t\t\tdsu.unite(head[p], i);\r\n\t\t\t}\r\n\t\t\
    }\r\n\t}\r\n\tvector<vector<int>> in(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\
    \t\tauto f1 = sieve.factor(a[i] + 1);\r\n\t\tauto f2 = sieve.factor(a[i]);\r\n\
    \t\treverse(f1.begin(), f1.end());\r\n\t\treverse(f2.begin(), f2.end());\r\n\t\
    \tvector<int> f;\r\n\t\twhile (!f1.empty() || !f2.empty()) {\r\n\t\t\tif (f1.empty())\
    \ {\r\n\t\t\t\tf.push_back(f2.back().first);\r\n\t\t\t\tf2.pop_back(); \r\n\t\t\
    \t} else if (f2.empty()) {\r\n\t\t\t\tf.push_back(f1.back().first);\r\n\t\t\t\t\
    f1.pop_back();\r\n\t\t\t} else {\r\n\t\t\t\tif (f1.back().first == f2.back().first)\
    \ {\r\n\t\t\t\t\tf1.pop_back();\r\n\t\t\t\t} else if (f1.back().first < f2.back().first)\
    \ {\r\n\t\t\t\t\tf.push_back(f1.back().first);\r\n\t\t\t\t\tf1.pop_back();\r\n\
    \t\t\t\t} else {\r\n\t\t\t\t\tf.push_back(f2.back().first);\r\n\t\t\t\t\tf2.pop_back();\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tvector<int> join;\r\n\t\tfor (int p : f)\
    \ {\r\n\t\t\tif (head[p] == -1) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tjoin.push_back(dsu.get(head[p]));\r\
    \n\t\t}\r\n\t\tsort(join.begin(), join.end());\r\n\t\tjoin.resize(unique(join.begin(),\
    \ join.end()) - join.begin());\r\n\t\tfor (int x : join) {\r\n\t\t\tin[x].push_back(i);\r\
    \n\t\t}\r\n\t}\r\n\tvector<hash_set<int>> check(n);\r\n\tfor (int i = 0; i < n;\
    \ ++i) {\r\n\t\tfor (int j : in[i]) {\r\n\t\t\tcheck[i].insert(j);\r\n\t\t}\r\n\
    \t}\r\n\tvector<int> ans(q, 2);\r\n\tvector<bool> big(n);\r\n\tvector<int> big_sets;\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tif (in[i].size() >= B) {\r\n\t\t\tbig[i]\
    \ = true;\r\n\t\t\tbig_sets.push_back(i);\r\n\t\t} else {\r\n\t\t\tbig[i] = false;\r\
    \n\t\t}\r\n\t}\r\n\tvector<vector<int>> table(n);\r\n\tfor (int i : big_sets)\
    \ {\r\n\t\tfor (int j : in[i]) {\r\n\t\t\ttable[j].push_back(i);\r\n\t\t}\r\n\t\
    }\r\n\tset<array<int, 2>> good_pairs;\r\n\tfor (vector<int> v : table) {\r\n\t\
    \tfor (int i : v) {\r\n\t\t\tfor (int j : v) {\r\n\t\t\t\tif (i < j) {\r\n\t\t\
    \t\t\tgood_pairs.insert({i, j});\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\
    auto overlap = [&](int u, int v) {\r\n\t\tif (u > v) {\r\n\t\t\tswap(u, v);\r\n\
    \t\t}\r\n\t\tif (big[u] && big[v]) {\r\n\t\t\tif (good_pairs.count({u, v})) {\r\
    \n\t\t\t\treturn true;\r\n\t\t\t} else {\r\n\t\t\t\treturn false;\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\tif (in[u].size() > in[v].size()) {\r\n\t\t\tswap(u, v);\r\n\t\t\
    }\r\n\t\tfor (int x : in[u]) {\r\n\t\t\tif (check[v].find(x) != check[v].end())\
    \ {\r\n\t\t\t\treturn true;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn false;\r\n\t};\r\
    \n\tfor (int qq = 0; qq < q; ++qq) {\r\n\t\tint s = read_int();\r\n\t\tint t =\
    \ read_int();\r\n\t\t--s, --t;\r\n\t\tif (dsu.same_set(s, t)) {\r\n\t\t\tans[qq]\
    \ = 0;\r\n\t\t} else {\r\n\t\t\tint u = dsu.get(s);\t\r\n\t\t\tint v = dsu.get(t);\r\
    \n\t\t\tif (overlap(u, v)) {\r\n\t\t\t\tans[qq] = 1;\r\n\t\t\t} else {\r\n\t\t\
    \t\tans[qq] = 2;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tfor (int qq = 0; qq < q; ++qq)\
    \ {\r\n\t\tcout << ans[qq] << '\\n';\r\n\t}\r\n\treturn 0;\r\n}\r\n\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/fast-factor-sieve.hpp
  - library/graphs/dsu.hpp
  - library/misc/fast-hash-map.hpp
  - library/misc/fast-input.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1553G.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1553G.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1553G.test.cpp
- /verify/verify/codeforces/codeforces-1553G.test.cpp.html
title: verify/codeforces/codeforces-1553G.test.cpp
---
