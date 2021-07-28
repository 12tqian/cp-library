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
    \n#include \"../library/string/hashing.hpp\"\n\nint main() {\n\tusing namespace\
    \ std;\n\tusing namespace Hashing;\n\tHashRange H;\n\tH.add(\"ababab\");\n\tfor\
    \ (int i = 0; i < 6; i++) \n\t\tfor (int j = i; j < 6; j++) {\n\t\t\tauto val\
    \ = H.hash(i, j);\n\t\t\tcout << i << \" \" << j << \" \" << val[0] << \" \" <<\
    \ val[1] << '\\n';\n\t\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/unit-test/unit-test-hashing.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-hashing.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-hashing.test.cpp
- /verify/verify/unit-test/unit-test-hashing.test.cpp.html
title: verify/unit-test/unit-test-hashing.test.cpp
---
