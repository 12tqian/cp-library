---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nafe.es/posts/2020-02-29-is-printable/
    - https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
  bundledCode: "#line 1 \"library/contest/template_full.cpp\"\n#pragma GCC optimize\
    \ (\"O3\")\n#pragma GCC target (\"sse4\")\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <deque>\n#include <iostream>\n#include <iomanip>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <vector>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;\ntemplate <class T> using\
    \ Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;\n\
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
    \ for (int i = (a); i < (b); ++i)\n#define F0R(i, a) FOR(i,0,a)\n#define ROF(i,\
    \ a, b) for (int i = (b) - 1; i >= (a); --i)\n#define R0F(i, a) ROF(i, 0, a)\n\
    #define each(a, x) for (auto& a : x)\n\nmt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 :\
    \ 0; }\ntemplate <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b,\
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
    \ bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))\n\ninline namespace\
    \ Helpers {\n    //////////// is_iterable\n    // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
    \    // this gets used only when we can call begin() and end() on that type\n\
    \    template <class T, class = void> struct is_iterable : false_type {};\n  \
    \  template <class T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),\n\
    \                                      decltype(end(declval<T>()))\n         \
    \                            >\n                           > : true_type {};\n\
    \    template <class T> constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n    //////////// is_readable\n    template <class T, class = void> struct is_readable\
    \ : false_type {};\n    template <class T> struct is_readable<T,\n           \
    \ typename std::enable_if_t<\n                is_same_v<decltype(cin >> declval<T&>()),\
    \ istream&>\n            >\n        > : true_type {};\n    template <class T>\
    \ constexpr bool is_readable_v = is_readable<T>::value;\n\n    //////////// is_printable\n\
    \    // // https://nafe.es/posts/2020-02-29-is-printable/\n    template <class\
    \ T, class = void> struct is_printable : false_type {};\n    template <class T>\
    \ struct is_printable<T,\n            typename std::enable_if_t<\n           \
    \     is_same_v<decltype(cout << declval<T>()), ostream&>\n            >\n   \
    \     > : true_type {};\n    template <class T> constexpr bool is_printable_v\
    \ = is_printable<T>::value;\n}\n\ninline namespace Input {\n    template <class\
    \ T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;\n \
    \   template <class T, class ...U> void re(T& t, U&... u);\n    template <class\
    \ T, class U> void re(pair<T, U>& p); // pairs\n\n    // re: read\n    template\
    \ <class T> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >>\
    \ x; } // default\n    template <class T> void re(complex<T>& c) { T a, b; re(a,\
    \ b); c = {a, b}; } // complex\n    template <class T> typename enable_if<needs_input_v<T>,void>::type\
    \ re(T& i); // ex. vectors, arrays\n    template <class T, class U> void re(pair<T,\
    \ U>& p) { re(p.first, p.second); }\n    template <class T> typename enable_if<needs_input_v<T>,void>::type\
    \ re(T& i) {\n        for (auto& x : i) re(x); }\n    template <class T, class\
    \ ...U> void re(T& t, U&... u) { re(t); re(u...); } // read multiple\n\n    //\
    \ rv: resize and read vectors\n    void rv(size_t) {}\n    template <class T,\
    \ class ...U> void rv(size_t N, vector<T>& t, U&... u);\n    template<class...U>\
    \ void rv(size_t, size_t N2, U&... u);\n    template <class T, class ...U> void\
    \ rv(size_t N, vector<T>& t, U&... u) {\n        t.resize(N); re(t);\n       \
    \ rv(N, u...); }\n    template<class...U> void rv(size_t, size_t N2, U&... u)\
    \ {\n        rv(N2, u...); }\n\n    // dumb shortcuts to read in ints\n    void\
    \ decrement() {} // subtract one from each\n    template <class T, class ...U>\
    \ void decrement(T& t, U&... u) { --t; decrement(u...); }\n    #define ints(...)\
    \ int __VA_ARGS__; re(__VA_ARGS__);\n    #define int1(...) ints(__VA_ARGS__);\
    \ decrement(__VA_ARGS__);\n}\n\ninline namespace ToString {\n    template <class\
    \ T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;\n\
    \n    // ts: string representation to print\n    template <class T> typename enable_if<is_printable_v<T>,\
    \ string>::type ts(T v) {\n        stringstream ss; ss << fixed << setprecision(15)\
    \ << v;\n        return ss.str(); } // default\n    template <class T> string\
    \ bit_vec(T t) { // bit vector to string\n        string res = \"{\"; for (int\
    \ i = 0; i < (int)t.size(); ++i) res += ts(t[i]);\n        res += \"}\"; return\
    \ res; }\n    string ts(vector<bool> v) { return bit_vec(v); }\n    template<size_t\
    \ SZ> string ts(bitset<SZ> b) { return bit_vec(b); } // bit vector\n    template\
    \ <class T, class U> string ts(pair<T, U> p); // pairs\n    template <class T>\
    \ typename enable_if<needs_output_v<T>, string>::type ts(T v); // vectors, arrays\n\
    \    template <class T, class U> string ts(pair<T, U> p) { return \"(\" + ts(p.first)\
    \ + \", \" + ts(p.second) + \")\"; }\n    template <class T> typename enable_if<is_iterable_v<T>,\
    \ string>::type ts_sep(T v, string sep) {\n        // convert container to string\
    \ w/ separator sep\n        bool fst = 1; string res = \"\";\n        for (const\
    \ auto& x : v) {\n            if (!fst) res += sep;\n            fst = 0; res\
    \ += ts(x);\n        }\n        return res;\n    }\n    template <class T> typename\
    \ enable_if<needs_output_v<T>, string>::type ts(T v) {\n        return \"{\" +\
    \ ts_sep(v, \", \") + \"}\"; }\n\n    // for nested DS\n    template<int, class\
    \ T> typename enable_if<!needs_output_v<T>, vector<string>>::type \n      ts_lev(const\
    \ T& v) { return {ts(v)}; }\n    template<int lev, class T> typename enable_if<needs_output_v<T>,\
    \ vector<string>>::type \n      ts_lev(const T& v) {\n        if (lev == 0 ||\
    \ !(int)v.size()) return {ts(v)};\n        vector<string> res;\n        for (const\
    \ auto& t : v) {\n            if ((int)res.size()) res.back() += \",\";\n    \
    \        vector<string> tmp = ts_lev<lev - 1>(t);\n            res.insert(res.end(),\
    \ tmp.begin(), tmp.end());\n        }\n        for (int i = 0; i < (int)res.size();\
    \ ++i) {\n            string bef = \" \"; if (i == 0) bef = \"{\";\n         \
    \   res[i] = bef + res[i];\n        }\n        res.back() += \"}\";\n        return\
    \ res;\n    }\n}\n\ninline namespace Output {\n    template<class T> void pr_sep(ostream&\
    \ os, string, const T& t) { os << ts(t); }\n    template<class T, class... U>\
    \ void pr_sep(ostream& os, string sep, const T& t, const U&... u) {\n        pr_sep(os,\
    \ sep, t); os << sep; pr_sep(os, sep, u...); }\n    // print w/ no spaces\n  \
    \  template<class ...T> void pr(const T&... t) { pr_sep(cout, \"\", t...); } \n\
    \    // print w/ spaces, end with newline\n    void ps() { cout << \"\\n\"; }\n\
    \    template<class ...T> void ps(const T&... t) { pr_sep(cout, \" \", t...);\
    \ ps(); } \n    // debug to cerr\n    template<class ...T> void dbg_out(const\
    \ T&... t) {\n        pr_sep(cerr, \" | \", t...); cerr << endl; }\n    void loc_info(int\
    \ line, string names) {\n        cerr << \"Line(\" << line << \") -> [\" << names\
    \ << \"]: \"; }\n    template<int lev, class T> void dbgl_out(const T& t) {\n\
    \        cerr << \"\\n\\n\" << ts_sep(ts_lev<lev>(t), \"\\n\") << \"\\n\" << endl;\
    \ }\n    #ifdef LOCAL\n        #define dbg(...) loc_info(__LINE__, #__VA_ARGS__),\
    \ dbg_out(__VA_ARGS__)\n        #define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)\n\
    \    #else // don't actually submit with this\n        #define dbg(...) 0\n  \
    \      #define dbgl(lev, x) 0\n    #endif\n}\n\ninline namespace FileIO {\n  \
    \  void set_in(string s)  { freopen(s.c_str(), \"r\", stdin); }\n    void set_out(string\
    \ s) { freopen(s.c_str(), \"w\", stdout); }\n    void setIO(string s = \"\") {\n\
    \        cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams\n     \
    \   // cin.exceptions(cin.failbit);\n        // throws exception when do smth\
    \ illegal\n        // ex. try to read letter into int\n        if (!s.empty())\
    \ set_in(s + \".in\"), set_out(s + \".out\"); // for old USACO\n    }\n}\n\nconst\
    \ int MOD = 1e9 + 7; // 998244353;\nconst ld PI = acos((ld) -1);\n\ntypedef std::decay\
    \ <decltype(MOD)>::type mod_t;\nstruct mi {\n    mod_t val;\n    explicit operator\
    \ mod_t() const { return val; }\n    mi() { val = 0; }\n    mi(const long long&\
    \ v) {\n        val = (-MOD <= v && v <= MOD) ? v : v % MOD;\n        if (val\
    \ < 0) val += MOD; }\n    friend std::istream& operator >> (std::istream& in,\
    \ mi& a) { \n        long long x; std::cin >> x; a = mi(x); return in; }\n   \
    \ friend std::ostream& operator << (std::ostream& os, const mi& a) { return os\
    \ << a.val; }\n    friend void pr(const mi& a) { pr(a.val); }\n    friend void\
    \ re(mi& a) { long long x; cin >> x; a = mi(x); }\n    friend bool operator ==\
    \ (const mi& a, const mi& b) { return a.val == b.val; }\n    friend bool operator\
    \ != (const mi& a, const mi& b) { return !(a == b); }    \n    friend bool operator\
    \ < (const mi& a, const mi& b) { return a.val < b.val; }\n    friend bool operator\
    \ > (const mi& a, const mi& b) { return a.val > b.val; }\n    friend bool operator\
    \ <= (const mi& a, const mi& b) { return a.val <= b.val; }\n    friend bool operator\
    \ >= (const mi& a, const mi& b) { return a.val >= b.val; }\n    mi operator -\
    \ () const { return mi(-val); }\n    mi& operator += (const mi& m) {\n       \
    \ if ((val += m.val) >= MOD) val -= MOD;\n        return *this; }\n    mi& operator\
    \ -= (const mi& m) {\n        if ((val -= m.val) < 0) val += MOD;\n        return\
    \ *this; }\n    mi& operator *= (const mi& m) { val = (long long) val * m.val\
    \ % MOD;\n        return *this; }\n    friend mi pow(mi a, long long p) {\n  \
    \      mi ans = 1; assert(p >= 0);\n        for (; p; p /= 2, a *= a) if (p &\
    \ 1) ans *= a;\n        return ans; }\n    friend mi inv(const mi& a) { assert(a\
    \ != 0); return pow(a, MOD - 2); }\n    mi& operator /= (const mi& m) { return\
    \ (*this) *= inv(m); }\n    friend mi operator + (mi a, const mi& b) { return\
    \ a += b; }\n    friend mi operator - (mi a, const mi& b) { return a -= b; }\n\
    \    friend mi operator * (mi a, const mi& b) { return a *= b; }\n    friend mi\
    \ operator / (mi a, const mi& b) { return a /= b; }\n};\n\ntypedef pair<mi, mi>\
    \ pmi;\ntypedef vector<mi> vmi;\ntypedef vector<pmi> vpmi;\n\nint main() {\n \
    \   setIO(\"\");\n    return 0;\n}\n"
  code: "#pragma GCC optimize (\"O3\")\n#pragma GCC target (\"sse4\")\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/pb_ds/assoc_container.hpp>\n\nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\ntemplate <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;\n\
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
    \ for (int i = (a); i < (b); ++i)\n#define F0R(i, a) FOR(i,0,a)\n#define ROF(i,\
    \ a, b) for (int i = (b) - 1; i >= (a); --i)\n#define R0F(i, a) ROF(i, 0, a)\n\
    #define each(a, x) for (auto& a : x)\n\nmt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 :\
    \ 0; }\ntemplate <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b,\
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
    \ bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))\n\ninline namespace\
    \ Helpers {\n    //////////// is_iterable\n    // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
    \    // this gets used only when we can call begin() and end() on that type\n\
    \    template <class T, class = void> struct is_iterable : false_type {};\n  \
    \  template <class T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),\n\
    \                                      decltype(end(declval<T>()))\n         \
    \                            >\n                           > : true_type {};\n\
    \    template <class T> constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n    //////////// is_readable\n    template <class T, class = void> struct is_readable\
    \ : false_type {};\n    template <class T> struct is_readable<T,\n           \
    \ typename std::enable_if_t<\n                is_same_v<decltype(cin >> declval<T&>()),\
    \ istream&>\n            >\n        > : true_type {};\n    template <class T>\
    \ constexpr bool is_readable_v = is_readable<T>::value;\n\n    //////////// is_printable\n\
    \    // // https://nafe.es/posts/2020-02-29-is-printable/\n    template <class\
    \ T, class = void> struct is_printable : false_type {};\n    template <class T>\
    \ struct is_printable<T,\n            typename std::enable_if_t<\n           \
    \     is_same_v<decltype(cout << declval<T>()), ostream&>\n            >\n   \
    \     > : true_type {};\n    template <class T> constexpr bool is_printable_v\
    \ = is_printable<T>::value;\n}\n\ninline namespace Input {\n    template <class\
    \ T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;\n \
    \   template <class T, class ...U> void re(T& t, U&... u);\n    template <class\
    \ T, class U> void re(pair<T, U>& p); // pairs\n\n    // re: read\n    template\
    \ <class T> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >>\
    \ x; } // default\n    template <class T> void re(complex<T>& c) { T a, b; re(a,\
    \ b); c = {a, b}; } // complex\n    template <class T> typename enable_if<needs_input_v<T>,void>::type\
    \ re(T& i); // ex. vectors, arrays\n    template <class T, class U> void re(pair<T,\
    \ U>& p) { re(p.first, p.second); }\n    template <class T> typename enable_if<needs_input_v<T>,void>::type\
    \ re(T& i) {\n        for (auto& x : i) re(x); }\n    template <class T, class\
    \ ...U> void re(T& t, U&... u) { re(t); re(u...); } // read multiple\n\n    //\
    \ rv: resize and read vectors\n    void rv(size_t) {}\n    template <class T,\
    \ class ...U> void rv(size_t N, vector<T>& t, U&... u);\n    template<class...U>\
    \ void rv(size_t, size_t N2, U&... u);\n    template <class T, class ...U> void\
    \ rv(size_t N, vector<T>& t, U&... u) {\n        t.resize(N); re(t);\n       \
    \ rv(N, u...); }\n    template<class...U> void rv(size_t, size_t N2, U&... u)\
    \ {\n        rv(N2, u...); }\n\n    // dumb shortcuts to read in ints\n    void\
    \ decrement() {} // subtract one from each\n    template <class T, class ...U>\
    \ void decrement(T& t, U&... u) { --t; decrement(u...); }\n    #define ints(...)\
    \ int __VA_ARGS__; re(__VA_ARGS__);\n    #define int1(...) ints(__VA_ARGS__);\
    \ decrement(__VA_ARGS__);\n}\n\ninline namespace ToString {\n    template <class\
    \ T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;\n\
    \n    // ts: string representation to print\n    template <class T> typename enable_if<is_printable_v<T>,\
    \ string>::type ts(T v) {\n        stringstream ss; ss << fixed << setprecision(15)\
    \ << v;\n        return ss.str(); } // default\n    template <class T> string\
    \ bit_vec(T t) { // bit vector to string\n        string res = \"{\"; for (int\
    \ i = 0; i < (int)t.size(); ++i) res += ts(t[i]);\n        res += \"}\"; return\
    \ res; }\n    string ts(vector<bool> v) { return bit_vec(v); }\n    template<size_t\
    \ SZ> string ts(bitset<SZ> b) { return bit_vec(b); } // bit vector\n    template\
    \ <class T, class U> string ts(pair<T, U> p); // pairs\n    template <class T>\
    \ typename enable_if<needs_output_v<T>, string>::type ts(T v); // vectors, arrays\n\
    \    template <class T, class U> string ts(pair<T, U> p) { return \"(\" + ts(p.first)\
    \ + \", \" + ts(p.second) + \")\"; }\n    template <class T> typename enable_if<is_iterable_v<T>,\
    \ string>::type ts_sep(T v, string sep) {\n        // convert container to string\
    \ w/ separator sep\n        bool fst = 1; string res = \"\";\n        for (const\
    \ auto& x : v) {\n            if (!fst) res += sep;\n            fst = 0; res\
    \ += ts(x);\n        }\n        return res;\n    }\n    template <class T> typename\
    \ enable_if<needs_output_v<T>, string>::type ts(T v) {\n        return \"{\" +\
    \ ts_sep(v, \", \") + \"}\"; }\n\n    // for nested DS\n    template<int, class\
    \ T> typename enable_if<!needs_output_v<T>, vector<string>>::type \n      ts_lev(const\
    \ T& v) { return {ts(v)}; }\n    template<int lev, class T> typename enable_if<needs_output_v<T>,\
    \ vector<string>>::type \n      ts_lev(const T& v) {\n        if (lev == 0 ||\
    \ !(int)v.size()) return {ts(v)};\n        vector<string> res;\n        for (const\
    \ auto& t : v) {\n            if ((int)res.size()) res.back() += \",\";\n    \
    \        vector<string> tmp = ts_lev<lev - 1>(t);\n            res.insert(res.end(),\
    \ tmp.begin(), tmp.end());\n        }\n        for (int i = 0; i < (int)res.size();\
    \ ++i) {\n            string bef = \" \"; if (i == 0) bef = \"{\";\n         \
    \   res[i] = bef + res[i];\n        }\n        res.back() += \"}\";\n        return\
    \ res;\n    }\n}\n\ninline namespace Output {\n    template<class T> void pr_sep(ostream&\
    \ os, string, const T& t) { os << ts(t); }\n    template<class T, class... U>\
    \ void pr_sep(ostream& os, string sep, const T& t, const U&... u) {\n        pr_sep(os,\
    \ sep, t); os << sep; pr_sep(os, sep, u...); }\n    // print w/ no spaces\n  \
    \  template<class ...T> void pr(const T&... t) { pr_sep(cout, \"\", t...); } \n\
    \    // print w/ spaces, end with newline\n    void ps() { cout << \"\\n\"; }\n\
    \    template<class ...T> void ps(const T&... t) { pr_sep(cout, \" \", t...);\
    \ ps(); } \n    // debug to cerr\n    template<class ...T> void dbg_out(const\
    \ T&... t) {\n        pr_sep(cerr, \" | \", t...); cerr << endl; }\n    void loc_info(int\
    \ line, string names) {\n        cerr << \"Line(\" << line << \") -> [\" << names\
    \ << \"]: \"; }\n    template<int lev, class T> void dbgl_out(const T& t) {\n\
    \        cerr << \"\\n\\n\" << ts_sep(ts_lev<lev>(t), \"\\n\") << \"\\n\" << endl;\
    \ }\n    #ifdef LOCAL\n        #define dbg(...) loc_info(__LINE__, #__VA_ARGS__),\
    \ dbg_out(__VA_ARGS__)\n        #define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)\n\
    \    #else // don't actually submit with this\n        #define dbg(...) 0\n  \
    \      #define dbgl(lev, x) 0\n    #endif\n}\n\ninline namespace FileIO {\n  \
    \  void set_in(string s)  { freopen(s.c_str(), \"r\", stdin); }\n    void set_out(string\
    \ s) { freopen(s.c_str(), \"w\", stdout); }\n    void setIO(string s = \"\") {\n\
    \        cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams\n     \
    \   // cin.exceptions(cin.failbit);\n        // throws exception when do smth\
    \ illegal\n        // ex. try to read letter into int\n        if (!s.empty())\
    \ set_in(s + \".in\"), set_out(s + \".out\"); // for old USACO\n    }\n}\n\nconst\
    \ int MOD = 1e9 + 7; // 998244353;\nconst ld PI = acos((ld) -1);\n\ntypedef std::decay\
    \ <decltype(MOD)>::type mod_t;\nstruct mi {\n    mod_t val;\n    explicit operator\
    \ mod_t() const { return val; }\n    mi() { val = 0; }\n    mi(const long long&\
    \ v) {\n        val = (-MOD <= v && v <= MOD) ? v : v % MOD;\n        if (val\
    \ < 0) val += MOD; }\n    friend std::istream& operator >> (std::istream& in,\
    \ mi& a) { \n        long long x; std::cin >> x; a = mi(x); return in; }\n   \
    \ friend std::ostream& operator << (std::ostream& os, const mi& a) { return os\
    \ << a.val; }\n    friend void pr(const mi& a) { pr(a.val); }\n    friend void\
    \ re(mi& a) { long long x; cin >> x; a = mi(x); }\n    friend bool operator ==\
    \ (const mi& a, const mi& b) { return a.val == b.val; }\n    friend bool operator\
    \ != (const mi& a, const mi& b) { return !(a == b); }    \n    friend bool operator\
    \ < (const mi& a, const mi& b) { return a.val < b.val; }\n    friend bool operator\
    \ > (const mi& a, const mi& b) { return a.val > b.val; }\n    friend bool operator\
    \ <= (const mi& a, const mi& b) { return a.val <= b.val; }\n    friend bool operator\
    \ >= (const mi& a, const mi& b) { return a.val >= b.val; }\n    mi operator -\
    \ () const { return mi(-val); }\n    mi& operator += (const mi& m) {\n       \
    \ if ((val += m.val) >= MOD) val -= MOD;\n        return *this; }\n    mi& operator\
    \ -= (const mi& m) {\n        if ((val -= m.val) < 0) val += MOD;\n        return\
    \ *this; }\n    mi& operator *= (const mi& m) { val = (long long) val * m.val\
    \ % MOD;\n        return *this; }\n    friend mi pow(mi a, long long p) {\n  \
    \      mi ans = 1; assert(p >= 0);\n        for (; p; p /= 2, a *= a) if (p &\
    \ 1) ans *= a;\n        return ans; }\n    friend mi inv(const mi& a) { assert(a\
    \ != 0); return pow(a, MOD - 2); }\n    mi& operator /= (const mi& m) { return\
    \ (*this) *= inv(m); }\n    friend mi operator + (mi a, const mi& b) { return\
    \ a += b; }\n    friend mi operator - (mi a, const mi& b) { return a -= b; }\n\
    \    friend mi operator * (mi a, const mi& b) { return a *= b; }\n    friend mi\
    \ operator / (mi a, const mi& b) { return a /= b; }\n};\n\ntypedef pair<mi, mi>\
    \ pmi;\ntypedef vector<mi> vmi;\ntypedef vector<pmi> vpmi;\n\nint main() {\n \
    \   setIO(\"\");\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/contest/template_full.cpp
  requiredBy: []
  timestamp: '2021-05-13 12:33:29-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/contest/template_full.cpp
layout: document
redirect_from:
- /library/library/contest/template_full.cpp
- /library/library/contest/template_full.cpp.html
title: library/contest/template_full.cpp
---
