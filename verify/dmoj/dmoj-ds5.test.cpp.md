---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    IGNORE_IF_GCC: ''
    links:
    - https://dmoj.ca/problem/ds5
  bundledCode: "#define IGNORE \"https://dmoj.ca/problem/ds5\"\r\n\r\n#pragma GCC\
    \ optimize (\"O3\")\r\n#pragma GCC target (\"sse4\")\r\n\r\n\r\n#include <algorithm>\r\
    \n#include <array>\r\n#include <bitset>\r\n#include <cassert>\r\n#include <chrono>\r\
    \n#include <cmath>\r\n#include <complex>\r\n#include <cstdio>\r\n#include <cstdlib>\r\
    \n#include <cstring>\r\n#include <ctime>\r\n#include <deque>\r\n#include <iostream>\r\
    \n#include <iomanip>\r\n#include <list>\r\n#include <map>\r\n#include <numeric>\r\
    \n#include <queue>\r\n#include <random>\r\n#include <set>\r\n#include <stack>\r\
    \n#include <string>\r\n#include <unordered_map>\r\n#include <vector>\r\n\r\nusing\
    \ namespace std;\n\r\nstruct info {\r\n  int sz, sum, mn, mx;\r\n\r\n  info(int\
    \ v) {\r\n    if (v == INT_MAX) {\r\n      sz = sum = 0;\r\n      mn = INT_MAX,\
    \ mx = INT_MIN;\r\n    } else {\r\n      sz = 1;\r\n      sum = mn = mx = v;\r\
    \n    }\r\n  }\r\n\r\n  info() : info(INT_MAX) {}\r\n\r\n  friend info& operator+=(info&\
    \ a, const info& b) {\r\n    a.sz += b.sz, a.sum += b.sum;\r\n    a.mn = std::min(a.mn,\
    \ b.mn);\r\n    a.mx = std::max(a.mx, b.mx);\r\n    return a;\r\n  }\r\n};\r\n\
    \r\ntypedef struct snode* sn;\r\n\r\nstruct snode {\r\n  int id, val;  // value\
    \ in node\r\n  sn p;         // parent\r\n  sn c[5];      // children\r\n  bool\
    \ flip = 0;\r\n  info data[2];\r\n  int next_num[2], lazy[2];\r\n\r\n  snode(int\
    \ _id, int v) {\r\n    id = _id;\r\n    val = v;\r\n    p = NULL;\r\n    for (int\
    \ i = 0; i < 5; i++) {\r\n      c[i] = NULL;\r\n    }\r\n    next_num[0] = next_num[1]\
    \ = INT_MAX;\r\n    lazy[0] = lazy[1] = 0;\r\n    calc();\r\n  }\r\n\r\n  ////////\
    \ splay tree operations\r\n  void prop() {\r\n    if (flip) {\r\n      std::swap(c[0],\
    \ c[1]);\r\n      for (int i = 0; i < 2; i++) {\r\n        if (c[i]) {\r\n   \
    \       c[i]->flip ^= 1;\r\n        }\r\n      }\r\n      flip = 0;\r\n    }\r\
    \n    if (next_num[1] != INT_MAX) {\r\n      if (data[1].sz) {\r\n        data[1].sum\
    \ = next_num[1] * data[1].sz;\r\n        data[1].mn = data[1].mx = next_num[1];\r\
    \n      }\r\n      for (int i = 0; i < 5; i++) {\r\n        if (c[i]) {\r\n  \
    \        c[i]->next_num[1] = next_num[1], c[i]->lazy[1] = 0;\r\n          if (i\
    \ >= 2) {\r\n            c[i]->next_num[0] = next_num[1];\r\n            c[i]->lazy[0]\
    \ = 0;\r\n          }\r\n        }\r\n      }\r\n      next_num[1] = INT_MAX;\r\
    \n    }\r\n    if (lazy[1] != 0) {\r\n      if (data[1].sz) {\r\n        data[1].sum\
    \ += lazy[1] * data[1].sz;\r\n        data[1].mn += lazy[1], data[1].mx += lazy[1];\r\
    \n      }\r\n      for (int i = 0; i < 5; i++) {\r\n        if (c[i]) {\r\n  \
    \        c[i]->lazy[1] += lazy[1];\r\n          if (i >= 2) {\r\n            c[i]->lazy[0]\
    \ += lazy[1];\r\n          }\r\n        }\r\n      }\r\n      lazy[1] = 0;\r\n\
    \    }\r\n    if (next_num[0] != INT_MAX) {\r\n      val = next_num[0];\r\n  \
    \    data[0].sum = next_num[0] * data[0].sz;\r\n      data[0].mn = data[0].mx\
    \ = next_num[0];\r\n      for (int i = 0; i < 2; i++) {\r\n        if (c[i]) {\r\
    \n          c[i]->next_num[0] = next_num[0];\r\n          c[i]->lazy[0] = 0;\r\
    \n        }\r\n      }\r\n      next_num[0] = INT_MAX;\r\n    }\r\n    if (lazy[0]\
    \ != 0) {\r\n      val += lazy[0];\r\n      data[0].sum += lazy[0] * data[0].sz;\r\
    \n      data[0].mn += lazy[0], data[0].mx += lazy[0];\r\n      for (int i = 0;\
    \ i < 2; i++) {\r\n        if (c[i]) {\r\n          c[i]->lazy[0] += lazy[0];\r\
    \n        }\r\n      }\r\n      lazy[0] = 0;\r\n    }\r\n  }\r\n\r\n  void calc()\
    \ {\r\n    for (int i = 0; i < 5; i++) {\r\n      if (c[i]) {\r\n        c[i]->prop();\r\
    \n      }\r\n    }\r\n    data[0] = info(val);\r\n    data[1] = info(INT_MAX);\r\
    \n    for (int i = 0; i < 5; i++) {\r\n      if (c[i]) {\r\n        data[1] +=\
    \ c[i]->data[1];\r\n        if (i >= 2) {\r\n          data[1] += c[i]->data[0];\r\
    \n        } else\r\n          data[0] += c[i]->data[0];\r\n      }\r\n    }\r\n\
    \  }\r\n\r\n  int dir() {\r\n    if (!p) return -2;\r\n    for (int i = 0; i <\
    \ 5; i++) {\r\n      if (p->c[i] == this) {\r\n        return i;\r\n      }\r\n\
    \    }\r\n    assert(false);\r\n  }\r\n\r\n  bool is_root() {\r\n    int d = dir();\r\
    \n    return d == -2 || d == 4;\r\n  }\r\n\r\n  friend void set_link(sn x, sn\
    \ y, int d) {\r\n    if (y) y->p = x;\r\n    if (d >= 0) x->c[d] = y;\r\n  }\r\
    \n\r\n  void rot() {\r\n    assert(!is_root());\r\n    int x = dir();\r\n    sn\
    \ pa = p;\r\n    set_link(pa->p, this, pa->dir());\r\n    set_link(pa, c[x ^ 1],\
    \ x);\r\n    set_link(this, pa, x ^ 1);\r\n    pa->calc();\r\n    calc();\r\n\
    \  }\r\n\r\n  bool ok_zero() {\r\n    int d = dir();\r\n    return d == 0 || d\
    \ == 1;\r\n  }\r\n\r\n  void splay() {\r\n    while (ok_zero() && p->ok_zero()\
    \ && p->p->ok_zero()) {\r\n      p->p->prop(), p->prop(), prop();\r\n      dir()\
    \ == p->dir() ? p->rot() : rot();\r\n      rot();\r\n    }\r\n    if (ok_zero()\
    \ && p->ok_zero()) p->prop(), prop(), rot();\r\n    if (ok_zero()) {\r\n     \
    \ p->prop(), prop();\r\n      auto a = p->p, b = p->c[2], c = p->c[3];\r\n   \
    \   int d = p->dir();\r\n      p->p = p->c[2] = p->c[3] = NULL;\r\n      p->calc();\r\
    \n      rot();\r\n      set_link(this, b, 2);\r\n      set_link(this, c, 3);\r\
    \n      set_link(a, this, d);\r\n      calc();\r\n    }\r\n    while (!is_root()\
    \ && !p->is_root()) {\r\n      p->p->prop(), p->prop(), prop();\r\n      dir()\
    \ == p->dir() ? p->rot() : rot();\r\n      rot();\r\n    }\r\n    if (!is_root())\
    \ p->prop(), prop(), rot();\r\n    prop();\r\n  }\r\n\r\n  sn splay_right() {\r\
    \n    prop();\r\n    if (!c[3]) {\r\n      splay();\r\n      return this;\r\n\
    \    }\r\n    return c[3]->splay_right();\r\n  }\r\n\r\n  friend sn join(sn a,\
    \ sn b) {\r\n    if (!a) return b;\r\n    a->splay();\r\n    a = a->splay_right();\r\
    \n    set_link(a, b, 3);\r\n    a->calc();\r\n    return a;\r\n  }\r\n\r\n  ////////\
    \ link cut tree operations\r\n  void access() {  // bring this to top of tree,\
    \ left subtree of this is now\r\n                   // path to root\r\n    int\
    \ it = 0;\r\n    for (sn v = this, pre = NULL; v; v = v->p) {\r\n      it++;\r\
    \n      v->splay();\r\n      auto c = v->c[1];\r\n      if (c) assert(!c->c[2]\
    \ && !c->c[3]);\r\n      if (pre) pre->prop();\r\n      if (pre) {\r\n       \
    \ assert(v->c[4] == pre);\r\n        auto a = pre->c[2], b = pre->c[3];\r\n  \
    \      if (a) a->p = NULL;\r\n        if (b) b->p = NULL;\r\n        pre->c[2]\
    \ = pre->c[3] = NULL;\r\n        pre->calc();\r\n        if (c) c->p = NULL;\r\
    \n        set_link(v, join(join(a, b), c), 4);\r\n      } else {\r\n        if\
    \ (c) c->p = NULL;\r\n        if (v->c[4]) v->c[4]->p = NULL;\r\n        set_link(v,\
    \ join(c, v->c[4]), 4);\r\n      }\r\n      v->c[1] = pre;\r\n      v->calc();\r\
    \n      pre = v;\r\n    }\r\n    splay();\r\n    assert(!c[1]);\r\n  }\r\n\r\n\
    \  void make_root() {\r\n    access();\r\n    flip ^= 1;\r\n  }\r\n\r\n  ////////\
    \ link cut tree queries\r\n  friend sn lca(sn x, sn y) {\r\n    if (x == y) return\
    \ x;\r\n    x->access();\r\n    y->access();\r\n    if (!x->p) return NULL;\r\n\
    \    x->splay();\r\n    return x->p ? x->p : x;\r\n  }\r\n\r\n  friend bool connected(sn\
    \ x, sn y) { return lca(x, y); }\r\n\r\n  friend sn get_par(sn x) {\r\n    x->access();\r\
    \n    x = x->c[0];\r\n    while (true) {\r\n      x->prop();\r\n      if (!x->c[1])\
    \ return x;\r\n      x = x->c[1];\r\n    }\r\n    return x;\r\n  }\r\n\r\n  ////////\
    \ link cut tree modifications\r\n  friend bool link(sn x, sn y) {  // make y parent\
    \ of x\r\n    if (connected(x, y)) exit(2);\r\n    x->make_root();\r\n    set_link(y,\
    \ join(x, y->c[4]), 4);\r\n    y->calc();\r\n    return 1;\r\n  }\r\n\r\n  friend\
    \ bool cut(sn x, sn y) {\r\n    x->make_root();\r\n    y->access();\r\n    if\
    \ (y->c[0] != x || x->c[0] || x->c[1]) exit(3);\r\n    x->p = y->c[0] = NULL;\r\
    \n    y->calc();\r\n    return true;\r\n  }\r\n\r\n  void prop_all() {\r\n   \
    \ prop();\r\n    for (int i = 0; i < 5; i++) {\r\n      if (c[i]) {\r\n      \
    \  c[i]->prop_all();\r\n      }\r\n    }\r\n  }\r\n};\n\r\n\r\n/**\r\n * Benq's\
    \ code made without macros and nicer\r\n * Does everything a link cut tree could\
    \ possibly want to\r\n */\r\n\r\n// // dmoj dynamic tree test\r\nint main() {\r\
    \n\tstd::ios_base::sync_with_stdio(0); std::cin.tie(0);\r\n\tint n, m, root;\r\
    \n\tstd::cin >> n >> m;\r\n\tstd::vector<sn> lct(n);\r\n\tstd::vector<std::pair<int,\
    \ int>> ed(n - 1);\r\n\tfor (int i = 0; i < n - 1; i++) {\r\n\t\tstd::cin >> ed[i].first\
    \ >> ed[i].second;\r\n\t}\r\n\tfor (int i = 1; i <= n; i++) {\r\n\t\tint x; std::cin\
    \ >> x;\r\n\t\tlct[i] = new snode(i, x);\r\n\t}\r\n\tfor (int i = 0; i < n - 1;\
    \ i++) {\r\n\t\tint x = ed[i].first, y = ed[i].second;\r\n\t\tlink(lct[x], lct[y]);\r\
    \n\t}\r\n\tstd::cin >> root;\r\n\twhile (m--) {\r\n\t\tint k; std::cin >> k;\r\
    \n\t\tif (k == 0 || k == 5) {\r\n\t\t\tint x, y; std::cin >> x >> y;\r\n\t\t\t\
    lct[root]->make_root();\r\n\t\t\tlct[x]->access();\r\n\t\t\tauto c = lct[x]->c[4];\r\
    \n\t\t\tif (k == 0) { // set weights in subtree of x to y\r\n\t\t\t\tif (c) c->prop(),\
    \ c->next_num[0] = c->next_num[1] = y;\r\n\t\t\t\tlct[x]->val = y;\r\n\r\n\t\t\
    \t} else { // add y to subtree of x vertices\r\n\t\t\t\tif (c) c->prop(), c->lazy[0]\
    \ = c->lazy[1] = y;\r\n\t\t\t\tlct[x]->val += y;\r\n\t\t\t}\r\n\t\t\tlct[x]->calc();\r\
    \n\t\t} else if (k == 1) { // change root\r\n\t\t\tint x; std::cin >> x;\r\n\t\
    \t\troot = x;\r\n\t\t} else if (k == 2 || k == 6) {\r\n\t\t\tint x, y, z; std::cin\
    \ >> x >> y >> z;\r\n\t\t\tlct[x]->make_root();\r\n\t\t\tif (k == 2) { // sets\
    \ path x to y to weight z\r\n\t\t\t\tlct[y]->access();\r\n\t\t\t\tlct[y]->next_num[0]\
    \ = z;\r\n\t\t\t}\r\n\t\t\telse { // add z to vertices on path from x to y\r\n\
    \t\t\t\tlct[y]->access();\r\n\t\t\t\tlct[y]->lazy[0] = z;\r\n\t\t\t}\r\n\t\t}\
    \ else if (k == 3 || k == 4 || k == 11) {\r\n\t\t\tint x; std::cin >> x;\r\n\t\
    \t\tlct[root]->make_root();\r\n\t\t\tlct[x]->access();\r\n\t\t\tauto ans = info(lct[x]->val);\r\
    \n\t\t\tsn c = lct[x]->c[4];\r\n\t\t\tif (c) c->prop(), ans += c->data[0], ans\
    \ += c->data[1];\r\n\t\t\tif (k == 3) std::cout << ans.mn << '\\n'; // x subtree\
    \ min\r\n\t\t\telse if (k == 4) std::cout << ans.mx << '\\n'; // x subtree max\r\
    \n\t\t\telse if (k == 11) std::cout << ans.sum << '\\n'; // x subtree sum\r\n\t\
    \t} else if (k == 7 || k == 8 || k == 10) {\r\n\t\t\tint x, y;\r\n\t\t\tstd::cin\
    \ >> x >> y;\r\n\t\t\tlct[x]->make_root();\r\n\t\t\tlct[y]->access();\r\n\t\t\t\
    auto ans = lct[y]->data[0];\r\n\t\t\tif (k == 7) std::cout << ans.mn << '\\n';\
    \ // x, y path min\r\n\t\t\telse if (k == 8) std::cout << ans.mx << '\\n'; //\
    \ x, y path max\r\n\t\t\telse std::cout << ans.sum << '\\n'; // x, y path sum\r\
    \n\t\t} else if (k == 9) { // change parent of x to y\r\n\t\t\tint x, y;\r\n\t\
    \t\tstd::cin >> x >> y;\r\n\t\t\tlct[root]->make_root();\r\n\t\t\tif (lca(lct[x],\
    \ lct[y]) == lct[x]) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tcut(get_par(lct[x]),\
    \ lct[x]);\r\n\t\t\tlink(lct[x], lct[y]);\r\n\t\t} else exit(5);\r\n\t}\r\n\t\
    return 0;\r\n}\r\n"
  code: "#define IGNORE \"https://dmoj.ca/problem/ds5\"\r\n\r\n#pragma GCC optimize\
    \ (\"O3\")\r\n#pragma GCC target (\"sse4\")\r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\
    \r\n#include \"../../library/graphs/link-cut-tree.hpp\"\r\n\r\n\r\n/**\r\n * Benq's\
    \ code made without macros and nicer\r\n * Does everything a link cut tree could\
    \ possibly want to\r\n */\r\n\r\n// // dmoj dynamic tree test\r\nint main() {\r\
    \n\tstd::ios_base::sync_with_stdio(0); std::cin.tie(0);\r\n\tint n, m, root;\r\
    \n\tstd::cin >> n >> m;\r\n\tstd::vector<sn> lct(n);\r\n\tstd::vector<std::pair<int,\
    \ int>> ed(n - 1);\r\n\tfor (int i = 0; i < n - 1; i++) {\r\n\t\tstd::cin >> ed[i].first\
    \ >> ed[i].second;\r\n\t}\r\n\tfor (int i = 1; i <= n; i++) {\r\n\t\tint x; std::cin\
    \ >> x;\r\n\t\tlct[i] = new snode(i, x);\r\n\t}\r\n\tfor (int i = 0; i < n - 1;\
    \ i++) {\r\n\t\tint x = ed[i].first, y = ed[i].second;\r\n\t\tlink(lct[x], lct[y]);\r\
    \n\t}\r\n\tstd::cin >> root;\r\n\twhile (m--) {\r\n\t\tint k; std::cin >> k;\r\
    \n\t\tif (k == 0 || k == 5) {\r\n\t\t\tint x, y; std::cin >> x >> y;\r\n\t\t\t\
    lct[root]->make_root();\r\n\t\t\tlct[x]->access();\r\n\t\t\tauto c = lct[x]->c[4];\r\
    \n\t\t\tif (k == 0) { // set weights in subtree of x to y\r\n\t\t\t\tif (c) c->prop(),\
    \ c->next_num[0] = c->next_num[1] = y;\r\n\t\t\t\tlct[x]->val = y;\r\n\r\n\t\t\
    \t} else { // add y to subtree of x vertices\r\n\t\t\t\tif (c) c->prop(), c->lazy[0]\
    \ = c->lazy[1] = y;\r\n\t\t\t\tlct[x]->val += y;\r\n\t\t\t}\r\n\t\t\tlct[x]->calc();\r\
    \n\t\t} else if (k == 1) { // change root\r\n\t\t\tint x; std::cin >> x;\r\n\t\
    \t\troot = x;\r\n\t\t} else if (k == 2 || k == 6) {\r\n\t\t\tint x, y, z; std::cin\
    \ >> x >> y >> z;\r\n\t\t\tlct[x]->make_root();\r\n\t\t\tif (k == 2) { // sets\
    \ path x to y to weight z\r\n\t\t\t\tlct[y]->access();\r\n\t\t\t\tlct[y]->next_num[0]\
    \ = z;\r\n\t\t\t}\r\n\t\t\telse { // add z to vertices on path from x to y\r\n\
    \t\t\t\tlct[y]->access();\r\n\t\t\t\tlct[y]->lazy[0] = z;\r\n\t\t\t}\r\n\t\t}\
    \ else if (k == 3 || k == 4 || k == 11) {\r\n\t\t\tint x; std::cin >> x;\r\n\t\
    \t\tlct[root]->make_root();\r\n\t\t\tlct[x]->access();\r\n\t\t\tauto ans = info(lct[x]->val);\r\
    \n\t\t\tsn c = lct[x]->c[4];\r\n\t\t\tif (c) c->prop(), ans += c->data[0], ans\
    \ += c->data[1];\r\n\t\t\tif (k == 3) std::cout << ans.mn << '\\n'; // x subtree\
    \ min\r\n\t\t\telse if (k == 4) std::cout << ans.mx << '\\n'; // x subtree max\r\
    \n\t\t\telse if (k == 11) std::cout << ans.sum << '\\n'; // x subtree sum\r\n\t\
    \t} else if (k == 7 || k == 8 || k == 10) {\r\n\t\t\tint x, y;\r\n\t\t\tstd::cin\
    \ >> x >> y;\r\n\t\t\tlct[x]->make_root();\r\n\t\t\tlct[y]->access();\r\n\t\t\t\
    auto ans = lct[y]->data[0];\r\n\t\t\tif (k == 7) std::cout << ans.mn << '\\n';\
    \ // x, y path min\r\n\t\t\telse if (k == 8) std::cout << ans.mx << '\\n'; //\
    \ x, y path max\r\n\t\t\telse std::cout << ans.sum << '\\n'; // x, y path sum\r\
    \n\t\t} else if (k == 9) { // change parent of x to y\r\n\t\t\tint x, y;\r\n\t\
    \t\tstd::cin >> x >> y;\r\n\t\t\tlct[root]->make_root();\r\n\t\t\tif (lca(lct[x],\
    \ lct[y]) == lct[x]) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tcut(get_par(lct[x]),\
    \ lct[x]);\r\n\t\t\tlink(lct[x], lct[y]);\r\n\t\t} else exit(5);\r\n\t}\r\n\t\
    return 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/link-cut-tree.hpp
  isVerificationFile: true
  path: verify/dmoj/dmoj-ds5.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 14:07:45-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dmoj/dmoj-ds5.test.cpp
layout: document
redirect_from:
- /verify/verify/dmoj/dmoj-ds5.test.cpp
- /verify/verify/dmoj/dmoj-ds5.test.cpp.html
title: verify/dmoj/dmoj-ds5.test.cpp
---
