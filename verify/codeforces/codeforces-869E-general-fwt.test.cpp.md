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
  code: "#define PROBLEM \"https://codeforces.com/contest/869/problem/E\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/2d-range-queries/general-fenwick-tree.hpp\"\
    \n#include \"../../library/numerical/mod-int2.hpp\"\n\nconst int N = 2505;\n\n\
    const int P = 998244353;\nconst int B = 2;\n\nusing mi = Mint<998244353, 5>;\n\
    \nBIT<mi, N, N> bit;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint n, m, q;\n\tcin >> m >> m >> q;\n\tmap<array<int, 4>, mi> rects;\n\tmi run\
    \ = 1;\n\twhile (q--) {\n\t\tint t, xl, xr, yl, yr;\n\t\tcin >> t >> xl >> yl\
    \ >> xr >> yr;\n\t\tauto rect = [&]() {\n\t\t\tmi v;\n\t\t\tif (t == 1) {\n\t\t\
    \t\trects[{xl, xr, yl, yr}] = run;\n\t\t\t\tv = run;\n\t\t\t\trun *= 2;\n\t\t\t\
    } else {\n\t\t\t\tv = rects[{xl, xr, yl, yr}];\n\t\t\t\tv *= -1;\n\t\t\t}\n\t\t\
    \tbit.upd(xl, yl, v);\n\t\t\tbit.upd(xl, yr + 1, -v);\n\t\t\tbit.upd(xr + 1, yl,\
    \ -v);\n\t\t\tbit.upd(xr + 1, yr + 1, v);\n\t\t};\n\t\tif (t <= 2) {\n\t\t\trect();\n\
    \t\t} else {\t\n\t\t\tif (bit.query(1, xl, 1, yl) == bit.query(1, xr, 1, yr))\
    \ {\n\t\t\t\tcout << \"Yes\" << '\\n';\n\t\t\t} else {\n\t\t\t\tcout << \"No\"\
    \ << '\\n';\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/codeforces/codeforces-869E-general-fwt.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-869E-general-fwt.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-869E-general-fwt.test.cpp
- /verify/verify/codeforces/codeforces-869E-general-fwt.test.cpp.html
title: verify/codeforces/codeforces-869E-general-fwt.test.cpp
---
