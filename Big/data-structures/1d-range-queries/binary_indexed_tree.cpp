#include<bits/stdc++.h>

template <class T> struct BIT {
    std::vector<T> bit;
    int n;
    void init(int n_) {
        n = n_;
        bit.resize(n);
    }
    void init(std::vector<int> a) {
        n = (int) a.size();
        for (int i = 0; i < (int) a.size(); i++) {
            add(i, a[i]);
        }
    }
    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }
    T query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    }
};

int main() {
    return 0;
}