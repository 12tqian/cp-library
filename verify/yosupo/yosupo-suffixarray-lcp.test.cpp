#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/string/suffix-array-lcp.hpp"

int main() {
	using namespace std;
	ios_base::sync_with_stdio(0);
	string s; cin >> s;
	int n = (int)s.size();
	SuffixArray S;
	S.generate_suffix_array(s);
	for (int i = 0; i < n; i++)
		cout << S.sa[i] << " ";
	cout << '\n';
	return 0;
}
