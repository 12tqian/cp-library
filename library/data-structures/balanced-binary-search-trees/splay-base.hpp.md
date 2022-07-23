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
  bundledCode: "template <class Tree, class Node, class T, class E, T (*f)(T, T),\r\
    \n\t\t\t\t\tT (*g)(T, E), E (*h)(E, E), T (*ts)(T)>\r\nstruct LazyReversibleBBST\
    \ : Tree {\r\n\tusing Tree::merge;\r\n\tusing Tree::split;\r\n\t\tusing class\
    \ Tree::Ptr;\r\n\r\n\tLazyReversibleBBST() = default;\r\n\r\n\tvoid toggle(Ptr\
    \ t) {\r\n\t\tswap(t->l, t->r);\r\n\t\tt->sum = ts(t->sum);\r\n\t\tt->rev ^= true;\r\
    \n\t}\r\n\r\n\tT fold(Ptr &t, int a, int b) {\r\n\t\tauto x = split(t, a);\r\n\
    \t\tauto y = split(x.second, b - a);\r\n\t\tauto ret = sum(y.first);\r\n\t\tt\
    \ = merge(x.first, merge(y.first, y.second));\r\n\t\treturn ret;\r\n\t}\r\n\r\n\
    \tvoid reverse(Ptr &t, int a, int b) {\r\n\t\tauto x = split(t, a);\r\n\t\tauto\
    \ y = split(x.second, b - a);\r\n\t\ttoggle(y.first);\r\n\t\tt = merge(x.first,\
    \ merge(y.first, y.second));\r\n\t}\r\n\r\n\tvoid apply(Ptr &t, int a, int b,\
    \ const E &e) {\r\n\t\tauto x = split(t, a);\r\n\t\tauto y = split(x.second, b\
    \ - a);\r\n\t\tpropagate(y.first, e);\r\n\t\tt = merge(x.first, merge(y.first,\
    \ y.second));\r\n\t}\r\n\r\n protected:\r\n\tinline T sum(const Ptr t) { return\
    \ t ? t->sum : T(); }\r\n\r\n\tPtr update(Ptr t) override {\r\n\t\tif (!t) return\
    \ t;\r\n\t\tt->cnt = 1;\r\n\t\tt->sum = t->key;\r\n\t\tif (t->l) t->cnt += t->l->cnt,\
    \ t->sum = f(t->l->sum, t->sum);\r\n\t\tif (t->r) t->cnt += t->r->cnt, t->sum\
    \ = f(t->sum, t->r->sum);\r\n\t\treturn t;\r\n\t}\r\n\r\n\tvoid push(Ptr t) override\
    \ {\r\n\t\tif (!t) return;\r\n\t\tif (t->rev) {\r\n\t\t\tif (t->l) toggle(t->l);\r\
    \n\t\t\tif (t->r) toggle(t->r);\r\n\t\t\tt->rev = false;\r\n\t\t}\r\n\t\tif (t->lazy\
    \ != E()) {\r\n\t\t\tif (t->l) propagate(t->l, t->lazy);\r\n\t\t\tif (t->r) propagate(t->r,\
    \ t->lazy);\r\n\t\t\tt->lazy = E();\r\n\t\t}\r\n\t}\r\n\r\n\tvoid propagate(Ptr\
    \ t, const E &x) {\r\n\t\tt->lazy = h(t->lazy, x);\r\n\t\tt->key = g(t->key, x);\r\
    \n\t\tt->sum = g(t->sum, x);\r\n\t}\r\n};\r\n\r\n/**\r\n * @brief \u9045\u5EF6\
    \u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\
    \u30AF\u30E9\u30B9)\r\n */\r\n\r\ntemplate <class Node>\r\nstruct SplayTreeBase\
    \ {\r\n\tusing Ptr = Node *;\r\n\ttemplate <class... Args>\r\n\tPtr my_new(const\
    \ Args &... args) {\r\n\t\treturn new Node(args...);\r\n\t}\r\n\tvoid my_del(Ptr\
    \ p) { delete p; }\r\n\r\n\tbool is_root(Ptr t) { return !(t->p) || (t->p->l !=\
    \ t && t->p->r != t); }\r\n\r\n\tint size(Ptr t) const { return count(t); }\r\n\
    \r\n\tvirtual void splay(Ptr t) {\r\n\t\tpush(t);\r\n\t\twhile (!is_root(t)) {\r\
    \n\t\t\tPtr q = t->p;\r\n\t\t\tif (is_root(q)) {\r\n\t\t\t\tpush(q), push(t);\r\
    \n\t\t\t\trot(t);\r\n\t\t\t} else {\r\n\t\t\t\tPtr r = q->p;\r\n\t\t\t\tpush(r),\
    \ push(q), push(t);\r\n\t\t\t\tif (pos(q) == pos(t))\r\n\t\t\t\t\trot(q), rot(t);\r\
    \n\t\t\t\telse\r\n\t\t\t\t\trot(t), rot(t);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\
    \tPtr get_left(Ptr t) {\r\n\t\twhile (t->l) push(t), t = t->l;\r\n\t\treturn t;\r\
    \n\t}\r\n\r\n\tPtr get_right(Ptr t) {\r\n\t\twhile (t->r) push(t), t = t->r;\r\
    \n\t\treturn t;\r\n\t}\r\n\r\n\tpair<Ptr, Ptr> split(Ptr t, int k) {\r\n\t\tif\
    \ (!t) return {nullptr, nullptr};\r\n\t\tif (k == 0) return {nullptr, t};\r\n\t\
    \tif (k == count(t)) return {t, nullptr};\r\n\t\tpush(t);\r\n\t\tif (k <= count(t->l))\
    \ {\r\n\t\t\tauto x = split(t->l, k);\r\n\t\t\tt->l = x.second;\r\n\t\t\tt->p\
    \ = nullptr;\r\n\t\t\tif (x.second) x.second->p = t;\r\n\t\t\treturn {x.first,\
    \ update(t)};\r\n\t\t} else {\r\n\t\t\tauto x = split(t->r, k - count(t->l) -\
    \ 1);\r\n\t\t\tt->r = x.first;\r\n\t\t\tt->p = nullptr;\r\n\t\t\tif (x.first)\
    \ x.first->p = t;\r\n\t\t\treturn {update(t), x.second};\r\n\t\t}\r\n\t}\r\n\r\
    \n\tPtr merge(Ptr l, Ptr r) {\r\n\t\tif (!l && !r) return nullptr;\r\n\t\tif (!l)\
    \ return splay(r), r;\r\n\t\tif (!r) return splay(l), l;\r\n\t\tsplay(l), splay(r);\r\
    \n\t\tl = get_right(l);\r\n\t\tsplay(l);\r\n\t\tl->r = r;\r\n\t\tr->p = l;\r\n\
    \t\tupdate(l);\r\n\t\treturn l;\r\n\t}\r\n\r\n\tusing Key = decltype(Node::key);\r\
    \n\tPtr build(const vector<Key> &v) { return build(0, v.size(), v); }\r\n\tPtr\
    \ build(int l, int r, const vector<Key> &v) {\r\n\t\tif (l + 1 >= r) return my_new(v[l]);\r\
    \n\t\treturn merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\r\n\t\
    }\r\n\r\n\ttemplate <class... Args>\r\n\tvoid insert(Ptr &t, int k, const Args\
    \ &... args) {\r\n\t\tsplay(t);\r\n\t\tauto x = split(t, k);\r\n\t\tt = merge(merge(x.first,\
    \ my_new(args...)), x.second);\r\n\t}\r\n\r\n\tvoid erase(Ptr &t, int k) {\r\n\
    \t\tsplay(t);\r\n\t\tauto x = split(t, k);\r\n\t\tauto y = split(x.second, 1);\r\
    \n\t\tmy_del(y.first);\r\n\t\tt = merge(x.first, y.second);\r\n\t}\r\n\r\n\tvirtual\
    \ Ptr update(Ptr t) = 0;\r\n\r\n protected:\r\n\tinline int count(Ptr t) const\
    \ { return t ? t->cnt : 0; }\r\n\r\n\tvirtual void push(Ptr t) = 0;\r\n\r\n\t\
    Ptr build(const vector<Ptr> &v) { return build(0, v.size(), v); }\r\n\r\n\tPtr\
    \ build(int l, int r, const vector<Ptr> &v) {\r\n\t\tif (l + 1 >= r) return v[l];\r\
    \n\t\treturn merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\r\n\t\
    }\r\n\r\n\tinline int pos(Ptr t) {\r\n\t\tif (t->p) {\r\n\t\t\tif (t->p->l ==\
    \ t) return -1;\r\n\t\t\tif (t->p->r == t) return 1;\r\n\t\t}\r\n\t\treturn 0;\r\
    \n\t}\r\n\r\n\tvirtual void rot(Ptr t) {\r\n\t\tPtr x = t->p, y = x->p;\r\n\t\t\
    if (pos(t) == -1) {\r\n\t\t\tif ((x->l = t->r)) t->r->p = x;\r\n\t\t\tt->r = x,\
    \ x->p = t;\r\n\t\t} else {\r\n\t\t\tif ((x->r = t->l)) t->l->p = x;\r\n\t\t\t\
    t->l = x, x->p = t;\r\n\t\t}\r\n\t\tupdate(x), update(t);\r\n\t\tif ((t->p = y))\
    \ {\r\n\t\t\tif (y->l == x) y->l = t;\r\n\t\t\tif (y->r == x) y->r = t;\r\n\t\t\
    }\r\n\t}\r\n};\r\n\r\n/**\r\n * @brief Splay Tree(base)\r\n */\r\n\r\ntemplate\
    \ <class T, class E>\r\nstruct LazyReversibleSplayTreeNode {\r\n\tusing Ptr =\
    \ LazyReversibleSplayTreeNode *;\r\n\tPtr l, r, p;\r\n\tT key, sum;\r\n\tE lazy;\r\
    \n\tint cnt;\r\n\tbool rev;\r\n\r\n\tLazyReversibleSplayTreeNode(const T &t =\
    \ T(), const E &e = E())\r\n\t\t\t: l(), r(), p(), key(t), sum(t), lazy(e), cnt(1),\
    \ rev(false) {}\r\n};\r\n\r\ntemplate <class T, class E, T (*f)(T, T), T (*g)(T,\
    \ E), E (*h)(E, E),\r\n\t\t\t\t\tT (*ts)(T)>\r\nstruct LazyReversibleSplayTree\r\
    \n\t\t: LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<T, E>>,\r\
    \n\t\t\t\t\t\t\t\t\t\t\t\t LazyReversibleSplayTreeNode<T, E>, T, E, f, g, h, ts>\
    \ {\r\n\tusing Node = LazyReversibleSplayTreeNode<T, E>;\r\n};\r\n\r\n/**\r\n\
    \ * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree\r\n */\n"
  code: "template <class Tree, class Node, class T, class E, T (*f)(T, T),\r\n\t\t\
    \t\t\tT (*g)(T, E), E (*h)(E, E), T (*ts)(T)>\r\nstruct LazyReversibleBBST : Tree\
    \ {\r\n\tusing Tree::merge;\r\n\tusing Tree::split;\r\n\t\tusing class Tree::Ptr;\r\
    \n\r\n\tLazyReversibleBBST() = default;\r\n\r\n\tvoid toggle(Ptr t) {\r\n\t\t\
    swap(t->l, t->r);\r\n\t\tt->sum = ts(t->sum);\r\n\t\tt->rev ^= true;\r\n\t}\r\n\
    \r\n\tT fold(Ptr &t, int a, int b) {\r\n\t\tauto x = split(t, a);\r\n\t\tauto\
    \ y = split(x.second, b - a);\r\n\t\tauto ret = sum(y.first);\r\n\t\tt = merge(x.first,\
    \ merge(y.first, y.second));\r\n\t\treturn ret;\r\n\t}\r\n\r\n\tvoid reverse(Ptr\
    \ &t, int a, int b) {\r\n\t\tauto x = split(t, a);\r\n\t\tauto y = split(x.second,\
    \ b - a);\r\n\t\ttoggle(y.first);\r\n\t\tt = merge(x.first, merge(y.first, y.second));\r\
    \n\t}\r\n\r\n\tvoid apply(Ptr &t, int a, int b, const E &e) {\r\n\t\tauto x =\
    \ split(t, a);\r\n\t\tauto y = split(x.second, b - a);\r\n\t\tpropagate(y.first,\
    \ e);\r\n\t\tt = merge(x.first, merge(y.first, y.second));\r\n\t}\r\n\r\n protected:\r\
    \n\tinline T sum(const Ptr t) { return t ? t->sum : T(); }\r\n\r\n\tPtr update(Ptr\
    \ t) override {\r\n\t\tif (!t) return t;\r\n\t\tt->cnt = 1;\r\n\t\tt->sum = t->key;\r\
    \n\t\tif (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\r\n\t\tif\
    \ (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\r\n\t\treturn t;\r\
    \n\t}\r\n\r\n\tvoid push(Ptr t) override {\r\n\t\tif (!t) return;\r\n\t\tif (t->rev)\
    \ {\r\n\t\t\tif (t->l) toggle(t->l);\r\n\t\t\tif (t->r) toggle(t->r);\r\n\t\t\t\
    t->rev = false;\r\n\t\t}\r\n\t\tif (t->lazy != E()) {\r\n\t\t\tif (t->l) propagate(t->l,\
    \ t->lazy);\r\n\t\t\tif (t->r) propagate(t->r, t->lazy);\r\n\t\t\tt->lazy = E();\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid propagate(Ptr t, const E &x) {\r\n\t\tt->lazy = h(t->lazy,\
    \ x);\r\n\t\tt->key = g(t->key, x);\r\n\t\tt->sum = g(t->sum, x);\r\n\t}\r\n};\r\
    \n\r\n/**\r\n * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\
    \u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\r\n */\r\n#line 2 \"lct/splay-base.hpp\"\
    \r\n\r\ntemplate <class Node>\r\nstruct SplayTreeBase {\r\n\tusing Ptr = Node\
    \ *;\r\n\ttemplate <class... Args>\r\n\tPtr my_new(const Args &... args) {\r\n\
    \t\treturn new Node(args...);\r\n\t}\r\n\tvoid my_del(Ptr p) { delete p; }\r\n\
    \r\n\tbool is_root(Ptr t) { return !(t->p) || (t->p->l != t && t->p->r != t);\
    \ }\r\n\r\n\tint size(Ptr t) const { return count(t); }\r\n\r\n\tvirtual void\
    \ splay(Ptr t) {\r\n\t\tpush(t);\r\n\t\twhile (!is_root(t)) {\r\n\t\t\tPtr q =\
    \ t->p;\r\n\t\t\tif (is_root(q)) {\r\n\t\t\t\tpush(q), push(t);\r\n\t\t\t\trot(t);\r\
    \n\t\t\t} else {\r\n\t\t\t\tPtr r = q->p;\r\n\t\t\t\tpush(r), push(q), push(t);\r\
    \n\t\t\t\tif (pos(q) == pos(t))\r\n\t\t\t\t\trot(q), rot(t);\r\n\t\t\t\telse\r\
    \n\t\t\t\t\trot(t), rot(t);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tPtr get_left(Ptr\
    \ t) {\r\n\t\twhile (t->l) push(t), t = t->l;\r\n\t\treturn t;\r\n\t}\r\n\r\n\t\
    Ptr get_right(Ptr t) {\r\n\t\twhile (t->r) push(t), t = t->r;\r\n\t\treturn t;\r\
    \n\t}\r\n\r\n\tpair<Ptr, Ptr> split(Ptr t, int k) {\r\n\t\tif (!t) return {nullptr,\
    \ nullptr};\r\n\t\tif (k == 0) return {nullptr, t};\r\n\t\tif (k == count(t))\
    \ return {t, nullptr};\r\n\t\tpush(t);\r\n\t\tif (k <= count(t->l)) {\r\n\t\t\t\
    auto x = split(t->l, k);\r\n\t\t\tt->l = x.second;\r\n\t\t\tt->p = nullptr;\r\n\
    \t\t\tif (x.second) x.second->p = t;\r\n\t\t\treturn {x.first, update(t)};\r\n\
    \t\t} else {\r\n\t\t\tauto x = split(t->r, k - count(t->l) - 1);\r\n\t\t\tt->r\
    \ = x.first;\r\n\t\t\tt->p = nullptr;\r\n\t\t\tif (x.first) x.first->p = t;\r\n\
    \t\t\treturn {update(t), x.second};\r\n\t\t}\r\n\t}\r\n\r\n\tPtr merge(Ptr l,\
    \ Ptr r) {\r\n\t\tif (!l && !r) return nullptr;\r\n\t\tif (!l) return splay(r),\
    \ r;\r\n\t\tif (!r) return splay(l), l;\r\n\t\tsplay(l), splay(r);\r\n\t\tl =\
    \ get_right(l);\r\n\t\tsplay(l);\r\n\t\tl->r = r;\r\n\t\tr->p = l;\r\n\t\tupdate(l);\r\
    \n\t\treturn l;\r\n\t}\r\n\r\n\tusing Key = decltype(Node::key);\r\n\tPtr build(const\
    \ vector<Key> &v) { return build(0, v.size(), v); }\r\n\tPtr build(int l, int\
    \ r, const vector<Key> &v) {\r\n\t\tif (l + 1 >= r) return my_new(v[l]);\r\n\t\
    \treturn merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\r\n\t}\r\
    \n\r\n\ttemplate <class... Args>\r\n\tvoid insert(Ptr &t, int k, const Args &...\
    \ args) {\r\n\t\tsplay(t);\r\n\t\tauto x = split(t, k);\r\n\t\tt = merge(merge(x.first,\
    \ my_new(args...)), x.second);\r\n\t}\r\n\r\n\tvoid erase(Ptr &t, int k) {\r\n\
    \t\tsplay(t);\r\n\t\tauto x = split(t, k);\r\n\t\tauto y = split(x.second, 1);\r\
    \n\t\tmy_del(y.first);\r\n\t\tt = merge(x.first, y.second);\r\n\t}\r\n\r\n\tvirtual\
    \ Ptr update(Ptr t) = 0;\r\n\r\n protected:\r\n\tinline int count(Ptr t) const\
    \ { return t ? t->cnt : 0; }\r\n\r\n\tvirtual void push(Ptr t) = 0;\r\n\r\n\t\
    Ptr build(const vector<Ptr> &v) { return build(0, v.size(), v); }\r\n\r\n\tPtr\
    \ build(int l, int r, const vector<Ptr> &v) {\r\n\t\tif (l + 1 >= r) return v[l];\r\
    \n\t\treturn merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\r\n\t\
    }\r\n\r\n\tinline int pos(Ptr t) {\r\n\t\tif (t->p) {\r\n\t\t\tif (t->p->l ==\
    \ t) return -1;\r\n\t\t\tif (t->p->r == t) return 1;\r\n\t\t}\r\n\t\treturn 0;\r\
    \n\t}\r\n\r\n\tvirtual void rot(Ptr t) {\r\n\t\tPtr x = t->p, y = x->p;\r\n\t\t\
    if (pos(t) == -1) {\r\n\t\t\tif ((x->l = t->r)) t->r->p = x;\r\n\t\t\tt->r = x,\
    \ x->p = t;\r\n\t\t} else {\r\n\t\t\tif ((x->r = t->l)) t->l->p = x;\r\n\t\t\t\
    t->l = x, x->p = t;\r\n\t\t}\r\n\t\tupdate(x), update(t);\r\n\t\tif ((t->p = y))\
    \ {\r\n\t\t\tif (y->l == x) y->l = t;\r\n\t\t\tif (y->r == x) y->r = t;\r\n\t\t\
    }\r\n\t}\r\n};\r\n\r\n/**\r\n * @brief Splay Tree(base)\r\n */\r\n#line 5 \"lct/splay-lazy-reversible.hpp\"\
    \r\n\r\ntemplate <class T, class E>\r\nstruct LazyReversibleSplayTreeNode {\r\n\
    \tusing Ptr = LazyReversibleSplayTreeNode *;\r\n\tPtr l, r, p;\r\n\tT key, sum;\r\
    \n\tE lazy;\r\n\tint cnt;\r\n\tbool rev;\r\n\r\n\tLazyReversibleSplayTreeNode(const\
    \ T &t = T(), const E &e = E())\r\n\t\t\t: l(), r(), p(), key(t), sum(t), lazy(e),\
    \ cnt(1), rev(false) {}\r\n};\r\n\r\ntemplate <class T, class E, T (*f)(T, T),\
    \ T (*g)(T, E), E (*h)(E, E),\r\n\t\t\t\t\tT (*ts)(T)>\r\nstruct LazyReversibleSplayTree\r\
    \n\t\t: LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<T, E>>,\r\
    \n\t\t\t\t\t\t\t\t\t\t\t\t LazyReversibleSplayTreeNode<T, E>, T, E, f, g, h, ts>\
    \ {\r\n\tusing Node = LazyReversibleSplayTreeNode<T, E>;\r\n};\r\n\r\n/**\r\n\
    \ * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/balanced-binary-search-trees/splay-base.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
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
