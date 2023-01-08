---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/easy-io.hpp
    title: library/misc/easy-io.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int.hpp
    title: library/modular-arithmetic/mod-int.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/big-integer.hpp
    title: Big Integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\r\n\r\n\
    \r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n#include <ext/pb_ds/tree_policy.hpp>\r\
    \n#include <ext/pb_ds/assoc_container.hpp>\r\n\r\nusing namespace __gnu_pbds;\r\
    \n\r\ntemplate <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\r\n\r\ntypedef long long ll;\r\ntypedef\
    \ long double ld;\r\ntypedef double db;\r\ntypedef string str;\r\n\r\ntypedef\
    \ pair<int, int> pi;\r\ntypedef pair<ll, ll> pl;\r\ntypedef pair<db, db> pd;\r\
    \n\r\ntypedef vector<int> vi;\r\ntypedef vector<bool> vb;\r\ntypedef vector<ll>\
    \ vl;\r\ntypedef vector<db> vd;\r\ntypedef vector<str> vs;\r\ntypedef vector<pi>\
    \ vpi;\r\ntypedef vector<pl> vpl;\r\ntypedef vector<pd> vpd;\r\n\r\n#define mp\
    \ make_pair\r\n#define f first\r\n#define s second\r\n#define sz(x) (int)(x).size()\r\
    \n#define all(x) begin(x), end(x)\r\n#define rall(x) (x).rbegin(), (x).rend()\r\
    \n#define sor(x) sort(all(x))\r\n#define rsz resize\r\n#define resz resize\r\n\
    #define ins insert\r\n#define ft front()\r\n#define bk back()\r\n#define pf push_front\r\
    \n#define pb push_back\r\n#define eb emplace_back\r\n#define lb lower_bound\r\n\
    #define ub upper_bound\r\n\r\n#define f1r(i, a, b) for (int i = (a); i < (b);\
    \ ++i)\r\n#define f0r(i, a) f1r(i, 0, a)\r\n#define r1f(i, a, b) for (int i =\
    \ (b); i --> (a); )\r\n#define r0f(i, a) r1f(i, 0, a)\r\n#define FOR(i, a, b)\
    \ for (int i = (a); i < (b); ++i)\r\n#define F0R(i, a) FOR(i, 0, a)\r\n#define\
    \ ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)\r\n#define R0F(i, a) ROF(i,\
    \ 0, a)\r\n#define each(a, x) for (auto& a : x)\r\n\r\nmt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());\r\
    \n\r\ntemplate <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b,\
    \ 1 : 0; }\r\ntemplate <class T> bool ckmax(T& a, const T& b) { return a < b ?\
    \ a = b, 1 : 0; }\r\n\r\ntemplate <class T> using V = vector<T>;\r\ntemplate <class\
    \ T> using VV = V<V<T>>;\r\ntemplate <class T> using VVV = V<V<V<T>>>;\r\ntemplate\
    \ <class T> using VVVV = V<V<V<V<T>>>>;\r\n\r\ntemplate <typename T, typename\
    \ S> ostream& operator<<(ostream& os, const pair<T, S>& p) { \r\n  return os <<\
    \ \"(\" << p.first << \", \" << p.second << \")\"; \r\n}\r\ntemplate <typename\
    \ C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C,\
    \ string>::value>::type* = nullptr>\r\nostream& operator << (ostream& os, const\
    \ C& c) { \r\n  bool f = true; \r\n  os << \"{\"; \r\n  for (const auto& x : c)\
    \ { \r\n    if (!f) \r\n      os << \", \"; \r\n    f = false; os << x; \r\n \
    \ } \r\n  return os << \"}\"; \r\n}\r\ntemplate <typename T> void debug(string\
    \ s, T x) { cerr << s << \" = \" << x << \"\\n\"; }\r\ntemplate <typename T, typename...\
    \ Args> void debug(string s, T x, Args... args) { \r\n  cerr << s.substr(0, s.find(','))\
    \ << \" = \" << x << \" | \"; \r\n  debug(s.substr(s.find(',') + 2), args...);\
    \ \r\n}\r\n\r\nconstexpr int pct(int x) { return __builtin_popcount(x); }\r\n\
    constexpr int bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))\r\
    \n\r\ninline namespace Helpers {\r\n\t//////////// is_iterable\r\n\t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\r\
    \n\t// this gets used only when we can call begin() and end() on that type\r\n\
    \ttemplate <class T, class = void> struct is_iterable : false_type {};\r\n\ttemplate\
    \ <class T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),\r\n\t\t\
    \t\t\t\t\t\t\t  decltype(end(declval<T>()))\r\n\t\t\t\t\t\t\t\t\t >\r\n\t\t\t\t\
    \t\t   > : true_type {};\r\n\ttemplate <class T> constexpr bool is_iterable_v\
    \ = is_iterable<T>::value;\r\n\r\n\t//////////// is_readable\r\n\ttemplate <class\
    \ T, class = void> struct is_readable : false_type {};\r\n\ttemplate <class T>\
    \ struct is_readable<T,\r\n\t\t\ttypename std::enable_if_t<\r\n\t\t\t\tis_same_v<decltype(cin\
    \ >> declval<T&>()), istream&>\r\n\t\t\t>\r\n\t\t> : true_type {};\r\n\ttemplate\
    \ <class T> constexpr bool is_readable_v = is_readable<T>::value;\r\n\r\n\t////////////\
    \ is_printable\r\n\t// // https://nafe.es/posts/2020-02-29-is-printable/\r\n\t\
    template <class T, class = void> struct is_printable : false_type {};\r\n\ttemplate\
    \ <class T> struct is_printable<T,\r\n\t\t\ttypename std::enable_if_t<\r\n\t\t\
    \t\tis_same_v<decltype(cout << declval<T>()), ostream&>\r\n\t\t\t>\r\n\t\t> :\
    \ true_type {};\r\n\ttemplate <class T> constexpr bool is_printable_v = is_printable<T>::value;\r\
    \n}\r\n\r\ninline namespace Input {\r\n\ttemplate <class T> constexpr bool needs_input_v\
    \ = !is_readable_v<T> && is_iterable_v<T>;\r\n\ttemplate <class T, class... U>\
    \ void re(T& t, U&... u);\r\n\ttemplate <class T, class U> void re(pair<T, U>&\
    \ p); // pairs\r\n\r\n\t// re: read\r\n\ttemplate <class T> typename enable_if<is_readable_v<T>,\
    \ void>::type re(T& x) { cin >> x; } // default\r\n\ttemplate <class T> void re(complex<T>&\
    \ c) { T a, b; re(a, b); c = {a, b}; } // complex\r\n\ttemplate <class T> typename\
    \ enable_if<needs_input_v<T>, void>::type re(T& i); // ex. vectors, arrays\r\n\
    \ttemplate <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second);\
    \ }\r\n\ttemplate <class T> typename enable_if<needs_input_v<T>, void>::type re(T&\
    \ i) {\r\n\t\tfor (auto& x : i) re(x); }\r\n\ttemplate <class T, class... U> void\
    \ re(T& t, U&... u) { re(t); re(u...); } // read multiple\r\n\r\n\t// rv: resize\
    \ and read vectors\r\n\tvoid rv(std::size_t) {}\r\n\ttemplate <class T, class...\
    \ U> void rv(std::size_t N, vector<T>& t, U&... u);\r\n\ttemplate <class...U>\
    \ void rv(std::size_t, std::size_t N2, U&... u);\r\n\ttemplate <class T, class...\
    \ U> void rv(std::size_t N, vector<T>& t, U&... u) {\r\n\t\tt.resize(N); re(t);\r\
    \n\t\trv(N, u...); }\r\n\ttemplate <class...U> void rv(std::size_t, std::size_t\
    \ N2, U&... u) {\r\n\t\trv(N2, u...); }\r\n\r\n\t// dumb shortcuts to read in\
    \ ints\r\n\tvoid decrement() {} // subtract one from each\r\n\ttemplate <class\
    \ T, class... U> void decrement(T& t, U&... u) { --t; decrement(u...); }\r\n\t\
    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);\r\n\t#define int1(...) ints(__VA_ARGS__);\
    \ decrement(__VA_ARGS__);\r\n}\r\n  \r\ninline namespace ToString {\r\n\ttemplate\
    \ <class T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;\r\
    \n\r\n\t// ts: string representation to print\r\n\ttemplate <class T> typename\
    \ enable_if<is_printable_v<T>, string>::type ts(T v) {\r\n\t\tstringstream ss;\
    \ ss << fixed << setprecision(15) << v;\r\n\t\treturn ss.str(); } // default\r\
    \n\ttemplate <class T> string bit_vec(T t) { // bit vector to string\r\n\t\tstring\
    \ res = \"{\"; for (int i = 0; i < (int)t.size(); ++i) res += ts(t[i]);\r\n\t\t\
    res += \"}\"; return res; }\r\n\tstring ts(vector<bool> v) { return bit_vec(v);\
    \ }\r\n\ttemplate <std::size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b);\
    \ } // bit vector\r\n\ttemplate <class T, class U> string ts(pair<T, U> p); //\
    \ pairs\r\n\ttemplate <class T> typename enable_if<needs_output_v<T>, string>::type\
    \ ts(T v); // vectors, arrays\r\n\ttemplate <class T, class U> string ts(pair<T,\
    \ U> p) { return \"(\" + ts(p.first) + \", \" + ts(p.second) + \")\"; }\r\n\t\
    template <class T> typename enable_if<is_iterable_v<T>, string>::type ts_sep(T\
    \ v, string sep) { \r\n\t\t// convert container to string w/ separator sep\r\n\
    \t\tbool fst = 1; string res = \"\";\r\n\t\tfor (const auto& x : v) { \r\n\t\t\
    \tif (!fst) res += sep;\r\n\t\t\tfst = 0; res += ts(x);\r\n\t\t}\r\n\t\treturn\
    \ res;\r\n\t}\r\n\ttemplate <class T> typename enable_if<needs_output_v<T>, string>::type\
    \ ts(T v) {\r\n\t\treturn \"{\" + ts_sep(v, \", \") + \"}\"; } \r\n\r\n\t// for\
    \ nested DS\r\n\ttemplate <int, class T> typename enable_if<!needs_output_v<T>,\
    \ vector<string>>::type \r\n\t  ts_lev(const T& v) { return {ts(v)}; }\r\n\ttemplate\
    \ <int lev, class T> typename enable_if<needs_output_v<T>, vector<string>>::type\
    \ \r\n\t  ts_lev(const T& v) {\r\n\t\tif (lev == 0 || !(int)v.size()) return {ts(v)};\r\
    \n\t\tvector<string> res;\r\n\t\tfor (const auto& t : v) {\r\n\t\t\tif ((int)res.size())\
    \ res.back() += \",\";\r\n\t\t\tvector<string> tmp = ts_lev<lev - 1>(t);\r\n\t\
    \t\tres.insert(res.end(), tmp.begin(), tmp.end()); \r\n\t\t}\r\n\t\tfor (int i\
    \ = 0; i < (int)res.size(); ++i) {\r\n\t\t\tstring bef = \" \"; if (i == 0) bef\
    \ = \"{\";\r\n\t\t\tres[i] = bef + res[i];\r\n\t\t}\r\n\t\tres.back() += \"}\"\
    ;\r\n\t\treturn res;\r\n\t}\r\n}\r\n\r\ninline namespace Output {\r\n\ttemplate\
    \ <class T> void pr_sep(ostream& os, string, const T& t) { os << ts(t); }\r\n\t\
    template <class T, class... U> void pr_sep(ostream& os, string sep, const T& t,\
    \ const U&... u) {\r\n\t\tpr_sep(os, sep, t); os << sep; pr_sep(os, sep, u...);\
    \ }\r\n\t// print w/ no spaces\r\n\ttemplate <class... T> void pr(const T&...\
    \ t) { pr_sep(cout, \"\", t...); } \r\n\t// print w/ spaces, end with newline\r\
    \n\tvoid ps() { cout << \"\\n\"; }\r\n\ttemplate <class... T> void ps(const T&...\
    \ t) { pr_sep(cout, \" \", t...); ps(); } \r\n\t// debug to cerr\r\n\ttemplate\
    \ <class... T> void dbg_out(const T&... t) {\r\n\t\tpr_sep(cerr, \" | \", t...);\
    \ cerr << endl; }\r\n\tvoid loc_info(int line, string names) {\r\n\t\tcerr <<\
    \ \"Line(\" << line << \") -> [\" << names << \"]: \"; }\r\n\ttemplate <int lev,\
    \ class T> void dbgl_out(const T& t) {\r\n\t\tcerr << \"\\n\\n\" << ts_sep(ts_lev<lev>(t),\
    \ \"\\n\") << \"\\n\" << endl; }\r\n\t#ifdef LOCAL\r\n\t\t#define dbg(...) loc_info(__LINE__,\
    \ #__VA_ARGS__), dbg_out(__VA_ARGS__)\r\n\t\t#define dbgl(lev, x) loc_info(__LINE__,\
    \ #x), dbgl_out<lev>(x)\r\n\t#else // don't actually submit with this\r\n\t\t\
    #define dbg(...) 0\r\n\t\t#define dbgl(lev, x) 0\r\n\t#endif\r\n}\r\n\r\ninline\
    \ namespace FileIO {\r\n\tvoid set_in(string s)  { (void)!freopen(s.c_str(), \"\
    r\", stdin); }\r\n\tvoid set_out(string s) { (void)!freopen(s.c_str(), \"w\",\
    \ stdout); }\r\n\tvoid set_io(string s = \"\") {\r\n\t\tcin.tie(0)->sync_with_stdio(0);\
    \ // unsync C / C++ I/O streams\r\n\t\t// cin.exceptions(cin.failbit);\r\n\t\t\
    // throws exception when do smth illegal\r\n\t\t// ex. try to read letter into\
    \ int\r\n\t\tif (!s.empty()) set_in(s + \".in\"), set_out(s + \".out\"); // for\
    \ old USACO\r\n\t}\r\n}\r\n\r\nconst int MOD = 1e9 + 7; // 998244353\r\n\r\ntypedef\
    \ std::decay<decltype(MOD)>::type mod_t; \r\nstruct mi {\r\n\tmod_t v;\r\n\texplicit\
    \ operator mod_t() const { return v; }\r\n\texplicit operator bool() const { return\
    \ v != 0; }\r\n\tmi() { v = 0; }\r\n\tmi(const long long& _v) {\r\n\t\tv = (-MOD\
    \ <= _v && _v < MOD) ? _v : _v % MOD;\r\n\t\tif (v < 0) v += MOD; }\r\n\tfriend\
    \ std::istream& operator>>(std::istream& in, mi& a) { \r\n\t\tlong long x; std::cin\
    \ >> x; a = mi(x); return in; }\r\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const mi& a) { return os << a.v; }\r\n\tfriend bool operator==(const mi&\
    \ a, const mi& b) { return a.v == b.v; }\r\n\tfriend bool operator!=(const mi&\
    \ a, const mi& b) { return !(a == b); }    \r\n\tfriend bool operator<(const mi&\
    \ a, const mi& b) { return a.v < b.v; }\r\n\tfriend bool operator>(const mi& a,\
    \ const mi& b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const mi& a,\
    \ const mi& b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const mi& a,\
    \ const mi& b) { return a.v >= b.v; }\r\n\tmi operator-() const { return mi(-v);\
    \ }\r\n\tmi& operator+=(const mi& m) {\r\n\t\tif ((v += m.v) >= MOD) v -= MOD;\r\
    \n\t\treturn *this; }\r\n\tmi& operator-=(const mi& m) {\r\n\t\tif ((v -= m.v)\
    \ < 0) v += MOD;\r\n\t\treturn *this; }\r\n\tmi& operator*=(const mi& m) { v =\
    \ (long long)v * m.v % MOD;\r\n\t\treturn *this; }\r\n\tfriend mi pow(mi a, long\
    \ long p) {\r\n\t\tmi ans = 1; assert(p >= 0);\r\n\t\tfor (; p; p /= 2, a *= a)\
    \ if (p & 1) ans *= a;\r\n\t\treturn ans; }\r\n\tfriend mi inv(const mi& a) {\
    \ assert(a != 0); return pow(a, MOD - 2); }\r\n\tmi& operator/=(const mi& m) {\
    \ return (*this) *= inv(m); }\r\n\tfriend mi operator+(mi a, const mi& b) { return\
    \ a += b; }\r\n\tfriend mi operator-(mi a, const mi& b) { return a -= b; }\r\n\
    \tfriend mi operator*(mi a, const mi& b) { return a *= b; }\r\n\tfriend mi operator/(mi\
    \ a, const mi& b) { return a /= b; }\r\n};\n\r\nconst ld PI = acos((ld)-1);\r\n\
    \r\ntypedef pair<mi, mi> pmi;\r\ntypedef vector<mi> vmi;\r\ntypedef vector<pmi>\
    \ vpmi;\r\n\r\n// base and base_digits must be consistent\r\nconstexpr int base\
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
    \ BigInt(s);\r\n}\n\r\nvoid test() {\r\n\tconst int D = 1000;\r\n\tconst int T\
    \ = 100;\r\n\tauto convert = [&](BigInt x) {\r\n\t\tmi res = 0;\r\n\t\tmi run\
    \ = 1;\r\n\t\tf0r(i, sz(x.z)) {\r\n\t\t\tres += x.z[i] * run;\r\n\t\t\trun *=\
    \ base;\r\n\t\t}\r\n\t\tif (x.sign == -1) {\r\n\t\t\tres *= -1;\r\n\t\t}\r\n\t\
    \treturn res;\r\n\t};\r\n\tf0r(t, T) {\r\n\t\tBigInt a = random_big_int(D) * ((rng()\
    \ % 2) * 2 - 1) ;\r\n\t\tBigInt b = random_big_int(D) * ((rng() % 2) * 2 - 1);\r\
    \n\t\tmi c = convert(a);\r\n\t\tmi d = convert(b);\r\n\t\tassert(convert(a + b)\
    \ == c + d);\r\n\t\tassert(convert(a * b) == c * d);\r\n\t\tassert(convert(a -\
    \ b) == c - d);\r\n\t}\r\n}\r\n\r\nint main() {\r\n\tset_io(\"\");\r\n\ttest();\r\
    \n\tint a, b;\r\n\tre(a, b);\r\n\tps(a + b);\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\r\n\r\n#include\
    \ \"../../library/contest/template-full.hpp\"\r\n#include \"../../library/numerical/big-integer.hpp\"\
    \r\n\r\nvoid test() {\r\n\tconst int D = 1000;\r\n\tconst int T = 100;\r\n\tauto\
    \ convert = [&](BigInt x) {\r\n\t\tmi res = 0;\r\n\t\tmi run = 1;\r\n\t\tf0r(i,\
    \ sz(x.z)) {\r\n\t\t\tres += x.z[i] * run;\r\n\t\t\trun *= base;\r\n\t\t}\r\n\t\
    \tif (x.sign == -1) {\r\n\t\t\tres *= -1;\r\n\t\t}\r\n\t\treturn res;\r\n\t};\r\
    \n\tf0r(t, T) {\r\n\t\tBigInt a = random_big_int(D) * ((rng() % 2) * 2 - 1) ;\r\
    \n\t\tBigInt b = random_big_int(D) * ((rng() % 2) * 2 - 1);\r\n\t\tmi c = convert(a);\r\
    \n\t\tmi d = convert(b);\r\n\t\tassert(convert(a + b) == c + d);\r\n\t\tassert(convert(a\
    \ * b) == c * d);\r\n\t\tassert(convert(a - b) == c - d);\r\n\t}\r\n}\r\n\r\n\
    int main() {\r\n\tset_io(\"\");\r\n\ttest();\r\n\tint a, b;\r\n\tre(a, b);\r\n\
    \tps(a + b);\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-full.hpp
  - library/contest/template-minimal.hpp
  - library/misc/easy-io.hpp
  - library/modular-arithmetic/mod-int.hpp
  - library/numerical/big-integer.hpp
  isVerificationFile: true
  path: verify/unit-test/unit-test-big-integer.test.cpp
  requiredBy: []
  timestamp: '2022-08-21 11:26:50-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-big-integer.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-big-integer.test.cpp
- /verify/verify/unit-test/unit-test-big-integer.test.cpp.html
title: verify/unit-test/unit-test-big-integer.test.cpp
---
