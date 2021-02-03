#include<bits/stdc++.h>

const long long INF = 1e18;

struct IntervalUnion {
    std::set<std::pair<long long, long long>> le, ri;

    void reset() {
        le.clear();
        ri.clear();
    }

    // inserts an interval while returning the intervals it intersected with
    std::vector<std::pair<long long, long long>> insert(std::pair<long long, long long> x) {
        std::set<std::pair<long long, long long>> bad;
        std::vector<std::pair<long long, long long>> ret;
        std::pair<long long, long long> use1 = std::make_pair(x.first, -INF), use2 = std::make_pair(x.second, INF);
        auto it1 = le.lower_bound(use1);
        auto it2 = ri.lower_bound(use2);
        if (it2 != ri.end()) {
            long long lo = (*it2).second, hi = (*it2).first;
            if (lo <= x.first && x.second <= hi) {
                ret.emplace_back(std::make_pair(lo, hi));
                long long mn = x.first, mx = x.second;
                for (auto b: ret) {
                    le.erase(b); ri.erase(std::make_pair(b.second, b.first));
                    mn = std::min(mn, b.first); mx = std::max(mx, b.second);
                }
                le.insert(std::make_pair(mn, mx)); ri.insert(std::make_pair(mx, mn));
                return ret;
            }
        }
        if (it1 != le.end()) {
            while (it1 != le.end()) {
                auto val = (*it1);
                if (val.first <= x.second) bad.insert(val);
                else break;
                it1 = next(it1);
            }
        }
        if (it2 != ri.begin()) {
            it2 = prev(it2);
            while (true) {
                auto val = (*it2);
                if (val.first >= x.first) bad.insert(std::make_pair(val.second, val.first));
                else break;
                if (it2 == ri.begin()) break;
                it2 = prev(it2);
            }
        }
        for (auto b: bad) ret.emplace_back(b);
        long long mn = x.first, mx = x.second;
        for (auto b: ret) {
            le.erase(b); ri.erase(std::make_pair(b.second, b.first));
            mn = std::min(mn, b.first); mx = std::max(mx, b.second);
        }
        le.insert(std::make_pair(mn, mx)); ri.insert(std::make_pair(mx, mn));
        return ret;
    }
};

int main() {
    return 0;
}
