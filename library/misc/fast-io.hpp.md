---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <unistd.h>\n\nnamespace FastIO {\n\nnamespace Internal {\n\
    \ntemplate <class T>\nusing is_signed_int128 =\n\ttypename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n\t\t\t\t\t\t\t\t  std::is_same<T, __int128>::value,\n\
    \t\t\t\t\t\t\t  std::true_type,\n\t\t\t\t\t\t\t  std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int128 =\n\ttypename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n\t\t\t\t\t\t\t\t  std::is_same<T, unsigned __int128>::value,\n\
    \t\t\t\t\t\t\t  std::true_type,\n\t\t\t\t\t\t\t  std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing make_unsigned_int128 =\n\ttypename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n\t\t\t\t\t\t\t  __uint128_t,\n\t\t\t\t\t\t\t  unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral =\n\ttypename std::conditional<std::is_integral<T>::value\
    \ ||\n\t\t\t\t\t\t\t\t  Internal::is_signed_int128<T>::value ||\n\t\t\t\t\t\t\t\
    \t  Internal::is_unsigned_int128<T>::value,\n\t\t\t\t\t\t\t  std::true_type,\n\
    \t\t\t\t\t\t\t  std::false_type>::type;\n\ntemplate <class T>\nusing is_signed_int\
    \ = typename std::conditional<(is_integral<T>::value &&\n\t\t\t\t\t\t\t\t\t\t\t\
    \t std::is_signed<T>::value) ||\n\t\t\t\t\t\t\t\t\t\t\t\t\tis_signed_int128<T>::value,\n\
    \t\t\t\t\t\t\t\t\t\t\t\tstd::true_type,\n\t\t\t\t\t\t\t\t\t\t\t\tstd::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int =\n\ttypename std::conditional<(is_integral<T>::value\
    \ &&\n\t\t\t\t\t\t\t   std::is_unsigned<T>::value) ||\n\t\t\t\t\t\t\t\t  is_unsigned_int128<T>::value,\n\
    \t\t\t\t\t\t\t  std::true_type,\n\t\t\t\t\t\t\t  std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing to_unsigned = typename std::conditional<\n\tis_signed_int128<T>::value,\n\
    \tmake_unsigned_int128<T>,\n\ttypename std::conditional<std::is_signed<T>::value,\n\
    \t\t\t\t\t\t\t  std::make_unsigned<T>,\n\t\t\t\t\t\t\t  std::common_type<T>>::type>::type;\n\
    \ntemplate <class T>\nusing is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    \ntemplate <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace Internal\n\n\nstruct Scanner {\npublic:\n\tScanner(FILE* fp) :\
    \ fd(fileno(fp)) {}\n\n\tvoid read() {}\n\ttemplate <class H, class... T> void\
    \ read(H &h, T &...t) {\n\t\tbool f = read_single(h);\n\t\tassert(f);\n\t\tread(t...);\n\
    \t}\n\n\tint read_unsafe() { return 0; }\n\ttemplate <class H, class... T> int\
    \ read_unsafe(H &h, T &...t) {\n\t\tbool f = read_single(h);\n\t\tif (!f) return\
    \ 0;\n\t\treturn 1 + read_unsafe(t...);\n\t}\n\nprivate:\n\tstatic constexpr size_t\
    \ SIZE = 1 << 15;\n\n\tbool read_single(std::string &ref) {\n\t\tif (!skip_space())\
    \ return false;\n\t\tref = \"\";\n\t\twhile (true) {\n\t\t\tchar c = top();\n\t\
    \t\tif (c <= ' ') break;\n\t\t\tref += c;\n\t\t\tst++;\n\t\t}\n\t\treturn true;\n\
    \t}\n\tbool read_single(double &ref) {\n\t\tstd::string s;\n\t\tif (!read_single(s))\
    \ return false;\n\t\tref = std::stod(s);\n\t\treturn true;\n\t}\n\n\ttemplate\
    \ <class T, Internal::is_signed_int_t<T>* = nullptr>\n\tbool read_single(T &sref)\
    \ {\n\t\tusing U = Internal::to_unsigned_t<T>;\n\t\tif (!skip_space(50)) return\
    \ false;\n\t\tbool neg = false;\n\t\tif (line[st] == '-') {\n\t\t\tneg = true;\n\
    \t\t\tst++;\n\t\t}\n\t\tU ref = 0;\n\t\tdo {\n\t\t\tref = 10 * ref + (line[st++]\
    \ & 0x0f);\n\t\t} while (line[st] >= '0');\n\t\tsref = neg ? -ref : ref;\n\t\t\
    return true;\n\t}\n\ttemplate <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n\
    \tbool read_single(U &ref) {\n\t\tif (!skip_space(50)) return false;\n\t\tref\
    \ = 0;\n\t\tdo {\n\t\t\tref = 10 * ref + (line[st++] & 0x0f);\n\t\t} while (line[st]\
    \ >= '0');\n\t\treturn true;\n\t}\n\n\tint fd = -1;\n\tchar line[SIZE];\n\tsize_t\
    \ st = 0, ed = 0;\n\tbool eof = false;\n\tbool reread() {\n\t\tif (ed - st >=\
    \ 50) return true;\n\t\tif (st > SIZE / 2) {\n\t\t\tstd::memmove(line, line +\
    \ st, ed - st);\n\t\t\ted -= st;\n\t\t\tst = 0;\n\t\t}\n\t\tif (eof) return false;\n\
    \t\tauto u = ::read(fd, line + ed, SIZE - ed);\n\t\tif (u == 0) {\n\t\t\teof =\
    \ true;\n\t\t\tline[ed] = '\\0';\n\t\t\tu = 1;\n\t\t}\n\t\ted += u;\n\t\treturn\
    \ true;\n\t}\n\n\tchar top() {\n\t\tif (st == ed) {\n\t\t\tbool f = reread();\n\
    \t\t\tassert(f);\n\t\t}\n\t\treturn line[st];\n\t}\n\n\tbool skip_space(unsigned\
    \ int token_len = 0) {\n\t\twhile (true) {\n\t\t\twhile (st != ed && line[st]\
    \ <= ' ') st++;\n\t\t\tif (ed - st > token_len) return true;\n\t\t\tfor (auto\
    \ i = st; i < ed; i++) {\n\t\t\t\tif (line[i] <= ' ') return true;\n\t\t\t}\n\t\
    \t\tif (!reread()) return false;\n\t\t}\n\t}\n};\n\nstruct Printer {\npublic:\n\
    \ttemplate <bool F = false> void write() {}\n\ttemplate <bool F = false, class\
    \ H, class... T>\n\tvoid write(const H &h, const T &...t) {\n\t\tif (F) write_single('\
    \ ');\n\t\twrite_single(h);\n\t\twrite<true>(t...);\n\t}\n\ttemplate <class...\
    \ T> void writeln(const T &...t) {\n\t\twrite(t...);\n\t\twrite_single('\\n');\n\
    \t}\n\n\tPrinter(FILE *_fp) : fd(fileno(_fp)) {}\n\t~Printer() { flush(); }\n\n\
    \tvoid flush() {\n\t\t::write(fd, line, pos);\n\t\tpos = 0;\n\t}\n\nprivate:\n\
    \tstatic std::array<std::array<char, 2>, 100> small;\n\tstatic std::array<unsigned\
    \ long long, 20> tens;\n\n\tstatic constexpr size_t SIZE = 1 << 15;\n\tint fd;\n\
    \tchar line[SIZE];\n\tsize_t pos = 0;\n\tvoid write_single(const char &val) {\n\
    \t\tif (pos == SIZE) flush();\n\t\tline[pos++] = val;\n\t}\n\n\ttemplate <class\
    \ T, Internal::is_signed_int_t<T>* = nullptr>\n\tvoid write_single(const T &val)\
    \ {\n\t\tusing U = Internal::to_unsigned_t<T>;\n\t\tif (val == 0) {\n\t\t\twrite_single('0');\n\
    \t\t\treturn;\n\t\t}\n\t\tif (pos > SIZE - 50) flush();\n\t\tU uval = val;\n\t\
    \tif (val < 0) {\n\t\t\twrite_single('-');\n\t\t\tuval = -uval;\n\t\t}\n\t\twrite_unsigned(uval);\n\
    \t}\n\n\ttemplate <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n\tvoid\
    \ write_single(U uval) {\n\t\tif (uval == 0) {\n\t\t\twrite_single('0');\n\t\t\
    \treturn;\n\t\t}\n\t\tif (pos > SIZE - 50) flush();\n\n\t\twrite_unsigned(uval);\n\
    \t}\n\n\ttemplate <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n\tstatic\
    \ int calc_len(U x) {\n\t\tint i = (bsr(x) * 3 + 3) / 10;\n\t\tif (x < tens[i])\n\
    \t\t\treturn i;\n\t\telse\n\t\t\treturn i + 1;\n\t}\n\n\ttemplate <class U,\n\t\
    \t\t  Internal::is_unsigned_int_t<U>* = nullptr,\n\t\t\t  std::enable_if_t<sizeof(U)\
    \ <= 8>* = nullptr>\n\tvoid write_unsigned(U uval) {\n\t\tsize_t len = calc_len(uval);\n\
    \t\tpos += len;\n\n\t\tchar *ptr = line + pos;\n\t\twhile (uval >= 100) {\n\t\t\
    \tptr -= 2;\n\t\t\tmemcpy(ptr, small[uval % 100].data(), 2);\n\t\t\tuval /= 100;\n\
    \t\t}\n\t\tif (uval >= 10) {\n\t\t\tmemcpy(ptr - 2, small[uval].data(), 2);\n\t\
    \t} else {\n\t\t\t*(ptr - 1) = char('0' + uval);\n\t\t}\n\t}\n\n\ttemplate <\n\
    \t\tclass U,\n\t\tstd::enable_if_t<Internal::is_unsigned_int128<U>::value>* =\
    \ nullptr>\n\tvoid write_unsigned(U uval) {\n\t\tstatic char buf[50];\n\t\tsize_t\
    \ len = 0;\n\t\twhile (uval > 0) {\n\t\t\tbuf[len++] = char((uval % 10) + '0');\n\
    \t\t\tuval /= 10;\n\t\t}\n\t\tstd::reverse(buf, buf + len);\n\t\tmemcpy(line +\
    \ pos, buf, len);\n\t\tpos += len;\n\t}\n\n\tvoid write_single(const std::string\
    \ &s) {\n\t\tfor (char c : s) write_single(c);\n\t}\n\tvoid write_single(const\
    \ char *s) {\n\t\tsize_t len = strlen(s);\n\t\tfor (size_t i = 0; i < len; i++)\
    \ write_single(s[i]);\n\t}\n\ttemplate <class T> void write_single(const std::vector<T>\
    \ &val) {\n\t\tauto n = val.size();\n\t\tfor (size_t i = 0; i < n; i++) {\n\t\t\
    \tif (i) write_single(' ');\n\t\t\twrite_single(val[i]);\n\t\t}\n\t}\n};\n\n}\
    \  // FastIO\n"
  code: "#pragma once\n#include <unistd.h>\n\nnamespace FastIO {\n\nnamespace Internal\
    \ {\n\ntemplate <class T>\nusing is_signed_int128 =\n\ttypename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n\t\t\t\t\t\t\t\t  std::is_same<T, __int128>::value,\n\
    \t\t\t\t\t\t\t  std::true_type,\n\t\t\t\t\t\t\t  std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int128 =\n\ttypename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n\t\t\t\t\t\t\t\t  std::is_same<T, unsigned __int128>::value,\n\
    \t\t\t\t\t\t\t  std::true_type,\n\t\t\t\t\t\t\t  std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing make_unsigned_int128 =\n\ttypename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n\t\t\t\t\t\t\t  __uint128_t,\n\t\t\t\t\t\t\t  unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral =\n\ttypename std::conditional<std::is_integral<T>::value\
    \ ||\n\t\t\t\t\t\t\t\t  Internal::is_signed_int128<T>::value ||\n\t\t\t\t\t\t\t\
    \t  Internal::is_unsigned_int128<T>::value,\n\t\t\t\t\t\t\t  std::true_type,\n\
    \t\t\t\t\t\t\t  std::false_type>::type;\n\ntemplate <class T>\nusing is_signed_int\
    \ = typename std::conditional<(is_integral<T>::value &&\n\t\t\t\t\t\t\t\t\t\t\t\
    \t std::is_signed<T>::value) ||\n\t\t\t\t\t\t\t\t\t\t\t\t\tis_signed_int128<T>::value,\n\
    \t\t\t\t\t\t\t\t\t\t\t\tstd::true_type,\n\t\t\t\t\t\t\t\t\t\t\t\tstd::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int =\n\ttypename std::conditional<(is_integral<T>::value\
    \ &&\n\t\t\t\t\t\t\t   std::is_unsigned<T>::value) ||\n\t\t\t\t\t\t\t\t  is_unsigned_int128<T>::value,\n\
    \t\t\t\t\t\t\t  std::true_type,\n\t\t\t\t\t\t\t  std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing to_unsigned = typename std::conditional<\n\tis_signed_int128<T>::value,\n\
    \tmake_unsigned_int128<T>,\n\ttypename std::conditional<std::is_signed<T>::value,\n\
    \t\t\t\t\t\t\t  std::make_unsigned<T>,\n\t\t\t\t\t\t\t  std::common_type<T>>::type>::type;\n\
    \ntemplate <class T>\nusing is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    \ntemplate <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace Internal\n\n\nstruct Scanner {\npublic:\n\tScanner(FILE* fp) :\
    \ fd(fileno(fp)) {}\n\n\tvoid read() {}\n\ttemplate <class H, class... T> void\
    \ read(H &h, T &...t) {\n\t\tbool f = read_single(h);\n\t\tassert(f);\n\t\tread(t...);\n\
    \t}\n\n\tint read_unsafe() { return 0; }\n\ttemplate <class H, class... T> int\
    \ read_unsafe(H &h, T &...t) {\n\t\tbool f = read_single(h);\n\t\tif (!f) return\
    \ 0;\n\t\treturn 1 + read_unsafe(t...);\n\t}\n\nprivate:\n\tstatic constexpr size_t\
    \ SIZE = 1 << 15;\n\n\tbool read_single(std::string &ref) {\n\t\tif (!skip_space())\
    \ return false;\n\t\tref = \"\";\n\t\twhile (true) {\n\t\t\tchar c = top();\n\t\
    \t\tif (c <= ' ') break;\n\t\t\tref += c;\n\t\t\tst++;\n\t\t}\n\t\treturn true;\n\
    \t}\n\tbool read_single(double &ref) {\n\t\tstd::string s;\n\t\tif (!read_single(s))\
    \ return false;\n\t\tref = std::stod(s);\n\t\treturn true;\n\t}\n\n\ttemplate\
    \ <class T, Internal::is_signed_int_t<T>* = nullptr>\n\tbool read_single(T &sref)\
    \ {\n\t\tusing U = Internal::to_unsigned_t<T>;\n\t\tif (!skip_space(50)) return\
    \ false;\n\t\tbool neg = false;\n\t\tif (line[st] == '-') {\n\t\t\tneg = true;\n\
    \t\t\tst++;\n\t\t}\n\t\tU ref = 0;\n\t\tdo {\n\t\t\tref = 10 * ref + (line[st++]\
    \ & 0x0f);\n\t\t} while (line[st] >= '0');\n\t\tsref = neg ? -ref : ref;\n\t\t\
    return true;\n\t}\n\ttemplate <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n\
    \tbool read_single(U &ref) {\n\t\tif (!skip_space(50)) return false;\n\t\tref\
    \ = 0;\n\t\tdo {\n\t\t\tref = 10 * ref + (line[st++] & 0x0f);\n\t\t} while (line[st]\
    \ >= '0');\n\t\treturn true;\n\t}\n\n\tint fd = -1;\n\tchar line[SIZE];\n\tsize_t\
    \ st = 0, ed = 0;\n\tbool eof = false;\n\tbool reread() {\n\t\tif (ed - st >=\
    \ 50) return true;\n\t\tif (st > SIZE / 2) {\n\t\t\tstd::memmove(line, line +\
    \ st, ed - st);\n\t\t\ted -= st;\n\t\t\tst = 0;\n\t\t}\n\t\tif (eof) return false;\n\
    \t\tauto u = ::read(fd, line + ed, SIZE - ed);\n\t\tif (u == 0) {\n\t\t\teof =\
    \ true;\n\t\t\tline[ed] = '\\0';\n\t\t\tu = 1;\n\t\t}\n\t\ted += u;\n\t\treturn\
    \ true;\n\t}\n\n\tchar top() {\n\t\tif (st == ed) {\n\t\t\tbool f = reread();\n\
    \t\t\tassert(f);\n\t\t}\n\t\treturn line[st];\n\t}\n\n\tbool skip_space(unsigned\
    \ int token_len = 0) {\n\t\twhile (true) {\n\t\t\twhile (st != ed && line[st]\
    \ <= ' ') st++;\n\t\t\tif (ed - st > token_len) return true;\n\t\t\tfor (auto\
    \ i = st; i < ed; i++) {\n\t\t\t\tif (line[i] <= ' ') return true;\n\t\t\t}\n\t\
    \t\tif (!reread()) return false;\n\t\t}\n\t}\n};\n\nstruct Printer {\npublic:\n\
    \ttemplate <bool F = false> void write() {}\n\ttemplate <bool F = false, class\
    \ H, class... T>\n\tvoid write(const H &h, const T &...t) {\n\t\tif (F) write_single('\
    \ ');\n\t\twrite_single(h);\n\t\twrite<true>(t...);\n\t}\n\ttemplate <class...\
    \ T> void writeln(const T &...t) {\n\t\twrite(t...);\n\t\twrite_single('\\n');\n\
    \t}\n\n\tPrinter(FILE *_fp) : fd(fileno(_fp)) {}\n\t~Printer() { flush(); }\n\n\
    \tvoid flush() {\n\t\t::write(fd, line, pos);\n\t\tpos = 0;\n\t}\n\nprivate:\n\
    \tstatic std::array<std::array<char, 2>, 100> small;\n\tstatic std::array<unsigned\
    \ long long, 20> tens;\n\n\tstatic constexpr size_t SIZE = 1 << 15;\n\tint fd;\n\
    \tchar line[SIZE];\n\tsize_t pos = 0;\n\tvoid write_single(const char &val) {\n\
    \t\tif (pos == SIZE) flush();\n\t\tline[pos++] = val;\n\t}\n\n\ttemplate <class\
    \ T, Internal::is_signed_int_t<T>* = nullptr>\n\tvoid write_single(const T &val)\
    \ {\n\t\tusing U = Internal::to_unsigned_t<T>;\n\t\tif (val == 0) {\n\t\t\twrite_single('0');\n\
    \t\t\treturn;\n\t\t}\n\t\tif (pos > SIZE - 50) flush();\n\t\tU uval = val;\n\t\
    \tif (val < 0) {\n\t\t\twrite_single('-');\n\t\t\tuval = -uval;\n\t\t}\n\t\twrite_unsigned(uval);\n\
    \t}\n\n\ttemplate <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n\tvoid\
    \ write_single(U uval) {\n\t\tif (uval == 0) {\n\t\t\twrite_single('0');\n\t\t\
    \treturn;\n\t\t}\n\t\tif (pos > SIZE - 50) flush();\n\n\t\twrite_unsigned(uval);\n\
    \t}\n\n\ttemplate <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n\tstatic\
    \ int calc_len(U x) {\n\t\tint i = (bsr(x) * 3 + 3) / 10;\n\t\tif (x < tens[i])\n\
    \t\t\treturn i;\n\t\telse\n\t\t\treturn i + 1;\n\t}\n\n\ttemplate <class U,\n\t\
    \t\t  Internal::is_unsigned_int_t<U>* = nullptr,\n\t\t\t  std::enable_if_t<sizeof(U)\
    \ <= 8>* = nullptr>\n\tvoid write_unsigned(U uval) {\n\t\tsize_t len = calc_len(uval);\n\
    \t\tpos += len;\n\n\t\tchar *ptr = line + pos;\n\t\twhile (uval >= 100) {\n\t\t\
    \tptr -= 2;\n\t\t\tmemcpy(ptr, small[uval % 100].data(), 2);\n\t\t\tuval /= 100;\n\
    \t\t}\n\t\tif (uval >= 10) {\n\t\t\tmemcpy(ptr - 2, small[uval].data(), 2);\n\t\
    \t} else {\n\t\t\t*(ptr - 1) = char('0' + uval);\n\t\t}\n\t}\n\n\ttemplate <\n\
    \t\tclass U,\n\t\tstd::enable_if_t<Internal::is_unsigned_int128<U>::value>* =\
    \ nullptr>\n\tvoid write_unsigned(U uval) {\n\t\tstatic char buf[50];\n\t\tsize_t\
    \ len = 0;\n\t\twhile (uval > 0) {\n\t\t\tbuf[len++] = char((uval % 10) + '0');\n\
    \t\t\tuval /= 10;\n\t\t}\n\t\tstd::reverse(buf, buf + len);\n\t\tmemcpy(line +\
    \ pos, buf, len);\n\t\tpos += len;\n\t}\n\n\tvoid write_single(const std::string\
    \ &s) {\n\t\tfor (char c : s) write_single(c);\n\t}\n\tvoid write_single(const\
    \ char *s) {\n\t\tsize_t len = strlen(s);\n\t\tfor (size_t i = 0; i < len; i++)\
    \ write_single(s[i]);\n\t}\n\ttemplate <class T> void write_single(const std::vector<T>\
    \ &val) {\n\t\tauto n = val.size();\n\t\tfor (size_t i = 0; i < n; i++) {\n\t\t\
    \tif (i) write_single(' ');\n\t\t\twrite_single(val[i]);\n\t\t}\n\t}\n};\n\n}\
    \  // FastIO\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast-io.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/fast-io.hpp
layout: document
redirect_from:
- /library/library/misc/fast-io.hpp
- /library/library/misc/fast-io.hpp.html
title: library/misc/fast-io.hpp
---
