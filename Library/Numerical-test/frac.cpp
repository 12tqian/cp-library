#include<bits/stdc++.h>
struct Frac {
    long long n, d;
    Frac(long long _n, long long _d) {
        n = _n, d = _d;
        long long g = std::__gcd(n, d); n /= g, d /= g;
        if (d < 0) n *= -1, d *= -1;
    }
    Frac(long long _n) : Frac(_n, 1) {}
    Frac() : Frac(0) {}
    friend Frac abs(Frac F) { return Frac(abs(F.n), F.d); }
    friend bool operator < (const Frac& l, const Frac& r) { return l.n * r.d < r.n * l.d; }
    friend bool operator <= (const Frac& l, const Frac& r) { return l.n * r.d <= r.n * l.d; }
    friend bool operator > (const Frac& l, const Frac& r) { return l.n * r.d > r.n * l.d; }
    friend bool operator >= (const Frac& l, const Frac& r) { return l.n * r.d >= r.n * l.d; }
    friend bool operator == (const Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d; }
    friend bool operator != (const Frac& l, const Frac& r) { return !(l == r); }
    Frac operator - () const { return Frac(-n, d); }
    friend Frac operator + (const Frac& l, const Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }
    friend Frac operator - (const Frac& l, const Frac& r) { return Frac(l.n * r.d - r.n * l.d, l.d * r.d); }
    friend Frac operator * (const Frac& l, const Frac& r) { return Frac(l.n * r.n, l.d * r.d); }
    friend Frac operator * (const Frac& l, int r) { return l * Frac(r, 1); }
    friend Frac operator * (int r, const Frac& l) { return l * r; }
    friend Frac operator / (const Frac& l, const Frac& r) { return l * Frac(r.d, r.n); }
    friend Frac operator / (const Frac& l, const int& r) { return l / Frac(r, 1); }
    friend Frac operator / (const int& l, const Frac& r) { return Frac(l, 1) / r; }
    friend Frac& operator += (Frac& l, const Frac& r) { return l = l + r; }
    friend Frac& operator -= (Frac& l, const Frac& r) { return l = l - r; }
    template <class T> friend Frac& operator *= (Frac& l, const T& r) { return l = l * r; }
    template <class T> friend Frac& operator /= (Frac& l, const T& r) { return l = l / r; }
    friend std::ostream& operator << (std::ostream& os, const Frac& a) { return os << a.n << "/" << a.d; }
};
int main() {
    return 0;
}
