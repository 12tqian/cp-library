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
  bundledCode: "#line 1 \"library/misc/easy_io.cpp\"\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\ninline namespace Helpers {\n    //////////// is_iterable\n\
    \    // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
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
    \ rv: resize and read vectors\n    void rv(std::size_t) {}\n    template <class\
    \ T, class ...U> void rv(std::size_t N, vector<T>& t, U&... u);\n    template\
    \ <class...U> void rv(std::size_t, std::size_t N2, U&... u);\n    template <class\
    \ T, class ...U> void rv(std::size_t N, vector<T>& t, U&... u) {\n        t.resize(N);\
    \ re(t);\n        rv(N, u...); }\n    template <class...U> void rv(std::size_t,\
    \ std::size_t N2, U&... u) {\n        rv(N2, u...); }\n\n    // dumb shortcuts\
    \ to read in ints\n    void decrement() {} // subtract one from each\n    template\
    \ <class T, class ...U> void decrement(T& t, U&... u) { --t; decrement(u...);\
    \ }\n    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);\n    #define int1(...)\
    \ ints(__VA_ARGS__); decrement(__VA_ARGS__);\n}\n\ninline namespace ToString {\n\
    \    template <class T> constexpr bool needs_output_v = !is_printable_v<T> &&\
    \ is_iterable_v<T>;\n\n    // ts: string representation to print\n    template\
    \ <class T> typename enable_if<is_printable_v<T>, string>::type ts(T v) {\n  \
    \      stringstream ss; ss << fixed << setprecision(15) << v;\n        return\
    \ ss.str(); } // default\n    template <class T> string bit_vec(T t) { // bit\
    \ vector to string\n        string res = \"{\"; for (int i = 0; i < (int)t.size();\
    \ ++i) res += ts(t[i]);\n        res += \"}\"; return res; }\n    string ts(vector<bool>\
    \ v) { return bit_vec(v); }\n    template <std::size_t SZ> string ts(bitset<SZ>\
    \ b) { return bit_vec(b); } // bit vector\n    template <class T, class U> string\
    \ ts(pair<T, U> p); // pairs\n    template <class T> typename enable_if<needs_output_v<T>,\
    \ string>::type ts(T v); // vectors, arrays\n    template <class T, class U> string\
    \ ts(pair<T, U> p) { return \"(\" + ts(p.first) + \", \" + ts(p.second) + \")\"\
    ; }\n    template <class T> typename enable_if<is_iterable_v<T>, string>::type\
    \ ts_sep(T v, string sep) {\n        // convert container to string w/ separator\
    \ sep\n        bool fst = 1; string res = \"\";\n        for (const auto& x :\
    \ v) {\n            if (!fst) res += sep;\n            fst = 0; res += ts(x);\n\
    \        }\n        return res;\n    }\n    template <class T> typename enable_if<needs_output_v<T>,\
    \ string>::type ts(T v) {\n        return \"{\" + ts_sep(v, \", \") + \"}\"; }\n\
    \n    // for nested DS\n    template <int, class T> typename enable_if<!needs_output_v<T>,\
    \ vector<string>>::type \n      ts_lev(const T& v) { return {ts(v)}; }\n    template\
    \ <int lev, class T> typename enable_if<needs_output_v<T>, vector<string>>::type\
    \ \n      ts_lev(const T& v) {\n        if (lev == 0 || !(int)v.size()) return\
    \ {ts(v)};\n        vector<string> res;\n        for (const auto& t : v) {\n \
    \           if ((int)res.size()) res.back() += \",\";\n            vector<string>\
    \ tmp = ts_lev<lev - 1>(t);\n            res.insert(res.end(), tmp.begin(), tmp.end());\n\
    \        }\n        for (int i = 0; i < (int)res.size(); ++i) {\n            string\
    \ bef = \" \"; if (i == 0) bef = \"{\";\n            res[i] = bef + res[i];\n\
    \        }\n        res.back() += \"}\";\n        return res;\n    }\n}\n\ninline\
    \ namespace Output {\n    template <class T> void pr_sep(ostream& os, string,\
    \ const T& t) { os << ts(t); }\n    template <class T, class... U> void pr_sep(ostream&\
    \ os, string sep, const T& t, const U&... u) {\n        pr_sep(os, sep, t); os\
    \ << sep; pr_sep(os, sep, u...); }\n    // print w/ no spaces\n    template <class\
    \ ...T> void pr(const T&... t) { pr_sep(cout, \"\", t...); } \n    // print w/\
    \ spaces, end with newline\n    void ps() { cout << \"\\n\"; }\n    template <class\
    \ ...T> void ps(const T&... t) { pr_sep(cout, \" \", t...); ps(); } \n    // debug\
    \ to cerr\n    template <class ...T> void dbg_out(const T&... t) {\n        pr_sep(cerr,\
    \ \" | \", t...); cerr << endl; }\n    void loc_info(int line, string names) {\n\
    \        cerr << \"Line(\" << line << \") -> [\" << names << \"]: \"; }\n    template\
    \ <int lev, class T> void dbgl_out(const T& t) {\n        cerr << \"\\n\\n\" <<\
    \ ts_sep(ts_lev<lev>(t), \"\\n\") << \"\\n\" << endl; }\n    #ifdef LOCAL\n  \
    \      #define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)\n\
    \        #define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)\n    #else\
    \ // don't actually submit with this\n        #define dbg(...) 0\n        #define\
    \ dbgl(lev, x) 0\n    #endif\n}\n\ninline namespace FileIO {\n    void set_in(string\
    \ s)  { freopen(s.c_str(), \"r\", stdin); }\n    void set_out(string s) { freopen(s.c_str(),\
    \ \"w\", stdout); }\n    void setIO(string s = \"\") {\n        cin.tie(0)->sync_with_stdio(0);\
    \ // unsync C / C++ I/O streams\n        // cin.exceptions(cin.failbit);\n   \
    \     // throws exception when do smth illegal\n        // ex. try to read letter\
    \ into int\n        if (!s.empty()) set_in(s + \".in\"), set_out(s + \".out\"\
    ); // for old USACO\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\ninline namespace Helpers\
    \ {\n    //////////// is_iterable\n    // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable\n\
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
    \ rv: resize and read vectors\n    void rv(std::size_t) {}\n    template <class\
    \ T, class ...U> void rv(std::size_t N, vector<T>& t, U&... u);\n    template\
    \ <class...U> void rv(std::size_t, std::size_t N2, U&... u);\n    template <class\
    \ T, class ...U> void rv(std::size_t N, vector<T>& t, U&... u) {\n        t.resize(N);\
    \ re(t);\n        rv(N, u...); }\n    template <class...U> void rv(std::size_t,\
    \ std::size_t N2, U&... u) {\n        rv(N2, u...); }\n\n    // dumb shortcuts\
    \ to read in ints\n    void decrement() {} // subtract one from each\n    template\
    \ <class T, class ...U> void decrement(T& t, U&... u) { --t; decrement(u...);\
    \ }\n    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);\n    #define int1(...)\
    \ ints(__VA_ARGS__); decrement(__VA_ARGS__);\n}\n\ninline namespace ToString {\n\
    \    template <class T> constexpr bool needs_output_v = !is_printable_v<T> &&\
    \ is_iterable_v<T>;\n\n    // ts: string representation to print\n    template\
    \ <class T> typename enable_if<is_printable_v<T>, string>::type ts(T v) {\n  \
    \      stringstream ss; ss << fixed << setprecision(15) << v;\n        return\
    \ ss.str(); } // default\n    template <class T> string bit_vec(T t) { // bit\
    \ vector to string\n        string res = \"{\"; for (int i = 0; i < (int)t.size();\
    \ ++i) res += ts(t[i]);\n        res += \"}\"; return res; }\n    string ts(vector<bool>\
    \ v) { return bit_vec(v); }\n    template <std::size_t SZ> string ts(bitset<SZ>\
    \ b) { return bit_vec(b); } // bit vector\n    template <class T, class U> string\
    \ ts(pair<T, U> p); // pairs\n    template <class T> typename enable_if<needs_output_v<T>,\
    \ string>::type ts(T v); // vectors, arrays\n    template <class T, class U> string\
    \ ts(pair<T, U> p) { return \"(\" + ts(p.first) + \", \" + ts(p.second) + \")\"\
    ; }\n    template <class T> typename enable_if<is_iterable_v<T>, string>::type\
    \ ts_sep(T v, string sep) {\n        // convert container to string w/ separator\
    \ sep\n        bool fst = 1; string res = \"\";\n        for (const auto& x :\
    \ v) {\n            if (!fst) res += sep;\n            fst = 0; res += ts(x);\n\
    \        }\n        return res;\n    }\n    template <class T> typename enable_if<needs_output_v<T>,\
    \ string>::type ts(T v) {\n        return \"{\" + ts_sep(v, \", \") + \"}\"; }\n\
    \n    // for nested DS\n    template <int, class T> typename enable_if<!needs_output_v<T>,\
    \ vector<string>>::type \n      ts_lev(const T& v) { return {ts(v)}; }\n    template\
    \ <int lev, class T> typename enable_if<needs_output_v<T>, vector<string>>::type\
    \ \n      ts_lev(const T& v) {\n        if (lev == 0 || !(int)v.size()) return\
    \ {ts(v)};\n        vector<string> res;\n        for (const auto& t : v) {\n \
    \           if ((int)res.size()) res.back() += \",\";\n            vector<string>\
    \ tmp = ts_lev<lev - 1>(t);\n            res.insert(res.end(), tmp.begin(), tmp.end());\n\
    \        }\n        for (int i = 0; i < (int)res.size(); ++i) {\n            string\
    \ bef = \" \"; if (i == 0) bef = \"{\";\n            res[i] = bef + res[i];\n\
    \        }\n        res.back() += \"}\";\n        return res;\n    }\n}\n\ninline\
    \ namespace Output {\n    template <class T> void pr_sep(ostream& os, string,\
    \ const T& t) { os << ts(t); }\n    template <class T, class... U> void pr_sep(ostream&\
    \ os, string sep, const T& t, const U&... u) {\n        pr_sep(os, sep, t); os\
    \ << sep; pr_sep(os, sep, u...); }\n    // print w/ no spaces\n    template <class\
    \ ...T> void pr(const T&... t) { pr_sep(cout, \"\", t...); } \n    // print w/\
    \ spaces, end with newline\n    void ps() { cout << \"\\n\"; }\n    template <class\
    \ ...T> void ps(const T&... t) { pr_sep(cout, \" \", t...); ps(); } \n    // debug\
    \ to cerr\n    template <class ...T> void dbg_out(const T&... t) {\n        pr_sep(cerr,\
    \ \" | \", t...); cerr << endl; }\n    void loc_info(int line, string names) {\n\
    \        cerr << \"Line(\" << line << \") -> [\" << names << \"]: \"; }\n    template\
    \ <int lev, class T> void dbgl_out(const T& t) {\n        cerr << \"\\n\\n\" <<\
    \ ts_sep(ts_lev<lev>(t), \"\\n\") << \"\\n\" << endl; }\n    #ifdef LOCAL\n  \
    \      #define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)\n\
    \        #define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)\n    #else\
    \ // don't actually submit with this\n        #define dbg(...) 0\n        #define\
    \ dbgl(lev, x) 0\n    #endif\n}\n\ninline namespace FileIO {\n    void set_in(string\
    \ s)  { freopen(s.c_str(), \"r\", stdin); }\n    void set_out(string s) { freopen(s.c_str(),\
    \ \"w\", stdout); }\n    void setIO(string s = \"\") {\n        cin.tie(0)->sync_with_stdio(0);\
    \ // unsync C / C++ I/O streams\n        // cin.exceptions(cin.failbit);\n   \
    \     // throws exception when do smth illegal\n        // ex. try to read letter\
    \ into int\n        if (!s.empty()) set_in(s + \".in\"), set_out(s + \".out\"\
    ); // for old USACO\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/easy_io.cpp
  requiredBy: []
  timestamp: '2021-05-25 20:29:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/easy_io.cpp
layout: document
redirect_from:
- /library/library/misc/easy_io.cpp
- /library/library/misc/easy_io.cpp.html
title: library/misc/easy_io.cpp
---
