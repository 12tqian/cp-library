---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/suffix-array-linear.test.cpp
    title: test/suffix-array-linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nstd::vector<int> suffix_array(std::vector<int> s, int upper) {\n\
    \tint n = (int)s.size();\n\tif (n == 0)\n\t\treturn {};\n\tstd::vector<int> sa(n);\n\
    \tstd::vector<bool> ls(n);\n\tfor (int i = n - 2; i >= 0; i--) \n\t\tls[i] = s[i]\
    \ == s[i + 1] ? ls[i + 1] : s[i] < s[i + 1];\n\tstd::vector<int> sum_l(upper),\
    \ sum_s(upper);\n\tfor (int i = 0; i < n; i++)\n\t\t(ls[i] ? sum_l[s[i] + 1] :\
    \ sum_s[s[i]])++;\n\tfor (int i = 0; i < upper; i++) {\n\t\tif (i)\n\t\t\tsum_l[i]\
    \ += sum_s[i - 1];\n\t\tsum_s[i] += sum_l[i];\n\t}\n\tauto induce = [&](const\
    \ std::vector<int> &lms) {\n\t\tfill(sa.begin(), sa.end(), -1);\n\t\tstd::vector<int>\
    \ buf = sum_s;\n\t\tfor (int d : lms) \n\t\t\tif (d != n)\n\t\t\t\tsa[buf[s[d]]++]\
    \ = d;\n\t\tbuf = sum_l;\n\t\tsa[buf[s[n - 1]]++] = n - 1;\n\t\tfor (int i = 0;\
    \ i < n; i++) {\n\t\t\tint v = sa[i] - 1;\n\t\t\tif (v >= 0 && !ls[v])\n\t\t\t\
    \tsa[buf[s[v]]++] = v;\n\t\t}\n\t\tbuf =  sum_l;\n\t\tfor (int i = n - 1; i >=\
    \ 0; i--) {\n\t\t\tint v = sa[i] - 1;\n\t\t\tif (v >= 0 && ls[v])\n\t\t\t\tsa[--buf[s[v]\
    \ + 1]] = v;\n\t\t}\n\t};  \n\tstd::vector<int> lms_map(n + 1, -1), lms;\n\tint\
    \ m = 0;\n\tfor (int i = 1; i < n; i++) \n\t\tif (!ls[i - 1] && ls[i])\n\t\t\t\
    lms_map[i] = m++, lms.push_back(i);\n\tinduce(lms);\n\tstd::vector<int> sorted_lms;\n\
    \tfor (auto &v : sa)\n\t\tif (lms_map[v] != -1)\n\t\t\tsorted_lms.push_back(v);\n\
    \tstd::vector<int> rec_s(m);\n\tint rec_upper = 0;\n\tfor (int i = 1; i < m; i++)\
    \ {\n\t\tint l = sorted_lms[i - 1];\n\t\tint r = sorted_lms[i];\n\t\tint end_l\
    \ = lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n;\n\t\tint end_r = lms_map[r]\
    \ + 1 < m ? lms[lms_map[r] + 1] : n;\n\t\tbool same = false;\n\t\tif (end_l -\
    \ l == end_r - r) {\n\t\t\tfor (; l < end_l && s[l] == s[r]; ++l, ++r);\n\t\t\t\
    if (l != n && s[l] == s[r])\n\t\t\t\tsame = true;\n\t\t}\n\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = (rec_upper += !same);\n\t}\n\tstd::vector<int> rec_sa = suffix_array(rec_s,\
    \ rec_upper\n\t\t + 1);\n\tfor (int i = 0; i < m; i++)\n\t\tsorted_lms[i] = lms[rec_sa[i]];\n\
    \tinduce(sorted_lms);\n\treturn sa;\n}\n"
  code: "#pragma once\n\nstd::vector<int> suffix_array(std::vector<int> s, int upper)\
    \ {\n\tint n = (int)s.size();\n\tif (n == 0)\n\t\treturn {};\n\tstd::vector<int>\
    \ sa(n);\n\tstd::vector<bool> ls(n);\n\tfor (int i = n - 2; i >= 0; i--) \n\t\t\
    ls[i] = s[i] == s[i + 1] ? ls[i + 1] : s[i] < s[i + 1];\n\tstd::vector<int> sum_l(upper),\
    \ sum_s(upper);\n\tfor (int i = 0; i < n; i++)\n\t\t(ls[i] ? sum_l[s[i] + 1] :\
    \ sum_s[s[i]])++;\n\tfor (int i = 0; i < upper; i++) {\n\t\tif (i)\n\t\t\tsum_l[i]\
    \ += sum_s[i - 1];\n\t\tsum_s[i] += sum_l[i];\n\t}\n\tauto induce = [&](const\
    \ std::vector<int> &lms) {\n\t\tfill(sa.begin(), sa.end(), -1);\n\t\tstd::vector<int>\
    \ buf = sum_s;\n\t\tfor (int d : lms) \n\t\t\tif (d != n)\n\t\t\t\tsa[buf[s[d]]++]\
    \ = d;\n\t\tbuf = sum_l;\n\t\tsa[buf[s[n - 1]]++] = n - 1;\n\t\tfor (int i = 0;\
    \ i < n; i++) {\n\t\t\tint v = sa[i] - 1;\n\t\t\tif (v >= 0 && !ls[v])\n\t\t\t\
    \tsa[buf[s[v]]++] = v;\n\t\t}\n\t\tbuf =  sum_l;\n\t\tfor (int i = n - 1; i >=\
    \ 0; i--) {\n\t\t\tint v = sa[i] - 1;\n\t\t\tif (v >= 0 && ls[v])\n\t\t\t\tsa[--buf[s[v]\
    \ + 1]] = v;\n\t\t}\n\t};  \n\tstd::vector<int> lms_map(n + 1, -1), lms;\n\tint\
    \ m = 0;\n\tfor (int i = 1; i < n; i++) \n\t\tif (!ls[i - 1] && ls[i])\n\t\t\t\
    lms_map[i] = m++, lms.push_back(i);\n\tinduce(lms);\n\tstd::vector<int> sorted_lms;\n\
    \tfor (auto &v : sa)\n\t\tif (lms_map[v] != -1)\n\t\t\tsorted_lms.push_back(v);\n\
    \tstd::vector<int> rec_s(m);\n\tint rec_upper = 0;\n\tfor (int i = 1; i < m; i++)\
    \ {\n\t\tint l = sorted_lms[i - 1];\n\t\tint r = sorted_lms[i];\n\t\tint end_l\
    \ = lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n;\n\t\tint end_r = lms_map[r]\
    \ + 1 < m ? lms[lms_map[r] + 1] : n;\n\t\tbool same = false;\n\t\tif (end_l -\
    \ l == end_r - r) {\n\t\t\tfor (; l < end_l && s[l] == s[r]; ++l, ++r);\n\t\t\t\
    if (l != n && s[l] == s[r])\n\t\t\t\tsame = true;\n\t\t}\n\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = (rec_upper += !same);\n\t}\n\tstd::vector<int> rec_sa = suffix_array(rec_s,\
    \ rec_upper\n\t\t + 1);\n\tfor (int i = 0; i < m; i++)\n\t\tsorted_lms[i] = lms[rec_sa[i]];\n\
    \tinduce(sorted_lms);\n\treturn sa;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/string/suffix-array-linear.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:46:46-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/suffix-array-linear.test.cpp
documentation_of: library/string/suffix-array-linear.hpp
layout: document
redirect_from:
- /library/library/string/suffix-array-linear.hpp
- /library/library/string/suffix-array-linear.hpp.html
title: library/string/suffix-array-linear.hpp
---
