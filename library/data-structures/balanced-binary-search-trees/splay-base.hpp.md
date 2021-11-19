---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\
      \u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)"
    links: []
  bundledCode: "template <class Tree, class Node, class T, class E, T (*f)(T, T),\n\
    \t\t\t\t\tT (*g)(T, E), E (*h)(E, E), T (*ts)(T)>\nstruct LazyReversibleBBST :\
    \ Tree {\n\tusing Tree::merge;\n\tusing Tree::split;\n\t\tusing class Tree::Ptr;\n\
    \n\tLazyReversibleBBST() = default;\n\n\tvoid toggle(Ptr t) {\n\t\tswap(t->l,\
    \ t->r);\n\t\tt->sum = ts(t->sum);\n\t\tt->rev ^= true;\n\t}\n\n\tT fold(Ptr &t,\
    \ int a, int b) {\n\t\tauto x = split(t, a);\n\t\tauto y = split(x.second, b -\
    \ a);\n\t\tauto ret = sum(y.first);\n\t\tt = merge(x.first, merge(y.first, y.second));\n\
    \t\treturn ret;\n\t}\n\n\tvoid reverse(Ptr &t, int a, int b) {\n\t\tauto x = split(t,\
    \ a);\n\t\tauto y = split(x.second, b - a);\n\t\ttoggle(y.first);\n\t\tt = merge(x.first,\
    \ merge(y.first, y.second));\n\t}\n\n\tvoid apply(Ptr &t, int a, int b, const\
    \ E &e) {\n\t\tauto x = split(t, a);\n\t\tauto y = split(x.second, b - a);\n\t\
    \tpropagate(y.first, e);\n\t\tt = merge(x.first, merge(y.first, y.second));\n\t\
    }\n\n protected:\n\tinline T sum(const Ptr t) { return t ? t->sum : T(); }\n\n\
    \tPtr update(Ptr t) override {\n\t\tif (!t) return t;\n\t\tt->cnt = 1;\n\t\tt->sum\
    \ = t->key;\n\t\tif (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n\
    \t\tif (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n\t\treturn\
    \ t;\n\t}\n\n\tvoid push(Ptr t) override {\n\t\tif (!t) return;\n\t\tif (t->rev)\
    \ {\n\t\t\tif (t->l) toggle(t->l);\n\t\t\tif (t->r) toggle(t->r);\n\t\t\tt->rev\
    \ = false;\n\t\t}\n\t\tif (t->lazy != E()) {\n\t\t\tif (t->l) propagate(t->l,\
    \ t->lazy);\n\t\t\tif (t->r) propagate(t->r, t->lazy);\n\t\t\tt->lazy = E();\n\
    \t\t}\n\t}\n\n\tvoid propagate(Ptr t, const E &x) {\n\t\tt->lazy = h(t->lazy,\
    \ x);\n\t\tt->key = g(t->key, x);\n\t\tt->sum = g(t->sum, x);\n\t}\n};\n\n/**\n\
    \ * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\
    \u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n\ntemplate <class Node>\nstruct SplayTreeBase\
    \ {\n\tusing Ptr = Node *;\n\ttemplate <class... Args>\n\tPtr my_new(const Args\
    \ &... args) {\n\t\treturn new Node(args...);\n\t}\n\tvoid my_del(Ptr p) { delete\
    \ p; }\n\n\tbool is_root(Ptr t) { return !(t->p) || (t->p->l != t && t->p->r !=\
    \ t); }\n\n\tint size(Ptr t) const { return count(t); }\n\n\tvirtual void splay(Ptr\
    \ t) {\n\t\tpush(t);\n\t\twhile (!is_root(t)) {\n\t\t\tPtr q = t->p;\n\t\t\tif\
    \ (is_root(q)) {\n\t\t\t\tpush(q), push(t);\n\t\t\t\trot(t);\n\t\t\t} else {\n\
    \t\t\t\tPtr r = q->p;\n\t\t\t\tpush(r), push(q), push(t);\n\t\t\t\tif (pos(q)\
    \ == pos(t))\n\t\t\t\t\trot(q), rot(t);\n\t\t\t\telse\n\t\t\t\t\trot(t), rot(t);\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tPtr get_left(Ptr t) {\n\t\twhile (t->l) push(t), t =\
    \ t->l;\n\t\treturn t;\n\t}\n\n\tPtr get_right(Ptr t) {\n\t\twhile (t->r) push(t),\
    \ t = t->r;\n\t\treturn t;\n\t}\n\n\tpair<Ptr, Ptr> split(Ptr t, int k) {\n\t\t\
    if (!t) return {nullptr, nullptr};\n\t\tif (k == 0) return {nullptr, t};\n\t\t\
    if (k == count(t)) return {t, nullptr};\n\t\tpush(t);\n\t\tif (k <= count(t->l))\
    \ {\n\t\t\tauto x = split(t->l, k);\n\t\t\tt->l = x.second;\n\t\t\tt->p = nullptr;\n\
    \t\t\tif (x.second) x.second->p = t;\n\t\t\treturn {x.first, update(t)};\n\t\t\
    } else {\n\t\t\tauto x = split(t->r, k - count(t->l) - 1);\n\t\t\tt->r = x.first;\n\
    \t\t\tt->p = nullptr;\n\t\t\tif (x.first) x.first->p = t;\n\t\t\treturn {update(t),\
    \ x.second};\n\t\t}\n\t}\n\n\tPtr merge(Ptr l, Ptr r) {\n\t\tif (!l && !r) return\
    \ nullptr;\n\t\tif (!l) return splay(r), r;\n\t\tif (!r) return splay(l), l;\n\
    \t\tsplay(l), splay(r);\n\t\tl = get_right(l);\n\t\tsplay(l);\n\t\tl->r = r;\n\
    \t\tr->p = l;\n\t\tupdate(l);\n\t\treturn l;\n\t}\n\n\tusing Key = decltype(Node::key);\n\
    \tPtr build(const vector<Key> &v) { return build(0, v.size(), v); }\n\tPtr build(int\
    \ l, int r, const vector<Key> &v) {\n\t\tif (l + 1 >= r) return my_new(v[l]);\n\
    \t\treturn merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n\t}\n\
    \n\ttemplate <class... Args>\n\tvoid insert(Ptr &t, int k, const Args &... args)\
    \ {\n\t\tsplay(t);\n\t\tauto x = split(t, k);\n\t\tt = merge(merge(x.first, my_new(args...)),\
    \ x.second);\n\t}\n\n\tvoid erase(Ptr &t, int k) {\n\t\tsplay(t);\n\t\tauto x\
    \ = split(t, k);\n\t\tauto y = split(x.second, 1);\n\t\tmy_del(y.first);\n\t\t\
    t = merge(x.first, y.second);\n\t}\n\n\tvirtual Ptr update(Ptr t) = 0;\n\n protected:\n\
    \tinline int count(Ptr t) const { return t ? t->cnt : 0; }\n\n\tvirtual void push(Ptr\
    \ t) = 0;\n\n\tPtr build(const vector<Ptr> &v) { return build(0, v.size(), v);\
    \ }\n\n\tPtr build(int l, int r, const vector<Ptr> &v) {\n\t\tif (l + 1 >= r)\
    \ return v[l];\n\t\treturn merge(build(l, (l + r) >> 1, v), build((l + r) >> 1,\
    \ r, v));\n\t}\n\n\tinline int pos(Ptr t) {\n\t\tif (t->p) {\n\t\t\tif (t->p->l\
    \ == t) return -1;\n\t\t\tif (t->p->r == t) return 1;\n\t\t}\n\t\treturn 0;\n\t\
    }\n\n\tvirtual void rot(Ptr t) {\n\t\tPtr x = t->p, y = x->p;\n\t\tif (pos(t)\
    \ == -1) {\n\t\t\tif ((x->l = t->r)) t->r->p = x;\n\t\t\tt->r = x, x->p = t;\n\
    \t\t} else {\n\t\t\tif ((x->r = t->l)) t->l->p = x;\n\t\t\tt->l = x, x->p = t;\n\
    \t\t}\n\t\tupdate(x), update(t);\n\t\tif ((t->p = y)) {\n\t\t\tif (y->l == x)\
    \ y->l = t;\n\t\t\tif (y->r == x) y->r = t;\n\t\t}\n\t}\n};\n\n/**\n * @brief\
    \ Splay Tree(base)\n */\n\ntemplate <class T, class E>\nstruct LazyReversibleSplayTreeNode\
    \ {\n\tusing Ptr = LazyReversibleSplayTreeNode *;\n\tPtr l, r, p;\n\tT key, sum;\n\
    \tE lazy;\n\tint cnt;\n\tbool rev;\n\n\tLazyReversibleSplayTreeNode(const T &t\
    \ = T(), const E &e = E())\n\t\t\t: l(), r(), p(), key(t), sum(t), lazy(e), cnt(1),\
    \ rev(false) {}\n};\n\ntemplate <class T, class E, T (*f)(T, T), T (*g)(T, E),\
    \ E (*h)(E, E),\n\t\t\t\t\tT (*ts)(T)>\nstruct LazyReversibleSplayTree\n\t\t:\
    \ LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<T, E>>,\n\t\t\t\
    \t\t\t\t\t\t\t\t\t LazyReversibleSplayTreeNode<T, E>, T, E, f, g, h, ts> {\n\t\
    using Node = LazyReversibleSplayTreeNode<T, E>;\n};\n\n/**\n * @brief \u9045\u5EF6\
    \u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree\n */\n"
  code: "template <class Tree, class Node, class T, class E, T (*f)(T, T),\n\t\t\t\
    \t\tT (*g)(T, E), E (*h)(E, E), T (*ts)(T)>\nstruct LazyReversibleBBST : Tree\
    \ {\n\tusing Tree::merge;\n\tusing Tree::split;\n\t\tusing class Tree::Ptr;\n\n\
    \tLazyReversibleBBST() = default;\n\n\tvoid toggle(Ptr t) {\n\t\tswap(t->l, t->r);\n\
    \t\tt->sum = ts(t->sum);\n\t\tt->rev ^= true;\n\t}\n\n\tT fold(Ptr &t, int a,\
    \ int b) {\n\t\tauto x = split(t, a);\n\t\tauto y = split(x.second, b - a);\n\t\
    \tauto ret = sum(y.first);\n\t\tt = merge(x.first, merge(y.first, y.second));\n\
    \t\treturn ret;\n\t}\n\n\tvoid reverse(Ptr &t, int a, int b) {\n\t\tauto x = split(t,\
    \ a);\n\t\tauto y = split(x.second, b - a);\n\t\ttoggle(y.first);\n\t\tt = merge(x.first,\
    \ merge(y.first, y.second));\n\t}\n\n\tvoid apply(Ptr &t, int a, int b, const\
    \ E &e) {\n\t\tauto x = split(t, a);\n\t\tauto y = split(x.second, b - a);\n\t\
    \tpropagate(y.first, e);\n\t\tt = merge(x.first, merge(y.first, y.second));\n\t\
    }\n\n protected:\n\tinline T sum(const Ptr t) { return t ? t->sum : T(); }\n\n\
    \tPtr update(Ptr t) override {\n\t\tif (!t) return t;\n\t\tt->cnt = 1;\n\t\tt->sum\
    \ = t->key;\n\t\tif (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n\
    \t\tif (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n\t\treturn\
    \ t;\n\t}\n\n\tvoid push(Ptr t) override {\n\t\tif (!t) return;\n\t\tif (t->rev)\
    \ {\n\t\t\tif (t->l) toggle(t->l);\n\t\t\tif (t->r) toggle(t->r);\n\t\t\tt->rev\
    \ = false;\n\t\t}\n\t\tif (t->lazy != E()) {\n\t\t\tif (t->l) propagate(t->l,\
    \ t->lazy);\n\t\t\tif (t->r) propagate(t->r, t->lazy);\n\t\t\tt->lazy = E();\n\
    \t\t}\n\t}\n\n\tvoid propagate(Ptr t, const E &x) {\n\t\tt->lazy = h(t->lazy,\
    \ x);\n\t\tt->key = g(t->key, x);\n\t\tt->sum = g(t->sum, x);\n\t}\n};\n\n/**\n\
    \ * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\
    \u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 2 \"lct/splay-base.hpp\"\n\n\
    template <class Node>\nstruct SplayTreeBase {\n\tusing Ptr = Node *;\n\ttemplate\
    \ <class... Args>\n\tPtr my_new(const Args &... args) {\n\t\treturn new Node(args...);\n\
    \t}\n\tvoid my_del(Ptr p) { delete p; }\n\n\tbool is_root(Ptr t) { return !(t->p)\
    \ || (t->p->l != t && t->p->r != t); }\n\n\tint size(Ptr t) const { return count(t);\
    \ }\n\n\tvirtual void splay(Ptr t) {\n\t\tpush(t);\n\t\twhile (!is_root(t)) {\n\
    \t\t\tPtr q = t->p;\n\t\t\tif (is_root(q)) {\n\t\t\t\tpush(q), push(t);\n\t\t\t\
    \trot(t);\n\t\t\t} else {\n\t\t\t\tPtr r = q->p;\n\t\t\t\tpush(r), push(q), push(t);\n\
    \t\t\t\tif (pos(q) == pos(t))\n\t\t\t\t\trot(q), rot(t);\n\t\t\t\telse\n\t\t\t\
    \t\trot(t), rot(t);\n\t\t\t}\n\t\t}\n\t}\n\n\tPtr get_left(Ptr t) {\n\t\twhile\
    \ (t->l) push(t), t = t->l;\n\t\treturn t;\n\t}\n\n\tPtr get_right(Ptr t) {\n\t\
    \twhile (t->r) push(t), t = t->r;\n\t\treturn t;\n\t}\n\n\tpair<Ptr, Ptr> split(Ptr\
    \ t, int k) {\n\t\tif (!t) return {nullptr, nullptr};\n\t\tif (k == 0) return\
    \ {nullptr, t};\n\t\tif (k == count(t)) return {t, nullptr};\n\t\tpush(t);\n\t\
    \tif (k <= count(t->l)) {\n\t\t\tauto x = split(t->l, k);\n\t\t\tt->l = x.second;\n\
    \t\t\tt->p = nullptr;\n\t\t\tif (x.second) x.second->p = t;\n\t\t\treturn {x.first,\
    \ update(t)};\n\t\t} else {\n\t\t\tauto x = split(t->r, k - count(t->l) - 1);\n\
    \t\t\tt->r = x.first;\n\t\t\tt->p = nullptr;\n\t\t\tif (x.first) x.first->p =\
    \ t;\n\t\t\treturn {update(t), x.second};\n\t\t}\n\t}\n\n\tPtr merge(Ptr l, Ptr\
    \ r) {\n\t\tif (!l && !r) return nullptr;\n\t\tif (!l) return splay(r), r;\n\t\
    \tif (!r) return splay(l), l;\n\t\tsplay(l), splay(r);\n\t\tl = get_right(l);\n\
    \t\tsplay(l);\n\t\tl->r = r;\n\t\tr->p = l;\n\t\tupdate(l);\n\t\treturn l;\n\t\
    }\n\n\tusing Key = decltype(Node::key);\n\tPtr build(const vector<Key> &v) { return\
    \ build(0, v.size(), v); }\n\tPtr build(int l, int r, const vector<Key> &v) {\n\
    \t\tif (l + 1 >= r) return my_new(v[l]);\n\t\treturn merge(build(l, (l + r) >>\
    \ 1, v), build((l + r) >> 1, r, v));\n\t}\n\n\ttemplate <class... Args>\n\tvoid\
    \ insert(Ptr &t, int k, const Args &... args) {\n\t\tsplay(t);\n\t\tauto x = split(t,\
    \ k);\n\t\tt = merge(merge(x.first, my_new(args...)), x.second);\n\t}\n\n\tvoid\
    \ erase(Ptr &t, int k) {\n\t\tsplay(t);\n\t\tauto x = split(t, k);\n\t\tauto y\
    \ = split(x.second, 1);\n\t\tmy_del(y.first);\n\t\tt = merge(x.first, y.second);\n\
    \t}\n\n\tvirtual Ptr update(Ptr t) = 0;\n\n protected:\n\tinline int count(Ptr\
    \ t) const { return t ? t->cnt : 0; }\n\n\tvirtual void push(Ptr t) = 0;\n\n\t\
    Ptr build(const vector<Ptr> &v) { return build(0, v.size(), v); }\n\n\tPtr build(int\
    \ l, int r, const vector<Ptr> &v) {\n\t\tif (l + 1 >= r) return v[l];\n\t\treturn\
    \ merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n\t}\n\n\tinline\
    \ int pos(Ptr t) {\n\t\tif (t->p) {\n\t\t\tif (t->p->l == t) return -1;\n\t\t\t\
    if (t->p->r == t) return 1;\n\t\t}\n\t\treturn 0;\n\t}\n\n\tvirtual void rot(Ptr\
    \ t) {\n\t\tPtr x = t->p, y = x->p;\n\t\tif (pos(t) == -1) {\n\t\t\tif ((x->l\
    \ = t->r)) t->r->p = x;\n\t\t\tt->r = x, x->p = t;\n\t\t} else {\n\t\t\tif ((x->r\
    \ = t->l)) t->l->p = x;\n\t\t\tt->l = x, x->p = t;\n\t\t}\n\t\tupdate(x), update(t);\n\
    \t\tif ((t->p = y)) {\n\t\t\tif (y->l == x) y->l = t;\n\t\t\tif (y->r == x) y->r\
    \ = t;\n\t\t}\n\t}\n};\n\n/**\n * @brief Splay Tree(base)\n */\n#line 5 \"lct/splay-lazy-reversible.hpp\"\
    \n\ntemplate <class T, class E>\nstruct LazyReversibleSplayTreeNode {\n\tusing\
    \ Ptr = LazyReversibleSplayTreeNode *;\n\tPtr l, r, p;\n\tT key, sum;\n\tE lazy;\n\
    \tint cnt;\n\tbool rev;\n\n\tLazyReversibleSplayTreeNode(const T &t = T(), const\
    \ E &e = E())\n\t\t\t: l(), r(), p(), key(t), sum(t), lazy(e), cnt(1), rev(false)\
    \ {}\n};\n\ntemplate <class T, class E, T (*f)(T, T), T (*g)(T, E), E (*h)(E,\
    \ E),\n\t\t\t\t\tT (*ts)(T)>\nstruct LazyReversibleSplayTree\n\t\t: LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<T,\
    \ E>>,\n\t\t\t\t\t\t\t\t\t\t\t\t LazyReversibleSplayTreeNode<T, E>, T, E, f, g,\
    \ h, ts> {\n\tusing Node = LazyReversibleSplayTreeNode<T, E>;\n};\n\n/**\n * @brief\
    \ \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/balanced-binary-search-trees/splay-base.hpp
  requiredBy: []
  timestamp: '2021-11-19 12:57:43-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/balanced-binary-search-trees/splay-base.hpp
layout: document
redirect_from:
- /library/library/data-structures/balanced-binary-search-trees/splay-base.hpp
- /library/library/data-structures/balanced-binary-search-trees/splay-base.hpp.html
title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\
  (\u57FA\u5E95\u30AF\u30E9\u30B9)"
---
