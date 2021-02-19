---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/string/suffix_array.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * sa stores sorted suffixes\n * isa is inverse of sa\n * lcp is longest\
    \ common prefix between consecutive elements\n * Indexing has been fixed so that\
    \ everything is 0-indexed by the end\n */\n\ntemplate <class T> struct SparseTable\
    \ {\n    std::vector<T> v;\n    std::vector<std::vector<int>> jump;\n\n    int\
    \ level(int x) {\n        return 31 - __builtin_clz(x);\n    }\n\n    int comb(int\
    \ a, int b) {\n        return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a\
    \ : b);\n    }\n\n    void init(const std::vector<T>& _v) {\n        v = _v;\n\
    \        jump = {std::vector<int>((int)v.size())};\n        iota(jump[0].begin(),\
    \ jump[0].end(), 0);\n        for (int j = 1; (1 << j) <= (int)v.size(); j++)\
    \ {\n            jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));\n\
    \            for (int i = 0; i < (int)jump[j].size(); i++) {\n               \
    \ jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n      \
    \      }\n        }\n    }\n\n    int index(int l, int r) {\n        assert(l\
    \ <= r);\n        int d = level(r - l + 1);\n        return comb(jump[d][l], jump[d][r\
    \ - (1 << d) + 1]);\n    }\n\n    T query(int l, int r) {\n        return v[index(l,\
    \ r)];\n    }\n};\n\nstruct SuffixArray {\n    std::string s;\n    int n;\n  \
    \  std::vector<int> sa, isa, lcp;\n    SparseTable<int> S;\n\n    void init(std::string\
    \ _s) {\n        n = (int)(s = _s).size() + 1;\n        gen_suffix_array();\n\
    \        gen_lcp_array();\n        gen_finish();\n    }\n\n    void gen_suffix_array()\
    \ {\n        sa = isa = std::vector<int>(n);\n        sa[0] = n - 1;\n       \
    \ iota(1 + sa.begin(), sa.end(), 0);\n        sort(1 + sa.begin(), sa.end(), [&](int\
    \ a, int b) {\n            return s[a] < s[b];\n        });\n        for (int\
    \ i = 1; i < n; i++) {\n            int a = sa[i - 1], b = sa[i];\n          \
    \  isa[b] = i > 1 && s[a] == s[b] ? isa[a] : i;\n        }\n        for (int len\
    \ = 1; len < n; len *= 2) {\n            std::vector<int> ss(sa), is(isa), pos(n);\n\
    \            iota(pos.begin(), pos.end(), 0);\n            for (auto& t : ss)\
    \ {\n                int tt = t - len;\n                if (tt >= 0) \n      \
    \              sa[pos[isa[tt]]++] = tt;\n            }\n            for (int i\
    \ = 1; i < n; i++) {\n                int a = sa[i - 1], b = sa[i];\n        \
    \        isa[b] = is[a] == is[b] && is[a + len] == is[b + len] ? isa[a] : i;\n\
    \            }\n        }\n    }\n\n    void gen_lcp_array() {\n        lcp =\
    \ std::vector<int>(n - 1);\n        int h = 0;\n        for (int b = 0; b < n\
    \ - 1; b++) {\n            int a = sa[isa[b] - 1];\n            while (a + h <\
    \ (int)s.size() && s[a + h] == s[b + h]) \n                h++;\n            lcp[isa[b]\
    \ - 1] = h;\n            if (h) h--;\n        }\n    }\n\n    void gen_finish()\
    \ {\n        lcp.erase(lcp.begin());\n        sa.erase(sa.begin());\n        for\
    \ (int i = 0; i < (int)isa.size(); i++) \n            isa[i]--;\n        n--;\
    \ \n        isa.pop_back();\n        S.init(lcp);\n    }\n    \n    int get_lcp(int\
    \ a, int b) {\n        if (a == b) {\n            return (int)s.size() - a;\n\
    \        }\n        int l = isa[a], r = isa[b]; \n        if (l > r) std::swap(l,\
    \ r);\n        return S.query(l, r - 1);\n    }\n};\n \nint main() {\n    using\
    \ namespace std;\n    ios_base::sync_with_stdio(0);\n    string s; cin >> s;\n\
    \    int n = (int)s.size();\n    SuffixArray S;\n    S.init(s);\n    for (int\
    \ i = 0; i < n; i++)\n        cout << S.sa[i] << \" \";\n    cout << '\\n';\n\
    \    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * sa stores sorted suffixes\n * isa is\
    \ inverse of sa\n * lcp is longest common prefix between consecutive elements\n\
    \ * Indexing has been fixed so that everything is 0-indexed by the end\n */\n\n\
    template <class T> struct SparseTable {\n    std::vector<T> v;\n    std::vector<std::vector<int>>\
    \ jump;\n\n    int level(int x) {\n        return 31 - __builtin_clz(x);\n   \
    \ }\n\n    int comb(int a, int b) {\n        return v[a] == v[b] ? std::min(a,\
    \ b) : (v[a] < v[b] ? a : b);\n    }\n\n    void init(const std::vector<T>& _v)\
    \ {\n        v = _v;\n        jump = {std::vector<int>((int)v.size())};\n    \
    \    iota(jump[0].begin(), jump[0].end(), 0);\n        for (int j = 1; (1 << j)\
    \ <= (int)v.size(); j++) {\n            jump.push_back(std::vector<int>((int)v.size()\
    \ - (1 << j) + 1));\n            for (int i = 0; i < (int)jump[j].size(); i++)\
    \ {\n                jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j\
    \ - 1))]);\n            }\n        }\n    }\n\n    int index(int l, int r) {\n\
    \        assert(l <= r);\n        int d = level(r - l + 1);\n        return comb(jump[d][l],\
    \ jump[d][r - (1 << d) + 1]);\n    }\n\n    T query(int l, int r) {\n        return\
    \ v[index(l, r)];\n    }\n};\n\nstruct SuffixArray {\n    std::string s;\n   \
    \ int n;\n    std::vector<int> sa, isa, lcp;\n    SparseTable<int> S;\n\n    void\
    \ init(std::string _s) {\n        n = (int)(s = _s).size() + 1;\n        gen_suffix_array();\n\
    \        gen_lcp_array();\n        gen_finish();\n    }\n\n    void gen_suffix_array()\
    \ {\n        sa = isa = std::vector<int>(n);\n        sa[0] = n - 1;\n       \
    \ iota(1 + sa.begin(), sa.end(), 0);\n        sort(1 + sa.begin(), sa.end(), [&](int\
    \ a, int b) {\n            return s[a] < s[b];\n        });\n        for (int\
    \ i = 1; i < n; i++) {\n            int a = sa[i - 1], b = sa[i];\n          \
    \  isa[b] = i > 1 && s[a] == s[b] ? isa[a] : i;\n        }\n        for (int len\
    \ = 1; len < n; len *= 2) {\n            std::vector<int> ss(sa), is(isa), pos(n);\n\
    \            iota(pos.begin(), pos.end(), 0);\n            for (auto& t : ss)\
    \ {\n                int tt = t - len;\n                if (tt >= 0) \n      \
    \              sa[pos[isa[tt]]++] = tt;\n            }\n            for (int i\
    \ = 1; i < n; i++) {\n                int a = sa[i - 1], b = sa[i];\n        \
    \        isa[b] = is[a] == is[b] && is[a + len] == is[b + len] ? isa[a] : i;\n\
    \            }\n        }\n    }\n\n    void gen_lcp_array() {\n        lcp =\
    \ std::vector<int>(n - 1);\n        int h = 0;\n        for (int b = 0; b < n\
    \ - 1; b++) {\n            int a = sa[isa[b] - 1];\n            while (a + h <\
    \ (int)s.size() && s[a + h] == s[b + h]) \n                h++;\n            lcp[isa[b]\
    \ - 1] = h;\n            if (h) h--;\n        }\n    }\n\n    void gen_finish()\
    \ {\n        lcp.erase(lcp.begin());\n        sa.erase(sa.begin());\n        for\
    \ (int i = 0; i < (int)isa.size(); i++) \n            isa[i]--;\n        n--;\
    \ \n        isa.pop_back();\n        S.init(lcp);\n    }\n    \n    int get_lcp(int\
    \ a, int b) {\n        if (a == b) {\n            return (int)s.size() - a;\n\
    \        }\n        int l = isa[a], r = isa[b]; \n        if (l > r) std::swap(l,\
    \ r);\n        return S.query(l, r - 1);\n    }\n};\n \nint main() {\n    using\
    \ namespace std;\n    ios_base::sync_with_stdio(0);\n    string s; cin >> s;\n\
    \    int n = (int)s.size();\n    SuffixArray S;\n    S.init(s);\n    for (int\
    \ i = 0; i < n; i++)\n        cout << S.sa[i] << \" \";\n    cout << '\\n';\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/string/suffix_array.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/suffix_array.cpp
layout: document
redirect_from:
- /library/library/string/suffix_array.cpp
- /library/library/string/suffix_array.cpp.html
title: library/string/suffix_array.cpp
---
