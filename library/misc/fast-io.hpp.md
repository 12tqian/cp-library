---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-fast-io.test.cpp
    title: verify/unit-test/unit-test-fast-io.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n#include <unistd.h>\r\n\r\nstruct Scanner {\r\n\tint fd = -1;\r\
    \n\tchar line[(1 << 15) + 1];\r\n\tsize_t st = 0, ed = 0;\r\n\t\r\n\tvoid reread()\
    \ {\r\n\t\tmemmove(line, line + st, ed - st);\r\n\t\ted -= st;\r\n\t\tst = 0;\r\
    \n\t\ted += ::read(fd, line + ed, (1 << 15) - ed);\r\n\t\tline[ed] = '\\0';\r\n\
    \t}\r\n\t\r\n\tbool succ() {\r\n\t\twhile (true) {\r\n\t\t\tif (st == ed) {\r\n\
    \t\t\t\treread();\r\n\t\t\t\tif (st == ed) return false;\r\n\t\t\t}\r\n\t\t\t\
    while (st != ed && isspace(line[st])) st++;\r\n\t\t\tif (st != ed) break;\r\n\t\
    \t}\r\n\t\tif (ed - st <= 50) {\r\n\t\t\tbool sep = false;\r\n\t\t\tfor (size_t\
    \ i = st; i < ed; i++) {\r\n\t\t\t\tif (isspace(line[i])) {\r\n\t\t\t\t\tsep =\
    \ true;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (!sep) reread();\r\
    \n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\ttemplate <class T, std::enable_if_t<std::is_same<T,\
    \ std::string>::value, int> = 0>\r\n\tbool read_single(T& ref) {\r\n\t\tif (!succ())\
    \ return false;\r\n\t\twhile (true) {\r\n\t\t\tsize_t sz = 0;\r\n\t\t\twhile (st\
    \ + sz < ed && !isspace(line[st + sz])) sz++;\r\n\t\t\tref.append(line + st, sz);\r\
    \n\t\t\tst += sz;\r\n\t\t\tif (!sz || st != ed) break;\r\n\t\t\treread();    \
    \        \r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\ttemplate <class T, std::enable_if_t<std::is_integral<T>::value,\
    \ int> = 0>\r\n\tbool read_single(T& ref) {\r\n\t\tif (!succ()) return false;\r\
    \n\t\tbool neg = false;\r\n\t\tif (line[st] == '-') {\r\n\t\t\tneg = true;\r\n\
    \t\t\tst++;\r\n\t\t}\r\n\t\tref = T(0);\r\n\t\twhile (isdigit(line[st])) {\r\n\
    \t\t\tref = 10 * ref + (line[st++] & 0xf);\r\n\t\t}\r\n\t\tif (neg) ref = -ref;\r\
    \n\t\treturn true;\r\n\t}\r\n\t\r\n\ttemplate <class T> bool read_single(std::vector<T>&\
    \ ref) {\r\n\t\tfor (auto& d : ref) {\r\n\t\t\tif (!read_single(d)) return false;\r\
    \n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\tvoid read() {}\r\n\t\r\n\ttemplate\
    \ <class H, class... T> void read(H& h, T&... t) {\r\n\t\tbool f = read_single(h);\r\
    \n\t\tassert(f);\r\n\t\tread(t...);\r\n\t}\r\n\t\r\n\tScanner(FILE* fp) : fd(fileno(fp))\
    \ {}\r\n};\r\n\r\nstruct Printer {\r\n  public:\r\n\ttemplate <bool F = false>\
    \ void write() {}\r\n\ttemplate <bool F = false, class H, class... T>\r\n\t\r\n\
    \tvoid write(const H& h, const T&... t) {\r\n\t\tif (F) write_single(' ');\r\n\
    \t\twrite_single(h);\r\n\t\twrite<true>(t...);\r\n\t}\r\n\t\r\n\ttemplate <class...\
    \ T> void writeln(const T&... t) {\r\n\t\twrite(t...);\r\n\t\twrite_single('\\\
    n');\r\n\t}\r\n\r\n\tPrinter(FILE* _fp) : fp(_fp) {}\r\n\t~Printer() { flush();\
    \ }\r\n\r\nprivate:\r\n\tstatic constexpr size_t SIZE = 1 << 15;\r\n\tFILE* fp;\r\
    \n\tchar line[SIZE], small[50];\r\n\tsize_t pos = 0;\r\n\t\r\n\tvoid flush() {\r\
    \n\t\tfwrite(line, 1, pos, fp);\r\n\t\tpos = 0;\r\n\t}\r\n\t\r\n\tvoid write_single(const\
    \ char& val) {\r\n\t\tif (pos == SIZE) flush();\r\n\t\tline[pos++] = val;\r\n\t\
    }\r\n\t\r\n\ttemplate <class T, std::enable_if_t<std::is_integral<T>::value, int>\
    \ = 0>\r\n\tvoid write_single(T val) {\r\n\t\tif (pos > (1 << 15) - 50) flush();\r\
    \n\t\tif (val == 0) {\r\n\t\t\twrite_single('0');\r\n\t\t\treturn;\r\n\t\t}\r\n\
    \t\tif (val < 0) {\r\n\t\t\twrite_single('-');\r\n\t\t\tval = -val;  // todo min\r\
    \n\t\t}\r\n\t\tsize_t len = 0;\r\n\t\twhile (val) {\r\n\t\t\tsmall[len++] = char(0x30\
    \ | (val % 10));\r\n\t\t\tval /= 10;\r\n\t\t}\r\n\t\tfor (size_t i = 0; i < len;\
    \ i++) {\r\n\t\t\tline[pos + i] = small[len - 1 - i];\r\n\t\t}\r\n\t\tpos += len;\r\
    \n\t}\r\n\t\r\n\tvoid write_single(const std::string& s) {\r\n\t\tfor (char c\
    \ : s) write_single(c);\r\n\t}\r\n\t\r\n\tvoid write_single(const char* s) {\r\
    \n\t\tsize_t len = strlen(s);\r\n\t\tfor (size_t i = 0; i < len; i++) write_single(s[i]);\r\
    \n\t}\r\n\r\n\ttemplate <class T> void write_single(const std::vector<T>& val)\
    \ {\r\n\t\tauto n = val.size();\r\n\t\tfor (size_t i = 0; i < n; i++) {\r\n\t\t\
    \tif (i) write_single(' ');\r\n\t\t\twrite_single(val[i]);\r\n\t\t}\r\n\t}\r\n\
    };\n"
  code: "#pragma once\r\n\r\n#include <unistd.h>\r\n\r\nstruct Scanner {\r\n\tint\
    \ fd = -1;\r\n\tchar line[(1 << 15) + 1];\r\n\tsize_t st = 0, ed = 0;\r\n\t\r\n\
    \tvoid reread() {\r\n\t\tmemmove(line, line + st, ed - st);\r\n\t\ted -= st;\r\
    \n\t\tst = 0;\r\n\t\ted += ::read(fd, line + ed, (1 << 15) - ed);\r\n\t\tline[ed]\
    \ = '\\0';\r\n\t}\r\n\t\r\n\tbool succ() {\r\n\t\twhile (true) {\r\n\t\t\tif (st\
    \ == ed) {\r\n\t\t\t\treread();\r\n\t\t\t\tif (st == ed) return false;\r\n\t\t\
    \t}\r\n\t\t\twhile (st != ed && isspace(line[st])) st++;\r\n\t\t\tif (st != ed)\
    \ break;\r\n\t\t}\r\n\t\tif (ed - st <= 50) {\r\n\t\t\tbool sep = false;\r\n\t\
    \t\tfor (size_t i = st; i < ed; i++) {\r\n\t\t\t\tif (isspace(line[i])) {\r\n\t\
    \t\t\t\tsep = true;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (!sep)\
    \ reread();\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\ttemplate <class T,\
    \ std::enable_if_t<std::is_same<T, std::string>::value, int> = 0>\r\n\tbool read_single(T&\
    \ ref) {\r\n\t\tif (!succ()) return false;\r\n\t\twhile (true) {\r\n\t\t\tsize_t\
    \ sz = 0;\r\n\t\t\twhile (st + sz < ed && !isspace(line[st + sz])) sz++;\r\n\t\
    \t\tref.append(line + st, sz);\r\n\t\t\tst += sz;\r\n\t\t\tif (!sz || st != ed)\
    \ break;\r\n\t\t\treread();            \r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\
    \t\r\n\ttemplate <class T, std::enable_if_t<std::is_integral<T>::value, int> =\
    \ 0>\r\n\tbool read_single(T& ref) {\r\n\t\tif (!succ()) return false;\r\n\t\t\
    bool neg = false;\r\n\t\tif (line[st] == '-') {\r\n\t\t\tneg = true;\r\n\t\t\t\
    st++;\r\n\t\t}\r\n\t\tref = T(0);\r\n\t\twhile (isdigit(line[st])) {\r\n\t\t\t\
    ref = 10 * ref + (line[st++] & 0xf);\r\n\t\t}\r\n\t\tif (neg) ref = -ref;\r\n\t\
    \treturn true;\r\n\t}\r\n\t\r\n\ttemplate <class T> bool read_single(std::vector<T>&\
    \ ref) {\r\n\t\tfor (auto& d : ref) {\r\n\t\t\tif (!read_single(d)) return false;\r\
    \n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\tvoid read() {}\r\n\t\r\n\ttemplate\
    \ <class H, class... T> void read(H& h, T&... t) {\r\n\t\tbool f = read_single(h);\r\
    \n\t\tassert(f);\r\n\t\tread(t...);\r\n\t}\r\n\t\r\n\tScanner(FILE* fp) : fd(fileno(fp))\
    \ {}\r\n};\r\n\r\nstruct Printer {\r\n  public:\r\n\ttemplate <bool F = false>\
    \ void write() {}\r\n\ttemplate <bool F = false, class H, class... T>\r\n\t\r\n\
    \tvoid write(const H& h, const T&... t) {\r\n\t\tif (F) write_single(' ');\r\n\
    \t\twrite_single(h);\r\n\t\twrite<true>(t...);\r\n\t}\r\n\t\r\n\ttemplate <class...\
    \ T> void writeln(const T&... t) {\r\n\t\twrite(t...);\r\n\t\twrite_single('\\\
    n');\r\n\t}\r\n\r\n\tPrinter(FILE* _fp) : fp(_fp) {}\r\n\t~Printer() { flush();\
    \ }\r\n\r\nprivate:\r\n\tstatic constexpr size_t SIZE = 1 << 15;\r\n\tFILE* fp;\r\
    \n\tchar line[SIZE], small[50];\r\n\tsize_t pos = 0;\r\n\t\r\n\tvoid flush() {\r\
    \n\t\tfwrite(line, 1, pos, fp);\r\n\t\tpos = 0;\r\n\t}\r\n\t\r\n\tvoid write_single(const\
    \ char& val) {\r\n\t\tif (pos == SIZE) flush();\r\n\t\tline[pos++] = val;\r\n\t\
    }\r\n\t\r\n\ttemplate <class T, std::enable_if_t<std::is_integral<T>::value, int>\
    \ = 0>\r\n\tvoid write_single(T val) {\r\n\t\tif (pos > (1 << 15) - 50) flush();\r\
    \n\t\tif (val == 0) {\r\n\t\t\twrite_single('0');\r\n\t\t\treturn;\r\n\t\t}\r\n\
    \t\tif (val < 0) {\r\n\t\t\twrite_single('-');\r\n\t\t\tval = -val;  // todo min\r\
    \n\t\t}\r\n\t\tsize_t len = 0;\r\n\t\twhile (val) {\r\n\t\t\tsmall[len++] = char(0x30\
    \ | (val % 10));\r\n\t\t\tval /= 10;\r\n\t\t}\r\n\t\tfor (size_t i = 0; i < len;\
    \ i++) {\r\n\t\t\tline[pos + i] = small[len - 1 - i];\r\n\t\t}\r\n\t\tpos += len;\r\
    \n\t}\r\n\t\r\n\tvoid write_single(const std::string& s) {\r\n\t\tfor (char c\
    \ : s) write_single(c);\r\n\t}\r\n\t\r\n\tvoid write_single(const char* s) {\r\
    \n\t\tsize_t len = strlen(s);\r\n\t\tfor (size_t i = 0; i < len; i++) write_single(s[i]);\r\
    \n\t}\r\n\r\n\ttemplate <class T> void write_single(const std::vector<T>& val)\
    \ {\r\n\t\tauto n = val.size();\r\n\t\tfor (size_t i = 0; i < n; i++) {\r\n\t\t\
    \tif (i) write_single(' ');\r\n\t\t\twrite_single(val[i]);\r\n\t\t}\r\n\t}\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast-io.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit-test/unit-test-fast-io.test.cpp
documentation_of: library/misc/fast-io.hpp
layout: document
redirect_from:
- /library/library/misc/fast-io.hpp
- /library/library/misc/fast-io.hpp.html
title: library/misc/fast-io.hpp
---
