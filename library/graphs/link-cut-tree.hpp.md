---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dmoj/dmoj-ds5.test.cpp
    title: verify/dmoj/dmoj-ds5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nstruct info {\r\n\tint sz, sum, mn, mx;\r\n\r\n\tinfo (int v)\
    \ {\r\n\t\tif (v == INT_MAX) {\r\n\t\t\tsz = sum = 0;\r\n\t\t\tmn = INT_MAX, mx\
    \ = INT_MIN;\r\n\t\t} else {\r\n\t\t\tsz = 1; sum = mn = mx = v;\r\n\t\t}\r\n\t\
    }\r\n\r\n\tinfo() : info(INT_MAX) {}\r\n\r\n\tfriend info& operator += (info&\
    \ a, const info& b) {\r\n\t\ta.sz += b.sz, a.sum += b.sum;\r\n\t\ta.mn = std::min(a.mn,\
    \ b.mn);\r\n\t\ta.mx = std::max(a.mx, b.mx);\r\n\t\treturn a;\r\n\t}\r\n};\r\n\
    \r\ntypedef struct snode* sn;\r\n\r\nstruct snode {\r\n\tint id, val; // value\
    \ in node\r\n\tsn p; // parent\r\n\tsn c[5]; // children\r\n\tbool flip = 0;\r\
    \n\tinfo data[2];\r\n\tint next_num[2], lazy[2];\r\n\r\n\tsnode(int _id, int v)\
    \ {\r\n\t\tid = _id; val = v;\r\n\t\tp = NULL;\r\n\t\tfor (int i = 0; i < 5; i++)\
    \ {\r\n\t\t\tc[i] = NULL;\r\n\t\t}\r\n\t\tnext_num[0] = next_num[1] = INT_MAX;\r\
    \n\t\tlazy[0] = lazy[1] = 0;\r\n\t\tcalc();\r\n\t}\r\n\r\n\t//////// splay tree\
    \ operations\r\n\tvoid prop() {\r\n\t\tif (flip) {\r\n\t\t\tstd::swap(c[0], c[1]);\r\
    \n\t\t\tfor (int i = 0; i < 2; i++) {\r\n\t\t\t\tif (c[i]) {\r\n\t\t\t\t\tc[i]->flip\
    \ ^= 1;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tflip = 0;\r\n\t\t}\r\n\t\tif (next_num[1]\
    \ != INT_MAX) {\r\n\t\t\tif (data[1].sz) {\r\n\t\t\t\tdata[1].sum = next_num[1]\
    \ * data[1].sz;\r\n\t\t\t\tdata[1].mn = data[1].mx = next_num[1];\r\n\t\t\t}\r\
    \n\t\t\tfor (int i = 0; i < 5; i++) {\r\n\t\t\t\tif (c[i]) {\r\n\t\t\t\t\tc[i]->next_num[1]\
    \ = next_num[1], c[i]->lazy[1] = 0;\r\n\t\t\t\t\tif (i >= 2) {\r\n\t\t\t\t\t\t\
    c[i]->next_num[0] = next_num[1];\r\n\t\t\t\t\t\tc[i]->lazy[0] = 0;\r\n\t\t\t\t\
    \t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tnext_num[1] = INT_MAX;\r\n\t\t}\r\n\t\tif\
    \ (lazy[1] != 0) {\r\n\t\t\tif (data[1].sz) {\r\n\t\t\t\tdata[1].sum += lazy[1]\
    \ * data[1].sz;\r\n\t\t\t\tdata[1].mn += lazy[1], data[1].mx += lazy[1];\r\n\t\
    \t\t}\r\n\t\t\tfor (int i = 0; i < 5; i++) {\r\n\t\t\t\tif (c[i]) {\r\n\t\t\t\t\
    \tc[i]->lazy[1] += lazy[1];\r\n\t\t\t\t\tif (i >= 2) {\r\n\t\t\t\t\t\tc[i]->lazy[0]\
    \ += lazy[1];\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tlazy[1] = 0;\r\n\
    \t\t}\r\n\t\tif (next_num[0] != INT_MAX) {\r\n\t\t\tval = next_num[0];\r\n\t\t\
    \tdata[0].sum = next_num[0] * data[0].sz;\r\n\t\t\tdata[0].mn = data[0].mx = next_num[0];\r\
    \n\t\t\tfor (int i = 0; i < 2; i++) {\r\n\t\t\t\tif (c[i]) {\r\n\t\t\t\t\tc[i]->next_num[0]\
    \ = next_num[0];\r\n\t\t\t\t\tc[i]->lazy[0] = 0;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t\tnext_num[0] = INT_MAX;\r\n\t\t}\r\n\t\tif (lazy[0] != 0) {\r\n\t\t\tval +=\
    \ lazy[0];\r\n\t\t\tdata[0].sum += lazy[0] * data[0].sz;\r\n\t\t\tdata[0].mn +=\
    \ lazy[0], data[0].mx += lazy[0];\r\n\t\t\tfor (int i = 0; i < 2; i++) {\r\n\t\
    \t\t\tif (c[i]) {\r\n\t\t\t\t\tc[i]->lazy[0] += lazy[0];\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t\tlazy[0] = 0;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid calc() {\r\n\t\tfor (int\
    \ i = 0; i < 5; i++) {\r\n\t\t\tif (c[i]) {\r\n\t\t\t\tc[i]->prop();\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\tdata[0] = info(val); data[1] = info(INT_MAX);\r\n\t\tfor (int\
    \ i = 0; i < 5; i++) {\r\n\t\t\tif (c[i]) {\r\n\t\t\t\tdata[1] += c[i]->data[1];\r\
    \n\t\t\t\tif (i >= 2) {\r\n\t\t\t\t\tdata[1] += c[i]->data[0];\r\n\t\t\t\t}\r\n\
    \t\t\t\telse data[0] += c[i]->data[0];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint\
    \ dir() {\r\n\t\tif (!p) return -2;\r\n\t\tfor (int i = 0; i < 5; i++) {\r\n\t\
    \t\tif (p->c[i] == this) {\r\n\t\t\t\treturn i;\r\n\t\t\t}\r\n\t\t}\r\n\t\tassert(false);\r\
    \n\t}\r\n\r\n\tbool is_root() {\r\n\t\tint d = dir();\r\n\t\treturn d == -2 ||\
    \ d == 4;\r\n\t}\r\n\r\n\tfriend void set_link(sn x, sn y, int d) {\r\n\t\tif\
    \ (y) y->p = x;\r\n\t\tif (d >= 0) x->c[d] = y;\r\n\t}\r\n\r\n\tvoid rot() {\r\
    \n\t\tassert(!is_root());\r\n\t\tint x = dir(); sn pa = p;\r\n\t\tset_link(pa->p,\
    \ this, pa->dir());\r\n\t\tset_link(pa, c[x ^ 1], x);\r\n\t\tset_link(this, pa,\
    \ x ^ 1);\r\n\t\tpa->calc(); calc();\r\n\t}\r\n\r\n\tbool ok_zero() {\r\n\t\t\
    int d = dir();\r\n\t\treturn d == 0 || d == 1;\r\n\t}\r\n\r\n\tvoid splay() {\r\
    \n\t\twhile (ok_zero() && p->ok_zero() && p->p->ok_zero()) {\r\n\t\t\tp->p->prop(),\
    \ p->prop(), prop();\r\n\t\t\tdir() == p->dir() ? p->rot() : rot();\r\n\t\t\t\
    rot();\r\n\t\t}\r\n\t\tif (ok_zero() && p->ok_zero()) p->prop(), prop(), rot();\r\
    \n\t\tif (ok_zero()) {\r\n\t\t\tp->prop(), prop();\r\n\t\t\tauto a = p->p, b =\
    \ p->c[2], c = p->c[3]; int d = p->dir();\r\n\t\t\tp->p = p->c[2] = p->c[3] =\
    \ NULL; p->calc(); rot();\r\n\t\t\tset_link(this, b, 2); set_link(this, c, 3);\
    \ set_link(a, this, d); calc();\r\n\t\t}\r\n\t\twhile (!is_root() && !p->is_root())\
    \ {\r\n\t\t\tp->p->prop(), p->prop(), prop();\r\n\t\t\tdir() == p->dir() ? p->rot()\
    \ : rot();\r\n\t\t\trot();\r\n\t\t}\r\n\t\tif (!is_root()) p->prop(), prop(),\
    \ rot();\r\n\t\tprop();\r\n\t}\r\n\r\n\tsn splay_right() {\r\n\t\tprop();\r\n\t\
    \tif (!c[3]) { splay(); return this; }\r\n\t\treturn c[3]->splay_right();\r\n\t\
    }\r\n\r\n\tfriend sn join(sn a, sn b) {\r\n\t\tif (!a) return b;\r\n\t\ta->splay();\
    \ a = a->splay_right();\r\n\t\tset_link(a, b, 3); a->calc();\r\n\t\treturn a;\r\
    \n\t}\r\n\r\n\t//////// link cut tree operations\r\n\tvoid access() { // bring\
    \ this to top of tree, left subtree of this is now path to root\r\n\t\tint it\
    \ = 0;\r\n\t\tfor (sn v = this, pre = NULL; v; v = v->p) {\r\n\t\t\tit ++;\r\n\
    \t\t\tv->splay(); auto c = v->c[1];\r\n\t\t\tif (c) assert(!c->c[2] && !c->c[3]);\r\
    \n\t\t\tif (pre) pre->prop();\r\n\t\t\tif (pre) {\r\n\t\t\t\tassert(v->c[4] ==\
    \ pre);\r\n\t\t\t\tauto a = pre->c[2], b = pre->c[3];\r\n\t\t\t\tif (a) a->p =\
    \ NULL;\r\n\t\t\t\tif (b) b->p = NULL;\r\n\t\t\t\tpre->c[2] = pre->c[3] = NULL;\
    \ pre->calc();\r\n\t\t\t\tif (c) c->p = NULL;\r\n\t\t\t\tset_link(v, join(join(a,\
    \ b), c), 4);\r\n\t\t\t} else {\r\n\t\t\t\tif (c) c->p = NULL;\r\n\t\t\t\tif (v->c[4])\
    \ v->c[4]->p = NULL;\r\n\t\t\t\tset_link(v, join(c, v->c[4]), 4);\r\n\t\t\t}\r\
    \n\t\t\tv->c[1] = pre; v->calc(); pre = v;\r\n\t\t}\r\n\t\tsplay(); assert(!c[1]);\r\
    \n\t}\r\n\r\n\tvoid make_root() {\r\n\t\taccess();\r\n\t\tflip ^= 1;\r\n\t}\r\n\
    \r\n\t//////// link cut tree queries\r\n\tfriend sn lca(sn x, sn y) {\r\n\t\t\
    if (x == y) return x;\r\n\t\tx->access(); y->access();\r\n\t\tif (!x->p) return\
    \ NULL;\r\n\t\tx->splay(); return x->p ? x->p : x;\r\n\t}\r\n\r\n\tfriend bool\
    \ connected(sn x, sn y) {\r\n\t\treturn lca(x, y);\r\n\t}\r\n\r\n\tfriend sn get_par(sn\
    \ x) {\r\n\t\tx->access(); x = x->c[0];\r\n\t\twhile (true) {\r\n\t\t\tx->prop();\r\
    \n\t\t\tif (!x->c[1]) return x;\r\n\t\t\tx = x->c[1];\r\n\t\t}\r\n\t\treturn x;\r\
    \n\t}\r\n\r\n\t//////// link cut tree modifications\r\n\tfriend bool link(sn x,\
    \ sn y) { // make y parent of x\r\n\t\tif (connected(x, y)) exit(2);\r\n\t\tx->make_root();\r\
    \n\t\tset_link(y, join(x, y->c[4]), 4);\r\n\t\ty->calc();\r\n\t\treturn 1;\r\n\
    \t}\r\n\r\n\tfriend bool cut(sn x, sn y) {\r\n\t\tx->make_root(); y->access();\r\
    \n\t\tif (y->c[0] != x || x->c[0] || x->c[1]) exit(3);\r\n\t\tx->p = y->c[0] =\
    \ NULL; y->calc();\r\n\t\treturn true;\r\n\t}\r\n\r\n\tvoid prop_all() {\r\n\t\
    \tprop();\r\n\t\tfor (int i = 0; i < 5; i++) {\r\n\t\t\tif (c[i]) {\r\n\t\t\t\t\
    c[i]->prop_all();\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\nstruct info {\r\n\tint sz, sum, mn, mx;\r\n\r\n\tinfo\
    \ (int v) {\r\n\t\tif (v == INT_MAX) {\r\n\t\t\tsz = sum = 0;\r\n\t\t\tmn = INT_MAX,\
    \ mx = INT_MIN;\r\n\t\t} else {\r\n\t\t\tsz = 1; sum = mn = mx = v;\r\n\t\t}\r\
    \n\t}\r\n\r\n\tinfo() : info(INT_MAX) {}\r\n\r\n\tfriend info& operator += (info&\
    \ a, const info& b) {\r\n\t\ta.sz += b.sz, a.sum += b.sum;\r\n\t\ta.mn = std::min(a.mn,\
    \ b.mn);\r\n\t\ta.mx = std::max(a.mx, b.mx);\r\n\t\treturn a;\r\n\t}\r\n};\r\n\
    \r\ntypedef struct snode* sn;\r\n\r\nstruct snode {\r\n\tint id, val; // value\
    \ in node\r\n\tsn p; // parent\r\n\tsn c[5]; // children\r\n\tbool flip = 0;\r\
    \n\tinfo data[2];\r\n\tint next_num[2], lazy[2];\r\n\r\n\tsnode(int _id, int v)\
    \ {\r\n\t\tid = _id; val = v;\r\n\t\tp = NULL;\r\n\t\tfor (int i = 0; i < 5; i++)\
    \ {\r\n\t\t\tc[i] = NULL;\r\n\t\t}\r\n\t\tnext_num[0] = next_num[1] = INT_MAX;\r\
    \n\t\tlazy[0] = lazy[1] = 0;\r\n\t\tcalc();\r\n\t}\r\n\r\n\t//////// splay tree\
    \ operations\r\n\tvoid prop() {\r\n\t\tif (flip) {\r\n\t\t\tstd::swap(c[0], c[1]);\r\
    \n\t\t\tfor (int i = 0; i < 2; i++) {\r\n\t\t\t\tif (c[i]) {\r\n\t\t\t\t\tc[i]->flip\
    \ ^= 1;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tflip = 0;\r\n\t\t}\r\n\t\tif (next_num[1]\
    \ != INT_MAX) {\r\n\t\t\tif (data[1].sz) {\r\n\t\t\t\tdata[1].sum = next_num[1]\
    \ * data[1].sz;\r\n\t\t\t\tdata[1].mn = data[1].mx = next_num[1];\r\n\t\t\t}\r\
    \n\t\t\tfor (int i = 0; i < 5; i++) {\r\n\t\t\t\tif (c[i]) {\r\n\t\t\t\t\tc[i]->next_num[1]\
    \ = next_num[1], c[i]->lazy[1] = 0;\r\n\t\t\t\t\tif (i >= 2) {\r\n\t\t\t\t\t\t\
    c[i]->next_num[0] = next_num[1];\r\n\t\t\t\t\t\tc[i]->lazy[0] = 0;\r\n\t\t\t\t\
    \t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tnext_num[1] = INT_MAX;\r\n\t\t}\r\n\t\tif\
    \ (lazy[1] != 0) {\r\n\t\t\tif (data[1].sz) {\r\n\t\t\t\tdata[1].sum += lazy[1]\
    \ * data[1].sz;\r\n\t\t\t\tdata[1].mn += lazy[1], data[1].mx += lazy[1];\r\n\t\
    \t\t}\r\n\t\t\tfor (int i = 0; i < 5; i++) {\r\n\t\t\t\tif (c[i]) {\r\n\t\t\t\t\
    \tc[i]->lazy[1] += lazy[1];\r\n\t\t\t\t\tif (i >= 2) {\r\n\t\t\t\t\t\tc[i]->lazy[0]\
    \ += lazy[1];\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tlazy[1] = 0;\r\n\
    \t\t}\r\n\t\tif (next_num[0] != INT_MAX) {\r\n\t\t\tval = next_num[0];\r\n\t\t\
    \tdata[0].sum = next_num[0] * data[0].sz;\r\n\t\t\tdata[0].mn = data[0].mx = next_num[0];\r\
    \n\t\t\tfor (int i = 0; i < 2; i++) {\r\n\t\t\t\tif (c[i]) {\r\n\t\t\t\t\tc[i]->next_num[0]\
    \ = next_num[0];\r\n\t\t\t\t\tc[i]->lazy[0] = 0;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t\tnext_num[0] = INT_MAX;\r\n\t\t}\r\n\t\tif (lazy[0] != 0) {\r\n\t\t\tval +=\
    \ lazy[0];\r\n\t\t\tdata[0].sum += lazy[0] * data[0].sz;\r\n\t\t\tdata[0].mn +=\
    \ lazy[0], data[0].mx += lazy[0];\r\n\t\t\tfor (int i = 0; i < 2; i++) {\r\n\t\
    \t\t\tif (c[i]) {\r\n\t\t\t\t\tc[i]->lazy[0] += lazy[0];\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t\tlazy[0] = 0;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid calc() {\r\n\t\tfor (int\
    \ i = 0; i < 5; i++) {\r\n\t\t\tif (c[i]) {\r\n\t\t\t\tc[i]->prop();\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\tdata[0] = info(val); data[1] = info(INT_MAX);\r\n\t\tfor (int\
    \ i = 0; i < 5; i++) {\r\n\t\t\tif (c[i]) {\r\n\t\t\t\tdata[1] += c[i]->data[1];\r\
    \n\t\t\t\tif (i >= 2) {\r\n\t\t\t\t\tdata[1] += c[i]->data[0];\r\n\t\t\t\t}\r\n\
    \t\t\t\telse data[0] += c[i]->data[0];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint\
    \ dir() {\r\n\t\tif (!p) return -2;\r\n\t\tfor (int i = 0; i < 5; i++) {\r\n\t\
    \t\tif (p->c[i] == this) {\r\n\t\t\t\treturn i;\r\n\t\t\t}\r\n\t\t}\r\n\t\tassert(false);\r\
    \n\t}\r\n\r\n\tbool is_root() {\r\n\t\tint d = dir();\r\n\t\treturn d == -2 ||\
    \ d == 4;\r\n\t}\r\n\r\n\tfriend void set_link(sn x, sn y, int d) {\r\n\t\tif\
    \ (y) y->p = x;\r\n\t\tif (d >= 0) x->c[d] = y;\r\n\t}\r\n\r\n\tvoid rot() {\r\
    \n\t\tassert(!is_root());\r\n\t\tint x = dir(); sn pa = p;\r\n\t\tset_link(pa->p,\
    \ this, pa->dir());\r\n\t\tset_link(pa, c[x ^ 1], x);\r\n\t\tset_link(this, pa,\
    \ x ^ 1);\r\n\t\tpa->calc(); calc();\r\n\t}\r\n\r\n\tbool ok_zero() {\r\n\t\t\
    int d = dir();\r\n\t\treturn d == 0 || d == 1;\r\n\t}\r\n\r\n\tvoid splay() {\r\
    \n\t\twhile (ok_zero() && p->ok_zero() && p->p->ok_zero()) {\r\n\t\t\tp->p->prop(),\
    \ p->prop(), prop();\r\n\t\t\tdir() == p->dir() ? p->rot() : rot();\r\n\t\t\t\
    rot();\r\n\t\t}\r\n\t\tif (ok_zero() && p->ok_zero()) p->prop(), prop(), rot();\r\
    \n\t\tif (ok_zero()) {\r\n\t\t\tp->prop(), prop();\r\n\t\t\tauto a = p->p, b =\
    \ p->c[2], c = p->c[3]; int d = p->dir();\r\n\t\t\tp->p = p->c[2] = p->c[3] =\
    \ NULL; p->calc(); rot();\r\n\t\t\tset_link(this, b, 2); set_link(this, c, 3);\
    \ set_link(a, this, d); calc();\r\n\t\t}\r\n\t\twhile (!is_root() && !p->is_root())\
    \ {\r\n\t\t\tp->p->prop(), p->prop(), prop();\r\n\t\t\tdir() == p->dir() ? p->rot()\
    \ : rot();\r\n\t\t\trot();\r\n\t\t}\r\n\t\tif (!is_root()) p->prop(), prop(),\
    \ rot();\r\n\t\tprop();\r\n\t}\r\n\r\n\tsn splay_right() {\r\n\t\tprop();\r\n\t\
    \tif (!c[3]) { splay(); return this; }\r\n\t\treturn c[3]->splay_right();\r\n\t\
    }\r\n\r\n\tfriend sn join(sn a, sn b) {\r\n\t\tif (!a) return b;\r\n\t\ta->splay();\
    \ a = a->splay_right();\r\n\t\tset_link(a, b, 3); a->calc();\r\n\t\treturn a;\r\
    \n\t}\r\n\r\n\t//////// link cut tree operations\r\n\tvoid access() { // bring\
    \ this to top of tree, left subtree of this is now path to root\r\n\t\tint it\
    \ = 0;\r\n\t\tfor (sn v = this, pre = NULL; v; v = v->p) {\r\n\t\t\tit ++;\r\n\
    \t\t\tv->splay(); auto c = v->c[1];\r\n\t\t\tif (c) assert(!c->c[2] && !c->c[3]);\r\
    \n\t\t\tif (pre) pre->prop();\r\n\t\t\tif (pre) {\r\n\t\t\t\tassert(v->c[4] ==\
    \ pre);\r\n\t\t\t\tauto a = pre->c[2], b = pre->c[3];\r\n\t\t\t\tif (a) a->p =\
    \ NULL;\r\n\t\t\t\tif (b) b->p = NULL;\r\n\t\t\t\tpre->c[2] = pre->c[3] = NULL;\
    \ pre->calc();\r\n\t\t\t\tif (c) c->p = NULL;\r\n\t\t\t\tset_link(v, join(join(a,\
    \ b), c), 4);\r\n\t\t\t} else {\r\n\t\t\t\tif (c) c->p = NULL;\r\n\t\t\t\tif (v->c[4])\
    \ v->c[4]->p = NULL;\r\n\t\t\t\tset_link(v, join(c, v->c[4]), 4);\r\n\t\t\t}\r\
    \n\t\t\tv->c[1] = pre; v->calc(); pre = v;\r\n\t\t}\r\n\t\tsplay(); assert(!c[1]);\r\
    \n\t}\r\n\r\n\tvoid make_root() {\r\n\t\taccess();\r\n\t\tflip ^= 1;\r\n\t}\r\n\
    \r\n\t//////// link cut tree queries\r\n\tfriend sn lca(sn x, sn y) {\r\n\t\t\
    if (x == y) return x;\r\n\t\tx->access(); y->access();\r\n\t\tif (!x->p) return\
    \ NULL;\r\n\t\tx->splay(); return x->p ? x->p : x;\r\n\t}\r\n\r\n\tfriend bool\
    \ connected(sn x, sn y) {\r\n\t\treturn lca(x, y);\r\n\t}\r\n\r\n\tfriend sn get_par(sn\
    \ x) {\r\n\t\tx->access(); x = x->c[0];\r\n\t\twhile (true) {\r\n\t\t\tx->prop();\r\
    \n\t\t\tif (!x->c[1]) return x;\r\n\t\t\tx = x->c[1];\r\n\t\t}\r\n\t\treturn x;\r\
    \n\t}\r\n\r\n\t//////// link cut tree modifications\r\n\tfriend bool link(sn x,\
    \ sn y) { // make y parent of x\r\n\t\tif (connected(x, y)) exit(2);\r\n\t\tx->make_root();\r\
    \n\t\tset_link(y, join(x, y->c[4]), 4);\r\n\t\ty->calc();\r\n\t\treturn 1;\r\n\
    \t}\r\n\r\n\tfriend bool cut(sn x, sn y) {\r\n\t\tx->make_root(); y->access();\r\
    \n\t\tif (y->c[0] != x || x->c[0] || x->c[1]) exit(3);\r\n\t\tx->p = y->c[0] =\
    \ NULL; y->calc();\r\n\t\treturn true;\r\n\t}\r\n\r\n\tvoid prop_all() {\r\n\t\
    \tprop();\r\n\t\tfor (int i = 0; i < 5; i++) {\r\n\t\t\tif (c[i]) {\r\n\t\t\t\t\
    c[i]->prop_all();\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/link-cut-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dmoj/dmoj-ds5.test.cpp
documentation_of: library/graphs/link-cut-tree.hpp
layout: document
redirect_from:
- /library/library/graphs/link-cut-tree.hpp
- /library/library/graphs/link-cut-tree.hpp.html
title: library/graphs/link-cut-tree.hpp
---
