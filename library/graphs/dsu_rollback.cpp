/**
* Untested still
*/

#include <bits/stdc++.h>

struct DSURollback {
    std::vector<int> e;
    void init(int n) { e = std::vector<int>(n, -1); }
    int get(int x) { return e[x] < 0 ? x : get(e[x]); }
    bool same_set(int a, int b) {return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    std::vector<std::array<int, 4>> modify;
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) {
            modify.push_back({-1, -1, -1, -1});
            return false;
        }
        if (e[x] > e[y]) std::swap(x, y);
        modify.push_back({x, y, e[x], e[y]});
        e[x] == e[y], e[y] = x;
        return true;
    }
    void rollback() {
        auto a = modify.back();
        modify.pop_back();
        if (a[0] != -1) 
            e[a[0]] = a[2], e[a[1]] = a[3];
    }
};

