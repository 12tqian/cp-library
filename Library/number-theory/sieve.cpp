#include<bits/stdc++.h>
template <int SZ> struct Sieve {
    std::bitset<SZ> pri;
    std::vector<int> pr;
    Sieve() {
        pri.set();
        pri[0] = pri[1] = 0;
        for (int i = 4; i < SZ; i += 2) {
            pri[i] = 0;
        }
        for (int i = 3; i * i < SZ; i += 2) {
            if (pri[i]) {
                for (int j = i * i; j < SZ; j += 2 * i) {
                    pri[j] = 0;
                }
            }
        }
        for (int i = 0; i < SZ; i++) {
            if (pri[i]) {
                pr.push_back(i);
            }
        }
    }
};
int main() {
    return 0;
}
