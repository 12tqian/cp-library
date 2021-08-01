---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/misc/fast-io.hpp
    title: library/misc/fast-io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n\
    #include <bits/stdc++.h>\n\n#include <unistd.h>\n\nstruct Scanner {\n\tint fd\
    \ = -1;\n\tchar line[(1 << 15) + 1];\n\tsize_t st = 0, ed = 0;\n\t\n\tvoid reread()\
    \ {\n\t\tmemmove(line, line + st, ed - st);\n\t\ted -= st;\n\t\tst = 0;\n\t\t\
    ed += ::read(fd, line + ed, (1 << 15) - ed);\n\t\tline[ed] = '\\0';\n\t}\n\t\n\
    \tbool succ() {\n\t\twhile (true) {\n\t\t\tif (st == ed) {\n\t\t\t\treread();\n\
    \t\t\t\tif (st == ed) return false;\n\t\t\t}\n\t\t\twhile (st != ed && isspace(line[st]))\
    \ st++;\n\t\t\tif (st != ed) break;\n\t\t}\n\t\tif (ed - st <= 50) {\n\t\t\tbool\
    \ sep = false;\n\t\t\tfor (size_t i = st; i < ed; i++) {\n\t\t\t\tif (isspace(line[i]))\
    \ {\n\t\t\t\t\tsep = true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (!sep)\
    \ reread();\n\t\t}\n\t\treturn true;\n\t}\n\t\n\ttemplate <class T, std::enable_if_t<std::is_same<T,\
    \ std::string>::value, int> = 0>\n\tbool read_single(T& ref) {\n\t\tif (!succ())\
    \ return false;\n\t\twhile (true) {\n\t\t\tsize_t sz = 0;\n\t\t\twhile (st + sz\
    \ < ed && !isspace(line[st + sz])) sz++;\n\t\t\tref.append(line + st, sz);\n\t\
    \t\tst += sz;\n\t\t\tif (!sz || st != ed) break;\n\t\t\treread();            \n\
    \t\t}\n\t\treturn true;\n\t}\n\t\n\ttemplate <class T, std::enable_if_t<std::is_integral<T>::value,\
    \ int> = 0>\n\tbool read_single(T& ref) {\n\t\tif (!succ()) return false;\n\t\t\
    bool neg = false;\n\t\tif (line[st] == '-') {\n\t\t\tneg = true;\n\t\t\tst++;\n\
    \t\t}\n\t\tref = T(0);\n\t\twhile (isdigit(line[st])) {\n\t\t\tref = 10 * ref\
    \ + (line[st++] & 0xf);\n\t\t}\n\t\tif (neg) ref = -ref;\n\t\treturn true;\n\t\
    }\n\t\n\ttemplate <class T> bool read_single(std::vector<T>& ref) {\n\t\tfor (auto&\
    \ d : ref) {\n\t\t\tif (!read_single(d)) return false;\n\t\t}\n\t\treturn true;\n\
    \t}\n\t\n\tvoid read() {}\n\t\n\ttemplate <class H, class... T> void read(H& h,\
    \ T&... t) {\n\t\tbool f = read_single(h);\n\t\tassert(f);\n\t\tread(t...);\n\t\
    }\n\t\n\tScanner(FILE* fp) : fd(fileno(fp)) {}\n};\n\nstruct Printer {\n  public:\n\
    \ttemplate <bool F = false> void write() {}\n\ttemplate <bool F = false, class\
    \ H, class... T>\n\t\n\tvoid write(const H& h, const T&... t) {\n\t\tif (F) write_single('\
    \ ');\n\t\twrite_single(h);\n\t\twrite<true>(t...);\n\t}\n\t\n\ttemplate <class...\
    \ T> void writeln(const T&... t) {\n\t\twrite(t...);\n\t\twrite_single('\\n');\n\
    \t}\n\n\tPrinter(FILE* _fp) : fp(_fp) {}\n\t~Printer() { flush(); }\n\nprivate:\n\
    \tstatic constexpr size_t SIZE = 1 << 15;\n\tFILE* fp;\n\tchar line[SIZE], small[50];\n\
    \tsize_t pos = 0;\n\t\n\tvoid flush() {\n\t\tfwrite(line, 1, pos, fp);\n\t\tpos\
    \ = 0;\n\t}\n\t\n\tvoid write_single(const char& val) {\n\t\tif (pos == SIZE)\
    \ flush();\n\t\tline[pos++] = val;\n\t}\n\t\n\ttemplate <class T, std::enable_if_t<std::is_integral<T>::value,\
    \ int> = 0>\n\tvoid write_single(T val) {\n\t\tif (pos > (1 << 15) - 50) flush();\n\
    \t\tif (val == 0) {\n\t\t\twrite_single('0');\n\t\t\treturn;\n\t\t}\n\t\tif (val\
    \ < 0) {\n\t\t\twrite_single('-');\n\t\t\tval = -val;  // todo min\n\t\t}\n\t\t\
    size_t len = 0;\n\t\twhile (val) {\n\t\t\tsmall[len++] = char(0x30 | (val % 10));\n\
    \t\t\tval /= 10;\n\t\t}\n\t\tfor (size_t i = 0; i < len; i++) {\n\t\t\tline[pos\
    \ + i] = small[len - 1 - i];\n\t\t}\n\t\tpos += len;\n\t}\n\t\n\tvoid write_single(const\
    \ std::string& s) {\n\t\tfor (char c : s) write_single(c);\n\t}\n\t\n\tvoid write_single(const\
    \ char* s) {\n\t\tsize_t len = strlen(s);\n\t\tfor (size_t i = 0; i < len; i++)\
    \ write_single(s[i]);\n\t}\n\n\ttemplate <class T> void write_single(const std::vector<T>&\
    \ val) {\n\t\tauto n = val.size();\n\t\tfor (size_t i = 0; i < n; i++) {\n\t\t\
    \tif (i) write_single(' ');\n\t\t\twrite_single(val[i]);\n\t\t}\n\t}\n};\n\nScanner\
    \ sc(stdin);\nPrinter pr(stdout);\n\nint main() {\n\tusing namespace std;\n\t\
    int tt;\n\tsc.read(tt);\n\twhile (tt--) {\n\t\tlong long a, b;\n\t\tsc.read(a,\
    \ b);\n\t\tpr.writeln(a + b);\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"../../library/misc/fast-io.hpp\"\n\nScanner sc(stdin);\n\
    Printer pr(stdout);\n\nint main() {\n\tusing namespace std;\n\tint tt;\n\tsc.read(tt);\n\
    \twhile (tt--) {\n\t\tlong long a, b;\n\t\tsc.read(a, b);\n\t\tpr.writeln(a +\
    \ b);\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/misc/fast-io.hpp
  isVerificationFile: true
  path: verify/unit-test/unit-test-fast-io.test.cpp
  requiredBy: []
  timestamp: '2021-08-01 15:42:25-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-fast-io.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-fast-io.test.cpp
- /verify/verify/unit-test/unit-test-fast-io.test.cpp.html
title: verify/unit-test/unit-test-fast-io.test.cpp
---
