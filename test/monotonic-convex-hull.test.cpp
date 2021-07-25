#define IGNORE

#include "../library/contest/template-minimal.hpp"
#include "../library/dynamic-programming/monotonic-convex-hull.hpp"

// 189 div 1C
int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n; std::cin >> n;
	std::vector<long long> a(n), b(n);
	for (int i = 0; i < n; i++) std::cin >> a[i];
	for (int i = 0; i < n; i++) std::cin >> b[i];
	std::vector<long long> pre(n);
	for (int i = 0; i < n; i++) {
		pre[i] = a[i] + (i ? pre[i - 1] : 0);
	}
	ConvexHullDeque C;
	std::vector<long long> dp(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dp[i] = 0;
			C.add(b[i], dp[i]);
		} else {
			dp[i] = C.query(a[i]);
			C.add(b[i], dp[i]);
		}
	}
	std::cout << dp[n - 1] << '\n';
	return 0;
}
