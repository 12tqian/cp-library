---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graphs/flows/min-cost-b-flow.hpp
    title: library/graphs/flows/min-cost-b-flow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n\r\nenum Objective {\r\n\tMINIMIZE = 1,\r\n\
    \tMAXIMIZE = -1,\r\n};\r\n\r\nenum class Status {\r\n\tOPTIMAL,\r\n\tINFEASIBLE,\r\
    \n};\r\n\r\ntemplate <class Flow, class Cost, Objective objective = Objective::MINIMIZE,\
    \ Flow SCALING_FACTOR = 2>\r\nclass MinCostFlow {\r\n\tusing V_id = uint32_t;\r\
    \n\tusing E_id = uint32_t;\r\n\r\n\tclass Edge {\r\n\t\tfriend class MinCostFlow;\r\
    \n\r\n\t\tV_id src, dst;\r\n\t\tFlow flow, cap;\r\n\t\tCost cost;\r\n\t\tE_id\
    \ rev;\r\n\r\n\tpublic:\r\n\t\tEdge() = default;\r\n\r\n\t\tEdge(const V_id _src,\
    \ const V_id _dst, const Flow _cap, const Cost _cost,\r\n\t\t\t const E_id _rev)\r\
    \n\t\t\t: src(_src), dst(_dst), flow(0), cap(_cap), cost(_cost), rev(_rev) {}\r\
    \n\r\n\t\t[[nodiscard]] Flow residual_cap() const { return cap - flow; }\r\n\t\
    };\r\n\r\npublic:\r\n\tclass EdgePtr {\r\n\t\tfriend class MinCostFlow;\r\n\r\n\
    \t\tconst MinCostFlow* instance;\r\n\r\n\t\tV_id v;\r\n\t\tE_id e;\r\n\r\n\t\t\
    EdgePtr(const MinCostFlow* const _instance, const V_id _v, const E_id _e)\r\n\t\
    \t\t: instance(_instance), v(_v), e(_e) {}\r\n\r\n\t\t[[nodiscard]] const Edge&\
    \ edge() const { return instance->g[v][e]; }\r\n\r\n\t\t[[nodiscard]] const Edge&\
    \ rev() const {\r\n\t\t\tconst Edge& _e = edge();\r\n\t\t\treturn instance->g[_e.dst][_e.rev];\r\
    \n\t\t}\r\n\r\n\tpublic:\r\n\t\tEdgePtr() = default;\r\n\r\n\t\t[[nodiscard]]\
    \ V_id src() const { return v; }\r\n\r\n\t\t[[nodiscard]] V_id dst() const { return\
    \ edge().dst; }\r\n\r\n\t\t[[nodiscard]] Flow flow() const { return edge().flow;\
    \ }\r\n\r\n\t\t[[nodiscard]] Flow lower() const { return -rev().cap; }\r\n\r\n\
    \t\t[[nodiscard]] Flow upper() const { return edge().cap; }\r\n\r\n\t\t[[nodiscard]]\
    \ Cost cost() const { return edge().cost; }\r\n\r\n\t\t[[nodiscard]] Cost gain()\
    \ const { return -edge().cost; }\r\n\t};\r\n\r\nprivate:\r\n\tV_id n;\r\n\tstd::vector<std::vector<Edge>>\
    \ g;\r\n\tstd::vector<Flow> b;\r\n\r\npublic:\r\n\tMinCostFlow() : n(0) {}\r\n\
    \r\n\tV_id add_vertex() {\r\n\t\t++n;\r\n\t\tg.resize(n);\r\n\t\tb.resize(n);\r\
    \n\t\treturn n-1;\r\n\t}\r\n\r\n\tstd::vector<V_id> add_vertices(const size_t\
    \ size) {\r\n\t\tstd::vector<V_id> ret(size);\r\n\t\tstd::iota(std::begin(ret),\
    \ std::end(ret), n);\r\n\t\tn += size;\r\n\t\tg.resize(n);\r\n\t\tb.resize(n);\r\
    \n\t\treturn ret;\r\n\t}\r\n\r\n\tEdgePtr add_edge(const V_id src, const V_id\
    \ dst, const Flow lower,\r\n\t\t\t\t\t const Flow upper, const Cost cost) {\r\n\
    \t\tconst E_id e = g[src].size(), re = src == dst ? e + 1 : g[dst].size();\r\n\
    \t\tassert(lower <= upper);\r\n\t\tg[src].emplace_back(Edge{src, dst, upper, cost\
    \ * objective, re});\r\n\t\tg[dst].emplace_back(Edge{dst, src, -lower, -cost *\
    \ objective, e});\r\n\t\treturn EdgePtr{this, src, e};\r\n\t}\r\n\r\n\tvoid add_supply(const\
    \ V_id v, const Flow amount) { b[v] += amount; }\r\n\r\n\tvoid add_demand(const\
    \ V_id v, const Flow amount) { b[v] -= amount; }\r\n\r\nprivate:\r\n\t// Variables\
    \ used in calculation\r\n\tconst Cost unreachable = std::numeric_limits<Cost>::max();\r\
    \n\tCost farthest;\r\n\tstd::vector<Cost> potential;\r\n\tstd::vector<Cost> dist;\r\
    \n\tstd::vector<Edge*> parent; // out-forest.\r\n\tstd::priority_queue<std::pair<Cost,\
    \ int>, std::vector<std::pair<Cost, int>>,\r\n\t\tstd::greater<>>\r\n\t\t\tpq;\
    \ // should be empty outside of dual()\r\n\tstd::vector<V_id> excess_vs, deficit_vs;\r\
    \n\r\n\tEdge& rev(const Edge& e) { return g[e.dst][e.rev]; }\r\n\r\n\tvoid push(Edge&\
    \ e, const Flow amount) {\r\n\t\te.flow += amount;\r\n\t\tg[e.dst][e.rev].flow\
    \ -= amount;\r\n\t}\r\n\r\n\tCost residual_cost(const V_id src, const V_id dst,\
    \ const Edge& e) {\r\n\t\treturn e.cost + potential[src] - potential[dst];\r\n\
    \t}\r\n\r\n\tbool dual(const Flow delta) {\r\n\t\tdist.assign(n, unreachable);\r\
    \n\t\tparent.assign(n, nullptr);\r\n\t\texcess_vs.erase(std::remove_if(std::begin(excess_vs),\
    \ \r\n\t\t\t\t\t\t\t\t\t\tstd::end(excess_vs),\r\n\t\t\t\t\t\t\t\t\t\t[&](const\
    \ V_id v) { return b[v] < delta; }),\r\n\t\t\t\t\t\t\t\t\t\tstd::end(excess_vs));\r\
    \n\t\tdeficit_vs.erase(std::remove_if(std::begin(deficit_vs),\r\n\t\t\t\t\t\t\t\
    \t\t\tstd::end(deficit_vs),\r\n\t\t\t\t\t\t\t\t\t\t[&](const V_id v) { return\
    \ b[v] > -delta; }),\r\n\t\t\t\t\t\t \t\t\t\tstd::end(deficit_vs));\r\n\t\tfor\
    \ (const auto v : excess_vs) pq.emplace(dist[v] = 0, v);\r\n\t\tfarthest = 0;\r\
    \n\t\tstd::size_t deficit_count = 0;\r\n\t\twhile (!pq.empty()) {\r\n\t\t\tCost\
    \ d;\r\n\t\t\tstd::size_t u;\r\n\t\t\tstd::tie(d, u) = pq.top();\r\n\t\t\tpq.pop();\r\
    \n\t\t\tif (dist[u] < d) continue;\r\n\t\t\tfarthest = d;\r\n\t\t\tif (b[u] <=\
    \ -delta) ++deficit_count;\r\n\t\t\tif (deficit_count >= deficit_vs.size()) break;\r\
    \n\t\t\tfor (auto& e : g[u]) {\r\n\t\t\t\tif (e.residual_cap() < delta) continue;\r\
    \n\t\t\t\tconst auto v = e.dst;\r\n\t\t\t\tconst auto new_dist = d + residual_cost(u,\
    \ v, e);\r\n\t\t\t\tif (new_dist >= dist[v]) continue;\r\n\t\t\t\tpq.emplace(dist[v]\
    \ = new_dist, v);\r\n\t\t\t\tparent[v] = &e;\r\n\t\t\t}\r\n\t\t}\r\n\t\tpq = decltype(pq)();\
    \ // pq.clear() doesn't exist.\r\n\t\tfor (V_id v = 0; v < n; ++v) {\r\n\t\t\t\
    potential[v] += std::min(dist[v], farthest);\r\n\t\t}\r\n\t\treturn deficit_count\
    \ > 0;\r\n\t}\r\n\r\n\tvoid primal(const Flow delta) {\r\n\t\tfor (const auto\
    \ t : deficit_vs) {\r\n\t\t\tif (dist[t] > farthest) continue;\r\n\t\t\tFlow f\
    \ = -b[t];\r\n\t\t\tV_id v;\r\n\t\t\tfor (v = t; parent[v] != nullptr; v = parent[v]->src)\
    \ {\r\n\t\t\t\tf = std::min(f, parent[v]->residual_cap());\r\n\t\t\t}\r\n\t\t\t\
    f = std::min(f, b[v]);\r\n\t\t\tf -= f % delta;\r\n\t\t\tif (f <= 0) continue;\r\
    \n\t\t\tfor (v = t; parent[v] != nullptr;) {\r\n\t\t\t\tauto& e = *parent[v];\r\
    \n\t\t\t\tpush(e, f);\r\n\t\t\t\tint u = parent[v]->src;\r\n\t\t\t\tif (e.residual_cap()\
    \ <= 0) parent[v] = nullptr;\r\n\t\t\t\tv = u;\r\n\t\t\t}\r\n\t\t\tb[t] += f;\r\
    \n\t\t\tb[v] -= f;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid saturate_negative(const Flow\
    \ delta) {\r\n\t\texcess_vs.clear();\r\n\t\tdeficit_vs.clear();\r\n\t\tfor (auto&\
    \ es : g) for (auto& e : es) {\r\n\t\t\tFlow rcap = e.residual_cap();\r\n\t\t\t\
    rcap -= rcap % delta;\r\n\t\t\tconst Cost rcost = residual_cost(e.src, e.dst,\
    \ e);\r\n\t\t\tif (rcost < 0 || rcap < 0) {\r\n\t\t\t\tpush(e, rcap);\r\n\t\t\t\
    \tb[e.src] -= rcap;\r\n\t\t\t\tb[e.dst] += rcap;\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor\
    \ (V_id v = 0; v < n; ++v) if (b[v] != 0) {\r\n\t\t\t(b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);\r\
    \n\t\t}\r\n\t}\r\n\r\npublic:\r\n\tstd::pair<Status, Cost> solve() {\r\n\t\tpotential.resize(n);\r\
    \n\t\tFlow inf_flow = 1;\r\n\t\tfor (const auto t : b)\r\n\t\t\tinf_flow = std::max({inf_flow,\
    \ t, -t});\r\n\t\tfor (const auto& es : g) for (const auto& e : es)\r\n\t\t\t\
    inf_flow = std::max({inf_flow, e.residual_cap(), -e.residual_cap()});\r\n\t\t\
    Flow delta = 1;\r\n\t\twhile (delta < inf_flow) delta *= SCALING_FACTOR;\r\n\t\
    \tfor (; delta; delta /= SCALING_FACTOR) {\r\n\t\t\tsaturate_negative(delta);\r\
    \n\t\t\twhile (dual(delta)) primal(delta);\r\n\t\t}\r\n\t\tCost value = 0;\r\n\
    \t\tfor (const auto& es : g) for (const auto& e : es) {\r\n\t\t\tvalue += e.flow\
    \ * e.cost;\r\n\t\t}\r\n\t\tvalue /= 2;\r\n\t\tif (excess_vs.empty() && deficit_vs.empty())\
    \ {\r\n\t\t\treturn { Status::OPTIMAL, value / objective };\r\n\t\t} else {\r\n\
    \t\t\treturn { Status::INFEASIBLE, value / objective };\r\n\t\t}\r\n\t}\r\n\r\n\
    \tstd::vector<Cost> get_potential() {\r\n\t\t// Not strictly necessary, but re-calculate\
    \ potential to bound the potential values,\r\n\t\t// plus make them somewhat canonical\
    \ so that it is robust for the algorithm chaneges.\r\n\t\tstd::fill(std::begin(potential),\
    \ std::end(potential), 0);\r\n\t\tfor (size_t i = 0; i < n; ++i) for (const auto&\
    \ es : g) for (const auto& e : es)\r\n\t\t\tif (e.residual_cap() > 0) potential[e.dst]\
    \ = std::min(potential[e.dst], potential[e.src] + e.cost);\r\n\t\treturn potential;\r\
    \n\t}\r\n\r\n\ttemplate <class T> T get_result_value() {\r\n\t\tT value = 0;\r\
    \n\t\tfor (const auto& es : g) for (const auto& e : es) {\r\n\t\t\tvalue += (T)(e.flow)\
    \ * (T)(e.cost);\r\n\t\t}\r\n\t\tvalue /= (T)2;\r\n\t\treturn value;\r\n\t}\r\n\
    \t\r\n\tstd::vector<size_t> get_cut() {\r\n\t\tstd::vector<size_t> res;\r\n\t\t\
    if (excess_vs.empty()) return res;\r\n\t\tfor (size_t v = 0; v < n; ++v) {\r\n\
    \t\t\tif (deficit_vs.empty() || (dist[v] < unreachable))\r\n\t\t\t\tres.emplace_back(v);\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\n\r\ntemplate <class T> std::string i2s(T\
    \ value) {\r\n    if (value < 0) return \"-\" + i2s(-value);\r\n    if (value\
    \ == 0) return \"0\";\r\n    std::string s;\r\n    while (value) {\r\n       \
    \ s += '0' + (value % 10);\r\n        value /= 10;\r\n    }\r\n    std::reverse(s.begin(),\
    \ s.end());\r\n    return s;\r\n}\r\n\r\nint main() {\r\n\tusing MCF = MinCostFlow<long\
    \ long, long long>;\r\n\tusing namespace std;\r\n\tint n, m;\r\n\tcin >> n >>\
    \ m;\r\n\tMCF mcf;\r\n\tconst auto vs = mcf.add_vertices(n);\r\n\tfor (const auto&\
    \ v : vs) {\r\n\t\tint x;\r\n\t\tcin >> x;\r\n\t\tmcf.add_supply(vs[v], x);\r\n\
    \t}\r\n\tvector<MCF::EdgePtr> edges;\r\n\twhile (m--) {\r\n\t\tint s, t, l, u,\
    \ c;\r\n\t\tcin >> s >> t >> l >> u >> c;\r\n\t\tedges.emplace_back(mcf.add_edge(s,\
    \ t, l, u, c));\r\n\t}\r\n\tconst auto status = mcf.solve().first;\r\n\tif (status\
    \ == Status::INFEASIBLE) {\r\n\t\tputs(\"infeasible\");\r\n\t} else {\r\n\t\t\
    const auto potential = mcf.get_potential();\r\n\t\tconst auto result_value = mcf.get_result_value<__int128_t>();\r\
    \n\t\tputs(i2s(result_value).c_str());\r\n\t\tfor (const auto& v : vs) {\r\n\t\
    \t\tputs(i2s(potential[v]).c_str());\r\n\t\t}\r\n\t\tfor (const auto& e : edges)\
    \ {\r\n\t\t\tputs(i2s(e.flow()).c_str());\r\n\t\t}\r\n\t}\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\r\n\r\
    \n#include <bits/stdc++.h>\r\n#include \"../../library/graphs/flows/min-cost-b-flow.hpp\"\
    \r\n\r\ntemplate <class T> std::string i2s(T value) {\r\n    if (value < 0) return\
    \ \"-\" + i2s(-value);\r\n    if (value == 0) return \"0\";\r\n    std::string\
    \ s;\r\n    while (value) {\r\n        s += '0' + (value % 10);\r\n        value\
    \ /= 10;\r\n    }\r\n    std::reverse(s.begin(), s.end());\r\n    return s;\r\n\
    }\r\n\r\nint main() {\r\n\tusing MCF = MinCostFlow<long long, long long>;\r\n\t\
    using namespace std;\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tMCF mcf;\r\n\tconst\
    \ auto vs = mcf.add_vertices(n);\r\n\tfor (const auto& v : vs) {\r\n\t\tint x;\r\
    \n\t\tcin >> x;\r\n\t\tmcf.add_supply(vs[v], x);\r\n\t}\r\n\tvector<MCF::EdgePtr>\
    \ edges;\r\n\twhile (m--) {\r\n\t\tint s, t, l, u, c;\r\n\t\tcin >> s >> t >>\
    \ l >> u >> c;\r\n\t\tedges.emplace_back(mcf.add_edge(s, t, l, u, c));\r\n\t}\r\
    \n\tconst auto status = mcf.solve().first;\r\n\tif (status == Status::INFEASIBLE)\
    \ {\r\n\t\tputs(\"infeasible\");\r\n\t} else {\r\n\t\tconst auto potential = mcf.get_potential();\r\
    \n\t\tconst auto result_value = mcf.get_result_value<__int128_t>();\r\n\t\tputs(i2s(result_value).c_str());\r\
    \n\t\tfor (const auto& v : vs) {\r\n\t\t\tputs(i2s(potential[v]).c_str());\r\n\
    \t\t}\r\n\t\tfor (const auto& e : edges) {\r\n\t\t\tputs(i2s(e.flow()).c_str());\r\
    \n\t\t}\r\n\t}\r\n}\r\n"
  dependsOn:
  - library/graphs/flows/min-cost-b-flow.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-min_cost_b_flow.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-min_cost_b_flow.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-min_cost_b_flow.test.cpp
- /verify/verify/yosupo/yosupo-min_cost_b_flow.test.cpp.html
title: verify/yosupo/yosupo-min_cost_b_flow.test.cpp
---
