---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: library/data-structures/1d-range-queries/sparse-table.hpp
  - icon: ':x:'
    path: library/string/suffix-array.hpp
    title: library/string/suffix-array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n/**\n * sa stores sorted suffixes\n * isa is inverse of sa\n * lcp is longest\
    \ common prefix between consecutive elements\n * Indexing has been fixed so that\
    \ everything is 0-indexed by the end\n */\n\n\n/**\n * This Sparse Table stores\
    \ indices of things\n * For destructive combinations like gcd, use associative_range_query.cpp\n\
    \ * Use this for min, max, and when you need the indices of things\n */\n\ntemplate\
    \ <class T> struct SparseTable {\n\tstd::vector<T> v;\n\tstd::vector<std::vector<int>>\
    \ jump;\n\n\tint level(int x) { return 31 - __builtin_clz(x); }\n\n\tint comb(int\
    \ a, int b) {\n\t\treturn v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\n\
    \t}\n\n\tvoid init(const std::vector<T> &_v) {\n\t\tv = _v;\n\t\tjump = {std::vector<int>((int)v.size())};\n\
    \t\tiota(jump[0].begin(), jump[0].end(), 0);\n\t\tfor (int j = 1; (1 << j) <=\
    \ (int)v.size(); j++) {\n\t\t\tjump.push_back(std::vector<int>((int)v.size() -\
    \ (1 << j) + 1));\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\n\t\t\
    \t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n\t\t\t\
    }\n\t\t}\n\t}\n\n\tint index(int l, int r) {\n\t\tassert(l <= r);\n\t\tint d =\
    \ level(r - l + 1);\n\t\treturn comb(jump[d][l], jump[d][r - (1 << d) + 1]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\treturn v[index(l, r)];\n\t}\n};\n\nstruct\
    \ SuffixArray {\n\tstd::string s;\n\tint n;\n\tstd::vector<int> sa, isa, lcp;\n\
    \tSparseTable<int> S;\n\n\tvoid init(std::string _s) {\n\t\tn = (int)(s = _s).size()\
    \ + 1;\n\t\tgen_suffix_array();\n\t\tgen_lcp_array();\n\t\tgen_finish();\n\t}\n\
    \n\tvoid gen_suffix_array() {\n\t\tsa = isa = std::vector<int>(n);\n\t\tsa[0]\
    \ = n - 1;\n\t\tiota(1 + sa.begin(), sa.end(), 0);\n\t\tsort(1 + sa.begin(), sa.end(),\
    \ [&](int a, int b) {\n\t\t\treturn s[a] < s[b];\n\t\t});\n\t\tfor (int i = 1;\
    \ i < n; i++) {\n\t\t\tint a = sa[i - 1], b = sa[i];\n\t\t\tisa[b] = i > 1 &&\
    \ s[a] == s[b] ? isa[a] : i;\n\t\t}\n\t\tfor (int len = 1; len < n; len *= 2)\
    \ {\n\t\t\tstd::vector<int> ss(sa), is(isa), pos(n);\n\t\t\tiota(pos.begin(),\
    \ pos.end(), 0);\n\t\t\tfor (auto &t : ss) {\n\t\t\t\tint tt = t - len;\n\t\t\t\
    \tif (tt >= 0) \n\t\t\t\t\tsa[pos[isa[tt]]++] = tt;\n\t\t\t}\n\t\t\tfor (int i\
    \ = 1; i < n; i++) {\n\t\t\t\tint a = sa[i - 1], b = sa[i];\n\t\t\t\tisa[b] =\
    \ is[a] == is[b] && is[a + len] == is[b + len] ? isa[a] : i;\n\t\t\t}\n\t\t}\n\
    \t}\n\n\tvoid gen_lcp_array() {\n\t\tlcp = std::vector<int>(n - 1);\n\t\tint h\
    \ = 0;\n\t\tfor (int b = 0; b < n - 1; b++) {\n\t\t\tint a = sa[isa[b] - 1];\n\
    \t\t\twhile (a + h < (int)s.size() && s[a + h] == s[b + h]) \n\t\t\t\th++;\n\t\
    \t\tlcp[isa[b] - 1] = h;\n\t\t\tif (h) h--;\n\t\t}\n\t}\n\n\tvoid gen_finish()\
    \ {\n\t\tlcp.erase(lcp.begin());\n\t\tsa.erase(sa.begin());\n\t\tfor (int i =\
    \ 0; i < (int)isa.size(); i++) \n\t\t\tisa[i]--;\n\t\tn--; \n\t\tisa.pop_back();\n\
    \t\tS.init(lcp);\n\t}\n\t\n\tint get_lcp(int a, int b) {\n\t\tif (a == b) {\n\t\
    \t\treturn (int)s.size() - a;\n\t\t}\n\t\tint l = isa[a], r = isa[b]; \n\t\tif\
    \ (l > r) std::swap(l, r);\n\t\treturn S.query(l, r - 1);\n\t}\n};\n\nint main()\
    \ {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\tstring s; cin\
    \ >> s;\n\tint n = (int)s.size();\n\tSuffixArray S;\n\tS.init(s);\n\tfor (int\
    \ i = 0; i < n; i++)\n\t\tcout << S.sa[i] << \" \";\n\tcout << '\\n';\n\treturn\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/string/suffix-array.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\t\
    string s; cin >> s;\n\tint n = (int)s.size();\n\tSuffixArray S;\n\tS.init(s);\n\
    \tfor (int i = 0; i < n; i++)\n\t\tcout << S.sa[i] << \" \";\n\tcout << '\\n';\n\
    \treturn 0;\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/string/suffix-array.hpp
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-suffixarray-logarithm.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-suffixarray-logarithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-suffixarray-logarithm.test.cpp
- /verify/verify/yosupo/yosupo-suffixarray-logarithm.test.cpp.html
title: verify/yosupo/yosupo-suffixarray-logarithm.test.cpp
---
