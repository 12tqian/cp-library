---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/misc/easy-io.hpp
    title: library/misc/easy-io.hpp
  - icon: ':question:'
    path: library/misc/pragma-short.hpp
    title: library/misc/pragma-short.hpp
  - icon: ':question:'
    path: library/modular-arithmetic/mod-int.hpp
    title: library/modular-arithmetic/mod-int.hpp
  - icon: ':x:'
    path: library/numerical/big-integer.hpp
    title: Big Integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n\n\n\
    #pragma GCC optimize (\"O3\")\n#pragma GCC target (\"sse4\")\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n#include <deque>\n#include <iostream>\n#include\
    \ <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <unordered_map>\n#include <vector>\n\nusing namespace std;\n\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/pb_ds/assoc_container.hpp>\n\nusing namespace __gnu_pbds;\n\ntemplate\
    \ <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef double db;\ntypedef\
    \ string str;\n\ntypedef pair<int, int> pi;\ntypedef pair<ll, ll> pl;\ntypedef\
    \ pair<db, db> pd;\n\ntypedef vector<int> vi;\ntypedef vector<bool> vb;\ntypedef\
    \ vector<ll> vl;\ntypedef vector<db> vd;\ntypedef vector<str> vs;\ntypedef vector<pi>\
    \ vpi;\ntypedef vector<pl> vpl;\ntypedef vector<pd> vpd;\n\n#define mp make_pair\n\
    #define f first\n#define s second\n#define sz(x) (int)(x).size()\n#define all(x)\
    \ begin(x), end(x)\n#define rall(x) (x).rbegin(), (x).rend()\n#define sor(x) sort(all(x))\n\
    #define rsz resize\n#define resz resize\n#define ins insert\n#define ft front()\n\
    #define bk back()\n#define pf push_front\n#define pb push_back\n#define eb emplace_back\n\
    #define lb lower_bound\n#define ub upper_bound\n\n#define f1r(i, a, b) for (int\
    \ i = (a); i < (b); ++i)\n#define f0r(i, a) f1r(i, 0, a)\n#define FOR(i, a, b)\
    \ for (int i = (a); i < (b); ++i)\n#define F0R(i, a) FOR(i, 0, a)\n#define ROF(i,\
    \ a, b) for (int i = (b) - 1; i >= (a); --i)\n#define R0F(i, a) ROF(i, 0, a)\n\
    #define each(a, x) for (auto& a : x)\n\nmt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 :\
    \ 0; }\ntemplate <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b,\
    \ 1 : 0; }\n\ntemplate <class T> using V = vector<T>;\ntemplate <class T> using\
    \ VV = V<V<T>>;\ntemplate <class T> using VVV = V<V<V<T>>>;\ntemplate <class T>\
    \ using VVVV = V<V<V<V<T>>>>;\n\n#ifdef LOCAL\n#define dbg(...) debug(#__VA_ARGS__,\
    \ __VA_ARGS__);\n#else\n#define dbg(...) 17;\n#endif\n\ntemplate <typename T,\
    \ typename S> ostream& operator << (ostream& os, const pair<T, S>& p) { return\
    \ os << \"(\" << p.first << \", \" << p.second << \")\"; }\ntemplate <typename\
    \ C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C,\
    \ string>::value>::type* = nullptr>\nostream& operator << (ostream& os, const\
    \ C& c) { bool f = true; os << \"{\"; for (const auto& x : c) { if (!f) os <<\
    \ \", \"; f = false; os << x; } return os << \"}\"; }\ntemplate <typename T> void\
    \ debug(string s, T x) { cerr << s << \" = \" << x << \"\\n\"; }\ntemplate <typename\
    \ T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0,\
    \ s.find(',')) << \" = \" << x << \" | \"; debug(s.substr(s.find(',') + 2), args...);\
    \ }\n\nconstexpr int pct(int x) { return __builtin_popcount(x); }\nconstexpr int\
    \ bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))\n\ninline namespace\
    \ Helpers {\n\t//////////// is_iterable\n\t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
    \t// this gets used only when we can call begin() and end() on that type\n\ttemplate\
    \ <class T, class = void> struct is_iterable : false_type {};\n\ttemplate <class\
    \ T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),\n\t\t\t\t\t\t\
    \t\t\t  decltype(end(declval<T>()))\n\t\t\t\t\t\t\t\t\t >\n\t\t\t\t\t\t   > :\
    \ true_type {};\n\ttemplate <class T> constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n\t//////////// is_readable\n\ttemplate <class T, class = void> struct is_readable\
    \ : false_type {};\n\ttemplate <class T> struct is_readable<T,\n\t\t\ttypename\
    \ std::enable_if_t<\n\t\t\t\tis_same_v<decltype(cin >> declval<T&>()), istream&>\n\
    \t\t\t>\n\t\t> : true_type {};\n\ttemplate <class T> constexpr bool is_readable_v\
    \ = is_readable<T>::value;\n\n\t//////////// is_printable\n\t// // https://nafe.es/posts/2020-02-29-is-printable/\n\
    \ttemplate <class T, class = void> struct is_printable : false_type {};\n\ttemplate\
    \ <class T> struct is_printable<T,\n\t\t\ttypename std::enable_if_t<\n\t\t\t\t\
    is_same_v<decltype(cout << declval<T>()), ostream&>\n\t\t\t>\n\t\t> : true_type\
    \ {};\n\ttemplate <class T> constexpr bool is_printable_v = is_printable<T>::value;\n\
    }\n\ninline namespace Input {\n\ttemplate <class T> constexpr bool needs_input_v\
    \ = !is_readable_v<T> && is_iterable_v<T>;\n\ttemplate <class T, class... U> void\
    \ re(T& t, U&... u);\n\ttemplate <class T, class U> void re(pair<T, U>& p); //\
    \ pairs\n\n\t// re: read\n\ttemplate <class T> typename enable_if<is_readable_v<T>,\
    \ void>::type re(T& x) { cin >> x; } // default\n\ttemplate <class T> void re(complex<T>&\
    \ c) { T a, b; re(a, b); c = {a, b}; } // complex\n\ttemplate <class T> typename\
    \ enable_if<needs_input_v<T>, void>::type re(T& i); // ex. vectors, arrays\n\t\
    template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }\n\
    \ttemplate <class T> typename enable_if<needs_input_v<T>, void>::type re(T& i)\
    \ {\n\t\tfor (auto& x : i) re(x); }\n\ttemplate <class T, class... U> void re(T&\
    \ t, U&... u) { re(t); re(u...); } // read multiple\n\n\t// rv: resize and read\
    \ vectors\n\tvoid rv(std::size_t) {}\n\ttemplate <class T, class... U> void rv(std::size_t\
    \ N, vector<T>& t, U&... u);\n\ttemplate <class...U> void rv(std::size_t, std::size_t\
    \ N2, U&... u);\n\ttemplate <class T, class... U> void rv(std::size_t N, vector<T>&\
    \ t, U&... u) {\n\t\tt.resize(N); re(t);\n\t\trv(N, u...); }\n\ttemplate <class...U>\
    \ void rv(std::size_t, std::size_t N2, U&... u) {\n\t\trv(N2, u...); }\n\n\t//\
    \ dumb shortcuts to read in ints\n\tvoid decrement() {} // subtract one from each\n\
    \ttemplate <class T, class... U> void decrement(T& t, U&... u) { --t; decrement(u...);\
    \ }\n\t#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);\n\t#define int1(...)\
    \ ints(__VA_ARGS__); decrement(__VA_ARGS__);\n}\n\ninline namespace ToString {\n\
    \ttemplate <class T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;\n\
    \n\t// ts: string representation to print\n\ttemplate <class T> typename enable_if<is_printable_v<T>,\
    \ string>::type ts(T v) {\n\t\tstringstream ss; ss << fixed << setprecision(15)\
    \ << v;\n\t\treturn ss.str(); } // default\n\ttemplate <class T> string bit_vec(T\
    \ t) { // bit vector to string\n\t\tstring res = \"{\"; for (int i = 0; i < (int)t.size();\
    \ ++i) res += ts(t[i]);\n\t\tres += \"}\"; return res; }\n\tstring ts(vector<bool>\
    \ v) { return bit_vec(v); }\n\ttemplate <std::size_t SZ> string ts(bitset<SZ>\
    \ b) { return bit_vec(b); } // bit vector\n\ttemplate <class T, class U> string\
    \ ts(pair<T, U> p); // pairs\n\ttemplate <class T> typename enable_if<needs_output_v<T>,\
    \ string>::type ts(T v); // vectors, arrays\n\ttemplate <class T, class U> string\
    \ ts(pair<T, U> p) { return \"(\" + ts(p.first) + \", \" + ts(p.second) + \")\"\
    ; }\n\ttemplate <class T> typename enable_if<is_iterable_v<T>, string>::type ts_sep(T\
    \ v, string sep) {\n\t\t// convert container to string w/ separator sep\n\t\t\
    bool fst = 1; string res = \"\";\n\t\tfor (const auto& x : v) {\n\t\t\tif (!fst)\
    \ res += sep;\n\t\t\tfst = 0; res += ts(x);\n\t\t}\n\t\treturn res;\n\t}\n\ttemplate\
    \ <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v) {\n\t\t\
    return \"{\" + ts_sep(v, \", \") + \"}\"; }\n\n\t// for nested DS\n\ttemplate\
    \ <int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type\
    \ \n\t  ts_lev(const T& v) { return {ts(v)}; }\n\ttemplate <int lev, class T>\
    \ typename enable_if<needs_output_v<T>, vector<string>>::type \n\t  ts_lev(const\
    \ T& v) {\n\t\tif (lev == 0 || !(int)v.size()) return {ts(v)};\n\t\tvector<string>\
    \ res;\n\t\tfor (const auto& t : v) {\n\t\t\tif ((int)res.size()) res.back() +=\
    \ \",\";\n\t\t\tvector<string> tmp = ts_lev<lev - 1>(t);\n\t\t\tres.insert(res.end(),\
    \ tmp.begin(), tmp.end());\n\t\t}\n\t\tfor (int i = 0; i < (int)res.size(); ++i)\
    \ {\n\t\t\tstring bef = \" \"; if (i == 0) bef = \"{\";\n\t\t\tres[i] = bef +\
    \ res[i];\n\t\t}\n\t\tres.back() += \"}\";\n\t\treturn res;\n\t}\n}\n\ninline\
    \ namespace Output {\n\ttemplate <class T> void pr_sep(ostream& os, string, const\
    \ T& t) { os << ts(t); }\n\ttemplate <class T, class... U> void pr_sep(ostream&\
    \ os, string sep, const T& t, const U&... u) {\n\t\tpr_sep(os, sep, t); os <<\
    \ sep; pr_sep(os, sep, u...); }\n\t// print w/ no spaces\n\ttemplate <class...\
    \ T> void pr(const T&... t) { pr_sep(cout, \"\", t...); } \n\t// print w/ spaces,\
    \ end with newline\n\tvoid ps() { cout << \"\\n\"; }\n\ttemplate <class... T>\
    \ void ps(const T&... t) { pr_sep(cout, \" \", t...); ps(); } \n\t// debug to\
    \ cerr\n\ttemplate <class... T> void dbg_out(const T&... t) {\n\t\tpr_sep(cerr,\
    \ \" | \", t...); cerr << endl; }\n\tvoid loc_info(int line, string names) {\n\
    \t\tcerr << \"Line(\" << line << \") -> [\" << names << \"]: \"; }\n\ttemplate\
    \ <int lev, class T> void dbgl_out(const T& t) {\n\t\tcerr << \"\\n\\n\" << ts_sep(ts_lev<lev>(t),\
    \ \"\\n\") << \"\\n\" << endl; }\n\t#ifdef LOCAL\n\t\t#define dbg(...) loc_info(__LINE__,\
    \ #__VA_ARGS__), dbg_out(__VA_ARGS__)\n\t\t#define dbgl(lev, x) loc_info(__LINE__,\
    \ #x), dbgl_out<lev>(x)\n\t#else // don't actually submit with this\n\t\t#define\
    \ dbg(...) 0\n\t\t#define dbgl(lev, x) 0\n\t#endif\n}\n\ninline namespace FileIO\
    \ {\n\tvoid set_in(string s)  { freopen(s.c_str(), \"r\", stdin); }\n\tvoid set_out(string\
    \ s) { freopen(s.c_str(), \"w\", stdout); }\n\tvoid setIO(string s = \"\") {\n\
    \t\tcin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams\n\t\t// cin.exceptions(cin.failbit);\n\
    \t\t// throws exception when do smth illegal\n\t\t// ex. try to read letter into\
    \ int\n\t\tif (!s.empty()) set_in(s + \".in\"), set_out(s + \".out\"); // for\
    \ old USACO\n\t}\n}\n\nconst int MOD = 1e9 + 7; // 998244353\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n\tmod_t v;\n\texplicit operator mod_t() const { return\
    \ v; }\n\texplicit operator bool() const { return v != 0; }\n\tmi() { v = 0; }\n\
    \tmi(const long long& v) {\n\t\tv = (-MOD <= v && v < MOD) ? v : v % MOD;\n\t\t\
    if (v < 0) v += MOD; }\n\tfriend std::istream& operator>>(std::istream& in, mi&\
    \ a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const mi& a) { return os << a.v; }\n\tfriend bool\
    \ operator==(const mi& a, const mi& b) { return a.v == b.v; }\n\tfriend bool operator!=(const\
    \ mi& a, const mi& b) { return !(a == b); }    \n\tfriend bool operator<(const\
    \ mi& a, const mi& b) { return a.v < b.v; }\n\tfriend bool operator>(const mi&\
    \ a, const mi& b) { return a.v > b.v; }\n\tfriend bool operator<=(const mi& a,\
    \ const mi& b) { return a.v <= b.v; }\n\tfriend bool operator>=(const mi& a, const\
    \ mi& b) { return a.v >= b.v; }\n\tmi operator-() const { return mi(-v); }\n\t\
    mi& operator+=(const mi& m) {\n\t\tif ((v += m.v) >= MOD) v -= MOD;\n\t\treturn\
    \ *this; }\n\tmi& operator-=(const mi& m) {\n\t\tif ((v -= m.v) < 0) v += MOD;\n\
    \t\treturn *this; }\n\tmi& operator*=(const mi& m) { v = (long long)v * m.v %\
    \ MOD;\n\t\treturn *this; }\n\tfriend mi pow(mi a, long long p) {\n\t\tmi ans\
    \ = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\
    \treturn ans; }\n\tfriend mi inv(const mi& a) { assert(a != 0); return pow(a,\
    \ MOD - 2); }\n\tmi& operator/=(const mi& m) { return (*this) *= inv(m); }\n\t\
    friend mi operator+(mi a, const mi& b) { return a += b; }\n\tfriend mi operator-(mi\
    \ a, const mi& b) { return a -= b; }\n\tfriend mi operator*(mi a, const mi& b)\
    \ { return a *= b; }\n\tfriend mi operator/(mi a, const mi& b) { return a /= b;\
    \ }\n};\n\nconst ld PI = acos((ld) -1);\n\ntypedef pair<mi, mi> pmi;\ntypedef\
    \ vector<mi> vmi;\ntypedef vector<pmi> vpmi;\n\n// base and base_digits must be\
    \ consistent\nconstexpr int base = 1000000000;\nconstexpr int base_digits = 9;\n\
    \nstruct BigInt {\n\t// value == 0 is represented by empty z\n\tstd::vector<int>\
    \ z; // digits\n\n\t// sign == 1 <==> value >= 0\n\t// sign == -1 <==> value <\
    \ 0\n\tint sign;\n\n\tBigInt() : sign(1) {}\n\tBigInt(long long v) { *this = v;\
    \ }\n\n\tBigInt& operator=(long long v) {\n\t\tsign = v < 0 ? -1 : 1; v *= sign;\n\
    \t\tz.clear(); for (; v > 0; v = v / base) z.push_back((int) (v % base));\n\t\t\
    return *this;\n\t}\n\n\tBigInt(const std::string& s) { read(s); }\n\n\tBigInt&\
    \ operator+=(const BigInt& other) {\n\t\tif (sign == other.sign) {\n\t\t\tfor\
    \ (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {\n\t\t\t\tif (i ==\
    \ z.size())\n\t\t\t\t\tz.push_back(0);\n\t\t\t\tz[i] += carry + (i < other.z.size()\
    \ ? other.z[i] : 0);\n\t\t\t\tcarry = z[i] >= base;\n\t\t\t\tif (carry)\n\t\t\t\
    \t\tz[i] -= base;\n\t\t\t}\n\t\t} else if (other != 0 /* prevent infinite loop\
    \ */) {\n\t\t\t*this -= -other;\n\t\t}\n\t\treturn *this;\n\t}\n\n\tfriend BigInt\
    \ operator+(BigInt a, const BigInt& b) { return a += b; }\n\n\tBigInt& operator-=(const\
    \ BigInt& other) {\n\t\tif (sign == other.sign) {\n\t\t\tif (sign == 1 && *this\
    \ >= other || sign == -1 && *this <= other) {\n\t\t\t\tfor (int i = 0, carry =\
    \ 0; i < other.z.size() || carry; ++i) {\n\t\t\t\t\tz[i] -= carry + (i < other.z.size()\
    \ ? other.z[i] : 0);\n\t\t\t\t\tcarry = z[i] < 0;\n\t\t\t\t\tif (carry)\n\t\t\t\
    \t\t\tz[i] += base;\n\t\t\t\t}\n\t\t\t\ttrim();\n\t\t\t} else {\n\t\t\t\t*this\
    \ = other - *this;\n\t\t\t\tthis->sign = -this->sign;\n\t\t\t}\n\t\t} else {\n\
    \t\t\t*this += -other;\n\t\t}\n\t\treturn *this;\n\t}\n\n\tfriend BigInt operator-(BigInt\
    \ a, const BigInt& b) { return a -= b; }\n\n\tBigInt& operator*=(int v) {\n\t\t\
    if (v < 0) sign = -sign, v = -v;\n\t\tfor (int i = 0, carry = 0; i < z.size()\
    \ || carry; ++i) {\n\t\t\tif (i == z.size())\n\t\t\t\tz.push_back(0);\n\t\t\t\
    long long cur = (long long) z[i] * v + carry;\n\t\t\tcarry = (int) (cur / base);\n\
    \t\t\tz[i] = (int) (cur % base);\n\t\t}\n\t\ttrim();\n\t\treturn *this;\n\t}\n\
    \n\tBigInt operator*(int v) const { return BigInt(*this) *= v; }\n\n\tfriend std::pair<BigInt,\
    \ BigInt> divmod(const BigInt& a1, const BigInt& b1) {\n\t\tint norm = base /\
    \ (b1.z.back() + 1);\n\t\tBigInt a = a1.abs() * norm;\n\t\tBigInt b = b1.abs()\
    \ * norm;\n\t\tBigInt q, r;\n\t\tq.z.resize(a.z.size());\n\n\t\tfor (int i = (int)\
    \ a.z.size() - 1; i >= 0; i--) {\n\t\t\tr *= base;\n\t\t\tr += a.z[i];\n\t\t\t\
    int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;\n\t\t\tint s2 = b.z.size()\
    \ - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;\n\t\t\tint d = (int) (((long long)\
    \ s1 * base + s2) / b.z.back());\n\t\t\tr -= b * d;\n\t\t\twhile (r < 0)\n\t\t\
    \t\tr += b, --d;\n\t\t\tq.z[i] = d;\n\t\t}\n\n\t\tq.sign = a1.sign * b1.sign;\n\
    \t\tr.sign = a1.sign;\n\t\tq.trim();\n\t\tr.trim();\n\t\treturn {q, r / norm};\n\
    \t}\n\n\tfriend BigInt sqrt(const BigInt& a1) {\n\t\tBigInt a = a1;\n\t\twhile\
    \ (a.z.empty() || a.z.size() % 2 == 1)\n\t\t\ta.z.push_back(0);\n\n\t\tint n =\
    \ a.z.size();\n\n\t\tint firstDigit = (int) ::sqrt((double) a.z[n - 1] * base\
    \ + a.z[n - 2]);\n\t\tint norm = base / (firstDigit + 1);\n\t\ta *= norm;\n\t\t\
    a *= norm;\n\t\twhile (a.z.empty() || a.z.size() % 2 == 1)\n\t\t\ta.z.push_back(0);\n\
    \n\t\tBigInt r = (long long) a.z[n - 1] * base + a.z[n - 2];\n\t\tfirstDigit =\
    \ (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);\n\t\tint q = firstDigit;\n\
    \t\tBigInt res;\n\n\t\tfor (int j = n / 2 - 1; j >= 0; j--) {\n\t\t\tfor (;; --q)\
    \ {\n\t\t\t\tBigInt r1 = (r - (res * 2 * base + q) * q) * base * base +\n\t\t\t\
    \t\t\t\t(j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);\n\t\t\
    \t\tif (r1 >= 0) {\n\t\t\t\t\tr = r1;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\tres *= base;\n\t\t\tres += q;\n\n\t\t\tif (j > 0) {\n\t\t\t\tint d1 = res.z.size()\
    \ + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;\n\t\t\t\tint d2 = res.z.size()\
    \ + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;\n\t\t\t\tint d3 = res.z.size()\
    \ < r.z.size() ? r.z[res.z.size()] : 0;\n\t\t\t\tq = (int) (((long long) d1 *\
    \ base * base + (long long) d2 * base + d3) / (firstDigit * 2));\n\t\t\t}\n\t\t\
    }\n\n\t\tres.trim();\n\t\treturn res / norm;\n\t}\n\n\tBigInt operator/(const\
    \ BigInt& v) const { return divmod(*this, v).first; }\n\n\tBigInt operator%(const\
    \ BigInt& v) const { return divmod(*this, v).second; }\n\n\tBigInt& operator/=(int\
    \ v) {\n\t\tif (v < 0) sign = -sign, v = -v;\n\t\tfor (int i = (int) z.size()\
    \ - 1, rem = 0; i >= 0; --i) {\n\t\t\tlong long cur = z[i] + rem * (long long)\
    \ base;\n\t\t\tz[i] = (int) (cur / v);\n\t\t\trem = (int) (cur % v);\n\t\t}\n\t\
    \ttrim();\n\t\treturn *this;\n\t}\n\n\tBigInt operator/(int v) const { return\
    \ BigInt(*this) /= v; }\n\n\tint operator%(int v) const {\n\t\tif (v < 0) v =\
    \ -v;\n\t\tint m = 0;\n\t\tfor (int i = (int) z.size() - 1; i >= 0; --i)\n\t\t\
    \tm = (int) ((z[i] + m * (long long) base) % v);\n\t\treturn m * sign;\n\t}\n\n\
    \tBigInt& operator*=(const BigInt& v) { return *this = *this * v; }\n\tBigInt&\
    \ operator/=(const BigInt& v) { return *this = *this / v; }\n\n\tbool operator<(const\
    \ BigInt& v) const {\n\t\tif (sign != v.sign)\n\t\t\treturn sign < v.sign;\n\t\
    \tif (z.size() != v.z.size())\n\t\t\treturn z.size() * sign < v.z.size() * v.sign;\n\
    \t\tfor (int i = (int) z.size() - 1; i >= 0; i--)\n\t\t\tif (z[i] != v.z[i])\n\
    \t\t\t\treturn z[i] * sign < v.z[i] * sign;\n\t\treturn false;\n\t}\n\n\tbool\
    \ operator>(const BigInt& v) const { return v < *this; }\n\tbool operator<=(const\
    \ BigInt& v) const { return !(v < *this); }\n\tbool operator>=(const BigInt& v)\
    \ const { return !(*this < v); }\n\tbool operator==(const BigInt& v) const { return\
    \ !(*this < v) && !(v < *this); }\n\tbool operator!=(const BigInt& v) const {\
    \ return *this < v || v < *this; }\n\n\tvoid trim() {\n\t\twhile (!z.empty() &&\
    \ z.back() == 0) z.pop_back();\n\t\tif (z.empty()) sign = 1;\n\t}\n\n\tbool is_zero()\
    \ const { return z.empty(); }\n\n\tfriend BigInt operator-(BigInt v) {\n\t\tif\
    \ (!v.z.empty()) v.sign = -v.sign;\n\t\treturn v;\n\t}\n\n\tBigInt abs() const\
    \ { return sign == 1 ? *this : -*this; }\n\n\tlong long longValue() const {\n\t\
    \tlong long res = 0;\n\t\tfor (int i = (int) z.size() - 1; i >= 0; i--)\n\t\t\t\
    res = res * base + z[i];\n\t\treturn res * sign;\n\t}\n\n\tfriend BigInt gcd(const\
    \ BigInt& a, const BigInt& b) {\n\t\treturn b.is_zero() ? a : gcd(b, a % b);\n\
    \t}\n\n\tfriend BigInt lcm(const BigInt& a, const BigInt& b) {\n\t\treturn a /\
    \ gcd(a, b) * b;\n\t}\n\n\tvoid read(const std::string& s) {\n\t\tsign = 1;\n\t\
    \tz.clear();\n\t\tint pos = 0;\n\t\twhile (pos < s.size() && (s[pos] == '-' ||\
    \ s[pos] == '+')) {\n\t\t\tif (s[pos] == '-')\n\t\t\t\tsign = -sign;\n\t\t\t++pos;\n\
    \t\t}\n\t\tfor (int i = (int) s.size() - 1; i >= pos; i -= base_digits) {\n\t\t\
    \tint x = 0;\n\t\t\tfor (int j = std::max(pos, i - base_digits + 1); j <= i; j++)\n\
    \t\t\t\tx = x * 10 + s[j] - '0';\n\t\t\tz.push_back(x);\n\t\t}\n\t\ttrim();\n\t\
    }\n\n\tfriend std::istream& operator>>(std::istream& stream, BigInt& v) {\n\t\t\
    std::string s; stream >> s;\n\t\tv.read(s);\n\t\treturn stream;\n\t}\n\n\tfriend\
    \ std::ostream& operator<<(std::ostream& stream, const BigInt& v) {\n\t\tif (v.sign\
    \ == -1)\n\t\t\tstream << '-';\n\t\tstream << (v.z.empty() ? 0 : v.z.back());\n\
    \t\tfor (int i = (int) v.z.size() - 2; i >= 0; --i)\n\t\t\tstream << std::setw(base_digits)\
    \ << std::setfill('0') << v.z[i];\n\t\treturn stream;\n\t}\n\n\tstatic std::vector<int>\
    \ convert_base(const std::vector<int>& a, int old_digits, int new_digits) {\n\t\
    \tstd::vector<long long> p(std::max(old_digits, new_digits) + 1);\n\t\tp[0] =\
    \ 1;\n\t\tfor (int i = 1; i < p.size(); i++)\n\t\t\tp[i] = p[i - 1] * 10;\n\t\t\
    std::vector<int> res;\n\t\tlong long cur = 0;\n\t\tint cur_digits = 0;\n\t\tfor\
    \ (int v : a) {\n\t\t\tcur += v * p[cur_digits];\n\t\t\tcur_digits += old_digits;\n\
    \t\t\twhile (cur_digits >= new_digits) {\n\t\t\t\tres.push_back(int(cur % p[new_digits]));\n\
    \t\t\t\tcur /= p[new_digits];\n\t\t\t\tcur_digits -= new_digits;\n\t\t\t}\n\t\t\
    }\n\t\tres.push_back((int) cur);\n\t\twhile (!res.empty() && res.back() == 0)\n\
    \t\t\tres.pop_back();\n\t\treturn res;\n\t}\n\n\tstatic std::vector<long long>\
    \ karatsubaMultiply(const std::vector<long long>& a, const std::vector<long long>&\
    \ b) {\n\t\tint n = a.size();\n\t\tstd::vector<long long> res(n + n);\n\t\tif\
    \ (n <= 32) {\n\t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\tfor (int j = 0; j <\
    \ n; j++)\n\t\t\t\t\tres[i + j] += a[i] * b[j];\n\t\t\treturn res;\n\t\t}\n\n\t\
    \tint k = n >> 1;\n\t\tstd::vector<long long> a1(a.begin(), a.begin() + k);\n\t\
    \tstd::vector<long long> a2(a.begin() + k, a.end());\n\t\tstd::vector<long long>\
    \ b1(b.begin(), b.begin() + k);\n\t\tstd::vector<long long> b2(b.begin() + k,\
    \ b.end());\n\n\t\tstd::vector<long long> a1b1 = karatsubaMultiply(a1, b1);\n\t\
    \tstd::vector<long long> a2b2 = karatsubaMultiply(a2, b2);\n\n\t\tfor (int i =\
    \ 0; i < k; i++)\n\t\t\ta2[i] += a1[i];\n\t\tfor (int i = 0; i < k; i++)\n\t\t\
    \tb2[i] += b1[i];\n\n\t\tstd::vector<long long> r = karatsubaMultiply(a2, b2);\n\
    \t\tfor (int i = 0; i < a1b1.size(); i++)\n\t\t\tr[i] -= a1b1[i];\n\t\tfor (int\
    \ i = 0; i < a2b2.size(); i++)\n\t\t\tr[i] -= a2b2[i];\n\n\t\tfor (int i = 0;\
    \ i < r.size(); i++)\n\t\t\tres[i + k] += r[i];\n\t\tfor (int i = 0; i < a1b1.size();\
    \ i++)\n\t\t\tres[i] += a1b1[i];\n\t\tfor (int i = 0; i < a2b2.size(); i++)\n\t\
    \t\tres[i + n] += a2b2[i];\n\t\treturn res;\n\t}\n\n\tBigInt operator*(const BigInt&\
    \ v) const {\n\t\tstd::vector<int> a6 = convert_base(this->z, base_digits, 6);\n\
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
    \ n; i++) {\n\t\ts += rand() % 10 + '0';\n\t}\n\treturn BigInt(s);\n}\n\nvoid\
    \ test() {\n\tsetIO(\"\");\n\tconst int D = 1000;\n\tconst int T = 100;\n\tauto\
    \ convert = [&](BigInt x) {\n\t\tmi res = 0;\n\t\tmi run = 1;\n\t\tf0r(i, sz(x.z))\
    \ {\n\t\t\tres += x.z[i] * run;\n\t\t\trun *= base;\n\t\t}\n\t\tif (x.sign ==\
    \ -1) {\n\t\t\tres *= -1;\n\t\t}\n\t\treturn res;\n\t};\n\tf0r(t, T) {\n\t\tBigInt\
    \ a = random_big_int(D) * ((rng() % 2) * 2 - 1) ;\n\t\tBigInt b = random_big_int(D)\
    \ * ((rng() % 2) * 2 - 1);\n\t\tmi c = convert(a);\n\t\tmi d = convert(b);\n\t\
    \tassert(convert(a + b) == c + d);\n\t\tassert(convert(a * b) == c * d);\n\t\t\
    assert(convert(a - b) == c - d);\n\t}\n}\n\nint main() {\n\tsetIO(\"\");\n\ttest();\n\
    \tint a, b;\n\tre(a, b);\n\tps(a + b);\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../library/contest/template-full.hpp\"\n#include \"../../library/numerical/big-integer.hpp\"\
    \n\nvoid test() {\n\tsetIO(\"\");\n\tconst int D = 1000;\n\tconst int T = 100;\n\
    \tauto convert = [&](BigInt x) {\n\t\tmi res = 0;\n\t\tmi run = 1;\n\t\tf0r(i,\
    \ sz(x.z)) {\n\t\t\tres += x.z[i] * run;\n\t\t\trun *= base;\n\t\t}\n\t\tif (x.sign\
    \ == -1) {\n\t\t\tres *= -1;\n\t\t}\n\t\treturn res;\n\t};\n\tf0r(t, T) {\n\t\t\
    BigInt a = random_big_int(D) * ((rng() % 2) * 2 - 1) ;\n\t\tBigInt b = random_big_int(D)\
    \ * ((rng() % 2) * 2 - 1);\n\t\tmi c = convert(a);\n\t\tmi d = convert(b);\n\t\
    \tassert(convert(a + b) == c + d);\n\t\tassert(convert(a * b) == c * d);\n\t\t\
    assert(convert(a - b) == c - d);\n\t}\n}\n\nint main() {\n\tsetIO(\"\");\n\ttest();\n\
    \tint a, b;\n\tre(a, b);\n\tps(a + b);\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-full.hpp
  - library/misc/pragma-short.hpp
  - library/contest/template-minimal.hpp
  - library/misc/easy-io.hpp
  - library/modular-arithmetic/mod-int.hpp
  - library/numerical/big-integer.hpp
  isVerificationFile: true
  path: verify/unit-test/unit-test-big-integer.test.cpp
  requiredBy: []
  timestamp: '2021-08-18 19:19:26-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-big-integer.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-big-integer.test.cpp
- /verify/verify/unit-test/unit-test-big-integer.test.cpp.html
title: verify/unit-test/unit-test-big-integer.test.cpp
---
