---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/basic_number_theory.cpp\"\n#include\
    \ <bits/stdc++.h>\r\n\r\nnamespace BasicNumberTheory { \r\n\r\n// find solution\
    \ to a * x + b * y = gcd(a, b)\r\n// |a * x|, |b * y) <= lcm(a, b)\r\nstd::pair<long\
    \ long, long long> euclid(long long a, long long b) {\r\n    if (!b) \r\n    \
    \    return {1, 0};\r\n    std::pair<long long, long long> p = euclid(b, a % b);\r\
    \n    return {p.second, p.first - a / b * p.second};\r\n}\r\nlong long mod_inverse(long\
    \ long a, long long b) {\r\n    auto p = euclid(a, b);\r\n    assert(p.first *\
    \ a + p.second * b == 1); // gcd is 1\r\n    return p.first + (p.first < 0) *\
    \ b;\r\n}\r\nstd::pair<long long, long long> CRT(std::pair<long long, long long>\
    \ a, \r\n    std::pair<long long, long long> b) {\r\n    if (a.second < b.second)\r\
    \n        std::swap(a, b);\r\n    long long x, y;\r\n    std::tie(x, y) = euclid(a.second,\
    \ b.second);\r\n    long long g = a.second * x + b.second * y;\r\n    long long\
    \ l = a.second / g * b.second;\r\n    if ((b.first - a.first) % g)\r\n       \
    \ return {-1, -1}; // no solution\r\n    x = (b.first - a.first) % b.second *\
    \ x % b.second / g * a.second + a.first;\r\n    return {x + (x < 0) * l, l};\r\
    \n}\r\nlong long cdiv(long long a, long long b) { // a / b rounded up\r\n    return\
    \ a / b + ((a ^ b) > 0 && a % b);\r\n}\r\nlong long fdiv(long long a, long long\
    \ b) { // a / b rounded down\r\n    return a / b - ((a ^ b) < 0 && a % b);\r\n\
    }\r\n// minimum x such that there is a y such that l <= a * x + b * y <= r\r\n\
    long long between(long long a, long long b, long long l, long long r) {\r\n  \
    \  a %= b;\r\n    if (a == 0)\r\n        return l == 0 ? 0 : -1;\r\n    long long\
    \ k = cdiv(l, a);\r\n    if (a * k <= r)\r\n        return k;\r\n    long long\
    \ x = between(b, a, a - r % a, a - l % a);\r\n    return x == -1 ? x : cdiv(b\
    \ * x + l, a);\r\n}\r\n\r\n} // BasicNumberTheory\r\n\r\nint main() {\r\n    using\
    \ namespace std;\r\n    using namespace BasicNumberTheory;\r\n    int tt; cin\
    \ >> tt;\r\n    while (tt--) {\r\n        long long a, n, b, m;\r\n        cin\
    \ >> a >> n >> b >> m;\r\n        auto ans = CRT({a, n}, {b, m});\r\n        if\
    \ (ans.first == -1) \r\n            cout << \"no solution\\n\";\r\n        else\
    \ \r\n            cout << ans.first << \" \" << ans.second << '\\n';\r\n    }\
    \   \r\n    return 0;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\n\r\nnamespace BasicNumberTheory { \r\n\r\n//\
    \ find solution to a * x + b * y = gcd(a, b)\r\n// |a * x|, |b * y) <= lcm(a,\
    \ b)\r\nstd::pair<long long, long long> euclid(long long a, long long b) {\r\n\
    \    if (!b) \r\n        return {1, 0};\r\n    std::pair<long long, long long>\
    \ p = euclid(b, a % b);\r\n    return {p.second, p.first - a / b * p.second};\r\
    \n}\r\nlong long mod_inverse(long long a, long long b) {\r\n    auto p = euclid(a,\
    \ b);\r\n    assert(p.first * a + p.second * b == 1); // gcd is 1\r\n    return\
    \ p.first + (p.first < 0) * b;\r\n}\r\nstd::pair<long long, long long> CRT(std::pair<long\
    \ long, long long> a, \r\n    std::pair<long long, long long> b) {\r\n    if (a.second\
    \ < b.second)\r\n        std::swap(a, b);\r\n    long long x, y;\r\n    std::tie(x,\
    \ y) = euclid(a.second, b.second);\r\n    long long g = a.second * x + b.second\
    \ * y;\r\n    long long l = a.second / g * b.second;\r\n    if ((b.first - a.first)\
    \ % g)\r\n        return {-1, -1}; // no solution\r\n    x = (b.first - a.first)\
    \ % b.second * x % b.second / g * a.second + a.first;\r\n    return {x + (x <\
    \ 0) * l, l};\r\n}\r\nlong long cdiv(long long a, long long b) { // a / b rounded\
    \ up\r\n    return a / b + ((a ^ b) > 0 && a % b);\r\n}\r\nlong long fdiv(long\
    \ long a, long long b) { // a / b rounded down\r\n    return a / b - ((a ^ b)\
    \ < 0 && a % b);\r\n}\r\n// minimum x such that there is a y such that l <= a\
    \ * x + b * y <= r\r\nlong long between(long long a, long long b, long long l,\
    \ long long r) {\r\n    a %= b;\r\n    if (a == 0)\r\n        return l == 0 ?\
    \ 0 : -1;\r\n    long long k = cdiv(l, a);\r\n    if (a * k <= r)\r\n        return\
    \ k;\r\n    long long x = between(b, a, a - r % a, a - l % a);\r\n    return x\
    \ == -1 ? x : cdiv(b * x + l, a);\r\n}\r\n\r\n} // BasicNumberTheory\r\n\r\nint\
    \ main() {\r\n    using namespace std;\r\n    using namespace BasicNumberTheory;\r\
    \n    int tt; cin >> tt;\r\n    while (tt--) {\r\n        long long a, n, b, m;\r\
    \n        cin >> a >> n >> b >> m;\r\n        auto ans = CRT({a, n}, {b, m});\r\
    \n        if (ans.first == -1) \r\n            cout << \"no solution\\n\";\r\n\
    \        else \r\n            cout << ans.first << \" \" << ans.second << '\\\
    n';\r\n    }   \r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/basic_number_theory.cpp
  requiredBy: []
  timestamp: '2020-12-02 23:09:14-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/basic_number_theory.cpp
layout: document
redirect_from:
- /library/library/number-theory/basic_number_theory.cpp
- /library/library/number-theory/basic_number_theory.cpp.html
title: library/number-theory/basic_number_theory.cpp
---
