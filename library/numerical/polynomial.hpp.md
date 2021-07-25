---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\nnamespace Polynomial {\n\nusing T = int;\nusing Poly = std::vector<T>;\n\
    \nT eval(const Poly &p, const T &x) {\n\tT res = 0;\n\tfor (int i = (int)p.size()\
    \ - 1; i >= 0; --i) {\n\t\tres = x * res + p[i];\n\t}\n\treturn res;\n}\n\nPoly&\
    \ operator+=(Poly &l, const Poly &r ){\n\tl.resize(std::max(l.size(), r.size()));\n\
    \tfor (int i = 0; i < r.size(); ++i) {\n\t\tl[i] += r[i];\n\t}\n\treturn l;\n\
    }\n\nPoly& operator-=(Poly &l, const Poly &r ){\n\tl.resize(std::max(l.size(),\
    \ r.size()));\n\tfor (int i = 0; i < r.size(); ++i) {\n\t\tl[i] -= r[i];\n\t}\n\
    \treturn l;\n}\n\nPoly& operator*=(Poly &l, const T& r) {\n\tfor (int i = 0; i\
    \ < l.size(); ++i) {\n\t\tl[i] *= r;\n\t}\n\treturn l;\n}\n\nPoly& operator/=(Poly\
    \ &l, const T& r) {\n\tfor (int i = 0; i < l.size(); ++i) {\n\t\tl[i] /= r;\n\t\
    }\n\treturn l;\n}\n\nPoly operator*(const Poly &l, const Poly &r) {\n\tif (!std::min(l.size(),\
    \ r.size())) {\n\t\treturn {};\n\t}\n\tPoly res(l.size() + r.size() - 1);\n\t\
    for (int i = 0; i < l.size(); ++i) {\n\t\tfor (int j = 0; j < r.size(); ++j) {\n\
    \t\t\tres[i + j] += l[i] * r[j];\n\t\t}\n\t}\n\treturn res;\n}\n\nPoly operator+(Poly\
    \ l, const Poly &r) { return l += r; }\nPoly operator-(Poly l, const Poly &r)\
    \ { return l -= r; }\nPoly operator-(Poly l) { for (auto &t : l) t *= -1; return\
    \ l; }\nPoly operator*(Poly l, const T &r) { return l *= r; }\nPoly operator*(const\
    \ T& r, const Poly &l) { return l * r; }\nPoly operator/(Poly l, const T &r) {\
    \ return l /= r;\t}\nPoly& operator*=(Poly &l, const Poly &r) { return l = l *\
    \ r; }\n\nPoly derivative(const Poly &p) {\n\tPoly res;\n\tfor (int i = 1; i <\
    \ p.size(); ++i) {\n\t\tres.push_back(T(i) * p[i]);\n\t}\n\treturn res;\n}\n\n\
    Poly integral(const Poly &p) {\n\tstatic Poly invs{0, 1};\n\tfor (int i = invs.size();\
    \ i <= p.size(); ++i ){\n\t\tinvs.push_back(1 / T(i));\n\t}\n\tPoly res(p.size()\
    \ + 1);\n\tfor (int i = 0; i < p.size(); ++i) {\n\t\tres[i + 1] = p[i] * invs[i\
    \ + 1];\n\t}\n\treturn res;\n}\n\n}\n"
  code: "#pragma once\n\nnamespace Polynomial {\n\nusing T = int;\nusing Poly = std::vector<T>;\n\
    \nT eval(const Poly &p, const T &x) {\n\tT res = 0;\n\tfor (int i = (int)p.size()\
    \ - 1; i >= 0; --i) {\n\t\tres = x * res + p[i];\n\t}\n\treturn res;\n}\n\nPoly&\
    \ operator+=(Poly &l, const Poly &r ){\n\tl.resize(std::max(l.size(), r.size()));\n\
    \tfor (int i = 0; i < r.size(); ++i) {\n\t\tl[i] += r[i];\n\t}\n\treturn l;\n\
    }\n\nPoly& operator-=(Poly &l, const Poly &r ){\n\tl.resize(std::max(l.size(),\
    \ r.size()));\n\tfor (int i = 0; i < r.size(); ++i) {\n\t\tl[i] -= r[i];\n\t}\n\
    \treturn l;\n}\n\nPoly& operator*=(Poly &l, const T& r) {\n\tfor (int i = 0; i\
    \ < l.size(); ++i) {\n\t\tl[i] *= r;\n\t}\n\treturn l;\n}\n\nPoly& operator/=(Poly\
    \ &l, const T& r) {\n\tfor (int i = 0; i < l.size(); ++i) {\n\t\tl[i] /= r;\n\t\
    }\n\treturn l;\n}\n\nPoly operator*(const Poly &l, const Poly &r) {\n\tif (!std::min(l.size(),\
    \ r.size())) {\n\t\treturn {};\n\t}\n\tPoly res(l.size() + r.size() - 1);\n\t\
    for (int i = 0; i < l.size(); ++i) {\n\t\tfor (int j = 0; j < r.size(); ++j) {\n\
    \t\t\tres[i + j] += l[i] * r[j];\n\t\t}\n\t}\n\treturn res;\n}\n\nPoly operator+(Poly\
    \ l, const Poly &r) { return l += r; }\nPoly operator-(Poly l, const Poly &r)\
    \ { return l -= r; }\nPoly operator-(Poly l) { for (auto &t : l) t *= -1; return\
    \ l; }\nPoly operator*(Poly l, const T &r) { return l *= r; }\nPoly operator*(const\
    \ T& r, const Poly &l) { return l * r; }\nPoly operator/(Poly l, const T &r) {\
    \ return l /= r;\t}\nPoly& operator*=(Poly &l, const Poly &r) { return l = l *\
    \ r; }\n\nPoly derivative(const Poly &p) {\n\tPoly res;\n\tfor (int i = 1; i <\
    \ p.size(); ++i) {\n\t\tres.push_back(T(i) * p[i]);\n\t}\n\treturn res;\n}\n\n\
    Poly integral(const Poly &p) {\n\tstatic Poly invs{0, 1};\n\tfor (int i = invs.size();\
    \ i <= p.size(); ++i ){\n\t\tinvs.push_back(1 / T(i));\n\t}\n\tPoly res(p.size()\
    \ + 1);\n\tfor (int i = 0; i < p.size(); ++i) {\n\t\tres[i + 1] = p[i] * invs[i\
    \ + 1];\n\t}\n\treturn res;\n}\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/polynomial.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:46:46-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/polynomial.hpp
layout: document
redirect_from:
- /library/library/numerical/polynomial.hpp
- /library/library/numerical/polynomial.hpp.html
title: library/numerical/polynomial.hpp
---
