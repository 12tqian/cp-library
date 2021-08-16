---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
    title: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\n\ntemplate <class T> struct SparseTable {\n\tstd::vector<T> v;\n\
    \tstd::vector<std::vector<int>> jump;\n\n\tint level(int x) { return 31 - __builtin_clz(x);\
    \ }\n\n\tint comb(int a, int b) {\n\t\treturn v[a] == v[b] ? std::min(a, b) :\
    \ (v[a] < v[b] ? a : b);\n\t}\n\n\tvoid init(const std::vector<T>& _v) {\n\t\t\
    v = _v;\n\t\tjump = {std::vector<int>((int)v.size())};\n\t\tiota(jump[0].begin(),\
    \ jump[0].end(), 0);\n\t\tfor (int j = 1; (1 << j) <= (int)v.size(); j++) {\n\t\
    \t\tjump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));\n\t\t\tfor\
    \ (int i = 0; i < (int)jump[j].size(); i++) {\n\t\t\t\tjump[j][i] = comb(jump[j\
    \ - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tint index(int\
    \ l, int r) {\n\t\tassert(l <= r);\n\t\tint d = level(r - l + 1);\n\t\treturn\
    \ comb(jump[d][l], jump[d][r - (1 << d) + 1]);\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\treturn v[index(l, r)];\n\t}\n};\n\nstruct SuffixArray {\n\tstring s;\n\
    \tint n;\n\tvector<int> sa, isa, lcp;\n\tSparseTable<int> spr;\n \n\tvector<int>\
    \ suffix_array(vector<int> st, int upper) {\n\t\tint sz = (int)st.size();\n\t\t\
    if (sz == 0)\n\t\t\treturn {};\n\t\tvector<int> res(sz);\n\t\tvector<bool> ls(sz);\n\
    \t\tfor (int i = sz - 2; i >= 0; i--) \n\t\t\tls[i] = st[i] == st[i + 1] ? ls[i\
    \ + 1] : st[i] < st[i + 1];\n\t\tvector<int> sum_l(upper), sum_s(upper);\n\t\t\
    for (int i = 0; i < sz; i++)\n\t\t\t(ls[i] ? sum_l[st[i] + 1] : sum_s[st[i]])++;\n\
    \t\tfor (int i = 0; i < upper; i++) {\n\t\t\tif (i)\n\t\t\t\tsum_l[i] += sum_s[i\
    \ - 1];\n\t\t\tsum_s[i] += sum_l[i];\n\t\t}\n\t\tauto induce = [&](const vector<int>\
    \ &lms) {\n\t\t\tfill(res.begin(), res.end(), -1);\n\t\t\tvector<int> buf = sum_s;\n\
    \t\t\tfor (int d : lms) \n\t\t\t\tif (d != sz)\n\t\t\t\t\tres[buf[st[d]]++] =\
    \ d;\n\t\t\tbuf = sum_l;\n\t\t\tres[buf[st[sz - 1]]++] = sz - 1;\n\t\t\tfor (int\
    \ i = 0; i < sz; i++) {\n\t\t\t\tint v = res[i] - 1;\n\t\t\t\tif (v >= 0 && !ls[v])\n\
    \t\t\t\t\tres[buf[st[v]]++] = v;\n\t\t\t}\n\t\t\tbuf =  sum_l;\n\t\t\tfor (int\
    \ i = sz - 1; i >= 0; i--) {\n\t\t\t\tint v = res[i] - 1;\n\t\t\t\tif (v >= 0\
    \ && ls[v])\n\t\t\t\t\tres[--buf[st[v] + 1]] = v;\n\t\t\t}\n\t\t};  \n\t\tvector<int>\
    \ lms_map(sz + 1, -1), lms;\n\t\tint m = 0;\n\t\tfor (int i = 1; i < sz; i++)\
    \ \n\t\t\tif (!ls[i - 1] && ls[i])\n\t\t\t\tlms_map[i] = m++, lms.push_back(i);\n\
    \t\tinduce(lms);\n\t\tvector<int> sorted_lms;\n\t\tfor (auto& v : res)\n\t\t\t\
    if (lms_map[v] != -1)\n\t\t\t\tsorted_lms.push_back(v);\n\t\tvector<int> rec_s(m);\n\
    \t\tint rec_upper = 0;\n\t\tfor (int i = 1; i < m; i++) {\n\t\t\tint l = sorted_lms[i\
    \ - 1];\n\t\t\tint r = sorted_lms[i];\n\t\t\tint end_l = lms_map[l] + 1 < m ?\
    \ lms[lms_map[l] + 1] : n;\n\t\t\tint end_r = lms_map[r] + 1 < m ? lms[lms_map[r]\
    \ + 1] : n;\n\t\t\tbool same = false;\n\t\t\tif (end_l - l == end_r - r) {\n\t\
    \t\t\tfor (; l < end_l && st[l] == st[r]; ++l, ++r);\n\t\t\t\tif (l != n && st[l]\
    \ == st[r])\n\t\t\t\t\tsame = true;\n\t\t\t}\n\t\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = (rec_upper += !same);\n\t\t}\n\t\tvector<int> rec_sa = suffix_array(rec_s,\
    \ rec_upper\n\t\t\t + 1);\n\t\tfor (int i = 0; i < m; i++)\n\t\t\tsorted_lms[i]\
    \ = lms[rec_sa[i]];\n\t\tinduce(sorted_lms);\n\t\treturn res;\n\t}\n\t\n\tvoid\
    \ generate_suffix_array(string _s) {\n\t\tn = (int)(s = _s).size() + 1;\n\t\t\
    vector<int> tmp;\n\t\tfor (int i = 0; i < (int)s.size(); ++i) {\n\t\t\ttmp.push_back(s[i]\
    \ - 'a');\n\t\t}\n\t\tsa = suffix_array(tmp, 26);\n\t}\n\n\tvoid generate_lcp_array()\
    \ {\n\t\tsa.insert(sa.begin(), -1);\n\t\tisa.resize(sa.size());\n\t\tfor (int\
    \ i = 1; i < (int)sa.size(); ++i) {\n\t\t\tisa[sa[i]] = i;\n\t\t}\t\n\t\tgen_lcp_array();\n\
    \t\tgen_finish();\n\t}\n \n\tvoid gen_lcp_array() {\n\t\tlcp = vector<int>(n -\
    \ 1);\n\t\tint h = 0;\n\t\tfor (int b = 0; b < n - 1; b++) {\n\t\t\tint a = sa[isa[b]\
    \ - 1];\n\t\t\twhile (a + h < (int)s.size() && s[a + h] == s[b + h]) \n\t\t\t\t\
    h++;\n\t\t\tlcp[isa[b] - 1] = h;\n\t\t\tif (h) h--;\n\t\t}\n\t}\n \n\tvoid gen_finish()\
    \ {\n\t\tlcp.erase(lcp.begin());\n\t\tsa.erase(sa.begin());\n\t\tfor (int i =\
    \ 0; i < (int)isa.size(); i++) \n\t\t\tisa[i]--;\n\t\tn--; \n\t\tisa.pop_back();\n\
    \t\tspr.init(lcp);\n\t}\n\t\n\tint get_lcp(int a, int b) {\n\t\tif (a == b) {\n\
    \t\t\treturn (int)s.size() - a;\n\t\t}\n\t\tint l = isa[a], r = isa[b]; \n\t\t\
    if (l > r) swap(l, r);\n\t\treturn spr.query(l, r - 1);\n\t}\n};\n"
  code: "#pragma once\n\n#include \"../data-structures/1d-range-queries/sparse-table.hpp\"\
    \n\nstruct SuffixArray {\n\tstring s;\n\tint n;\n\tvector<int> sa, isa, lcp;\n\
    \tSparseTable<int> spr;\n \n\tvector<int> suffix_array(vector<int> st, int upper)\
    \ {\n\t\tint sz = (int)st.size();\n\t\tif (sz == 0)\n\t\t\treturn {};\n\t\tvector<int>\
    \ res(sz);\n\t\tvector<bool> ls(sz);\n\t\tfor (int i = sz - 2; i >= 0; i--) \n\
    \t\t\tls[i] = st[i] == st[i + 1] ? ls[i + 1] : st[i] < st[i + 1];\n\t\tvector<int>\
    \ sum_l(upper), sum_s(upper);\n\t\tfor (int i = 0; i < sz; i++)\n\t\t\t(ls[i]\
    \ ? sum_l[st[i] + 1] : sum_s[st[i]])++;\n\t\tfor (int i = 0; i < upper; i++) {\n\
    \t\t\tif (i)\n\t\t\t\tsum_l[i] += sum_s[i - 1];\n\t\t\tsum_s[i] += sum_l[i];\n\
    \t\t}\n\t\tauto induce = [&](const vector<int> &lms) {\n\t\t\tfill(res.begin(),\
    \ res.end(), -1);\n\t\t\tvector<int> buf = sum_s;\n\t\t\tfor (int d : lms) \n\t\
    \t\t\tif (d != sz)\n\t\t\t\t\tres[buf[st[d]]++] = d;\n\t\t\tbuf = sum_l;\n\t\t\
    \tres[buf[st[sz - 1]]++] = sz - 1;\n\t\t\tfor (int i = 0; i < sz; i++) {\n\t\t\
    \t\tint v = res[i] - 1;\n\t\t\t\tif (v >= 0 && !ls[v])\n\t\t\t\t\tres[buf[st[v]]++]\
    \ = v;\n\t\t\t}\n\t\t\tbuf =  sum_l;\n\t\t\tfor (int i = sz - 1; i >= 0; i--)\
    \ {\n\t\t\t\tint v = res[i] - 1;\n\t\t\t\tif (v >= 0 && ls[v])\n\t\t\t\t\tres[--buf[st[v]\
    \ + 1]] = v;\n\t\t\t}\n\t\t};  \n\t\tvector<int> lms_map(sz + 1, -1), lms;\n\t\
    \tint m = 0;\n\t\tfor (int i = 1; i < sz; i++) \n\t\t\tif (!ls[i - 1] && ls[i])\n\
    \t\t\t\tlms_map[i] = m++, lms.push_back(i);\n\t\tinduce(lms);\n\t\tvector<int>\
    \ sorted_lms;\n\t\tfor (auto& v : res)\n\t\t\tif (lms_map[v] != -1)\n\t\t\t\t\
    sorted_lms.push_back(v);\n\t\tvector<int> rec_s(m);\n\t\tint rec_upper = 0;\n\t\
    \tfor (int i = 1; i < m; i++) {\n\t\t\tint l = sorted_lms[i - 1];\n\t\t\tint r\
    \ = sorted_lms[i];\n\t\t\tint end_l = lms_map[l] + 1 < m ? lms[lms_map[l] + 1]\
    \ : n;\n\t\t\tint end_r = lms_map[r] + 1 < m ? lms[lms_map[r] + 1] : n;\n\t\t\t\
    bool same = false;\n\t\t\tif (end_l - l == end_r - r) {\n\t\t\t\tfor (; l < end_l\
    \ && st[l] == st[r]; ++l, ++r);\n\t\t\t\tif (l != n && st[l] == st[r])\n\t\t\t\
    \t\tsame = true;\n\t\t\t}\n\t\t\trec_s[lms_map[sorted_lms[i]]] = (rec_upper +=\
    \ !same);\n\t\t}\n\t\tvector<int> rec_sa = suffix_array(rec_s, rec_upper\n\t\t\
    \t + 1);\n\t\tfor (int i = 0; i < m; i++)\n\t\t\tsorted_lms[i] = lms[rec_sa[i]];\n\
    \t\tinduce(sorted_lms);\n\t\treturn res;\n\t}\n\t\n\tvoid generate_suffix_array(string\
    \ _s) {\n\t\tn = (int)(s = _s).size() + 1;\n\t\tvector<int> tmp;\n\t\tfor (int\
    \ i = 0; i < (int)s.size(); ++i) {\n\t\t\ttmp.push_back(s[i] - 'a');\n\t\t}\n\t\
    \tsa = suffix_array(tmp, 26);\n\t}\n\n\tvoid generate_lcp_array() {\n\t\tsa.insert(sa.begin(),\
    \ -1);\n\t\tisa.resize(sa.size());\n\t\tfor (int i = 1; i < (int)sa.size(); ++i)\
    \ {\n\t\t\tisa[sa[i]] = i;\n\t\t}\t\n\t\tgen_lcp_array();\n\t\tgen_finish();\n\
    \t}\n \n\tvoid gen_lcp_array() {\n\t\tlcp = vector<int>(n - 1);\n\t\tint h = 0;\n\
    \t\tfor (int b = 0; b < n - 1; b++) {\n\t\t\tint a = sa[isa[b] - 1];\n\t\t\twhile\
    \ (a + h < (int)s.size() && s[a + h] == s[b + h]) \n\t\t\t\th++;\n\t\t\tlcp[isa[b]\
    \ - 1] = h;\n\t\t\tif (h) h--;\n\t\t}\n\t}\n \n\tvoid gen_finish() {\n\t\tlcp.erase(lcp.begin());\n\
    \t\tsa.erase(sa.begin());\n\t\tfor (int i = 0; i < (int)isa.size(); i++) \n\t\t\
    \tisa[i]--;\n\t\tn--; \n\t\tisa.pop_back();\n\t\tspr.init(lcp);\n\t}\n\t\n\tint\
    \ get_lcp(int a, int b) {\n\t\tif (a == b) {\n\t\t\treturn (int)s.size() - a;\n\
    \t\t}\n\t\tint l = isa[a], r = isa[b]; \n\t\tif (l > r) swap(l, r);\n\t\treturn\
    \ spr.query(l, r - 1);\n\t}\n};"
  dependsOn:
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: false
  path: library/string/suffix-array-lcp.hpp
  requiredBy: []
  timestamp: '2021-08-16 13:21:48-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-suffixarray-lcp.test.cpp
documentation_of: library/string/suffix-array-lcp.hpp
layout: document
title: Suffix Array with Longest Common Prefix
---

## Suffix Array with Longest Common Prefix

### Assumptions
- We assume that we only use latin letters from `'a'` to `'z'`. This can be modified in `generate_suffix_array`. 
- We $0$-index things. 

### Functions
- `generate_suffix_array(s)`: Generates suffix array of string $s$ in $\mathcal O(n)$.
- `generate_lcp_array`: Generates longest common prefix array in $\mathcal O(n \log n)$, must be called after `generate_suffix_array`.
- `get_lcp(int a, int b)`: Gets the longest common prefix between the suffixes starting at $a$ and $b$, assuming lcp array is already generated.

### Variables
- `sa`: Stores the indices of the sorted suffixes.
- `isa`: Inverse of `sa`. 
- `lcp`: Longest commmon prefix between consecutive elements. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/strings%20(14)/Light/SuffixArrayLinear.h)