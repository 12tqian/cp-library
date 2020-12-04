#include<bits/stdc++.h>
const int MOD = 1e9 + 7;
struct MaxDeque {
    std::deque<std::pair<int, int>> mx;
    std::deque<int> tmp;

    int l = 0,r = -1;

    int del() {
        if (mx.front().second == l++) mx.pop_front();
        int t = tmp.front();
        tmp.pop_front();
        return t;
    }
    int query() {
        if (mx.size() == 0) return -MOD;
        return mx.front().first;
    }
    void ad(int x) {
        while ((mx).size() && mx.back().first <= x) mx.pop_back();
        mx.push_back({x, ++r});
        tmp.push_back(x);
    }
};
int main(){
    return 0;
}
