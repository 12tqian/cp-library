---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/data-structures/1d-range-queries/fenwick-tree.hpp
    title: library/data-structures/1d-range-queries/fenwick-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/number-theory/counting-primes.hpp
    title: library/number-theory/counting-primes.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n\r\ntemplate <class T> struct\
    \ FenwickTree {\r\n\tstd::vector<T> fwt;\r\n\tint n;\r\n\r\n\tvoid init(int n_)\
    \ {\r\n\t\tn = n_;\r\n\t\tfwt.assign(n, 0);\r\n\t}\r\n\r\n\tvoid init(std::vector<T>&\
    \ a) {\r\n\t\tn = (int)a.size();\r\n\t\tfwt.assign(n, 0);\r\n\t\tfor (int i =\
    \ 0; i < (int)a.size(); i++) {\r\n\t\t\tadd(i, a[i]);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    T sum(int r) {\r\n\t\tT ret = 0;\r\n\t\tfor (; r >= 0; r = (r & (r + 1)) - 1)\
    \ \r\n\t\t\tret += fwt[r];\r\n\t\treturn ret;\r\n\t}\r\n\r\n\tT query(int l, int\
    \ r) {\r\n\t\treturn sum(r) - sum(l - 1);\r\n\t}\r\n\t\r\n\tvoid add(int idx,\
    \ T delta) {\r\n\t\tfor (; idx < n; idx = idx | (idx + 1)) \r\n\t\t\tfwt[idx]\
    \ += delta;\r\n\t}\r\n};\n\r\nconst int RL = 1010101;\r\nconst int CL = 10101;\r\
    \n\r\nstd::bitset<RL + 1> isp;\r\nstd::vector<int> ps, cs;\r\n\r\nvoid init(int\
    \ c) {\r\n\tps.clear(); cs.clear();\r\n\tisp[0] = isp[1] = 1;\r\n\tfor (int p\
    \ = 2; p * p <= RL; p++) \r\n\t\tif (!isp[p]) \r\n\t\t\tfor (int q = p * p; q\
    \ <= RL; q += p) \r\n\t\t\t\tisp[q] = 1;\r\n\tfor (int i = 2; i <= RL; i++) {\r\
    \n\t\tif (!isp[i]) {\r\n\t\t\tps.push_back(i);\r\n\t\t\tif (i <= c) cs.push_back(i);\r\
    \n\t\t}\r\n\t}\r\n}\r\n\r\nlong long phi(long long x, long long a, long long cnt)\
    \ {\r\n\tlong long res = 0;\r\n\tstd::vector<int> mu(a + 1, 1), minp(a + 1, a);\r\
    \n\tfor (int i = 1; i <= a; i++) {\r\n\t\tif (!isp[i]) {\r\n\t\t\tfor (long long\
    \ j = i; j <= a; j += i) {\r\n\t\t\t\tmu[j] *= -1;\r\n\t\t\t\tminp[j] = std::min(minp[j],\
    \ i);\r\n\t\t\t}\r\n\t\t\tfor (long long j = i * i, k = j; k <= a; k += j) \r\n\
    \t\t\t\tmu[k] = 0;\r\n\t\t}\r\n\t\tres += mu[i] * (x / i);\r\n\t}\r\n\tstd::vector<long\
    \ long> sum(cnt);\r\n\tfor (long long lo = 1; lo < x / a; lo += a) {\r\n\t\tlong\
    \ long hi = std::min(lo + a, x / a);\r\n\t\tFenwickTree<long long> F;\r\n\t\t\
    F.init(a + 2);\r\n\t\tstd::bitset<CL> is_one;\r\n\t\tfor (int b = 0; b < cnt;\
    \ b++) {\r\n\t\t\tint p = cs[b];\r\n\t\t\tint mi = std::max(x / p / hi, a / p);\r\
    \n\t\t\tint ma = std::min(x / p / lo, a);\r\n\t\t\tif (p < ma) \r\n\t\t\t\tfor\
    \ (int m = ma; m > mi; m--) \r\n\t\t\t\t\tif (mu[m] != 0 && minp[m] > p) \r\n\t\
    \t\t\t\t\tres -= mu[m] * (sum[b] + x / p / m - lo + 1 - F.sum(x / p / m - lo));\
    \            \r\n\t\t\tsum[b] += a - F.sum(a - 1);\r\n\t\t\tfor (int q = (p -\
    \ lo % p) % p; q < a; q += p) {\r\n\t\t\t\tif (!is_one[q]) {\r\n\t\t\t\t\tF.add(q,\
    \ 1);\r\n\t\t\t\t\tis_one[q] = 1;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\
    return res;\r\n}\r\n\r\nlong long count_primes(long long x) {\r\n\tint r = sqrt(x);\r\
    \n\tint c = cbrt(x);\r\n\tinit(c);\r\n\tif (x <= RL) \r\n\t\treturn upper_bound(ps.begin(),\
    \ ps.end(), x) - ps.begin();\r\n\tlong long a = upper_bound(ps.begin(), ps.end(),\
    \ c) - ps.begin();\r\n\tlong long b = upper_bound(ps.begin(), ps.end(), r) - ps.begin();\r\
    \n\tlong long res = phi(x, c, a) + (b + a - 2) * (b - a + 1) / 2;\r\n\tint idx\
    \ = b - 1;\r\n\tfor (int s = r; s <= x && idx >= a; s += c) {\r\n\t\tstd::vector<long\
    \ long> cur(c + 1);\r\n\t\tstd::bitset<CL> val;\r\n\t\tcur[0] = b;\r\n\t\tfor\
    \ (int i = 0; i < CL; i++) val[i] = 1;\r\n\t\tfor (int p : cs) \r\n\t\t\tfor (int\
    \ q = (p - s % p) % p; q <= c; q += p) \r\n\t\t\t\tval[q] = 0;\r\n\t\tfor (int\
    \ i = 1; i <= c; i++) cur[i] = cur[i - 1] + val[i];\r\n\t\t\tb = cur[c];\r\n\t\
    \twhile (s <= x / ps[idx] && x / ps[idx] < s + c && idx >= a) {\r\n\t\t\tres -=\
    \ cur[x / ps[idx] - s];\r\n\t\t\tidx--;\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\n\
    \r\nint main() {\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tlong long n; cin >>\
    \ n;\r\n\tcout << count_primes(n) << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\r\n\r\
    \n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/number-theory/counting-primes.hpp\"\
    \r\n\r\nint main() {\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tlong long n; cin\
    \ >> n;\r\n\tcout << count_primes(n) << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/counting-primes.hpp
  - library/data-structures/1d-range-queries/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-counting_primes.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-counting_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-counting_primes.test.cpp
- /verify/verify/yosupo/yosupo-counting_primes.test.cpp.html
title: verify/yosupo/yosupo-counting_primes.test.cpp
---
