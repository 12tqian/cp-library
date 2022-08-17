---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.cpp
    title: library/contest/template-full.cpp
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/easy-io.hpp
    title: library/misc/easy-io.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int.hpp
    title: library/modular-arithmetic/mod-int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links: []
  bundledCode: "#define IGNORE \"just testing compilation\"\r\n\r\n\r\n\r\n#include\
    \ <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include <cassert>\r\
    \n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n#include <cstdio>\r\
    \n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\n#include <deque>\r\
    \n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\n#include <map>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\n#include <set>\r\
    \n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\n#include\
    \ <vector>\r\n\r\nusing namespace std;\n\r\n#include <ext/pb_ds/tree_policy.hpp>\r\
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
    \ S> ostream& operator << (ostream& os, const pair<T, S>& p) { return os << \"\
    (\" << p.first << \", \" << p.second << \")\"; }\r\ntemplate <typename C, typename\
    \ T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type*\
    \ = nullptr>\r\nostream& operator << (ostream& os, const C& c) { bool f = true;\
    \ os << \"{\"; for (const auto& x : c) { if (!f) os << \", \"; f = false; os <<\
    \ x; } return os << \"}\"; }\r\ntemplate <typename T> void debug(string s, T x)\
    \ { cerr << s << \" = \" << x << \"\\n\"; }\r\ntemplate <typename T, typename...\
    \ Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(','))\
    \ << \" = \" << x << \" | \"; debug(s.substr(s.find(',') + 2), args...); }\r\n\
    \r\nconstexpr int pct(int x) { return __builtin_popcount(x); }\r\nconstexpr int\
    \ bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))\r\n\r\ninline\
    \ namespace Helpers {\r\n\t//////////// is_iterable\r\n\t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\r\
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
    \ vpmi;\r\n\r\nint main() {\r\n\tset_io(\"\");\r\n\treturn 0;\r\n}\r\n"
  code: "#define IGNORE \"just testing compilation\"\r\n\r\n#include \"../../library/contest/template-full.cpp\""
  dependsOn:
  - library/contest/template-full.cpp
  - library/contest/template-full.hpp
  - library/contest/template-minimal.hpp
  - library/misc/easy-io.hpp
  - library/modular-arithmetic/mod-int.hpp
  isVerificationFile: true
  path: verify/unit-test/unit-test-template-full.test.cpp
  requiredBy: []
  timestamp: '2022-08-17 00:00:35-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-template-full.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-template-full.test.cpp
- /verify/verify/unit-test/unit-test-template-full.test.cpp.html
title: verify/unit-test/unit-test-template-full.test.cpp
---
