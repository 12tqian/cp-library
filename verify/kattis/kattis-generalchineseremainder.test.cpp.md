---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nnamespace BasicNumberTheory { \n\n// find solution to a * x + b * y = gcd(a,\
    \ b)\n// |a * x|, |b * y| <= lcm(a, b)\nstd::pair<long long, long long> euclid(long\
    \ long a, long long b) {\n\tif (!b) \n\t\treturn {1, 0};\n\tstd::pair<long long,\
    \ long long> p = euclid(b, a % b);\n\treturn {p.second, p.first - a / b * p.second};\n\
    }\n\nlong long mod_inverse(long long a, long long b) {\n\tauto p = euclid(a, b);\n\
    \tassert(p.first * a + p.second * b == 1); // gcd is 1\n\treturn p.first + (p.first\
    \ < 0) * b;\n}\n\nstd::pair<long long, long long> CRT(std::pair<long long, long\
    \ long> a, \n\tstd::pair<long long, long long> b) {\n\tif (a.second < b.second)\n\
    \t\tstd::swap(a, b);\n\tlong long x, y;\n\tstd::tie(x, y) = euclid(a.second, b.second);\n\
    \tlong long g = a.second * x + b.second * y;\n\tlong long l = a.second / g * b.second;\n\
    \tif ((b.first - a.first) % g)\n\t\treturn {-1, -1}; // no solution\n\tx = (b.first\
    \ - a.first) % b.second * x % b.second / g * a.second + a.first;\n\treturn {x\
    \ + (x < 0) * l, l};\n}\n\nlong long cdiv(long long a, long long b) { // a / b\
    \ rounded up\n\treturn a / b + ((a ^ b) > 0 && a % b);\n}\n\nlong long fdiv(long\
    \ long a, long long b) { // a / b rounded down\n\treturn a / b - ((a ^ b) < 0\
    \ && a % b);\n}\n\n// minimum x such that there is a y such that l <= a * x +\
    \ b * y <= r\nlong long between(long long a, long long b, long long l, long long\
    \ r) {\n\ta %= b;\n\tif (a == 0)\n\t\treturn l == 0 ? 0 : -1;\n\tlong long k =\
    \ cdiv(l, a);\n\tif (a * k <= r)\n\t\treturn k;\n\tlong long x = between(b, a,\
    \ a - r % a, a - l % a);\n\treturn x == -1 ? x : cdiv(b * x + l, a);\n}\n\n//\
    \ sum from i = 0 to i = n - 1 of floor(a * i + b / m), works for positive and\
    \ negative m, a, b\nlong long floor_sum(long long n, long long m, long  long a,\
    \ long long b) {\n\tif (m < 0) \n\t\ta *= -1, b *= -1, m *= -1;\n\tlong long na\
    \ = a % m;\n\tif (na < 0) na += m;\n\tlong long nb = b % m;\n\tif (nb < 0) nb\
    \ += m;\n\tlong long ans = 0;\n\tans += n * (n - 1) / 2 * ((a - na) / m);\n\t\
    ans += n * ((b - nb) / m);\n\tstd::swap(a, na);\n\tstd::swap(b, nb);\n\tlong long\
    \ y_max = (a * n + b) / m;\n\tlong long x_max = (y_max * m - b);\n\tif (y_max\
    \ == 0) return ans;\n\tans += (n - (x_max + a - 1) / a) * y_max;\n\tans += floor_sum(y_max,\
    \ a, m, (a - x_max % a) % a);\n\treturn ans;\n}\n\n} // BasicNumberTheory\n\n\
    int main() {\n\tusing namespace BasicNumberTheory;\n\tint tt; cin >> tt;\n\twhile\
    \ (tt--) {\n\t\tlong long a, n, b, m;\n\t\tcin >> a >> n >> b >> m;\n\t\tauto\
    \ ans = CRT({a, n}, {b, m});\n\t\tif (ans.first == -1) \n\t\t\tcout << \"no solution\\\
    n\";\n\t\telse \n\t\t\tcout << ans.first << \" \" << ans.second << '\\n';\n\t\
    }   \n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/problems/generalchineseremainder\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/number-theory/basic-number-theory.hpp\"\
    \n\nint main() {\n\tusing namespace BasicNumberTheory;\n\tint tt; cin >> tt;\n\
    \twhile (tt--) {\n\t\tlong long a, n, b, m;\n\t\tcin >> a >> n >> b >> m;\n\t\t\
    auto ans = CRT({a, n}, {b, m});\n\t\tif (ans.first == -1) \n\t\t\tcout << \"no\
    \ solution\\n\";\n\t\telse \n\t\t\tcout << ans.first << \" \" << ans.second <<\
    \ '\\n';\n\t}   \n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/basic-number-theory.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-generalchineseremainder.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-generalchineseremainder.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-generalchineseremainder.test.cpp
- /verify/verify/kattis/kattis-generalchineseremainder.test.cpp.html
title: verify/kattis/kattis-generalchineseremainder.test.cpp
---