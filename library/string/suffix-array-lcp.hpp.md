---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
    title: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\n\r\ntemplate <class T> struct SparseTable {\r\n\tstd::vector<T>\
    \ v;\r\n\tstd::vector<std::vector<int>> jump;\r\n\r\n\tint level(int x) { return\
    \ 31 - __builtin_clz(x); }\r\n\r\n\tint comb(int a, int b) {\r\n\t\treturn v[a]\
    \ == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\r\n\t}\r\n\r\n\tvoid init(const\
    \ std::vector<T>& _v) {\r\n\t\tv = _v;\r\n\t\tjump = {std::vector<int>((int)v.size())};\r\
    \n\t\tiota(jump[0].begin(), jump[0].end(), 0);\r\n\t\tfor (int j = 1; (1 << j)\
    \ <= (int)v.size(); j++) {\r\n\t\t\tjump.push_back(std::vector<int>((int)v.size()\
    \ - (1 << j) + 1));\r\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\r\
    \n\t\t\t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint index(int l, int r) {\r\n\t\tassert(l <=\
    \ r);\r\n\t\tint d = level(r - l + 1);\r\n\t\treturn comb(jump[d][l], jump[d][r\
    \ - (1 << d) + 1]);\r\n\t}\r\n\r\n\tT query(int l, int r) {\r\n\t\treturn v[index(l,\
    \ r)];\r\n\t}\r\n};\n\r\nstruct SuffixArray {\r\n\tstring s;\r\n\tint n;\r\n\t\
    vector<int> sa, isa, lcp;\r\n\tSparseTable<int> spr;\r\n \r\n\tvector<int> suffix_array(vector<int>\
    \ st, int upper) {\r\n\t\tint sz = (int)st.size();\r\n\t\tif (sz == 0)\r\n\t\t\
    \treturn {};\r\n\t\tvector<int> res(sz);\r\n\t\tvector<bool> ls(sz);\r\n\t\tfor\
    \ (int i = sz - 2; i >= 0; i--) \r\n\t\t\tls[i] = st[i] == st[i + 1] ? ls[i +\
    \ 1] : st[i] < st[i + 1];\r\n\t\tvector<int> sum_l(upper), sum_s(upper);\r\n\t\
    \tfor (int i = 0; i < sz; i++)\r\n\t\t\t(ls[i] ? sum_l[st[i] + 1] : sum_s[st[i]])++;\r\
    \n\t\tfor (int i = 0; i < upper; i++) {\r\n\t\t\tif (i)\r\n\t\t\t\tsum_l[i] +=\
    \ sum_s[i - 1];\r\n\t\t\tsum_s[i] += sum_l[i];\r\n\t\t}\r\n\t\tauto induce = [&](const\
    \ vector<int>& lms) {\r\n\t\t\tfill(res.begin(), res.end(), -1);\r\n\t\t\tvector<int>\
    \ buf = sum_s;\r\n\t\t\tfor (int d : lms) \r\n\t\t\t\tif (d != sz)\r\n\t\t\t\t\
    \tres[buf[st[d]]++] = d;\r\n\t\t\tbuf = sum_l;\r\n\t\t\tres[buf[st[sz - 1]]++]\
    \ = sz - 1;\r\n\t\t\tfor (int i = 0; i < sz; i++) {\r\n\t\t\t\tint v = res[i]\
    \ - 1;\r\n\t\t\t\tif (v >= 0 && !ls[v])\r\n\t\t\t\t\tres[buf[st[v]]++] = v;\r\n\
    \t\t\t}\r\n\t\t\tbuf =  sum_l;\r\n\t\t\tfor (int i = sz - 1; i >= 0; i--) {\r\n\
    \t\t\t\tint v = res[i] - 1;\r\n\t\t\t\tif (v >= 0 && ls[v])\r\n\t\t\t\t\tres[--buf[st[v]\
    \ + 1]] = v;\r\n\t\t\t}\r\n\t\t};  \r\n\t\tvector<int> lms_map(sz + 1, -1), lms;\r\
    \n\t\tint m = 0;\r\n\t\tfor (int i = 1; i < sz; i++) \r\n\t\t\tif (!ls[i - 1]\
    \ && ls[i])\r\n\t\t\t\tlms_map[i] = m++, lms.push_back(i);\r\n\t\tinduce(lms);\r\
    \n\t\tvector<int> sorted_lms;\r\n\t\tfor (auto& v : res)\r\n\t\t\tif (lms_map[v]\
    \ != -1)\r\n\t\t\t\tsorted_lms.push_back(v);\r\n\t\tvector<int> rec_s(m);\r\n\t\
    \tint rec_upper = 0;\r\n\t\tfor (int i = 1; i < m; i++) {\r\n\t\t\tint l = sorted_lms[i\
    \ - 1];\r\n\t\t\tint r = sorted_lms[i];\r\n\t\t\tint end_l = lms_map[l] + 1 <\
    \ m ? lms[lms_map[l] + 1] : n;\r\n\t\t\tint end_r = lms_map[r] + 1 < m ? lms[lms_map[r]\
    \ + 1] : n;\r\n\t\t\tbool same = false;\r\n\t\t\tif (end_l - l == end_r - r) {\r\
    \n\t\t\t\tfor (; l < end_l && st[l] == st[r]; ++l, ++r);\r\n\t\t\t\tif (l != n\
    \ && st[l] == st[r])\r\n\t\t\t\t\tsame = true;\r\n\t\t\t}\r\n\t\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = (rec_upper += !same);\r\n\t\t}\r\n\t\tvector<int> rec_sa = suffix_array(rec_s,\
    \ rec_upper\r\n\t\t\t + 1);\r\n\t\tfor (int i = 0; i < m; i++)\r\n\t\t\tsorted_lms[i]\
    \ = lms[rec_sa[i]];\r\n\t\tinduce(sorted_lms);\r\n\t\treturn res;\r\n\t}\r\n\t\
    \r\n\tvoid generate_suffix_array(string _s) {\r\n\t\tn = (int)(s = _s).size()\
    \ + 1;\r\n\t\tvector<int> tmp;\r\n\t\tfor (int i = 0; i < (int)s.size(); ++i)\
    \ {\r\n\t\t\ttmp.push_back(s[i] - 'a');\r\n\t\t}\r\n\t\tsa = suffix_array(tmp,\
    \ 26);\r\n\t}\r\n\r\n\tvoid generate_lcp_array() {\r\n\t\tsa.insert(sa.begin(),\
    \ -1);\r\n\t\tisa.resize(sa.size());\r\n\t\tfor (int i = 1; i < (int)sa.size();\
    \ ++i) {\r\n\t\t\tisa[sa[i]] = i;\r\n\t\t}\t\r\n\t\tgen_lcp_array();\r\n\t\tgen_finish();\r\
    \n\t}\r\n \r\n\tvoid gen_lcp_array() {\r\n\t\tlcp = vector<int>(n - 1);\r\n\t\t\
    int h = 0;\r\n\t\tfor (int b = 0; b < n - 1; b++) {\r\n\t\t\tint a = sa[isa[b]\
    \ - 1];\r\n\t\t\twhile (a + h < (int)s.size() && s[a + h] == s[b + h]) \r\n\t\t\
    \t\th++;\r\n\t\t\tlcp[isa[b] - 1] = h;\r\n\t\t\tif (h) h--;\r\n\t\t}\r\n\t}\r\n\
    \ \r\n\tvoid gen_finish() {\r\n\t\tlcp.erase(lcp.begin());\r\n\t\tsa.erase(sa.begin());\r\
    \n\t\tfor (int i = 0; i < (int)isa.size(); i++) \r\n\t\t\tisa[i]--;\r\n\t\tn--;\
    \ \r\n\t\tisa.pop_back();\r\n\t\tspr.init(lcp);\r\n\t}\r\n\t\r\n\tint get_lcp(int\
    \ a, int b) {\r\n\t\tif (a == b) {\r\n\t\t\treturn (int)s.size() - a;\r\n\t\t\
    }\r\n\t\tint l = isa[a], r = isa[b]; \r\n\t\tif (l > r) swap(l, r);\r\n\t\treturn\
    \ spr.query(l, r - 1);\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\n#include \"../data-structures/1d-range-queries/sparse-table.hpp\"\
    \r\n\r\nstruct SuffixArray {\r\n\tstring s;\r\n\tint n;\r\n\tvector<int> sa, isa,\
    \ lcp;\r\n\tSparseTable<int> spr;\r\n \r\n\tvector<int> suffix_array(vector<int>\
    \ st, int upper) {\r\n\t\tint sz = (int)st.size();\r\n\t\tif (sz == 0)\r\n\t\t\
    \treturn {};\r\n\t\tvector<int> res(sz);\r\n\t\tvector<bool> ls(sz);\r\n\t\tfor\
    \ (int i = sz - 2; i >= 0; i--) \r\n\t\t\tls[i] = st[i] == st[i + 1] ? ls[i +\
    \ 1] : st[i] < st[i + 1];\r\n\t\tvector<int> sum_l(upper), sum_s(upper);\r\n\t\
    \tfor (int i = 0; i < sz; i++)\r\n\t\t\t(ls[i] ? sum_l[st[i] + 1] : sum_s[st[i]])++;\r\
    \n\t\tfor (int i = 0; i < upper; i++) {\r\n\t\t\tif (i)\r\n\t\t\t\tsum_l[i] +=\
    \ sum_s[i - 1];\r\n\t\t\tsum_s[i] += sum_l[i];\r\n\t\t}\r\n\t\tauto induce = [&](const\
    \ vector<int>& lms) {\r\n\t\t\tfill(res.begin(), res.end(), -1);\r\n\t\t\tvector<int>\
    \ buf = sum_s;\r\n\t\t\tfor (int d : lms) \r\n\t\t\t\tif (d != sz)\r\n\t\t\t\t\
    \tres[buf[st[d]]++] = d;\r\n\t\t\tbuf = sum_l;\r\n\t\t\tres[buf[st[sz - 1]]++]\
    \ = sz - 1;\r\n\t\t\tfor (int i = 0; i < sz; i++) {\r\n\t\t\t\tint v = res[i]\
    \ - 1;\r\n\t\t\t\tif (v >= 0 && !ls[v])\r\n\t\t\t\t\tres[buf[st[v]]++] = v;\r\n\
    \t\t\t}\r\n\t\t\tbuf =  sum_l;\r\n\t\t\tfor (int i = sz - 1; i >= 0; i--) {\r\n\
    \t\t\t\tint v = res[i] - 1;\r\n\t\t\t\tif (v >= 0 && ls[v])\r\n\t\t\t\t\tres[--buf[st[v]\
    \ + 1]] = v;\r\n\t\t\t}\r\n\t\t};  \r\n\t\tvector<int> lms_map(sz + 1, -1), lms;\r\
    \n\t\tint m = 0;\r\n\t\tfor (int i = 1; i < sz; i++) \r\n\t\t\tif (!ls[i - 1]\
    \ && ls[i])\r\n\t\t\t\tlms_map[i] = m++, lms.push_back(i);\r\n\t\tinduce(lms);\r\
    \n\t\tvector<int> sorted_lms;\r\n\t\tfor (auto& v : res)\r\n\t\t\tif (lms_map[v]\
    \ != -1)\r\n\t\t\t\tsorted_lms.push_back(v);\r\n\t\tvector<int> rec_s(m);\r\n\t\
    \tint rec_upper = 0;\r\n\t\tfor (int i = 1; i < m; i++) {\r\n\t\t\tint l = sorted_lms[i\
    \ - 1];\r\n\t\t\tint r = sorted_lms[i];\r\n\t\t\tint end_l = lms_map[l] + 1 <\
    \ m ? lms[lms_map[l] + 1] : n;\r\n\t\t\tint end_r = lms_map[r] + 1 < m ? lms[lms_map[r]\
    \ + 1] : n;\r\n\t\t\tbool same = false;\r\n\t\t\tif (end_l - l == end_r - r) {\r\
    \n\t\t\t\tfor (; l < end_l && st[l] == st[r]; ++l, ++r);\r\n\t\t\t\tif (l != n\
    \ && st[l] == st[r])\r\n\t\t\t\t\tsame = true;\r\n\t\t\t}\r\n\t\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = (rec_upper += !same);\r\n\t\t}\r\n\t\tvector<int> rec_sa = suffix_array(rec_s,\
    \ rec_upper\r\n\t\t\t + 1);\r\n\t\tfor (int i = 0; i < m; i++)\r\n\t\t\tsorted_lms[i]\
    \ = lms[rec_sa[i]];\r\n\t\tinduce(sorted_lms);\r\n\t\treturn res;\r\n\t}\r\n\t\
    \r\n\tvoid generate_suffix_array(string _s) {\r\n\t\tn = (int)(s = _s).size()\
    \ + 1;\r\n\t\tvector<int> tmp;\r\n\t\tfor (int i = 0; i < (int)s.size(); ++i)\
    \ {\r\n\t\t\ttmp.push_back(s[i] - 'a');\r\n\t\t}\r\n\t\tsa = suffix_array(tmp,\
    \ 26);\r\n\t}\r\n\r\n\tvoid generate_lcp_array() {\r\n\t\tsa.insert(sa.begin(),\
    \ -1);\r\n\t\tisa.resize(sa.size());\r\n\t\tfor (int i = 1; i < (int)sa.size();\
    \ ++i) {\r\n\t\t\tisa[sa[i]] = i;\r\n\t\t}\t\r\n\t\tgen_lcp_array();\r\n\t\tgen_finish();\r\
    \n\t}\r\n \r\n\tvoid gen_lcp_array() {\r\n\t\tlcp = vector<int>(n - 1);\r\n\t\t\
    int h = 0;\r\n\t\tfor (int b = 0; b < n - 1; b++) {\r\n\t\t\tint a = sa[isa[b]\
    \ - 1];\r\n\t\t\twhile (a + h < (int)s.size() && s[a + h] == s[b + h]) \r\n\t\t\
    \t\th++;\r\n\t\t\tlcp[isa[b] - 1] = h;\r\n\t\t\tif (h) h--;\r\n\t\t}\r\n\t}\r\n\
    \ \r\n\tvoid gen_finish() {\r\n\t\tlcp.erase(lcp.begin());\r\n\t\tsa.erase(sa.begin());\r\
    \n\t\tfor (int i = 0; i < (int)isa.size(); i++) \r\n\t\t\tisa[i]--;\r\n\t\tn--;\
    \ \r\n\t\tisa.pop_back();\r\n\t\tspr.init(lcp);\r\n\t}\r\n\t\r\n\tint get_lcp(int\
    \ a, int b) {\r\n\t\tif (a == b) {\r\n\t\t\treturn (int)s.size() - a;\r\n\t\t\
    }\r\n\t\tint l = isa[a], r = isa[b]; \r\n\t\tif (l > r) swap(l, r);\r\n\t\treturn\
    \ spr.query(l, r - 1);\r\n\t}\r\n};"
  dependsOn:
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: false
  path: library/string/suffix-array-lcp.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
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