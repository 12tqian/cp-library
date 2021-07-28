#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/string/suffix-array-linear.hpp"

int main() {
	using namespace std;
	ios_base::sync_with_stdio(0);
	string s; cin >> s;
	std::vector<int> a((int)s.size());
	for (int i = 0; i < (int)s.size(); i++)
		a[i] = s[i] - 'a';
	std::vector<int> res = suffix_array(a, 26);
	for (int i = 0; i < (int)s.size(); i++)
		cout << res[i] << " ";
	cout << '\n';
	return 0;
}