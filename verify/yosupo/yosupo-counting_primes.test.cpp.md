---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n\ntemplate <class T> struct FenwickTree {\n\tstd::vector<T> fwt;\n\tint n;\n\
    \n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tfwt.assign(n, 0);\n\t}\n\n\tvoid init(std::vector<T>\
    \ &a) {\n\t\tn = (int)a.size();\n\t\tfwt.assign(n, 0);\n\t\tfor (int i = 0; i\
    \ < (int)a.size(); i++) {\n\t\t\tadd(i, a[i]);\n\t\t}\n\t}\n\n\tT sum(int r) {\n\
    \t\tT ret = 0;\n\t\tfor (; r >= 0; r = (r & (r + 1)) - 1) \n\t\t\tret += fwt[r];\n\
    \t\treturn ret;\n\t}\n\n\tT query(int l, int r) {\n\t\treturn sum(r) - sum(l -\
    \ 1);\n\t}\n\t\n\tvoid add(int idx, T delta) {\n\t\tfor (; idx < n; idx = idx\
    \ | (idx + 1)) \n\t\t\tfwt[idx] += delta;\n\t}\n};\n\nconst int RL = 1010101;\n\
    const int CL = 10101;\n\nstd::bitset<RL + 1> isp;\nstd::vector<int> ps, cs;\n\n\
    void init(int c) {\n\tps.clear(); cs.clear();\n\tisp[0] = isp[1] = 1;\n\tfor (int\
    \ p = 2; p * p <= RL; p++) \n\t\tif (!isp[p]) \n\t\t\tfor (int q = p * p; q <=\
    \ RL; q += p) \n\t\t\t\tisp[q] = 1;\n\tfor (int i = 2; i <= RL; i++) {\n\t\tif\
    \ (!isp[i]) {\n\t\t\tps.push_back(i);\n\t\t\tif (i <= c) cs.push_back(i);\n\t\t\
    }\n\t}\n}\n\nlong long phi(long long x, long long a, long long cnt) {\n\tlong\
    \ long res = 0;\n\tstd::vector<int> mu(a + 1, 1), minp(a + 1, a);\n\tfor (int\
    \ i = 1; i <= a; i++) {\n\t\tif (!isp[i]) {\n\t\t\tfor (long long j = i; j <=\
    \ a; j += i) {\n\t\t\t\tmu[j] *= -1;\n\t\t\t\tminp[j] = std::min(minp[j], i);\n\
    \t\t\t}\n\t\t\tfor (long long j = i * i, k = j; k <= a; k += j) \n\t\t\t\tmu[k]\
    \ = 0;\n\t\t}\n\t\tres += mu[i] * (x / i);\n\t}\n\tstd::vector<long long> sum(cnt);\n\
    \tfor (long long lo = 1; lo < x / a; lo += a) {\n\t\tlong long hi = std::min(lo\
    \ + a, x / a);\n\t\tFenwickTree<long long> F;\n\t\tF.init(a + 2);\n\t\tstd::bitset<CL>\
    \ is_one;\n\t\tfor (int b = 0; b < cnt; b++) {\n\t\t\tint p = cs[b];\n\t\t\tint\
    \ mi = std::max(x / p / hi, a / p);\n\t\t\tint ma = std::min(x / p / lo, a);\n\
    \t\t\tif (p < ma) \n\t\t\t\tfor (int m = ma; m > mi; m--) \n\t\t\t\t\tif (mu[m]\
    \ != 0 && minp[m] > p) \n\t\t\t\t\t\tres -= mu[m] * (sum[b] + x / p / m - lo +\
    \ 1 - F.sum(x / p / m - lo));            \n\t\t\tsum[b] += a - F.sum(a - 1);\n\
    \t\t\tfor (int q = (p - lo % p) % p; q < a; q += p) {\n\t\t\t\tif (!is_one[q])\
    \ {\n\t\t\t\t\tF.add(q, 1);\n\t\t\t\t\tis_one[q] = 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\treturn res;\n}\n\nlong long count_primes(long long x) {\n\tint r = sqrt(x);\n\
    \tint c = cbrt(x);\n\tinit(c);\n\tif (x <= RL) \n\t\treturn upper_bound(ps.begin(),\
    \ ps.end(), x) - ps.begin();\n\tlong long a = upper_bound(ps.begin(), ps.end(),\
    \ c) - ps.begin();\n\tlong long b = upper_bound(ps.begin(), ps.end(), r) - ps.begin();\n\
    \tlong long res = phi(x, c, a) + (b + a - 2) * (b - a + 1) / 2;\n\tint idx = b\
    \ - 1;\n\tfor (int s = r; s <= x && idx >= a; s += c) {\n\t\tstd::vector<long\
    \ long> cur(c + 1);\n\t\tstd::bitset<CL> val;\n\t\tcur[0] = b;\n\t\tfor (int i\
    \ = 0; i < CL; i++) val[i] = 1;\n\t\tfor (int p : cs) \n\t\t\tfor (int q = (p\
    \ - s % p) % p; q <= c; q += p) \n\t\t\t\tval[q] = 0;\n\t\tfor (int i = 1; i <=\
    \ c; i++) cur[i] = cur[i - 1] + val[i];\n\t\t\tb = cur[c];\n\t\twhile (s <= x\
    \ / ps[idx] && x / ps[idx] < s + c && idx >= a) {\n\t\t\tres -= cur[x / ps[idx]\
    \ - s];\n\t\t\tidx--;\n\t\t}\n\t}\n\treturn res;\n}\n\nint main() {\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tlong long n; cin >> n;\n\tcout << count_primes(n) << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/number-theory/counting-primes.hpp\"\
    \n\nint main() {\n\tcin.tie(0)->sync_with_stdio(0);\n\tlong long n; cin >> n;\n\
    \tcout << count_primes(n) << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/counting-primes.hpp
  - library/data-structures/1d-range-queries/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-counting_primes.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-counting_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-counting_primes.test.cpp
- /verify/verify/yosupo/yosupo-counting_primes.test.cpp.html
title: verify/yosupo/yosupo-counting_primes.test.cpp
---
