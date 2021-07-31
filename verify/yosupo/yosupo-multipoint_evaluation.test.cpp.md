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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/numerical/mod-int2.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/numerical/mod-int2.hpp\"\
    \n#include \"../../library/numerical/multipoint-evaluation.hpp\"\n\n\nusing mi\
    \ = Mint<998244353, 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tvector<mi> c(n);\n\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\tcin >> c[i];\n\t}\n\tvector<mi> p(m);\n\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\tcin >> p[i];\n\t}\n\tPoly<mi> poly(c);\n\tMultiEval<mi> multi(p);\n\t\
    auto ans = multi.query(c);\n\tfor (int i = 0; i < m; ++i) {\n\t\tcout << ans[i]\
    \ << ' ';\n\t}\n\tcout << '\\n';\n\treturn 0;\t\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-multipoint_evaluation.test.cpp
- /verify/verify/yosupo/yosupo-multipoint_evaluation.test.cpp.html
title: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
---
