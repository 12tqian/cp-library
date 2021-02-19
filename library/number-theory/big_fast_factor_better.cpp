#include<bits/stdc++.h>

namespace FactorBig {

long long gcd(long long _a, long long _b) {
    unsigned long long a = abs(_a), b = abs(_b);
    if (a == 0) return b;
    if (b == 0) return a;
    auto bsf = [](unsigned long long x) -> int {
        return __builtin_ctzll(x);
    };
    int shift = bsf(a | b);
    a >>= bsf(a);
    do {
        b >>= bsf(b);
        if (a > b) 
            std::swap(a, b);
        b -= a;
    } while (b);
    return (a << shift);
}

template <class T, class U> T pow_mod(T x, U n, T md) {
    T r = 1 % md;
    x %= md;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n <= a) break;
        long long t = d;
        long long y = pow_mod<__int128_t>(a, t, n);  // over
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = __int128_t(y) * y % n;  // flow
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}

long long pollard_single(long long n) {
    auto f = [&](long long x) { return (__int128_t(x) * x + 1) % n; };
    if (is_prime(n)) return n;
    if (n % 2 == 0) return 2;
    long long st = 0;
    while (true) {
        st++;
        long long x = st, y = f(x);
        while (true) {
            long long p = gcd((y - x + n), n);
            if (p == 0 || p == n) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }
}

std::vector<long long> pollard(long long n) {
    if (n == 1) return {};
    long long x = pollard_single(n);
    if (x == n) return {x};
    std::vector<long long> le = pollard(x);
    std::vector<long long> ri = pollard(n / x);
    le.insert(le.end(), ri.begin(), ri.end());
    return le;
}

}

int main() {
    using namespace std;
    using namespace FactorBig;
    int q;
    scanf("%d", &q);
    map<long long, vector<long long>> cache;
    for (int i = 0; i < q; i++) {
        long long a;
        scanf("%lld", &a);
        if (!cache.count(a)) {
            auto v = pollard(a);
            sort(v.begin(), v.end());
            cache[a] = v;
        }
        auto v = cache[a];
        printf("%d", (int)v.size());
        for (auto d: v) printf(" %lld", d);
        printf("\n");
    }
    return 0;
}