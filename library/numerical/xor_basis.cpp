#include <bits/stdc++.h>

template <class T> T reduce(std::vector<T>& b, T x) {
    for (auto& t : b) {
        x = std::min(x, x ^ t);
    }
    return x;
}

template <class T> bool add(std::vector<T>& b, T x) {
    if (!(x = reduce(b, x))) return false;
    int ind = 0;
    while (ind < int(b.size()) && b[ind] > x) ind++;
    b.insert(b.begin() + ind, x);
    return true;
}

int main() {
    return 0;
}