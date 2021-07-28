#define PROBLEM "https://www.spoj.com/problems/FACT0/"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/number-theory/basic-factor.hpp"

// verified probably using SPOJ?
int main() {
	using namespace FactorBasic;
	using namespace std;
	while (true) {
		long long n;
		cin >> n;
		if (n == 0) return 0;
		auto f = factor(n);
		for (auto x : f) {
			cout << x.first << "^" << x.second << " ";
		}
		cout << '\n';
	}  
	return 0;
}