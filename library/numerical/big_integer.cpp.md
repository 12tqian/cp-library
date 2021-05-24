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
    \            blob/master/cpp/numbertheory/BigInt.cpp\n * Verification: https://oj.uz/problem/view/IOI11_parrots\n\
    \ */\n\n// base and base_digits must be consistent\nconstexpr int base = 1000000000;\n\
    constexpr int base_digits = 9;\n\nstruct BigInt {\n    // value == 0 is represented\
    \ by empty z\n    std::vector<int> z; // digits\n\n    // sign == 1 <==> value\
    \ >= 0\n    // sign == -1 <==> value < 0\n    int sign;\n\n    BigInt() : sign(1)\
    \ {}\n    BigInt(long long v) { *this = v; }\n\n    BigInt &operator=(long long\
    \ v) {\n        sign = v < 0 ? -1 : 1; v *= sign;\n        z.clear(); for (; v\
    \ > 0; v = v / base) z.push_back((int) (v % base));\n        return *this;\n \
    \   }\n\n    BigInt(const std::string &s) { read(s); }\n\n    BigInt &operator+=(const\
    \ BigInt &other) {\n        if (sign == other.sign) {\n            for (int i\
    \ = 0, carry = 0; i < other.z.size() || carry; ++i) {\n                if (i ==\
    \ z.size())\n                    z.push_back(0);\n                z[i] += carry\
    \ + (i < other.z.size() ? other.z[i] : 0);\n                carry = z[i] >= base;\n\
    \                if (carry)\n                    z[i] -= base;\n            }\n\
    \        } else if (other != 0 /* prevent infinite loop */) {\n            *this\
    \ -= -other;\n        }\n        return *this;\n    }\n\n    friend BigInt operator+(BigInt\
    \ a, const BigInt &b) { return a += b; }\n\n    BigInt &operator-=(const BigInt\
    \ &other) {\n        if (sign == other.sign) {\n            if (sign == 1 && *this\
    \ >= other || sign == -1 && *this <= other) {\n                for (int i = 0,\
    \ carry = 0; i < other.z.size() || carry; ++i) {\n                    z[i] -=\
    \ carry + (i < other.z.size() ? other.z[i] : 0);\n                    carry =\
    \ z[i] < 0;\n                    if (carry)\n                        z[i] += base;\n\
    \                }\n                trim();\n            } else {\n          \
    \      *this = other - *this;\n                this->sign = -this->sign;\n   \
    \         }\n        } else {\n            *this += -other;\n        }\n     \
    \   return *this;\n    }\n\n    friend BigInt operator-(BigInt a, const BigInt\
    \ &b) { return a -= b; }\n\n    BigInt &operator*=(int v) {\n        if (v < 0)\
    \ sign = -sign, v = -v;\n        for (int i = 0, carry = 0; i < z.size() || carry;\
    \ ++i) {\n            if (i == z.size())\n                z.push_back(0);\n  \
    \          long long cur = (long long) z[i] * v + carry;\n            carry =\
    \ (int) (cur / base);\n            z[i] = (int) (cur % base);\n        }\n   \
    \     trim();\n        return *this;\n    }\n\n    BigInt operator*(int v) const\
    \ { return BigInt(*this) *= v; }\n\n    friend std::pair<BigInt, BigInt> divmod(const\
    \ BigInt &a1, const BigInt &b1) {\n        int norm = base / (b1.z.back() + 1);\n\
    \        BigInt a = a1.abs() * norm;\n        BigInt b = b1.abs() * norm;\n  \
    \      BigInt q, r;\n        q.z.resize(a.z.size());\n\n        for (int i = (int)\
    \ a.z.size() - 1; i >= 0; i--) {\n            r *= base;\n            r += a.z[i];\n\
    \            int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;\n       \
    \     int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;\n      \
    \      int d = (int) (((long long) s1 * base + s2) / b.z.back());\n          \
    \  r -= b * d;\n            while (r < 0)\n                r += b, --d;\n    \
    \        q.z[i] = d;\n        }\n\n        q.sign = a1.sign * b1.sign;\n     \
    \   r.sign = a1.sign;\n        q.trim();\n        r.trim();\n        return {q,\
    \ r / norm};\n    }\n\n    friend BigInt sqrt(const BigInt &a1) {\n        BigInt\
    \ a = a1;\n        while (a.z.empty() || a.z.size() % 2 == 1)\n            a.z.push_back(0);\n\
    \n        int n = a.z.size();\n\n        int firstDigit = (int) ::sqrt((double)\
    \ a.z[n - 1] * base + a.z[n - 2]);\n        int norm = base / (firstDigit + 1);\n\
    \        a *= norm;\n        a *= norm;\n        while (a.z.empty() || a.z.size()\
    \ % 2 == 1)\n            a.z.push_back(0);\n\n        BigInt r = (long long) a.z[n\
    \ - 1] * base + a.z[n - 2];\n        firstDigit = (int) ::sqrt((double) a.z[n\
    \ - 1] * base + a.z[n - 2]);\n        int q = firstDigit;\n        BigInt res;\n\
    \n        for (int j = n / 2 - 1; j >= 0; j--) {\n            for (;; --q) {\n\
    \                BigInt r1 = (r - (res * 2 * base + q) * q) * base * base +\n\
    \                            (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2\
    \ * j - 2] : 0);\n                if (r1 >= 0) {\n                    r = r1;\n\
    \                    break;\n                }\n            }\n            res\
    \ *= base;\n            res += q;\n\n            if (j > 0) {\n              \
    \  int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;\n     \
    \           int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;\n\
    \                int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;\n\
    \                q = (int) (((long long) d1 * base * base + (long long) d2 * base\
    \ + d3) / (firstDigit * 2));\n            }\n        }\n\n        res.trim();\n\
    \        return res / norm;\n    }\n\n    BigInt operator/(const BigInt &v) const\
    \ { return divmod(*this, v).first; }\n\n    BigInt operator%(const BigInt &v)\
    \ const { return divmod(*this, v).second; }\n\n    BigInt &operator/=(int v) {\n\
    \        if (v < 0) sign = -sign, v = -v;\n        for (int i = (int) z.size()\
    \ - 1, rem = 0; i >= 0; --i) {\n            long long cur = z[i] + rem * (long\
    \ long) base;\n            z[i] = (int) (cur / v);\n            rem = (int) (cur\
    \ % v);\n        }\n        trim();\n        return *this;\n    }\n\n    BigInt\
    \ operator/(int v) const { return BigInt(*this) /= v; }\n\n    int operator%(int\
    \ v) const {\n        if (v < 0) v = -v;\n        int m = 0;\n        for (int\
    \ i = (int) z.size() - 1; i >= 0; --i)\n            m = (int) ((z[i] + m * (long\
    \ long) base) % v);\n        return m * sign;\n    }\n\n    BigInt &operator*=(const\
    \ BigInt &v) { return *this = *this * v; }\n    BigInt &operator/=(const BigInt\
    \ &v) { return *this = *this / v; }\n\n    bool operator<(const BigInt &v) const\
    \ {\n        if (sign != v.sign)\n            return sign < v.sign;\n        if\
    \ (z.size() != v.z.size())\n            return z.size() * sign < v.z.size() *\
    \ v.sign;\n        for (int i = (int) z.size() - 1; i >= 0; i--)\n           \
    \ if (z[i] != v.z[i])\n                return z[i] * sign < v.z[i] * sign;\n \
    \       return false;\n    }\n\n    bool operator>(const BigInt &v) const { return\
    \ v < *this; }\n    bool operator<=(const BigInt &v) const { return !(v < *this);\
    \ }\n    bool operator>=(const BigInt &v) const { return !(*this < v); }\n   \
    \ bool operator==(const BigInt &v) const { return !(*this < v) && !(v < *this);\
    \ }\n    bool operator!=(const BigInt &v) const { return *this < v || v < *this;\
    \ }\n\n    void trim() {\n        while (!z.empty() && z.back() == 0) z.pop_back();\n\
    \        if (z.empty()) sign = 1;\n    }\n\n    bool is_zero() const { return\
    \ z.empty(); }\n\n    friend BigInt operator-(BigInt v) {\n        if (!v.z.empty())\
    \ v.sign = -v.sign;\n        return v;\n    }\n\n    BigInt abs() const { return\
    \ sign == 1 ? *this : -*this; }\n\n    long long longValue() const {\n       \
    \ long long res = 0;\n        for (int i = (int) z.size() - 1; i >= 0; i--)\n\
    \            res = res * base + z[i];\n        return res * sign;\n    }\n\n \
    \   friend BigInt gcd(const BigInt &a, const BigInt &b) {\n        return b.is_zero()\
    \ ? a : gcd(b, a % b);\n    }\n\n    friend BigInt lcm(const BigInt &a, const\
    \ BigInt &b) {\n        return a / gcd(a, b) * b;\n    }\n\n    void read(const\
    \ std::string &s) {\n        sign = 1;\n        z.clear();\n        int pos =\
    \ 0;\n        while (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {\n \
    \           if (s[pos] == '-')\n                sign = -sign;\n            ++pos;\n\
    \        }\n        for (int i = (int) s.size() - 1; i >= pos; i -= base_digits)\
    \ {\n            int x = 0;\n            for (int j = std::max(pos, i - base_digits\
    \ + 1); j <= i; j++)\n                x = x * 10 + s[j] - '0';\n            z.push_back(x);\n\
    \        }\n        trim();\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &stream, BigInt &v) {\n        std::string s; stream >> s;\n        v.read(s);\n\
    \        return stream;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &stream, const BigInt &v) {\n        if (v.sign == -1)\n            stream <<\
    \ '-';\n        stream << (v.z.empty() ? 0 : v.z.back());\n        for (int i\
    \ = (int) v.z.size() - 2; i >= 0; --i)\n            stream << std::setw(base_digits)\
    \ << std::setfill('0') << v.z[i];\n        return stream;\n    }\n\n    static\
    \ std::vector<int> convert_base(const std::vector<int> &a, int old_digits, int\
    \ new_digits) {\n        std::vector<long long> p(std::max(old_digits, new_digits)\
    \ + 1);\n        p[0] = 1;\n        for (int i = 1; i < p.size(); i++)\n     \
    \       p[i] = p[i - 1] * 10;\n        std::vector<int> res;\n        long long\
    \ cur = 0;\n        int cur_digits = 0;\n        for (int v : a) {\n         \
    \   cur += v * p[cur_digits];\n            cur_digits += old_digits;\n       \
    \     while (cur_digits >= new_digits) {\n                res.push_back(int(cur\
    \ % p[new_digits]));\n                cur /= p[new_digits];\n                cur_digits\
    \ -= new_digits;\n            }\n        }\n        res.push_back((int) cur);\n\
    \        while (!res.empty() && res.back() == 0)\n            res.pop_back();\n\
    \        return res;\n    }\n\n    static std::vector<long long> karatsubaMultiply(const\
    \ std::vector<long long> &a, const std::vector<long long> &b) {\n        int n\
    \ = a.size();\n        std::vector<long long> res(n + n);\n        if (n <= 32)\
    \ {\n            for (int i = 0; i < n; i++)\n                for (int j = 0;\
    \ j < n; j++)\n                    res[i + j] += a[i] * b[j];\n            return\
    \ res;\n        }\n\n        int k = n >> 1;\n        std::vector<long long> a1(a.begin(),\
    \ a.begin() + k);\n        std::vector<long long> a2(a.begin() + k, a.end());\n\
    \        std::vector<long long> b1(b.begin(), b.begin() + k);\n        std::vector<long\
    \ long> b2(b.begin() + k, b.end());\n\n        std::vector<long long> a1b1 = karatsubaMultiply(a1,\
    \ b1);\n        std::vector<long long> a2b2 = karatsubaMultiply(a2, b2);\n\n \
    \       for (int i = 0; i < k; i++)\n            a2[i] += a1[i];\n        for\
    \ (int i = 0; i < k; i++)\n            b2[i] += b1[i];\n\n        std::vector<long\
    \ long> r = karatsubaMultiply(a2, b2);\n        for (int i = 0; i < a1b1.size();\
    \ i++)\n            r[i] -= a1b1[i];\n        for (int i = 0; i < a2b2.size();\
    \ i++)\n            r[i] -= a2b2[i];\n\n        for (int i = 0; i < r.size();\
    \ i++)\n            res[i + k] += r[i];\n        for (int i = 0; i < a1b1.size();\
    \ i++)\n            res[i] += a1b1[i];\n        for (int i = 0; i < a2b2.size();\
    \ i++)\n            res[i + n] += a2b2[i];\n        return res;\n    }\n\n   \
    \ BigInt operator*(const BigInt &v) const {\n        std::vector<int> a6 = convert_base(this->z,\
    \ base_digits, 6);\n        std::vector<int> b6 = convert_base(v.z, base_digits,\
    \ 6);\n        std::vector<long long> a(a6.begin(), a6.end());\n        std::vector<long\
    \ long> b(b6.begin(), b6.end());\n        while (a.size() < b.size())\n      \
    \      a.push_back(0);\n        while (b.size() < a.size())\n            b.push_back(0);\n\
    \        while (a.size() & (a.size() - 1))\n            a.push_back(0), b.push_back(0);\n\
    \        std::vector<long long> c = karatsubaMultiply(a, b);\n        BigInt res;\n\
    \        res.sign = sign * v.sign;\n        for (int i = 0, carry = 0; i < c.size();\
    \ i++) {\n            long long cur = c[i] + carry;\n            res.z.push_back((int)\
    \ (cur % 1000000));\n            carry = (int) (cur / 1000000);\n        }\n \
    \       res.z = convert_base(res.z, 6, base_digits);\n        res.trim();\n  \
    \      return res;\n    }\n};\n\nBigInt random_big_int(int n) {\n    std::string\
    \ s;\n    for (int i = 0; i < n; i++) {\n        s += rand() % 10 + '0';\n   \
    \ }\n    return BigInt(s);\n}\n"
  code: "#include <bits/stdc++.h>\n/**\n * Description: Big Integer\n * Source: https://github.com/indy256/codelibrary/\n\
    \            blob/master/cpp/numbertheory/BigInt.cpp\n * Verification: https://oj.uz/problem/view/IOI11_parrots\n\
    \ */\n\n// base and base_digits must be consistent\nconstexpr int base = 1000000000;\n\
    constexpr int base_digits = 9;\n\nstruct BigInt {\n    // value == 0 is represented\
    \ by empty z\n    std::vector<int> z; // digits\n\n    // sign == 1 <==> value\
    \ >= 0\n    // sign == -1 <==> value < 0\n    int sign;\n\n    BigInt() : sign(1)\
    \ {}\n    BigInt(long long v) { *this = v; }\n\n    BigInt &operator=(long long\
    \ v) {\n        sign = v < 0 ? -1 : 1; v *= sign;\n        z.clear(); for (; v\
    \ > 0; v = v / base) z.push_back((int) (v % base));\n        return *this;\n \
    \   }\n\n    BigInt(const std::string &s) { read(s); }\n\n    BigInt &operator+=(const\
    \ BigInt &other) {\n        if (sign == other.sign) {\n            for (int i\
    \ = 0, carry = 0; i < other.z.size() || carry; ++i) {\n                if (i ==\
    \ z.size())\n                    z.push_back(0);\n                z[i] += carry\
    \ + (i < other.z.size() ? other.z[i] : 0);\n                carry = z[i] >= base;\n\
    \                if (carry)\n                    z[i] -= base;\n            }\n\
    \        } else if (other != 0 /* prevent infinite loop */) {\n            *this\
    \ -= -other;\n        }\n        return *this;\n    }\n\n    friend BigInt operator+(BigInt\
    \ a, const BigInt &b) { return a += b; }\n\n    BigInt &operator-=(const BigInt\
    \ &other) {\n        if (sign == other.sign) {\n            if (sign == 1 && *this\
    \ >= other || sign == -1 && *this <= other) {\n                for (int i = 0,\
    \ carry = 0; i < other.z.size() || carry; ++i) {\n                    z[i] -=\
    \ carry + (i < other.z.size() ? other.z[i] : 0);\n                    carry =\
    \ z[i] < 0;\n                    if (carry)\n                        z[i] += base;\n\
    \                }\n                trim();\n            } else {\n          \
    \      *this = other - *this;\n                this->sign = -this->sign;\n   \
    \         }\n        } else {\n            *this += -other;\n        }\n     \
    \   return *this;\n    }\n\n    friend BigInt operator-(BigInt a, const BigInt\
    \ &b) { return a -= b; }\n\n    BigInt &operator*=(int v) {\n        if (v < 0)\
    \ sign = -sign, v = -v;\n        for (int i = 0, carry = 0; i < z.size() || carry;\
    \ ++i) {\n            if (i == z.size())\n                z.push_back(0);\n  \
    \          long long cur = (long long) z[i] * v + carry;\n            carry =\
    \ (int) (cur / base);\n            z[i] = (int) (cur % base);\n        }\n   \
    \     trim();\n        return *this;\n    }\n\n    BigInt operator*(int v) const\
    \ { return BigInt(*this) *= v; }\n\n    friend std::pair<BigInt, BigInt> divmod(const\
    \ BigInt &a1, const BigInt &b1) {\n        int norm = base / (b1.z.back() + 1);\n\
    \        BigInt a = a1.abs() * norm;\n        BigInt b = b1.abs() * norm;\n  \
    \      BigInt q, r;\n        q.z.resize(a.z.size());\n\n        for (int i = (int)\
    \ a.z.size() - 1; i >= 0; i--) {\n            r *= base;\n            r += a.z[i];\n\
    \            int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;\n       \
    \     int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;\n      \
    \      int d = (int) (((long long) s1 * base + s2) / b.z.back());\n          \
    \  r -= b * d;\n            while (r < 0)\n                r += b, --d;\n    \
    \        q.z[i] = d;\n        }\n\n        q.sign = a1.sign * b1.sign;\n     \
    \   r.sign = a1.sign;\n        q.trim();\n        r.trim();\n        return {q,\
    \ r / norm};\n    }\n\n    friend BigInt sqrt(const BigInt &a1) {\n        BigInt\
    \ a = a1;\n        while (a.z.empty() || a.z.size() % 2 == 1)\n            a.z.push_back(0);\n\
    \n        int n = a.z.size();\n\n        int firstDigit = (int) ::sqrt((double)\
    \ a.z[n - 1] * base + a.z[n - 2]);\n        int norm = base / (firstDigit + 1);\n\
    \        a *= norm;\n        a *= norm;\n        while (a.z.empty() || a.z.size()\
    \ % 2 == 1)\n            a.z.push_back(0);\n\n        BigInt r = (long long) a.z[n\
    \ - 1] * base + a.z[n - 2];\n        firstDigit = (int) ::sqrt((double) a.z[n\
    \ - 1] * base + a.z[n - 2]);\n        int q = firstDigit;\n        BigInt res;\n\
    \n        for (int j = n / 2 - 1; j >= 0; j--) {\n            for (;; --q) {\n\
    \                BigInt r1 = (r - (res * 2 * base + q) * q) * base * base +\n\
    \                            (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2\
    \ * j - 2] : 0);\n                if (r1 >= 0) {\n                    r = r1;\n\
    \                    break;\n                }\n            }\n            res\
    \ *= base;\n            res += q;\n\n            if (j > 0) {\n              \
    \  int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;\n     \
    \           int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;\n\
    \                int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;\n\
    \                q = (int) (((long long) d1 * base * base + (long long) d2 * base\
    \ + d3) / (firstDigit * 2));\n            }\n        }\n\n        res.trim();\n\
    \        return res / norm;\n    }\n\n    BigInt operator/(const BigInt &v) const\
    \ { return divmod(*this, v).first; }\n\n    BigInt operator%(const BigInt &v)\
    \ const { return divmod(*this, v).second; }\n\n    BigInt &operator/=(int v) {\n\
    \        if (v < 0) sign = -sign, v = -v;\n        for (int i = (int) z.size()\
    \ - 1, rem = 0; i >= 0; --i) {\n            long long cur = z[i] + rem * (long\
    \ long) base;\n            z[i] = (int) (cur / v);\n            rem = (int) (cur\
    \ % v);\n        }\n        trim();\n        return *this;\n    }\n\n    BigInt\
    \ operator/(int v) const { return BigInt(*this) /= v; }\n\n    int operator%(int\
    \ v) const {\n        if (v < 0) v = -v;\n        int m = 0;\n        for (int\
    \ i = (int) z.size() - 1; i >= 0; --i)\n            m = (int) ((z[i] + m * (long\
    \ long) base) % v);\n        return m * sign;\n    }\n\n    BigInt &operator*=(const\
    \ BigInt &v) { return *this = *this * v; }\n    BigInt &operator/=(const BigInt\
    \ &v) { return *this = *this / v; }\n\n    bool operator<(const BigInt &v) const\
    \ {\n        if (sign != v.sign)\n            return sign < v.sign;\n        if\
    \ (z.size() != v.z.size())\n            return z.size() * sign < v.z.size() *\
    \ v.sign;\n        for (int i = (int) z.size() - 1; i >= 0; i--)\n           \
    \ if (z[i] != v.z[i])\n                return z[i] * sign < v.z[i] * sign;\n \
    \       return false;\n    }\n\n    bool operator>(const BigInt &v) const { return\
    \ v < *this; }\n    bool operator<=(const BigInt &v) const { return !(v < *this);\
    \ }\n    bool operator>=(const BigInt &v) const { return !(*this < v); }\n   \
    \ bool operator==(const BigInt &v) const { return !(*this < v) && !(v < *this);\
    \ }\n    bool operator!=(const BigInt &v) const { return *this < v || v < *this;\
    \ }\n\n    void trim() {\n        while (!z.empty() && z.back() == 0) z.pop_back();\n\
    \        if (z.empty()) sign = 1;\n    }\n\n    bool is_zero() const { return\
    \ z.empty(); }\n\n    friend BigInt operator-(BigInt v) {\n        if (!v.z.empty())\
    \ v.sign = -v.sign;\n        return v;\n    }\n\n    BigInt abs() const { return\
    \ sign == 1 ? *this : -*this; }\n\n    long long longValue() const {\n       \
    \ long long res = 0;\n        for (int i = (int) z.size() - 1; i >= 0; i--)\n\
    \            res = res * base + z[i];\n        return res * sign;\n    }\n\n \
    \   friend BigInt gcd(const BigInt &a, const BigInt &b) {\n        return b.is_zero()\
    \ ? a : gcd(b, a % b);\n    }\n\n    friend BigInt lcm(const BigInt &a, const\
    \ BigInt &b) {\n        return a / gcd(a, b) * b;\n    }\n\n    void read(const\
    \ std::string &s) {\n        sign = 1;\n        z.clear();\n        int pos =\
    \ 0;\n        while (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {\n \
    \           if (s[pos] == '-')\n                sign = -sign;\n            ++pos;\n\
    \        }\n        for (int i = (int) s.size() - 1; i >= pos; i -= base_digits)\
    \ {\n            int x = 0;\n            for (int j = std::max(pos, i - base_digits\
    \ + 1); j <= i; j++)\n                x = x * 10 + s[j] - '0';\n            z.push_back(x);\n\
    \        }\n        trim();\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &stream, BigInt &v) {\n        std::string s; stream >> s;\n        v.read(s);\n\
    \        return stream;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &stream, const BigInt &v) {\n        if (v.sign == -1)\n            stream <<\
    \ '-';\n        stream << (v.z.empty() ? 0 : v.z.back());\n        for (int i\
    \ = (int) v.z.size() - 2; i >= 0; --i)\n            stream << std::setw(base_digits)\
    \ << std::setfill('0') << v.z[i];\n        return stream;\n    }\n\n    static\
    \ std::vector<int> convert_base(const std::vector<int> &a, int old_digits, int\
    \ new_digits) {\n        std::vector<long long> p(std::max(old_digits, new_digits)\
    \ + 1);\n        p[0] = 1;\n        for (int i = 1; i < p.size(); i++)\n     \
    \       p[i] = p[i - 1] * 10;\n        std::vector<int> res;\n        long long\
    \ cur = 0;\n        int cur_digits = 0;\n        for (int v : a) {\n         \
    \   cur += v * p[cur_digits];\n            cur_digits += old_digits;\n       \
    \     while (cur_digits >= new_digits) {\n                res.push_back(int(cur\
    \ % p[new_digits]));\n                cur /= p[new_digits];\n                cur_digits\
    \ -= new_digits;\n            }\n        }\n        res.push_back((int) cur);\n\
    \        while (!res.empty() && res.back() == 0)\n            res.pop_back();\n\
    \        return res;\n    }\n\n    static std::vector<long long> karatsubaMultiply(const\
    \ std::vector<long long> &a, const std::vector<long long> &b) {\n        int n\
    \ = a.size();\n        std::vector<long long> res(n + n);\n        if (n <= 32)\
    \ {\n            for (int i = 0; i < n; i++)\n                for (int j = 0;\
    \ j < n; j++)\n                    res[i + j] += a[i] * b[j];\n            return\
    \ res;\n        }\n\n        int k = n >> 1;\n        std::vector<long long> a1(a.begin(),\
    \ a.begin() + k);\n        std::vector<long long> a2(a.begin() + k, a.end());\n\
    \        std::vector<long long> b1(b.begin(), b.begin() + k);\n        std::vector<long\
    \ long> b2(b.begin() + k, b.end());\n\n        std::vector<long long> a1b1 = karatsubaMultiply(a1,\
    \ b1);\n        std::vector<long long> a2b2 = karatsubaMultiply(a2, b2);\n\n \
    \       for (int i = 0; i < k; i++)\n            a2[i] += a1[i];\n        for\
    \ (int i = 0; i < k; i++)\n            b2[i] += b1[i];\n\n        std::vector<long\
    \ long> r = karatsubaMultiply(a2, b2);\n        for (int i = 0; i < a1b1.size();\
    \ i++)\n            r[i] -= a1b1[i];\n        for (int i = 0; i < a2b2.size();\
    \ i++)\n            r[i] -= a2b2[i];\n\n        for (int i = 0; i < r.size();\
    \ i++)\n            res[i + k] += r[i];\n        for (int i = 0; i < a1b1.size();\
    \ i++)\n            res[i] += a1b1[i];\n        for (int i = 0; i < a2b2.size();\
    \ i++)\n            res[i + n] += a2b2[i];\n        return res;\n    }\n\n   \
    \ BigInt operator*(const BigInt &v) const {\n        std::vector<int> a6 = convert_base(this->z,\
    \ base_digits, 6);\n        std::vector<int> b6 = convert_base(v.z, base_digits,\
    \ 6);\n        std::vector<long long> a(a6.begin(), a6.end());\n        std::vector<long\
    \ long> b(b6.begin(), b6.end());\n        while (a.size() < b.size())\n      \
    \      a.push_back(0);\n        while (b.size() < a.size())\n            b.push_back(0);\n\
    \        while (a.size() & (a.size() - 1))\n            a.push_back(0), b.push_back(0);\n\
    \        std::vector<long long> c = karatsubaMultiply(a, b);\n        BigInt res;\n\
    \        res.sign = sign * v.sign;\n        for (int i = 0, carry = 0; i < c.size();\
    \ i++) {\n            long long cur = c[i] + carry;\n            res.z.push_back((int)\
    \ (cur % 1000000));\n            carry = (int) (cur / 1000000);\n        }\n \
    \       res.z = convert_base(res.z, 6, base_digits);\n        res.trim();\n  \
    \      return res;\n    }\n};\n\nBigInt random_big_int(int n) {\n    std::string\
    \ s;\n    for (int i = 0; i < n; i++) {\n        s += rand() % 10 + '0';\n   \
    \ }\n    return BigInt(s);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/big_integer.cpp
  requiredBy: []
  timestamp: '2021-05-24 13:50:40-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/big_integer.cpp
layout: document
redirect_from:
- /library/library/numerical/big_integer.cpp
- /library/library/numerical/big_integer.cpp.html
title: library/numerical/big_integer.cpp
---
