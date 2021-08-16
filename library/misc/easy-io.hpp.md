---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
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
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
    title: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nafe.es/posts/2020-02-29-is-printable/
    - https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
  bundledCode: "\nusing namespace std;\n\ninline namespace Helpers {\n\t////////////\
    \ is_iterable\n\t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
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
    \ re(T& t, U& ...u);\n\ttemplate <class T, class U> void re(pair<T, U>& p); //\
    \ pairs\n\n\t// re: read\n\ttemplate <class T> typename enable_if<is_readable_v<T>,\
    \ void>::type re(T& x) { cin >> x; } // default\n\ttemplate <class T> void re(complex<T>&\
    \ c) { T a, b; re(a, b); c = {a, b}; } // complex\n\ttemplate <class T> typename\
    \ enable_if<needs_input_v<T>, void>::type re(T& i); // ex. vectors, arrays\n\t\
    template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }\n\
    \ttemplate <class T> typename enable_if<needs_input_v<T>, void>::type re(T& i)\
    \ {\n\t\tfor (auto& x : i) re(x); }\n\ttemplate <class T, class ...U> void re(T&\
    \ t, U& ...u) { re(t); re(u...); } // read multiple\n\n\t// rv: resize and read\
    \ vectors\n\tvoid rv(std::size_t) {}\n\ttemplate <class T, class ...U> void rv(std::size_t\
    \ N, vector<T>& t, U& ...u);\n\ttemplate <class...U> void rv(std::size_t, std::size_t\
    \ N2, U& ...u);\n\ttemplate <class T, class ...U> void rv(std::size_t N, vector<T>&\
    \ t, U& ...u) {\n\t\tt.resize(N); re(t);\n\t\trv(N, u...); }\n\ttemplate <class...U>\
    \ void rv(std::size_t, std::size_t N2, U& ...u) {\n\t\trv(N2, u...); }\n\n\t//\
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
    bool fst = 1; string res = \"\";\n\t\tfor (const auto& x : v) {\n\t\t\tif (!fst)\
    \ res += sep;\n\t\t\tfst = 0; res += ts(x);\n\t\t}\n\t\treturn res;\n\t}\n\ttemplate\
    \ <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v) {\n\t\t\
    return \"{\" + ts_sep(v, \", \") + \"}\"; }\n\n\t// for nested DS\n\ttemplate\
    \ <int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type\
    \ \n\t  ts_lev(const T& v) { return {ts(v)}; }\n\ttemplate <int lev, class T>\
    \ typename enable_if<needs_output_v<T>, vector<string>>::type \n\t  ts_lev(const\
    \ T& v) {\n\t\tif (lev == 0 || !(int)v.size()) return {ts(v)};\n\t\tvector<string>\
    \ res;\n\t\tfor (const auto& t : v) {\n\t\t\tif ((int)res.size()) res.back() +=\
    \ \",\";\n\t\t\tvector<string> tmp = ts_lev<lev - 1>(t);\n\t\t\tres.insert(res.end(),\
    \ tmp.begin(), tmp.end());\n\t\t}\n\t\tfor (int i = 0; i < (int)res.size(); ++i)\
    \ {\n\t\t\tstring bef = \" \"; if (i == 0) bef = \"{\";\n\t\t\tres[i] = bef +\
    \ res[i];\n\t\t}\n\t\tres.back() += \"}\";\n\t\treturn res;\n\t}\n}\n\ninline\
    \ namespace Output {\n\ttemplate <class T> void pr_sep(ostream& os, string, const\
    \ T& t) { os << ts(t); }\n\ttemplate <class T, class... U> void pr_sep(ostream&\
    \ os, string sep, const T& t, const U& ...u) {\n\t\tpr_sep(os, sep, t); os <<\
    \ sep; pr_sep(os, sep, u...); }\n\t// print w/ no spaces\n\ttemplate <class ...T>\
    \ void pr(const T& ...t) { pr_sep(cout, \"\", t...); } \n\t// print w/ spaces,\
    \ end with newline\n\tvoid ps() { cout << \"\\n\"; }\n\ttemplate <class ...T>\
    \ void ps(const T& ...t) { pr_sep(cout, \" \", t...); ps(); } \n\t// debug to\
    \ cerr\n\ttemplate <class ...T> void dbg_out(const T& ...t) {\n\t\tpr_sep(cerr,\
    \ \" | \", t...); cerr << endl; }\n\tvoid loc_info(int line, string names) {\n\
    \t\tcerr << \"Line(\" << line << \") -> [\" << names << \"]: \"; }\n\ttemplate\
    \ <int lev, class T> void dbgl_out(const T& t) {\n\t\tcerr << \"\\n\\n\" << ts_sep(ts_lev<lev>(t),\
    \ \"\\n\") << \"\\n\" << endl; }\n\t#ifdef LOCAL\n\t\t#define dbg(...) loc_info(__LINE__,\
    \ #__VA_ARGS__), dbg_out(__VA_ARGS__)\n\t\t#define dbgl(lev, x) loc_info(__LINE__,\
    \ #x), dbgl_out<lev>(x)\n\t#else // don't actually submit with this\n\t\t#define\
    \ dbg(...) 0\n\t\t#define dbgl(lev, x) 0\n\t#endif\n}\n\ninline namespace FileIO\
    \ {\n\tvoid set_in(string s)  { freopen(s.c_str(), \"r\", stdin); }\n\tvoid set_out(string\
    \ s) { freopen(s.c_str(), \"w\", stdout); }\n\tvoid setIO(string s = \"\") {\n\
    \t\tcin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams\n\t\t// cin.exceptions(cin.failbit);\n\
    \t\t// throws exception when do smth illegal\n\t\t// ex. try to read letter into\
    \ int\n\t\tif (!s.empty()) set_in(s + \".in\"), set_out(s + \".out\"); // for\
    \ old USACO\n\t}\n}\n"
  code: "#pragma once\n\nusing namespace std;\n\ninline namespace Helpers {\n\t////////////\
    \ is_iterable\n\t// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
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
    \ re(T& t, U& ...u);\n\ttemplate <class T, class U> void re(pair<T, U>& p); //\
    \ pairs\n\n\t// re: read\n\ttemplate <class T> typename enable_if<is_readable_v<T>,\
    \ void>::type re(T& x) { cin >> x; } // default\n\ttemplate <class T> void re(complex<T>&\
    \ c) { T a, b; re(a, b); c = {a, b}; } // complex\n\ttemplate <class T> typename\
    \ enable_if<needs_input_v<T>, void>::type re(T& i); // ex. vectors, arrays\n\t\
    template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }\n\
    \ttemplate <class T> typename enable_if<needs_input_v<T>, void>::type re(T& i)\
    \ {\n\t\tfor (auto& x : i) re(x); }\n\ttemplate <class T, class ...U> void re(T&\
    \ t, U& ...u) { re(t); re(u...); } // read multiple\n\n\t// rv: resize and read\
    \ vectors\n\tvoid rv(std::size_t) {}\n\ttemplate <class T, class ...U> void rv(std::size_t\
    \ N, vector<T>& t, U& ...u);\n\ttemplate <class...U> void rv(std::size_t, std::size_t\
    \ N2, U& ...u);\n\ttemplate <class T, class ...U> void rv(std::size_t N, vector<T>&\
    \ t, U& ...u) {\n\t\tt.resize(N); re(t);\n\t\trv(N, u...); }\n\ttemplate <class...U>\
    \ void rv(std::size_t, std::size_t N2, U& ...u) {\n\t\trv(N2, u...); }\n\n\t//\
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
    bool fst = 1; string res = \"\";\n\t\tfor (const auto& x : v) {\n\t\t\tif (!fst)\
    \ res += sep;\n\t\t\tfst = 0; res += ts(x);\n\t\t}\n\t\treturn res;\n\t}\n\ttemplate\
    \ <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v) {\n\t\t\
    return \"{\" + ts_sep(v, \", \") + \"}\"; }\n\n\t// for nested DS\n\ttemplate\
    \ <int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type\
    \ \n\t  ts_lev(const T& v) { return {ts(v)}; }\n\ttemplate <int lev, class T>\
    \ typename enable_if<needs_output_v<T>, vector<string>>::type \n\t  ts_lev(const\
    \ T& v) {\n\t\tif (lev == 0 || !(int)v.size()) return {ts(v)};\n\t\tvector<string>\
    \ res;\n\t\tfor (const auto& t : v) {\n\t\t\tif ((int)res.size()) res.back() +=\
    \ \",\";\n\t\t\tvector<string> tmp = ts_lev<lev - 1>(t);\n\t\t\tres.insert(res.end(),\
    \ tmp.begin(), tmp.end());\n\t\t}\n\t\tfor (int i = 0; i < (int)res.size(); ++i)\
    \ {\n\t\t\tstring bef = \" \"; if (i == 0) bef = \"{\";\n\t\t\tres[i] = bef +\
    \ res[i];\n\t\t}\n\t\tres.back() += \"}\";\n\t\treturn res;\n\t}\n}\n\ninline\
    \ namespace Output {\n\ttemplate <class T> void pr_sep(ostream& os, string, const\
    \ T& t) { os << ts(t); }\n\ttemplate <class T, class... U> void pr_sep(ostream&\
    \ os, string sep, const T& t, const U& ...u) {\n\t\tpr_sep(os, sep, t); os <<\
    \ sep; pr_sep(os, sep, u...); }\n\t// print w/ no spaces\n\ttemplate <class ...T>\
    \ void pr(const T& ...t) { pr_sep(cout, \"\", t...); } \n\t// print w/ spaces,\
    \ end with newline\n\tvoid ps() { cout << \"\\n\"; }\n\ttemplate <class ...T>\
    \ void ps(const T& ...t) { pr_sep(cout, \" \", t...); ps(); } \n\t// debug to\
    \ cerr\n\ttemplate <class ...T> void dbg_out(const T& ...t) {\n\t\tpr_sep(cerr,\
    \ \" | \", t...); cerr << endl; }\n\tvoid loc_info(int line, string names) {\n\
    \t\tcerr << \"Line(\" << line << \") -> [\" << names << \"]: \"; }\n\ttemplate\
    \ <int lev, class T> void dbgl_out(const T& t) {\n\t\tcerr << \"\\n\\n\" << ts_sep(ts_lev<lev>(t),\
    \ \"\\n\") << \"\\n\" << endl; }\n\t#ifdef LOCAL\n\t\t#define dbg(...) loc_info(__LINE__,\
    \ #__VA_ARGS__), dbg_out(__VA_ARGS__)\n\t\t#define dbgl(lev, x) loc_info(__LINE__,\
    \ #x), dbgl_out<lev>(x)\n\t#else // don't actually submit with this\n\t\t#define\
    \ dbg(...) 0\n\t\t#define dbgl(lev, x) 0\n\t#endif\n}\n\ninline namespace FileIO\
    \ {\n\tvoid set_in(string s)  { freopen(s.c_str(), \"r\", stdin); }\n\tvoid set_out(string\
    \ s) { freopen(s.c_str(), \"w\", stdout); }\n\tvoid setIO(string s = \"\") {\n\
    \t\tcin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams\n\t\t// cin.exceptions(cin.failbit);\n\
    \t\t// throws exception when do smth illegal\n\t\t// ex. try to read letter into\
    \ int\n\t\tif (!s.empty()) set_in(s + \".in\"), set_out(s + \".out\"); // for\
    \ old USACO\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/easy-io.hpp
  requiredBy:
  - library/contest/template-full.hpp
  timestamp: '2021-08-16 13:31:52-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
  - verify/unit-test/unit-test-hashing.test.cpp
  - verify/unit-test/unit-test-fraction.test.cpp
  - verify/unit-test/unit-test-big-integer.test.cpp
  - verify/unit-test/unit-test-gosper-hack.test.cpp
documentation_of: library/misc/easy-io.hpp
layout: document
redirect_from:
- /library/library/misc/easy-io.hpp
- /library/library/misc/easy-io.hpp.html
title: library/misc/easy-io.hpp
---
