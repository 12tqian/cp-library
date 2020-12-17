#include <bits/stdc++.H>
/**
* x is in (0, SZ), y != 0, not the not 0 part
* untested
*/
template<class T> struct Offline2DBIT { 
    bool mode = 0; // mode = 1 -> initialized
    int sz;
    std::vector<std::pair<int, int>> todo;
    std::vector<int> cnt, st, val;
    std::vector<T> bit;
    void init(int sz_) {
        sz = sz_;
        cnt.assign(sz, 0);
        st.assign(sz, 0);
    }
    void build() { 
        assert(!mode); mode = 1;
        std::vector<int> lst(sz, 0);
        cnt.assign(sz, 0);
        sort(todo.begin(), todo.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) { 
            return a.second < b.second; });
        for (auto& t : todo) 
            for (int x = t.first; x < sz; x += x & -x)
                if (lst[x] != t.second)
                    lst[x] = t.second, cnt[x]++;
        int sum = 0; 
        for (int i = 0; i < sz; i++)
            lst[i] = 0, st[i] = (sum += cnt[i]);
        val.resize(sum); bit.resize(sum);
        reverse(todo.begin(), todo.end());
        for (auto& t : todo) 
            for (int x = t.first; x < sz; x += x & -x)
                if (lst[x] != t.second)
                    lst[x] = t.second, val[--st[x]] = t.second;
    }
    int rank(int y, int l, int r) {
        return std::upper_bound(val.begin() + l, val.begin() + r, y) - val.begin() - l;
    }
    void update(int x, int y, T t) {
        for (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x]; y += y & -y)
            bit[st[x] + y - 1] += t;
    }
    void upd(int x, int y, T t) {
        if (!mode) todo.push_back({x, y});
        else 
            for (; x < sz; x += x & -x)
                update(x, y, t);
    }
    int ask(int x, int y) {
        T res = 0;
        for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y)
            res += bit[st[x] + y - 1];
        return res;
    }
    T query(int x, int y) {
        assert(mode);
        T res = 0;
        for (; x; x -= x & -x) 
            res += ask(x, y);
        return res;
    }
    T query(int xl, int xr, int yl, int yr) {
        return query(xr, yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);
    }
};

int main() {
    return 0;
}