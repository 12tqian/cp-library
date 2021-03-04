---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/misc/fast_io.cpp\"\n#include <bits/stdc++.h>\n#include\
    \ <unistd.h>\n\nnamespace FastIO {\n\nnamespace Internal {\n\ntemplate <class\
    \ T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ =\n    typename std::conditional<std::is_integral<T>::value ||\n           \
    \                       Internal::is_signed_int128<T>::value ||\n            \
    \                      Internal::is_unsigned_int128<T>::value,\n             \
    \                 std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_signed_int = typename std::conditional<(is_integral<T>::value\
    \ &&\n                                                 std::is_signed<T>::value)\
    \ ||\n                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\ntemplate <class T>\nusing is_integral_t\
    \ = std::enable_if_t<is_integral<T>::value>;\n\ntemplate <class T>\nusing is_signed_int_t\
    \ = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate <class T>\nusing is_unsigned_int_t\
    \ = std::enable_if_t<is_unsigned_int<T>::value>;\n\ntemplate <class T> using to_unsigned_t\
    \ = typename to_unsigned<T>::type;\n\n}  // namespace Internal\n\n\nstruct Scanner\
    \ {\npublic:\n    Scanner(FILE* fp) : fd(fileno(fp)) {}\n\n    void read() {}\n\
    \    template <class H, class... T> void read(H& h, T&... t) {\n        bool f\
    \ = read_single(h);\n        assert(f);\n        read(t...);\n    }\n\n    int\
    \ read_unsafe() { return 0; }\n    template <class H, class... T> int read_unsafe(H&\
    \ h, T&... t) {\n        bool f = read_single(h);\n        if (!f) return 0;\n\
    \        return 1 + read_unsafe(t...);\n    }\n\nprivate:\n    static constexpr\
    \ size_t SIZE = 1 << 15;\n\n    bool read_single(std::string& ref) {\n       \
    \ if (!skip_space()) return false;\n        ref = \"\";\n        while (true)\
    \ {\n            char c = top();\n            if (c <= ' ') break;\n         \
    \   ref += c;\n            st++;\n        }\n        return true;\n    }\n   \
    \ bool read_single(double& ref) {\n        std::string s;\n        if (!read_single(s))\
    \ return false;\n        ref = std::stod(s);\n        return true;\n    }\n\n\
    \    template <class T, Internal::is_signed_int_t<T>* = nullptr>\n    bool read_single(T&\
    \ sref) {\n        using U = Internal::to_unsigned_t<T>;\n        if (!skip_space(50))\
    \ return false;\n        bool neg = false;\n        if (line[st] == '-') {\n \
    \           neg = true;\n            st++;\n        }\n        U ref = 0;\n  \
    \      do {\n            ref = 10 * ref + (line[st++] & 0x0f);\n        } while\
    \ (line[st] >= '0');\n        sref = neg ? -ref : ref;\n        return true;\n\
    \    }\n    template <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n  \
    \  bool read_single(U& ref) {\n        if (!skip_space(50)) return false;\n  \
    \      ref = 0;\n        do {\n            ref = 10 * ref + (line[st++] & 0x0f);\n\
    \        } while (line[st] >= '0');\n        return true;\n    }\n\n    int fd\
    \ = -1;\n    char line[SIZE];\n    size_t st = 0, ed = 0;\n    bool eof = false;\n\
    \    bool reread() {\n        if (ed - st >= 50) return true;\n        if (st\
    \ > SIZE / 2) {\n            std::memmove(line, line + st, ed - st);\n       \
    \     ed -= st;\n            st = 0;\n        }\n        if (eof) return false;\n\
    \        auto u = ::read(fd, line + ed, SIZE - ed);\n        if (u == 0) {\n \
    \           eof = true;\n            line[ed] = '\\0';\n            u = 1;\n \
    \       }\n        ed += u;\n        return true;\n    }\n\n    char top() {\n\
    \        if (st == ed) {\n            bool f = reread();\n            assert(f);\n\
    \        }\n        return line[st];\n    }\n\n    bool skip_space(unsigned int\
    \ token_len = 0) {\n        while (true) {\n            while (st != ed && line[st]\
    \ <= ' ') st++;\n            if (ed - st > token_len) return true;\n         \
    \   for (auto i = st; i < ed; i++) {\n                if (line[i] <= ' ') return\
    \ true;\n            }\n            if (!reread()) return false;\n        }\n\
    \    }\n};\n\nstruct Printer {\npublic:\n    template <bool F = false> void write()\
    \ {}\n    template <bool F = false, class H, class... T>\n    void write(const\
    \ H& h, const T&... t) {\n        if (F) write_single(' ');\n        write_single(h);\n\
    \        write<true>(t...);\n    }\n    template <class... T> void writeln(const\
    \ T&... t) {\n        write(t...);\n        write_single('\\n');\n    }\n\n  \
    \  Printer(FILE* _fp) : fd(fileno(_fp)) {}\n    ~Printer() { flush(); }\n\n  \
    \  void flush() {\n        ::write(fd, line, pos);\n        pos = 0;\n    }\n\n\
    private:\n    static std::array<std::array<char, 2>, 100> small;\n    static std::array<unsigned\
    \ long long, 20> tens;\n\n    static constexpr size_t SIZE = 1 << 15;\n    int\
    \ fd;\n    char line[SIZE];\n    size_t pos = 0;\n    void write_single(const\
    \ char& val) {\n        if (pos == SIZE) flush();\n        line[pos++] = val;\n\
    \    }\n\n    template <class T, Internal::is_signed_int_t<T>* = nullptr>\n  \
    \  void write_single(const T& val) {\n        using U = Internal::to_unsigned_t<T>;\n\
    \        if (val == 0) {\n            write_single('0');\n            return;\n\
    \        }\n        if (pos > SIZE - 50) flush();\n        U uval = val;\n   \
    \     if (val < 0) {\n            write_single('-');\n            uval = -uval;\n\
    \        }\n        write_unsigned(uval);\n    }\n\n    template <class U, Internal::is_unsigned_int_t<U>*\
    \ = nullptr>\n    void write_single(U uval) {\n        if (uval == 0) {\n    \
    \        write_single('0');\n            return;\n        }\n        if (pos >\
    \ SIZE - 50) flush();\n\n        write_unsigned(uval);\n    }\n\n    template\
    \ <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n    static int calc_len(U\
    \ x) {\n        int i = (bsr(x) * 3 + 3) / 10;\n        if (x < tens[i])\n   \
    \         return i;\n        else\n            return i + 1;\n    }\n\n    template\
    \ <class U,\n              Internal::is_unsigned_int_t<U>* = nullptr,\n      \
    \        std::enable_if_t<sizeof(U) <= 8>* = nullptr>\n    void write_unsigned(U\
    \ uval) {\n        size_t len = calc_len(uval);\n        pos += len;\n\n     \
    \   char* ptr = line + pos;\n        while (uval >= 100) {\n            ptr -=\
    \ 2;\n            memcpy(ptr, small[uval % 100].data(), 2);\n            uval\
    \ /= 100;\n        }\n        if (uval >= 10) {\n            memcpy(ptr - 2, small[uval].data(),\
    \ 2);\n        } else {\n            *(ptr - 1) = char('0' + uval);\n        }\n\
    \    }\n\n    template <\n        class U,\n        std::enable_if_t<Internal::is_unsigned_int128<U>::value>*\
    \ = nullptr>\n    void write_unsigned(U uval) {\n        static char buf[50];\n\
    \        size_t len = 0;\n        while (uval > 0) {\n            buf[len++] =\
    \ char((uval % 10) + '0');\n            uval /= 10;\n        }\n        std::reverse(buf,\
    \ buf + len);\n        memcpy(line + pos, buf, len);\n        pos += len;\n  \
    \  }\n\n    void write_single(const std::string& s) {\n        for (char c : s)\
    \ write_single(c);\n    }\n    void write_single(const char* s) {\n        size_t\
    \ len = strlen(s);\n        for (size_t i = 0; i < len; i++) write_single(s[i]);\n\
    \    }\n    template <class T> void write_single(const std::vector<T>& val) {\n\
    \        auto n = val.size();\n        for (size_t i = 0; i < n; i++) {\n    \
    \        if (i) write_single(' ');\n            write_single(val[i]);\n      \
    \  }\n    }\n};\n\n}  // FastIO\n"
  code: "#include <bits/stdc++.h>\n#include <unistd.h>\n\nnamespace FastIO {\n\nnamespace\
    \ Internal {\n\ntemplate <class T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ =\n    typename std::conditional<std::is_integral<T>::value ||\n           \
    \                       Internal::is_signed_int128<T>::value ||\n            \
    \                      Internal::is_unsigned_int128<T>::value,\n             \
    \                 std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_signed_int = typename std::conditional<(is_integral<T>::value\
    \ &&\n                                                 std::is_signed<T>::value)\
    \ ||\n                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\ntemplate <class T>\nusing is_integral_t\
    \ = std::enable_if_t<is_integral<T>::value>;\n\ntemplate <class T>\nusing is_signed_int_t\
    \ = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate <class T>\nusing is_unsigned_int_t\
    \ = std::enable_if_t<is_unsigned_int<T>::value>;\n\ntemplate <class T> using to_unsigned_t\
    \ = typename to_unsigned<T>::type;\n\n}  // namespace Internal\n\n\nstruct Scanner\
    \ {\npublic:\n    Scanner(FILE* fp) : fd(fileno(fp)) {}\n\n    void read() {}\n\
    \    template <class H, class... T> void read(H& h, T&... t) {\n        bool f\
    \ = read_single(h);\n        assert(f);\n        read(t...);\n    }\n\n    int\
    \ read_unsafe() { return 0; }\n    template <class H, class... T> int read_unsafe(H&\
    \ h, T&... t) {\n        bool f = read_single(h);\n        if (!f) return 0;\n\
    \        return 1 + read_unsafe(t...);\n    }\n\nprivate:\n    static constexpr\
    \ size_t SIZE = 1 << 15;\n\n    bool read_single(std::string& ref) {\n       \
    \ if (!skip_space()) return false;\n        ref = \"\";\n        while (true)\
    \ {\n            char c = top();\n            if (c <= ' ') break;\n         \
    \   ref += c;\n            st++;\n        }\n        return true;\n    }\n   \
    \ bool read_single(double& ref) {\n        std::string s;\n        if (!read_single(s))\
    \ return false;\n        ref = std::stod(s);\n        return true;\n    }\n\n\
    \    template <class T, Internal::is_signed_int_t<T>* = nullptr>\n    bool read_single(T&\
    \ sref) {\n        using U = Internal::to_unsigned_t<T>;\n        if (!skip_space(50))\
    \ return false;\n        bool neg = false;\n        if (line[st] == '-') {\n \
    \           neg = true;\n            st++;\n        }\n        U ref = 0;\n  \
    \      do {\n            ref = 10 * ref + (line[st++] & 0x0f);\n        } while\
    \ (line[st] >= '0');\n        sref = neg ? -ref : ref;\n        return true;\n\
    \    }\n    template <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n  \
    \  bool read_single(U& ref) {\n        if (!skip_space(50)) return false;\n  \
    \      ref = 0;\n        do {\n            ref = 10 * ref + (line[st++] & 0x0f);\n\
    \        } while (line[st] >= '0');\n        return true;\n    }\n\n    int fd\
    \ = -1;\n    char line[SIZE];\n    size_t st = 0, ed = 0;\n    bool eof = false;\n\
    \    bool reread() {\n        if (ed - st >= 50) return true;\n        if (st\
    \ > SIZE / 2) {\n            std::memmove(line, line + st, ed - st);\n       \
    \     ed -= st;\n            st = 0;\n        }\n        if (eof) return false;\n\
    \        auto u = ::read(fd, line + ed, SIZE - ed);\n        if (u == 0) {\n \
    \           eof = true;\n            line[ed] = '\\0';\n            u = 1;\n \
    \       }\n        ed += u;\n        return true;\n    }\n\n    char top() {\n\
    \        if (st == ed) {\n            bool f = reread();\n            assert(f);\n\
    \        }\n        return line[st];\n    }\n\n    bool skip_space(unsigned int\
    \ token_len = 0) {\n        while (true) {\n            while (st != ed && line[st]\
    \ <= ' ') st++;\n            if (ed - st > token_len) return true;\n         \
    \   for (auto i = st; i < ed; i++) {\n                if (line[i] <= ' ') return\
    \ true;\n            }\n            if (!reread()) return false;\n        }\n\
    \    }\n};\n\nstruct Printer {\npublic:\n    template <bool F = false> void write()\
    \ {}\n    template <bool F = false, class H, class... T>\n    void write(const\
    \ H& h, const T&... t) {\n        if (F) write_single(' ');\n        write_single(h);\n\
    \        write<true>(t...);\n    }\n    template <class... T> void writeln(const\
    \ T&... t) {\n        write(t...);\n        write_single('\\n');\n    }\n\n  \
    \  Printer(FILE* _fp) : fd(fileno(_fp)) {}\n    ~Printer() { flush(); }\n\n  \
    \  void flush() {\n        ::write(fd, line, pos);\n        pos = 0;\n    }\n\n\
    private:\n    static std::array<std::array<char, 2>, 100> small;\n    static std::array<unsigned\
    \ long long, 20> tens;\n\n    static constexpr size_t SIZE = 1 << 15;\n    int\
    \ fd;\n    char line[SIZE];\n    size_t pos = 0;\n    void write_single(const\
    \ char& val) {\n        if (pos == SIZE) flush();\n        line[pos++] = val;\n\
    \    }\n\n    template <class T, Internal::is_signed_int_t<T>* = nullptr>\n  \
    \  void write_single(const T& val) {\n        using U = Internal::to_unsigned_t<T>;\n\
    \        if (val == 0) {\n            write_single('0');\n            return;\n\
    \        }\n        if (pos > SIZE - 50) flush();\n        U uval = val;\n   \
    \     if (val < 0) {\n            write_single('-');\n            uval = -uval;\n\
    \        }\n        write_unsigned(uval);\n    }\n\n    template <class U, Internal::is_unsigned_int_t<U>*\
    \ = nullptr>\n    void write_single(U uval) {\n        if (uval == 0) {\n    \
    \        write_single('0');\n            return;\n        }\n        if (pos >\
    \ SIZE - 50) flush();\n\n        write_unsigned(uval);\n    }\n\n    template\
    \ <class U, Internal::is_unsigned_int_t<U>* = nullptr>\n    static int calc_len(U\
    \ x) {\n        int i = (bsr(x) * 3 + 3) / 10;\n        if (x < tens[i])\n   \
    \         return i;\n        else\n            return i + 1;\n    }\n\n    template\
    \ <class U,\n              Internal::is_unsigned_int_t<U>* = nullptr,\n      \
    \        std::enable_if_t<sizeof(U) <= 8>* = nullptr>\n    void write_unsigned(U\
    \ uval) {\n        size_t len = calc_len(uval);\n        pos += len;\n\n     \
    \   char* ptr = line + pos;\n        while (uval >= 100) {\n            ptr -=\
    \ 2;\n            memcpy(ptr, small[uval % 100].data(), 2);\n            uval\
    \ /= 100;\n        }\n        if (uval >= 10) {\n            memcpy(ptr - 2, small[uval].data(),\
    \ 2);\n        } else {\n            *(ptr - 1) = char('0' + uval);\n        }\n\
    \    }\n\n    template <\n        class U,\n        std::enable_if_t<Internal::is_unsigned_int128<U>::value>*\
    \ = nullptr>\n    void write_unsigned(U uval) {\n        static char buf[50];\n\
    \        size_t len = 0;\n        while (uval > 0) {\n            buf[len++] =\
    \ char((uval % 10) + '0');\n            uval /= 10;\n        }\n        std::reverse(buf,\
    \ buf + len);\n        memcpy(line + pos, buf, len);\n        pos += len;\n  \
    \  }\n\n    void write_single(const std::string& s) {\n        for (char c : s)\
    \ write_single(c);\n    }\n    void write_single(const char* s) {\n        size_t\
    \ len = strlen(s);\n        for (size_t i = 0; i < len; i++) write_single(s[i]);\n\
    \    }\n    template <class T> void write_single(const std::vector<T>& val) {\n\
    \        auto n = val.size();\n        for (size_t i = 0; i < n; i++) {\n    \
    \        if (i) write_single(' ');\n            write_single(val[i]);\n      \
    \  }\n    }\n};\n\n}  // FastIO\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast_io.cpp
  requiredBy: []
  timestamp: '2021-03-04 16:44:44-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/fast_io.cpp
layout: document
redirect_from:
- /library/library/misc/fast_io.cpp
- /library/library/misc/fast_io.cpp.html
title: library/misc/fast_io.cpp
---
