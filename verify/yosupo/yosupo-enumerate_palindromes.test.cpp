#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/string/manacher.hpp"

int main() {
	std::ios_base::sync_with_stdio(0);
	std::string s; std::cin >> s;
	std::vector<int> ans = manacher(s);
	for (int &x : ans)
		std::cout << x << " ";
	std::cout << '\n';
	return 0;
}   