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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../library/graphs/strongly-connected-components-kosaraju.hpp\t\
    : line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../library/contest/template-minimal.hpp\"\
    \n#include \"../library/graphs/strongly-connected-components-kosaraju.hpp\t\"\n\
    int main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint\
    \ n, m; \n\tcin >> n >> m;\n\tSCC S; S.init(n);\n\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tS.ae(u, v);\n\t}\n\tS.gen();\n\tS.build_scc_graph();\n\
    \tcout << S.roots.size() << '\\n';\n\tfor (auto &c : S.topo_ord) {\n\t\tcout <<\
    \ S.comps[c].size() << \" \";\n\t\tfor (auto &x : S.comps[c]) \n\t\t\tcout <<\
    \ x << \" \";\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/strongly-connected-components-kosaraju.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/strongly-connected-components-kosaraju.test.cpp
layout: document
redirect_from:
- /verify/test/strongly-connected-components-kosaraju.test.cpp
- /verify/test/strongly-connected-components-kosaraju.test.cpp.html
title: test/strongly-connected-components-kosaraju.test.cpp
---
