---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/indy256/codelibrary/
    - https://oj.uz/problem/view/IOI11_parrots
  bundledCode: "#line 1 \"library/numerical/big_integer.cpp\"\n#include <bits/stdc++.h>\n\
    /**\n * Description: Big Integer\n * Source: https://github.com/indy256/codelibrary/\n\
    \t\t\tblob/master/cpp/numbertheory/BigInt.cpp\n * Verification: https://oj.uz/problem/view/IOI11_parrots\n\
    \ */\n\n// base and base_digits must be consistent\nconstexpr int base = 1000000000;\n\
    constexpr int base_digits = 9;\n\nstruct BigInt {\n\t// value == 0 is represented\
    \ by empty z\n\tstd::vector<int> z; // digits\n\n\t// sign == 1 <==> value >=\
    \ 0\n\t// sign == -1 <==> value < 0\n\tint sign;\n\n\tBigInt() : sign(1) {}\n\t\
    BigInt(long long v) { *this = v; }\n\n\tBigInt &operator=(long long v) {\n\t\t\
    sign = v < 0 ? -1 : 1; v *= sign;\n\t\tz.clear(); for (; v > 0; v = v / base)\
    \ z.push_back((int) (v % base));\n\t\treturn *this;\n\t}\n\n\tBigInt(const std::string\
    \ &s) { read(s); }\n\n\tBigInt &operator+=(const BigInt &other) {\n\t\tif (sign\
    \ == other.sign) {\n\t\t\tfor (int i = 0, carry = 0; i < other.z.size() || carry;\
    \ ++i) {\n\t\t\t\tif (i == z.size())\n\t\t\t\t\tz.push_back(0);\n\t\t\t\tz[i]\
    \ += carry + (i < other.z.size() ? other.z[i] : 0);\n\t\t\t\tcarry = z[i] >= base;\n\
    \t\t\t\tif (carry)\n\t\t\t\t\tz[i] -= base;\n\t\t\t}\n\t\t} else if (other !=\
    \ 0 /* prevent infinite loop */) {\n\t\t\t*this -= -other;\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\n\tfriend BigInt operator+(BigInt a, const BigInt &b) { return\
    \ a += b; }\n\n\tBigInt &operator-=(const BigInt &other) {\n\t\tif (sign == other.sign)\
    \ {\n\t\t\tif (sign == 1 && *this >= other || sign == -1 && *this <= other) {\n\
    \t\t\t\tfor (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {\n\t\t\t\
    \t\tz[i] -= carry + (i < other.z.size() ? other.z[i] : 0);\n\t\t\t\t\tcarry =\
    \ z[i] < 0;\n\t\t\t\t\tif (carry)\n\t\t\t\t\t\tz[i] += base;\n\t\t\t\t}\n\t\t\t\
    \ttrim();\n\t\t\t} else {\n\t\t\t\t*this = other - *this;\n\t\t\t\tthis->sign\
    \ = -this->sign;\n\t\t\t}\n\t\t} else {\n\t\t\t*this += -other;\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\n\tfriend BigInt operator-(BigInt a, const BigInt &b) { return\
    \ a -= b; }\n\n\tBigInt &operator*=(int v) {\n\t\tif (v < 0) sign = -sign, v =\
    \ -v;\n\t\tfor (int i = 0, carry = 0; i < z.size() || carry; ++i) {\n\t\t\tif\
    \ (i == z.size())\n\t\t\t\tz.push_back(0);\n\t\t\tlong long cur = (long long)\
    \ z[i] * v + carry;\n\t\t\tcarry = (int) (cur / base);\n\t\t\tz[i] = (int) (cur\
    \ % base);\n\t\t}\n\t\ttrim();\n\t\treturn *this;\n\t}\n\n\tBigInt operator*(int\
    \ v) const { return BigInt(*this) *= v; }\n\n\tfriend std::pair<BigInt, BigInt>\
    \ divmod(const BigInt &a1, const BigInt &b1) {\n\t\tint norm = base / (b1.z.back()\
    \ + 1);\n\t\tBigInt a = a1.abs() * norm;\n\t\tBigInt b = b1.abs() * norm;\n\t\t\
    BigInt q, r;\n\t\tq.z.resize(a.z.size());\n\n\t\tfor (int i = (int) a.z.size()\
    \ - 1; i >= 0; i--) {\n\t\t\tr *= base;\n\t\t\tr += a.z[i];\n\t\t\tint s1 = b.z.size()\
    \ < r.z.size() ? r.z[b.z.size()] : 0;\n\t\t\tint s2 = b.z.size() - 1 < r.z.size()\
    \ ? r.z[b.z.size() - 1] : 0;\n\t\t\tint d = (int) (((long long) s1 * base + s2)\
    \ / b.z.back());\n\t\t\tr -= b * d;\n\t\t\twhile (r < 0)\n\t\t\t\tr += b, --d;\n\
    \t\t\tq.z[i] = d;\n\t\t}\n\n\t\tq.sign = a1.sign * b1.sign;\n\t\tr.sign = a1.sign;\n\
    \t\tq.trim();\n\t\tr.trim();\n\t\treturn {q, r / norm};\n\t}\n\n\tfriend BigInt\
    \ sqrt(const BigInt &a1) {\n\t\tBigInt a = a1;\n\t\twhile (a.z.empty() || a.z.size()\
    \ % 2 == 1)\n\t\t\ta.z.push_back(0);\n\n\t\tint n = a.z.size();\n\n\t\tint firstDigit\
    \ = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);\n\t\tint norm = base\
    \ / (firstDigit + 1);\n\t\ta *= norm;\n\t\ta *= norm;\n\t\twhile (a.z.empty()\
    \ || a.z.size() % 2 == 1)\n\t\t\ta.z.push_back(0);\n\n\t\tBigInt r = (long long)\
    \ a.z[n - 1] * base + a.z[n - 2];\n\t\tfirstDigit = (int) ::sqrt((double) a.z[n\
    \ - 1] * base + a.z[n - 2]);\n\t\tint q = firstDigit;\n\t\tBigInt res;\n\n\t\t\
    for (int j = n / 2 - 1; j >= 0; j--) {\n\t\t\tfor (;; --q) {\n\t\t\t\tBigInt r1\
    \ = (r - (res * 2 * base + q) * q) * base * base +\n\t\t\t\t\t\t\t(j > 0 ? (long\
    \ long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);\n\t\t\t\tif (r1 >= 0) {\n\
    \t\t\t\t\tr = r1;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tres *= base;\n\t\
    \t\tres += q;\n\n\t\t\tif (j > 0) {\n\t\t\t\tint d1 = res.z.size() + 2 < r.z.size()\
    \ ? r.z[res.z.size() + 2] : 0;\n\t\t\t\tint d2 = res.z.size() + 1 < r.z.size()\
    \ ? r.z[res.z.size() + 1] : 0;\n\t\t\t\tint d3 = res.z.size() < r.z.size() ? r.z[res.z.size()]\
    \ : 0;\n\t\t\t\tq = (int) (((long long) d1 * base * base + (long long) d2 * base\
    \ + d3) / (firstDigit * 2));\n\t\t\t}\n\t\t}\n\n\t\tres.trim();\n\t\treturn res\
    \ / norm;\n\t}\n\n\tBigInt operator/(const BigInt &v) const { return divmod(*this,\
    \ v).first; }\n\n\tBigInt operator%(const BigInt &v) const { return divmod(*this,\
    \ v).second; }\n\n\tBigInt &operator/=(int v) {\n\t\tif (v < 0) sign = -sign,\
    \ v = -v;\n\t\tfor (int i = (int) z.size() - 1, rem = 0; i >= 0; --i) {\n\t\t\t\
    long long cur = z[i] + rem * (long long) base;\n\t\t\tz[i] = (int) (cur / v);\n\
    \t\t\trem = (int) (cur % v);\n\t\t}\n\t\ttrim();\n\t\treturn *this;\n\t}\n\n\t\
    BigInt operator/(int v) const { return BigInt(*this) /= v; }\n\n\tint operator%(int\
    \ v) const {\n\t\tif (v < 0) v = -v;\n\t\tint m = 0;\n\t\tfor (int i = (int) z.size()\
    \ - 1; i >= 0; --i)\n\t\t\tm = (int) ((z[i] + m * (long long) base) % v);\n\t\t\
    return m * sign;\n\t}\n\n\tBigInt &operator*=(const BigInt &v) { return *this\
    \ = *this * v; }\n\tBigInt &operator/=(const BigInt &v) { return *this = *this\
    \ / v; }\n\n\tbool operator<(const BigInt &v) const {\n\t\tif (sign != v.sign)\n\
    \t\t\treturn sign < v.sign;\n\t\tif (z.size() != v.z.size())\n\t\t\treturn z.size()\
    \ * sign < v.z.size() * v.sign;\n\t\tfor (int i = (int) z.size() - 1; i >= 0;\
    \ i--)\n\t\t\tif (z[i] != v.z[i])\n\t\t\t\treturn z[i] * sign < v.z[i] * sign;\n\
    \t\treturn false;\n\t}\n\n\tbool operator>(const BigInt &v) const { return v <\
    \ *this; }\n\tbool operator<=(const BigInt &v) const { return !(v < *this); }\n\
    \tbool operator>=(const BigInt &v) const { return !(*this < v); }\n\tbool operator==(const\
    \ BigInt &v) const { return !(*this < v) && !(v < *this); }\n\tbool operator!=(const\
    \ BigInt &v) const { return *this < v || v < *this; }\n\n\tvoid trim() {\n\t\t\
    while (!z.empty() && z.back() == 0) z.pop_back();\n\t\tif (z.empty()) sign = 1;\n\
    \t}\n\n\tbool is_zero() const { return z.empty(); }\n\n\tfriend BigInt operator-(BigInt\
    \ v) {\n\t\tif (!v.z.empty()) v.sign = -v.sign;\n\t\treturn v;\n\t}\n\n\tBigInt\
    \ abs() const { return sign == 1 ? *this : -*this; }\n\n\tlong long longValue()\
    \ const {\n\t\tlong long res = 0;\n\t\tfor (int i = (int) z.size() - 1; i >= 0;\
    \ i--)\n\t\t\tres = res * base + z[i];\n\t\treturn res * sign;\n\t}\n\n\tfriend\
    \ BigInt gcd(const BigInt &a, const BigInt &b) {\n\t\treturn b.is_zero() ? a :\
    \ gcd(b, a % b);\n\t}\n\n\tfriend BigInt lcm(const BigInt &a, const BigInt &b)\
    \ {\n\t\treturn a / gcd(a, b) * b;\n\t}\n\n\tvoid read(const std::string &s) {\n\
    \t\tsign = 1;\n\t\tz.clear();\n\t\tint pos = 0;\n\t\twhile (pos < s.size() &&\
    \ (s[pos] == '-' || s[pos] == '+')) {\n\t\t\tif (s[pos] == '-')\n\t\t\t\tsign\
    \ = -sign;\n\t\t\t++pos;\n\t\t}\n\t\tfor (int i = (int) s.size() - 1; i >= pos;\
    \ i -= base_digits) {\n\t\t\tint x = 0;\n\t\t\tfor (int j = std::max(pos, i -\
    \ base_digits + 1); j <= i; j++)\n\t\t\t\tx = x * 10 + s[j] - '0';\n\t\t\tz.push_back(x);\n\
    \t\t}\n\t\ttrim();\n\t}\n\n\tfriend std::istream &operator>>(std::istream &stream,\
    \ BigInt &v) {\n\t\tstd::string s; stream >> s;\n\t\tv.read(s);\n\t\treturn stream;\n\
    \t}\n\n\tfriend std::ostream &operator<<(std::ostream &stream, const BigInt &v)\
    \ {\n\t\tif (v.sign == -1)\n\t\t\tstream << '-';\n\t\tstream << (v.z.empty() ?\
    \ 0 : v.z.back());\n\t\tfor (int i = (int) v.z.size() - 2; i >= 0; --i)\n\t\t\t\
    stream << std::setw(base_digits) << std::setfill('0') << v.z[i];\n\t\treturn stream;\n\
    \t}\n\n\tstatic std::vector<int> convert_base(const std::vector<int> &a, int old_digits,\
    \ int new_digits) {\n\t\tstd::vector<long long> p(std::max(old_digits, new_digits)\
    \ + 1);\n\t\tp[0] = 1;\n\t\tfor (int i = 1; i < p.size(); i++)\n\t\t\tp[i] = p[i\
    \ - 1] * 10;\n\t\tstd::vector<int> res;\n\t\tlong long cur = 0;\n\t\tint cur_digits\
    \ = 0;\n\t\tfor (int v : a) {\n\t\t\tcur += v * p[cur_digits];\n\t\t\tcur_digits\
    \ += old_digits;\n\t\t\twhile (cur_digits >= new_digits) {\n\t\t\t\tres.push_back(int(cur\
    \ % p[new_digits]));\n\t\t\t\tcur /= p[new_digits];\n\t\t\t\tcur_digits -= new_digits;\n\
    \t\t\t}\n\t\t}\n\t\tres.push_back((int) cur);\n\t\twhile (!res.empty() && res.back()\
    \ == 0)\n\t\t\tres.pop_back();\n\t\treturn res;\n\t}\n\n\tstatic std::vector<long\
    \ long> karatsubaMultiply(const std::vector<long long> &a, const std::vector<long\
    \ long> &b) {\n\t\tint n = a.size();\n\t\tstd::vector<long long> res(n + n);\n\
    \t\tif (n <= 32) {\n\t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\tfor (int j = 0;\
    \ j < n; j++)\n\t\t\t\t\tres[i + j] += a[i] * b[j];\n\t\t\treturn res;\n\t\t}\n\
    \n\t\tint k = n >> 1;\n\t\tstd::vector<long long> a1(a.begin(), a.begin() + k);\n\
    \t\tstd::vector<long long> a2(a.begin() + k, a.end());\n\t\tstd::vector<long long>\
    \ b1(b.begin(), b.begin() + k);\n\t\tstd::vector<long long> b2(b.begin() + k,\
    \ b.end());\n\n\t\tstd::vector<long long> a1b1 = karatsubaMultiply(a1, b1);\n\t\
    \tstd::vector<long long> a2b2 = karatsubaMultiply(a2, b2);\n\n\t\tfor (int i =\
    \ 0; i < k; i++)\n\t\t\ta2[i] += a1[i];\n\t\tfor (int i = 0; i < k; i++)\n\t\t\
    \tb2[i] += b1[i];\n\n\t\tstd::vector<long long> r = karatsubaMultiply(a2, b2);\n\
    \t\tfor (int i = 0; i < a1b1.size(); i++)\n\t\t\tr[i] -= a1b1[i];\n\t\tfor (int\
    \ i = 0; i < a2b2.size(); i++)\n\t\t\tr[i] -= a2b2[i];\n\n\t\tfor (int i = 0;\
    \ i < r.size(); i++)\n\t\t\tres[i + k] += r[i];\n\t\tfor (int i = 0; i < a1b1.size();\
    \ i++)\n\t\t\tres[i] += a1b1[i];\n\t\tfor (int i = 0; i < a2b2.size(); i++)\n\t\
    \t\tres[i + n] += a2b2[i];\n\t\treturn res;\n\t}\n\n\tBigInt operator*(const BigInt\
    \ &v) const {\n\t\tstd::vector<int> a6 = convert_base(this->z, base_digits, 6);\n\
    \t\tstd::vector<int> b6 = convert_base(v.z, base_digits, 6);\n\t\tstd::vector<long\
    \ long> a(a6.begin(), a6.end());\n\t\tstd::vector<long long> b(b6.begin(), b6.end());\n\
    \t\twhile (a.size() < b.size())\n\t\t\ta.push_back(0);\n\t\twhile (b.size() <\
    \ a.size())\n\t\t\tb.push_back(0);\n\t\twhile (a.size() & (a.size() - 1))\n\t\t\
    \ta.push_back(0), b.push_back(0);\n\t\tstd::vector<long long> c = karatsubaMultiply(a,\
    \ b);\n\t\tBigInt res;\n\t\tres.sign = sign * v.sign;\n\t\tfor (int i = 0, carry\
    \ = 0; i < c.size(); i++) {\n\t\t\tlong long cur = c[i] + carry;\n\t\t\tres.z.push_back((int)\
    \ (cur % 1000000));\n\t\t\tcarry = (int) (cur / 1000000);\n\t\t}\n\t\tres.z =\
    \ convert_base(res.z, 6, base_digits);\n\t\tres.trim();\n\t\treturn res;\n\t}\n\
    };\n\nBigInt random_big_int(int n) {\n\tstd::string s;\n\tfor (int i = 0; i <\
    \ n; i++) {\n\t\ts += rand() % 10 + '0';\n\t}\n\treturn BigInt(s);\n}\n"
  code: "#include <bits/stdc++.h>\n/**\n * Description: Big Integer\n * Source: https://github.com/indy256/codelibrary/\n\
    \t\t\tblob/master/cpp/numbertheory/BigInt.cpp\n * Verification: https://oj.uz/problem/view/IOI11_parrots\n\
    \ */\n\n// base and base_digits must be consistent\nconstexpr int base = 1000000000;\n\
    constexpr int base_digits = 9;\n\nstruct BigInt {\n\t// value == 0 is represented\
    \ by empty z\n\tstd::vector<int> z; // digits\n\n\t// sign == 1 <==> value >=\
    \ 0\n\t// sign == -1 <==> value < 0\n\tint sign;\n\n\tBigInt() : sign(1) {}\n\t\
    BigInt(long long v) { *this = v; }\n\n\tBigInt &operator=(long long v) {\n\t\t\
    sign = v < 0 ? -1 : 1; v *= sign;\n\t\tz.clear(); for (; v > 0; v = v / base)\
    \ z.push_back((int) (v % base));\n\t\treturn *this;\n\t}\n\n\tBigInt(const std::string\
    \ &s) { read(s); }\n\n\tBigInt &operator+=(const BigInt &other) {\n\t\tif (sign\
    \ == other.sign) {\n\t\t\tfor (int i = 0, carry = 0; i < other.z.size() || carry;\
    \ ++i) {\n\t\t\t\tif (i == z.size())\n\t\t\t\t\tz.push_back(0);\n\t\t\t\tz[i]\
    \ += carry + (i < other.z.size() ? other.z[i] : 0);\n\t\t\t\tcarry = z[i] >= base;\n\
    \t\t\t\tif (carry)\n\t\t\t\t\tz[i] -= base;\n\t\t\t}\n\t\t} else if (other !=\
    \ 0 /* prevent infinite loop */) {\n\t\t\t*this -= -other;\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\n\tfriend BigInt operator+(BigInt a, const BigInt &b) { return\
    \ a += b; }\n\n\tBigInt &operator-=(const BigInt &other) {\n\t\tif (sign == other.sign)\
    \ {\n\t\t\tif (sign == 1 && *this >= other || sign == -1 && *this <= other) {\n\
    \t\t\t\tfor (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {\n\t\t\t\
    \t\tz[i] -= carry + (i < other.z.size() ? other.z[i] : 0);\n\t\t\t\t\tcarry =\
    \ z[i] < 0;\n\t\t\t\t\tif (carry)\n\t\t\t\t\t\tz[i] += base;\n\t\t\t\t}\n\t\t\t\
    \ttrim();\n\t\t\t} else {\n\t\t\t\t*this = other - *this;\n\t\t\t\tthis->sign\
    \ = -this->sign;\n\t\t\t}\n\t\t} else {\n\t\t\t*this += -other;\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\n\tfriend BigInt operator-(BigInt a, const BigInt &b) { return\
    \ a -= b; }\n\n\tBigInt &operator*=(int v) {\n\t\tif (v < 0) sign = -sign, v =\
    \ -v;\n\t\tfor (int i = 0, carry = 0; i < z.size() || carry; ++i) {\n\t\t\tif\
    \ (i == z.size())\n\t\t\t\tz.push_back(0);\n\t\t\tlong long cur = (long long)\
    \ z[i] * v + carry;\n\t\t\tcarry = (int) (cur / base);\n\t\t\tz[i] = (int) (cur\
    \ % base);\n\t\t}\n\t\ttrim();\n\t\treturn *this;\n\t}\n\n\tBigInt operator*(int\
    \ v) const { return BigInt(*this) *= v; }\n\n\tfriend std::pair<BigInt, BigInt>\
    \ divmod(const BigInt &a1, const BigInt &b1) {\n\t\tint norm = base / (b1.z.back()\
    \ + 1);\n\t\tBigInt a = a1.abs() * norm;\n\t\tBigInt b = b1.abs() * norm;\n\t\t\
    BigInt q, r;\n\t\tq.z.resize(a.z.size());\n\n\t\tfor (int i = (int) a.z.size()\
    \ - 1; i >= 0; i--) {\n\t\t\tr *= base;\n\t\t\tr += a.z[i];\n\t\t\tint s1 = b.z.size()\
    \ < r.z.size() ? r.z[b.z.size()] : 0;\n\t\t\tint s2 = b.z.size() - 1 < r.z.size()\
    \ ? r.z[b.z.size() - 1] : 0;\n\t\t\tint d = (int) (((long long) s1 * base + s2)\
    \ / b.z.back());\n\t\t\tr -= b * d;\n\t\t\twhile (r < 0)\n\t\t\t\tr += b, --d;\n\
    \t\t\tq.z[i] = d;\n\t\t}\n\n\t\tq.sign = a1.sign * b1.sign;\n\t\tr.sign = a1.sign;\n\
    \t\tq.trim();\n\t\tr.trim();\n\t\treturn {q, r / norm};\n\t}\n\n\tfriend BigInt\
    \ sqrt(const BigInt &a1) {\n\t\tBigInt a = a1;\n\t\twhile (a.z.empty() || a.z.size()\
    \ % 2 == 1)\n\t\t\ta.z.push_back(0);\n\n\t\tint n = a.z.size();\n\n\t\tint firstDigit\
    \ = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);\n\t\tint norm = base\
    \ / (firstDigit + 1);\n\t\ta *= norm;\n\t\ta *= norm;\n\t\twhile (a.z.empty()\
    \ || a.z.size() % 2 == 1)\n\t\t\ta.z.push_back(0);\n\n\t\tBigInt r = (long long)\
    \ a.z[n - 1] * base + a.z[n - 2];\n\t\tfirstDigit = (int) ::sqrt((double) a.z[n\
    \ - 1] * base + a.z[n - 2]);\n\t\tint q = firstDigit;\n\t\tBigInt res;\n\n\t\t\
    for (int j = n / 2 - 1; j >= 0; j--) {\n\t\t\tfor (;; --q) {\n\t\t\t\tBigInt r1\
    \ = (r - (res * 2 * base + q) * q) * base * base +\n\t\t\t\t\t\t\t(j > 0 ? (long\
    \ long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);\n\t\t\t\tif (r1 >= 0) {\n\
    \t\t\t\t\tr = r1;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tres *= base;\n\t\
    \t\tres += q;\n\n\t\t\tif (j > 0) {\n\t\t\t\tint d1 = res.z.size() + 2 < r.z.size()\
    \ ? r.z[res.z.size() + 2] : 0;\n\t\t\t\tint d2 = res.z.size() + 1 < r.z.size()\
    \ ? r.z[res.z.size() + 1] : 0;\n\t\t\t\tint d3 = res.z.size() < r.z.size() ? r.z[res.z.size()]\
    \ : 0;\n\t\t\t\tq = (int) (((long long) d1 * base * base + (long long) d2 * base\
    \ + d3) / (firstDigit * 2));\n\t\t\t}\n\t\t}\n\n\t\tres.trim();\n\t\treturn res\
    \ / norm;\n\t}\n\n\tBigInt operator/(const BigInt &v) const { return divmod(*this,\
    \ v).first; }\n\n\tBigInt operator%(const BigInt &v) const { return divmod(*this,\
    \ v).second; }\n\n\tBigInt &operator/=(int v) {\n\t\tif (v < 0) sign = -sign,\
    \ v = -v;\n\t\tfor (int i = (int) z.size() - 1, rem = 0; i >= 0; --i) {\n\t\t\t\
    long long cur = z[i] + rem * (long long) base;\n\t\t\tz[i] = (int) (cur / v);\n\
    \t\t\trem = (int) (cur % v);\n\t\t}\n\t\ttrim();\n\t\treturn *this;\n\t}\n\n\t\
    BigInt operator/(int v) const { return BigInt(*this) /= v; }\n\n\tint operator%(int\
    \ v) const {\n\t\tif (v < 0) v = -v;\n\t\tint m = 0;\n\t\tfor (int i = (int) z.size()\
    \ - 1; i >= 0; --i)\n\t\t\tm = (int) ((z[i] + m * (long long) base) % v);\n\t\t\
    return m * sign;\n\t}\n\n\tBigInt &operator*=(const BigInt &v) { return *this\
    \ = *this * v; }\n\tBigInt &operator/=(const BigInt &v) { return *this = *this\
    \ / v; }\n\n\tbool operator<(const BigInt &v) const {\n\t\tif (sign != v.sign)\n\
    \t\t\treturn sign < v.sign;\n\t\tif (z.size() != v.z.size())\n\t\t\treturn z.size()\
    \ * sign < v.z.size() * v.sign;\n\t\tfor (int i = (int) z.size() - 1; i >= 0;\
    \ i--)\n\t\t\tif (z[i] != v.z[i])\n\t\t\t\treturn z[i] * sign < v.z[i] * sign;\n\
    \t\treturn false;\n\t}\n\n\tbool operator>(const BigInt &v) const { return v <\
    \ *this; }\n\tbool operator<=(const BigInt &v) const { return !(v < *this); }\n\
    \tbool operator>=(const BigInt &v) const { return !(*this < v); }\n\tbool operator==(const\
    \ BigInt &v) const { return !(*this < v) && !(v < *this); }\n\tbool operator!=(const\
    \ BigInt &v) const { return *this < v || v < *this; }\n\n\tvoid trim() {\n\t\t\
    while (!z.empty() && z.back() == 0) z.pop_back();\n\t\tif (z.empty()) sign = 1;\n\
    \t}\n\n\tbool is_zero() const { return z.empty(); }\n\n\tfriend BigInt operator-(BigInt\
    \ v) {\n\t\tif (!v.z.empty()) v.sign = -v.sign;\n\t\treturn v;\n\t}\n\n\tBigInt\
    \ abs() const { return sign == 1 ? *this : -*this; }\n\n\tlong long longValue()\
    \ const {\n\t\tlong long res = 0;\n\t\tfor (int i = (int) z.size() - 1; i >= 0;\
    \ i--)\n\t\t\tres = res * base + z[i];\n\t\treturn res * sign;\n\t}\n\n\tfriend\
    \ BigInt gcd(const BigInt &a, const BigInt &b) {\n\t\treturn b.is_zero() ? a :\
    \ gcd(b, a % b);\n\t}\n\n\tfriend BigInt lcm(const BigInt &a, const BigInt &b)\
    \ {\n\t\treturn a / gcd(a, b) * b;\n\t}\n\n\tvoid read(const std::string &s) {\n\
    \t\tsign = 1;\n\t\tz.clear();\n\t\tint pos = 0;\n\t\twhile (pos < s.size() &&\
    \ (s[pos] == '-' || s[pos] == '+')) {\n\t\t\tif (s[pos] == '-')\n\t\t\t\tsign\
    \ = -sign;\n\t\t\t++pos;\n\t\t}\n\t\tfor (int i = (int) s.size() - 1; i >= pos;\
    \ i -= base_digits) {\n\t\t\tint x = 0;\n\t\t\tfor (int j = std::max(pos, i -\
    \ base_digits + 1); j <= i; j++)\n\t\t\t\tx = x * 10 + s[j] - '0';\n\t\t\tz.push_back(x);\n\
    \t\t}\n\t\ttrim();\n\t}\n\n\tfriend std::istream &operator>>(std::istream &stream,\
    \ BigInt &v) {\n\t\tstd::string s; stream >> s;\n\t\tv.read(s);\n\t\treturn stream;\n\
    \t}\n\n\tfriend std::ostream &operator<<(std::ostream &stream, const BigInt &v)\
    \ {\n\t\tif (v.sign == -1)\n\t\t\tstream << '-';\n\t\tstream << (v.z.empty() ?\
    \ 0 : v.z.back());\n\t\tfor (int i = (int) v.z.size() - 2; i >= 0; --i)\n\t\t\t\
    stream << std::setw(base_digits) << std::setfill('0') << v.z[i];\n\t\treturn stream;\n\
    \t}\n\n\tstatic std::vector<int> convert_base(const std::vector<int> &a, int old_digits,\
    \ int new_digits) {\n\t\tstd::vector<long long> p(std::max(old_digits, new_digits)\
    \ + 1);\n\t\tp[0] = 1;\n\t\tfor (int i = 1; i < p.size(); i++)\n\t\t\tp[i] = p[i\
    \ - 1] * 10;\n\t\tstd::vector<int> res;\n\t\tlong long cur = 0;\n\t\tint cur_digits\
    \ = 0;\n\t\tfor (int v : a) {\n\t\t\tcur += v * p[cur_digits];\n\t\t\tcur_digits\
    \ += old_digits;\n\t\t\twhile (cur_digits >= new_digits) {\n\t\t\t\tres.push_back(int(cur\
    \ % p[new_digits]));\n\t\t\t\tcur /= p[new_digits];\n\t\t\t\tcur_digits -= new_digits;\n\
    \t\t\t}\n\t\t}\n\t\tres.push_back((int) cur);\n\t\twhile (!res.empty() && res.back()\
    \ == 0)\n\t\t\tres.pop_back();\n\t\treturn res;\n\t}\n\n\tstatic std::vector<long\
    \ long> karatsubaMultiply(const std::vector<long long> &a, const std::vector<long\
    \ long> &b) {\n\t\tint n = a.size();\n\t\tstd::vector<long long> res(n + n);\n\
    \t\tif (n <= 32) {\n\t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\tfor (int j = 0;\
    \ j < n; j++)\n\t\t\t\t\tres[i + j] += a[i] * b[j];\n\t\t\treturn res;\n\t\t}\n\
    \n\t\tint k = n >> 1;\n\t\tstd::vector<long long> a1(a.begin(), a.begin() + k);\n\
    \t\tstd::vector<long long> a2(a.begin() + k, a.end());\n\t\tstd::vector<long long>\
    \ b1(b.begin(), b.begin() + k);\n\t\tstd::vector<long long> b2(b.begin() + k,\
    \ b.end());\n\n\t\tstd::vector<long long> a1b1 = karatsubaMultiply(a1, b1);\n\t\
    \tstd::vector<long long> a2b2 = karatsubaMultiply(a2, b2);\n\n\t\tfor (int i =\
    \ 0; i < k; i++)\n\t\t\ta2[i] += a1[i];\n\t\tfor (int i = 0; i < k; i++)\n\t\t\
    \tb2[i] += b1[i];\n\n\t\tstd::vector<long long> r = karatsubaMultiply(a2, b2);\n\
    \t\tfor (int i = 0; i < a1b1.size(); i++)\n\t\t\tr[i] -= a1b1[i];\n\t\tfor (int\
    \ i = 0; i < a2b2.size(); i++)\n\t\t\tr[i] -= a2b2[i];\n\n\t\tfor (int i = 0;\
    \ i < r.size(); i++)\n\t\t\tres[i + k] += r[i];\n\t\tfor (int i = 0; i < a1b1.size();\
    \ i++)\n\t\t\tres[i] += a1b1[i];\n\t\tfor (int i = 0; i < a2b2.size(); i++)\n\t\
    \t\tres[i + n] += a2b2[i];\n\t\treturn res;\n\t}\n\n\tBigInt operator*(const BigInt\
    \ &v) const {\n\t\tstd::vector<int> a6 = convert_base(this->z, base_digits, 6);\n\
    \t\tstd::vector<int> b6 = convert_base(v.z, base_digits, 6);\n\t\tstd::vector<long\
    \ long> a(a6.begin(), a6.end());\n\t\tstd::vector<long long> b(b6.begin(), b6.end());\n\
    \t\twhile (a.size() < b.size())\n\t\t\ta.push_back(0);\n\t\twhile (b.size() <\
    \ a.size())\n\t\t\tb.push_back(0);\n\t\twhile (a.size() & (a.size() - 1))\n\t\t\
    \ta.push_back(0), b.push_back(0);\n\t\tstd::vector<long long> c = karatsubaMultiply(a,\
    \ b);\n\t\tBigInt res;\n\t\tres.sign = sign * v.sign;\n\t\tfor (int i = 0, carry\
    \ = 0; i < c.size(); i++) {\n\t\t\tlong long cur = c[i] + carry;\n\t\t\tres.z.push_back((int)\
    \ (cur % 1000000));\n\t\t\tcarry = (int) (cur / 1000000);\n\t\t}\n\t\tres.z =\
    \ convert_base(res.z, 6, base_digits);\n\t\tres.trim();\n\t\treturn res;\n\t}\n\
    };\n\nBigInt random_big_int(int n) {\n\tstd::string s;\n\tfor (int i = 0; i <\
    \ n; i++) {\n\t\ts += rand() % 10 + '0';\n\t}\n\treturn BigInt(s);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/big_integer.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/big_integer.cpp
layout: document
redirect_from:
- /library/library/numerical/big_integer.cpp
- /library/library/numerical/big_integer.cpp.html
title: library/numerical/big_integer.cpp
---
