---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../library/contest/template-minimal.hpp:\
    \ line -1: no such header\n"
  code: "#define IGNORE \"self tested\"\n\n#include \"../library/contest/template-minimal.hpp\"\
    \n#include \"../library/dynamic-programming/gosper-hack.hpp\"\n\nint main() {\n\
    \tint n = 4;\n\tfor (int sz = 1; sz <= n; sz++) {\n\t\tlong long c = (1 << sz)\
    \ - 1;\n\t\twhile (c < (1 << n)) {\n\t\t\tstd::cout << binary(c) << std::endl;\
    \ // do stuff to binary string with sz 1's\n\t\t\tlong long a = c & -c;\n\t\t\t\
    long long b = c + a;\n\t\t\tc = (c ^ b) / 4 / a | b;\n\t\t}\n\t}\n\treturn 0;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: verify/unit-test/unit-test-gosper-hack.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-gosper-hack.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-gosper-hack.test.cpp
- /verify/verify/unit-test/unit-test-gosper-hack.test.cpp.html
title: verify/unit-test/unit-test-gosper-hack.test.cpp
---
