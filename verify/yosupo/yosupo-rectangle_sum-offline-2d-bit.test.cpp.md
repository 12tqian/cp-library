---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
    title: Offline 2D BIT
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\r\
    \n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ninline namespace Helpers\
    \ {\r\n\t//////////// is_iterable\r\n\t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\r\
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
    \ namespace FileIO {\r\n\tvoid set_in(string s)  { freopen(s.c_str(), \"r\", stdin);\
    \ }\r\n\tvoid set_out(string s) { freopen(s.c_str(), \"w\", stdout); }\r\n\tvoid\
    \ set_io(string s = \"\") {\r\n\t\tcin.tie(0)->sync_with_stdio(0); // unsync C\
    \ / C++ I/O streams\r\n\t\t// cin.exceptions(cin.failbit);\r\n\t\t// throws exception\
    \ when do smth illegal\r\n\t\t// ex. try to read letter into int\r\n\t\tif (!s.empty())\
    \ set_in(s + \".in\"), set_out(s + \".out\"); // for old USACO\r\n\t}\r\n}\r\n\
    \r\n/**\r\n * x \\in [0, sz)\r\n * y \\in [0, sz)\r\n * First do all the updates,\
    \ then call init\r\n * Afterwards, do the updates again, and now you can mix in\
    \ the queries too\r\n */\r\n\r\ntemplate <class T> struct Offline2DBIT { \r\n\t\
    bool mode = false; // mode = 1 -> initialized\r\n\tint sz;\r\n\tstd::vector<std::pair<int,\
    \ int>> todo;\r\n\tstd::vector<int> cnt, st, val;\r\n\tstd::vector<T> bit;\r\n\
    \r\n\tvoid init(int sz_) {\r\n\t\tsz = sz_;\r\n\t\tsz++;\r\n\t\tcnt.assign(sz,\
    \ 0);\r\n\t\tst.assign(sz, 0);\r\n\t\tassert(!mode); mode = 1;\r\n\t\tstd::vector<int>\
    \ lst(sz, 0);\r\n\t\tcnt.assign(sz, 0);\r\n\t\tsort(todo.begin(), todo.end(),\
    \ [](const std::pair<int, int>& a, const std::pair<int, int>& b) { \r\n\t\t\t\
    return a.second < b.second; });\r\n\t\tfor (auto& t : todo) \r\n\t\t\tfor (int\
    \ x = t.first; x < sz; x += x & -x)\r\n\t\t\t\tif (lst[x] != t.second)\r\n\t\t\
    \t\t\tlst[x] = t.second, cnt[x]++;\r\n\t\tint sum = 0; \r\n\t\tfor (int i = 0;\
    \ i < sz; i++)\r\n\t\t\tlst[i] = 0, st[i] = (sum += cnt[i]);\r\n\t\tval.resize(sum);\
    \ bit.resize(sum);\r\n\t\treverse(todo.begin(), todo.end());\r\n\t\tfor (auto&\
    \ t : todo) \r\n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\r\n\t\t\t\tif\
    \ (lst[x] != t.second)\r\n\t\t\t\t\tlst[x] = t.second, val[--st[x]] = t.second;\r\
    \n\t}\r\n\r\n\tint rank(int y, int l, int r) {\r\n\t\treturn std::upper_bound(val.begin()\
    \ + l, val.begin() + r, y) - val.begin() - l;\r\n\t}\r\n\r\n\tvoid inner_update(int\
    \ x, int y, T t) {\r\n\t\tfor (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x];\
    \ y += y & -y)\r\n\t\t\tbit[st[x] + y - 1] += t;\r\n\t}\r\n\r\n\tvoid update(int\
    \ x, int y, T t) {\r\n\t\tx++, y++;\r\n\t\tif (!mode) todo.push_back({x, y});\r\
    \n\t\telse \r\n\t\t\tfor (; x < sz; x += x & -x)\r\n\t\t\t\tinner_update(x, y,\
    \ t);\r\n\t}\r\n\r\n\tT inner_query(int x, int y) {\r\n\t\tT res = 0;\r\n\t\t\
    for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y)\r\n\t\t\tres += bit[st[x]\
    \ + y - 1];\r\n\t\treturn res;\r\n\t}\r\n\r\n\tT query(int x, int y) {\r\n\t\t\
    x++, y++;\r\n\t\tassert(mode);\r\n\t\tT res = 0;\r\n\t\tfor (; x; x -= x & -x)\
    \ \r\n\t\t\tres += inner_query(x, y);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tT query(int\
    \ xl, int xr, int yl, int yr) {\r\n\t\treturn query(xr, yr) - query(xl - 1, yr)\
    \ - query(xr, yl - 1) + query(xl - 1, yl - 1);\r\n\t}\r\n};\r\n\r\nint main()\
    \ {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n, q;\r\n\
    \tcin >> n >> q;\r\n\tvector<int> xs, ys;\r\n\tvector<array<int, 3>> pts(n);\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tfor (int j = 0; j < 3; ++j) {\r\n\t\t\
    \tcin >> pts[i][j];\r\n\t\t}\r\n\t\txs.push_back(pts[i][0]);\r\n\t\tys.push_back(pts[i][1]);\r\
    \n\t}\r\n\tvector<array<int, 4>> qs(q);\r\n\tfor (int i = 0; i < q; ++i) {\r\n\
    \t\tcin >> qs[i][0] >> qs[i][2] >> qs[i][1] >> qs[i][3];\r\n\t\t--qs[i][1];\r\n\
    \t\t--qs[i][3];\r\n\t\txs.push_back(qs[i][0]);\r\n\t\txs.push_back(qs[i][1]);\r\
    \n\t\tys.push_back(qs[i][2]);\r\n\t\tys.push_back(qs[i][3]);\r\n\t}\r\n\tauto\
    \ duplicates = [&](vector<int>& v) {\r\n\t\tsort(v.begin(), v.end());\r\n\t\t\
    v.resize(unique(v.begin(), v.end()) - v.begin());\r\n\t};\r\n\tduplicates(xs);\r\
    \n\tduplicates(ys);\r\n\tauto get = [&](vector<int> &v, int x) {\r\n\t\treturn\
    \ lower_bound(v.begin(), v.end(), x) - v.begin();\r\n\t};\t\r\n\tOffline2DBIT<long\
    \ long> O;\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tO.update(get(xs, pts[i][0]),\
    \ get(ys, pts[i][1]), pts[i][2]);\r\n\t}\r\n\tO.init(xs.size() + 5);\r\n\tfor\
    \ (int i = 0; i < n; ++i) {\r\n\t\tO.update(get(xs, pts[i][0]), get(ys, pts[i][1]),\
    \ pts[i][2]);\r\n\t}\r\n\tfor (int i = 0; i < q; ++i) {\r\n\t\tcout << O.query(get(xs,\
    \ qs[i][0]), get(xs, qs[i][1]), get(ys, qs[i][2]), get(ys, qs[i][3])) << '\\n';\r\
    \n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/misc/easy-io.hpp\"\
    \r\n#include \"../../library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp\"\
    \r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<int> xs, ys;\r\n\tvector<array<int,\
    \ 3>> pts(n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tfor (int j = 0; j < 3;\
    \ ++j) {\r\n\t\t\tcin >> pts[i][j];\r\n\t\t}\r\n\t\txs.push_back(pts[i][0]);\r\
    \n\t\tys.push_back(pts[i][1]);\r\n\t}\r\n\tvector<array<int, 4>> qs(q);\r\n\t\
    for (int i = 0; i < q; ++i) {\r\n\t\tcin >> qs[i][0] >> qs[i][2] >> qs[i][1] >>\
    \ qs[i][3];\r\n\t\t--qs[i][1];\r\n\t\t--qs[i][3];\r\n\t\txs.push_back(qs[i][0]);\r\
    \n\t\txs.push_back(qs[i][1]);\r\n\t\tys.push_back(qs[i][2]);\r\n\t\tys.push_back(qs[i][3]);\r\
    \n\t}\r\n\tauto duplicates = [&](vector<int>& v) {\r\n\t\tsort(v.begin(), v.end());\r\
    \n\t\tv.resize(unique(v.begin(), v.end()) - v.begin());\r\n\t};\r\n\tduplicates(xs);\r\
    \n\tduplicates(ys);\r\n\tauto get = [&](vector<int> &v, int x) {\r\n\t\treturn\
    \ lower_bound(v.begin(), v.end(), x) - v.begin();\r\n\t};\t\r\n\tOffline2DBIT<long\
    \ long> O;\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tO.update(get(xs, pts[i][0]),\
    \ get(ys, pts[i][1]), pts[i][2]);\r\n\t}\r\n\tO.init(xs.size() + 5);\r\n\tfor\
    \ (int i = 0; i < n; ++i) {\r\n\t\tO.update(get(xs, pts[i][0]), get(ys, pts[i][1]),\
    \ pts[i][2]);\r\n\t}\r\n\tfor (int i = 0; i < q; ++i) {\r\n\t\tcout << O.query(get(xs,\
    \ qs[i][0]), get(xs, qs[i][1]), get(ys, qs[i][2]), get(ys, qs[i][3])) << '\\n';\r\
    \n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/misc/easy-io.hpp
  - library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
  requiredBy: []
  timestamp: '2022-07-22 23:22:14-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
- /verify/verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp.html
title: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
---
