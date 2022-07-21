#define PROBLEM "https://open.kattis.com/problems/generalchineseremainder"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/number-theory/basic-number-theory.hpp"

int main() {
	using namespace BasicNumberTheory;
	int tt; cin >> tt;
	while (tt--) {
		long long a, n, b, m;
		cin >> a >> n >> b >> m;
		auto ans = CRT({a, n}, {b, m});
		if (ans.first == -1) 
			cout << "no solution\n";
		else 
			cout << ans.first << " " << ans.second << '\n';
	}   
	return 0;
}