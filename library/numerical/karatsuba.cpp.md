---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/karatsuba.cpp\"\n#include <bits/stdc++.h>\n\
    \nnamespace Karatsuba {\n\nint size(int s) {\n    return s > 1 ? 32 - __builtin_clz(s\
    \ - 1) : 0;\n}\n\ntemplate <class T> void karatsuba(T* a, T* b, T* c, T* t, int\
    \ n) {\n    int ca = 0, cb = 0;\n    for (int i = 0; i < n; i++)\n        ca +=\
    \ (a[i] != 0), cb += (b[i] != 0);\n    if (std::min(ca, cb) <= 1500 / n) { //\
    \ not many multiplications\n        if (ca > cb) \n            std::swap(ca, cb);\n\
    \        for (int i = 0; i < n; i++) \n            if (a[i] != 0)\n          \
    \      for (int j = 0; j < n; j++)\n                    c[i + j] += a[i] * b[j];\n\
    \n    } else {\n        int h = n >> 1;\n        karatsuba(a, b, c, t, h); //\
    \ a0 * b0\n        karatsuba(a + h, b + h, c + n, t, h); // a1 * b1\n        for\
    \ (int i = 0; i < h; i++)\n            a[i] += a[i + h], b[i] += b[i + h];\n \
    \       karatsuba(a, b, t, t + n, h); // (a0 + a1) * (b0 + b1)\n        for (int\
    \ i = 0; i < h; i++)\n            a[i] -= a[i + h], b[i] -= b[i + h];\n      \
    \  for (int i = 0; i < n; i++)\n            t[i] -= c[i] + c[i + n];\n       \
    \ for (int i = 0; i < n; i++)\n            c[i + h] += t[i], t[i] = 0;\n    }\n\
    }\n\ntemplate <class T> std::vector<T> convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    int sa = (int) a.size(), sb = (int) b.size();\n    if (!sa || !sb)\
    \ \n        return {};\n    int n = (1 << size(std::max(sa, sb)));\n    a.resize(n);\n\
    \    b.resize(n);\n    std::vector<T> c(2 * n), t(2 * n);\n    karatsuba(&a[0],\
    \ &b[0], &c[0], &t[0], n);\n    c.resize(sa + sb - 1);\n    return c;\n}\n\n}\n\
    \nint main() {\n    using namespace std;\n    using namespace Karatsuba;\n   \
    \ ios_base::sync_with_stdio(0);\n    int tt; \n    cin >> tt;\n    while (tt--)\
    \ {\n        int sa, sb;\n        cin >> sa;\n        vector<long long> a(sa +\
    \ 1);\n        for (int i = 0; i < sa + 1; i++)\n            cin >> a[i];\n  \
    \      cin >> sb;\n        vector<long long> b(sb + 1);\n        for (int i =\
    \ 0; i < sb + 1; i++)\n            cin >> b[i];\n        vector<long long> c =\
    \ convolution<long long>(a, b);\n        cout << (int) c.size() - 1 << '\\n';\n\
    \        for (int i = 0; i < (int) c.size(); i++)\n            cout << c[i] <<\
    \ \" \";\n        cout << '\\n';\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nnamespace Karatsuba {\n\nint size(int s) {\n\
    \    return s > 1 ? 32 - __builtin_clz(s - 1) : 0;\n}\n\ntemplate <class T> void\
    \ karatsuba(T* a, T* b, T* c, T* t, int n) {\n    int ca = 0, cb = 0;\n    for\
    \ (int i = 0; i < n; i++)\n        ca += (a[i] != 0), cb += (b[i] != 0);\n   \
    \ if (std::min(ca, cb) <= 1500 / n) { // not many multiplications\n        if\
    \ (ca > cb) \n            std::swap(ca, cb);\n        for (int i = 0; i < n; i++)\
    \ \n            if (a[i] != 0)\n                for (int j = 0; j < n; j++)\n\
    \                    c[i + j] += a[i] * b[j];\n\n    } else {\n        int h =\
    \ n >> 1;\n        karatsuba(a, b, c, t, h); // a0 * b0\n        karatsuba(a +\
    \ h, b + h, c + n, t, h); // a1 * b1\n        for (int i = 0; i < h; i++)\n  \
    \          a[i] += a[i + h], b[i] += b[i + h];\n        karatsuba(a, b, t, t +\
    \ n, h); // (a0 + a1) * (b0 + b1)\n        for (int i = 0; i < h; i++)\n     \
    \       a[i] -= a[i + h], b[i] -= b[i + h];\n        for (int i = 0; i < n; i++)\n\
    \            t[i] -= c[i] + c[i + n];\n        for (int i = 0; i < n; i++)\n \
    \           c[i + h] += t[i], t[i] = 0;\n    }\n}\n\ntemplate <class T> std::vector<T>\
    \ convolution(std::vector<T> a, std::vector<T> b) {\n    int sa = (int) a.size(),\
    \ sb = (int) b.size();\n    if (!sa || !sb) \n        return {};\n    int n =\
    \ (1 << size(std::max(sa, sb)));\n    a.resize(n);\n    b.resize(n);\n    std::vector<T>\
    \ c(2 * n), t(2 * n);\n    karatsuba(&a[0], &b[0], &c[0], &t[0], n);\n    c.resize(sa\
    \ + sb - 1);\n    return c;\n}\n\n}\n\nint main() {\n    using namespace std;\n\
    \    using namespace Karatsuba;\n    ios_base::sync_with_stdio(0);\n    int tt;\
    \ \n    cin >> tt;\n    while (tt--) {\n        int sa, sb;\n        cin >> sa;\n\
    \        vector<long long> a(sa + 1);\n        for (int i = 0; i < sa + 1; i++)\n\
    \            cin >> a[i];\n        cin >> sb;\n        vector<long long> b(sb\
    \ + 1);\n        for (int i = 0; i < sb + 1; i++)\n            cin >> b[i];\n\
    \        vector<long long> c = convolution<long long>(a, b);\n        cout <<\
    \ (int) c.size() - 1 << '\\n';\n        for (int i = 0; i < (int) c.size(); i++)\n\
    \            cout << c[i] << \" \";\n        cout << '\\n';\n    }\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/karatsuba.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/karatsuba.cpp
layout: document
redirect_from:
- /library/library/numerical/karatsuba.cpp
- /library/library/numerical/karatsuba.cpp.html
title: library/numerical/karatsuba.cpp
---
