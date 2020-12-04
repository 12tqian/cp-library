#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
struct MinDeque {
    int lo = 0, hi = -1;
    std::deque<std::pair<int, int>> d;
    void ins(int x) { // add to back
        while ((d).size() && d.back().first >= x) d.pop_back();
        d.push_back({x, ++hi});
    }
    void del() { // delete from front
        if (d.front().second == lo++) d.pop_front();
    }
    int get() {
        return (d).size() ? d.front().first : MOD;
    }
};
int main(){
    return 0;
}
