---
data:
  _extendedDependsOn: []
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/contest/template-minimal.hpp:\
    \ line -1: no such header\n"
  code: "#define IGNORE\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n#include \"../../library/geometry/convex-hull.hpp\"\n\n// kattis verified\n\
    int main() {\n\tusing namespace std;\n\tusing namespace ConvexHull;\n\tios_base::sync_with_stdio(0);\n\
    \twhile (true) {\n\t\tint n; cin >> n;\n\t\tif (n == 0) \n\t\t\treturn 0;\n\t\t\
    vector<Point<int>> v(n);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tcin >> v[i].x\
    \ >> v[i].y;\n\t\tauto hull = convex_hull(v);\n\t\tcout << (int)hull.size() <<\
    \ '\\n';       \n\t\tfor (auto &p : hull)\n\t\t\tcout << p.x << \" \" << p.y <<\
    \ '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/convex-hull.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/convex-hull.cpp
layout: document
redirect_from:
- /library/test/convex-hull.cpp
- /library/test/convex-hull.cpp.html
title: test/convex-hull.cpp
---
