---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  - icon: ':heavy_check_mark:'
    path: library/dynamic-programming/gosper-hack.hpp
    title: library/dynamic-programming/gosper-hack.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/easy-io.hpp
    title: library/misc/easy-io.hpp
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
  bundledCode: "#define IGNORE \"self tested\"\n\n\n#pragma GCC optimize (\"O3\")\n\
    #pragma GCC target (\"sse4\")\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <deque>\n#include <iostream>\n#include <iomanip>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <vector>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;\ntemplate <class T> using\
    \ Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
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
    #define each(a, x) for (auto &a : x)\n\nmt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 :\
    \ 0; }\ntemplate <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b,\
    \ 1 : 0; }\n\ntemplate <class T> using V = vector<T>;\ntemplate <class T> using\
    \ VV = V<V<T>>;\ntemplate <class T> using VVV = V<V<V<T>>>;\ntemplate <class T>\
    \ using VVVV = V<V<V<V<T>>>>;\n\n#ifdef LOCAL\n#define dbg(...) debug(#__VA_ARGS__,\
    \ __VA_ARGS__);\n#else\n#define dbg(...) 17;\n#endif\n\ntemplate <typename T,\
    \ typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return\
    \ os << \"(\" << p.first << \", \" << p.second << \")\"; }\ntemplate <typename\
    \ C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C,\
    \ string>::value>::type* = nullptr>\nostream& operator << (ostream &os, const\
    \ C &c) { bool f = true; os << \"{\"; for (const auto &x : c) { if (!f) os <<\
    \ \", \"; f = false; os << x; } return os << \"}\"; }\ntemplate <typename T> void\
    \ debug(string s, T x) { cerr << s << \" = \" << x << \"\\n\"; }\ntemplate <typename\
    \ T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0,\
    \ s.find(',')) << \" = \" << x << \" | \"; debug(s.substr(s.find(',') + 2), args...);\
    \ }\n\nconstexpr int pct(int x) { return __builtin_popcount(x); }\nconstexpr int\
    \ bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))\n\n\nusing namespace\
    \ std;\n\ninline namespace Helpers {\n\t//////////// is_iterable\n\t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
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
    \ = !is_readable_v<T> && is_iterable_v<T>;\n\ttemplate <class T, class ...U> void\
    \ re(T &t, U &...u);\n\ttemplate <class T, class U> void re(pair<T, U> &p); //\
    \ pairs\n\n\t// re: read\n\ttemplate <class T> typename enable_if<is_readable_v<T>,\
    \ void>::type re(T &x) { cin >> x; } // default\n\ttemplate <class T> void re(complex<T>\
    \ &c) { T a, b; re(a, b); c = {a, b}; } // complex\n\ttemplate <class T> typename\
    \ enable_if<needs_input_v<T>, void>::type re(T &i); // ex. vectors, arrays\n\t\
    template <class T, class U> void re(pair<T, U> &p) { re(p.first, p.second); }\n\
    \ttemplate <class T> typename enable_if<needs_input_v<T>, void>::type re(T &i)\
    \ {\n\t\tfor (auto &x : i) re(x); }\n\ttemplate <class T, class ...U> void re(T\
    \ &t, U &...u) { re(t); re(u...); } // read multiple\n\n\t// rv: resize and read\
    \ vectors\n\tvoid rv(std::size_t) {}\n\ttemplate <class T, class ...U> void rv(std::size_t\
    \ N, vector<T> &t, U &...u);\n\ttemplate <class...U> void rv(std::size_t, std::size_t\
    \ N2, U &...u);\n\ttemplate <class T, class ...U> void rv(std::size_t N, vector<T>\
    \ &t, U &...u) {\n\t\tt.resize(N); re(t);\n\t\trv(N, u...); }\n\ttemplate <class...U>\
    \ void rv(std::size_t, std::size_t N2, U &...u) {\n\t\trv(N2, u...); }\n\n\t//\
    \ dumb shortcuts to read in ints\n\tvoid decrement() {} // subtract one from each\n\
    \ttemplate <class T, class ...U> void decrement(T &t, U &...u) { --t; decrement(u...);\
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
    bool fst = 1; string res = \"\";\n\t\tfor (const auto &x : v) {\n\t\t\tif (!fst)\
    \ res += sep;\n\t\t\tfst = 0; res += ts(x);\n\t\t}\n\t\treturn res;\n\t}\n\ttemplate\
    \ <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v) {\n\t\t\
    return \"{\" + ts_sep(v, \", \") + \"}\"; }\n\n\t// for nested DS\n\ttemplate\
    \ <int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type\
    \ \n\t  ts_lev(const T &v) { return {ts(v)}; }\n\ttemplate <int lev, class T>\
    \ typename enable_if<needs_output_v<T>, vector<string>>::type \n\t  ts_lev(const\
    \ T &v) {\n\t\tif (lev == 0 || !(int)v.size()) return {ts(v)};\n\t\tvector<string>\
    \ res;\n\t\tfor (const auto &t : v) {\n\t\t\tif ((int)res.size()) res.back() +=\
    \ \",\";\n\t\t\tvector<string> tmp = ts_lev<lev - 1>(t);\n\t\t\tres.insert(res.end(),\
    \ tmp.begin(), tmp.end());\n\t\t}\n\t\tfor (int i = 0; i < (int)res.size(); ++i)\
    \ {\n\t\t\tstring bef = \" \"; if (i == 0) bef = \"{\";\n\t\t\tres[i] = bef +\
    \ res[i];\n\t\t}\n\t\tres.back() += \"}\";\n\t\treturn res;\n\t}\n}\n\ninline\
    \ namespace Output {\n\ttemplate <class T> void pr_sep(ostream &os, string, const\
    \ T &t) { os << ts(t); }\n\ttemplate <class T, class... U> void pr_sep(ostream\
    \ &os, string sep, const T &t, const U &...u) {\n\t\tpr_sep(os, sep, t); os <<\
    \ sep; pr_sep(os, sep, u...); }\n\t// print w/ no spaces\n\ttemplate <class ...T>\
    \ void pr(const T &...t) { pr_sep(cout, \"\", t...); } \n\t// print w/ spaces,\
    \ end with newline\n\tvoid ps() { cout << \"\\n\"; }\n\ttemplate <class ...T>\
    \ void ps(const T &...t) { pr_sep(cout, \" \", t...); ps(); } \n\t// debug to\
    \ cerr\n\ttemplate <class ...T> void dbg_out(const T &...t) {\n\t\tpr_sep(cerr,\
    \ \" | \", t...); cerr << endl; }\n\tvoid loc_info(int line, string names) {\n\
    \t\tcerr << \"Line(\" << line << \") -> [\" << names << \"]: \"; }\n\ttemplate\
    \ <int lev, class T> void dbgl_out(const T &t) {\n\t\tcerr << \"\\n\\n\" << ts_sep(ts_lev<lev>(t),\
    \ \"\\n\") << \"\\n\" << endl; }\n\t#ifdef LOCAL\n\t\t#define dbg(...) loc_info(__LINE__,\
    \ #__VA_ARGS__), dbg_out(__VA_ARGS__)\n\t\t#define dbgl(lev, x) loc_info(__LINE__,\
    \ #x), dbgl_out<lev>(x)\n\t#else // don't actually submit with this\n\t\t#define\
    \ dbg(...) 0\n\t\t#define dbgl(lev, x) 0\n\t#endif\n}\n\ninline namespace FileIO\
    \ {\n\tvoid set_in(string s)  { freopen(s.c_str(), \"r\", stdin); }\n\tvoid set_out(string\
    \ s) { freopen(s.c_str(), \"w\", stdout); }\n\tvoid setIO(string s = \"\") {\n\
    \t\tcin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams\n\t\t// cin.exceptions(cin.failbit);\n\
    \t\t// throws exception when do smth illegal\n\t\t// ex. try to read letter into\
    \ int\n\t\tif (!s.empty()) set_in(s + \".in\"), set_out(s + \".out\"); // for\
    \ old USACO\n\t}\n}\n\nconst int MOD = 1e9 + 7; // 998244353;\nconst ld PI = acos((ld)\
    \ -1);\n\ntypedef std::decay<decltype(MOD)>::type mod_t; \nstruct mi {\n\tmod_t\
    \ val;\n\texplicit operator mod_t() const { return val; }\n\tmi() { val = 0; }\n\
    \tmi(const long long &v) {\n\t\tval = (-MOD <= v && v < MOD) ? v : v % MOD;\n\t\
    \tif (val < 0) val += MOD; }\n\tfriend std::istream& operator>>(std::istream &in,\
    \ mi &a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\tfriend\
    \ std::ostream& operator<<(std::ostream &os, const mi &a) { return os << a.val;\
    \ }\n\tfriend void pr(const mi &a) { pr(a.val); }\n\tfriend void re(mi &a) { long\
    \ long x; cin >> x; a = mi(x); }\n\tfriend bool operator==(const mi &a, const\
    \ mi &b) { return a.val == b.val; }\n\tfriend bool operator!=(const mi &a, const\
    \ mi &b) { return !(a == b); }    \n\tfriend bool operator<(const mi &a, const\
    \ mi &b) { return a.val < b.val; }\n\tfriend bool operator>(const mi &a, const\
    \ mi &b) { return a.val > b.val; }\n\tfriend bool operator<=(const mi &a, const\
    \ mi &b) { return a.val <= b.val; }\n\tfriend bool operator>=(const mi &a, const\
    \ mi &b) { return a.val >= b.val; }\n\tmi operator-() const { return mi(-val);\
    \ }\n\tmi& operator+=(const mi &m) {\n\t\tif ((val += m.val) >= MOD) val -= MOD;\n\
    \t\treturn *this; }\n\tmi& operator-=(const mi &m) {\n\t\tif ((val -= m.val) <\
    \ 0) val += MOD;\n\t\treturn *this; }\n\tmi& operator*=(const mi &m) { val = (long\
    \ long)val * m.val % MOD;\n\t\treturn *this; }\n\tfriend mi pow(mi a, long long\
    \ p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p &\
    \ 1) ans *= a;\n\t\treturn ans; }\n\tfriend mi inv(const mi &a) { assert(a !=\
    \ 0); return pow(a, MOD - 2); }\n\tmi& operator/=(const mi &m) { return (*this)\
    \ *= inv(m); }\n\tfriend mi operator+(mi a, const mi &b) { return a += b; }\n\t\
    friend mi operator-(mi a, const mi &b) { return a -= b; }\n\tfriend mi operator*(mi\
    \ a, const mi &b) { return a *= b; }\n\tfriend mi operator/(mi a, const mi &b)\
    \ { return a /= b; }\n};\n\ntypedef pair<mi, mi> pmi;\ntypedef vector<mi> vmi;\n\
    typedef vector<pmi> vpmi;\n\nstd::string binary(unsigned long long n ) { //long\
    \ long to binary string\n\tstd::string result;\n\tdo result.push_back('0' + (n\
    \ & 1));\n\twhile (n >>= 1);\n\treverse(result.begin(), result.end());\n\treturn\
    \ result;\n}\n\nstd::vector<int> gosper_generate(int n) {\n\tstd::vector<int>\
    \ res{0};\n\tfor (int sz = 1; sz <= n; sz++) {\n\t\tlong long c = (1 << sz) -\
    \ 1;\n\t\twhile (c < (1 << n)) {\n\t\t\tres.pb(c);\n\t\t\tlong long a = c & -c;\n\
    \t\t\tlong long b = c + a;\n\t\t\tc = (c ^ b) / 4 / a | b;\n\t\t}\n\t}\n\treturn\
    \ res;\n}\n\nvoid test_n(int n) {\n\tvi res = gosper_generate(n);\n\tf0r(i, sz(res)\
    \ - 1) {\n\t\tassert(__builtin_popcount(res[i]) <= __builtin_popcount(res[i +\
    \ 1]));\n\t}\n\tsort(all(res));\n\tf0r(i, (1 << n)) {\n\t\tassert(res[i] == i);\n\
    \t}\n\tassert(res.size() == (1 << n));\n}\n\nvoid test() {\n\tconst int L = 17;\n\
    \tf1r(i, 1, L) {\n\t\ttest_n(i);\n\t}\n}\n\nint main() {\n\tsetIO(\"\");\n\ttest();\n\
    \tint a, b;\n\tre(a, b);\n\tps(a + b);\n\treturn 0;\n}\n"
  code: "#define IGNORE \"self tested\"\n\n#include \"../../library/contest/template-full.hpp\"\
    \n#include \"../../library/dynamic-programming/gosper-hack.hpp\"\n\nvoid test_n(int\
    \ n) {\n\tvi res = gosper_generate(n);\n\tf0r(i, sz(res) - 1) {\n\t\tassert(__builtin_popcount(res[i])\
    \ <= __builtin_popcount(res[i + 1]));\n\t}\n\tsort(all(res));\n\tf0r(i, (1 <<\
    \ n)) {\n\t\tassert(res[i] == i);\n\t}\n\tassert(res.size() == (1 << n));\n}\n\
    \nvoid test() {\n\tconst int L = 17;\n\tf1r(i, 1, L) {\n\t\ttest_n(i);\n\t}\n\
    }\n\nint main() {\n\tsetIO(\"\");\n\ttest();\n\tint a, b;\n\tre(a, b);\n\tps(a\
    \ + b);\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-full.hpp
  - library/misc/easy-io.hpp
  - library/dynamic-programming/gosper-hack.hpp
  isVerificationFile: true
  path: verify/unit-test/unit-test-gosper-hack.test.cpp
  requiredBy: []
  timestamp: '2021-07-29 01:54:19-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-gosper-hack.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-gosper-hack.test.cpp
- /verify/verify/unit-test/unit-test-gosper-hack.test.cpp.html
title: verify/unit-test/unit-test-gosper-hack.test.cpp
---
