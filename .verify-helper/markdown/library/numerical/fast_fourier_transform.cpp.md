---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\numerical\\\\fast_fourier_transform.cpp\"\n#include\
    \ <bits/stdc++.h>\r\n\r\ntemplate <int MOD, int RT> struct Mint {\r\n    static\
    \ const int mod = MOD;\r\n    static constexpr Mint rt() { return RT; } // primitive\
    \ root for FFT\r\n    int v; \r\n    explicit operator int() const { return v;\
    \ } // explicit -> don't silently convert to int\r\n    Mint() { v = 0; }\r\n\
    \    Mint(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if\
    \ (v < 0) v += MOD; }\r\n    friend bool operator == (const Mint& a, const Mint&\
    \ b) { return a.v == b.v; }\r\n    friend bool operator != (const Mint& a, const\
    \ Mint& b) { return !(a == b); }\r\n    friend bool operator < (const Mint& a,\
    \ const Mint& b) { return a.v < b.v; }\r\n    friend bool operator > (const Mint&\
    \ a, const Mint& b) { return a.v > b.v; }\r\n    friend bool operator <= (const\
    \ Mint& a, const Mint& b) { return a.v <= b.v; }\r\n    friend bool operator >=\
    \ (const Mint& a, const Mint& b) { return a.v >= b.v; }\r\n    friend std::istream&\
    \ operator >> (std::istream& in, Mint& a) { \r\n        long long x; std::cin\
    \ >> x; a = Mint(x); return in; }\r\n    friend std::ostream& operator << (std::ostream&\
    \ os, const Mint& a) { return os << a.v; }\r\n    Mint& operator += (const Mint&\
    \ m) { \r\n        if ((v += m.v) >= MOD) v -= MOD; \r\n        return *this;\
    \ }\r\n    Mint& operator -= (const Mint& m) { \r\n        if ((v -= m.v) < 0)\
    \ v += MOD; \r\n        return *this; }\r\n    Mint& operator *= (const Mint&\
    \ m) { \r\n        v = (long long ) v * m.v % MOD; return *this; }\r\n    Mint&\
    \ operator /= (const Mint& m) { return (*this) *= inv(m); }\r\n    friend Mint\
    \ pow(Mint a, long long p) {\r\n        Mint ans = 1; assert(p >= 0);\r\n    \
    \    for (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n        return ans; \r\n\
    \    }\r\n    friend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a,\
    \ MOD - 2); }\r\n    Mint operator - () const { return Mint(-v); }\r\n    Mint&\
    \ operator ++ () { return *this += 1; }\r\n    Mint& operator -- () { return *this\
    \ -= 1; }\r\n    friend Mint operator + (Mint a, const Mint& b) { return a +=\
    \ b; }\r\n    friend Mint operator - (Mint a, const Mint& b) { return a -= b;\
    \ }\r\n    friend Mint operator * (Mint a, const Mint& b) { return a *= b; }\r\
    \n    friend Mint operator / (Mint a, const Mint& b) { return a /= b; }\r\n};\r\
    \n\r\nnamespace FFT {\r\n\r\ntemplate <class T> void fft(std::vector<T>& A, bool\
    \ inv = 0) {\r\n    int n = (int) A.size();\r\n    assert((T::mod - 1) % n ==\
    \ 0);\r\n    std::vector<T> B(n);\r\n    for (int b = n / 2; b; b /= 2, A.swap(B))\
    \ {\r\n        T w = pow(T::rt(), (T::mod - 1) / n * b);\r\n        T m = 1;\r\
    \n        for (int i = 0; i < n; i += b * 2, m *= w)\r\n            for (int j\
    \ = 0; j < b; j++) {\r\n                T u = A[i + j];\r\n                T v\
    \ = A[i + j + b] * m;\r\n                B[i / 2 + j] = u + v;\r\n           \
    \     B[i / 2 + j + n / 2] = u - v;\r\n            }\r\n    }\r\n    if (inv)\
    \ {\r\n        std::reverse(1 + A.begin(), A.end());\r\n        T z = T(1) / T(n);\r\
    \n        for (auto & t : A) \r\n            t *= z;\r\n    }\r\n}\r\ntemplate\
    \ <class T> std::vector<T> multiply(std::vector<T> A, std::vector<T> B) {\r\n\
    \    int sa = (int) A.size();\r\n    int sb = (int) B.size();\r\n    if (!std::min(sa,\
    \ sb))\r\n        return {};\r\n    int s = sa + sb - 1;\r\n    int n = 1;\r\n\
    \    for (; n < s; n *= 2);\r\n    bool eq = A == B;\r\n    A.resize(n);\r\n \
    \   fft(A);\r\n    if (eq) \r\n        B = A;\r\n    else \r\n        B.resize(n),\
    \ fft(B);\r\n    for (int i = 0; i < n; i++)\r\n        A[i] *= B[i];\r\n    fft(A,\
    \ 1);\r\n    A.resize(s);\r\n    return A;\r\n}\r\ntemplate <class M, class T>\
    \ std::vector<M> multiply_mod(std::vector<T> x, std::vector<T> y) {\r\n    auto\
    \ convert = [](const std::vector<T>& v) {\r\n        std::vector<M> w((int) v.size());\r\
    \n        for (int i =  0; i < (int) v.size(); i++)\r\n            w[i] = (int)\
    \ v[i];\r\n        return w;\r\n    };\r\n    return multiply(convert(x), convert(y));\r\
    \n}\r\ntemplate <class T> std::vector<T> general_multiply(const std::vector<T>&\
    \ A, const std::vector<T>& B) { \r\n    // arbitrary modulus\r\n    using m0 =\
    \ Mint<(119 << 23) + 1, 62>; \r\n    using m1 = Mint<(5 << 25) + 1, 62>;\r\n \
    \   using m2 = Mint<(7 << 26) + 1, 62>;\r\n    auto c0 = multiply_mod<m0>(A, B);\r\
    \n    auto c1 = multiply_mod<m1>(A, B);\r\n    auto c2 = multiply_mod<m2>(A, B);\r\
    \n    int n = (int) c0.size();\r\n    std::vector<T> res(n);\r\n    m1 r01 = 1\
    \ / m1(m0::mod);\r\n    m2 r02 = 1 / m2(m0::mod);\r\n    m2 r12 = 1 / m2(m1::mod);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        int a = c0[i].v;\r\n        int\
    \ b = ((c1[i] - a) * r01).v;\r\n        int c = (((c2[i] - a) * r02 - b) * r12).v;\r\
    \n        res[i] = (T(c) * m1::mod + b) * m0::mod + a;\r\n    }\r\n    return\
    \ res;\r\n}\r\n\r\n}\r\n\r\nint main() {\r\n    using namespace std;\r\n    using\
    \ namespace FFT;\r\n    ios_base::sync_with_stdio(0);\r\n    int n, m; \r\n  \
    \  cin >> n >> m;\r\n    const int MOD = 1e9 + 7;\r\n    using num = Mint<MOD,\
    \ 5>;\r\n    vector<num> a(n), b(m);\r\n    for (int i = 0; i < n; i++)\r\n  \
    \      cin >> a[i];\r\n    for (int i = 0; i < m; i++)\r\n        cin >> b[i];\r\
    \n    vector<num> c = general_multiply(a, b);\r\n    for (int i = 0; i < (int)\
    \ c.size(); i++)\r\n        cout << c[i] << \" \";\r\n    cout << '\\n';\r\n}\n"
  code: "#include <bits/stdc++.h>\r\n\r\ntemplate <int MOD, int RT> struct Mint {\r\
    \n    static const int mod = MOD;\r\n    static constexpr Mint rt() { return RT;\
    \ } // primitive root for FFT\r\n    int v; \r\n    explicit operator int() const\
    \ { return v; } // explicit -> don't silently convert to int\r\n    Mint() { v\
    \ = 0; }\r\n    Mint(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v\
    \ % MOD); if (v < 0) v += MOD; }\r\n    friend bool operator == (const Mint& a,\
    \ const Mint& b) { return a.v == b.v; }\r\n    friend bool operator != (const\
    \ Mint& a, const Mint& b) { return !(a == b); }\r\n    friend bool operator <\
    \ (const Mint& a, const Mint& b) { return a.v < b.v; }\r\n    friend bool operator\
    \ > (const Mint& a, const Mint& b) { return a.v > b.v; }\r\n    friend bool operator\
    \ <= (const Mint& a, const Mint& b) { return a.v <= b.v; }\r\n    friend bool\
    \ operator >= (const Mint& a, const Mint& b) { return a.v >= b.v; }\r\n    friend\
    \ std::istream& operator >> (std::istream& in, Mint& a) { \r\n        long long\
    \ x; std::cin >> x; a = Mint(x); return in; }\r\n    friend std::ostream& operator\
    \ << (std::ostream& os, const Mint& a) { return os << a.v; }\r\n    Mint& operator\
    \ += (const Mint& m) { \r\n        if ((v += m.v) >= MOD) v -= MOD; \r\n     \
    \   return *this; }\r\n    Mint& operator -= (const Mint& m) { \r\n        if\
    \ ((v -= m.v) < 0) v += MOD; \r\n        return *this; }\r\n    Mint& operator\
    \ *= (const Mint& m) { \r\n        v = (long long ) v * m.v % MOD; return *this;\
    \ }\r\n    Mint& operator /= (const Mint& m) { return (*this) *= inv(m); }\r\n\
    \    friend Mint pow(Mint a, long long p) {\r\n        Mint ans = 1; assert(p\
    \ >= 0);\r\n        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n       \
    \ return ans; \r\n    }\r\n    friend Mint inv(const Mint& a) { assert(a.v !=\
    \ 0); return pow(a, MOD - 2); }\r\n    Mint operator - () const { return Mint(-v);\
    \ }\r\n    Mint& operator ++ () { return *this += 1; }\r\n    Mint& operator --\
    \ () { return *this -= 1; }\r\n    friend Mint operator + (Mint a, const Mint&\
    \ b) { return a += b; }\r\n    friend Mint operator - (Mint a, const Mint& b)\
    \ { return a -= b; }\r\n    friend Mint operator * (Mint a, const Mint& b) { return\
    \ a *= b; }\r\n    friend Mint operator / (Mint a, const Mint& b) { return a /=\
    \ b; }\r\n};\r\n\r\nnamespace FFT {\r\n\r\ntemplate <class T> void fft(std::vector<T>&\
    \ A, bool inv = 0) {\r\n    int n = (int) A.size();\r\n    assert((T::mod - 1)\
    \ % n == 0);\r\n    std::vector<T> B(n);\r\n    for (int b = n / 2; b; b /= 2,\
    \ A.swap(B)) {\r\n        T w = pow(T::rt(), (T::mod - 1) / n * b);\r\n      \
    \  T m = 1;\r\n        for (int i = 0; i < n; i += b * 2, m *= w)\r\n        \
    \    for (int j = 0; j < b; j++) {\r\n                T u = A[i + j];\r\n    \
    \            T v = A[i + j + b] * m;\r\n                B[i / 2 + j] = u + v;\r\
    \n                B[i / 2 + j + n / 2] = u - v;\r\n            }\r\n    }\r\n\
    \    if (inv) {\r\n        std::reverse(1 + A.begin(), A.end());\r\n        T\
    \ z = T(1) / T(n);\r\n        for (auto & t : A) \r\n            t *= z;\r\n \
    \   }\r\n}\r\ntemplate <class T> std::vector<T> multiply(std::vector<T> A, std::vector<T>\
    \ B) {\r\n    int sa = (int) A.size();\r\n    int sb = (int) B.size();\r\n   \
    \ if (!std::min(sa, sb))\r\n        return {};\r\n    int s = sa + sb - 1;\r\n\
    \    int n = 1;\r\n    for (; n < s; n *= 2);\r\n    bool eq = A == B;\r\n   \
    \ A.resize(n);\r\n    fft(A);\r\n    if (eq) \r\n        B = A;\r\n    else \r\
    \n        B.resize(n), fft(B);\r\n    for (int i = 0; i < n; i++)\r\n        A[i]\
    \ *= B[i];\r\n    fft(A, 1);\r\n    A.resize(s);\r\n    return A;\r\n}\r\ntemplate\
    \ <class M, class T> std::vector<M> multiply_mod(std::vector<T> x, std::vector<T>\
    \ y) {\r\n    auto convert = [](const std::vector<T>& v) {\r\n        std::vector<M>\
    \ w((int) v.size());\r\n        for (int i =  0; i < (int) v.size(); i++)\r\n\
    \            w[i] = (int) v[i];\r\n        return w;\r\n    };\r\n    return multiply(convert(x),\
    \ convert(y));\r\n}\r\ntemplate <class T> std::vector<T> general_multiply(const\
    \ std::vector<T>& A, const std::vector<T>& B) { \r\n    // arbitrary modulus\r\
    \n    using m0 = Mint<(119 << 23) + 1, 62>; \r\n    using m1 = Mint<(5 << 25)\
    \ + 1, 62>;\r\n    using m2 = Mint<(7 << 26) + 1, 62>;\r\n    auto c0 = multiply_mod<m0>(A,\
    \ B);\r\n    auto c1 = multiply_mod<m1>(A, B);\r\n    auto c2 = multiply_mod<m2>(A,\
    \ B);\r\n    int n = (int) c0.size();\r\n    std::vector<T> res(n);\r\n    m1\
    \ r01 = 1 / m1(m0::mod);\r\n    m2 r02 = 1 / m2(m0::mod);\r\n    m2 r12 = 1 /\
    \ m2(m1::mod);\r\n    for (int i = 0; i < n; i++) {\r\n        int a = c0[i].v;\r\
    \n        int b = ((c1[i] - a) * r01).v;\r\n        int c = (((c2[i] - a) * r02\
    \ - b) * r12).v;\r\n        res[i] = (T(c) * m1::mod + b) * m0::mod + a;\r\n \
    \   }\r\n    return res;\r\n}\r\n\r\n}\r\n\r\nint main() {\r\n    using namespace\
    \ std;\r\n    using namespace FFT;\r\n    ios_base::sync_with_stdio(0);\r\n  \
    \  int n, m; \r\n    cin >> n >> m;\r\n    const int MOD = 1e9 + 7;\r\n    using\
    \ num = Mint<MOD, 5>;\r\n    vector<num> a(n), b(m);\r\n    for (int i = 0; i\
    \ < n; i++)\r\n        cin >> a[i];\r\n    for (int i = 0; i < m; i++)\r\n   \
    \     cin >> b[i];\r\n    vector<num> c = general_multiply(a, b);\r\n    for (int\
    \ i = 0; i < (int) c.size(); i++)\r\n        cout << c[i] << \" \";\r\n    cout\
    \ << '\\n';\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library\numerical\fast_fourier_transform.cpp
  requiredBy: []
  timestamp: '2020-11-28 21:02:01-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\numerical\fast_fourier_transform.cpp
layout: document
redirect_from:
- /library\library\numerical\fast_fourier_transform.cpp
- /library\library\numerical\fast_fourier_transform.cpp.html
title: library\numerical\fast_fourier_transform.cpp
---
