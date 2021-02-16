#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

/**
 * Benq's code made without macros and nicer
 * Does everything a link cut tree could possibly want to
 */

#include <bits/stdc++.h>

struct info {
    int sz, sum, mn, mx;

    info (int v) {
        if (v == INT_MAX) {
            sz = sum = 0;
            mn = INT_MAX, mx = INT_MIN;
        } else {
            sz = 1; sum = mn = mx = v;
        }
    }

    info() : info(INT_MAX) {}

    friend info& operator += (info& a, const info& b) {
        a.sz += b.sz, a.sum += b.sum;
        a.mn = std::min(a.mn, b.mn);
        a.mx = std::max(a.mx, b.mx);
        return a;
    }
};

typedef struct snode* sn;

struct snode {
    int id, val; // value in node
    sn p; // parent
    sn c[5]; // children
    bool flip = 0;
    info data[2];
    int next_num[2], lazy[2];

    snode(int _id, int v) {
        id = _id; val = v;
        p = NULL;
        for (int i = 0; i < 5; i++) {
            c[i] = NULL;
        }
        next_num[0] = next_num[1] = INT_MAX;
        lazy[0] = lazy[1] = 0;
        calc();
    }

    //////// splay tree operations
    void prop() {
        if (flip) {
            std::swap(c[0], c[1]);
            for (int i = 0; i < 2; i++) {
                if (c[i]) {
                    c[i]->flip ^= 1;
                }
            }
            flip = 0;
        }
        if (next_num[1] != INT_MAX) {
            if (data[1].sz) {
                data[1].sum = next_num[1] * data[1].sz;
                data[1].mn = data[1].mx = next_num[1];
            }
            for (int i = 0; i < 5; i++) {
                if (c[i]) {
                    c[i]->next_num[1] = next_num[1], c[i]->lazy[1] = 0;
                    if (i >= 2) {
                        c[i]->next_num[0] = next_num[1];
                        c[i]->lazy[0] = 0;
                    }
                }
            }
            next_num[1] = INT_MAX;
        }
        if (lazy[1] != 0) {
            if (data[1].sz) {
                data[1].sum += lazy[1] * data[1].sz;
                data[1].mn += lazy[1], data[1].mx += lazy[1];
            }
            for (int i = 0; i < 5; i++) {
                if (c[i]) {
                    c[i]->lazy[1] += lazy[1];
                    if (i >= 2) {
                        c[i]->lazy[0] += lazy[1];
                    }
                }
            }
            lazy[1] = 0;
        }
        if (next_num[0] != INT_MAX) {
            val = next_num[0];
            data[0].sum = next_num[0] * data[0].sz;
            data[0].mn = data[0].mx = next_num[0];
            for (int i = 0; i < 2; i++) {
                if (c[i]) {
                    c[i]->next_num[0] = next_num[0];
                    c[i]->lazy[0] = 0;
                }
            }
            next_num[0] = INT_MAX;
        }
        if (lazy[0] != 0) {
            val += lazy[0];
            data[0].sum += lazy[0] * data[0].sz;
            data[0].mn += lazy[0], data[0].mx += lazy[0];
            for (int i = 0; i < 2; i++) {
                if (c[i]) {
                    c[i]->lazy[0] += lazy[0];
                }
            }
            lazy[0] = 0;
        }
    }

    void calc() {
        for (int i = 0; i < 5; i++) {
            if (c[i]) {
                c[i]->prop();
            }
        }
        data[0] = info(val); data[1] = info(INT_MAX);
        for (int i = 0; i < 5; i++) {
            if (c[i]) {
                data[1] += c[i]->data[1];
                if (i >= 2) {
                    data[1] += c[i]->data[0];
                }
                else data[0] += c[i]->data[0];
            }
        }
    }

    int dir() {
        if (!p) return -2;
        for (int i = 0; i < 5; i++) {
            if (p->c[i] == this) {
                return i;
            }
        }
        assert(false);
    }

    bool is_root() {
        int d = dir();
        return d == -2 || d == 4;
    }

    friend void set_link(sn x, sn y, int d) {
        if (y) y->p = x;
        if (d >= 0) x->c[d] = y;
    }

    void rot() {
        assert(!is_root());
        int x = dir(); sn pa = p;
        set_link(pa->p, this, pa->dir());
        set_link(pa, c[x ^ 1], x);
        set_link(this, pa, x ^ 1);
        pa->calc(); calc();
    }

    bool ok_zero() {
        int d = dir();
        return d == 0 || d == 1;
    }

    void splay() {
        while (ok_zero() && p->ok_zero() && p->p->ok_zero()) {
            p->p->prop(), p->prop(), prop();
            dir() == p->dir() ? p->rot() : rot();
            rot();
        }
        if (ok_zero() && p->ok_zero()) p->prop(), prop(), rot();
        if (ok_zero()) {
            p->prop(), prop();
            auto a = p->p, b = p->c[2], c = p->c[3]; int d = p->dir();
            p->p = p->c[2] = p->c[3] = NULL; p->calc(); rot();
            set_link(this, b, 2); set_link(this, c, 3); set_link(a, this, d); calc();
        }
        while (!is_root() && !p->is_root()) {
            p->p->prop(), p->prop(), prop();
            dir() == p->dir() ? p->rot() : rot();
            rot();
        }
        if (!is_root()) p->prop(), prop(), rot();
        prop();
    }

