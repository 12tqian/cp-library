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

namespace FactorFast {

std::mt19937 random_number((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());
Sieve<(1 << 20)> S;

unsigned long long mod_mul(unsigned long long a, unsigned long long b, unsigned long long mod) {
    long long ret = a * b - mod * (unsigned long long) ((long double) a * b / mod);
    return ret + ((ret < 0) - (ret >= (long long) mod)) * mod;
}

unsigned long long mod_pow(unsigned long long a, unsigned long long b, unsigned long long mod) {
    if (b == 0) {
        return 1;
    }
    unsigned long long res = mod_pow(a, b / 2, mod);
    res = mod_mul(res, res, mod);
    if (b & 1) {
        return mod_mul(res, a, mod);
    }
    return res;
}

bool miller_rabin(long long p) {
    if (p == 2) {
        return true;
    } else if (p == 1 || p % 2 == 0) {
        return false;
    }
    long long s = p - 1;
    while (s % 2 == 0) {
        s /= 2;
    }
    for (int i = 0; i < 30; i++) {
        long long a = random_number() % (p - 1) + 1;
        long long tmp = s;
        long long mod = mod_pow(a, tmp, p);
        while (tmp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mod_mul(mod, mod, p);
            tmp *= 2;
        }
        if (mod != p - 1 && tmp % 2 == 0) {
            return false;
        }
    }
    return true;
}

long long f(long long a, long long n, long long& has) {
    return (mod_mul(a, a, n) + has) % n;
}

std::vector<std::pair<long long, long long>> pollards_rho(long long d) {
    std::vector<std::pair<long long, long long>> res;
    auto& pr = S.pr;
    for (int i = 0; i < (int)pr.size() && pr[i] * pr[i] <= d; i++) {
        if (d % pr[i] == 0) {
            int co = 0;
            while (d % pr[i] == 0) {
                d /= pr[i];
                co++;
            }
            res.emplace_back(pr[i], co);
        }
    }
    if (d > 1) {
        if (miller_rabin(d)) {
            res.emplace_back(d, 1);
        } else {
            while (true) {
                long long has = random_number() % 2321 + 47;
                long long x = 2, y = 2, c = 1;
                for (; c == 1; c = std::__gcd(abs(x - y), d)) {
                    x = f(x, d, has);
                    y = f(f(y, d, has), d, has);
                }
                if (c != d) {
                    d /= c;
                    if (d > c) {
                        std::swap(d, c);
                    }
                    if (c == d) {
                        res.emplace_back(c, 2);
                    } else {
                        res.emplace_back(c, 1);
                        res.emplace_back(d, 1);
                    }
                    break;
                }
            }
        }
    }
    return res;
}

}


int main() {
    using namespace FactorFast;
    using namespace std;
    int q; cin >> q;
    while (q--) {
        long long a; cin >> a;
        auto f = pollards_rho(a);
        int tot = 0;
        for (auto x : f) {
            tot += x.second;
        }
        cout << tot << " ";
        for (auto x : f) {
            for (int i = 0; i < x.second; i++) 
                cout << x.first << " ";
        }
        cout << '\n';
    }
    return 0;
}
