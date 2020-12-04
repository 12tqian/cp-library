---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dmoj_dynamic_tree_test.cpp\"\n/**\nBenq's\
    \ code made without macros and nicer\nDoes everything a link cut tree could possibly\
    \ want to\n*/\n#pragma GCC optimize (\"O3\")\n#pragma GCC target (\"sse4\")\n\n\
    #include <bits/stdc++.h>\n\nstruct info {\n    int sz, sum, mn, mx;\n    info\
    \ (int v) {\n        if (v == INT_MAX) {\n            sz = sum = 0;\n        \
    \    mn = INT_MAX, mx = INT_MIN;\n        } else {\n            sz = 1; sum =\
    \ mn = mx = v;\n        }\n    }\n    info() : info(INT_MAX) {}\n    friend info&\
    \ operator+=(info& a, const info& b) {\n        a.sz += b.sz, a.sum += b.sum;\n\
    \        a.mn = std::min(a.mn, b.mn);\n        a.mx = std::max(a.mx, b.mx);\n\
    \        return a;\n    }\n};\ntypedef struct snode* sn;\nstruct snode {\n   \
    \ int id, val; // value in node\n    sn p; // parent\n    sn c[5]; // children\n\
    \    bool flip = 0;\n    info data[2];\n    int next_num[2], lazy[2];\n    snode(int\
    \ _id, int v) {\n        id = _id; val = v;\n        p = NULL;\n        for (int\
    \ i = 0; i < 5; i++) {\n            c[i] = NULL;\n        }\n        next_num[0]\
    \ = next_num[1] = INT_MAX;\n        lazy[0] = lazy[1] = 0;\n        calc();\n\
    \    }\n    //////// splay tree operations\n    void prop() {\n        if (flip)\
    \ {\n            std::swap(c[0], c[1]);\n            for (int i = 0; i < 2; i++)\
    \ {\n                if (c[i]) {\n                    c[i]->flip ^= 1;\n     \
    \           }\n            }\n            flip = 0;\n        }\n        if (next_num[1]\
    \ != INT_MAX) {\n            if (data[1].sz) {\n                data[1].sum =\
    \ next_num[1] * data[1].sz;\n                data[1].mn = data[1].mx = next_num[1];\n\
    \            }\n            for (int i = 0; i < 5; i++) {\n                if\
    \ (c[i]) {\n                    c[i]->next_num[1] = next_num[1], c[i]->lazy[1]\
    \ = 0;\n                    if (i >= 2) {\n                        c[i]->next_num[0]\
    \ = next_num[1];\n                        c[i]->lazy[0] = 0;\n               \
    \     }\n                }\n            }\n            next_num[1] = INT_MAX;\n\
    \        }\n        if (lazy[1] != 0) {\n            if (data[1].sz) {\n     \
    \           data[1].sum += lazy[1] * data[1].sz;\n                data[1].mn +=\
    \ lazy[1], data[1].mx += lazy[1];\n            }\n            for (int i = 0;\
    \ i < 5; i++) {\n                if (c[i]) {\n                    c[i]->lazy[1]\
    \ += lazy[1];\n                    if (i >= 2) {\n                        c[i]->lazy[0]\
    \ += lazy[1];\n                    }\n                }\n            }\n     \
    \       lazy[1] = 0;\n        }\n        if (next_num[0] != INT_MAX) {\n     \
    \       val = next_num[0];\n            data[0].sum = next_num[0] * data[0].sz;\n\
    \            data[0].mn = data[0].mx = next_num[0];\n            for (int i =\
    \ 0; i < 2; i++) {\n                if (c[i]) {\n                    c[i]->next_num[0]\
    \ = next_num[0];\n                    c[i]->lazy[0] = 0;\n                }\n\
    \            }\n            next_num[0] = INT_MAX;\n        }\n        if (lazy[0]\
    \ != 0) {\n            val += lazy[0];\n            data[0].sum += lazy[0] * data[0].sz;\n\
    \            data[0].mn += lazy[0], data[0].mx += lazy[0];\n            for (int\
    \ i = 0; i < 2; i++) {\n                if (c[i]) {\n                    c[i]->lazy[0]\
    \ += lazy[0];\n                }\n            }\n            lazy[0] = 0;\n  \
    \      }\n    }\n    void calc() {\n        for (int i = 0; i < 5; i++) {\n  \
    \          if (c[i]) {\n                c[i]->prop();\n            }\n       \
    \ }\n        data[0] = info(val); data[1] = info(INT_MAX);\n        for (int i\
    \ = 0; i < 5; i++) {\n            if (c[i]) {\n                data[1] += c[i]->data[1];\n\
    \                if (i >= 2) {\n                    data[1] += c[i]->data[0];\n\
    \                }\n                else data[0] += c[i]->data[0];\n         \
    \   }\n        }\n    }\n    int dir() {\n        if (!p) return -2;\n       \
    \ for (int i = 0; i < 5; i++) {\n            if (p->c[i] == this) {\n        \
    \        return i;\n            }\n        }\n        assert(false);\n    }\n\
    \    bool is_root() {\n        int d = dir();\n        return d == -2 || d ==\
    \ 4;\n    }\n\n    friend void set_link(sn x, sn y, int d) {\n        if (y) y->p\
    \ = x;\n        if (d >= 0) x->c[d] = y;\n    }\n    void rot() {\n        assert(!is_root());\n\
    \        int x = dir(); sn pa = p;\n        set_link(pa->p, this, pa->dir());\n\
    \        set_link(pa, c[x ^ 1], x);\n        set_link(this, pa, x ^ 1);\n    \
    \    pa->calc(); calc();\n    }\n    bool ok_zero() {\n        int d = dir();\n\
    \        return d == 0 || d == 1;\n    }\n    void splay() {\n        while (ok_zero()\
    \ && p->ok_zero() && p->p->ok_zero()) {\n            p->p->prop(), p->prop(),\
    \ prop();\n            dir() == p->dir() ? p->rot() : rot();\n            rot();\n\
    \        }\n        if (ok_zero() && p->ok_zero()) p->prop(), prop(), rot();\n\
    \        if (ok_zero()) {\n            p->prop(), prop();\n            auto a\
    \ = p->p, b = p->c[2], c = p->c[3]; int d = p->dir();\n            p->p = p->c[2]\
    \ = p->c[3] = NULL; p->calc(); rot();\n            set_link(this, b, 2); set_link(this,\
    \ c, 3); set_link(a, this, d); calc();\n        }\n        while (!is_root() &&\
    \ !p->is_root()) {\n            p->p->prop(), p->prop(), prop();\n           \
    \ dir() == p->dir() ? p->rot() : rot();\n            rot();\n        }\n     \
    \   if (!is_root()) p->prop(), prop(), rot();\n        prop();\n    }\n\n    sn\
    \ splay_right() {\n        prop();\n        if (!c[3]) { splay(); return this;\
    \ }\n        return c[3]->splay_right();\n    }\n\n    friend sn join(sn a, sn\
    \ b) {\n        if (!a) return b;\n        a->splay(); a = a->splay_right();\n\
    \        set_link(a, b, 3); a->calc();\n        return a;\n    }\n    ////////\
    \ link cut tree operations\n    void access() { // bring this to top of tree,\
    \ left subtree of this is now path to root\n        int it = 0;\n        for (sn\
    \ v = this, pre = NULL; v; v = v->p) {\n            it ++;\n            v->splay();\
    \ auto c = v->c[1];\n            if (c) assert(!c->c[2] && !c->c[3]);\n      \
    \      if (pre) pre->prop();\n            if (pre) {\n                assert(v->c[4]\
    \ == pre);\n                auto a = pre->c[2], b = pre->c[3];\n             \
    \   if (a) a->p = NULL;\n                if (b) b->p = NULL;\n               \
    \ pre->c[2] = pre->c[3] = NULL; pre->calc();\n                if (c) c->p = NULL;\n\
    \                set_link(v, join(join(a, b), c), 4);\n            } else {\n\
    \                if (c) c->p = NULL;\n                if (v->c[4]) v->c[4]->p\
    \ = NULL;\n                set_link(v, join(c, v->c[4]), 4);\n            }\n\
    \            v->c[1] = pre; v->calc(); pre = v;\n        }\n        splay(); assert(!c[1]);\n\
    \    }\n    void make_root() {\n        access();\n        flip ^= 1;\n    }\n\
    \    //////// link cut tree queries\n    friend sn lca(sn x, sn y) {\n       \
    \ if (x == y) return x;\n        x->access(); y->access();\n        if (!x->p)\
    \ return NULL;\n        x->splay(); return x->p ? x->p : x;\n    }\n    friend\
    \ bool connected(sn x, sn y) {\n        return lca(x,y);\n    }\n    friend sn\
    \ get_par(sn x) {\n        x->access(); x = x->c[0];\n        while (true) {\n\
    \            x->prop();\n            if (!x->c[1]) return x;\n            x =\
    \ x->c[1];\n        }\n        return x;\n    }\n    //////// link cut tree modifications\n\
    \    friend bool link(sn x, sn y) { // make y parent of x\n        if (connected(x,\
    \ y)) exit(2);\n        x->make_root();\n        set_link(y, join(x, y->c[4]),\
    \ 4);\n        y->calc();\n        return 1;\n    }\n    friend bool cut(sn x,\
    \ sn y) {\n        x->make_root(); y->access();\n        if (y->c[0] != x || x->c[0]\
    \ || x->c[1]) exit(3);\n        x->p = y->c[0] = NULL; y->calc();\n        return\
    \ true;\n    }\n    void prop_all() {\n        prop();\n        for (int i = 0;\
    \ i < 5; i++) {\n            if (c[i]) {\n                c[i]->prop_all();\n\
    \            }\n        }\n    }\n};\nint main() {\n    std::ios_base::sync_with_stdio(0);\
    \ std::cin.tie(0);\n    int n, m, root;\n    std::cin >> n >> m;\n    std::vector<sn>\
    \ lct(n);\n    std::vector<std::pair<int, int>> ed(n - 1);\n    for (int i = 0;\
    \ i < n - 1; i++) {\n        std::cin >> ed[i].first >> ed[i].second;\n    }\n\
    \    for (int i = 1; i <= n; i++) {\n        int x; std::cin >> x;\n        lct[i]\
    \ = new snode(i, x);\n    }\n    for (int i = 0; i < n - 1; i++) {\n        int\
    \ x = ed[i].first, y = ed[i].second;\n        link(lct[x], lct[y]);\n    }\n \
    \   std::cin >> root;\n    while (m--) {\n        int k; std::cin >> k;\n    \
    \    if (k == 0 || k == 5) {\n            int x, y; std::cin >> x >> y;\n    \
    \        lct[root]->make_root();\n            lct[x]->access();\n            auto\
    \ c = lct[x]->c[4];\n            if (k == 0) { // set weights in subtree of x\
    \ to y\n                if (c) c->prop(), c->next_num[0] = c->next_num[1] = y;\n\
    \                lct[x]->val = y;\n\n            } else { // add y to subtree\
    \ of x vertices\n                if (c) c->prop(), c->lazy[0] = c->lazy[1] = y;\n\
    \                lct[x]->val += y;\n            }\n            lct[x]->calc();\n\
    \        } else if (k == 1) { // change root\n            int x; std::cin >> x;\n\
    \            root = x;\n        } else if (k == 2 || k == 6) {\n            int\
    \ x, y, z; std::cin >> x >> y >> z;\n            lct[x]->make_root();\n      \
    \      if (k == 2) { // sets path x to y to weight z\n                lct[y]->access();\n\
    \                lct[y]->next_num[0] = z;\n            }\n            else { //\
    \ add z to vertices on path from x to y\n                lct[y]->access();\n \
    \               lct[y]->lazy[0] = z;\n            }\n        } else if (k == 3\
    \ || k == 4 || k == 11) {\n            int x; std::cin >> x;\n            lct[root]->make_root();\n\
    \            lct[x]->access();\n            auto ans = info(lct[x]->val);\n  \
    \          sn c = lct[x]->c[4];\n            if (c) c->prop(), ans += c->data[0],\
    \ ans += c->data[1];\n            if (k == 3) std::cout << ans.mn << '\\n'; //\
    \ x subtree min\n            else if (k == 4) std::cout << ans.mx << '\\n'; //\
    \ x subtree max\n            else if (k == 11) std::cout << ans.sum << '\\n';\
    \ // x subtree sum\n        } else if (k == 7 || k == 8 || k == 10) {\n      \
    \      int x, y;\n            std::cin >> x >> y;\n            lct[x]->make_root();\n\
    \            lct[y]->access();\n            auto ans = lct[y]->data[0];\n    \
    \        if (k == 7) std::cout << ans.mn << '\\n'; // x, y path min\n        \
    \    else if (k == 8) std::cout << ans.mx << '\\n'; // x, y path max\n       \
    \     else std::cout << ans.sum << '\\n'; // x, y path sum\n        } else if\
    \ (k == 9) { // change parent of x to y\n            int x, y;\n            std::cin\
    \ >> x >> y;\n            lct[root]->make_root();\n            if (lca(lct[x],\
    \ lct[y]) == lct[x]) {\n                continue;\n            }\n           \
    \ cut(get_par(lct[x]), lct[x]);\n            link(lct[x], lct[y]);\n        }\
    \ else exit(5);\n    }\n    return 0;\n}\n"
  code: "/**\nBenq's code made without macros and nicer\nDoes everything a link cut\
    \ tree could possibly want to\n*/\n#pragma GCC optimize (\"O3\")\n#pragma GCC\
    \ target (\"sse4\")\n\n#include <bits/stdc++.h>\n\nstruct info {\n    int sz,\
    \ sum, mn, mx;\n    info (int v) {\n        if (v == INT_MAX) {\n            sz\
    \ = sum = 0;\n            mn = INT_MAX, mx = INT_MIN;\n        } else {\n    \
    \        sz = 1; sum = mn = mx = v;\n        }\n    }\n    info() : info(INT_MAX)\
    \ {}\n    friend info& operator+=(info& a, const info& b) {\n        a.sz += b.sz,\
    \ a.sum += b.sum;\n        a.mn = std::min(a.mn, b.mn);\n        a.mx = std::max(a.mx,\
    \ b.mx);\n        return a;\n    }\n};\ntypedef struct snode* sn;\nstruct snode\
    \ {\n    int id, val; // value in node\n    sn p; // parent\n    sn c[5]; // children\n\
    \    bool flip = 0;\n    info data[2];\n    int next_num[2], lazy[2];\n    snode(int\
    \ _id, int v) {\n        id = _id; val = v;\n        p = NULL;\n        for (int\
    \ i = 0; i < 5; i++) {\n            c[i] = NULL;\n        }\n        next_num[0]\
    \ = next_num[1] = INT_MAX;\n        lazy[0] = lazy[1] = 0;\n        calc();\n\
    \    }\n    //////// splay tree operations\n    void prop() {\n        if (flip)\
    \ {\n            std::swap(c[0], c[1]);\n            for (int i = 0; i < 2; i++)\
    \ {\n                if (c[i]) {\n                    c[i]->flip ^= 1;\n     \
    \           }\n            }\n            flip = 0;\n        }\n        if (next_num[1]\
    \ != INT_MAX) {\n            if (data[1].sz) {\n                data[1].sum =\
    \ next_num[1] * data[1].sz;\n                data[1].mn = data[1].mx = next_num[1];\n\
    \            }\n            for (int i = 0; i < 5; i++) {\n                if\
    \ (c[i]) {\n                    c[i]->next_num[1] = next_num[1], c[i]->lazy[1]\
    \ = 0;\n                    if (i >= 2) {\n                        c[i]->next_num[0]\
    \ = next_num[1];\n                        c[i]->lazy[0] = 0;\n               \
    \     }\n                }\n            }\n            next_num[1] = INT_MAX;\n\
    \        }\n        if (lazy[1] != 0) {\n            if (data[1].sz) {\n     \
    \           data[1].sum += lazy[1] * data[1].sz;\n                data[1].mn +=\
    \ lazy[1], data[1].mx += lazy[1];\n            }\n            for (int i = 0;\
    \ i < 5; i++) {\n                if (c[i]) {\n                    c[i]->lazy[1]\
    \ += lazy[1];\n                    if (i >= 2) {\n                        c[i]->lazy[0]\
    \ += lazy[1];\n                    }\n                }\n            }\n     \
    \       lazy[1] = 0;\n        }\n        if (next_num[0] != INT_MAX) {\n     \
    \       val = next_num[0];\n            data[0].sum = next_num[0] * data[0].sz;\n\
    \            data[0].mn = data[0].mx = next_num[0];\n            for (int i =\
    \ 0; i < 2; i++) {\n                if (c[i]) {\n                    c[i]->next_num[0]\
    \ = next_num[0];\n                    c[i]->lazy[0] = 0;\n                }\n\
    \            }\n            next_num[0] = INT_MAX;\n        }\n        if (lazy[0]\
    \ != 0) {\n            val += lazy[0];\n            data[0].sum += lazy[0] * data[0].sz;\n\
    \            data[0].mn += lazy[0], data[0].mx += lazy[0];\n            for (int\
    \ i = 0; i < 2; i++) {\n                if (c[i]) {\n                    c[i]->lazy[0]\
    \ += lazy[0];\n                }\n            }\n            lazy[0] = 0;\n  \
    \      }\n    }\n    void calc() {\n        for (int i = 0; i < 5; i++) {\n  \
    \          if (c[i]) {\n                c[i]->prop();\n            }\n       \
    \ }\n        data[0] = info(val); data[1] = info(INT_MAX);\n        for (int i\
    \ = 0; i < 5; i++) {\n            if (c[i]) {\n                data[1] += c[i]->data[1];\n\
    \                if (i >= 2) {\n                    data[1] += c[i]->data[0];\n\
    \                }\n                else data[0] += c[i]->data[0];\n         \
    \   }\n        }\n    }\n    int dir() {\n        if (!p) return -2;\n       \
    \ for (int i = 0; i < 5; i++) {\n            if (p->c[i] == this) {\n        \
    \        return i;\n            }\n        }\n        assert(false);\n    }\n\
    \    bool is_root() {\n        int d = dir();\n        return d == -2 || d ==\
    \ 4;\n    }\n\n    friend void set_link(sn x, sn y, int d) {\n        if (y) y->p\
    \ = x;\n        if (d >= 0) x->c[d] = y;\n    }\n    void rot() {\n        assert(!is_root());\n\
    \        int x = dir(); sn pa = p;\n        set_link(pa->p, this, pa->dir());\n\
    \        set_link(pa, c[x ^ 1], x);\n        set_link(this, pa, x ^ 1);\n    \
    \    pa->calc(); calc();\n    }\n    bool ok_zero() {\n        int d = dir();\n\
    \        return d == 0 || d == 1;\n    }\n    void splay() {\n        while (ok_zero()\
    \ && p->ok_zero() && p->p->ok_zero()) {\n            p->p->prop(), p->prop(),\
    \ prop();\n            dir() == p->dir() ? p->rot() : rot();\n            rot();\n\
    \        }\n        if (ok_zero() && p->ok_zero()) p->prop(), prop(), rot();\n\
    \        if (ok_zero()) {\n            p->prop(), prop();\n            auto a\
    \ = p->p, b = p->c[2], c = p->c[3]; int d = p->dir();\n            p->p = p->c[2]\
    \ = p->c[3] = NULL; p->calc(); rot();\n            set_link(this, b, 2); set_link(this,\
    \ c, 3); set_link(a, this, d); calc();\n        }\n        while (!is_root() &&\
    \ !p->is_root()) {\n            p->p->prop(), p->prop(), prop();\n           \
    \ dir() == p->dir() ? p->rot() : rot();\n            rot();\n        }\n     \
    \   if (!is_root()) p->prop(), prop(), rot();\n        prop();\n    }\n\n    sn\
    \ splay_right() {\n        prop();\n        if (!c[3]) { splay(); return this;\
    \ }\n        return c[3]->splay_right();\n    }\n\n    friend sn join(sn a, sn\
    \ b) {\n        if (!a) return b;\n        a->splay(); a = a->splay_right();\n\
    \        set_link(a, b, 3); a->calc();\n        return a;\n    }\n    ////////\
    \ link cut tree operations\n    void access() { // bring this to top of tree,\
    \ left subtree of this is now path to root\n        int it = 0;\n        for (sn\
    \ v = this, pre = NULL; v; v = v->p) {\n            it ++;\n            v->splay();\
    \ auto c = v->c[1];\n            if (c) assert(!c->c[2] && !c->c[3]);\n      \
    \      if (pre) pre->prop();\n            if (pre) {\n                assert(v->c[4]\
    \ == pre);\n                auto a = pre->c[2], b = pre->c[3];\n             \
    \   if (a) a->p = NULL;\n                if (b) b->p = NULL;\n               \
    \ pre->c[2] = pre->c[3] = NULL; pre->calc();\n                if (c) c->p = NULL;\n\
    \                set_link(v, join(join(a, b), c), 4);\n            } else {\n\
    \                if (c) c->p = NULL;\n                if (v->c[4]) v->c[4]->p\
    \ = NULL;\n                set_link(v, join(c, v->c[4]), 4);\n            }\n\
    \            v->c[1] = pre; v->calc(); pre = v;\n        }\n        splay(); assert(!c[1]);\n\
    \    }\n    void make_root() {\n        access();\n        flip ^= 1;\n    }\n\
    \    //////// link cut tree queries\n    friend sn lca(sn x, sn y) {\n       \
    \ if (x == y) return x;\n        x->access(); y->access();\n        if (!x->p)\
    \ return NULL;\n        x->splay(); return x->p ? x->p : x;\n    }\n    friend\
    \ bool connected(sn x, sn y) {\n        return lca(x,y);\n    }\n    friend sn\
    \ get_par(sn x) {\n        x->access(); x = x->c[0];\n        while (true) {\n\
    \            x->prop();\n            if (!x->c[1]) return x;\n            x =\
    \ x->c[1];\n        }\n        return x;\n    }\n    //////// link cut tree modifications\n\
    \    friend bool link(sn x, sn y) { // make y parent of x\n        if (connected(x,\
    \ y)) exit(2);\n        x->make_root();\n        set_link(y, join(x, y->c[4]),\
    \ 4);\n        y->calc();\n        return 1;\n    }\n    friend bool cut(sn x,\
    \ sn y) {\n        x->make_root(); y->access();\n        if (y->c[0] != x || x->c[0]\
    \ || x->c[1]) exit(3);\n        x->p = y->c[0] = NULL; y->calc();\n        return\
    \ true;\n    }\n    void prop_all() {\n        prop();\n        for (int i = 0;\
    \ i < 5; i++) {\n            if (c[i]) {\n                c[i]->prop_all();\n\
    \            }\n        }\n    }\n};\nint main() {\n    std::ios_base::sync_with_stdio(0);\
    \ std::cin.tie(0);\n    int n, m, root;\n    std::cin >> n >> m;\n    std::vector<sn>\
    \ lct(n);\n    std::vector<std::pair<int, int>> ed(n - 1);\n    for (int i = 0;\
    \ i < n - 1; i++) {\n        std::cin >> ed[i].first >> ed[i].second;\n    }\n\
    \    for (int i = 1; i <= n; i++) {\n        int x; std::cin >> x;\n        lct[i]\
    \ = new snode(i, x);\n    }\n    for (int i = 0; i < n - 1; i++) {\n        int\
    \ x = ed[i].first, y = ed[i].second;\n        link(lct[x], lct[y]);\n    }\n \
    \   std::cin >> root;\n    while (m--) {\n        int k; std::cin >> k;\n    \
    \    if (k == 0 || k == 5) {\n            int x, y; std::cin >> x >> y;\n    \
    \        lct[root]->make_root();\n            lct[x]->access();\n            auto\
    \ c = lct[x]->c[4];\n            if (k == 0) { // set weights in subtree of x\
    \ to y\n                if (c) c->prop(), c->next_num[0] = c->next_num[1] = y;\n\
    \                lct[x]->val = y;\n\n            } else { // add y to subtree\
    \ of x vertices\n                if (c) c->prop(), c->lazy[0] = c->lazy[1] = y;\n\
    \                lct[x]->val += y;\n            }\n            lct[x]->calc();\n\
    \        } else if (k == 1) { // change root\n            int x; std::cin >> x;\n\
    \            root = x;\n        } else if (k == 2 || k == 6) {\n            int\
    \ x, y, z; std::cin >> x >> y >> z;\n            lct[x]->make_root();\n      \
    \      if (k == 2) { // sets path x to y to weight z\n                lct[y]->access();\n\
    \                lct[y]->next_num[0] = z;\n            }\n            else { //\
    \ add z to vertices on path from x to y\n                lct[y]->access();\n \
    \               lct[y]->lazy[0] = z;\n            }\n        } else if (k == 3\
    \ || k == 4 || k == 11) {\n            int x; std::cin >> x;\n            lct[root]->make_root();\n\
    \            lct[x]->access();\n            auto ans = info(lct[x]->val);\n  \
    \          sn c = lct[x]->c[4];\n            if (c) c->prop(), ans += c->data[0],\
    \ ans += c->data[1];\n            if (k == 3) std::cout << ans.mn << '\\n'; //\
    \ x subtree min\n            else if (k == 4) std::cout << ans.mx << '\\n'; //\
    \ x subtree max\n            else if (k == 11) std::cout << ans.sum << '\\n';\
    \ // x subtree sum\n        } else if (k == 7 || k == 8 || k == 10) {\n      \
    \      int x, y;\n            std::cin >> x >> y;\n            lct[x]->make_root();\n\
    \            lct[y]->access();\n            auto ans = lct[y]->data[0];\n    \
    \        if (k == 7) std::cout << ans.mn << '\\n'; // x, y path min\n        \
    \    else if (k == 8) std::cout << ans.mx << '\\n'; // x, y path max\n       \
    \     else std::cout << ans.sum << '\\n'; // x, y path sum\n        } else if\
    \ (k == 9) { // change parent of x to y\n            int x, y;\n            std::cin\
    \ >> x >> y;\n            lct[root]->make_root();\n            if (lca(lct[x],\
    \ lct[y]) == lct[x]) {\n                continue;\n            }\n           \
    \ cut(get_par(lct[x]), lct[x]);\n            link(lct[x], lct[y]);\n        }\
    \ else exit(5);\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dmoj_dynamic_tree_test.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dmoj_dynamic_tree_test.cpp
layout: document
redirect_from:
- /library/library/graphs/dmoj_dynamic_tree_test.cpp
- /library/library/graphs/dmoj_dynamic_tree_test.cpp.html
title: library/graphs/dmoj_dynamic_tree_test.cpp
---
