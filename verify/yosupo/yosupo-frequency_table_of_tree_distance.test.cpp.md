---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
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
    \n\n\n#pragma GCC optimize (\"O3\")\n#pragma GCC target (\"sse4\")\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/pb_ds/assoc_container.hpp>\n\nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\ntemplate <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n\ntypedef long long ll;\ntypedef long double\
    \ ld;\ntypedef double db;\ntypedef string str;\n\ntypedef pair<int, int> pi;\n\
    typedef pair<ll, ll> pl;\ntypedef pair<db, db> pd;\n\ntypedef vector<int> vi;\n\
    typedef vector<bool> vb;\ntypedef vector<ll> vl;\ntypedef vector<db> vd;\ntypedef\
    \ vector<str> vs;\ntypedef vector<pi> vpi;\ntypedef vector<pl> vpl;\ntypedef vector<pd>\
    \ vpd;\n\n#define mp make_pair\n#define f first\n#define s second\n#define sz(x)\
    \ (int)(x).size()\n#define all(x) begin(x), end(x)\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define sor(x) sort(all(x))\n#define rsz resize\n#define resz resize\n\
    #define ins insert\n#define ft front()\n#define bk back()\n#define pf push_front\n\
    #define pb push_back\n#define eb emplace_back\n#define lb lower_bound\n#define\
    \ ub upper_bound\n\n#define f1r(i, a, b) for (int i = (a); i < (b); ++i)\n#define\
    \ f0r(i, a) f1r(i, 0, a)\n#define FOR(i, a, b) for (int i = (a); i < (b); ++i)\n\
    #define F0R(i, a) FOR(i, 0, a)\n#define ROF(i, a, b) for (int i = (b) - 1; i >=\
    \ (a); --i)\n#define R0F(i, a) ROF(i, 0, a)\n#define each(a, x) for (auto &a :\
    \ x)\n\nmt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());\n\
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
    typedef vector<pmi> vpmi;\n\nstruct CentroidDecomposition {\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ g, cg; // cg is directed tree for centroids\n\tstd::vector<bool> vis;\n\tstd::vector<int>\
    \ size;\n\tstd::vector<int> parent;\n\tint root;\n\n\tvoid init(int n_) {\n\t\t\
    n = n_;\n\t\tg.assign(n, std::vector<int>());\n\t\tcg.assign(n, std::vector<int>());\n\
    \t\tvis.assign(n, false);\n\t\tparent.assign(n, 0);\n\t\tsize.assign(n, 0);\n\t\
    }\n\n\tvoid ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\
    \t}\n\n\tvoid dfs_size(int src, int par = -1) {\n\t\tsize[src] = 1;\n\t\tfor (int\
    \ nxt : g[src]) {\n\t\t\tif (nxt == par || vis[nxt]) \n\t\t\t\tcontinue;\n\t\t\
    \tdfs_size(nxt, src);\n\t\t\tsize[src] += size[nxt];\n\t\t}\n\t}\n\n\tint get_centroid(int\
    \ src) {\n\t\tdfs_size(src);\n\t\tint num = size[src];\n\t\tint par = -1;\n\t\t\
    do {    \t\n\t\t\tint go = -1;\n\t\t\tfor (int nxt : g[src]) {\n\t\t\t\tif (nxt\
    \ == par || vis[nxt])\n\t\t\t\t\tcontinue;\n\t\t\t\tif (2 * size[nxt] > num) \n\
    \t\t\t\t\tgo = nxt;\n\t\t\t}\n\t\t\tpar = src;\n\t\t\tsrc = go;\n\t\t} while (src\
    \ != -1);\n\t\treturn par;\n\t}\n\n\tint build_dfs(int src, int par = -1) {\n\t\
    \tint c = get_centroid(src);\n\t\tvis[c] = true;\n\t\tparent[c] = par;\n\t\tif\
    \ (par != -1) {\n\t\t\tcg[par].push_back(c);\n\t\t}\n\t\tfor (int nxt : g[c])\
    \ {\n\t\t\tif (vis[nxt]) \n\t\t\t\tcontinue;\n\t\t\tbuild_dfs(nxt, c);\n\t\t}\n\
    \t\treturn c;\n\t}\n\n\tvoid build() {\n\t\troot = build_dfs(0);\n\t}\n};  \n\n\
    \ntemplate <class T> struct SparseTable {\n\tstd::vector<T> v;\n\tstd::vector<std::vector<int>>\
    \ jump;\n\n\tint level(int x) { return 31 - __builtin_clz(x); }\n\n\tint comb(int\
    \ a, int b) {\n\t\treturn v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\n\
    \t}\n\n\tvoid init(const std::vector<T> &_v) {\n\t\tv = _v;\n\t\tjump = {std::vector<int>((int)v.size())};\n\
    \t\tiota(jump[0].begin(), jump[0].end(), 0);\n\t\tfor (int j = 1; (1 << j) <=\
    \ (int)v.size(); j++) {\n\t\t\tjump.push_back(std::vector<int>((int)v.size() -\
    \ (1 << j) + 1));\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\n\t\t\
    \t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n\t\t\t\
    }\n\t\t}\n\t}\n\n\tint index(int l, int r) {\n\t\tassert(l <= r);\n\t\tint d =\
    \ level(r - l + 1);\n\t\treturn comb(jump[d][l], jump[d][r - (1 << d) + 1]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\treturn v[index(l, r)];\n\t}\n};\n\nstruct\
    \ LCARMQ {\n\tint n; \n\tstd::vector<std::vector<int>> adj;\n\tstd::vector<int>\
    \ dep, in, par, rev, out, pos;\n\tstd::vector<std::pair<int, int>> tmp;\n\tSparseTable<std::pair<int,\
    \ int>> S;\n\tstd::vector<std::vector<int>> sparse;\n\tint ti = 0;\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\tadj.resize(n);\n\t\tdep = in = out = par = rev = pos\
    \ = std::vector<int>(n);\n\t\tsparse = {std::vector<int>(n)};\n\t\tfor (int j\
    \ = 1; (1 << j) <= n; j++) {\n\t\t\tsparse.push_back(std::vector<int>(n - (1 <<\
    \ j) + 1));\n\t\t}\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tadj[u].push_back(v);\n\
    \t\tadj[v].push_back(u);\n\t}\n\n\tvoid dfs(int src) {\n\t\tin[src] = ti++;\n\t\
    \tsparse[0][in[src]] = src;\n\t\tpos[src] = (int)tmp.size();\n\t\ttmp.emplace_back(dep[src],\
    \ src);\n\t\tfor (auto &nxt : adj[src]) {\n\t\t\tif (nxt == par[src]) continue;\n\
    \t\t\tdep[nxt] = dep[par[nxt] = src] + 1;\n\t\t\tdfs(nxt);\n\t\t\ttmp.emplace_back(dep[src],\
    \ src);\n\t\t}\n\t\tout[src] = ti;\n\t}\n\n\tinline int mini(int u, int v) {\n\
    \t\treturn (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v])) ? u : v;\n\
    \t}\n\n\tvoid gen(int root = 0) {\n\t\tpar[root] = root;\n\t\tdfs(root);\n\t\t\
    S.init(tmp); \n\t\tfor (int j = 1; j < (int)sparse.size(); j++) {\n\t\t\tfor (int\
    \ i = 0; i < (int)sparse[j].size(); i++) {\n\t\t\t\tsparse[j][i] = mini(sparse[j\
    \ - 1][i], sparse[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tint lca(int\
    \ u, int v) {\n\t\tu = pos[u];\n\t\tv = pos[v];\n\t\tif (u > v) std::swap(u, v);\n\
    \t\treturn S.query(u, v).second;\n\t}\n\n\tint dist(int u, int v) {\n\t\treturn\
    \ dep[u] + dep[v] - 2 * dep[lca(u, v)];\n\t}\n\n\tbool is_ancestor(int anc, int\
    \ src) {\n\t\treturn in[anc] <= in[src] && out[anc] >= out[src];\n\t}\n\n\tint\
    \ get_child(int anc, int src) {\n\t\tif (!is_ancestor(anc, src)) return -1;\n\t\
    \tint l = in[anc] + 1;\n\t\tint r = in[src];\n\t\tint d = 31 - __builtin_clz(r\
    \ - l + 1);\n\t\treturn mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);\n\t}\n\
    \t\n\tstd::vector<std::pair<int, int>> compress(std::vector<int> nodes) {\n\t\t\
    auto cmp = [&](int a, int b) {\n\t\t\treturn pos[a] < pos[b];\n\t\t};\n\t\tsort(nodes.begin(),\
    \ nodes.end(), cmp);\n\t\tfor (int i = (int)nodes.size() - 2; i >= 0; i--) {\n\
    \t\t\tnodes.push_back(lca(nodes[i], nodes[i + 1]));\n\t\t}\n\t\tsort(nodes.begin(),\
    \ nodes.end(), cmp);\n\t\tnodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());\n\
    \t\tstd::vector<std::pair<int, int>> ret{{0, nodes[0]}};\n\t\tfor (int i = 0;\
    \ i < (int)nodes.size(); i++) {\n\t\t\trev[nodes[i]] = i;\n\t\t}\n\t\tfor (int\
    \ i = 1; i < (int)nodes.size(); i++) {\n\t\t\tret.emplace_back(rev[lca(nodes[i\
    \ - 1], nodes[i])], nodes[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n\n\n// 5 is a\
    \ root of both mods\ntemplate <int MOD, int RT> struct Mint {\n\tstatic const\
    \ int mod = MOD;\n\tstatic constexpr Mint rt() { return RT; } // primitive root\
    \ for FFT\n\tstatic constexpr int md() { return MOD; } // primitive root for FFT\n\
    \tint v; \n\texplicit operator int() const { return v; } // explicit -> don't\
    \ silently convert to int\n\texplicit operator bool() const { return v != 0; }\n\
    \tMint() { v = 0; }\n\tMint(long long _v) { v = int((-MOD <= _v && _v < MOD) ?\
    \ _v : _v % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const Mint&\
    \ a, const Mint& b) { return a.v == b.v; }\n\tfriend bool operator!=(const Mint&\
    \ a, const Mint& b) { return !(a == b); }\n\tfriend bool operator<(const Mint&\
    \ a, const Mint& b) { return a.v < b.v; }\n\tfriend bool operator>(const Mint&\
    \ a, const Mint& b) { return a.v > b.v; }\n\tfriend bool operator<=(const Mint&\
    \ a, const Mint& b) { return a.v <= b.v; }\n\tfriend bool operator>=(const Mint&\
    \ a, const Mint& b) { return a.v >= b.v; }\n\tfriend std::istream& operator >>\
    \ (std::istream& in, Mint& a) { \n\t\tlong long x; std::cin >> x; a = Mint(x);\
    \ return in; }\n\tfriend std::ostream& operator << (std::ostream& os, const Mint&\
    \ a) { return os << a.v; }\n\tMint& operator+=(const Mint& m) { \n\t\tif ((v +=\
    \ m.v) >= MOD) v -= MOD; \n\t\treturn *this; }\n\tMint& operator-=(const Mint&\
    \ m) { \n\t\tif ((v -= m.v) < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const\
    \ Mint& m) { \n\t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const\
    \ Mint& m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long\
    \ p) {\n\t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint& a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint& b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint& b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint& b) { return a /= b; }\n};\n\nnamespace FFT {\n\
    \ntemplate <class T> void fft(std::vector<T> &A, bool inv = 0) {\n\tint n = (int)A.size();\n\
    \tassert((T::mod - 1) % n == 0);\n\tstd::vector<T> B(n);\n\tfor (int b = n / 2;\
    \ b; b /= 2, A.swap(B)) {\n\t\tT w = pow(T::rt(), (T::mod - 1) / n * b);\n\t\t\
    T m = 1;\n\t\tfor (int i = 0; i < n; i += b * 2, m *= w)\n\t\t\tfor (int j = 0;\
    \ j < b; j++) {\n\t\t\t\tT u = A[i + j];\n\t\t\t\tT v = A[i + j + b] * m;\n\t\t\
    \t\tB[i / 2 + j] = u + v;\n\t\t\t\tB[i / 2 + j + n / 2] = u - v;\n\t\t\t}\n\t\
    }\n\tif (inv) {\n\t\tstd::reverse(1 + A.begin(), A.end());\n\t\tT z = T(1) / T(n);\n\
    \t\tfor (auto &t : A) \n\t\t\tt *= z;\n\t}\n}\n\ntemplate <class T> std::vector<T>\
    \ multiply(std::vector<T> A, std::vector<T> B) {\n\tint sa = (int)A.size();\n\t\
    int sb = (int)B.size();\n\tif (!std::min(sa, sb))\n\t\treturn {};\n\tint s = sa\
    \ + sb - 1;\n\tint n = 1;\n\tfor (; n < s; n *= 2);\n\tbool eq = A == B;\n\tA.resize(n);\n\
    \tfft(A);\n\tif (eq) \n\t\tB = A;\n\telse \n\t\tB.resize(n), fft(B);\n\tfor (int\
    \ i = 0; i < n; i++)\n\t\tA[i] *= B[i];\n\tfft(A, 1);\n\tA.resize(s);\n\treturn\
    \ A;\n}\n\ntemplate <class M, class T> std::vector<M> multiply_mod(std::vector<T>\
    \ x, std::vector<T> y) {\n\tauto convert = [](const std::vector<T> &v) {\n\t\t\
    std::vector<M> w((int)v.size());\n\t\tfor (int i =  0; i < (int)v.size(); i++)\n\
    \t\t\tw[i] = (int) v[i];\n\t\treturn w;\n\t};\n\treturn multiply(convert(x), convert(y));\n\
    }\n\ntemplate <class T> std::vector<T> general_multiply(const std::vector<T> &A,\
    \ const std::vector<T> &B) { \n\t// arbitrary modulus\n\tusing m0 = Mint<(119\
    \ << 23) + 1, 62>; \n\tusing m1 = Mint<(5 << 25) + 1, 62>;\n\tusing m2 = Mint<(7\
    \ << 26) + 1, 62>;\n\tauto c0 = multiply_mod<m0>(A, B);\n\tauto c1 = multiply_mod<m1>(A,\
    \ B);\n\tauto c2 = multiply_mod<m2>(A, B);\n\tint n = (int)c0.size();\n\tstd::vector<T>\
    \ res(n);\n\tm1 r01 = 1 / m1(m0::mod);\n\tm2 r02 = 1 / m2(m0::mod);\n\tm2 r12\
    \ = 1 / m2(m1::mod);\n\tfor (int i = 0; i < n; i++) {\n\t\tint a = c0[i].v;\n\t\
    \tint b = ((c1[i] - a) * r01).v;\n\t\tint c = (((c2[i] - a) * r02 - b) * r12).v;\n\
    \t\tres[i] = (T(c) * m1::mod + b) * m0::mod + a;\n\t}\n\treturn res;\n}\n\n} //\
    \ namespace FFT\n\n\nnamespace Polynomial {\n\nusing T = long long;\nusing Poly\
    \ = std::vector<T>;\n\nT eval(const Poly &p, const T &x) {\n\tT res = 0;\n\tfor\
    \ (int i = (int)p.size() - 1; i >= 0; --i) {\n\t\tres = x * res + p[i];\n\t}\n\
    \treturn res;\n}\n\nPoly& operator+=(Poly &l, const Poly &r) {\n\tl.resize(std::max((int)l.size(),\
    \ (int)r.size()));\n\tfor (int i = 0; i < (int)r.size(); ++i) {\n\t\tl[i] += r[i];\n\
    \t}\n\treturn l;\n}\n\nPoly& operator-=(Poly &l, const Poly &r) {\n\tl.resize(std::max((int)l.size(),\
    \ (int)r.size()));\n\tfor (int i = 0; i < (int)r.size(); ++i) {\n\t\tl[i] -= r[i];\n\
    \t}\n\treturn l;\n}\n\nPoly& operator*=(Poly &l, const T& r) {\n\tfor (int i =\
    \ 0; i < (int)l.size(); ++i) {\n\t\tl[i] *= r;\n\t}\n\treturn l;\n}\n\nPoly& operator/=(Poly\
    \ &l, const T& r) {\n\tfor (int i = 0; i < (int)l.size(); ++i) {\n\t\tl[i] /=\
    \ r;\n\t}\n\treturn l;\n}\n\nPoly operator*(const Poly &l, const Poly &r) {\n\t\
    if (!std::min((int)l.size(), (int)r.size())) {\n\t\treturn {};\n\t}\n\treturn\
    \ FFT::general_multiply(l, r);\n\tPoly res((int)l.size() + (int)r.size() - 1);\n\
    \tfor (int i = 0; i < (int)l.size(); ++i) {\n\t\tfor (int j = 0; j < (int)r.size();\
    \ ++j) {\n\t\t\tres[i + j] += l[i] * r[j];\n\t\t}\n\t}\n\treturn res;\n}\n\nPoly\
    \ operator+(Poly l, const Poly &r) { return l += r; }\nPoly operator-(Poly l,\
    \ const Poly &r) { return l -= r; }\nPoly operator-(Poly l) { for (auto &t : l)\
    \ t *= -1; return l; }\nPoly operator*(Poly l, const T &r) { return l *= r; }\n\
    Poly operator*(const T& r, const Poly &l) { return l * r; }\nPoly operator/(Poly\
    \ l, const T &r) { return l /= r;\t}\nPoly& operator*=(Poly &l, const Poly &r)\
    \ { return l = l * r; }\n\nPoly derivative(const Poly &p) {\n\tPoly res;\n\tfor\
    \ (int i = 1; i < (int)p.size(); ++i) {\n\t\tres.push_back(T(i) * p[i]);\n\t}\n\
    \treturn res;\n}\n\nPoly integral(const Poly &p) {\n\tstatic Poly invs{0, 1};\n\
    \tfor (int i = invs.size(); i <= (int)p.size(); ++i ){\n\t\tinvs.push_back(1 /\
    \ T(i));\n\t}\n\tPoly res((int)p.size() + 1);\n\tfor (int i = 0; i < (int)p.size();\
    \ ++i) {\n\t\tres[i + 1] = p[i] * invs[i + 1];\n\t}\n\treturn res;\n}\n\n}\n\n\
    int main() {\n\tusing namespace FFT;\n\tusing namespace Polynomial;\n\tsetIO(\"\
    \");\n\tint n;\n\tre(n);\n\tCentroidDecomposition cd;\n\tcd.init(n);\n\tLCARMQ\
    \ lca;\n\tlca.init(n);\n\tvector<vi> g(n);\n\tf0r(i, n - 1) {\n\t\tint u, v;\n\
    \t\tre(u, v);\n\t\tg[u].pb(v);\n\t\tg[v].pb(u);\n\t\tlca.ae(u, v);\n\t\tcd.ae(u,\
    \ v);\n\t}\n\tlca.gen();\n\tcd.build();\n\tvl ans(n);\n\tfunction<vi(int)> dfs\
    \ = [&](int u) { // return how many at dist x\n\t\tvi verts;\n\t\tvector<vl> polys;\n\
    \t\tpolys.pb({1});\n\t\tvl tmp;\n\t\teach(v, cd.cg[u]) {\t\n\t\t\tauto res = dfs(v);\n\
    \t\t\teach(x, res) verts.pb(x);\n\t\t\ttmp.assign(res.size() + 1, 0);\n\t\t\t\
    each(x, res) {\n\t\t\t\t++tmp[lca.dist(x, u)];\n\t\t\t}\n\t\t\twhile (tmp.back()\
    \ == 0) tmp.pop_back();\n\t\t\tpolys.pb(tmp);\n\t\t}\t\n\t\tvl sum;\n\t\teach(x,\
    \ polys) sum += x;\n\t\tvl res = sum * sum;\n\t\teach(x, polys) res -= x * x;\n\
    \t\tres /= 2;\n\t\tf0r(i, sz(res)) {\n\t\t\tans[i] += res[i];\n\t\t}\n\t\tverts.pb(u);\n\
    \t\treturn verts;\n\t};\n\tdfs(cd.root);\n\tf1r(i, 1, n) {\n\t\tpr(ans[i], ' ');\n\
    \t}\n\tps();\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../../library/contest/template-full.hpp\"\n#include \"../../library/graphs/centroid-decomposition.hpp\"\
    \n#include \"../../library/graphs/lca-rmq.hpp\"\n#include \"../../library/polynomial/fast-fourier-transform.hpp\"\
    \n#include \"../../library/polynomial/polynomial2.hpp\"\n\nint main() {\n\tusing\
    \ namespace FFT;\n\tusing namespace Polynomial;\n\tsetIO(\"\");\n\tint n;\n\t\
    re(n);\n\tCentroidDecomposition cd;\n\tcd.init(n);\n\tLCARMQ lca;\n\tlca.init(n);\n\
    \tvector<vi> g(n);\n\tf0r(i, n - 1) {\n\t\tint u, v;\n\t\tre(u, v);\n\t\tg[u].pb(v);\n\
    \t\tg[v].pb(u);\n\t\tlca.ae(u, v);\n\t\tcd.ae(u, v);\n\t}\n\tlca.gen();\n\tcd.build();\n\
    \tvl ans(n);\n\tfunction<vi(int)> dfs = [&](int u) { // return how many at dist\
    \ x\n\t\tvi verts;\n\t\tvector<vl> polys;\n\t\tpolys.pb({1});\n\t\tvl tmp;\n\t\
    \teach(v, cd.cg[u]) {\t\n\t\t\tauto res = dfs(v);\n\t\t\teach(x, res) verts.pb(x);\n\
    \t\t\ttmp.assign(res.size() + 1, 0);\n\t\t\teach(x, res) {\n\t\t\t\t++tmp[lca.dist(x,\
    \ u)];\n\t\t\t}\n\t\t\twhile (tmp.back() == 0) tmp.pop_back();\n\t\t\tpolys.pb(tmp);\n\
    \t\t}\t\n\t\tvl sum;\n\t\teach(x, polys) sum += x;\n\t\tvl res = sum * sum;\n\t\
    \teach(x, polys) res -= x * x;\n\t\tres /= 2;\n\t\tf0r(i, sz(res)) {\n\t\t\tans[i]\
    \ += res[i];\n\t\t}\n\t\tverts.pb(u);\n\t\treturn verts;\n\t};\n\tdfs(cd.root);\n\
    \tf1r(i, 1, n) {\n\t\tpr(ans[i], ' ');\n\t}\n\tps();\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-full.hpp
  - library/misc/easy-io.hpp
  - library/graphs/centroid-decomposition.hpp
  - library/graphs/lca-rmq.hpp
  - library/data-structures/1d-range-queries/sparse-table.hpp
  - library/polynomial/fast-fourier-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  - library/polynomial/polynomial2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 17:58:43-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
- /verify/verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp.html
title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
---
