---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':warning:'
    path: library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
    title: library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
  - icon: ':warning:'
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
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
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
    \ old USACO\n\t}\n}\n\n/**\n * x \\in [0, sz)\n * y \\in [0, sz)\n * First do\
    \ all the updates, then call init\n * Afterwards, do the updates again, and now\
    \ you can mix in the queries too\n */\n\ntemplate <class T> struct Offline2DBIT\
    \ { \n\tbool mode = false; // mode = 1 -> initialized\n\tint sz;\n\tstd::vector<std::pair<int,\
    \ int>> todo;\n\tstd::vector<int> cnt, st, val;\n\tstd::vector<T> bit;\n\n\tvoid\
    \ init(int sz_) {\n\t\tsz = sz_;\n\t\tsz++;\n\t\tcnt.assign(sz, 0);\n\t\tst.assign(sz,\
    \ 0);\n\t\tassert(!mode); mode = 1;\n\t\tstd::vector<int> lst(sz, 0);\n\t\tcnt.assign(sz,\
    \ 0);\n\t\tsort(todo.begin(), todo.end(), [](const std::pair<int, int>& a, const\
    \ std::pair<int, int>& b) { \n\t\t\treturn a.second < b.second; });\n\t\tfor (auto\
    \ &t : todo) \n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\n\t\t\t\tif (lst[x]\
    \ != t.second)\n\t\t\t\t\tlst[x] = t.second, cnt[x]++;\n\t\tint sum = 0; \n\t\t\
    for (int i = 0; i < sz; i++)\n\t\t\tlst[i] = 0, st[i] = (sum += cnt[i]);\n\t\t\
    val.resize(sum); bit.resize(sum);\n\t\treverse(todo.begin(), todo.end());\n\t\t\
    for (auto &t : todo) \n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\n\t\t\t\
    \tif (lst[x] != t.second)\n\t\t\t\t\tlst[x] = t.second, val[--st[x]] = t.second;\n\
    \t}\n\n\tint rank(int y, int l, int r) {\n\t\treturn std::upper_bound(val.begin()\
    \ + l, val.begin() + r, y) - val.begin() - l;\n\t}\n\n\tvoid inner_update(int\
    \ x, int y, T t) {\n\t\tfor (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x];\
    \ y += y & -y)\n\t\t\tbit[st[x] + y - 1] += t;\n\t}\n\n\tvoid update(int x, int\
    \ y, T t) {\n\t\tx++, y++;\n\t\tif (!mode) todo.push_back({x, y});\n\t\telse \n\
    \t\t\tfor (; x < sz; x += x & -x)\n\t\t\t\tinner_update(x, y, t);\n\t}\n\n\tint\
    \ inner_query(int x, int y) {\n\t\tT res = 0;\n\t\tfor (y = rank(y, st[x], st[x]\
    \ + cnt[x]); y; y -= y & -y)\n\t\t\tres += bit[st[x] + y - 1];\n\t\treturn res;\n\
    \t}\n\n\tT query(int x, int y) {\n\t\tx++, y++;\n\t\tassert(mode);\n\t\tT res\
    \ = 0;\n\t\tfor (; x; x -= x & -x) \n\t\t\tres += inner_query(x, y);\n\t\treturn\
    \ res;\n\t}\n\t\n\tT query(int xl, int xr, int yl, int yr) {\n\t\treturn query(xr,\
    \ yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);\n\t}\n\
    };\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint\
    \ n, q;\n\tcin >> n >> q;\n\tvector<int> xs, ys;\n\tvector<array<int, 3>> pts(n);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < 3; ++j) {\n\t\t\tcin\
    \ >> pts[i][j];\n\t\t}\n\t\txs.push_back(pts[i][0]);\n\t\tys.push_back(pts[i][1]);\n\
    \t}\n\tvector<array<int, 4>> qs(q);\n\tfor (int i = 0; i < q; ++i) {\n\t\tcin\
    \ >> qs[i][0] >> qs[i][2] >> qs[i][1] >> qs[i][3];\n\t\t--qs[i][1];\n\t\t--qs[i][3];\n\
    \t\txs.push_back(qs[i][0]);\n\t\txs.push_back(qs[i][1]);\n\t\tys.push_back(qs[i][2]);\n\
    \t\tys.push_back(qs[i][3]);\n\t}\n\tauto duplicates = [&](vector<int>& v) {\n\t\
    \tsort(v.begin(), v.end());\n\t\tv.resize(unique(v.begin(), v.end()) - v.begin());\n\
    \t};\n\tduplicates(xs);\n\tduplicates(ys);\n\tauto get = [&](vector<int> &v, int\
    \ x) {\n\t\treturn lower_bound(v.begin(), v.end(), x) - v.begin();\n\t};\t\n\t\
    Offline2DBIT<long long> O;\n\tfor (int i = 0; i < n; ++i) {\n\t\tO.update(get(xs,\
    \ pts[i][0]), get(ys, pts[i][1]), pts[i][2]);\n\t}\n\tO.init(xs.size() + 5);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tO.update(get(xs, pts[i][0]), get(ys, pts[i][1]),\
    \ pts[i][2]);\n\t}\n\tfor (int i = 0; i < q; ++i) {\n\t\tcout << O.query(get(xs,\
    \ qs[i][0]), get(xs, qs[i][1]), get(ys, qs[i][2]), get(ys, qs[i][3])) << '\\n';\n\
    \t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../library/contest/template-minimal.hpp\"\n#include \"../library/misc/easy-io.hpp\"\
    \n#include \"../library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tvector<int> xs, ys;\n\tvector<array<int, 3>> pts(n);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < 3; ++j) {\n\t\t\tcin\
    \ >> pts[i][j];\n\t\t}\n\t\txs.push_back(pts[i][0]);\n\t\tys.push_back(pts[i][1]);\n\
    \t}\n\tvector<array<int, 4>> qs(q);\n\tfor (int i = 0; i < q; ++i) {\n\t\tcin\
    \ >> qs[i][0] >> qs[i][2] >> qs[i][1] >> qs[i][3];\n\t\t--qs[i][1];\n\t\t--qs[i][3];\n\
    \t\txs.push_back(qs[i][0]);\n\t\txs.push_back(qs[i][1]);\n\t\tys.push_back(qs[i][2]);\n\
    \t\tys.push_back(qs[i][3]);\n\t}\n\tauto duplicates = [&](vector<int>& v) {\n\t\
    \tsort(v.begin(), v.end());\n\t\tv.resize(unique(v.begin(), v.end()) - v.begin());\n\
    \t};\n\tduplicates(xs);\n\tduplicates(ys);\n\tauto get = [&](vector<int> &v, int\
    \ x) {\n\t\treturn lower_bound(v.begin(), v.end(), x) - v.begin();\n\t};\t\n\t\
    Offline2DBIT<long long> O;\n\tfor (int i = 0; i < n; ++i) {\n\t\tO.update(get(xs,\
    \ pts[i][0]), get(ys, pts[i][1]), pts[i][2]);\n\t}\n\tO.init(xs.size() + 5);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tO.update(get(xs, pts[i][0]), get(ys, pts[i][1]),\
    \ pts[i][2]);\n\t}\n\tfor (int i = 0; i < q; ++i) {\n\t\tcout << O.query(get(xs,\
    \ qs[i][0]), get(xs, qs[i][1]), get(ys, qs[i][2]), get(ys, qs[i][3])) << '\\n';\n\
    \t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/misc/easy-io.hpp
  - library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
  isVerificationFile: false
  path: test/offline-2d-binary-indexed-tree.cpp
  requiredBy: []
  timestamp: '2021-07-25 17:11:24-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/offline-2d-binary-indexed-tree.cpp
layout: document
redirect_from:
- /library/test/offline-2d-binary-indexed-tree.cpp
- /library/test/offline-2d-binary-indexed-tree.cpp.html
title: test/offline-2d-binary-indexed-tree.cpp
---
