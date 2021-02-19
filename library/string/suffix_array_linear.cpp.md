---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/string/suffix_array_linear.cpp\"\n#include <bits/stdc++.h>\n\
    \nstd::vector<int> suffix_array(std::vector<int> s, int upper) {\n    int n =\
    \ (int)s.size();\n    if (n == 0)\n        return {};\n    std::vector<int> sa(n);\n\
    \    std::vector<bool> ls(n);\n    for (int i = n - 2; i >= 0; i--) \n       \
    \ ls[i] = s[i] == s[i + 1] ? ls[i + 1] : s[i] < s[i + 1];\n    std::vector<int>\
    \ sum_l(upper), sum_s(upper);\n    for (int i = 0; i < n; i++)\n        (ls[i]\
    \ ? sum_l[s[i] + 1] : sum_s[s[i]])++;\n    for (int i = 0; i < upper; i++) {\n\
    \        if (i)\n            sum_l[i] += sum_s[i - 1];\n        sum_s[i] += sum_l[i];\n\
    \    }\n    auto induce = [&](const std::vector<int>& lms) {\n        fill(sa.begin(),\
    \ sa.end(), -1);\n        std::vector<int> buf = sum_s;\n        for (int d :\
    \ lms) \n            if (d != n)\n                sa[buf[s[d]]++] = d;\n     \
    \   buf = sum_l;\n        sa[buf[s[n - 1]]++] = n - 1;\n        for (int i = 0;\
    \ i < n; i++) {\n            int v = sa[i] - 1;\n            if (v >= 0 && !ls[v])\n\
    \                sa[buf[s[v]]++] = v;\n        }\n        buf =  sum_l;\n    \
    \    for (int i = n - 1; i >= 0; i--) {\n            int v = sa[i] - 1;\n    \
    \        if (v >= 0 && ls[v])\n                sa[--buf[s[v] + 1]] = v;\n    \
    \    }\n    };  \n    std::vector<int> lms_map(n + 1, -1), lms;\n    int m = 0;\n\
    \    for (int i = 1; i < n; i++) \n        if (!ls[i - 1] && ls[i])\n        \
    \    lms_map[i] = m++, lms.push_back(i);\n    induce(lms);\n    std::vector<int>\
    \ sorted_lms;\n    for (auto& v : sa)\n        if (lms_map[v] != -1)\n       \
    \     sorted_lms.push_back(v);\n    std::vector<int> rec_s(m);\n    int rec_upper\
    \ = 0;\n    for (int i = 1; i < m; i++) {\n        int l = sorted_lms[i - 1];\n\
    \        int r = sorted_lms[i];\n        int end_l = lms_map[l] + 1 < m ? lms[lms_map[l]\
    \ + 1] : n;\n        int end_r = lms_map[r] + 1 < m ? lms[lms_map[r] + 1] : n;\n\
    \        bool same = false;\n        if (end_l - l == end_r - r) {\n         \
    \   for (; l < end_l && s[l] == s[r]; ++l, ++r);\n            if (l != n && s[l]\
    \ == s[r])\n                same = true;\n        }\n        rec_s[lms_map[sorted_lms[i]]]\
    \ = (rec_upper += !same);\n    }\n    std::vector<int> rec_sa = suffix_array(rec_s,\
    \ rec_upper\n         + 1);\n    for (int i = 0; i < m; i++)\n        sorted_lms[i]\
    \ = lms[rec_sa[i]];\n    induce(sorted_lms);\n    return sa;\n}\n\nint main()\
    \ {\n    using namespace std;\n    ios_base::sync_with_stdio(0);\n    string s;\
    \ cin >> s;\n    std::vector<int> a((int)s.size());\n    for (int i = 0; i < (int)s.size();\
    \ i++)\n        a[i] = s[i] - 'a';\n    std::vector<int> res = suffix_array(a,\
    \ 26);\n    for (int i = 0; i < (int)s.size(); i++)\n        cout << res[i] <<\
    \ \" \";\n    cout << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nstd::vector<int> suffix_array(std::vector<int>\
    \ s, int upper) {\n    int n = (int)s.size();\n    if (n == 0)\n        return\
    \ {};\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int\
    \ i = n - 2; i >= 0; i--) \n        ls[i] = s[i] == s[i + 1] ? ls[i + 1] : s[i]\
    \ < s[i + 1];\n    std::vector<int> sum_l(upper), sum_s(upper);\n    for (int\
    \ i = 0; i < n; i++)\n        (ls[i] ? sum_l[s[i] + 1] : sum_s[s[i]])++;\n   \
    \ for (int i = 0; i < upper; i++) {\n        if (i)\n            sum_l[i] += sum_s[i\
    \ - 1];\n        sum_s[i] += sum_l[i];\n    }\n    auto induce = [&](const std::vector<int>&\
    \ lms) {\n        fill(sa.begin(), sa.end(), -1);\n        std::vector<int> buf\
    \ = sum_s;\n        for (int d : lms) \n            if (d != n)\n            \
    \    sa[buf[s[d]]++] = d;\n        buf = sum_l;\n        sa[buf[s[n - 1]]++] =\
    \ n - 1;\n        for (int i = 0; i < n; i++) {\n            int v = sa[i] - 1;\n\
    \            if (v >= 0 && !ls[v])\n                sa[buf[s[v]]++] = v;\n   \
    \     }\n        buf =  sum_l;\n        for (int i = n - 1; i >= 0; i--) {\n \
    \           int v = sa[i] - 1;\n            if (v >= 0 && ls[v])\n           \
    \     sa[--buf[s[v] + 1]] = v;\n        }\n    };  \n    std::vector<int> lms_map(n\
    \ + 1, -1), lms;\n    int m = 0;\n    for (int i = 1; i < n; i++) \n        if\
    \ (!ls[i - 1] && ls[i])\n            lms_map[i] = m++, lms.push_back(i);\n   \
    \ induce(lms);\n    std::vector<int> sorted_lms;\n    for (auto& v : sa)\n   \
    \     if (lms_map[v] != -1)\n            sorted_lms.push_back(v);\n    std::vector<int>\
    \ rec_s(m);\n    int rec_upper = 0;\n    for (int i = 1; i < m; i++) {\n     \
    \   int l = sorted_lms[i - 1];\n        int r = sorted_lms[i];\n        int end_l\
    \ = lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n;\n        int end_r = lms_map[r]\
    \ + 1 < m ? lms[lms_map[r] + 1] : n;\n        bool same = false;\n        if (end_l\
    \ - l == end_r - r) {\n            for (; l < end_l && s[l] == s[r]; ++l, ++r);\n\
    \            if (l != n && s[l] == s[r])\n                same = true;\n     \
    \   }\n        rec_s[lms_map[sorted_lms[i]]] = (rec_upper += !same);\n    }\n\
    \    std::vector<int> rec_sa = suffix_array(rec_s, rec_upper\n         + 1);\n\
    \    for (int i = 0; i < m; i++)\n        sorted_lms[i] = lms[rec_sa[i]];\n  \
    \  induce(sorted_lms);\n    return sa;\n}\n\nint main() {\n    using namespace\
    \ std;\n    ios_base::sync_with_stdio(0);\n    string s; cin >> s;\n    std::vector<int>\
    \ a((int)s.size());\n    for (int i = 0; i < (int)s.size(); i++)\n        a[i]\
    \ = s[i] - 'a';\n    std::vector<int> res = suffix_array(a, 26);\n    for (int\
    \ i = 0; i < (int)s.size(); i++)\n        cout << res[i] << \" \";\n    cout <<\
    \ '\\n';\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/string/suffix_array_linear.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/suffix_array_linear.cpp
layout: document
redirect_from:
- /library/library/string/suffix_array_linear.cpp
- /library/library/string/suffix_array_linear.cpp.html
title: library/string/suffix_array_linear.cpp
---
