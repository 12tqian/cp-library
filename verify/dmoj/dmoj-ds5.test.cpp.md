---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/link-cut-tree.hpp
    title: library/graphs/link-cut-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://dmoj.ca/problem/ds5
  bundledCode: "#define IGNORE \"https://dmoj.ca/problem/ds5\"\n\n#pragma GCC optimize\
    \ (\"O3\")\n#pragma GCC target (\"sse4\")\n\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n#include <deque>\n#include <iostream>\n#include\
    \ <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <unordered_map>\n#include <vector>\n\nusing namespace std;\n\nstruct info {\n\
    \tint sz, sum, mn, mx;\n\n\tinfo (int v) {\n\t\tif (v == INT_MAX) {\n\t\t\tsz\
    \ = sum = 0;\n\t\t\tmn = INT_MAX, mx = INT_MIN;\n\t\t} else {\n\t\t\tsz = 1; sum\
    \ = mn = mx = v;\n\t\t}\n\t}\n\n\tinfo() : info(INT_MAX) {}\n\n\tfriend info&\
    \ operator += (info &a, const info &b) {\n\t\ta.sz += b.sz, a.sum += b.sum;\n\t\
    \ta.mn = std::min(a.mn, b.mn);\n\t\ta.mx = std::max(a.mx, b.mx);\n\t\treturn a;\n\
    \t}\n};\n\ntypedef struct snode *sn;\n\nstruct snode {\n\tint id, val; // value\
    \ in node\n\tsn p; // parent\n\tsn c[5]; // children\n\tbool flip = 0;\n\tinfo\
    \ data[2];\n\tint next_num[2], lazy[2];\n\n\tsnode(int _id, int v) {\n\t\tid =\
    \ _id; val = v;\n\t\tp = NULL;\n\t\tfor (int i = 0; i < 5; i++) {\n\t\t\tc[i]\
    \ = NULL;\n\t\t}\n\t\tnext_num[0] = next_num[1] = INT_MAX;\n\t\tlazy[0] = lazy[1]\
    \ = 0;\n\t\tcalc();\n\t}\n\n\t//////// splay tree operations\n\tvoid prop() {\n\
    \t\tif (flip) {\n\t\t\tstd::swap(c[0], c[1]);\n\t\t\tfor (int i = 0; i < 2; i++)\
    \ {\n\t\t\t\tif (c[i]) {\n\t\t\t\t\tc[i]->flip ^= 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \tflip = 0;\n\t\t}\n\t\tif (next_num[1] != INT_MAX) {\n\t\t\tif (data[1].sz) {\n\
    \t\t\t\tdata[1].sum = next_num[1] * data[1].sz;\n\t\t\t\tdata[1].mn = data[1].mx\
    \ = next_num[1];\n\t\t\t}\n\t\t\tfor (int i = 0; i < 5; i++) {\n\t\t\t\tif (c[i])\
    \ {\n\t\t\t\t\tc[i]->next_num[1] = next_num[1], c[i]->lazy[1] = 0;\n\t\t\t\t\t\
    if (i >= 2) {\n\t\t\t\t\t\tc[i]->next_num[0] = next_num[1];\n\t\t\t\t\t\tc[i]->lazy[0]\
    \ = 0;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tnext_num[1] = INT_MAX;\n\t\t}\n\
    \t\tif (lazy[1] != 0) {\n\t\t\tif (data[1].sz) {\n\t\t\t\tdata[1].sum += lazy[1]\
    \ * data[1].sz;\n\t\t\t\tdata[1].mn += lazy[1], data[1].mx += lazy[1];\n\t\t\t\
    }\n\t\t\tfor (int i = 0; i < 5; i++) {\n\t\t\t\tif (c[i]) {\n\t\t\t\t\tc[i]->lazy[1]\
    \ += lazy[1];\n\t\t\t\t\tif (i >= 2) {\n\t\t\t\t\t\tc[i]->lazy[0] += lazy[1];\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tlazy[1] = 0;\n\t\t}\n\t\tif (next_num[0]\
    \ != INT_MAX) {\n\t\t\tval = next_num[0];\n\t\t\tdata[0].sum = next_num[0] * data[0].sz;\n\
    \t\t\tdata[0].mn = data[0].mx = next_num[0];\n\t\t\tfor (int i = 0; i < 2; i++)\
    \ {\n\t\t\t\tif (c[i]) {\n\t\t\t\t\tc[i]->next_num[0] = next_num[0];\n\t\t\t\t\
    \tc[i]->lazy[0] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t\tnext_num[0] = INT_MAX;\n\t\t}\n\
    \t\tif (lazy[0] != 0) {\n\t\t\tval += lazy[0];\n\t\t\tdata[0].sum += lazy[0] *\
    \ data[0].sz;\n\t\t\tdata[0].mn += lazy[0], data[0].mx += lazy[0];\n\t\t\tfor\
    \ (int i = 0; i < 2; i++) {\n\t\t\t\tif (c[i]) {\n\t\t\t\t\tc[i]->lazy[0] += lazy[0];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tlazy[0] = 0;\n\t\t}\n\t}\n\n\tvoid calc() {\n\t\tfor\
    \ (int i = 0; i < 5; i++) {\n\t\t\tif (c[i]) {\n\t\t\t\tc[i]->prop();\n\t\t\t\
    }\n\t\t}\n\t\tdata[0] = info(val); data[1] = info(INT_MAX);\n\t\tfor (int i =\
    \ 0; i < 5; i++) {\n\t\t\tif (c[i]) {\n\t\t\t\tdata[1] += c[i]->data[1];\n\t\t\
    \t\tif (i >= 2) {\n\t\t\t\t\tdata[1] += c[i]->data[0];\n\t\t\t\t}\n\t\t\t\telse\
    \ data[0] += c[i]->data[0];\n\t\t\t}\n\t\t}\n\t}\n\n\tint dir() {\n\t\tif (!p)\
    \ return -2;\n\t\tfor (int i = 0; i < 5; i++) {\n\t\t\tif (p->c[i] == this) {\n\
    \t\t\t\treturn i;\n\t\t\t}\n\t\t}\n\t\tassert(false);\n\t}\n\n\tbool is_root()\
    \ {\n\t\tint d = dir();\n\t\treturn d == -2 || d == 4;\n\t}\n\n\tfriend void set_link(sn\
    \ x, sn y, int d) {\n\t\tif (y) y->p = x;\n\t\tif (d >= 0) x->c[d] = y;\n\t}\n\
    \n\tvoid rot() {\n\t\tassert(!is_root());\n\t\tint x = dir(); sn pa = p;\n\t\t\
    set_link(pa->p, this, pa->dir());\n\t\tset_link(pa, c[x ^ 1], x);\n\t\tset_link(this,\
    \ pa, x ^ 1);\n\t\tpa->calc(); calc();\n\t}\n\n\tbool ok_zero() {\n\t\tint d =\
    \ dir();\n\t\treturn d == 0 || d == 1;\n\t}\n\n\tvoid splay() {\n\t\twhile (ok_zero()\
    \ && p->ok_zero() && p->p->ok_zero()) {\n\t\t\tp->p->prop(), p->prop(), prop();\n\
    \t\t\tdir() == p->dir() ? p->rot() : rot();\n\t\t\trot();\n\t\t}\n\t\tif (ok_zero()\
    \ && p->ok_zero()) p->prop(), prop(), rot();\n\t\tif (ok_zero()) {\n\t\t\tp->prop(),\
    \ prop();\n\t\t\tauto a = p->p, b = p->c[2], c = p->c[3]; int d = p->dir();\n\t\
    \t\tp->p = p->c[2] = p->c[3] = NULL; p->calc(); rot();\n\t\t\tset_link(this, b,\
    \ 2); set_link(this, c, 3); set_link(a, this, d); calc();\n\t\t}\n\t\twhile (!is_root()\
    \ && !p->is_root()) {\n\t\t\tp->p->prop(), p->prop(), prop();\n\t\t\tdir() ==\
    \ p->dir() ? p->rot() : rot();\n\t\t\trot();\n\t\t}\n\t\tif (!is_root()) p->prop(),\
    \ prop(), rot();\n\t\tprop();\n\t}\n\n\tsn splay_right() {\n\t\tprop();\n\t\t\
    if (!c[3]) { splay(); return this; }\n\t\treturn c[3]->splay_right();\n\t}\n\n\
    \tfriend sn join(sn a, sn b) {\n\t\tif (!a) return b;\n\t\ta->splay(); a = a->splay_right();\n\
    \t\tset_link(a, b, 3); a->calc();\n\t\treturn a;\n\t}\n\n\t//////// link cut tree\
    \ operations\n\tvoid access() { // bring this to top of tree, left subtree of\
    \ this is now path to root\n\t\tint it = 0;\n\t\tfor (sn v = this, pre = NULL;\
    \ v; v = v->p) {\n\t\t\tit ++;\n\t\t\tv->splay(); auto c = v->c[1];\n\t\t\tif\
    \ (c) assert(!c->c[2] && !c->c[3]);\n\t\t\tif (pre) pre->prop();\n\t\t\tif (pre)\
    \ {\n\t\t\t\tassert(v->c[4] == pre);\n\t\t\t\tauto a = pre->c[2], b = pre->c[3];\n\
    \t\t\t\tif (a) a->p = NULL;\n\t\t\t\tif (b) b->p = NULL;\n\t\t\t\tpre->c[2] =\
    \ pre->c[3] = NULL; pre->calc();\n\t\t\t\tif (c) c->p = NULL;\n\t\t\t\tset_link(v,\
    \ join(join(a, b), c), 4);\n\t\t\t} else {\n\t\t\t\tif (c) c->p = NULL;\n\t\t\t\
    \tif (v->c[4]) v->c[4]->p = NULL;\n\t\t\t\tset_link(v, join(c, v->c[4]), 4);\n\
    \t\t\t}\n\t\t\tv->c[1] = pre; v->calc(); pre = v;\n\t\t}\n\t\tsplay(); assert(!c[1]);\n\
    \t}\n\n\tvoid make_root() {\n\t\taccess();\n\t\tflip ^= 1;\n\t}\n\n\t////////\
    \ link cut tree queries\n\tfriend sn lca(sn x, sn y) {\n\t\tif (x == y) return\
    \ x;\n\t\tx->access(); y->access();\n\t\tif (!x->p) return NULL;\n\t\tx->splay();\
    \ return x->p ? x->p : x;\n\t}\n\n\tfriend bool connected(sn x, sn y) {\n\t\t\
    return lca(x, y);\n\t}\n\n\tfriend sn get_par(sn x) {\n\t\tx->access(); x = x->c[0];\n\
    \t\twhile (true) {\n\t\t\tx->prop();\n\t\t\tif (!x->c[1]) return x;\n\t\t\tx =\
    \ x->c[1];\n\t\t}\n\t\treturn x;\n\t}\n\n\t//////// link cut tree modifications\n\
    \tfriend bool link(sn x, sn y) { // make y parent of x\n\t\tif (connected(x, y))\
    \ exit(2);\n\t\tx->make_root();\n\t\tset_link(y, join(x, y->c[4]), 4);\n\t\ty->calc();\n\
    \t\treturn 1;\n\t}\n\n\tfriend bool cut(sn x, sn y) {\n\t\tx->make_root(); y->access();\n\
    \t\tif (y->c[0] != x || x->c[0] || x->c[1]) exit(3);\n\t\tx->p = y->c[0] = NULL;\
    \ y->calc();\n\t\treturn true;\n\t}\n\n\tvoid prop_all() {\n\t\tprop();\n\t\t\
    for (int i = 0; i < 5; i++) {\n\t\t\tif (c[i]) {\n\t\t\t\tc[i]->prop_all();\n\t\
    \t\t}\n\t\t}\n\t}\n};\n\n\n/**\n * Benq's code made without macros and nicer\n\
    \ * Does everything a link cut tree could possibly want to\n */\n\n// // dmoj\
    \ dynamic tree test\nint main() {\n\tstd::ios_base::sync_with_stdio(0); std::cin.tie(0);\n\
    \tint n, m, root;\n\tstd::cin >> n >> m;\n\tstd::vector<sn> lct(n);\n\tstd::vector<std::pair<int,\
    \ int>> ed(n - 1);\n\tfor (int i = 0; i < n - 1; i++) {\n\t\tstd::cin >> ed[i].first\
    \ >> ed[i].second;\n\t}\n\tfor (int i = 1; i <= n; i++) {\n\t\tint x; std::cin\
    \ >> x;\n\t\tlct[i] = new snode(i, x);\n\t}\n\tfor (int i = 0; i < n - 1; i++)\
    \ {\n\t\tint x = ed[i].first, y = ed[i].second;\n\t\tlink(lct[x], lct[y]);\n\t\
    }\n\tstd::cin >> root;\n\twhile (m--) {\n\t\tint k; std::cin >> k;\n\t\tif (k\
    \ == 0 || k == 5) {\n\t\t\tint x, y; std::cin >> x >> y;\n\t\t\tlct[root]->make_root();\n\
    \t\t\tlct[x]->access();\n\t\t\tauto c = lct[x]->c[4];\n\t\t\tif (k == 0) { //\
    \ set weights in subtree of x to y\n\t\t\t\tif (c) c->prop(), c->next_num[0] =\
    \ c->next_num[1] = y;\n\t\t\t\tlct[x]->val = y;\n\n\t\t\t} else { // add y to\
    \ subtree of x vertices\n\t\t\t\tif (c) c->prop(), c->lazy[0] = c->lazy[1] = y;\n\
    \t\t\t\tlct[x]->val += y;\n\t\t\t}\n\t\t\tlct[x]->calc();\n\t\t} else if (k ==\
    \ 1) { // change root\n\t\t\tint x; std::cin >> x;\n\t\t\troot = x;\n\t\t} else\
    \ if (k == 2 || k == 6) {\n\t\t\tint x, y, z; std::cin >> x >> y >> z;\n\t\t\t\
    lct[x]->make_root();\n\t\t\tif (k == 2) { // sets path x to y to weight z\n\t\t\
    \t\tlct[y]->access();\n\t\t\t\tlct[y]->next_num[0] = z;\n\t\t\t}\n\t\t\telse {\
    \ // add z to vertices on path from x to y\n\t\t\t\tlct[y]->access();\n\t\t\t\t\
    lct[y]->lazy[0] = z;\n\t\t\t}\n\t\t} else if (k == 3 || k == 4 || k == 11) {\n\
    \t\t\tint x; std::cin >> x;\n\t\t\tlct[root]->make_root();\n\t\t\tlct[x]->access();\n\
    \t\t\tauto ans = info(lct[x]->val);\n\t\t\tsn c = lct[x]->c[4];\n\t\t\tif (c)\
    \ c->prop(), ans += c->data[0], ans += c->data[1];\n\t\t\tif (k == 3) std::cout\
    \ << ans.mn << '\\n'; // x subtree min\n\t\t\telse if (k == 4) std::cout << ans.mx\
    \ << '\\n'; // x subtree max\n\t\t\telse if (k == 11) std::cout << ans.sum <<\
    \ '\\n'; // x subtree sum\n\t\t} else if (k == 7 || k == 8 || k == 10) {\n\t\t\
    \tint x, y;\n\t\t\tstd::cin >> x >> y;\n\t\t\tlct[x]->make_root();\n\t\t\tlct[y]->access();\n\
    \t\t\tauto ans = lct[y]->data[0];\n\t\t\tif (k == 7) std::cout << ans.mn << '\\\
    n'; // x, y path min\n\t\t\telse if (k == 8) std::cout << ans.mx << '\\n'; //\
    \ x, y path max\n\t\t\telse std::cout << ans.sum << '\\n'; // x, y path sum\n\t\
    \t} else if (k == 9) { // change parent of x to y\n\t\t\tint x, y;\n\t\t\tstd::cin\
    \ >> x >> y;\n\t\t\tlct[root]->make_root();\n\t\t\tif (lca(lct[x], lct[y]) ==\
    \ lct[x]) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tcut(get_par(lct[x]), lct[x]);\n\
    \t\t\tlink(lct[x], lct[y]);\n\t\t} else exit(5);\n\t}\n\treturn 0;\n}\n"
  code: "#define IGNORE \"https://dmoj.ca/problem/ds5\"\n\n#pragma GCC optimize (\"\
    O3\")\n#pragma GCC target (\"sse4\")\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n#include \"../../library/graphs/link-cut-tree.hpp\"\n\n\n/**\n * Benq's code\
    \ made without macros and nicer\n * Does everything a link cut tree could possibly\
    \ want to\n */\n\n// // dmoj dynamic tree test\nint main() {\n\tstd::ios_base::sync_with_stdio(0);\
    \ std::cin.tie(0);\n\tint n, m, root;\n\tstd::cin >> n >> m;\n\tstd::vector<sn>\
    \ lct(n);\n\tstd::vector<std::pair<int, int>> ed(n - 1);\n\tfor (int i = 0; i\
    \ < n - 1; i++) {\n\t\tstd::cin >> ed[i].first >> ed[i].second;\n\t}\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tint x; std::cin >> x;\n\t\tlct[i] = new snode(i,\
    \ x);\n\t}\n\tfor (int i = 0; i < n - 1; i++) {\n\t\tint x = ed[i].first, y =\
    \ ed[i].second;\n\t\tlink(lct[x], lct[y]);\n\t}\n\tstd::cin >> root;\n\twhile\
    \ (m--) {\n\t\tint k; std::cin >> k;\n\t\tif (k == 0 || k == 5) {\n\t\t\tint x,\
    \ y; std::cin >> x >> y;\n\t\t\tlct[root]->make_root();\n\t\t\tlct[x]->access();\n\
    \t\t\tauto c = lct[x]->c[4];\n\t\t\tif (k == 0) { // set weights in subtree of\
    \ x to y\n\t\t\t\tif (c) c->prop(), c->next_num[0] = c->next_num[1] = y;\n\t\t\
    \t\tlct[x]->val = y;\n\n\t\t\t} else { // add y to subtree of x vertices\n\t\t\
    \t\tif (c) c->prop(), c->lazy[0] = c->lazy[1] = y;\n\t\t\t\tlct[x]->val += y;\n\
    \t\t\t}\n\t\t\tlct[x]->calc();\n\t\t} else if (k == 1) { // change root\n\t\t\t\
    int x; std::cin >> x;\n\t\t\troot = x;\n\t\t} else if (k == 2 || k == 6) {\n\t\
    \t\tint x, y, z; std::cin >> x >> y >> z;\n\t\t\tlct[x]->make_root();\n\t\t\t\
    if (k == 2) { // sets path x to y to weight z\n\t\t\t\tlct[y]->access();\n\t\t\
    \t\tlct[y]->next_num[0] = z;\n\t\t\t}\n\t\t\telse { // add z to vertices on path\
    \ from x to y\n\t\t\t\tlct[y]->access();\n\t\t\t\tlct[y]->lazy[0] = z;\n\t\t\t\
    }\n\t\t} else if (k == 3 || k == 4 || k == 11) {\n\t\t\tint x; std::cin >> x;\n\
    \t\t\tlct[root]->make_root();\n\t\t\tlct[x]->access();\n\t\t\tauto ans = info(lct[x]->val);\n\
    \t\t\tsn c = lct[x]->c[4];\n\t\t\tif (c) c->prop(), ans += c->data[0], ans +=\
    \ c->data[1];\n\t\t\tif (k == 3) std::cout << ans.mn << '\\n'; // x subtree min\n\
    \t\t\telse if (k == 4) std::cout << ans.mx << '\\n'; // x subtree max\n\t\t\t\
    else if (k == 11) std::cout << ans.sum << '\\n'; // x subtree sum\n\t\t} else\
    \ if (k == 7 || k == 8 || k == 10) {\n\t\t\tint x, y;\n\t\t\tstd::cin >> x >>\
    \ y;\n\t\t\tlct[x]->make_root();\n\t\t\tlct[y]->access();\n\t\t\tauto ans = lct[y]->data[0];\n\
    \t\t\tif (k == 7) std::cout << ans.mn << '\\n'; // x, y path min\n\t\t\telse if\
    \ (k == 8) std::cout << ans.mx << '\\n'; // x, y path max\n\t\t\telse std::cout\
    \ << ans.sum << '\\n'; // x, y path sum\n\t\t} else if (k == 9) { // change parent\
    \ of x to y\n\t\t\tint x, y;\n\t\t\tstd::cin >> x >> y;\n\t\t\tlct[root]->make_root();\n\
    \t\t\tif (lca(lct[x], lct[y]) == lct[x]) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\t\
    cut(get_par(lct[x]), lct[x]);\n\t\t\tlink(lct[x], lct[y]);\n\t\t} else exit(5);\n\
    \t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/link-cut-tree.hpp
  isVerificationFile: true
  path: verify/dmoj/dmoj-ds5.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dmoj/dmoj-ds5.test.cpp
layout: document
redirect_from:
- /verify/verify/dmoj/dmoj-ds5.test.cpp
- /verify/verify/dmoj/dmoj-ds5.test.cpp.html
title: verify/dmoj/dmoj-ds5.test.cpp
---
