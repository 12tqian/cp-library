#include <bits/stdc++.h>

/**
 * Example use:
 * Call: manacher("abacaba")
 * Return: {1 0 3 0 1 0 7 0 1 0 3 0 1}
 */

std::vector<int> manacher(std::string s) {
    std::string t = "@";
    for (auto& c : s) 
        t += c, t += '#';
    t.back() = '&';
    std::vector<int> res((int) t.size() - 1);
    int lo = 0, hi = 0;
    for (int i = 1; i < (int) t.size() - 1; i++) {
        if (i != 1)
            res[i] = std::min(hi - i, res[hi - i + lo]);
        while (t[i - res[i] - 1] == t[i + res[i] + 1])
            res[i]++;
        if (i + res[i] > hi)
            lo = i - res[i], hi = i + res[i];
    }
    res.erase(res.begin());
    for (int i = 0; i < (int) res.size(); i++)
        if ((i & 1) == (res[i] & 1))
            res[i]++;
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::string s; std::cin >> s;
    std::vector<int> ans = manacher(s);
    for (int& x : ans)
        std::cout << x << " ";
    std::cout << '\n';
    return 0;
}   