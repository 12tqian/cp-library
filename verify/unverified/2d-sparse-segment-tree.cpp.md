---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../library/contest/template-minimal.hpp:\
    \ line -1: no such header\n"
  code: "#define IGNORE\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
    \n\n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/misc/easy-io.hpp\"\
    \n#include \"../library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tfreopen(\"\
    input.txt\", \"r\", stdin);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<int> xs,\
    \ ys;\n\tdbg(n, q);\n\tvector<array<int, 3>> pts(n);\n\tfor (int i = 0; i < n;\
    \ ++i) {\n\t\tfor (int j = 0; j < 3; ++j) {\n\t\t\tcin >> pts[i][j];\n\t\t}\n\t\
    \txs.push_back(pts[i][0]);\n\t\tys.push_back(pts[i][1]);\n\t}\n\tvector<array<int,\
    \ 4>> qs(q);\n\tfor (int i = 0; i < q; ++i) {\n\t\tcin >> qs[i][0] >> qs[i][2]\
    \ >> qs[i][1] >> qs[i][3];\n\t\t--qs[i][1];\n\t\t--qs[i][3];\n\t\txs.push_back(qs[i][0]);\n\
    \t\txs.push_back(qs[i][1]);\n\t\tys.push_back(qs[i][2]);\n\t\tys.push_back(qs[i][3]);\n\
    \t}\n\tauto duplicates = [&](vector<int>& v) {\n\t\tsort(v.begin(), v.end());\n\
    \t\tv.resize(unique(v.begin(), v.end()) - v.begin());\n\t};\n\tduplicates(xs);\n\
    \tduplicates(ys);\n\tauto get = [&](vector<int> &v, int x) {\n\t\treturn lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n\t};\t\n\tNode2D<int> O;\n\tfor (int i = 0; i < n;\
    \ ++i) {\n\t\tO.upd(get(xs, pts[i][0]), get(ys, pts[i][1]), pts[i][2]);\n\t}\n\
    \tfor (int i = 0; i < q; ++i) {\n\t\tcout << O.query(get(xs, qs[i][0]), get(xs,\
    \ qs[i][1]), get(ys, qs[i][2]), get(ys, qs[i][3])) << '\\n';\n\t}\n\treturn 0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: verify/unverified/2d-sparse-segment-tree.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/unverified/2d-sparse-segment-tree.cpp
layout: document
redirect_from:
- /library/verify/unverified/2d-sparse-segment-tree.cpp
- /library/verify/unverified/2d-sparse-segment-tree.cpp.html
title: verify/unverified/2d-sparse-segment-tree.cpp
---
