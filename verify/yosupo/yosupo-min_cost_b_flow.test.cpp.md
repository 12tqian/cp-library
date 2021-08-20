---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/graphs/flows/min-cost-b-flow.hpp
    title: library/graphs/flows/min-cost-b-flow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\
    \n\n#include <bits/stdc++.h>\n\nenum Objective {\n\tMINIMIZE = 1,\n\tMAXIMIZE\
    \ = -1,\n};\n\nenum class Status {\n\tOPTIMAL,\n\tINFEASIBLE,\n};\n\ntemplate\
    \ <class Flow, class Cost, Objective objective = Objective::MINIMIZE>\nclass MinCostFlow\
    \ {\n\tclass Edge {\n\t\tfriend class MinCostFlow;\n\n\t\tint src, dst;\n\t\t\
    Flow flow, cap;\n\t\tCost cost;\n\t\tint rev;\n\n\t\tpublic:\n\t\tEdge() = default;\n\
    \n\t\tEdge(const int _src, const int _dst, const Flow _cap, const Cost _cost,\n\
    \t\t\t const int _rev)\n\t\t\t: src(_src), dst(_dst), flow(0), cap(_cap), cost(_cost),\
    \ rev(_rev) {}\n\n\t\t[[nodiscard]] Flow residual_cap() const { return cap - flow;\
    \ }\n\t};\n\npublic:\n\tclass EdgePtr {\n\t\tfriend class MinCostFlow;\n\n\t\t\
    const MinCostFlow* instance;\n\t\tint v;\n\t\tint e;\n\n\t\tEdgePtr(const MinCostFlow*\
    \ const _instance, const int _v, const int _e)\n\t\t\t: instance(_instance), v(_v),\
    \ e(_e) {}\n\n\t\t[[nodiscard]] const Edge& edge() const { return instance->g[v][e];\
    \ }\n\n\t\t[[nodiscard]] const Edge& rev() const {\n\t\t\tconst Edge& _e = edge();\n\
    \t\t\treturn instance->g[_e.dst][_e.rev];\n\t\t}\n\n\t\tpublic:\n\t\tEdgePtr()\
    \ = default;\n\n\t\t[[nodiscard]] int src() const { return v; }\n\n\t\t[[nodiscard]]\
    \ int dst() const { return edge().dst; }\n\n\t\t[[nodiscard]] Flow flow() const\
    \ { return edge().flow; }\n\n\t\t[[nodiscard]] Flow lower() const { return -rev().cap;\
    \ }\n\n\t\t[[nodiscard]] Flow upper() const { return edge().cap; }\n\n\t\t[[nodiscard]]\
    \ Cost cost() const { return edge().cost; }\n\n\t\t[[nodiscard]] Cost gain() const\
    \ { return -edge().cost; }\n\t};\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<Edge>>\
    \ g;\n\tstd::vector<Flow> b;\n\npublic:\n\tMinCostFlow() : n(0) {}\n\n\tint add_vertex()\
    \ {\n\t\t++n;\n\t\tg.resize(n);\n\t\tb.resize(n);\n\t\treturn n-1;\n\t}\n\n\t\
    std::vector<int> add_vertices(const size_t size) {\n\t\tstd::vector<int> ret(size);\n\
    \t\tstd::iota(std::begin(ret), std::end(ret), n);\n\t\tn += size;\n\t\tg.resize(n);\n\
    \t\tb.resize(n);\n\t\treturn ret;\n\t}\n\n\tEdgePtr add_edge(const int src, const\
    \ int dst, const Flow lower,\n\t\t\t\t\t const Flow upper, const Cost cost) {\n\
    \t\tconst int e = g[src].size(), re = src == dst ? e + 1 : g[dst].size();\n\t\t\
    assert(lower <= upper);\n\t\tg[src].emplace_back(Edge{src, dst, upper, cost *\
    \ objective, re});\n\t\tg[dst].emplace_back(Edge{dst, src, -lower, -cost * objective,\
    \ e});\n\t\treturn EdgePtr{this, src, e};\n\t}\n\n\tvoid add_supply(const int\
    \ v, const Flow amount) { b[v] += amount; }\n\n\tvoid add_demand(const int v,\
    \ const Flow amount) { b[v] -= amount; }\n\nprivate:\n\t// Variables used in calculation\n\
    \tconst Cost unreachable = std::numeric_limits<Cost>::max();\n\tCost farthest;\n\
    \tstd::vector<Cost> potential;\n\tstd::vector<Cost> dist;\n\tstd::vector<Edge*>\
    \ parent; // out-forrest.\n\tstd::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost,\
    \ int>>,\n\t\tstd::greater<>>\n\t\t\tpq; // should be empty outside of dual()\n\
    \tstd::vector<int> excess_vs, deficit_vs;\n\n\tEdge& rev(const Edge& e) { return\
    \ g[e.dst][e.rev]; }\n\n\tvoid push(Edge& e, const Flow amount) {\n\t\te.flow\
    \ += amount;\n\t\tg[e.dst][e.rev].flow -= amount;\n\t}\n\n\tCost residual_cost(const\
    \ int src, const int dst, const Edge& e) {\n\t\treturn e.cost + potential[src]\
    \ - potential[dst];\n\t}\n\n\tbool dual(const Flow delta) {\n\t\tdist.assign(n,\
    \ unreachable);\n\t\tparent.assign(n, nullptr);\n\t\texcess_vs.erase(std::remove_if(std::begin(excess_vs),\
    \ std::end(excess_vs),\n\t\t\t\t\t\t\t\t\t   [&](const int v) { return b[v] <\
    \ delta; }),\n\t\t\t\t\t\tstd::end(excess_vs));\n\t\tdeficit_vs.erase(std::remove_if(std::begin(deficit_vs),\n\
    \t\t\t\t\t\t\t\t\t\tstd::end(deficit_vs),\n\t\t\t\t\t\t\t\t\t\t[&](const int v)\
    \ { return b[v] > -delta; }),\n\t\t\t\t\t\t std::end(deficit_vs));\n\t\tfor (const\
    \ auto v : excess_vs) pq.emplace(dist[v] = 0, v);\n\t\tfarthest = 0;\n\t\tstd::size_t\
    \ deficit_count = 0;\n\t\twhile (!pq.empty()) {\n\t\t\tCost d;\n\t\t\tstd::size_t\
    \ u;\n\t\t\tstd::tie(d, u) = pq.top();\n\t\t\t// const auto [d, u] = pq.top();\n\
    \t\t\tpq.pop();\n\t\t\tif (dist[u] < d) continue;\n\t\t\tfarthest = d;\n\t\t\t\
    if (b[u] <= -delta) ++deficit_count;\n\t\t\tif (deficit_count >= deficit_vs.size())\
    \ break;\n\t\t\tfor (auto& e : g[u]) {\n\t\t\t\tif (e.residual_cap() < delta)\
    \ continue;\n\t\t\t\tconst auto v = e.dst;\n\t\t\t\tconst auto new_dist = d +\
    \ residual_cost(u, v, e);\n\t\t\t\tif (new_dist >= dist[v]) continue;\n\t\t\t\t\
    pq.emplace(dist[v] = new_dist, v);\n\t\t\t\tparent[v] = &e;\n\t\t\t}\n\t\t}\n\t\
    \tpq = decltype(pq)(); // pq.clear() doesn't exist.\n\t\tfor (int v = 0; v < n;\
    \ ++v) {\n\t\t\tpotential[v] += std::min(dist[v], farthest);\n\t\t}\n\t\treturn\
    \ deficit_count > 0;\n\t}\n\n\tvoid primal(const Flow delta) {\n\t\tfor (const\
    \ auto t : deficit_vs) {\n\t\t\tif (dist[t] > farthest) continue;\n\t\t\tFlow\
    \ f = -b[t];\n\t\t\tint v;\n\t\t\tfor (v = t; parent[v] != nullptr; v = parent[v]->src)\
    \ {\n\t\t\t\tf = std::min(f, parent[v]->residual_cap());\n\t\t\t}\n\t\t\tf = std::min(f,\
    \ b[v]);\n\t\t\tf -= f % delta;\n\t\t\tif (f <= 0) continue;\n\t\t\tfor (v = t;\
    \ parent[v] != nullptr;) {\n\t\t\t\tauto& e = *parent[v];\n\t\t\t\tpush(e, f);\n\
    \t\t\t\tint u = parent[v]->src;\n\t\t\t\tif (e.residual_cap() <= 0) parent[v]\
    \ = nullptr;\n\t\t\t\tv = u;\n\t\t\t}\n\t\t\tb[t] += f;\n\t\t\tb[v] -= f;\n\t\t\
    }\n\t}\n\n\tvoid saturate_negative(const Flow delta) {\n\t\tfor (auto& es : g)\
    \ for (auto& e : es) {\n\t\t\tFlow rcap = e.residual_cap();\n\t\t\trcap -= rcap\
    \ % delta;\n\t\t\tconst Cost rcost = residual_cost(e.src, e.dst, e);\n\t\t\tif\
    \ (rcost < 0 || rcap < 0) {\n\t\t\t\tpush(e, rcap);\n\t\t\t\tb[e.src] -= rcap;\n\
    \t\t\t\tb[e.dst] += rcap;\n\t\t\t}\n\t\t}\n\t\tfor (int v = 0; v < n; ++v) if\
    \ (b[v] != 0) {\n\t\t\t(b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);\n\t\
    \t}\n\t}\n\npublic:\n\tstd::pair<Status, Cost> solve() {\n\t\tpotential.resize(n);\n\
    \n\t\tsaturate_negative(1);\n\t\twhile (dual(1)) primal(1);\n\n\t\tCost value\
    \ = 0;\n\t\tfor (const auto& es : g) for (const auto& e : es) {\n\t\t\tvalue +=\
    \ e.flow * e.cost;\n\t\t}\n\t\tvalue /= 2;\n\n\t\tif (excess_vs.empty() && deficit_vs.empty())\
    \ {\n\t\t\treturn { Status::OPTIMAL, value / objective };\n\t\t} else {\n\t\t\t\
    return { Status::INFEASIBLE, value / objective };\n\t\t}\n\t}\n\n\tstd::vector<Cost>\
    \ get_potential() {\n\t\treturn potential;\n\t}\n\ttemplate <class T> T get_result_value()\
    \ {\n\t\tT value = 0;\n\t\tfor (const auto& es : g) for (const auto& e : es) {\n\
    \t\t\tvalue += (T)(e.flow) * (T)(e.cost);\n\t\t}\n\t\tvalue /= (T)2;\n\t\treturn\
    \ value;\n\t}\n};\n\ntemplate <class T> std::string i2s(T value) {\n    if (value\
    \ < 0) return \"-\" + i2s(-value);\n    if (value == 0) return \"0\";\n    std::string\
    \ s;\n    while (value) {\n        s += '0' + (value % 10);\n        value /=\
    \ 10;\n    }\n    std::reverse(s.begin(), s.end());\n    return s;\n}\n\nint main()\
    \ {\n\tusing MCF = MinCostFlow<long long, long long>;\n\tusing namespace std;\n\
    \tint n, m;\n\tcin >> n >> m;\n\tMCF mcf;\n\tconst auto vs = mcf.add_vertices(n);\n\
    \tfor (const auto& v : vs) {\n\t\tint x;\n\t\tcin >> x;\n\t\tmcf.add_supply(vs[v],\
    \ x);\n\t}\n\tvector<MCF::EdgePtr> edges;\n\twhile (m--) {\n\t\tint s, t, l, u,\
    \ c;\n\t\tcin >> s >> t >> l >> u >> c;\n\t\tedges.emplace_back(mcf.add_edge(s,\
    \ t, l, u, c));\n\t}\n\tconst auto status = mcf.solve().first;\n\tif (status ==\
    \ Status::INFEASIBLE) {\n\t\tputs(\"infeasible\");\n\t} else {\n\t\tconst auto\
    \ potential = mcf.get_potential();\n\t\tconst auto result_value = mcf.get_result_value<__int128_t>();\n\
    \t\tputs(i2s(result_value).c_str());\n\t\tfor (const auto& v : vs) {\n\t\t\tputs(i2s(potential[v]).c_str());\n\
    \t\t}\n\t\tfor (const auto& e : edges) {\n\t\t\tputs(i2s(e.flow()).c_str());\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"../../library/graphs/flows/min-cost-b-flow.hpp\"\
    \n\ntemplate <class T> std::string i2s(T value) {\n    if (value < 0) return \"\
    -\" + i2s(-value);\n    if (value == 0) return \"0\";\n    std::string s;\n  \
    \  while (value) {\n        s += '0' + (value % 10);\n        value /= 10;\n \
    \   }\n    std::reverse(s.begin(), s.end());\n    return s;\n}\n\nint main() {\n\
    \tusing MCF = MinCostFlow<long long, long long>;\n\tusing namespace std;\n\tint\
    \ n, m;\n\tcin >> n >> m;\n\tMCF mcf;\n\tconst auto vs = mcf.add_vertices(n);\n\
    \tfor (const auto& v : vs) {\n\t\tint x;\n\t\tcin >> x;\n\t\tmcf.add_supply(vs[v],\
    \ x);\n\t}\n\tvector<MCF::EdgePtr> edges;\n\twhile (m--) {\n\t\tint s, t, l, u,\
    \ c;\n\t\tcin >> s >> t >> l >> u >> c;\n\t\tedges.emplace_back(mcf.add_edge(s,\
    \ t, l, u, c));\n\t}\n\tconst auto status = mcf.solve().first;\n\tif (status ==\
    \ Status::INFEASIBLE) {\n\t\tputs(\"infeasible\");\n\t} else {\n\t\tconst auto\
    \ potential = mcf.get_potential();\n\t\tconst auto result_value = mcf.get_result_value<__int128_t>();\n\
    \t\tputs(i2s(result_value).c_str());\n\t\tfor (const auto& v : vs) {\n\t\t\tputs(i2s(potential[v]).c_str());\n\
    \t\t}\n\t\tfor (const auto& e : edges) {\n\t\t\tputs(i2s(e.flow()).c_str());\n\
    \t\t}\n\t}\n}\n"
  dependsOn:
  - library/graphs/flows/min-cost-b-flow.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-min_cost_b_flow.test.cpp
  requiredBy: []
  timestamp: '2021-08-20 12:43:19-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-min_cost_b_flow.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-min_cost_b_flow.test.cpp
- /verify/verify/yosupo/yosupo-min_cost_b_flow.test.cpp.html
title: verify/yosupo/yosupo-min_cost_b_flow.test.cpp
---
