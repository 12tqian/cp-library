#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"

#include <bits/stdc++.h>
#include "../../library/graphs/flows/min-cost-b-flow.hpp"

template <class T> std::string i2s(T value) {
    if (value < 0) return "-" + i2s(-value);
    if (value == 0) return "0";
    std::string s;
    while (value) {
        s += '0' + (value % 10);
        value /= 10;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

int main() {
	using MCF = MinCostFlow<long long, long long>;
	using namespace std;
	int n, m;
	cin >> n >> m;
	MCF mcf;
	const auto vs = mcf.add_vertices(n);
	for (const auto& v : vs) {
		int x;
		cin >> x;
		mcf.add_supply(vs[v], x);
	}
	vector<MCF::EdgePtr> edges;
	while (m--) {
		int s, t, l, u, c;
		cin >> s >> t >> l >> u >> c;
		edges.emplace_back(mcf.add_edge(s, t, l, u, c));
	}
	const auto status = mcf.solve().first;
	if (status == Status::INFEASIBLE) {
		puts("infeasible");
	} else {
		const auto potential = mcf.get_potential();
		const auto result_value = mcf.get_result_value<__int128_t>();
		puts(i2s(result_value).c_str());
		for (const auto& v : vs) {
			puts(i2s(potential[v]).c_str());
		}
		for (const auto& e : edges) {
			puts(i2s(e.flow()).c_str());
		}
	}
}
