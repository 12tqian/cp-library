---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\numerical\\\\karatsuba.cpp\"\n#include <bits/stdc++.h>\r\
    \n\r\nnamespace Karatsuba {\r\n\r\nint size(int s) {\r\n    return s > 1 ? 32\
    \ - __builtin_clz(s - 1) : 0;\r\n}\r\ntemplate <class T> void karatsuba(T* a,\
    \ T* b, T* c, T* t, int n) {\r\n    int ca = 0, cb = 0;\r\n    for (int i = 0;\
    \ i < n; i++)\r\n        ca += (a[i] != 0), cb += (b[i] != 0);\r\n    if (std::min(ca,\
    \ cb) <= 1500 / n) { // not many multiplications\r\n        if (ca > cb) \r\n\
    \            std::swap(ca, cb);\r\n        for (int i = 0; i < n; i++) \r\n  \
    \          if (a[i] != 0)\r\n                for (int j = 0; j < n; j++)\r\n \
    \                   c[i + j] += a[i] * b[j];\r\n\r\n    } else {\r\n        int\
    \ h = n >> 1;\r\n        karatsuba(a, b, c, t, h); // a0 * b0\r\n        karatsuba(a\
    \ + h, b + h, c + n, t, h); // a1 * b1\r\n        for (int i = 0; i < h; i++)\r\
    \n            a[i] += a[i + h], b[i] += b[i + h];\r\n        karatsuba(a, b, t,\
    \ t + n, h); // (a0 + a1) * (b0 + b1)\r\n        for (int i = 0; i < h; i++)\r\
    \n            a[i] -= a[i + h], b[i] -= b[i + h];\r\n        for (int i = 0; i\
    \ < n; i++)\r\n            t[i] -= c[i] + c[i + n];\r\n        for (int i = 0;\
    \ i < n; i++)\r\n            c[i + h] += t[i], t[i] = 0;\r\n    }\r\n}\r\ntemplate\
    \ <class T> std::vector<T> convolution(std::vector<T> a, std::vector<T> b) {\r\
    \n    int sa = (int) a.size(), sb = (int) b.size();\r\n    if (!sa || !sb) \r\n\
    \        return {};\r\n    int n = (1 << size(std::max(sa, sb)));\r\n    a.resize(n);\r\
    \n    b.resize(n);\r\n    std::vector<T> c(2 * n), t(2 * n);\r\n    karatsuba(&a[0],\
    \ &b[0], &c[0], &t[0], n);\r\n    c.resize(sa + sb - 1);\r\n    return c;\r\n\
    }\r\n\r\n}\r\n\r\nint main() {\r\n    using namespace std;\r\n    using namespace\
    \ Karatsuba;\r\n    ios_base::sync_with_stdio(0);\r\n    int tt; \r\n    cin >>\
    \ tt;\r\n    while (tt--) {\r\n        int sa, sb;\r\n        cin >> sa;\r\n \
    \       vector<long long> a(sa + 1);\r\n        for (int i = 0; i < sa + 1; i++)\r\
    \n            cin >> a[i];\r\n        cin >> sb;\r\n        vector<long long>\
    \ b(sb + 1);\r\n        for (int i = 0; i < sb + 1; i++)\r\n            cin >>\
    \ b[i];\r\n        vector<long long> c = convolution<long long>(a, b);\r\n   \
    \     cout << (int) c.size() - 1 << '\\n';\r\n        for (int i = 0; i < (int)\
    \ c.size(); i++)\r\n            cout << c[i] << \" \";\r\n        cout << '\\\
    n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\n\r\nnamespace Karatsuba {\r\n\r\nint size(int\
    \ s) {\r\n    return s > 1 ? 32 - __builtin_clz(s - 1) : 0;\r\n}\r\ntemplate <class\
    \ T> void karatsuba(T* a, T* b, T* c, T* t, int n) {\r\n    int ca = 0, cb = 0;\r\
    \n    for (int i = 0; i < n; i++)\r\n        ca += (a[i] != 0), cb += (b[i] !=\
    \ 0);\r\n    if (std::min(ca, cb) <= 1500 / n) { // not many multiplications\r\
    \n        if (ca > cb) \r\n            std::swap(ca, cb);\r\n        for (int\
    \ i = 0; i < n; i++) \r\n            if (a[i] != 0)\r\n                for (int\
    \ j = 0; j < n; j++)\r\n                    c[i + j] += a[i] * b[j];\r\n\r\n \
    \   } else {\r\n        int h = n >> 1;\r\n        karatsuba(a, b, c, t, h); //\
    \ a0 * b0\r\n        karatsuba(a + h, b + h, c + n, t, h); // a1 * b1\r\n    \
    \    for (int i = 0; i < h; i++)\r\n            a[i] += a[i + h], b[i] += b[i\
    \ + h];\r\n        karatsuba(a, b, t, t + n, h); // (a0 + a1) * (b0 + b1)\r\n\
    \        for (int i = 0; i < h; i++)\r\n            a[i] -= a[i + h], b[i] -=\
    \ b[i + h];\r\n        for (int i = 0; i < n; i++)\r\n            t[i] -= c[i]\
    \ + c[i + n];\r\n        for (int i = 0; i < n; i++)\r\n            c[i + h] +=\
    \ t[i], t[i] = 0;\r\n    }\r\n}\r\ntemplate <class T> std::vector<T> convolution(std::vector<T>\
    \ a, std::vector<T> b) {\r\n    int sa = (int) a.size(), sb = (int) b.size();\r\
    \n    if (!sa || !sb) \r\n        return {};\r\n    int n = (1 << size(std::max(sa,\
    \ sb)));\r\n    a.resize(n);\r\n    b.resize(n);\r\n    std::vector<T> c(2 * n),\
    \ t(2 * n);\r\n    karatsuba(&a[0], &b[0], &c[0], &t[0], n);\r\n    c.resize(sa\
    \ + sb - 1);\r\n    return c;\r\n}\r\n\r\n}\r\n\r\nint main() {\r\n    using namespace\
    \ std;\r\n    using namespace Karatsuba;\r\n    ios_base::sync_with_stdio(0);\r\
    \n    int tt; \r\n    cin >> tt;\r\n    while (tt--) {\r\n        int sa, sb;\r\
    \n        cin >> sa;\r\n        vector<long long> a(sa + 1);\r\n        for (int\
    \ i = 0; i < sa + 1; i++)\r\n            cin >> a[i];\r\n        cin >> sb;\r\n\
    \        vector<long long> b(sb + 1);\r\n        for (int i = 0; i < sb + 1; i++)\r\
    \n            cin >> b[i];\r\n        vector<long long> c = convolution<long long>(a,\
    \ b);\r\n        cout << (int) c.size() - 1 << '\\n';\r\n        for (int i =\
    \ 0; i < (int) c.size(); i++)\r\n            cout << c[i] << \" \";\r\n      \
    \  cout << '\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library\numerical\karatsuba.cpp
  requiredBy: []
  timestamp: '2020-11-28 20:26:17-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\numerical\karatsuba.cpp
layout: document
redirect_from:
- /library\library\numerical\karatsuba.cpp
- /library\library\numerical\karatsuba.cpp.html
title: library\numerical\karatsuba.cpp
---
