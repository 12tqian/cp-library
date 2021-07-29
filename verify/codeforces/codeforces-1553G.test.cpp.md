---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1553/problem/G\"\n\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <int SZ> struct Sieve {\n\tint spf[SZ];\n\t\n\tSieve() {\n\t\tspf[1]\
    \ = 1;\n\t\tfor (int i = 2; i < SZ; i++) \n\t\t\tspf[i] = i;\n\t\tfor (int i =\
    \ 4; i < SZ; i += 2) \n\t\t\tspf[i] = 2;\n\t\tfor (int i = 3; i * i < SZ; i++)\
    \ \n\t\t\tif (spf[i] == i) \n\t\t\t\tfor (int j = i * i; j < SZ; j += i) \n\t\t\
    \t\t\tif (spf[j] == j) \n\t\t\t\t\t\tspf[j] = i;\n\t}\n\n\tstd::vector<std::pair<int,\
    \ int>> factor(int x) {\n\t\tstd::vector<std::pair<int, int>> ret;\n\t\twhile\
    \ (x != 1) {\n\t\t\tif ((int)ret.size() == 0) \n\t\t\t\tret.emplace_back(spf[x],\
    \ 1);\n\t\t\telse {\n\t\t\t\tif (ret.back().first == spf[x]) \n\t\t\t\t\tret.back().second++;\n\
    \t\t\t\telse \n\t\t\t\t\tret.emplace_back(spf[x], 1);\n\t\t\t}\n\t\t\tx /= spf[x];\n\
    \t\t}\n\t\treturn ret;\n\t}\n};\n\nstruct DSU {\n\tstd::vector<int> e;\n\n\tvoid\
    \ init(int n) {\n\t\te = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\
    \t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\n\t}\n\n\tbool same_set(int a, int\
    \ b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\
    \t}\n\n\tbool unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\tif (x ==\
    \ y) return false;\n\t\tif (e[x] > e[y]) std::swap(x, y);\n\t\te[x] += e[y]; e[y]\
    \ = x;\n\t\treturn true;\n\t}\n};\n\n#include <bits/extc++.h>\n\nstruct splitmix64_hash\
    \ {\n\tstatic uint64_t splitmix64(uint64_t x) {\n\t\tx += 0x9e3779b97f4a7c15;\n\
    \t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \t\treturn x ^ (x >> 31);\n\t}\n\n\tsize_t operator()(uint64_t x) const {\n\t\t\
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \t\treturn splitmix64(x + FIXED_RANDOM);\n\t}\n};\n\ntemplate <typename K, typename\
    \ V, typename Hash = splitmix64_hash>\nusing hash_map = __gnu_pbds::gp_hash_table<K,\
    \ V, Hash>;\n\ntemplate <typename K, typename Hash = splitmix64_hash>\nusing hash_set\
    \ = hash_map<K, __gnu_pbds::null_type, Hash>;\n\ninline char gc() { // like getchar()\n\
    \tstatic char buf[1 << 16];\n\tstatic size_t bc, be;\n\tif (bc >= be) {\n\t\t\
    buf[0] = 0, bc = 0;\n\t\tbe = fread(buf, 1, sizeof(buf), stdin);\n\t}\n\treturn\
    \ buf[bc++]; // returns 0 on EOF\n}\n\nint read_int() {\n\tint a, c;\n\twhile\
    \ ((a = gc()) < 40);\n\tif (a == '-') return -read_int();\n\twhile ((c = gc())\
    \ >= 48) a = a * 10 + c - 480;\n\treturn a - 48;\n}\n\nconst int N = 1e6 + 5;\n\
    const int B = 600;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tSieve<N> sieve;\n\tint n = read_int();\n\tint q = read_int();\n\tvector<int>\
    \ a(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\ta[i] = read_int();\n\t}\n\tvector<int>\
    \ head(N, -1);\n\tDSU dsu;\n\tdsu.init(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\
    \tauto f = sieve.factor(a[i]);\n\t\tfor (auto [p, e] : f) {\n\t\t\tif (head[p]\
    \ == -1) {\n\t\t\t\thead[p] = i;\n\t\t\t} else {\n\t\t\t\tdsu.unite(head[p], i);\n\
    \t\t\t}\n\t\t}\n\t}\n\tvector<vector<int>> in(n);\n\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\tauto f1 = sieve.factor(a[i] + 1);\n\t\tauto f2 = sieve.factor(a[i]);\n\
    \t\treverse(f1.begin(), f1.end());\n\t\treverse(f2.begin(), f2.end());\n\t\tvector<int>\
    \ f;\n\t\twhile (!f1.empty() || !f2.empty()) {\n\t\t\tif (f1.empty()) {\n\t\t\t\
    \tf.push_back(f2.back().first);\n\t\t\t\tf2.pop_back(); \n\t\t\t} else if (f2.empty())\
    \ {\n\t\t\t\tf.push_back(f1.back().first);\n\t\t\t\tf1.pop_back();\n\t\t\t} else\
    \ {\n\t\t\t\tif (f1.back().first == f2.back().first) {\n\t\t\t\t\tf1.pop_back();\n\
    \t\t\t\t} else if (f1.back().first < f2.back().first) {\n\t\t\t\t\tf.push_back(f1.back().first);\n\
    \t\t\t\t\tf1.pop_back();\n\t\t\t\t} else {\n\t\t\t\t\tf.push_back(f2.back().first);\n\
    \t\t\t\t\tf2.pop_back();\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> join;\n\t\
    \tfor (int p : f) {\n\t\t\tif (head[p] == -1) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\
    \t\tjoin.push_back(dsu.get(head[p]));\n\t\t}\n\t\tsort(join.begin(), join.end());\n\
    \t\tjoin.resize(unique(join.begin(), join.end()) - join.begin());\n\t\tfor (int\
    \ x : join) {\n\t\t\tin[x].push_back(i);\n\t\t}\n\t}\n\tvector<hash_set<int>>\
    \ check(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j : in[i]) {\n\t\t\t\
    check[i].insert(j);\n\t\t}\n\t}\n\tvector<int> ans(q, 2);\n\tvector<bool> big(n);\n\
    \tvector<int> big_sets;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (in[i].size()\
    \ >= B) {\n\t\t\tbig[i] = true;\n\t\t\tbig_sets.push_back(i);\n\t\t} else {\n\t\
    \t\tbig[i] = false;\n\t\t}\n\t}\n\tvector<vector<int>> table(n);\n\tfor (int i\
    \ : big_sets) {\n\t\tfor (int j : in[i]) {\n\t\t\ttable[j].push_back(i);\n\t\t\
    }\n\t}\n\tset<array<int, 2>> good_pairs;\n\tfor (vector<int> v : table) {\n\t\t\
    for (int i : v) {\n\t\t\tfor (int j : v) {\n\t\t\t\tif (i < j) {\n\t\t\t\t\tgood_pairs.insert({i,\
    \ j});\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tauto overlap = [&](int u, int v) {\n\
    \t\tif (u > v) {\n\t\t\tswap(u, v);\n\t\t}\n\t\tif (big[u] && big[v]) {\n\t\t\t\
    if (good_pairs.count({u, v})) {\n\t\t\t\treturn true;\n\t\t\t} else {\n\t\t\t\t\
    return false;\n\t\t\t}\n\t\t}\n\t\tif (in[u].size() > in[v].size()) {\n\t\t\t\
    swap(u, v);\n\t\t}\n\t\tfor (int x : in[u]) {\n\t\t\tif (check[v].find(x) != check[v].end())\
    \ {\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t};\n\tfor (int\
    \ qq = 0; qq < q; ++qq) {\n\t\tint s = read_int();\n\t\tint t = read_int();\n\t\
    \t--s, --t;\n\t\tif (dsu.same_set(s, t)) {\n\t\t\tans[qq] = 0;\n\t\t} else {\n\
    \t\t\tint u = dsu.get(s);\t\n\t\t\tint v = dsu.get(t);\n\t\t\tif (overlap(u, v))\
    \ {\n\t\t\t\tans[qq] = 1;\n\t\t\t} else {\n\t\t\t\tans[qq] = 2;\n\t\t\t}\n\t\t\
    }\n\t}\n\tfor (int qq = 0; qq < q; ++qq) {\n\t\tcout << ans[qq] << '\\n';\n\t\
    }\n\treturn 0;\n}\n\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1553/problem/G\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/number-theory/fast-factor-sieve.hpp\"\
    \n#include \"../../library/graphs/dsu.hpp\"\n#include \"../../library/misc/fast-hash-map.hpp\"\
    \n#include \"../../library/misc/fast-input.hpp\"\n\nconst int N = 1e6 + 5;\nconst\
    \ int B = 600;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tSieve<N> sieve;\n\tint n = read_int();\n\tint q = read_int();\n\tvector<int>\
    \ a(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\ta[i] = read_int();\n\t}\n\tvector<int>\
    \ head(N, -1);\n\tDSU dsu;\n\tdsu.init(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\
    \tauto f = sieve.factor(a[i]);\n\t\tfor (auto [p, e] : f) {\n\t\t\tif (head[p]\
    \ == -1) {\n\t\t\t\thead[p] = i;\n\t\t\t} else {\n\t\t\t\tdsu.unite(head[p], i);\n\
    \t\t\t}\n\t\t}\n\t}\n\tvector<vector<int>> in(n);\n\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\tauto f1 = sieve.factor(a[i] + 1);\n\t\tauto f2 = sieve.factor(a[i]);\n\
    \t\treverse(f1.begin(), f1.end());\n\t\treverse(f2.begin(), f2.end());\n\t\tvector<int>\
    \ f;\n\t\twhile (!f1.empty() || !f2.empty()) {\n\t\t\tif (f1.empty()) {\n\t\t\t\
    \tf.push_back(f2.back().first);\n\t\t\t\tf2.pop_back(); \n\t\t\t} else if (f2.empty())\
    \ {\n\t\t\t\tf.push_back(f1.back().first);\n\t\t\t\tf1.pop_back();\n\t\t\t} else\
    \ {\n\t\t\t\tif (f1.back().first == f2.back().first) {\n\t\t\t\t\tf1.pop_back();\n\
    \t\t\t\t} else if (f1.back().first < f2.back().first) {\n\t\t\t\t\tf.push_back(f1.back().first);\n\
    \t\t\t\t\tf1.pop_back();\n\t\t\t\t} else {\n\t\t\t\t\tf.push_back(f2.back().first);\n\
    \t\t\t\t\tf2.pop_back();\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> join;\n\t\
    \tfor (int p : f) {\n\t\t\tif (head[p] == -1) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\
    \t\tjoin.push_back(dsu.get(head[p]));\n\t\t}\n\t\tsort(join.begin(), join.end());\n\
    \t\tjoin.resize(unique(join.begin(), join.end()) - join.begin());\n\t\tfor (int\
    \ x : join) {\n\t\t\tin[x].push_back(i);\n\t\t}\n\t}\n\tvector<hash_set<int>>\
    \ check(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j : in[i]) {\n\t\t\t\
    check[i].insert(j);\n\t\t}\n\t}\n\tvector<int> ans(q, 2);\n\tvector<bool> big(n);\n\
    \tvector<int> big_sets;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (in[i].size()\
    \ >= B) {\n\t\t\tbig[i] = true;\n\t\t\tbig_sets.push_back(i);\n\t\t} else {\n\t\
    \t\tbig[i] = false;\n\t\t}\n\t}\n\tvector<vector<int>> table(n);\n\tfor (int i\
    \ : big_sets) {\n\t\tfor (int j : in[i]) {\n\t\t\ttable[j].push_back(i);\n\t\t\
    }\n\t}\n\tset<array<int, 2>> good_pairs;\n\tfor (vector<int> v : table) {\n\t\t\
    for (int i : v) {\n\t\t\tfor (int j : v) {\n\t\t\t\tif (i < j) {\n\t\t\t\t\tgood_pairs.insert({i,\
    \ j});\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tauto overlap = [&](int u, int v) {\n\
    \t\tif (u > v) {\n\t\t\tswap(u, v);\n\t\t}\n\t\tif (big[u] && big[v]) {\n\t\t\t\
    if (good_pairs.count({u, v})) {\n\t\t\t\treturn true;\n\t\t\t} else {\n\t\t\t\t\
    return false;\n\t\t\t}\n\t\t}\n\t\tif (in[u].size() > in[v].size()) {\n\t\t\t\
    swap(u, v);\n\t\t}\n\t\tfor (int x : in[u]) {\n\t\t\tif (check[v].find(x) != check[v].end())\
    \ {\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t};\n\tfor (int\
    \ qq = 0; qq < q; ++qq) {\n\t\tint s = read_int();\n\t\tint t = read_int();\n\t\
    \t--s, --t;\n\t\tif (dsu.same_set(s, t)) {\n\t\t\tans[qq] = 0;\n\t\t} else {\n\
    \t\t\tint u = dsu.get(s);\t\n\t\t\tint v = dsu.get(t);\n\t\t\tif (overlap(u, v))\
    \ {\n\t\t\t\tans[qq] = 1;\n\t\t\t} else {\n\t\t\t\tans[qq] = 2;\n\t\t\t}\n\t\t\
    }\n\t}\n\tfor (int qq = 0; qq < q; ++qq) {\n\t\tcout << ans[qq] << '\\n';\n\t\
    }\n\treturn 0;\n}\n\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/fast-factor-sieve.hpp
  - library/graphs/dsu.hpp
  - library/misc/fast-hash-map.hpp
  - library/misc/fast-input.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1553G.test.cpp
  requiredBy: []
  timestamp: '2021-07-29 01:03:11-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1553G.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1553G.test.cpp
- /verify/verify/codeforces/codeforces-1553G.test.cpp.html
title: verify/codeforces/codeforces-1553G.test.cpp
---
