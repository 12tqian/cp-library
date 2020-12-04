---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/fast_fourier_transform.cpp\"\n#include\
    \ <bits/stdc++.h>\n\ntemplate <int MOD, int RT> struct Mint {\n    static const\
    \ int mod = MOD;\n    static constexpr Mint rt() { return RT; } // primitive root\
    \ for FFT\n    int v; \n    explicit operator int() const { return v; } // explicit\
    \ -> don't silently convert to int\n    Mint() { v = 0; }\n    Mint(long long\
    \ _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD;\
    \ }\n    friend bool operator == (const Mint& a, const Mint& b) { return a.v ==\
    \ b.v; }\n    friend bool operator != (const Mint& a, const Mint& b) { return\
    \ !(a == b); }\n    friend bool operator < (const Mint& a, const Mint& b) { return\
    \ a.v < b.v; }\n    friend bool operator > (const Mint& a, const Mint& b) { return\
    \ a.v > b.v; }\n    friend bool operator <= (const Mint& a, const Mint& b) { return\
    \ a.v <= b.v; }\n    friend bool operator >= (const Mint& a, const Mint& b) {\
    \ return a.v >= b.v; }\n    friend std::istream& operator >> (std::istream& in,\
    \ Mint& a) { \n        long long x; std::cin >> x; a = Mint(x); return in; }\n\
    \    friend std::ostream& operator << (std::ostream& os, const Mint& a) { return\
    \ os << a.v; }\n    Mint& operator += (const Mint& m) { \n        if ((v += m.v)\
    \ >= MOD) v -= MOD; \n        return *this; }\n    Mint& operator -= (const Mint&\
    \ m) { \n        if ((v -= m.v) < 0) v += MOD; \n        return *this; }\n   \
    \ Mint& operator *= (const Mint& m) { \n        v = (long long ) v * m.v % MOD;\
    \ return *this; }\n    Mint& operator /= (const Mint& m) { return (*this) *= inv(m);\
    \ }\n    friend Mint pow(Mint a, long long p) {\n        Mint ans = 1; assert(p\
    \ >= 0);\n        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n        return\
    \ ans; \n    }\n    friend Mint inv(const Mint& a) { assert(a.v != 0); return\
    \ pow(a, MOD - 2); }\n    Mint operator - () const { return Mint(-v); }\n    Mint&\
    \ operator ++ () { return *this += 1; }\n    Mint& operator -- () { return *this\
    \ -= 1; }\n    friend Mint operator + (Mint a, const Mint& b) { return a += b;\
    \ }\n    friend Mint operator - (Mint a, const Mint& b) { return a -= b; }\n \
    \   friend Mint operator * (Mint a, const Mint& b) { return a *= b; }\n    friend\
    \ Mint operator / (Mint a, const Mint& b) { return a /= b; }\n};\n\nnamespace\
    \ FFT {\n\ntemplate <class T> void fft(std::vector<T>& A, bool inv = 0) {\n  \
    \  int n = (int) A.size();\n    assert((T::mod - 1) % n == 0);\n    std::vector<T>\
    \ B(n);\n    for (int b = n / 2; b; b /= 2, A.swap(B)) {\n        T w = pow(T::rt(),\
    \ (T::mod - 1) / n * b);\n        T m = 1;\n        for (int i = 0; i < n; i +=\
    \ b * 2, m *= w)\n            for (int j = 0; j < b; j++) {\n                T\
    \ u = A[i + j];\n                T v = A[i + j + b] * m;\n                B[i\
    \ / 2 + j] = u + v;\n                B[i / 2 + j + n / 2] = u - v;\n         \
    \   }\n    }\n    if (inv) {\n        std::reverse(1 + A.begin(), A.end());\n\
    \        T z = T(1) / T(n);\n        for (auto & t : A) \n            t *= z;\n\
    \    }\n}\ntemplate <class T> std::vector<T> multiply(std::vector<T> A, std::vector<T>\
    \ B) {\n    int sa = (int) A.size();\n    int sb = (int) B.size();\n    if (!std::min(sa,\
    \ sb))\n        return {};\n    int s = sa + sb - 1;\n    int n = 1;\n    for\
    \ (; n < s; n *= 2);\n    bool eq = A == B;\n    A.resize(n);\n    fft(A);\n \
    \   if (eq) \n        B = A;\n    else \n        B.resize(n), fft(B);\n    for\
    \ (int i = 0; i < n; i++)\n        A[i] *= B[i];\n    fft(A, 1);\n    A.resize(s);\n\
    \    return A;\n}\ntemplate <class M, class T> std::vector<M> multiply_mod(std::vector<T>\
    \ x, std::vector<T> y) {\n    auto convert = [](const std::vector<T>& v) {\n \
    \       std::vector<M> w((int) v.size());\n        for (int i =  0; i < (int)\
    \ v.size(); i++)\n            w[i] = (int) v[i];\n        return w;\n    };\n\
    \    return multiply(convert(x), convert(y));\n}\ntemplate <class T> std::vector<T>\
    \ general_multiply(const std::vector<T>& A, const std::vector<T>& B) { \n    //\
    \ arbitrary modulus\n    using m0 = Mint<(119 << 23) + 1, 62>; \n    using m1\
    \ = Mint<(5 << 25) + 1, 62>;\n    using m2 = Mint<(7 << 26) + 1, 62>;\n    auto\
    \ c0 = multiply_mod<m0>(A, B);\n    auto c1 = multiply_mod<m1>(A, B);\n    auto\
    \ c2 = multiply_mod<m2>(A, B);\n    int n = (int) c0.size();\n    std::vector<T>\
    \ res(n);\n    m1 r01 = 1 / m1(m0::mod);\n    m2 r02 = 1 / m2(m0::mod);\n    m2\
    \ r12 = 1 / m2(m1::mod);\n    for (int i = 0; i < n; i++) {\n        int a = c0[i].v;\n\
    \        int b = ((c1[i] - a) * r01).v;\n        int c = (((c2[i] - a) * r02 -\
    \ b) * r12).v;\n        res[i] = (T(c) * m1::mod + b) * m0::mod + a;\n    }\n\
    \    return res;\n}\n\n}\n\nint main() {\n    using namespace std;\n    using\
    \ namespace FFT;\n    ios_base::sync_with_stdio(0);\n    int n, m; \n    cin >>\
    \ n >> m;\n    const int MOD = 1e9 + 7;\n    using num = Mint<MOD, 5>;\n    vector<num>\
    \ a(n), b(m);\n    for (int i = 0; i < n; i++)\n        cin >> a[i];\n    for\
    \ (int i = 0; i < m; i++)\n        cin >> b[i];\n    vector<num> c = general_multiply(a,\
    \ b);\n    for (int i = 0; i < (int) c.size(); i++)\n        cout << c[i] << \"\
    \ \";\n    cout << '\\n';\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <int MOD, int RT> struct Mint {\n  \
    \  static const int mod = MOD;\n    static constexpr Mint rt() { return RT; }\
    \ // primitive root for FFT\n    int v; \n    explicit operator int() const {\
    \ return v; } // explicit -> don't silently convert to int\n    Mint() { v = 0;\
    \ }\n    Mint(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);\
    \ if (v < 0) v += MOD; }\n    friend bool operator == (const Mint& a, const Mint&\
    \ b) { return a.v == b.v; }\n    friend bool operator != (const Mint& a, const\
    \ Mint& b) { return !(a == b); }\n    friend bool operator < (const Mint& a, const\
    \ Mint& b) { return a.v < b.v; }\n    friend bool operator > (const Mint& a, const\
    \ Mint& b) { return a.v > b.v; }\n    friend bool operator <= (const Mint& a,\
    \ const Mint& b) { return a.v <= b.v; }\n    friend bool operator >= (const Mint&\
    \ a, const Mint& b) { return a.v >= b.v; }\n    friend std::istream& operator\
    \ >> (std::istream& in, Mint& a) { \n        long long x; std::cin >> x; a = Mint(x);\
    \ return in; }\n    friend std::ostream& operator << (std::ostream& os, const\
    \ Mint& a) { return os << a.v; }\n    Mint& operator += (const Mint& m) { \n \
    \       if ((v += m.v) >= MOD) v -= MOD; \n        return *this; }\n    Mint&\
    \ operator -= (const Mint& m) { \n        if ((v -= m.v) < 0) v += MOD; \n   \
    \     return *this; }\n    Mint& operator *= (const Mint& m) { \n        v = (long\
    \ long ) v * m.v % MOD; return *this; }\n    Mint& operator /= (const Mint& m)\
    \ { return (*this) *= inv(m); }\n    friend Mint pow(Mint a, long long p) {\n\
    \        Mint ans = 1; assert(p >= 0);\n        for (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n        return ans; \n    }\n    friend Mint inv(const Mint&\
    \ a) { assert(a.v != 0); return pow(a, MOD - 2); }\n    Mint operator - () const\
    \ { return Mint(-v); }\n    Mint& operator ++ () { return *this += 1; }\n    Mint&\
    \ operator -- () { return *this -= 1; }\n    friend Mint operator + (Mint a, const\
    \ Mint& b) { return a += b; }\n    friend Mint operator - (Mint a, const Mint&\
    \ b) { return a -= b; }\n    friend Mint operator * (Mint a, const Mint& b) {\
    \ return a *= b; }\n    friend Mint operator / (Mint a, const Mint& b) { return\
    \ a /= b; }\n};\n\nnamespace FFT {\n\ntemplate <class T> void fft(std::vector<T>&\
    \ A, bool inv = 0) {\n    int n = (int) A.size();\n    assert((T::mod - 1) % n\
    \ == 0);\n    std::vector<T> B(n);\n    for (int b = n / 2; b; b /= 2, A.swap(B))\
    \ {\n        T w = pow(T::rt(), (T::mod - 1) / n * b);\n        T m = 1;\n   \
    \     for (int i = 0; i < n; i += b * 2, m *= w)\n            for (int j = 0;\
    \ j < b; j++) {\n                T u = A[i + j];\n                T v = A[i +\
    \ j + b] * m;\n                B[i / 2 + j] = u + v;\n                B[i / 2\
    \ + j + n / 2] = u - v;\n            }\n    }\n    if (inv) {\n        std::reverse(1\
    \ + A.begin(), A.end());\n        T z = T(1) / T(n);\n        for (auto & t :\
    \ A) \n            t *= z;\n    }\n}\ntemplate <class T> std::vector<T> multiply(std::vector<T>\
    \ A, std::vector<T> B) {\n    int sa = (int) A.size();\n    int sb = (int) B.size();\n\
    \    if (!std::min(sa, sb))\n        return {};\n    int s = sa + sb - 1;\n  \
    \  int n = 1;\n    for (; n < s; n *= 2);\n    bool eq = A == B;\n    A.resize(n);\n\
    \    fft(A);\n    if (eq) \n        B = A;\n    else \n        B.resize(n), fft(B);\n\
    \    for (int i = 0; i < n; i++)\n        A[i] *= B[i];\n    fft(A, 1);\n    A.resize(s);\n\
    \    return A;\n}\ntemplate <class M, class T> std::vector<M> multiply_mod(std::vector<T>\
    \ x, std::vector<T> y) {\n    auto convert = [](const std::vector<T>& v) {\n \
    \       std::vector<M> w((int) v.size());\n        for (int i =  0; i < (int)\
    \ v.size(); i++)\n            w[i] = (int) v[i];\n        return w;\n    };\n\
    \    return multiply(convert(x), convert(y));\n}\ntemplate <class T> std::vector<T>\
    \ general_multiply(const std::vector<T>& A, const std::vector<T>& B) { \n    //\
    \ arbitrary modulus\n    using m0 = Mint<(119 << 23) + 1, 62>; \n    using m1\
    \ = Mint<(5 << 25) + 1, 62>;\n    using m2 = Mint<(7 << 26) + 1, 62>;\n    auto\
    \ c0 = multiply_mod<m0>(A, B);\n    auto c1 = multiply_mod<m1>(A, B);\n    auto\
    \ c2 = multiply_mod<m2>(A, B);\n    int n = (int) c0.size();\n    std::vector<T>\
    \ res(n);\n    m1 r01 = 1 / m1(m0::mod);\n    m2 r02 = 1 / m2(m0::mod);\n    m2\
    \ r12 = 1 / m2(m1::mod);\n    for (int i = 0; i < n; i++) {\n        int a = c0[i].v;\n\
    \        int b = ((c1[i] - a) * r01).v;\n        int c = (((c2[i] - a) * r02 -\
    \ b) * r12).v;\n        res[i] = (T(c) * m1::mod + b) * m0::mod + a;\n    }\n\
    \    return res;\n}\n\n}\n\nint main() {\n    using namespace std;\n    using\
    \ namespace FFT;\n    ios_base::sync_with_stdio(0);\n    int n, m; \n    cin >>\
    \ n >> m;\n    const int MOD = 1e9 + 7;\n    using num = Mint<MOD, 5>;\n    vector<num>\
    \ a(n), b(m);\n    for (int i = 0; i < n; i++)\n        cin >> a[i];\n    for\
    \ (int i = 0; i < m; i++)\n        cin >> b[i];\n    vector<num> c = general_multiply(a,\
    \ b);\n    for (int i = 0; i < (int) c.size(); i++)\n        cout << c[i] << \"\
    \ \";\n    cout << '\\n';\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/fast_fourier_transform.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/fast_fourier_transform.cpp
layout: document
redirect_from:
- /library/library/numerical/fast_fourier_transform.cpp
- /library/library/numerical/fast_fourier_transform.cpp.html
title: library/numerical/fast_fourier_transform.cpp
---
