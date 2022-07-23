---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.cpp
    title: library/contest/template-full.cpp
  - icon: ':question:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/unit-test/unit-test-big-integer.test.cpp
    title: verify/unit-test/unit-test-big-integer.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-fraction.test.cpp
    title: verify/unit-test/unit-test-fraction.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-gosper-hack.test.cpp
    title: verify/unit-test/unit-test-gosper-hack.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-hashing.test.cpp
    title: verify/unit-test/unit-test-hashing.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-template-full.test.cpp
    title: verify/unit-test/unit-test-template-full.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
    title: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://nafe.es/posts/2020-02-29-is-printable/
    - https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
  bundledCode: "\r\ninline namespace Helpers {\r\n\t//////////// is_iterable\r\n\t\
    // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\r\
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
    \ set_in(s + \".in\"), set_out(s + \".out\"); // for old USACO\r\n\t}\r\n}\r\n"
  code: "#pragma once\r\n\r\ninline namespace Helpers {\r\n\t//////////// is_iterable\r\
    \n\t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\r\
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
    \ set_in(s + \".in\"), set_out(s + \".out\"); // for old USACO\r\n\t}\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/easy-io.hpp
  requiredBy:
  - library/contest/template-full.cpp
  - library/contest/template-full.hpp
  timestamp: '2022-07-22 23:22:14-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/unit-test/unit-test-fraction.test.cpp
  - verify/unit-test/unit-test-gosper-hack.test.cpp
  - verify/unit-test/unit-test-big-integer.test.cpp
  - verify/unit-test/unit-test-hashing.test.cpp
  - verify/unit-test/unit-test-template-full.test.cpp
  - verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
documentation_of: library/misc/easy-io.hpp
layout: document
redirect_from:
- /library/library/misc/easy-io.hpp
- /library/library/misc/easy-io.hpp.html
title: library/misc/easy-io.hpp
---
