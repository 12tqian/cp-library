---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-big-integer.test.cpp
    title: verify/unit-test/unit-test-big-integer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n// base and base_digits must be consistent\r\nconstexpr int base\
    \ = 1000000000;\r\nconstexpr int base_digits = 9;\r\n\r\nstruct BigInt {\r\n\t\
    // value == 0 is represented by empty z\r\n\tstd::vector<int> z; // digits\r\n\
    \r\n\t// sign == 1 <==> value >= 0\r\n\t// sign == -1 <==> value < 0\r\n\tint\
    \ sign;\r\n\r\n\tBigInt() : sign(1) {}\r\n\tBigInt(long long v) { *this = v; }\r\
    \n\r\n\tBigInt& operator=(long long v) {\r\n\t\tsign = v < 0 ? -1 : 1; v *= sign;\r\
    \n\t\tz.clear(); for (; v > 0; v = v / base) z.push_back((int) (v % base));\r\n\
    \t\treturn *this;\r\n\t}\r\n\r\n\tBigInt(const std::string& s) { read(s); }\r\n\
    \r\n\tBigInt& operator+=(const BigInt& other) {\r\n\t\tif (sign == other.sign)\
    \ {\r\n\t\t\tfor (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {\r\n\
    \t\t\t\tif (i == z.size())\r\n\t\t\t\t\tz.push_back(0);\r\n\t\t\t\tz[i] += carry\
    \ + (i < other.z.size() ? other.z[i] : 0);\r\n\t\t\t\tcarry = z[i] >= base;\r\n\
    \t\t\t\tif (carry)\r\n\t\t\t\t\tz[i] -= base;\r\n\t\t\t}\r\n\t\t} else if (other\
    \ != 0 /* prevent infinite loop */) {\r\n\t\t\t*this -= -other;\r\n\t\t}\r\n\t\
    \treturn *this;\r\n\t}\r\n\r\n\tfriend BigInt operator+(BigInt a, const BigInt&\
    \ b) { return a += b; }\r\n\r\n\tBigInt& operator-=(const BigInt& other) {\r\n\
    \t\tif (sign == other.sign) {\r\n\t\t\tif (sign == 1 && *this >= other || sign\
    \ == -1 && *this <= other) {\r\n\t\t\t\tfor (int i = 0, carry = 0; i < other.z.size()\
    \ || carry; ++i) {\r\n\t\t\t\t\tz[i] -= carry + (i < other.z.size() ? other.z[i]\
    \ : 0);\r\n\t\t\t\t\tcarry = z[i] < 0;\r\n\t\t\t\t\tif (carry)\r\n\t\t\t\t\t\t\
    z[i] += base;\r\n\t\t\t\t}\r\n\t\t\t\ttrim();\r\n\t\t\t} else {\r\n\t\t\t\t*this\
    \ = other - *this;\r\n\t\t\t\tthis->sign = -this->sign;\r\n\t\t\t}\r\n\t\t} else\
    \ {\r\n\t\t\t*this += -other;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tfriend\
    \ BigInt operator-(BigInt a, const BigInt& b) { return a -= b; }\r\n\r\n\tBigInt&\
    \ operator*=(int v) {\r\n\t\tif (v < 0) sign = -sign, v = -v;\r\n\t\tfor (int\
    \ i = 0, carry = 0; i < z.size() || carry; ++i) {\r\n\t\t\tif (i == z.size())\r\
    \n\t\t\t\tz.push_back(0);\r\n\t\t\tlong long cur = (long long) z[i] * v + carry;\r\
    \n\t\t\tcarry = (int) (cur / base);\r\n\t\t\tz[i] = (int) (cur % base);\r\n\t\t\
    }\r\n\t\ttrim();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBigInt operator*(int v)\
    \ const { return BigInt(*this) *= v; }\r\n\r\n\tfriend std::pair<BigInt, BigInt>\
    \ divmod(const BigInt& a1, const BigInt& b1) {\r\n\t\tint norm = base / (b1.z.back()\
    \ + 1);\r\n\t\tBigInt a = a1.abs() * norm;\r\n\t\tBigInt b = b1.abs() * norm;\r\
    \n\t\tBigInt q, r;\r\n\t\tq.z.resize(a.z.size());\r\n\r\n\t\tfor (int i = (int)\
    \ a.z.size() - 1; i >= 0; i--) {\r\n\t\t\tr *= base;\r\n\t\t\tr += a.z[i];\r\n\
    \t\t\tint s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;\r\n\t\t\tint s2\
    \ = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;\r\n\t\t\tint d = (int)\
    \ (((long long) s1 * base + s2) / b.z.back());\r\n\t\t\tr -= b * d;\r\n\t\t\t\
    while (r < 0)\r\n\t\t\t\tr += b, --d;\r\n\t\t\tq.z[i] = d;\r\n\t\t}\r\n\r\n\t\t\
    q.sign = a1.sign * b1.sign;\r\n\t\tr.sign = a1.sign;\r\n\t\tq.trim();\r\n\t\t\
    r.trim();\r\n\t\treturn {q, r / norm};\r\n\t}\r\n\r\n\tfriend BigInt sqrt(const\
    \ BigInt& a1) {\r\n\t\tBigInt a = a1;\r\n\t\twhile (a.z.empty() || a.z.size()\
    \ % 2 == 1)\r\n\t\t\ta.z.push_back(0);\r\n\r\n\t\tint n = a.z.size();\r\n\r\n\t\
    \tint firstDigit = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);\r\n\t\
    \tint norm = base / (firstDigit + 1);\r\n\t\ta *= norm;\r\n\t\ta *= norm;\r\n\t\
    \twhile (a.z.empty() || a.z.size() % 2 == 1)\r\n\t\t\ta.z.push_back(0);\r\n\r\n\
    \t\tBigInt r = (long long) a.z[n - 1] * base + a.z[n - 2];\r\n\t\tfirstDigit =\
    \ (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);\r\n\t\tint q = firstDigit;\r\
    \n\t\tBigInt res;\r\n\r\n\t\tfor (int j = n / 2 - 1; j >= 0; j--) {\r\n\t\t\t\
    for (;; --q) {\r\n\t\t\t\tBigInt r1 = (r - (res * 2 * base + q) * q) * base *\
    \ base +\r\n\t\t\t\t\t\t\t(j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 *\
    \ j - 2] : 0);\r\n\t\t\t\tif (r1 >= 0) {\r\n\t\t\t\t\tr = r1;\r\n\t\t\t\t\tbreak;\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tres *= base;\r\n\t\t\tres += q;\r\n\r\n\t\t\t\
    if (j > 0) {\r\n\t\t\t\tint d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size()\
    \ + 2] : 0;\r\n\t\t\t\tint d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size()\
    \ + 1] : 0;\r\n\t\t\t\tint d3 = res.z.size() < r.z.size() ? r.z[res.z.size()]\
    \ : 0;\r\n\t\t\t\tq = (int) (((long long) d1 * base * base + (long long) d2 *\
    \ base + d3) / (firstDigit * 2));\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tres.trim();\r\
    \n\t\treturn res / norm;\r\n\t}\r\n\r\n\tBigInt operator/(const BigInt& v) const\
    \ { return divmod(*this, v).first; }\r\n\r\n\tBigInt operator%(const BigInt& v)\
    \ const { return divmod(*this, v).second; }\r\n\r\n\tBigInt& operator/=(int v)\
    \ {\r\n\t\tif (v < 0) sign = -sign, v = -v;\r\n\t\tfor (int i = (int) z.size()\
    \ - 1, rem = 0; i >= 0; --i) {\r\n\t\t\tlong long cur = z[i] + rem * (long long)\
    \ base;\r\n\t\t\tz[i] = (int) (cur / v);\r\n\t\t\trem = (int) (cur % v);\r\n\t\
    \t}\r\n\t\ttrim();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBigInt operator/(int v)\
    \ const { return BigInt(*this) /= v; }\r\n\r\n\tint operator%(int v) const {\r\
    \n\t\tif (v < 0) v = -v;\r\n\t\tint m = 0;\r\n\t\tfor (int i = (int) z.size()\
    \ - 1; i >= 0; --i)\r\n\t\t\tm = (int) ((z[i] + m * (long long) base) % v);\r\n\
    \t\treturn m * sign;\r\n\t}\r\n\r\n\tBigInt& operator*=(const BigInt& v) { return\
    \ *this = *this * v; }\r\n\tBigInt& operator/=(const BigInt& v) { return *this\
    \ = *this / v; }\r\n\r\n\tbool operator<(const BigInt& v) const {\r\n\t\tif (sign\
    \ != v.sign)\r\n\t\t\treturn sign < v.sign;\r\n\t\tif (z.size() != v.z.size())\r\
    \n\t\t\treturn z.size() * sign < v.z.size() * v.sign;\r\n\t\tfor (int i = (int)\
    \ z.size() - 1; i >= 0; i--)\r\n\t\t\tif (z[i] != v.z[i])\r\n\t\t\t\treturn z[i]\
    \ * sign < v.z[i] * sign;\r\n\t\treturn false;\r\n\t}\r\n\r\n\tbool operator>(const\
    \ BigInt& v) const { return v < *this; }\r\n\tbool operator<=(const BigInt& v)\
    \ const { return !(v < *this); }\r\n\tbool operator>=(const BigInt& v) const {\
    \ return !(*this < v); }\r\n\tbool operator==(const BigInt& v) const { return\
    \ !(*this < v) && !(v < *this); }\r\n\tbool operator!=(const BigInt& v) const\
    \ { return *this < v || v < *this; }\r\n\r\n\tvoid trim() {\r\n\t\twhile (!z.empty()\
    \ && z.back() == 0) z.pop_back();\r\n\t\tif (z.empty()) sign = 1;\r\n\t}\r\n\r\
    \n\tbool is_zero() const { return z.empty(); }\r\n\r\n\tfriend BigInt operator-(BigInt\
    \ v) {\r\n\t\tif (!v.z.empty()) v.sign = -v.sign;\r\n\t\treturn v;\r\n\t}\r\n\r\
    \n\tBigInt abs() const { return sign == 1 ? *this : -*this; }\r\n\r\n\tlong long\
    \ longValue() const {\r\n\t\tlong long res = 0;\r\n\t\tfor (int i = (int) z.size()\
    \ - 1; i >= 0; i--)\r\n\t\t\tres = res * base + z[i];\r\n\t\treturn res * sign;\r\
    \n\t}\r\n\r\n\tfriend BigInt gcd(const BigInt& a, const BigInt& b) {\r\n\t\treturn\
    \ b.is_zero() ? a : gcd(b, a % b);\r\n\t}\r\n\r\n\tfriend BigInt lcm(const BigInt&\
    \ a, const BigInt& b) {\r\n\t\treturn a / gcd(a, b) * b;\r\n\t}\r\n\r\n\tvoid\
    \ read(const std::string& s) {\r\n\t\tsign = 1;\r\n\t\tz.clear();\r\n\t\tint pos\
    \ = 0;\r\n\t\twhile (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {\r\n\
    \t\t\tif (s[pos] == '-')\r\n\t\t\t\tsign = -sign;\r\n\t\t\t++pos;\r\n\t\t}\r\n\
    \t\tfor (int i = (int) s.size() - 1; i >= pos; i -= base_digits) {\r\n\t\t\tint\
    \ x = 0;\r\n\t\t\tfor (int j = std::max(pos, i - base_digits + 1); j <= i; j++)\r\
    \n\t\t\t\tx = x * 10 + s[j] - '0';\r\n\t\t\tz.push_back(x);\r\n\t\t}\r\n\t\ttrim();\r\
    \n\t}\r\n\r\n\tfriend std::istream& operator>>(std::istream& stream, BigInt& v)\
    \ {\r\n\t\tstd::string s; stream >> s;\r\n\t\tv.read(s);\r\n\t\treturn stream;\r\
    \n\t}\r\n\r\n\tfriend std::ostream& operator<<(std::ostream& stream, const BigInt&\
    \ v) {\r\n\t\tif (v.sign == -1)\r\n\t\t\tstream << '-';\r\n\t\tstream << (v.z.empty()\
    \ ? 0 : v.z.back());\r\n\t\tfor (int i = (int) v.z.size() - 2; i >= 0; --i)\r\n\
    \t\t\tstream << std::setw(base_digits) << std::setfill('0') << v.z[i];\r\n\t\t\
    return stream;\r\n\t}\r\n\r\n\tstatic std::vector<int> convert_base(const std::vector<int>&\
    \ a, int old_digits, int new_digits) {\r\n\t\tstd::vector<long long> p(std::max(old_digits,\
    \ new_digits) + 1);\r\n\t\tp[0] = 1;\r\n\t\tfor (int i = 1; i < p.size(); i++)\r\
    \n\t\t\tp[i] = p[i - 1] * 10;\r\n\t\tstd::vector<int> res;\r\n\t\tlong long cur\
    \ = 0;\r\n\t\tint cur_digits = 0;\r\n\t\tfor (int v : a) {\r\n\t\t\tcur += v *\
    \ p[cur_digits];\r\n\t\t\tcur_digits += old_digits;\r\n\t\t\twhile (cur_digits\
    \ >= new_digits) {\r\n\t\t\t\tres.push_back(int(cur % p[new_digits]));\r\n\t\t\
    \t\tcur /= p[new_digits];\r\n\t\t\t\tcur_digits -= new_digits;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\tres.push_back((int) cur);\r\n\t\twhile (!res.empty() && res.back()\
    \ == 0)\r\n\t\t\tres.pop_back();\r\n\t\treturn res;\r\n\t}\r\n\r\n\tstatic std::vector<long\
    \ long> karatsubaMultiply(const std::vector<long long>& a, const std::vector<long\
    \ long>& b) {\r\n\t\tint n = a.size();\r\n\t\tstd::vector<long long> res(n + n);\r\
    \n\t\tif (n <= 32) {\r\n\t\t\tfor (int i = 0; i < n; i++)\r\n\t\t\t\tfor (int\
    \ j = 0; j < n; j++)\r\n\t\t\t\t\tres[i + j] += a[i] * b[j];\r\n\t\t\treturn res;\r\
    \n\t\t}\r\n\r\n\t\tint k = n >> 1;\r\n\t\tstd::vector<long long> a1(a.begin(),\
    \ a.begin() + k);\r\n\t\tstd::vector<long long> a2(a.begin() + k, a.end());\r\n\
    \t\tstd::vector<long long> b1(b.begin(), b.begin() + k);\r\n\t\tstd::vector<long\
    \ long> b2(b.begin() + k, b.end());\r\n\r\n\t\tstd::vector<long long> a1b1 = karatsubaMultiply(a1,\
    \ b1);\r\n\t\tstd::vector<long long> a2b2 = karatsubaMultiply(a2, b2);\r\n\r\n\
    \t\tfor (int i = 0; i < k; i++)\r\n\t\t\ta2[i] += a1[i];\r\n\t\tfor (int i = 0;\
    \ i < k; i++)\r\n\t\t\tb2[i] += b1[i];\r\n\r\n\t\tstd::vector<long long> r = karatsubaMultiply(a2,\
    \ b2);\r\n\t\tfor (int i = 0; i < a1b1.size(); i++)\r\n\t\t\tr[i] -= a1b1[i];\r\
    \n\t\tfor (int i = 0; i < a2b2.size(); i++)\r\n\t\t\tr[i] -= a2b2[i];\r\n\r\n\t\
    \tfor (int i = 0; i < r.size(); i++)\r\n\t\t\tres[i + k] += r[i];\r\n\t\tfor (int\
    \ i = 0; i < a1b1.size(); i++)\r\n\t\t\tres[i] += a1b1[i];\r\n\t\tfor (int i =\
    \ 0; i < a2b2.size(); i++)\r\n\t\t\tres[i + n] += a2b2[i];\r\n\t\treturn res;\r\
    \n\t}\r\n\r\n\tBigInt operator*(const BigInt& v) const {\r\n\t\tstd::vector<int>\
    \ a6 = convert_base(this->z, base_digits, 6);\r\n\t\tstd::vector<int> b6 = convert_base(v.z,\
    \ base_digits, 6);\r\n\t\tstd::vector<long long> a(a6.begin(), a6.end());\r\n\t\
    \tstd::vector<long long> b(b6.begin(), b6.end());\r\n\t\twhile (a.size() < b.size())\r\
    \n\t\t\ta.push_back(0);\r\n\t\twhile (b.size() < a.size())\r\n\t\t\tb.push_back(0);\r\
    \n\t\twhile (a.size() & (a.size() - 1))\r\n\t\t\ta.push_back(0), b.push_back(0);\r\
    \n\t\tstd::vector<long long> c = karatsubaMultiply(a, b);\r\n\t\tBigInt res;\r\
    \n\t\tres.sign = sign * v.sign;\r\n\t\tfor (int i = 0, carry = 0; i < c.size();\
    \ i++) {\r\n\t\t\tlong long cur = c[i] + carry;\r\n\t\t\tres.z.push_back((int)\
    \ (cur % 1000000));\r\n\t\t\tcarry = (int) (cur / 1000000);\r\n\t\t}\r\n\t\tres.z\
    \ = convert_base(res.z, 6, base_digits);\r\n\t\tres.trim();\r\n\t\treturn res;\r\
    \n\t}\r\n};\r\n\r\nBigInt random_big_int(int n) {\r\n\tstd::string s;\r\n\tfor\
    \ (int i = 0; i < n; i++) {\r\n\t\ts += rand() % 10 + '0';\r\n\t}\r\n\treturn\
    \ BigInt(s);\r\n}\n"
  code: "#pragma once\r\n\r\n// base and base_digits must be consistent\r\nconstexpr\
    \ int base = 1000000000;\r\nconstexpr int base_digits = 9;\r\n\r\nstruct BigInt\
    \ {\r\n\t// value == 0 is represented by empty z\r\n\tstd::vector<int> z; // digits\r\
    \n\r\n\t// sign == 1 <==> value >= 0\r\n\t// sign == -1 <==> value < 0\r\n\tint\
    \ sign;\r\n\r\n\tBigInt() : sign(1) {}\r\n\tBigInt(long long v) { *this = v; }\r\
    \n\r\n\tBigInt& operator=(long long v) {\r\n\t\tsign = v < 0 ? -1 : 1; v *= sign;\r\
    \n\t\tz.clear(); for (; v > 0; v = v / base) z.push_back((int) (v % base));\r\n\
    \t\treturn *this;\r\n\t}\r\n\r\n\tBigInt(const std::string& s) { read(s); }\r\n\
    \r\n\tBigInt& operator+=(const BigInt& other) {\r\n\t\tif (sign == other.sign)\
    \ {\r\n\t\t\tfor (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {\r\n\
    \t\t\t\tif (i == z.size())\r\n\t\t\t\t\tz.push_back(0);\r\n\t\t\t\tz[i] += carry\
    \ + (i < other.z.size() ? other.z[i] : 0);\r\n\t\t\t\tcarry = z[i] >= base;\r\n\
    \t\t\t\tif (carry)\r\n\t\t\t\t\tz[i] -= base;\r\n\t\t\t}\r\n\t\t} else if (other\
    \ != 0 /* prevent infinite loop */) {\r\n\t\t\t*this -= -other;\r\n\t\t}\r\n\t\
    \treturn *this;\r\n\t}\r\n\r\n\tfriend BigInt operator+(BigInt a, const BigInt&\
    \ b) { return a += b; }\r\n\r\n\tBigInt& operator-=(const BigInt& other) {\r\n\
    \t\tif (sign == other.sign) {\r\n\t\t\tif (sign == 1 && *this >= other || sign\
    \ == -1 && *this <= other) {\r\n\t\t\t\tfor (int i = 0, carry = 0; i < other.z.size()\
    \ || carry; ++i) {\r\n\t\t\t\t\tz[i] -= carry + (i < other.z.size() ? other.z[i]\
    \ : 0);\r\n\t\t\t\t\tcarry = z[i] < 0;\r\n\t\t\t\t\tif (carry)\r\n\t\t\t\t\t\t\
    z[i] += base;\r\n\t\t\t\t}\r\n\t\t\t\ttrim();\r\n\t\t\t} else {\r\n\t\t\t\t*this\
    \ = other - *this;\r\n\t\t\t\tthis->sign = -this->sign;\r\n\t\t\t}\r\n\t\t} else\
    \ {\r\n\t\t\t*this += -other;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tfriend\
    \ BigInt operator-(BigInt a, const BigInt& b) { return a -= b; }\r\n\r\n\tBigInt&\
    \ operator*=(int v) {\r\n\t\tif (v < 0) sign = -sign, v = -v;\r\n\t\tfor (int\
    \ i = 0, carry = 0; i < z.size() || carry; ++i) {\r\n\t\t\tif (i == z.size())\r\
    \n\t\t\t\tz.push_back(0);\r\n\t\t\tlong long cur = (long long) z[i] * v + carry;\r\
    \n\t\t\tcarry = (int) (cur / base);\r\n\t\t\tz[i] = (int) (cur % base);\r\n\t\t\
    }\r\n\t\ttrim();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBigInt operator*(int v)\
    \ const { return BigInt(*this) *= v; }\r\n\r\n\tfriend std::pair<BigInt, BigInt>\
    \ divmod(const BigInt& a1, const BigInt& b1) {\r\n\t\tint norm = base / (b1.z.back()\
    \ + 1);\r\n\t\tBigInt a = a1.abs() * norm;\r\n\t\tBigInt b = b1.abs() * norm;\r\
    \n\t\tBigInt q, r;\r\n\t\tq.z.resize(a.z.size());\r\n\r\n\t\tfor (int i = (int)\
    \ a.z.size() - 1; i >= 0; i--) {\r\n\t\t\tr *= base;\r\n\t\t\tr += a.z[i];\r\n\
    \t\t\tint s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;\r\n\t\t\tint s2\
    \ = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;\r\n\t\t\tint d = (int)\
    \ (((long long) s1 * base + s2) / b.z.back());\r\n\t\t\tr -= b * d;\r\n\t\t\t\
    while (r < 0)\r\n\t\t\t\tr += b, --d;\r\n\t\t\tq.z[i] = d;\r\n\t\t}\r\n\r\n\t\t\
    q.sign = a1.sign * b1.sign;\r\n\t\tr.sign = a1.sign;\r\n\t\tq.trim();\r\n\t\t\
    r.trim();\r\n\t\treturn {q, r / norm};\r\n\t}\r\n\r\n\tfriend BigInt sqrt(const\
    \ BigInt& a1) {\r\n\t\tBigInt a = a1;\r\n\t\twhile (a.z.empty() || a.z.size()\
    \ % 2 == 1)\r\n\t\t\ta.z.push_back(0);\r\n\r\n\t\tint n = a.z.size();\r\n\r\n\t\
    \tint firstDigit = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);\r\n\t\
    \tint norm = base / (firstDigit + 1);\r\n\t\ta *= norm;\r\n\t\ta *= norm;\r\n\t\
    \twhile (a.z.empty() || a.z.size() % 2 == 1)\r\n\t\t\ta.z.push_back(0);\r\n\r\n\
    \t\tBigInt r = (long long) a.z[n - 1] * base + a.z[n - 2];\r\n\t\tfirstDigit =\
    \ (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);\r\n\t\tint q = firstDigit;\r\
    \n\t\tBigInt res;\r\n\r\n\t\tfor (int j = n / 2 - 1; j >= 0; j--) {\r\n\t\t\t\
    for (;; --q) {\r\n\t\t\t\tBigInt r1 = (r - (res * 2 * base + q) * q) * base *\
    \ base +\r\n\t\t\t\t\t\t\t(j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 *\
    \ j - 2] : 0);\r\n\t\t\t\tif (r1 >= 0) {\r\n\t\t\t\t\tr = r1;\r\n\t\t\t\t\tbreak;\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tres *= base;\r\n\t\t\tres += q;\r\n\r\n\t\t\t\
    if (j > 0) {\r\n\t\t\t\tint d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size()\
    \ + 2] : 0;\r\n\t\t\t\tint d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size()\
    \ + 1] : 0;\r\n\t\t\t\tint d3 = res.z.size() < r.z.size() ? r.z[res.z.size()]\
    \ : 0;\r\n\t\t\t\tq = (int) (((long long) d1 * base * base + (long long) d2 *\
    \ base + d3) / (firstDigit * 2));\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tres.trim();\r\
    \n\t\treturn res / norm;\r\n\t}\r\n\r\n\tBigInt operator/(const BigInt& v) const\
    \ { return divmod(*this, v).first; }\r\n\r\n\tBigInt operator%(const BigInt& v)\
    \ const { return divmod(*this, v).second; }\r\n\r\n\tBigInt& operator/=(int v)\
    \ {\r\n\t\tif (v < 0) sign = -sign, v = -v;\r\n\t\tfor (int i = (int) z.size()\
    \ - 1, rem = 0; i >= 0; --i) {\r\n\t\t\tlong long cur = z[i] + rem * (long long)\
    \ base;\r\n\t\t\tz[i] = (int) (cur / v);\r\n\t\t\trem = (int) (cur % v);\r\n\t\
    \t}\r\n\t\ttrim();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBigInt operator/(int v)\
    \ const { return BigInt(*this) /= v; }\r\n\r\n\tint operator%(int v) const {\r\
    \n\t\tif (v < 0) v = -v;\r\n\t\tint m = 0;\r\n\t\tfor (int i = (int) z.size()\
    \ - 1; i >= 0; --i)\r\n\t\t\tm = (int) ((z[i] + m * (long long) base) % v);\r\n\
    \t\treturn m * sign;\r\n\t}\r\n\r\n\tBigInt& operator*=(const BigInt& v) { return\
    \ *this = *this * v; }\r\n\tBigInt& operator/=(const BigInt& v) { return *this\
    \ = *this / v; }\r\n\r\n\tbool operator<(const BigInt& v) const {\r\n\t\tif (sign\
    \ != v.sign)\r\n\t\t\treturn sign < v.sign;\r\n\t\tif (z.size() != v.z.size())\r\
    \n\t\t\treturn z.size() * sign < v.z.size() * v.sign;\r\n\t\tfor (int i = (int)\
    \ z.size() - 1; i >= 0; i--)\r\n\t\t\tif (z[i] != v.z[i])\r\n\t\t\t\treturn z[i]\
    \ * sign < v.z[i] * sign;\r\n\t\treturn false;\r\n\t}\r\n\r\n\tbool operator>(const\
    \ BigInt& v) const { return v < *this; }\r\n\tbool operator<=(const BigInt& v)\
    \ const { return !(v < *this); }\r\n\tbool operator>=(const BigInt& v) const {\
    \ return !(*this < v); }\r\n\tbool operator==(const BigInt& v) const { return\
    \ !(*this < v) && !(v < *this); }\r\n\tbool operator!=(const BigInt& v) const\
    \ { return *this < v || v < *this; }\r\n\r\n\tvoid trim() {\r\n\t\twhile (!z.empty()\
    \ && z.back() == 0) z.pop_back();\r\n\t\tif (z.empty()) sign = 1;\r\n\t}\r\n\r\
    \n\tbool is_zero() const { return z.empty(); }\r\n\r\n\tfriend BigInt operator-(BigInt\
    \ v) {\r\n\t\tif (!v.z.empty()) v.sign = -v.sign;\r\n\t\treturn v;\r\n\t}\r\n\r\
    \n\tBigInt abs() const { return sign == 1 ? *this : -*this; }\r\n\r\n\tlong long\
    \ longValue() const {\r\n\t\tlong long res = 0;\r\n\t\tfor (int i = (int) z.size()\
    \ - 1; i >= 0; i--)\r\n\t\t\tres = res * base + z[i];\r\n\t\treturn res * sign;\r\
    \n\t}\r\n\r\n\tfriend BigInt gcd(const BigInt& a, const BigInt& b) {\r\n\t\treturn\
    \ b.is_zero() ? a : gcd(b, a % b);\r\n\t}\r\n\r\n\tfriend BigInt lcm(const BigInt&\
    \ a, const BigInt& b) {\r\n\t\treturn a / gcd(a, b) * b;\r\n\t}\r\n\r\n\tvoid\
    \ read(const std::string& s) {\r\n\t\tsign = 1;\r\n\t\tz.clear();\r\n\t\tint pos\
    \ = 0;\r\n\t\twhile (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {\r\n\
    \t\t\tif (s[pos] == '-')\r\n\t\t\t\tsign = -sign;\r\n\t\t\t++pos;\r\n\t\t}\r\n\
    \t\tfor (int i = (int) s.size() - 1; i >= pos; i -= base_digits) {\r\n\t\t\tint\
    \ x = 0;\r\n\t\t\tfor (int j = std::max(pos, i - base_digits + 1); j <= i; j++)\r\
    \n\t\t\t\tx = x * 10 + s[j] - '0';\r\n\t\t\tz.push_back(x);\r\n\t\t}\r\n\t\ttrim();\r\
    \n\t}\r\n\r\n\tfriend std::istream& operator>>(std::istream& stream, BigInt& v)\
    \ {\r\n\t\tstd::string s; stream >> s;\r\n\t\tv.read(s);\r\n\t\treturn stream;\r\
    \n\t}\r\n\r\n\tfriend std::ostream& operator<<(std::ostream& stream, const BigInt&\
    \ v) {\r\n\t\tif (v.sign == -1)\r\n\t\t\tstream << '-';\r\n\t\tstream << (v.z.empty()\
    \ ? 0 : v.z.back());\r\n\t\tfor (int i = (int) v.z.size() - 2; i >= 0; --i)\r\n\
    \t\t\tstream << std::setw(base_digits) << std::setfill('0') << v.z[i];\r\n\t\t\
    return stream;\r\n\t}\r\n\r\n\tstatic std::vector<int> convert_base(const std::vector<int>&\
    \ a, int old_digits, int new_digits) {\r\n\t\tstd::vector<long long> p(std::max(old_digits,\
    \ new_digits) + 1);\r\n\t\tp[0] = 1;\r\n\t\tfor (int i = 1; i < p.size(); i++)\r\
    \n\t\t\tp[i] = p[i - 1] * 10;\r\n\t\tstd::vector<int> res;\r\n\t\tlong long cur\
    \ = 0;\r\n\t\tint cur_digits = 0;\r\n\t\tfor (int v : a) {\r\n\t\t\tcur += v *\
    \ p[cur_digits];\r\n\t\t\tcur_digits += old_digits;\r\n\t\t\twhile (cur_digits\
    \ >= new_digits) {\r\n\t\t\t\tres.push_back(int(cur % p[new_digits]));\r\n\t\t\
    \t\tcur /= p[new_digits];\r\n\t\t\t\tcur_digits -= new_digits;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\tres.push_back((int) cur);\r\n\t\twhile (!res.empty() && res.back()\
    \ == 0)\r\n\t\t\tres.pop_back();\r\n\t\treturn res;\r\n\t}\r\n\r\n\tstatic std::vector<long\
    \ long> karatsubaMultiply(const std::vector<long long>& a, const std::vector<long\
    \ long>& b) {\r\n\t\tint n = a.size();\r\n\t\tstd::vector<long long> res(n + n);\r\
    \n\t\tif (n <= 32) {\r\n\t\t\tfor (int i = 0; i < n; i++)\r\n\t\t\t\tfor (int\
    \ j = 0; j < n; j++)\r\n\t\t\t\t\tres[i + j] += a[i] * b[j];\r\n\t\t\treturn res;\r\
    \n\t\t}\r\n\r\n\t\tint k = n >> 1;\r\n\t\tstd::vector<long long> a1(a.begin(),\
    \ a.begin() + k);\r\n\t\tstd::vector<long long> a2(a.begin() + k, a.end());\r\n\
    \t\tstd::vector<long long> b1(b.begin(), b.begin() + k);\r\n\t\tstd::vector<long\
    \ long> b2(b.begin() + k, b.end());\r\n\r\n\t\tstd::vector<long long> a1b1 = karatsubaMultiply(a1,\
    \ b1);\r\n\t\tstd::vector<long long> a2b2 = karatsubaMultiply(a2, b2);\r\n\r\n\
    \t\tfor (int i = 0; i < k; i++)\r\n\t\t\ta2[i] += a1[i];\r\n\t\tfor (int i = 0;\
    \ i < k; i++)\r\n\t\t\tb2[i] += b1[i];\r\n\r\n\t\tstd::vector<long long> r = karatsubaMultiply(a2,\
    \ b2);\r\n\t\tfor (int i = 0; i < a1b1.size(); i++)\r\n\t\t\tr[i] -= a1b1[i];\r\
    \n\t\tfor (int i = 0; i < a2b2.size(); i++)\r\n\t\t\tr[i] -= a2b2[i];\r\n\r\n\t\
    \tfor (int i = 0; i < r.size(); i++)\r\n\t\t\tres[i + k] += r[i];\r\n\t\tfor (int\
    \ i = 0; i < a1b1.size(); i++)\r\n\t\t\tres[i] += a1b1[i];\r\n\t\tfor (int i =\
    \ 0; i < a2b2.size(); i++)\r\n\t\t\tres[i + n] += a2b2[i];\r\n\t\treturn res;\r\
    \n\t}\r\n\r\n\tBigInt operator*(const BigInt& v) const {\r\n\t\tstd::vector<int>\
    \ a6 = convert_base(this->z, base_digits, 6);\r\n\t\tstd::vector<int> b6 = convert_base(v.z,\
    \ base_digits, 6);\r\n\t\tstd::vector<long long> a(a6.begin(), a6.end());\r\n\t\
    \tstd::vector<long long> b(b6.begin(), b6.end());\r\n\t\twhile (a.size() < b.size())\r\
    \n\t\t\ta.push_back(0);\r\n\t\twhile (b.size() < a.size())\r\n\t\t\tb.push_back(0);\r\
    \n\t\twhile (a.size() & (a.size() - 1))\r\n\t\t\ta.push_back(0), b.push_back(0);\r\
    \n\t\tstd::vector<long long> c = karatsubaMultiply(a, b);\r\n\t\tBigInt res;\r\
    \n\t\tres.sign = sign * v.sign;\r\n\t\tfor (int i = 0, carry = 0; i < c.size();\
    \ i++) {\r\n\t\t\tlong long cur = c[i] + carry;\r\n\t\t\tres.z.push_back((int)\
    \ (cur % 1000000));\r\n\t\t\tcarry = (int) (cur / 1000000);\r\n\t\t}\r\n\t\tres.z\
    \ = convert_base(res.z, 6, base_digits);\r\n\t\tres.trim();\r\n\t\treturn res;\r\
    \n\t}\r\n};\r\n\r\nBigInt random_big_int(int n) {\r\n\tstd::string s;\r\n\tfor\
    \ (int i = 0; i < n; i++) {\r\n\t\ts += rand() % 10 + '0';\r\n\t}\r\n\treturn\
    \ BigInt(s);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/big-integer.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit-test/unit-test-big-integer.test.cpp
documentation_of: library/numerical/big-integer.hpp
layout: document
title: Big Integer
---

## Big Integer

A struct for big integer. 

### Resources
- [indy256](https://github.com/indy256/codelibrary/)
- [Benq](https://github.com/bqi343/USACO/search?q=big+int)

