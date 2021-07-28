---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':warning:'
    path: library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp
    title: library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/easy-io.hpp
    title: library/misc/easy-io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#define IGNORE\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nusing namespace std;\n\ninline namespace Helpers {\n\t//////////// is_iterable\n\
    \t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
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
    \ old USACO\n\t}\n}\n\n// bump allocator\n\nstatic char buf[450 << 20];\nvoid*\
    \ operator new(size_t s) {\n\tstatic size_t i = sizeof buf;\n\tassert(s < i);\n\
    \treturn (void*)&buf[i -= s];\n}\nvoid operator delete(void*) {}\n\nconst int\
    \ SZ = (1 << 17);\n\ntemplate <class T> struct Node {\n\tT val = 0; \n\tNode<T>\
    \ *c[2];\n\tNode() { c[0] = c[1] = NULL; }\n\n\tvoid upd(int ind, T v, int L =\
    \ 0, int R = SZ - 1) { // add v\n\t\tif (L == ind && R == ind) { val += v; return;\
    \ }\n\t\tint M = (L + R) / 2;\n\t\tif (ind <= M) {\n\t\t\tif (!c[0]) c[0] = new\
    \ Node();\n\t\t\tc[0]->upd(ind, v, L, M);\n\t\t} else {\n\t\t\tif (!c[1]) c[1]\
    \ = new Node();\n\t\t\tc[1]->upd(ind, v, M + 1, R);\n\t\t}\n\t\tval = 0; \n\t\t\
    for (int i = 0; i < 2; i++)\n\t\t\tif (c[i]) val += c[i]->val;\n\t}\n\n\tT query(int\
    \ lo, int hi, int L = 0, int R = SZ - 1) { // query sum of segment\n\t\tif (hi\
    \ < L || R < lo) return 0;\n\t\tif (lo <= L && R <= hi) return val;\n\t\tint M\
    \ = (L + R) / 2; \n\t\tT res = 0;\n\t\tif (c[0]) res += c[0]->query(lo, hi, L,\
    \ M);\n\t\tif (c[1]) res += c[1]->query(lo, hi, M + 1, R);\n\t\treturn res;\n\t\
    }\n\n\tvoid update_2d(int ind, Node *c0, Node *c1, int L = 0, int R = SZ - 1)\
    \ { // for 2D segtree\n\t\tif (L != R) {\n\t\t\tint M = (L + R) / 2;\n\t\t\tif\
    \ (ind <= M) {\n\t\t\t\tif (!c[0]) c[0] = new Node();\n\t\t\t\tc[0]->update_2d(ind,\
    \ (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL), L, M);\n\t\t\t} else {\n\t\t\
    \t\tif (!c[1]) c[1] = new Node();\n\t\t\t\tc[1]->update_2d(ind, (c0 ? c0->c[1]\
    \ : NULL), (c1 ? c1->c[1] : NULL), M + 1, R);\n\t\t\t}\n\t\t} \n\t\tval = (c0\
    \ ? c0->val : 0) + (c1 ? c1->val : 0);\n\t}\n};\n\ntemplate <class T> struct Node2D\
    \ {\n\tNode<T> seg; \n\tNode2D *c[2];\n\n\tNode2D() { c[0] = c[1] = NULL; }\n\n\
    \tvoid upd(int x, int y, T v, int L = 0, int R = SZ - 1) { // add v\n\t\tif (L\
    \ == x && R == x) { seg.upd(y, v); return; }\n\t\tint M = (L + R) / 2;\n\t\tif\
    \ (x <= M) {\n\t\t\tif (!c[0]) c[0] = new Node2D();\n\t\t\tc[0]->upd(x, y, v,\
    \ L, M);\n\t\t} else {\n\t\t\tif (!c[1]) c[1] = new Node2D();\n\t\t\tc[1]->upd(x,\
    \ y, v, M + 1, R);\n\t\t}\n\t\tseg.upd(y, v); // only for addition\n\t\t// seg.update_2d(y,\
    \ (c[0] ? & c[0]->seg : NULL), (c[1] ? & c[1]->seg : NULL));\n\t}\n\n\tT query(int\
    \ x1, int x2, int y1, int y2, int L = 0, int R = SZ - 1) { // query sum of rectangle\n\
    \t\tif (x1 <= L && R <= x2) return seg.query(y1, y2);\n\t\tif (x2 < L || R < x1)\
    \ return 0;\n\t\tint M = (L + R) / 2; \n\t\tT res = 0;\n\t\tif (c[0]) res += c[0]->query(x1,\
    \ x2, y1, y2, L, M);\n\t\tif (c[1]) res += c[1]->query(x1, x2, y1, y2, M + 1,\
    \ R);\n\t\treturn res;\n\t}\n};\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tfreopen(\"input.txt\", \"r\", stdin);\n\tint n, q;\n\t\
    cin >> n >> q;\n\tvector<int> xs, ys;\n\tdbg(n, q);\n\tvector<array<int, 3>> pts(n);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < 3; ++j) {\n\t\t\tcin\
    \ >> pts[i][j];\n\t\t}\n\t\txs.push_back(pts[i][0]);\n\t\tys.push_back(pts[i][1]);\n\
    \t}\n\tvector<array<int, 4>> qs(q);\n\tfor (int i = 0; i < q; ++i) {\n\t\tcin\
    \ >> qs[i][0] >> qs[i][2] >> qs[i][1] >> qs[i][3];\n\t\t--qs[i][1];\n\t\t--qs[i][3];\n\
    \t\txs.push_back(qs[i][0]);\n\t\txs.push_back(qs[i][1]);\n\t\tys.push_back(qs[i][2]);\n\
    \t\tys.push_back(qs[i][3]);\n\t}\n\tauto duplicates = [&](vector<int>& v) {\n\t\
    \tsort(v.begin(), v.end());\n\t\tv.resize(unique(v.begin(), v.end()) - v.begin());\n\
    \t};\n\tduplicates(xs);\n\tduplicates(ys);\n\tauto get = [&](vector<int> &v, int\
    \ x) {\n\t\treturn lower_bound(v.begin(), v.end(), x) - v.begin();\n\t};\t\n\t\
    Node2D<int> O;\n\tfor (int i = 0; i < n; ++i) {\n\t\tO.upd(get(xs, pts[i][0]),\
    \ get(ys, pts[i][1]), pts[i][2]);\n\t}\n\tfor (int i = 0; i < q; ++i) {\n\t\t\
    cout << O.query(get(xs, qs[i][0]), get(xs, qs[i][1]), get(ys, qs[i][2]), get(ys,\
    \ qs[i][3])) << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define IGNORE\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/misc/easy-io.hpp\"\
    \n#include \"../../library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tfreopen(\"\
    input.txt\", \"r\", stdin);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<int> xs,\
    \ ys;\n\tdbg(n, q);\n\tvector<array<int, 3>> pts(n);\n\tfor (int i = 0; i < n;\
    \ ++i) {\n\t\tfor (int j = 0; j < 3; ++j) {\n\t\t\tcin >> pts[i][j];\n\t\t}\n\t\
    \txs.push_back(pts[i][0]);\n\t\tys.push_back(pts[i][1]);\n\t}\n\tvector<array<int,\
    \ 4>> qs(q);\n\tfor (int i = 0; i < q; ++i) {\n\t\tcin >> qs[i][0] >> qs[i][2]\
    \ >> qs[i][1] >> qs[i][3];\n\t\t--qs[i][1];\n\t\t--qs[i][3];\n\t\txs.push_back(qs[i][0]);\n\
    \t\txs.push_back(qs[i][1]);\n\t\tys.push_back(qs[i][2]);\n\t\tys.push_back(qs[i][3]);\n\
    \t}\n\tauto duplicates = [&](vector<int>& v) {\n\t\tsort(v.begin(), v.end());\n\
    \t\tv.resize(unique(v.begin(), v.end()) - v.begin());\n\t};\n\tduplicates(xs);\n\
    \tduplicates(ys);\n\tauto get = [&](vector<int> &v, int x) {\n\t\treturn lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n\t};\t\n\tNode2D<int> O;\n\tfor (int i = 0; i < n;\
    \ ++i) {\n\t\tO.upd(get(xs, pts[i][0]), get(ys, pts[i][1]), pts[i][2]);\n\t}\n\
    \tfor (int i = 0; i < q; ++i) {\n\t\tcout << O.query(get(xs, qs[i][0]), get(xs,\
    \ qs[i][1]), get(ys, qs[i][2]), get(ys, qs[i][3])) << '\\n';\n\t}\n\treturn 0;\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/misc/easy-io.hpp
  - library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp
  isVerificationFile: false
  path: verify/unverified/2d-sparse-segment-tree.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:56:26-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/unverified/2d-sparse-segment-tree.cpp
layout: document
redirect_from:
- /library/verify/unverified/2d-sparse-segment-tree.cpp
- /library/verify/unverified/2d-sparse-segment-tree.cpp.html
title: verify/unverified/2d-sparse-segment-tree.cpp
---
