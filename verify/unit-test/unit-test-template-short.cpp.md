---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/contest/template-short.cpp
    title: library/contest/template-short.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/contest/template-short.cpp\"\
    : line -1: no such header\n"
  code: '#define IGNORE "just testing compilation"


    #include "../../library/contest/template-short.cpp""'
  dependsOn:
  - library/contest/template-short.cpp
  isVerificationFile: false
  path: verify/unit-test/unit-test-template-short.cpp
  requiredBy: []
  timestamp: '2021-07-29 00:58:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-template-short.cpp
layout: document
redirect_from:
- /library/verify/unit-test/unit-test-template-short.cpp
- /library/verify/unit-test/unit-test-template-short.cpp.html
title: verify/unit-test/unit-test-template-short.cpp
---
