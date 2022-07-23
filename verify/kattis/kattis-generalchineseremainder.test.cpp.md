---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/number-theory/basic-number-theory.hpp
    title: library/number-theory/basic-number-theory.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://open.kattis.com/problems/generalchineseremainder
    links:
    - https://open.kattis.com/problems/generalchineseremainder
  bundledCode: "#define PROBLEM \"https://open.kattis.com/problems/generalchineseremainder\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nnamespace BasicNumberTheory\
    \ { \r\n\r\n// find solution to a * x + b * y = gcd(a, b)\r\n// |a * x|, |b *\
    \ y| <= lcm(a, b)\r\nstd::pair<long long, long long> euclid(long long a, long\
    \ long b) {\r\n\tif (!b) \r\n\t\treturn {1, 0};\r\n\tstd::pair<long long, long\
    \ long> p = euclid(b, a % b);\r\n\treturn {p.second, p.first - a / b * p.second};\r\
    \n}\r\n\r\nlong long mod_inverse(long long a, long long b) {\r\n\tauto p = euclid(a,\
    \ b);\r\n\tassert(p.first * a + p.second * b == 1); // gcd is 1\r\n\treturn p.first\
    \ + (p.first < 0) * b;\r\n}\r\n\r\nstd::pair<long long, long long> CRT(std::pair<long\
    \ long, long long> a, \r\n\tstd::pair<long long, long long> b) {\r\n\tif (a.second\
    \ < b.second)\r\n\t\tstd::swap(a, b);\r\n\tlong long x, y;\r\n\tstd::tie(x, y)\
    \ = euclid(a.second, b.second);\r\n\tlong long g = a.second * x + b.second * y;\r\
    \n\tlong long l = a.second / g * b.second;\r\n\tif ((b.first - a.first) % g)\r\
    \n\t\treturn {-1, -1}; // no solution\r\n\tx = (b.first - a.first) % b.second\
    \ * x % b.second / g * a.second + a.first;\r\n\treturn {x + (x < 0) * l, l};\r\
    \n}\r\n\r\nlong long cdiv(long long a, long long b) { // a / b rounded up\r\n\t\
    return a / b + ((a ^ b) > 0 && a % b);\r\n}\r\n\r\nlong long fdiv(long long a,\
    \ long long b) { // a / b rounded down\r\n\treturn a / b - ((a ^ b) < 0 && a %\
    \ b);\r\n}\r\n\r\n// minimum x such that there is a y such that l <= a * x + b\
    \ * y <= r\r\nlong long between(long long a, long long b, long long l, long long\
    \ r) {\r\n\ta %= b;\r\n\tif (a == 0)\r\n\t\treturn l == 0 ? 0 : -1;\r\n\tlong\
    \ long k = cdiv(l, a);\r\n\tif (a * k <= r)\r\n\t\treturn k;\r\n\tlong long x\
    \ = between(b, a, a - r % a, a - l % a);\r\n\treturn x == -1 ? x : cdiv(b * x\
    \ + l, a);\r\n}\r\n\r\n// sum from i = 0 to i = n - 1 of floor(a * i + b / m),\
    \ works for positive and negative m, a, b\r\nlong long floor_sum(long long n,\
    \ long long m, long  long a, long long b) {\r\n\tif (m < 0) \r\n\t\ta *= -1, b\
    \ *= -1, m *= -1;\r\n\tlong long na = a % m;\r\n\tif (na < 0) na += m;\r\n\tlong\
    \ long nb = b % m;\r\n\tif (nb < 0) nb += m;\r\n\tlong long ans = 0;\r\n\tans\
    \ += n * (n - 1) / 2 * ((a - na) / m);\r\n\tans += n * ((b - nb) / m);\r\n\tstd::swap(a,\
    \ na);\r\n\tstd::swap(b, nb);\r\n\tlong long y_max = (a * n + b) / m;\r\n\tlong\
    \ long x_max = (y_max * m - b);\r\n\tif (y_max == 0) return ans;\r\n\tans += (n\
    \ - (x_max + a - 1) / a) * y_max;\r\n\tans += floor_sum(y_max, a, m, (a - x_max\
    \ % a) % a);\r\n\treturn ans;\r\n}\r\n\r\n} // BasicNumberTheory\n\r\nint main()\
    \ {\r\n\tusing namespace BasicNumberTheory;\r\n\tint tt; cin >> tt;\r\n\twhile\
    \ (tt--) {\r\n\t\tlong long a, n, b, m;\r\n\t\tcin >> a >> n >> b >> m;\r\n\t\t\
    auto ans = CRT({a, n}, {b, m});\r\n\t\tif (ans.first == -1) \r\n\t\t\tcout <<\
    \ \"no solution\\n\";\r\n\t\telse \r\n\t\t\tcout << ans.first << \" \" << ans.second\
    \ << '\\n';\r\n\t}   \r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/problems/generalchineseremainder\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/number-theory/basic-number-theory.hpp\"\r\n\r\nint main() {\r\n\t\
    using namespace BasicNumberTheory;\r\n\tint tt; cin >> tt;\r\n\twhile (tt--) {\r\
    \n\t\tlong long a, n, b, m;\r\n\t\tcin >> a >> n >> b >> m;\r\n\t\tauto ans =\
    \ CRT({a, n}, {b, m});\r\n\t\tif (ans.first == -1) \r\n\t\t\tcout << \"no solution\\\
    n\";\r\n\t\telse \r\n\t\t\tcout << ans.first << \" \" << ans.second << '\\n';\r\
    \n\t}   \r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/basic-number-theory.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-generalchineseremainder.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-generalchineseremainder.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-generalchineseremainder.test.cpp
- /verify/verify/kattis/kattis-generalchineseremainder.test.cpp.html
title: verify/kattis/kattis-generalchineseremainder.test.cpp
---
