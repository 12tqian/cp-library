---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: library/data-structures/1d-range-queries/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: library/string/suffix-array-lcp.hpp
    title: Suffix Array with Longest Common Prefix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
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
    \ SuffixArray {\n\tstring s;\n\tint n;\n\tvector<int> sa, isa, lcp;\n\tSparseTable<int>\
    \ spr;\n \n\tvector<int> suffix_array(vector<int> st, int upper) {\n\t\tint sz\
    \ = (int)st.size();\n\t\tif (sz == 0)\n\t\t\treturn {};\n\t\tvector<int> res(sz);\n\
    \t\tvector<bool> ls(sz);\n\t\tfor (int i = sz - 2; i >= 0; i--) \n\t\t\tls[i]\
    \ = st[i] == st[i + 1] ? ls[i + 1] : st[i] < st[i + 1];\n\t\tvector<int> sum_l(upper),\
    \ sum_s(upper);\n\t\tfor (int i = 0; i < sz; i++)\n\t\t\t(ls[i] ? sum_l[st[i]\
    \ + 1] : sum_s[st[i]])++;\n\t\tfor (int i = 0; i < upper; i++) {\n\t\t\tif (i)\n\
    \t\t\t\tsum_l[i] += sum_s[i - 1];\n\t\t\tsum_s[i] += sum_l[i];\n\t\t}\n\t\tauto\
    \ induce = [&](const vector<int> &lms) {\n\t\t\tfill(res.begin(), res.end(), -1);\n\
    \t\t\tvector<int> buf = sum_s;\n\t\t\tfor (int d : lms) \n\t\t\t\tif (d != sz)\n\
    \t\t\t\t\tres[buf[st[d]]++] = d;\n\t\t\tbuf = sum_l;\n\t\t\tres[buf[st[sz - 1]]++]\
    \ = sz - 1;\n\t\t\tfor (int i = 0; i < sz; i++) {\n\t\t\t\tint v = res[i] - 1;\n\
    \t\t\t\tif (v >= 0 && !ls[v])\n\t\t\t\t\tres[buf[st[v]]++] = v;\n\t\t\t}\n\t\t\
    \tbuf =  sum_l;\n\t\t\tfor (int i = sz - 1; i >= 0; i--) {\n\t\t\t\tint v = res[i]\
    \ - 1;\n\t\t\t\tif (v >= 0 && ls[v])\n\t\t\t\t\tres[--buf[st[v] + 1]] = v;\n\t\
    \t\t}\n\t\t};  \n\t\tvector<int> lms_map(sz + 1, -1), lms;\n\t\tint m = 0;\n\t\
    \tfor (int i = 1; i < sz; i++) \n\t\t\tif (!ls[i - 1] && ls[i])\n\t\t\t\tlms_map[i]\
    \ = m++, lms.push_back(i);\n\t\tinduce(lms);\n\t\tvector<int> sorted_lms;\n\t\t\
    for (auto& v : res)\n\t\t\tif (lms_map[v] != -1)\n\t\t\t\tsorted_lms.push_back(v);\n\
    \t\tvector<int> rec_s(m);\n\t\tint rec_upper = 0;\n\t\tfor (int i = 1; i < m;\
    \ i++) {\n\t\t\tint l = sorted_lms[i - 1];\n\t\t\tint r = sorted_lms[i];\n\t\t\
    \tint end_l = lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n;\n\t\t\tint end_r =\
    \ lms_map[r] + 1 < m ? lms[lms_map[r] + 1] : n;\n\t\t\tbool same = false;\n\t\t\
    \tif (end_l - l == end_r - r) {\n\t\t\t\tfor (; l < end_l && st[l] == st[r]; ++l,\
    \ ++r);\n\t\t\t\tif (l != n && st[l] == st[r])\n\t\t\t\t\tsame = true;\n\t\t\t\
    }\n\t\t\trec_s[lms_map[sorted_lms[i]]] = (rec_upper += !same);\n\t\t}\n\t\tvector<int>\
    \ rec_sa = suffix_array(rec_s, rec_upper\n\t\t\t + 1);\n\t\tfor (int i = 0; i\
    \ < m; i++)\n\t\t\tsorted_lms[i] = lms[rec_sa[i]];\n\t\tinduce(sorted_lms);\n\t\
    \treturn res;\n\t}\n\t\n\tvoid generate_suffix_array(string _s) {\n\t\tn = (int)(s\
    \ = _s).size() + 1;\n\t\tvector<int> tmp;\n\t\tfor (int i = 0; i < (int)s.size();\
    \ ++i) {\n\t\t\ttmp.push_back(s[i] - 'a');\n\t\t}\n\t\tsa = suffix_array(tmp,\
    \ 26);\n\t}\n\n\tvoid generate_lcp_array() {\n\t\tsa.insert(sa.begin(), -1);\n\
    \t\tisa.resize(sa.size());\n\t\tfor (int i = 1; i < (int)sa.size(); ++i) {\n\t\
    \t\tisa[sa[i]] = i;\n\t\t}\t\n\t\tgen_lcp_array();\n\t\tgen_finish();\n\t}\n \n\
    \tvoid gen_lcp_array() {\n\t\tlcp = vector<int>(n - 1);\n\t\tint h = 0;\n\t\t\
    for (int b = 0; b < n - 1; b++) {\n\t\t\tint a = sa[isa[b] - 1];\n\t\t\twhile\
    \ (a + h < (int)s.size() && s[a + h] == s[b + h]) \n\t\t\t\th++;\n\t\t\tlcp[isa[b]\
    \ - 1] = h;\n\t\t\tif (h) h--;\n\t\t}\n\t}\n \n\tvoid gen_finish() {\n\t\tlcp.erase(lcp.begin());\n\
    \t\tsa.erase(sa.begin());\n\t\tfor (int i = 0; i < (int)isa.size(); i++) \n\t\t\
    \tisa[i]--;\n\t\tn--; \n\t\tisa.pop_back();\n\t\tspr.init(lcp);\n\t}\n\t\n\tint\
    \ get_lcp(int a, int b) {\n\t\tif (a == b) {\n\t\t\treturn (int)s.size() - a;\n\
    \t\t}\n\t\tint l = isa[a], r = isa[b]; \n\t\tif (l > r) swap(l, r);\n\t\treturn\
    \ spr.query(l, r - 1);\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\
    \tstring s; cin >> s;\n\tint n = (int)s.size();\n\tSuffixArray S;\n\tS.generate_suffix_array(s);\n\
    \tfor (int i = 0; i < n; i++)\n\t\tcout << S.sa[i] << \" \";\n\tcout << '\\n';\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/string/suffix-array-lcp.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\t\
    string s; cin >> s;\n\tint n = (int)s.size();\n\tSuffixArray S;\n\tS.generate_suffix_array(s);\n\
    \tfor (int i = 0; i < n; i++)\n\t\tcout << S.sa[i] << \" \";\n\tcout << '\\n';\n\
    \treturn 0;\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/string/suffix-array-lcp.hpp
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
  requiredBy: []
  timestamp: '2021-08-12 23:30:38-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-suffixarray-lcp.test.cpp
- /verify/verify/yosupo/yosupo-suffixarray-lcp.test.cpp.html
title: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
---