    sn splay_right() {
        prop();
        if (!c[3]) { splay(); return this; }
        return c[3]->splay_right();
    }

    friend sn join(sn a, sn b) {
        if (!a) return b;
        a->splay(); a = a->splay_right();
        set_link(a, b, 3); a->calc();
        return a;
    }

    //////// link cut tree operations
    void access() { // bring this to top of tree, left subtree of this is now path to root
        int it = 0;
        for (sn v = this, pre = NULL; v; v = v->p) {
            it ++;
            v->splay(); auto c = v->c[1];
            if (c) assert(!c->c[2] && !c->c[3]);
            if (pre) pre->prop();
            if (pre) {
                assert(v->c[4] == pre);
                auto a = pre->c[2], b = pre->c[3];
                if (a) a->p = NULL;
                if (b) b->p = NULL;
                pre->c[2] = pre->c[3] = NULL; pre->calc();
                if (c) c->p = NULL;
                set_link(v, join(join(a, b), c), 4);
            } else {
                if (c) c->p = NULL;
                if (v->c[4]) v->c[4]->p = NULL;
                set_link(v, join(c, v->c[4]), 4);
            }
            v->c[1] = pre; v->calc(); pre = v;
        }
        splay(); assert(!c[1]);
    }

    void make_root() {
        access();
        flip ^= 1;
    }

    //////// link cut tree queries
    friend sn lca(sn x, sn y) {
        if (x == y) return x;
        x->access(); y->access();
        if (!x->p) return NULL;
        x->splay(); return x->p ? x->p : x;
    }

    friend bool connected(sn x, sn y) {
        return lca(x, y);
    }

    friend sn get_par(sn x) {
        x->access(); x = x->c[0];
        while (true) {
            x->prop();
            if (!x->c[1]) return x;
            x = x->c[1];
        }
        return x;
    }

    //////// link cut tree modifications
    friend bool link(sn x, sn y) { // make y parent of x
        if (connected(x, y)) exit(2);
        x->make_root();
        set_link(y, join(x, y->c[4]), 4);
        y->calc();
        return 1;
    }

    friend bool cut(sn x, sn y) {
        x->make_root(); y->access();
        if (y->c[0] != x || x->c[0] || x->c[1]) exit(3);
        x->p = y->c[0] = NULL; y->calc();
        return true;
    }

    void prop_all() {
        prop();
        for (int i = 0; i < 5; i++) {
            if (c[i]) {
                c[i]->prop_all();
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int n, m, root;
    std::cin >> n >> m;
    std::vector<sn> lct(n);
    std::vector<std::pair<int, int>> ed(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> ed[i].first >> ed[i].second;
    }
    for (int i = 1; i <= n; i++) {
        int x; std::cin >> x;
        lct[i] = new snode(i, x);
    }
    for (int i = 0; i < n - 1; i++) {
        int x = ed[i].first, y = ed[i].second;
        link(lct[x], lct[y]);
    }
    std::cin >> root;
    while (m--) {
        int k; std::cin >> k;
        if (k == 0 || k == 5) {
            int x, y; std::cin >> x >> y;
            lct[root]->make_root();
            lct[x]->access();
            auto c = lct[x]->c[4];
            if (k == 0) { // set weights in subtree of x to y
                if (c) c->prop(), c->next_num[0] = c->next_num[1] = y;
                lct[x]->val = y;

            } else { // add y to subtree of x vertices
                if (c) c->prop(), c->lazy[0] = c->lazy[1] = y;
                lct[x]->val += y;
            }
            lct[x]->calc();
        } else if (k == 1) { // change root
            int x; std::cin >> x;
            root = x;
        } else if (k == 2 || k == 6) {
            int x, y, z; std::cin >> x >> y >> z;
            lct[x]->make_root();
            if (k == 2) { // sets path x to y to weight z
                lct[y]->access();
                lct[y]->next_num[0] = z;
            }
            else { // add z to vertices on path from x to y
                lct[y]->access();
                lct[y]->lazy[0] = z;
            }
        } else if (k == 3 || k == 4 || k == 11) {
            int x; std::cin >> x;
            lct[root]->make_root();
            lct[x]->access();
            auto ans = info(lct[x]->val);
            sn c = lct[x]->c[4];
            if (c) c->prop(), ans += c->data[0], ans += c->data[1];
            if (k == 3) std::cout << ans.mn << '\n'; // x subtree min
            else if (k == 4) std::cout << ans.mx << '\n'; // x subtree max
            else if (k == 11) std::cout << ans.sum << '\n'; // x subtree sum
        } else if (k == 7 || k == 8 || k == 10) {
            int x, y;
            std::cin >> x >> y;
            lct[x]->make_root();
            lct[y]->access();
            auto ans = lct[y]->data[0];
            if (k == 7) std::cout << ans.mn << '\n'; // x, y path min
            else if (k == 8) std::cout << ans.mx << '\n'; // x, y path max
            else std::cout << ans.sum << '\n'; // x, y path sum
        } else if (k == 9) { // change parent of x to y
            int x, y;
            std::cin >> x >> y;
            lct[root]->make_root();
            if (lca(lct[x], lct[y]) == lct[x]) {
                continue;
            }
            cut(get_par(lct[x]), lct[x]);
            link(lct[x], lct[y]);
        } else exit(5);
    }
    return 0;
}
