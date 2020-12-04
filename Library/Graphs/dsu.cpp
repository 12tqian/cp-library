#include<bits/stdc++.h>

struct DSU {
    std::vector<int> e;
    void init(int n) {
        e = std::vector<int>(n, -1);
    }
    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    bool same_set(int a, int b) {
        return get(a) == get(b);
    }
    int size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) std::swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};
int main() {
    return 0;
}
