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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once \n\n#include \"polynomial.hpp\"\n\ntemplate <class Mint> Poly<Mint>\
    \ berlekamp_massey(const Poly<Mint>& s) {\n\tint n = int(s.size());\n\tstd::vector<Mint>\
    \ b = {Mint(-1)}, c = {Mint(-1)};\n\tMint y = Mint(1);\n\tfor (int ed = 1; ed\
    \ <= n; ed++) {\n\t\tint l = int(c.size()), m = int(b.size());\n\t\tMint x = 0;\n\
    \t\tfor (int i = 0; i < l; i++) {\n\t\t\tx += c[i] * s[ed - l + i];\n\t\t}\n\t\
    \tb.push_back(0);\n\t\tm++;\n\t\tif (!x) continue;\n\t\tMint freq = x / y;\n\t\
    \tif (l < m) {\n\t\t\t// use b\n\t\t\tauto tmp = c;\n\t\t\tc.insert(begin(c),\
    \ m - l, Mint(0));\n\t\t\tfor (int i = 0; i < m; i++) {\n\t\t\t\tc[m - 1 - i]\
    \ -= freq * b[m - 1 - i];\n\t\t\t}\n\t\t\tb = tmp;\n\t\t\ty = x;\n\t\t} else {\n\
    \t\t\t// use c\n\t\t\tfor (int i = 0; i < m; i++) {\n\t\t\t\tc[l - 1 - i] -= freq\
    \ * b[m - 1 - i];\n\t\t\t}\n\t\t}\n\t}\n\treturn c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/berlekamp-massey.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/berlekamp-massey.hpp
layout: document
redirect_from:
- /library/library/numerical/berlekamp-massey.hpp
- /library/library/numerical/berlekamp-massey.hpp.html
title: library/numerical/berlekamp-massey.hpp
---
