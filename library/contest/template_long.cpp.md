---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/contest/template_long.cpp\"\n#pragma GCC optimize\
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
    \ bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))\n\nnamespace\
    \ input {\n\ttemplate <class T> void re(complex<T>& x);\n\ttemplate <class T1,\
    \ class T2> void re(pair<T1, T2>& p);\n\ttemplate <class T> void re(vector<T>&\
    \ a);\n\ttemplate <class T, int SZ> void re(array<T, SZ>& a);\n\ttemplate <class\
    \ T> void re(T& x) { cin >> x; }\n\tvoid re(double& x) { string t; re(t); x =\
    \ stod(t); }\n\tvoid re(ld& x) { string t; re(t); x = stold(t); }\n\ttemplate\
    \ <class T, class... Ts> void re(T& t, Ts&... ts) {\n\t\tre(t); re(ts...); }\n\
    \ttemplate <class T> void re(complex<T>& x) { T a, b; re(a, b); x = cd(a, b);\
    \ }\n\ttemplate <class T1, class T2> void re(pair<T1, T2>& p) { re(p.f, p.s);\
    \ }\n\ttemplate <class T> void re(vector<T>& a) { F0R(i, sz(a)) re(a[i]); }\n\t\
    template <class T, int SZ> void re(array<T, SZ>& a) { F0R(i, SZ) re(a[i]); }\n\
    }\n\nusing namespace input;\n\nnamespace output {\n\tvoid pr(int x) { cout <<\
    \ x; }\n\tvoid pr(long x) { cout << x; }\n\tvoid pr(ll x) { cout << x; }\n\tvoid\
    \ pr(unsigned x) { cout << x; }\n\tvoid pr(unsigned long x) { cout << x; }\n\t\
    void pr(unsigned long long x) { cout << x; }\n\tvoid pr(float x) { cout << x;\
    \ }\n\tvoid pr(double x) { cout << x; }\n\tvoid pr(ld x) { cout << x; }\n\tvoid\
    \ pr(char x) { cout << x; }\n\tvoid pr(const char* x) { cout << x; }\n\tvoid pr(const\
    \ string& x) { cout << x; }\n\tvoid pr(bool x) { pr(x ? \"true\" : \"false\");\
    \ }\n\ttemplate <class T> void pr(const complex<T>& x) { cout << x; }\n\ttemplate\
    \ <class T1, class T2> void pr(const pair<T1, T2>& x);\n\ttemplate <class T> void\
    \ pr(const T& x);\n\ttemplate <class T, class... Ts> void pr(const T& t, const\
    \ Ts&... ts) {\n\t\tpr(t); pr(ts...); }\n\ttemplate <class T1, class T2> void\
    \ pr(const pair<T1,T2>& x) {\n\t\tpr(\"{\", x.f, \", \", x.s, \"}\"); }\n\ttemplate\
    \ <class T> void pr(const T& x) {\n\t\tpr(\"{\"); // const iterator needed for\
    \ vector<bool>\n\t\tbool fst = 1; for (const auto& a: x) pr(!fst ? \", \" : \"\
    \", a), fst = 0;\n\t\tpr(\"}\"); }\n\tvoid ps() { pr(\"\\n\"); } // print w/ spaces\n\
    \ttemplate <class T, class... Ts> void ps(const T& t, const Ts&... ts) {\n\t\t\
    pr(t); if (sizeof...(ts)) pr(\" \"); ps(ts...); }\n\tvoid pc() { pr(\"]\\n\");\
    \ } // debug w/ commas\n\ttemplate <class T, class... Ts> void pc(const T& t,\
    \ const Ts&... ts) {\n\t\tpr(t); if (sizeof...(ts)) pr(\", \"); pc(ts...); }\n\
    }\n\nusing namespace output;\n\nnamespace io {\n\tvoid setIn(string s) { freopen(s.c_str(),\
    \ \"r\", stdin); }\n\tvoid setOut(string s) { freopen(s.c_str(), \"w\", stdout);\
    \ }\n\tvoid setIO(string s = \"\") {\n\t\tcin.sync_with_stdio(0); cin.tie(0);\n\
    \t\tif (sz(s)) { setIn(s + \".in\"), setOut(s + \".out\"); }\n\t}\n}\n\nusing\
    \ namespace io;\n\nconst int MOD = 1e9 + 7; // 998244353;\nconst ld PI = acos((ld)\
    \ -1);\n\ntypedef std::decay <decltype(MOD)>::type mod_t;\nstruct mi {\n\tmod_t\
    \ val;\n\texplicit operator mod_t() const { return val; }\n\tmi() { val = 0; }\n\
    \tmi(const long long& v) {\n\t\tval = (-MOD <= v && v <= MOD) ? v : v % MOD;\n\
    \t\tif (val < 0) val += MOD; }\n\tfriend std::istream& operator >> (std::istream&\
    \ in, mi& a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\tfriend\
    \ std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val;\
    \ }\n\tfriend void pr(const mi& a) { pr(a.val); }\n\tfriend void re(mi& a) { long\
    \ long x; cin >> x; a = mi(x); }\n\tfriend bool operator == (const mi& a, const\
    \ mi& b) { return a.val == b.val; }\n\tfriend bool operator != (const mi& a, const\
    \ mi& b) { return !(a == b); }    \n\tfriend bool operator < (const mi& a, const\
    \ mi& b) { return a.val < b.val; }\n\tfriend bool operator > (const mi& a, const\
    \ mi& b) { return a.val > b.val; }\n\tfriend bool operator <= (const mi& a, const\
    \ mi& b) { return a.val <= b.val; }\n\tfriend bool operator >= (const mi& a, const\
    \ mi& b) { return a.val >= b.val; }\n\tmi operator - () const { return mi(-val);\
    \ }\n\tmi& operator += (const mi& m) {\n\t\tif ((val += m.val) >= MOD) val -=\
    \ MOD;\n\t\treturn *this; }\n\tmi& operator -= (const mi& m) {\n\t\tif ((val -=\
    \ m.val) < 0) val += MOD;\n\t\treturn *this; }\n\tmi& operator *= (const mi& m)\
    \ { val = (long long) val * m.val % MOD;\n\t\treturn *this; }\n\tfriend mi pow(mi\
    \ a, long long p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a\
    \ *= a) if (p & 1) ans *= a;\n\t\treturn ans; }\n\tfriend mi inv(const mi& a)\
    \ { assert(a != 0); return pow(a, MOD - 2); }\n\tmi& operator /= (const mi& m)\
    \ { return (*this) *= inv(m); }\n\tfriend mi operator + (mi a, const mi& b) {\
    \ return a += b; }\n\tfriend mi operator - (mi a, const mi& b) { return a -= b;\
    \ }\n\tfriend mi operator * (mi a, const mi& b) { return a *= b; }\n\tfriend mi\
    \ operator / (mi a, const mi& b) { return a /= b; }\n};\ntypedef pair<mi, mi>\
    \ pmi;\ntypedef vector<mi> vmi;\ntypedef vector<pmi> vpmi;\n\nint main() {\n\t\
    setIO(\"\");\n\treturn 0;\n}\n"
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
    \ bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))\n\nnamespace\
    \ input {\n\ttemplate <class T> void re(complex<T>& x);\n\ttemplate <class T1,\
    \ class T2> void re(pair<T1, T2>& p);\n\ttemplate <class T> void re(vector<T>&\
    \ a);\n\ttemplate <class T, int SZ> void re(array<T, SZ>& a);\n\ttemplate <class\
    \ T> void re(T& x) { cin >> x; }\n\tvoid re(double& x) { string t; re(t); x =\
    \ stod(t); }\n\tvoid re(ld& x) { string t; re(t); x = stold(t); }\n\ttemplate\
    \ <class T, class... Ts> void re(T& t, Ts&... ts) {\n\t\tre(t); re(ts...); }\n\
    \ttemplate <class T> void re(complex<T>& x) { T a, b; re(a, b); x = cd(a, b);\
    \ }\n\ttemplate <class T1, class T2> void re(pair<T1, T2>& p) { re(p.f, p.s);\
    \ }\n\ttemplate <class T> void re(vector<T>& a) { F0R(i, sz(a)) re(a[i]); }\n\t\
    template <class T, int SZ> void re(array<T, SZ>& a) { F0R(i, SZ) re(a[i]); }\n\
    }\n\nusing namespace input;\n\nnamespace output {\n\tvoid pr(int x) { cout <<\
    \ x; }\n\tvoid pr(long x) { cout << x; }\n\tvoid pr(ll x) { cout << x; }\n\tvoid\
    \ pr(unsigned x) { cout << x; }\n\tvoid pr(unsigned long x) { cout << x; }\n\t\
    void pr(unsigned long long x) { cout << x; }\n\tvoid pr(float x) { cout << x;\
    \ }\n\tvoid pr(double x) { cout << x; }\n\tvoid pr(ld x) { cout << x; }\n\tvoid\
    \ pr(char x) { cout << x; }\n\tvoid pr(const char* x) { cout << x; }\n\tvoid pr(const\
    \ string& x) { cout << x; }\n\tvoid pr(bool x) { pr(x ? \"true\" : \"false\");\
    \ }\n\ttemplate <class T> void pr(const complex<T>& x) { cout << x; }\n\ttemplate\
    \ <class T1, class T2> void pr(const pair<T1, T2>& x);\n\ttemplate <class T> void\
    \ pr(const T& x);\n\ttemplate <class T, class... Ts> void pr(const T& t, const\
    \ Ts&... ts) {\n\t\tpr(t); pr(ts...); }\n\ttemplate <class T1, class T2> void\
    \ pr(const pair<T1,T2>& x) {\n\t\tpr(\"{\", x.f, \", \", x.s, \"}\"); }\n\ttemplate\
    \ <class T> void pr(const T& x) {\n\t\tpr(\"{\"); // const iterator needed for\
    \ vector<bool>\n\t\tbool fst = 1; for (const auto& a: x) pr(!fst ? \", \" : \"\
    \", a), fst = 0;\n\t\tpr(\"}\"); }\n\tvoid ps() { pr(\"\\n\"); } // print w/ spaces\n\
    \ttemplate <class T, class... Ts> void ps(const T& t, const Ts&... ts) {\n\t\t\
    pr(t); if (sizeof...(ts)) pr(\" \"); ps(ts...); }\n\tvoid pc() { pr(\"]\\n\");\
    \ } // debug w/ commas\n\ttemplate <class T, class... Ts> void pc(const T& t,\
    \ const Ts&... ts) {\n\t\tpr(t); if (sizeof...(ts)) pr(\", \"); pc(ts...); }\n\
    }\n\nusing namespace output;\n\nnamespace io {\n\tvoid setIn(string s) { freopen(s.c_str(),\
    \ \"r\", stdin); }\n\tvoid setOut(string s) { freopen(s.c_str(), \"w\", stdout);\
    \ }\n\tvoid setIO(string s = \"\") {\n\t\tcin.sync_with_stdio(0); cin.tie(0);\n\
    \t\tif (sz(s)) { setIn(s + \".in\"), setOut(s + \".out\"); }\n\t}\n}\n\nusing\
    \ namespace io;\n\nconst int MOD = 1e9 + 7; // 998244353;\nconst ld PI = acos((ld)\
    \ -1);\n\ntypedef std::decay <decltype(MOD)>::type mod_t;\nstruct mi {\n\tmod_t\
    \ val;\n\texplicit operator mod_t() const { return val; }\n\tmi() { val = 0; }\n\
    \tmi(const long long& v) {\n\t\tval = (-MOD <= v && v <= MOD) ? v : v % MOD;\n\
    \t\tif (val < 0) val += MOD; }\n\tfriend std::istream& operator >> (std::istream&\
    \ in, mi& a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\tfriend\
    \ std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val;\
    \ }\n\tfriend void pr(const mi& a) { pr(a.val); }\n\tfriend void re(mi& a) { long\
    \ long x; cin >> x; a = mi(x); }\n\tfriend bool operator == (const mi& a, const\
    \ mi& b) { return a.val == b.val; }\n\tfriend bool operator != (const mi& a, const\
    \ mi& b) { return !(a == b); }    \n\tfriend bool operator < (const mi& a, const\
    \ mi& b) { return a.val < b.val; }\n\tfriend bool operator > (const mi& a, const\
    \ mi& b) { return a.val > b.val; }\n\tfriend bool operator <= (const mi& a, const\
    \ mi& b) { return a.val <= b.val; }\n\tfriend bool operator >= (const mi& a, const\
    \ mi& b) { return a.val >= b.val; }\n\tmi operator - () const { return mi(-val);\
    \ }\n\tmi& operator += (const mi& m) {\n\t\tif ((val += m.val) >= MOD) val -=\
    \ MOD;\n\t\treturn *this; }\n\tmi& operator -= (const mi& m) {\n\t\tif ((val -=\
    \ m.val) < 0) val += MOD;\n\t\treturn *this; }\n\tmi& operator *= (const mi& m)\
    \ { val = (long long) val * m.val % MOD;\n\t\treturn *this; }\n\tfriend mi pow(mi\
    \ a, long long p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a\
    \ *= a) if (p & 1) ans *= a;\n\t\treturn ans; }\n\tfriend mi inv(const mi& a)\
    \ { assert(a != 0); return pow(a, MOD - 2); }\n\tmi& operator /= (const mi& m)\
    \ { return (*this) *= inv(m); }\n\tfriend mi operator + (mi a, const mi& b) {\
    \ return a += b; }\n\tfriend mi operator - (mi a, const mi& b) { return a -= b;\
    \ }\n\tfriend mi operator * (mi a, const mi& b) { return a *= b; }\n\tfriend mi\
    \ operator / (mi a, const mi& b) { return a /= b; }\n};\ntypedef pair<mi, mi>\
    \ pmi;\ntypedef vector<mi> vmi;\ntypedef vector<pmi> vpmi;\n\nint main() {\n\t\
    setIO(\"\");\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/contest/template_long.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/contest/template_long.cpp
layout: document
redirect_from:
- /library/library/contest/template_long.cpp
- /library/library/contest/template_long.cpp.html
title: library/contest/template_long.cpp
---
