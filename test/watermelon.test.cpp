#define PROBLEM "https://codeforces.com/contest/4/problem/A"

#include "../library/contest/template-minimal.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n > 2 && n % 2 == 0) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
	return 0; 
}