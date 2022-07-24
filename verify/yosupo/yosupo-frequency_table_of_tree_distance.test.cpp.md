---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: library/graphs/centroid-decomposition.hpp
    title: library/graphs/centroid-decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/lca-rmq.hpp
    title: LCA RMQ
  - icon: ':heavy_check_mark:'
    path: library/misc/easy-io.hpp
    title: library/misc/easy-io.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/pragma-short.hpp
    title: library/misc/pragma-short.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int.hpp
    title: library/modular-arithmetic/mod-int.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fast-fourier-transform.hpp
    title: library/polynomial/fast-fourier-transform.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/polynomial2.hpp
    title: library/polynomial/polynomial2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n\r\n\r\n#pragma GCC optimize (\"O3\")\r\n#pragma GCC target (\"sse4\"\
    )\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
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
    \ vpmi;\r\n\r\nstruct CentroidDecomposition {\r\n\tint n;\r\n\tstd::vector<std::vector<int>>\
    \ g, cg; // cg is directed tree for centroids\r\n\tstd::vector<bool> vis;\r\n\t\
    std::vector<int> size;\r\n\tstd::vector<int> parent;\r\n\tint root;\r\n\r\n\t\
    void init(int n_) {\r\n\t\tn = n_;\r\n\t\tg.assign(n, std::vector<int>());\r\n\
    \t\tcg.assign(n, std::vector<int>());\r\n\t\tvis.assign(n, false);\r\n\t\tparent.assign(n,\
    \ 0);\r\n\t\tsize.assign(n, 0);\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\t\
    g[u].push_back(v);\r\n\t\tg[v].push_back(u);\r\n\t}\r\n\r\n\tvoid dfs_size(int\
    \ src, int par = -1) {\r\n\t\tsize[src] = 1;\r\n\t\tfor (int nxt : g[src]) {\r\
    \n\t\t\tif (nxt == par || vis[nxt]) \r\n\t\t\t\tcontinue;\r\n\t\t\tdfs_size(nxt,\
    \ src);\r\n\t\t\tsize[src] += size[nxt];\r\n\t\t}\r\n\t}\r\n\r\n\tint get_centroid(int\
    \ src) {\r\n\t\tdfs_size(src);\r\n\t\tint num = size[src];\r\n\t\tint par = -1;\r\
    \n\t\tdo {    \t\r\n\t\t\tint go = -1;\r\n\t\t\tfor (int nxt : g[src]) {\r\n\t\
    \t\t\tif (nxt == par || vis[nxt])\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\tif (2 * size[nxt]\
    \ > num) \r\n\t\t\t\t\tgo = nxt;\r\n\t\t\t}\r\n\t\t\tpar = src;\r\n\t\t\tsrc =\
    \ go;\r\n\t\t} while (src != -1);\r\n\t\treturn par;\r\n\t}\r\n\r\n\tint build_dfs(int\
    \ src, int par = -1) {\r\n\t\tint c = get_centroid(src);\r\n\t\tvis[c] = true;\r\
    \n\t\tparent[c] = par;\r\n\t\tif (par != -1) {\r\n\t\t\tcg[par].push_back(c);\r\
    \n\t\t}\r\n\t\tfor (int nxt : g[c]) {\r\n\t\t\tif (vis[nxt]) \r\n\t\t\t\tcontinue;\r\
    \n\t\t\tbuild_dfs(nxt, c);\r\n\t\t}\r\n\t\treturn c;\r\n\t}\r\n\r\n\tvoid build()\
    \ {\r\n\t\troot = build_dfs(0);\r\n\t}\r\n};  \r\n\r\n\r\ntemplate <class T> struct\
    \ SparseTable {\r\n\tstd::vector<T> v;\r\n\tstd::vector<std::vector<int>> jump;\r\
    \n\r\n\tint level(int x) { return 31 - __builtin_clz(x); }\r\n\r\n\tint comb(int\
    \ a, int b) {\r\n\t\treturn v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a :\
    \ b);\r\n\t}\r\n\r\n\tvoid init(const std::vector<T>& _v) {\r\n\t\tv = _v;\r\n\
    \t\tjump = {std::vector<int>((int)v.size())};\r\n\t\tiota(jump[0].begin(), jump[0].end(),\
    \ 0);\r\n\t\tfor (int j = 1; (1 << j) <= (int)v.size(); j++) {\r\n\t\t\tjump.push_back(std::vector<int>((int)v.size()\
    \ - (1 << j) + 1));\r\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\r\
    \n\t\t\t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint index(int l, int r) {\r\n\t\tassert(l <=\
    \ r);\r\n\t\tint d = level(r - l + 1);\r\n\t\treturn comb(jump[d][l], jump[d][r\
    \ - (1 << d) + 1]);\r\n\t}\r\n\r\n\tT query(int l, int r) {\r\n\t\treturn v[index(l,\
    \ r)];\r\n\t}\r\n};\n\r\nstruct LCARMQ {\r\n\tint n; \r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\tstd::vector<int> dep, in, par, rev, out, pos;\r\n\tstd::vector<std::pair<int,\
    \ int>> tmp;\r\n\tSparseTable<std::pair<int, int>> S;\r\n\tstd::vector<std::vector<int>>\
    \ sparse;\r\n\tint ti = 0;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\t\
    adj.resize(n);\r\n\t\tdep = in = out = par = rev = pos = std::vector<int>(n);\r\
    \n\t\tsparse = {std::vector<int>(n)};\r\n\t\tfor (int j = 1; (1 << j) <= n; j++)\
    \ {\r\n\t\t\tsparse.push_back(std::vector<int>(n - (1 << j) + 1));\r\n\t\t}\r\n\
    \t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tadj[u].push_back(v);\r\n\t\tadj[v].push_back(u);\r\
    \n\t}\r\n\r\n\tvoid dfs(int src) {\r\n\t\tin[src] = ti++;\r\n\t\tsparse[0][in[src]]\
    \ = src;\r\n\t\tpos[src] = (int)tmp.size();\r\n\t\ttmp.emplace_back(dep[src],\
    \ src);\r\n\t\tfor (auto &nxt : adj[src]) {\r\n\t\t\tif (nxt == par[src]) continue;\r\
    \n\t\t\tdep[nxt] = dep[par[nxt] = src] + 1;\r\n\t\t\tdfs(nxt);\r\n\t\t\ttmp.emplace_back(dep[src],\
    \ src);\r\n\t\t}\r\n\t\tout[src] = ti;\r\n\t}\r\n\r\n\tinline int mini(int u,\
    \ int v) {\r\n\t\treturn (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v]))\
    \ ? u : v;\r\n\t}\r\n\r\n\tvoid gen(int root = 0) {\r\n\t\tpar[root] = root;\r\
    \n\t\tdfs(root);\r\n\t\tS.init(tmp); \r\n\t\tfor (int j = 1; j < (int)sparse.size();\
    \ j++) {\r\n\t\t\tfor (int i = 0; i < (int)sparse[j].size(); i++) {\r\n\t\t\t\t\
    sparse[j][i] = mini(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);\r\n\t\
    \t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint lca(int u, int v) {\r\n\t\tu = pos[u];\r\n\t\
    \tv = pos[v];\r\n\t\tif (u > v) std::swap(u, v);\r\n\t\treturn S.query(u, v).second;\r\
    \n\t}\r\n\r\n\tint dist(int u, int v) {\r\n\t\treturn dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\r\n\t}\r\n\r\n\tbool is_ancestor(int anc, int src) {\r\n\t\treturn in[anc]\
    \ <= in[src] && out[anc] >= out[src];\r\n\t}\r\n\r\n\tint get_child(int anc, int\
    \ src) {\r\n\t\tif (!is_ancestor(anc, src)) return -1;\r\n\t\tint l = in[anc]\
    \ + 1;\r\n\t\tint r = in[src];\r\n\t\tint d = 31 - __builtin_clz(r - l + 1);\r\
    \n\t\treturn mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);\r\n\t}\r\n\t\r\n\
    \tstd::vector<std::pair<int, int>> compress(std::vector<int> nodes) {\r\n\t\t\
    auto cmp = [&](int a, int b) {\r\n\t\t\treturn pos[a] < pos[b];\r\n\t\t};\r\n\t\
    \tsort(nodes.begin(), nodes.end(), cmp);\r\n\t\tfor (int i = (int)nodes.size()\
    \ - 2; i >= 0; i--) {\r\n\t\t\tnodes.push_back(lca(nodes[i], nodes[i + 1]));\r\
    \n\t\t}\r\n\t\tsort(nodes.begin(), nodes.end(), cmp);\r\n\t\tnodes.erase(unique(nodes.begin(),\
    \ nodes.end()), nodes.end());\r\n\t\tstd::vector<std::pair<int, int>> ret{{0,\
    \ nodes[0]}};\r\n\t\tfor (int i = 0; i < (int)nodes.size(); i++) {\r\n\t\t\trev[nodes[i]]\
    \ = i;\r\n\t\t}\r\n\t\tfor (int i = 1; i < (int)nodes.size(); i++) {\r\n\t\t\t\
    ret.emplace_back(rev[lca(nodes[i - 1], nodes[i])], nodes[i]);\r\n\t\t}\r\n\t\t\
    return ret;\r\n\t}\r\n};\r\n\r\n\r\n// 5 is a root of both mods\r\ntemplate <int\
    \ MOD, int RT> struct Mint {\r\n\tstatic const int mod = MOD;\r\n\tstatic constexpr\
    \ Mint rt() { return RT; } // primitive root for FFT\r\n\tstatic constexpr int\
    \ md() { return MOD; } // primitive root for FFT\r\n\tint v; \r\n\texplicit operator\
    \ int() const { return v; } // explicit -> don't silently convert to int\r\n\t\
    explicit operator bool() const { return v != 0; }\r\n\tMint() { v = 0; }\r\n\t\
    Mint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v\
    \ < 0) v += MOD; }\r\n\tfriend bool operator==(const Mint& a, const Mint& b) {\
    \ return a.v == b.v; }\r\n\tfriend bool operator!=(const Mint& a, const Mint&\
    \ b) { return !(a == b); }\r\n\tfriend bool operator<(const Mint& a, const Mint&\
    \ b) { return a.v < b.v; }\r\n\tfriend bool operator>(const Mint& a, const Mint&\
    \ b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const Mint& a, const Mint&\
    \ b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const Mint& a, const Mint&\
    \ b) { return a.v >= b.v; }\r\n\tfriend std::istream& operator >> (std::istream&\
    \ in, Mint& a) { \r\n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\r\
    \n\tfriend std::ostream& operator << (std::ostream& os, const Mint& a) { return\
    \ os << a.v; }\r\n\tMint& operator+=(const Mint& m) { \r\n\t\tif ((v += m.v) >=\
    \ MOD) v -= MOD; \r\n\t\treturn *this; }\r\n\tMint& operator-=(const Mint& m)\
    \ { \r\n\t\tif ((v -= m.v) < 0) v += MOD; \r\n\t\treturn *this; }\r\n\tMint& operator*=(const\
    \ Mint& m) { \r\n\t\tv = (long long)v * m.v % MOD; return *this; }\r\n\tMint&\
    \ operator/=(const Mint& m) { return (*this) *= inv(m); }\r\n\tfriend Mint pow(Mint\
    \ a, long long p) {\r\n\t\tMint ans = 1; assert(p >= 0);\r\n\t\tfor (; p; p /=\
    \ 2, a *= a) if (p & 1) ans *= a;\r\n\t\treturn ans; \r\n\t}\r\n\tfriend Mint\
    \ inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }\r\n\tMint operator-()\
    \ const { return Mint(-v); }\r\n\tMint& operator++() { return *this += 1; }\r\n\
    \tMint& operator--() { return *this -= 1; }\r\n\tfriend Mint operator+(Mint a,\
    \ const Mint& b) { return a += b; }\r\n\tfriend Mint operator-(Mint a, const Mint&\
    \ b) { return a -= b; }\r\n\tfriend Mint operator*(Mint a, const Mint& b) { return\
    \ a *= b; }\r\n\tfriend Mint operator/(Mint a, const Mint& b) { return a /= b;\
    \ }\r\n};\r\n\r\nnamespace FFT {\r\n\r\ntemplate <class T> void fft(std::vector<T>&\
    \ A, bool inv = 0) {\r\n\tint n = (int)A.size();\r\n\tassert((T::mod - 1) % n\
    \ == 0);\r\n\tstd::vector<T> B(n);\r\n\tfor (int b = n / 2; b; b /= 2, A.swap(B))\
    \ {\r\n\t\tT w = pow(T::rt(), (T::mod - 1) / n * b);\r\n\t\tT m = 1;\r\n\t\tfor\
    \ (int i = 0; i < n; i += b * 2, m *= w)\r\n\t\t\tfor (int j = 0; j < b; j++)\
    \ {\r\n\t\t\t\tT u = A[i + j];\r\n\t\t\t\tT v = A[i + j + b] * m;\r\n\t\t\t\t\
    B[i / 2 + j] = u + v;\r\n\t\t\t\tB[i / 2 + j + n / 2] = u - v;\r\n\t\t\t}\r\n\t\
    }\r\n\tif (inv) {\r\n\t\tstd::reverse(1 + A.begin(), A.end());\r\n\t\tT z = T(1)\
    \ / T(n);\r\n\t\tfor (auto& t : A) \r\n\t\t\tt *= z;\r\n\t}\r\n}\r\n\r\ntemplate\
    \ <class T> std::vector<T> multiply(std::vector<T> A, std::vector<T> B) {\r\n\t\
    int sa = (int)A.size();\r\n\tint sb = (int)B.size();\r\n\tif (!std::min(sa, sb))\r\
    \n\t\treturn {};\r\n\tint s = sa + sb - 1;\r\n\tint n = 1;\r\n\tfor (; n < s;\
    \ n *= 2);\r\n\tbool eq = A == B;\r\n\tA.resize(n);\r\n\tfft(A);\r\n\tif (eq)\
    \ \r\n\t\tB = A;\r\n\telse \r\n\t\tB.resize(n), fft(B);\r\n\tfor (int i = 0; i\
    \ < n; i++)\r\n\t\tA[i] *= B[i];\r\n\tfft(A, 1);\r\n\tA.resize(s);\r\n\treturn\
    \ A;\r\n}\r\n\r\ntemplate <class M, class T> std::vector<M> multiply_mod(std::vector<T>\
    \ x, std::vector<T> y) {\r\n\tauto convert = [](const std::vector<T>& v) {\r\n\
    \t\tstd::vector<M> w((int)v.size());\r\n\t\tfor (int i =  0; i < (int)v.size();\
    \ i++)\r\n\t\t\tw[i] = (int)v[i];\r\n\t\treturn w;\r\n\t};\r\n\treturn multiply(convert(x),\
    \ convert(y));\r\n}\r\n\r\ntemplate <class T> std::vector<T> general_multiply(const\
    \ std::vector<T>& A, const std::vector<T>& B) { \r\n\t// arbitrary modulus\r\n\
    \tusing m0 = Mint<(119 << 23) + 1, 62>; \r\n\tusing m1 = Mint<(5 << 25) + 1, 62>;\r\
    \n\tusing m2 = Mint<(7 << 26) + 1, 62>;\r\n\tauto c0 = multiply_mod<m0>(A, B);\r\
    \n\tauto c1 = multiply_mod<m1>(A, B);\r\n\tauto c2 = multiply_mod<m2>(A, B);\r\
    \n\tint n = (int)c0.size();\r\n\tstd::vector<T> res(n);\r\n\tm1 r01 = 1 / m1(m0::mod);\r\
    \n\tm2 r02 = 1 / m2(m0::mod);\r\n\tm2 r12 = 1 / m2(m1::mod);\r\n\tfor (int i =\
    \ 0; i < n; i++) {\r\n\t\tint a = c0[i].v;\r\n\t\tint b = ((c1[i] - a) * r01).v;\r\
    \n\t\tint c = (((c2[i] - a) * r02 - b) * r12).v;\r\n\t\tres[i] = (T(c) * m1::mod\
    \ + b) * m0::mod + a;\r\n\t}\r\n\treturn res;\r\n}\r\n\r\n} // namespace FFT\n\
    \r\n\r\nnamespace Polynomial {\r\n\r\nusing T = long long;\r\nusing Poly = std::vector<T>;\r\
    \n\r\nT eval(const Poly& p, const T& x) {\r\n\tT res = 0;\r\n\tfor (int i = (int)p.size()\
    \ - 1; i >= 0; --i) {\r\n\t\tres = x * res + p[i];\r\n\t}\r\n\treturn res;\r\n\
    }\r\n\r\nPoly& operator+=(Poly& l, const Poly& r) {\r\n\tl.resize(std::max((int)l.size(),\
    \ (int)r.size()));\r\n\tfor (int i = 0; i < (int)r.size(); ++i) {\r\n\t\tl[i]\
    \ += r[i];\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly& operator-=(Poly& l, const Poly&\
    \ r) {\r\n\tl.resize(std::max((int)l.size(), (int)r.size()));\r\n\tfor (int i\
    \ = 0; i < (int)r.size(); ++i) {\r\n\t\tl[i] -= r[i];\r\n\t}\r\n\treturn l;\r\n\
    }\r\n\r\nPoly& operator*=(Poly& l, const T& r) {\r\n\tfor (int i = 0; i < (int)l.size();\
    \ ++i) {\r\n\t\tl[i] *= r;\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly& operator/=(Poly&\
    \ l, const T& r) {\r\n\tfor (int i = 0; i < (int)l.size(); ++i) {\r\n\t\tl[i]\
    \ /= r;\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly operator*(const Poly& l, const\
    \ Poly& r) {\r\n\tif (!std::min((int)l.size(), (int)r.size())) {\r\n\t\treturn\
    \ {};\r\n\t}\r\n\treturn FFT::general_multiply(l, r);\r\n\tPoly res((int)l.size()\
    \ + (int)r.size() - 1);\r\n\tfor (int i = 0; i < (int)l.size(); ++i) {\r\n\t\t\
    for (int j = 0; j < (int)r.size(); ++j) {\r\n\t\t\tres[i + j] += l[i] * r[j];\r\
    \n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\nPoly operator+(Poly l, const Poly&\
    \ r) { return l += r; }\r\nPoly operator-(Poly l, const Poly& r) { return l -=\
    \ r; }\r\nPoly operator-(Poly l) { for (auto &t : l) t *= -1; return l; }\r\n\
    Poly operator*(Poly l, const T& r) { return l *= r; }\r\nPoly operator*(const\
    \ T& r, const Poly& l) { return l * r; }\r\nPoly operator/(Poly l, const T& r)\
    \ { return l /= r;\t}\r\nPoly& operator*=(Poly& l, const Poly& r) { return l =\
    \ l * r; }\r\n\r\nPoly derivative(const Poly& p) {\r\n\tPoly res;\r\n\tfor (int\
    \ i = 1; i < (int)p.size(); ++i) {\r\n\t\tres.push_back(T(i) * p[i]);\r\n\t}\r\
    \n\treturn res;\r\n}\r\n\r\nPoly integral(const Poly& p) {\r\n\tstatic Poly invs{0,\
    \ 1};\r\n\tfor (int i = invs.size(); i <= (int)p.size(); ++i ){\r\n\t\tinvs.push_back(1\
    \ / T(i));\r\n\t}\r\n\tPoly res((int)p.size() + 1);\r\n\tfor (int i = 0; i < (int)p.size();\
    \ ++i) {\r\n\t\tres[i + 1] = p[i] * invs[i + 1];\r\n\t}\r\n\treturn res;\r\n}\r\
    \n\r\n}\n\r\nint main() {\r\n\tusing namespace FFT;\r\n\tusing namespace Polynomial;\r\
    \n\tset_io(\"\");\r\n\tint n;\r\n\tre(n);\r\n\tCentroidDecomposition cd;\r\n\t\
    cd.init(n);\r\n\tLCARMQ lca;\r\n\tlca.init(n);\r\n\tvector<vi> g(n);\r\n\tf0r(i,\
    \ n - 1) {\r\n\t\tint u, v;\r\n\t\tre(u, v);\r\n\t\tg[u].pb(v);\r\n\t\tg[v].pb(u);\r\
    \n\t\tlca.ae(u, v);\r\n\t\tcd.ae(u, v);\r\n\t}\r\n\tlca.gen();\r\n\tcd.build();\r\
    \n\tvl ans(n);\r\n\tfunction<vi(int)> dfs = [&](int u) { // return how many at\
    \ dist x\r\n\t\tvi verts;\r\n\t\tvector<vl> polys;\r\n\t\tpolys.pb({1});\r\n\t\
    \tvl tmp;\r\n\t\teach(v, cd.cg[u]) {\t\r\n\t\t\tauto res = dfs(v);\r\n\t\t\teach(x,\
    \ res) verts.pb(x);\r\n\t\t\ttmp.assign(res.size() + 1, 0);\r\n\t\t\teach(x, res)\
    \ {\r\n\t\t\t\t++tmp[lca.dist(x, u)];\r\n\t\t\t}\r\n\t\t\twhile (tmp.back() ==\
    \ 0) tmp.pop_back();\r\n\t\t\tpolys.pb(tmp);\r\n\t\t}\t\r\n\t\tvl sum;\r\n\t\t\
    each(x, polys) sum += x;\r\n\t\tvl res = sum * sum;\r\n\t\teach(x, polys) res\
    \ -= x * x;\r\n\t\tres /= 2;\r\n\t\tf0r(i, sz(res)) {\r\n\t\t\tans[i] += res[i];\r\
    \n\t\t}\r\n\t\tverts.pb(u);\r\n\t\treturn verts;\r\n\t};\r\n\tdfs(cd.root);\r\n\
    \tf1r(i, 1, n) {\r\n\t\tpr(ans[i], ' ');\r\n\t}\r\n\tps();\r\n\treturn 0;\r\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#include \"../../library/contest/template-full.hpp\"\r\n#include \"../../library/graphs/centroid-decomposition.hpp\"\
    \r\n#include \"../../library/graphs/lca-rmq.hpp\"\r\n#include \"../../library/polynomial/fast-fourier-transform.hpp\"\
    \r\n#include \"../../library/polynomial/polynomial2.hpp\"\r\n\r\nint main() {\r\
    \n\tusing namespace FFT;\r\n\tusing namespace Polynomial;\r\n\tset_io(\"\");\r\
    \n\tint n;\r\n\tre(n);\r\n\tCentroidDecomposition cd;\r\n\tcd.init(n);\r\n\tLCARMQ\
    \ lca;\r\n\tlca.init(n);\r\n\tvector<vi> g(n);\r\n\tf0r(i, n - 1) {\r\n\t\tint\
    \ u, v;\r\n\t\tre(u, v);\r\n\t\tg[u].pb(v);\r\n\t\tg[v].pb(u);\r\n\t\tlca.ae(u,\
    \ v);\r\n\t\tcd.ae(u, v);\r\n\t}\r\n\tlca.gen();\r\n\tcd.build();\r\n\tvl ans(n);\r\
    \n\tfunction<vi(int)> dfs = [&](int u) { // return how many at dist x\r\n\t\t\
    vi verts;\r\n\t\tvector<vl> polys;\r\n\t\tpolys.pb({1});\r\n\t\tvl tmp;\r\n\t\t\
    each(v, cd.cg[u]) {\t\r\n\t\t\tauto res = dfs(v);\r\n\t\t\teach(x, res) verts.pb(x);\r\
    \n\t\t\ttmp.assign(res.size() + 1, 0);\r\n\t\t\teach(x, res) {\r\n\t\t\t\t++tmp[lca.dist(x,\
    \ u)];\r\n\t\t\t}\r\n\t\t\twhile (tmp.back() == 0) tmp.pop_back();\r\n\t\t\tpolys.pb(tmp);\r\
    \n\t\t}\t\r\n\t\tvl sum;\r\n\t\teach(x, polys) sum += x;\r\n\t\tvl res = sum *\
    \ sum;\r\n\t\teach(x, polys) res -= x * x;\r\n\t\tres /= 2;\r\n\t\tf0r(i, sz(res))\
    \ {\r\n\t\t\tans[i] += res[i];\r\n\t\t}\r\n\t\tverts.pb(u);\r\n\t\treturn verts;\r\
    \n\t};\r\n\tdfs(cd.root);\r\n\tf1r(i, 1, n) {\r\n\t\tpr(ans[i], ' ');\r\n\t}\r\
    \n\tps();\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-full.hpp
  - library/misc/pragma-short.hpp
  - library/contest/template-minimal.hpp
  - library/misc/easy-io.hpp
  - library/modular-arithmetic/mod-int.hpp
  - library/graphs/centroid-decomposition.hpp
  - library/graphs/lca-rmq.hpp
  - library/data-structures/1d-range-queries/sparse-table.hpp
  - library/polynomial/fast-fourier-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  - library/polynomial/polynomial2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2022-07-24 00:24:04-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
- /verify/verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp.html
title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
---
