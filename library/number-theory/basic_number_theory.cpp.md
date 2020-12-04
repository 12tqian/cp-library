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
    \ <bits/stdc++.h>\n\nnamespace BasicNumberTheory { \n\n// find solution to a *\
    \ x + b * y = gcd(a, b)\n// |a * x|, |b * y) <= lcm(a, b)\nstd::pair<long long,\
    \ long long> euclid(long long a, long long b) {\n    if (!b) \n        return\
    \ {1, 0};\n    std::pair<long long, long long> p = euclid(b, a % b);\n    return\
    \ {p.second, p.first - a / b * p.second};\n}\nlong long mod_inverse(long long\
    \ a, long long b) {\n    auto p = euclid(a, b);\n    assert(p.first * a + p.second\
    \ * b == 1); // gcd is 1\n    return p.first + (p.first < 0) * b;\n}\nstd::pair<long\
    \ long, long long> CRT(std::pair<long long, long long> a, \n    std::pair<long\
    \ long, long long> b) {\n    if (a.second < b.second)\n        std::swap(a, b);\n\
    \    long long x, y;\n    std::tie(x, y) = euclid(a.second, b.second);\n    long\
    \ long g = a.second * x + b.second * y;\n    long long l = a.second / g * b.second;\n\
    \    if ((b.first - a.first) % g)\n        return {-1, -1}; // no solution\n \
    \   x = (b.first - a.first) % b.second * x % b.second / g * a.second + a.first;\n\
    \    return {x + (x < 0) * l, l};\n}\nlong long cdiv(long long a, long long b)\
    \ { // a / b rounded up\n    return a / b + ((a ^ b) > 0 && a % b);\n}\nlong long\
    \ fdiv(long long a, long long b) { // a / b rounded down\n    return a / b - ((a\
    \ ^ b) < 0 && a % b);\n}\n// minimum x such that there is a y such that l <= a\
    \ * x + b * y <= r\nlong long between(long long a, long long b, long long l, long\
    \ long r) {\n    a %= b;\n    if (a == 0)\n        return l == 0 ? 0 : -1;\n \
    \   long long k = cdiv(l, a);\n    if (a * k <= r)\n        return k;\n    long\
    \ long x = between(b, a, a - r % a, a - l % a);\n    return x == -1 ? x : cdiv(b\
    \ * x + l, a);\n}\n\n} // BasicNumberTheory\n\nint main() {\n    using namespace\
    \ std;\n    using namespace BasicNumberTheory;\n    int tt; cin >> tt;\n    while\
    \ (tt--) {\n        long long a, n, b, m;\n        cin >> a >> n >> b >> m;\n\
    \        auto ans = CRT({a, n}, {b, m});\n        if (ans.first == -1) \n    \
    \        cout << \"no solution\\n\";\n        else \n            cout << ans.first\
    \ << \" \" << ans.second << '\\n';\n    }   \n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nnamespace BasicNumberTheory { \n\n// find solution\
    \ to a * x + b * y = gcd(a, b)\n// |a * x|, |b * y) <= lcm(a, b)\nstd::pair<long\
    \ long, long long> euclid(long long a, long long b) {\n    if (!b) \n        return\
    \ {1, 0};\n    std::pair<long long, long long> p = euclid(b, a % b);\n    return\
    \ {p.second, p.first - a / b * p.second};\n}\nlong long mod_inverse(long long\
    \ a, long long b) {\n    auto p = euclid(a, b);\n    assert(p.first * a + p.second\
    \ * b == 1); // gcd is 1\n    return p.first + (p.first < 0) * b;\n}\nstd::pair<long\
    \ long, long long> CRT(std::pair<long long, long long> a, \n    std::pair<long\
    \ long, long long> b) {\n    if (a.second < b.second)\n        std::swap(a, b);\n\
    \    long long x, y;\n    std::tie(x, y) = euclid(a.second, b.second);\n    long\
    \ long g = a.second * x + b.second * y;\n    long long l = a.second / g * b.second;\n\
    \    if ((b.first - a.first) % g)\n        return {-1, -1}; // no solution\n \
    \   x = (b.first - a.first) % b.second * x % b.second / g * a.second + a.first;\n\
    \    return {x + (x < 0) * l, l};\n}\nlong long cdiv(long long a, long long b)\
    \ { // a / b rounded up\n    return a / b + ((a ^ b) > 0 && a % b);\n}\nlong long\
    \ fdiv(long long a, long long b) { // a / b rounded down\n    return a / b - ((a\
    \ ^ b) < 0 && a % b);\n}\n// minimum x such that there is a y such that l <= a\
    \ * x + b * y <= r\nlong long between(long long a, long long b, long long l, long\
    \ long r) {\n    a %= b;\n    if (a == 0)\n        return l == 0 ? 0 : -1;\n \
    \   long long k = cdiv(l, a);\n    if (a * k <= r)\n        return k;\n    long\
    \ long x = between(b, a, a - r % a, a - l % a);\n    return x == -1 ? x : cdiv(b\
    \ * x + l, a);\n}\n\n} // BasicNumberTheory\n\nint main() {\n    using namespace\
    \ std;\n    using namespace BasicNumberTheory;\n    int tt; cin >> tt;\n    while\
    \ (tt--) {\n        long long a, n, b, m;\n        cin >> a >> n >> b >> m;\n\
    \        auto ans = CRT({a, n}, {b, m});\n        if (ans.first == -1) \n    \
    \        cout << \"no solution\\n\";\n        else \n            cout << ans.first\
    \ << \" \" << ans.second << '\\n';\n    }   \n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/basic_number_theory.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/basic_number_theory.cpp
layout: document
redirect_from:
- /library/library/number-theory/basic_number_theory.cpp
- /library/library/number-theory/basic_number_theory.cpp.html
title: library/number-theory/basic_number_theory.cpp
---
