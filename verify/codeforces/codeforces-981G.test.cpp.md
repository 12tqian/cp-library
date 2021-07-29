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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/data-structures/1d-range-queries/interval-union.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/981/problem/G\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/affine-segment-tree.hpp\"\
    \n#include \"../../library/numerical/mod-int2.hpp\"\n#include \"../../library/data-structures/1d-range-queries/interval-union.hpp\"\
    \n\nusing mi = Mint<998244353, 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<IntervalUnion<int>>\
    \ iu(n);\n\tAffineSegmentTree<mi> seg;\n\tseg.init(n);\n\twhile (q--) {\n\t\t\
    int t;\n\t\tcin >> t;\n\t\tif (t == 1) {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >>\
    \ r >> x;\n\t\t\t--l, --r, --x;\n\t\t\tvector<pair<int, int>> use = iu[x].insert({l,\
    \ r});\n\t\t\tfor (auto &y : use) {\n\t\t\t\tseg.upd(1, max(l, y.first), min(r,\
    \ y.second), 2);\n\t\t\t}\n\t\t\tif (!use.empty()) {\n\t\t\t\tfor (int i = 0;\
    \ i < use.size() + 1; ++i) {\n\t\t\t\t\tif (i == 0) {\n\t\t\t\t\t\tseg.upd(0,\
    \ l, use[i].first - 1, 1);\n\t\t\t\t\t} else if (i != use.size()) {\n\t\t\t\t\t\
    \tseg.upd(0, use[i - 1].second + 1, use[i].first - 1, 1);\n\t\t\t\t\t} else {\n\
    \t\t\t\t\t\tseg.upd(0, use[i - 1].second + 1, r, 1);\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t} else {\n\t\t\t\tseg.upd(0, l, r, 1);\n\t\t\t}\n\t\t} else {\n\t\t\tint\
    \ l, r;\n\t\t\tcin >> l >> r;\n\t\t\t--l, --r;\n\t\t\tcout << seg.qsum(l, r) <<\
    \ '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/codeforces/codeforces-981G.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-981G.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-981G.test.cpp
- /verify/verify/codeforces/codeforces-981G.test.cpp.html
title: verify/codeforces/codeforces-981G.test.cpp
---
