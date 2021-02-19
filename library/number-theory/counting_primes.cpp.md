---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/counting_primes.cpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <class T> struct FenwickTree {\n    std::vector<T> fwt;\n    int n;\n\
    \n    void init(int n_) {\n        n = n_;\n        fwt.resize(n);\n    }\n\n\
    \    void init(std::vector<T>& a) {\n        n = (int)a.size();\n        a.assign(n,\
    \ 0);\n        for (int i = 0; i < (int)a.size(); i++) {\n            add(i, a[i]);\n\
    \        }\n    }\n\n    T sum(int r) {\n        T ret = 0;\n        for (; r\
    \ >= 0; r = (r & (r + 1)) - 1) \n            ret += fwt[r];\n        return ret;\n\
    \    }\n\n    T query(int l, int r) {\n        return sum(r) - sum(l - 1);\n \
    \   }\n    \n    void add(int idx, T delta) {\n        for (; idx < n; idx = idx\
    \ | (idx + 1)) \n            fwt[idx] += delta;\n    }\n};\n\nconst int RL = 1010101;\n\
    const int CL = 10101;\n\nstd::bitset<RL + 1> isp;\nstd::vector<int> ps, cs;\n\n\
    void init(int c) {\n    ps.clear(); cs.clear();\n    isp[0] = isp[1] = 1;\n  \
    \  for (int p = 2; p * p <= RL; p++) \n        if (!isp[p]) \n            for\
    \ (int q = p * p; q <= RL; q += p) \n                isp[q] = 1;\n    for (int\
    \ i = 2; i <= RL; i++) {\n        if (!isp[i]) {\n            ps.push_back(i);\n\
    \            if (i <= c) cs.push_back(i);\n        }\n    }\n}\n\nlong long phi(long\
    \ long x, long long a, long long cnt) {\n    long long res = 0;\n    std::vector<int>\
    \ mu(a + 1, 1), minp(a + 1, a);\n    for (int i = 1; i <= a; i++) {\n        if\
    \ (!isp[i]) {\n            for (long long j = i; j <= a; j += i) {\n         \
    \       mu[j] *= -1;\n                minp[j] = std::min(minp[j], i);\n      \
    \      }\n            for (long long j = i * i, k = j; k <= a; k += j) \n    \
    \            mu[k] = 0;\n        }\n        res += mu[i] * (x / i);\n    }\n \
    \   std::vector<long long> sum(cnt);\n    for (long long lo = 1; lo < x / a; lo\
    \ += a) {\n        long long hi = std::min(lo + a, x / a);\n        FenwickTree<long\
    \ long> F;\n        F.init(a + 2);\n        std::bitset<CL> is_one;\n        for\
    \ (int b = 0; b < cnt; b++) {\n            int p = cs[b];\n            int mi\
    \ = std::max(x / p / hi, a / p);\n            int ma = std::min(x / p / lo, a);\n\
    \            if (p < ma) \n                for (int m = ma; m > mi; m--) \n  \
    \                  if (mu[m] != 0 && minp[m] > p) \n                        res\
    \ -= mu[m] * (sum[b] + x / p / m - lo + 1 - F.sum(x / p / m - lo));          \
    \  \n            sum[b] += a - F.sum(a - 1);\n            for (int q = (p - lo\
    \ % p) % p; q < a; q += p) {\n                if (!is_one[q]) {\n            \
    \        F.add(q, 1);\n                    is_one[q] = 1;\n                }\n\
    \            }\n        }\n    }\n    return res;\n}\n\nlong long count_primes(long\
    \ long x) {\n    int r = sqrt(x);\n    int c = cbrt(x);\n    init(c);\n    if\
    \ (x <= RL) \n        return upper_bound(ps.begin(), ps.end(), x) - ps.begin();\n\
    \    long long a = upper_bound(ps.begin(), ps.end(), c) - ps.begin();\n    long\
    \ long b = upper_bound(ps.begin(), ps.end(), r) - ps.begin();\n    long long res\
    \ = phi(x, c, a) + (b + a - 2) * (b - a + 1) / 2;\n    int idx = b - 1;\n    for\
    \ (int s = r; s <= x && idx >= a; s += c) {\n        std::vector<long long> cur(c\
    \ + 1);\n        std::bitset<CL> val;\n        cur[0] = b;\n        for (int i\
    \ = 0; i < CL; i++) val[i] = 1;\n        for (int p : cs) \n            for (int\
    \ q = (p - s % p) % p; q <= c; q += p) \n                val[q] = 0;\n       \
    \ for (int i = 1; i <= c; i++) cur[i] = cur[i - 1] + val[i];\n            b =\
    \ cur[c];\n        while (s <= x / ps[idx] && x / ps[idx] < s + c && idx >= a)\
    \ {\n            res -= cur[x / ps[idx] - s];\n            idx--;\n        }\n\
    \    }\n    return res;\n}\n\nint main() {\n    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    long long n; cin >> n;\n    cout << count_primes(n) << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct FenwickTree {\n   \
    \ std::vector<T> fwt;\n    int n;\n\n    void init(int n_) {\n        n = n_;\n\
    \        fwt.resize(n);\n    }\n\n    void init(std::vector<T>& a) {\n       \
    \ n = (int)a.size();\n        a.assign(n, 0);\n        for (int i = 0; i < (int)a.size();\
    \ i++) {\n            add(i, a[i]);\n        }\n    }\n\n    T sum(int r) {\n\
    \        T ret = 0;\n        for (; r >= 0; r = (r & (r + 1)) - 1) \n        \
    \    ret += fwt[r];\n        return ret;\n    }\n\n    T query(int l, int r) {\n\
    \        return sum(r) - sum(l - 1);\n    }\n    \n    void add(int idx, T delta)\
    \ {\n        for (; idx < n; idx = idx | (idx + 1)) \n            fwt[idx] +=\
    \ delta;\n    }\n};\n\nconst int RL = 1010101;\nconst int CL = 10101;\n\nstd::bitset<RL\
    \ + 1> isp;\nstd::vector<int> ps, cs;\n\nvoid init(int c) {\n    ps.clear(); cs.clear();\n\
    \    isp[0] = isp[1] = 1;\n    for (int p = 2; p * p <= RL; p++) \n        if\
    \ (!isp[p]) \n            for (int q = p * p; q <= RL; q += p) \n            \
    \    isp[q] = 1;\n    for (int i = 2; i <= RL; i++) {\n        if (!isp[i]) {\n\
    \            ps.push_back(i);\n            if (i <= c) cs.push_back(i);\n    \
    \    }\n    }\n}\n\nlong long phi(long long x, long long a, long long cnt) {\n\
    \    long long res = 0;\n    std::vector<int> mu(a + 1, 1), minp(a + 1, a);\n\
    \    for (int i = 1; i <= a; i++) {\n        if (!isp[i]) {\n            for (long\
    \ long j = i; j <= a; j += i) {\n                mu[j] *= -1;\n              \
    \  minp[j] = std::min(minp[j], i);\n            }\n            for (long long\
    \ j = i * i, k = j; k <= a; k += j) \n                mu[k] = 0;\n        }\n\
    \        res += mu[i] * (x / i);\n    }\n    std::vector<long long> sum(cnt);\n\
    \    for (long long lo = 1; lo < x / a; lo += a) {\n        long long hi = std::min(lo\
    \ + a, x / a);\n        FenwickTree<long long> F;\n        F.init(a + 2);\n  \
    \      std::bitset<CL> is_one;\n        for (int b = 0; b < cnt; b++) {\n    \
    \        int p = cs[b];\n            int mi = std::max(x / p / hi, a / p);\n \
    \           int ma = std::min(x / p / lo, a);\n            if (p < ma) \n    \
    \            for (int m = ma; m > mi; m--) \n                    if (mu[m] !=\
    \ 0 && minp[m] > p) \n                        res -= mu[m] * (sum[b] + x / p /\
    \ m - lo + 1 - F.sum(x / p / m - lo));            \n            sum[b] += a -\
    \ F.sum(a - 1);\n            for (int q = (p - lo % p) % p; q < a; q += p) {\n\
    \                if (!is_one[q]) {\n                    F.add(q, 1);\n       \
    \             is_one[q] = 1;\n                }\n            }\n        }\n  \
    \  }\n    return res;\n}\n\nlong long count_primes(long long x) {\n    int r =\
    \ sqrt(x);\n    int c = cbrt(x);\n    init(c);\n    if (x <= RL) \n        return\
    \ upper_bound(ps.begin(), ps.end(), x) - ps.begin();\n    long long a = upper_bound(ps.begin(),\
    \ ps.end(), c) - ps.begin();\n    long long b = upper_bound(ps.begin(), ps.end(),\
    \ r) - ps.begin();\n    long long res = phi(x, c, a) + (b + a - 2) * (b - a +\
    \ 1) / 2;\n    int idx = b - 1;\n    for (int s = r; s <= x && idx >= a; s +=\
    \ c) {\n        std::vector<long long> cur(c + 1);\n        std::bitset<CL> val;\n\
    \        cur[0] = b;\n        for (int i = 0; i < CL; i++) val[i] = 1;\n     \
    \   for (int p : cs) \n            for (int q = (p - s % p) % p; q <= c; q +=\
    \ p) \n                val[q] = 0;\n        for (int i = 1; i <= c; i++) cur[i]\
    \ = cur[i - 1] + val[i];\n            b = cur[c];\n        while (s <= x / ps[idx]\
    \ && x / ps[idx] < s + c && idx >= a) {\n            res -= cur[x / ps[idx] -\
    \ s];\n            idx--;\n        }\n    }\n    return res;\n}\n\nint main()\
    \ {\n    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n    long long\
    \ n; cin >> n;\n    cout << count_primes(n) << '\\n';\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/counting_primes.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/counting_primes.cpp
layout: document
redirect_from:
- /library/library/number-theory/counting_primes.cpp
- /library/library/number-theory/counting_primes.cpp.html
title: library/number-theory/counting_primes.cpp
---
