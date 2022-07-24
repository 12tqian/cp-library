---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graphs/blossom-matching.hpp
    title: library/graphs/blossom-matching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\
    \n\n#include <bits/stdc++.h>\n\nstruct MaxMatching {\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<int> mate, first, res;\n\tstd::vector<bool> white;\n\tstd::vector<std::pair<int,\
    \ int>> label;\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tadj = std::vector<std::vector<int>>(n\
    \ + 1);\n\t\tmate = first = std::vector<int>(n + 1);\n\t\tlabel = std::vector<std::pair<int,\
    \ int>>(n + 1);\n\t\twhite = std::vector<bool>(n + 1);\n\t\tres = std::vector<int>(n,\
    \ -1);\n\t}\n\n\tvoid ae(int u, int v) { \n\t\t++u, ++v;\n\t\tadj.at(u).push_back(v),\
    \ adj.at(v).push_back(u); \n\t}\n\n\tint group(int x) {\n\t\tif (white[first[x]])\
    \ first[x] = group(first[x]);\n\t\treturn first[x];\n\t}\n\n\tvoid match(int p,\
    \ int b) {\n\t\tstd::swap(b, mate[p]);\n\t\tif (mate[b] != p) return;\n\t\tif\
    \ (!label[p].second)\n\t\t\tmate[b] = label[p].first, match(label[p].first, b);\t\
    \ // vertex label\n\t\telse\n\t\t\tmatch(label[p].first, label[p].second), match(label[p].second,\
    \ label[p].first);\t // edge label\n\t}\n\n\tbool augment(int st) {\n\t\tassert(st);\n\
    \t\twhite[st] = 1;\n\t\tfirst[st] = 0;\n\t\tlabel[st] = {0, 0};\n\t\tstd::queue<int>\
    \ q;\n\t\tq.push(st);\n\t\twhile (!q.empty()) {\n\t\t\tint a = q.front();\n\t\t\
    \tq.pop();\t// outer vertex\n\t\t\tfor (auto& b : adj[a]) {\n\t\t\t\tassert(b);\n\
    \t\t\t\tif (white[b]) {\t // two outer vertices, form blossom\n\t\t\t\t\tint x\
    \ = group(a), y = group(b), lca = 0;\n\t\t\t\t\twhile (x || y) {\n\t\t\t\t\t\t\
    if (y) std::swap(x, y);\n\t\t\t\t\t\tif (label[x] == std::pair<int, int>{a, b})\
    \ {\n\t\t\t\t\t\t\tlca = x;\n\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t}\n\t\t\t\t\t\t\
    label[x] = {a, b};\n\t\t\t\t\t\tx = group(label[mate[x]].first);\n\t\t\t\t\t}\n\
    \t\t\t\t\tfor (int v : {group(a), group(b)})\n\t\t\t\t\t\twhile (v != lca) {\n\
    \t\t\t\t\t\t\tassert(!white[v]);\t// make everything along path white\n\t\t\t\t\
    \t\t\tq.push(v);\n\t\t\t\t\t\t\twhite[v] = true;\n\t\t\t\t\t\t\tfirst[v] = lca;\n\
    \t\t\t\t\t\t\tv = group(label[mate[v]].first);\n\t\t\t\t\t\t}\n\t\t\t\t} else\
    \ if (!mate[b]) {\t// found augmenting path\n\t\t\t\t\tmate[b] = a;\n\t\t\t\t\t\
    match(a, b);\n\t\t\t\t\twhite = std::vector<bool>(n + 1);\t// reset\n\t\t\t\t\t\
    return true;\n\t\t\t\t} else if (!white[mate[b]]) {\n\t\t\t\t\twhite[mate[b]]\
    \ = true;\n\t\t\t\t\tfirst[mate[b]] = b;\n\t\t\t\t\tlabel[b] = {0, 0};\n\t\t\t\
    \t\tlabel[mate[b]] = std::pair<int, int>{a, 0};\n\t\t\t\t\tq.push(mate[b]);\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\n\tint solve() {\n\t\tint ans\
    \ = 0;\n\t\tfor (int st = 1; st <= n; ++st) {\n\t\t\tif (!mate[st]) {\n\t\t\t\t\
    ans += augment(st);\n\t\t\t}\n\t\t}\n\t\tfor (int st = 1; st <= n; ++st) {\n\t\
    \t\tif (!mate[st] && !white[st]) {\n\t\t\t\tassert(!augment(st));\n\t\t\t}\n\t\
    \t}\n\t\tfor (int i = 1; i <= n; ++i) {\n\t\t\tres[i - 1] = mate[i] - 1;\n\t\t\
    }\n\t\treturn ans;\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\tint n,\
    \ m;\n\tcin >> n >> m;\n\tMaxMatching mm;\n\tmm.init(n);\n\twhile (m--) {\n\t\t\
    int u, v;\n\t\tcin >> u >> v;\n\t\tmm.ae(u, v);\n\t}\n\tint ans = mm.solve();\n\
    \tcout << ans << '\\n';\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (mm.res[i] >\
    \ i) {\n\t\t\tcout << i << ' ' << mm.res[i] << '\\n';\n\t\t}\n\t}\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n\n\
    #include <bits/stdc++.h>\n#include \"../../library/graphs/blossom-matching.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tint n, m;\n\tcin >> n >> m;\n\tMaxMatching\
    \ mm;\n\tmm.init(n);\n\twhile (m--) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t\
    mm.ae(u, v);\n\t}\n\tint ans = mm.solve();\n\tcout << ans << '\\n';\n\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\tif (mm.res[i] > i) {\n\t\t\tcout << i << ' ' << mm.res[i]\
    \ << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/graphs/blossom-matching.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-general_matching.test.cpp
  requiredBy: []
  timestamp: '2022-07-23 23:14:31-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-general_matching.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-general_matching.test.cpp
- /verify/verify/yosupo/yosupo-general_matching.test.cpp.html
title: verify/yosupo/yosupo-general_matching.test.cpp
---
