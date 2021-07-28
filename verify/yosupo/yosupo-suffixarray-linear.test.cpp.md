---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/string/suffix-array-linear.hpp
    title: library/string/suffix-array-linear.hpp
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
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nstd::vector<int> suffix_array(std::vector<int> s, int upper) {\n\tint n = (int)s.size();\n\
    \tif (n == 0)\n\t\treturn {};\n\tstd::vector<int> sa(n);\n\tstd::vector<bool>\
    \ ls(n);\n\tfor (int i = n - 2; i >= 0; i--) \n\t\tls[i] = s[i] == s[i + 1] ?\
    \ ls[i + 1] : s[i] < s[i + 1];\n\tstd::vector<int> sum_l(upper), sum_s(upper);\n\
    \tfor (int i = 0; i < n; i++)\n\t\t(ls[i] ? sum_l[s[i] + 1] : sum_s[s[i]])++;\n\
    \tfor (int i = 0; i < upper; i++) {\n\t\tif (i)\n\t\t\tsum_l[i] += sum_s[i - 1];\n\
    \t\tsum_s[i] += sum_l[i];\n\t}\n\tauto induce = [&](const std::vector<int> &lms)\
    \ {\n\t\tfill(sa.begin(), sa.end(), -1);\n\t\tstd::vector<int> buf = sum_s;\n\t\
    \tfor (int d : lms) \n\t\t\tif (d != n)\n\t\t\t\tsa[buf[s[d]]++] = d;\n\t\tbuf\
    \ = sum_l;\n\t\tsa[buf[s[n - 1]]++] = n - 1;\n\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\tint v = sa[i] - 1;\n\t\t\tif (v >= 0 && !ls[v])\n\t\t\t\tsa[buf[s[v]]++]\
    \ = v;\n\t\t}\n\t\tbuf =  sum_l;\n\t\tfor (int i = n - 1; i >= 0; i--) {\n\t\t\
    \tint v = sa[i] - 1;\n\t\t\tif (v >= 0 && ls[v])\n\t\t\t\tsa[--buf[s[v] + 1]]\
    \ = v;\n\t\t}\n\t};  \n\tstd::vector<int> lms_map(n + 1, -1), lms;\n\tint m =\
    \ 0;\n\tfor (int i = 1; i < n; i++) \n\t\tif (!ls[i - 1] && ls[i])\n\t\t\tlms_map[i]\
    \ = m++, lms.push_back(i);\n\tinduce(lms);\n\tstd::vector<int> sorted_lms;\n\t\
    for (auto &v : sa)\n\t\tif (lms_map[v] != -1)\n\t\t\tsorted_lms.push_back(v);\n\
    \tstd::vector<int> rec_s(m);\n\tint rec_upper = 0;\n\tfor (int i = 1; i < m; i++)\
    \ {\n\t\tint l = sorted_lms[i - 1];\n\t\tint r = sorted_lms[i];\n\t\tint end_l\
    \ = lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n;\n\t\tint end_r = lms_map[r]\
    \ + 1 < m ? lms[lms_map[r] + 1] : n;\n\t\tbool same = false;\n\t\tif (end_l -\
    \ l == end_r - r) {\n\t\t\tfor (; l < end_l && s[l] == s[r]; ++l, ++r);\n\t\t\t\
    if (l != n && s[l] == s[r])\n\t\t\t\tsame = true;\n\t\t}\n\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = (rec_upper += !same);\n\t}\n\tstd::vector<int> rec_sa = suffix_array(rec_s,\
    \ rec_upper\n\t\t + 1);\n\tfor (int i = 0; i < m; i++)\n\t\tsorted_lms[i] = lms[rec_sa[i]];\n\
    \tinduce(sorted_lms);\n\treturn sa;\n}\n\nint main() {\n\tusing namespace std;\n\
    \tios_base::sync_with_stdio(0);\n\tstring s; cin >> s;\n\tstd::vector<int> a((int)s.size());\n\
    \tfor (int i = 0; i < (int)s.size(); i++)\n\t\ta[i] = s[i] - 'a';\n\tstd::vector<int>\
    \ res = suffix_array(a, 26);\n\tfor (int i = 0; i < (int)s.size(); i++)\n\t\t\
    cout << res[i] << \" \";\n\tcout << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/string/suffix-array-linear.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\t\
    string s; cin >> s;\n\tstd::vector<int> a((int)s.size());\n\tfor (int i = 0; i\
    \ < (int)s.size(); i++)\n\t\ta[i] = s[i] - 'a';\n\tstd::vector<int> res = suffix_array(a,\
    \ 26);\n\tfor (int i = 0; i < (int)s.size(); i++)\n\t\tcout << res[i] << \" \"\
    ;\n\tcout << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/string/suffix-array-linear.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-suffixarray-linear.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-suffixarray-linear.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-suffixarray-linear.test.cpp
- /verify/verify/yosupo/yosupo-suffixarray-linear.test.cpp.html
title: verify/yosupo/yosupo-suffixarray-linear.test.cpp
---
