---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-min_cost_b_flow.test.cpp
    title: verify/yosupo/yosupo-min_cost_b_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nenum Objective {\n\tMINIMIZE = 1,\n\tMAXIMIZE = -1,\n};\n\nenum\
    \ class Status {\n\tOPTIMAL,\n\tINFEASIBLE,\n};\n\ntemplate <class Flow, class\
    \ Cost, Objective objective = Objective::MINIMIZE, Flow SCALING_FACTOR = 2>\n\
    class MinCostFlow {\n\tusing V_id = uint32_t;\n\tusing E_id = uint32_t;\n\n\t\
    class Edge {\n\t\tfriend class MinCostFlow;\n\n\t\tV_id src, dst;\n\t\tFlow flow,\
    \ cap;\n\t\tCost cost;\n\t\tE_id rev;\n\n\tpublic:\n\t\tEdge() = default;\n\n\t\
    \tEdge(const V_id _src, const V_id _dst, const Flow _cap, const Cost _cost,\n\t\
    \t\t const E_id _rev)\n\t\t\t: src(_src), dst(_dst), flow(0), cap(_cap), cost(_cost),\
    \ rev(_rev) {}\n\n\t\t[[nodiscard]] Flow residual_cap() const { return cap - flow;\
    \ }\n\t};\n\npublic:\n\tclass EdgePtr {\n\t\tfriend class MinCostFlow;\n\n\t\t\
    const MinCostFlow* instance;\n\n\t\tV_id v;\n\t\tE_id e;\n\n\t\tEdgePtr(const\
    \ MinCostFlow* const _instance, const V_id _v, const E_id _e)\n\t\t\t: instance(_instance),\
    \ v(_v), e(_e) {}\n\n\t\t[[nodiscard]] const Edge& edge() const { return instance->g[v][e];\
    \ }\n\n\t\t[[nodiscard]] const Edge& rev() const {\n\t\t\tconst Edge& _e = edge();\n\
    \t\t\treturn instance->g[_e.dst][_e.rev];\n\t\t}\n\n\tpublic:\n\t\tEdgePtr() =\
    \ default;\n\n\t\t[[nodiscard]] V_id src() const { return v; }\n\n\t\t[[nodiscard]]\
    \ V_id dst() const { return edge().dst; }\n\n\t\t[[nodiscard]] Flow flow() const\
    \ { return edge().flow; }\n\n\t\t[[nodiscard]] Flow lower() const { return -rev().cap;\
    \ }\n\n\t\t[[nodiscard]] Flow upper() const { return edge().cap; }\n\n\t\t[[nodiscard]]\
    \ Cost cost() const { return edge().cost; }\n\n\t\t[[nodiscard]] Cost gain() const\
    \ { return -edge().cost; }\n\t};\n\nprivate:\n\tV_id n;\n\tstd::vector<std::vector<Edge>>\
    \ g;\n\tstd::vector<Flow> b;\n\npublic:\n\tMinCostFlow() : n(0) {}\n\n\tV_id add_vertex()\
    \ {\n\t\t++n;\n\t\tg.resize(n);\n\t\tb.resize(n);\n\t\treturn n-1;\n\t}\n\n\t\
    std::vector<V_id> add_vertices(const size_t size) {\n\t\tstd::vector<V_id> ret(size);\n\
    \t\tstd::iota(std::begin(ret), std::end(ret), n);\n\t\tn += size;\n\t\tg.resize(n);\n\
    \t\tb.resize(n);\n\t\treturn ret;\n\t}\n\n\tEdgePtr add_edge(const V_id src, const\
    \ V_id dst, const Flow lower,\n\t\t\t\t\t const Flow upper, const Cost cost) {\n\
    \t\tconst E_id e = g[src].size(), re = src == dst ? e + 1 : g[dst].size();\n\t\
    \tassert(lower <= upper);\n\t\tg[src].emplace_back(Edge{src, dst, upper, cost\
    \ * objective, re});\n\t\tg[dst].emplace_back(Edge{dst, src, -lower, -cost * objective,\
    \ e});\n\t\treturn EdgePtr{this, src, e};\n\t}\n\n\tvoid add_supply(const V_id\
    \ v, const Flow amount) { b[v] += amount; }\n\n\tvoid add_demand(const V_id v,\
    \ const Flow amount) { b[v] -= amount; }\n\nprivate:\n\t// Variables used in calculation\n\
    \tconst Cost unreachable = std::numeric_limits<Cost>::max();\n\tCost farthest;\n\
    \tstd::vector<Cost> potential;\n\tstd::vector<Cost> dist;\n\tstd::vector<Edge*>\
    \ parent; // out-forest.\n\tstd::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost,\
    \ int>>,\n\t\tstd::greater<>>\n\t\t\tpq; // should be empty outside of dual()\n\
    \tstd::vector<V_id> excess_vs, deficit_vs;\n\n\tEdge& rev(const Edge& e) { return\
    \ g[e.dst][e.rev]; }\n\n\tvoid push(Edge& e, const Flow amount) {\n\t\te.flow\
    \ += amount;\n\t\tg[e.dst][e.rev].flow -= amount;\n\t}\n\n\tCost residual_cost(const\
    \ V_id src, const V_id dst, const Edge& e) {\n\t\treturn e.cost + potential[src]\
    \ - potential[dst];\n\t}\n\n\tbool dual(const Flow delta) {\n\t\tdist.assign(n,\
    \ unreachable);\n\t\tparent.assign(n, nullptr);\n\t\texcess_vs.erase(std::remove_if(std::begin(excess_vs),\
    \ \n\t\t\t\t\t\t\t\t\t\tstd::end(excess_vs),\n\t\t\t\t\t\t\t\t\t\t[&](const V_id\
    \ v) { return b[v] < delta; }),\n\t\t\t\t\t\t\t\t\t\tstd::end(excess_vs));\n\t\
    \tdeficit_vs.erase(std::remove_if(std::begin(deficit_vs),\n\t\t\t\t\t\t\t\t\t\t\
    std::end(deficit_vs),\n\t\t\t\t\t\t\t\t\t\t[&](const V_id v) { return b[v] > -delta;\
    \ }),\n\t\t\t\t\t\t \t\t\t\tstd::end(deficit_vs));\n\t\tfor (const auto v : excess_vs)\
    \ pq.emplace(dist[v] = 0, v);\n\t\tfarthest = 0;\n\t\tstd::size_t deficit_count\
    \ = 0;\n\t\twhile (!pq.empty()) {\n\t\t\tCost d;\n\t\t\tstd::size_t u;\n\t\t\t\
    std::tie(d, u) = pq.top();\n\t\t\tpq.pop();\n\t\t\tif (dist[u] < d) continue;\n\
    \t\t\tfarthest = d;\n\t\t\tif (b[u] <= -delta) ++deficit_count;\n\t\t\tif (deficit_count\
    \ >= deficit_vs.size()) break;\n\t\t\tfor (auto& e : g[u]) {\n\t\t\t\tif (e.residual_cap()\
    \ < delta) continue;\n\t\t\t\tconst auto v = e.dst;\n\t\t\t\tconst auto new_dist\
    \ = d + residual_cost(u, v, e);\n\t\t\t\tif (new_dist >= dist[v]) continue;\n\t\
    \t\t\tpq.emplace(dist[v] = new_dist, v);\n\t\t\t\tparent[v] = &e;\n\t\t\t}\n\t\
    \t}\n\t\tpq = decltype(pq)(); // pq.clear() doesn't exist.\n\t\tfor (V_id v =\
    \ 0; v < n; ++v) {\n\t\t\tpotential[v] += std::min(dist[v], farthest);\n\t\t}\n\
    \t\treturn deficit_count > 0;\n\t}\n\n\tvoid primal(const Flow delta) {\n\t\t\
    for (const auto t : deficit_vs) {\n\t\t\tif (dist[t] > farthest) continue;\n\t\
    \t\tFlow f = -b[t];\n\t\t\tV_id v;\n\t\t\tfor (v = t; parent[v] != nullptr; v\
    \ = parent[v]->src) {\n\t\t\t\tf = std::min(f, parent[v]->residual_cap());\n\t\
    \t\t}\n\t\t\tf = std::min(f, b[v]);\n\t\t\tf -= f % delta;\n\t\t\tif (f <= 0)\
    \ continue;\n\t\t\tfor (v = t; parent[v] != nullptr;) {\n\t\t\t\tauto& e = *parent[v];\n\
    \t\t\t\tpush(e, f);\n\t\t\t\tint u = parent[v]->src;\n\t\t\t\tif (e.residual_cap()\
    \ <= 0) parent[v] = nullptr;\n\t\t\t\tv = u;\n\t\t\t}\n\t\t\tb[t] += f;\n\t\t\t\
    b[v] -= f;\n\t\t}\n\t}\n\n\tvoid saturate_negative(const Flow delta) {\n\t\texcess_vs.clear();\n\
    \t\tdeficit_vs.clear();\n\t\tfor (auto& es : g) for (auto& e : es) {\n\t\t\tFlow\
    \ rcap = e.residual_cap();\n\t\t\trcap -= rcap % delta;\n\t\t\tconst Cost rcost\
    \ = residual_cost(e.src, e.dst, e);\n\t\t\tif (rcost < 0 || rcap < 0) {\n\t\t\t\
    \tpush(e, rcap);\n\t\t\t\tb[e.src] -= rcap;\n\t\t\t\tb[e.dst] += rcap;\n\t\t\t\
    }\n\t\t}\n\t\tfor (V_id v = 0; v < n; ++v) if (b[v] != 0) {\n\t\t\t(b[v] > 0 ?\
    \ excess_vs : deficit_vs).emplace_back(v);\n\t\t}\n\t}\n\npublic:\n\tstd::pair<Status,\
    \ Cost> solve() {\n\t\tpotential.resize(n);\n\t\tFlow inf_flow = 1;\n\t\tfor (const\
    \ auto t : b)\n\t\t\tinf_flow = std::max({inf_flow, t, -t});\n\t\tfor (const auto&\
    \ es : g) for (const auto& e : es)\n\t\t\tinf_flow = std::max({inf_flow, e.residual_cap(),\
    \ -e.residual_cap()});\n\t\tFlow delta = 1;\n\t\twhile (delta < inf_flow) delta\
    \ *= SCALING_FACTOR;\n\t\tfor (; delta; delta /= SCALING_FACTOR) {\n\t\t\tsaturate_negative(delta);\n\
    \t\t\twhile (dual(delta)) primal(delta);\n\t\t}\n\t\tCost value = 0;\n\t\tfor\
    \ (const auto& es : g) for (const auto& e : es) {\n\t\t\tvalue += e.flow * e.cost;\n\
    \t\t}\n\t\tvalue /= 2;\n\t\tif (excess_vs.empty() && deficit_vs.empty()) {\n\t\
    \t\treturn { Status::OPTIMAL, value / objective };\n\t\t} else {\n\t\t\treturn\
    \ { Status::INFEASIBLE, value / objective };\n\t\t}\n\t}\n\n\tstd::vector<Cost>\
    \ get_potential() {\n\t\t// Not strictly necessary, but re-calculate potential\
    \ to bound the potential values,\n\t\t// plus make them somewhat canonical so\
    \ that it is robust for the algorithm chaneges.\n\t\tstd::fill(std::begin(potential),\
    \ std::end(potential), 0);\n\t\tfor (size_t i = 0; i < n; ++i) for (const auto&\
    \ es : g) for (const auto& e : es)\n\t\t\tif (e.residual_cap() > 0) potential[e.dst]\
    \ = std::min(potential[e.dst], potential[e.src] + e.cost);\n\t\treturn potential;\n\
    \t}\n\n\ttemplate <class T> T get_result_value() {\n\t\tT value = 0;\n\t\tfor\
    \ (const auto& es : g) for (const auto& e : es) {\n\t\t\tvalue += (T)(e.flow)\
    \ * (T)(e.cost);\n\t\t}\n\t\tvalue /= (T)2;\n\t\treturn value;\n\t}\n\t\n\tstd::vector<size_t>\
    \ get_cut() {\n\t\tstd::vector<size_t> res;\n\t\tif (excess_vs.empty()) return\
    \ res;\n\t\tfor (size_t v = 0; v < n; ++v) {\n\t\t\tif (deficit_vs.empty() ||\
    \ (dist[v] < unreachable))\n\t\t\t\tres.emplace_back(v);\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n"
  code: "#pragma once\n\nenum Objective {\n\tMINIMIZE = 1,\n\tMAXIMIZE = -1,\n};\n\
    \nenum class Status {\n\tOPTIMAL,\n\tINFEASIBLE,\n};\n\ntemplate <class Flow,\
    \ class Cost, Objective objective = Objective::MINIMIZE, Flow SCALING_FACTOR =\
    \ 2>\nclass MinCostFlow {\n\tusing V_id = uint32_t;\n\tusing E_id = uint32_t;\n\
    \n\tclass Edge {\n\t\tfriend class MinCostFlow;\n\n\t\tV_id src, dst;\n\t\tFlow\
    \ flow, cap;\n\t\tCost cost;\n\t\tE_id rev;\n\n\tpublic:\n\t\tEdge() = default;\n\
    \n\t\tEdge(const V_id _src, const V_id _dst, const Flow _cap, const Cost _cost,\n\
    \t\t\t const E_id _rev)\n\t\t\t: src(_src), dst(_dst), flow(0), cap(_cap), cost(_cost),\
    \ rev(_rev) {}\n\n\t\t[[nodiscard]] Flow residual_cap() const { return cap - flow;\
    \ }\n\t};\n\npublic:\n\tclass EdgePtr {\n\t\tfriend class MinCostFlow;\n\n\t\t\
    const MinCostFlow* instance;\n\n\t\tV_id v;\n\t\tE_id e;\n\n\t\tEdgePtr(const\
    \ MinCostFlow* const _instance, const V_id _v, const E_id _e)\n\t\t\t: instance(_instance),\
    \ v(_v), e(_e) {}\n\n\t\t[[nodiscard]] const Edge& edge() const { return instance->g[v][e];\
    \ }\n\n\t\t[[nodiscard]] const Edge& rev() const {\n\t\t\tconst Edge& _e = edge();\n\
    \t\t\treturn instance->g[_e.dst][_e.rev];\n\t\t}\n\n\tpublic:\n\t\tEdgePtr() =\
    \ default;\n\n\t\t[[nodiscard]] V_id src() const { return v; }\n\n\t\t[[nodiscard]]\
    \ V_id dst() const { return edge().dst; }\n\n\t\t[[nodiscard]] Flow flow() const\
    \ { return edge().flow; }\n\n\t\t[[nodiscard]] Flow lower() const { return -rev().cap;\
    \ }\n\n\t\t[[nodiscard]] Flow upper() const { return edge().cap; }\n\n\t\t[[nodiscard]]\
    \ Cost cost() const { return edge().cost; }\n\n\t\t[[nodiscard]] Cost gain() const\
    \ { return -edge().cost; }\n\t};\n\nprivate:\n\tV_id n;\n\tstd::vector<std::vector<Edge>>\
    \ g;\n\tstd::vector<Flow> b;\n\npublic:\n\tMinCostFlow() : n(0) {}\n\n\tV_id add_vertex()\
    \ {\n\t\t++n;\n\t\tg.resize(n);\n\t\tb.resize(n);\n\t\treturn n-1;\n\t}\n\n\t\
    std::vector<V_id> add_vertices(const size_t size) {\n\t\tstd::vector<V_id> ret(size);\n\
    \t\tstd::iota(std::begin(ret), std::end(ret), n);\n\t\tn += size;\n\t\tg.resize(n);\n\
    \t\tb.resize(n);\n\t\treturn ret;\n\t}\n\n\tEdgePtr add_edge(const V_id src, const\
    \ V_id dst, const Flow lower,\n\t\t\t\t\t const Flow upper, const Cost cost) {\n\
    \t\tconst E_id e = g[src].size(), re = src == dst ? e + 1 : g[dst].size();\n\t\
    \tassert(lower <= upper);\n\t\tg[src].emplace_back(Edge{src, dst, upper, cost\
    \ * objective, re});\n\t\tg[dst].emplace_back(Edge{dst, src, -lower, -cost * objective,\
    \ e});\n\t\treturn EdgePtr{this, src, e};\n\t}\n\n\tvoid add_supply(const V_id\
    \ v, const Flow amount) { b[v] += amount; }\n\n\tvoid add_demand(const V_id v,\
    \ const Flow amount) { b[v] -= amount; }\n\nprivate:\n\t// Variables used in calculation\n\
    \tconst Cost unreachable = std::numeric_limits<Cost>::max();\n\tCost farthest;\n\
    \tstd::vector<Cost> potential;\n\tstd::vector<Cost> dist;\n\tstd::vector<Edge*>\
    \ parent; // out-forest.\n\tstd::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost,\
    \ int>>,\n\t\tstd::greater<>>\n\t\t\tpq; // should be empty outside of dual()\n\
    \tstd::vector<V_id> excess_vs, deficit_vs;\n\n\tEdge& rev(const Edge& e) { return\
    \ g[e.dst][e.rev]; }\n\n\tvoid push(Edge& e, const Flow amount) {\n\t\te.flow\
    \ += amount;\n\t\tg[e.dst][e.rev].flow -= amount;\n\t}\n\n\tCost residual_cost(const\
    \ V_id src, const V_id dst, const Edge& e) {\n\t\treturn e.cost + potential[src]\
    \ - potential[dst];\n\t}\n\n\tbool dual(const Flow delta) {\n\t\tdist.assign(n,\
    \ unreachable);\n\t\tparent.assign(n, nullptr);\n\t\texcess_vs.erase(std::remove_if(std::begin(excess_vs),\
    \ \n\t\t\t\t\t\t\t\t\t\tstd::end(excess_vs),\n\t\t\t\t\t\t\t\t\t\t[&](const V_id\
    \ v) { return b[v] < delta; }),\n\t\t\t\t\t\t\t\t\t\tstd::end(excess_vs));\n\t\
    \tdeficit_vs.erase(std::remove_if(std::begin(deficit_vs),\n\t\t\t\t\t\t\t\t\t\t\
    std::end(deficit_vs),\n\t\t\t\t\t\t\t\t\t\t[&](const V_id v) { return b[v] > -delta;\
    \ }),\n\t\t\t\t\t\t \t\t\t\tstd::end(deficit_vs));\n\t\tfor (const auto v : excess_vs)\
    \ pq.emplace(dist[v] = 0, v);\n\t\tfarthest = 0;\n\t\tstd::size_t deficit_count\
    \ = 0;\n\t\twhile (!pq.empty()) {\n\t\t\tCost d;\n\t\t\tstd::size_t u;\n\t\t\t\
    std::tie(d, u) = pq.top();\n\t\t\tpq.pop();\n\t\t\tif (dist[u] < d) continue;\n\
    \t\t\tfarthest = d;\n\t\t\tif (b[u] <= -delta) ++deficit_count;\n\t\t\tif (deficit_count\
    \ >= deficit_vs.size()) break;\n\t\t\tfor (auto& e : g[u]) {\n\t\t\t\tif (e.residual_cap()\
    \ < delta) continue;\n\t\t\t\tconst auto v = e.dst;\n\t\t\t\tconst auto new_dist\
    \ = d + residual_cost(u, v, e);\n\t\t\t\tif (new_dist >= dist[v]) continue;\n\t\
    \t\t\tpq.emplace(dist[v] = new_dist, v);\n\t\t\t\tparent[v] = &e;\n\t\t\t}\n\t\
    \t}\n\t\tpq = decltype(pq)(); // pq.clear() doesn't exist.\n\t\tfor (V_id v =\
    \ 0; v < n; ++v) {\n\t\t\tpotential[v] += std::min(dist[v], farthest);\n\t\t}\n\
    \t\treturn deficit_count > 0;\n\t}\n\n\tvoid primal(const Flow delta) {\n\t\t\
    for (const auto t : deficit_vs) {\n\t\t\tif (dist[t] > farthest) continue;\n\t\
    \t\tFlow f = -b[t];\n\t\t\tV_id v;\n\t\t\tfor (v = t; parent[v] != nullptr; v\
    \ = parent[v]->src) {\n\t\t\t\tf = std::min(f, parent[v]->residual_cap());\n\t\
    \t\t}\n\t\t\tf = std::min(f, b[v]);\n\t\t\tf -= f % delta;\n\t\t\tif (f <= 0)\
    \ continue;\n\t\t\tfor (v = t; parent[v] != nullptr;) {\n\t\t\t\tauto& e = *parent[v];\n\
    \t\t\t\tpush(e, f);\n\t\t\t\tint u = parent[v]->src;\n\t\t\t\tif (e.residual_cap()\
    \ <= 0) parent[v] = nullptr;\n\t\t\t\tv = u;\n\t\t\t}\n\t\t\tb[t] += f;\n\t\t\t\
    b[v] -= f;\n\t\t}\n\t}\n\n\tvoid saturate_negative(const Flow delta) {\n\t\texcess_vs.clear();\n\
    \t\tdeficit_vs.clear();\n\t\tfor (auto& es : g) for (auto& e : es) {\n\t\t\tFlow\
    \ rcap = e.residual_cap();\n\t\t\trcap -= rcap % delta;\n\t\t\tconst Cost rcost\
    \ = residual_cost(e.src, e.dst, e);\n\t\t\tif (rcost < 0 || rcap < 0) {\n\t\t\t\
    \tpush(e, rcap);\n\t\t\t\tb[e.src] -= rcap;\n\t\t\t\tb[e.dst] += rcap;\n\t\t\t\
    }\n\t\t}\n\t\tfor (V_id v = 0; v < n; ++v) if (b[v] != 0) {\n\t\t\t(b[v] > 0 ?\
    \ excess_vs : deficit_vs).emplace_back(v);\n\t\t}\n\t}\n\npublic:\n\tstd::pair<Status,\
    \ Cost> solve() {\n\t\tpotential.resize(n);\n\t\tFlow inf_flow = 1;\n\t\tfor (const\
    \ auto t : b)\n\t\t\tinf_flow = std::max({inf_flow, t, -t});\n\t\tfor (const auto&\
    \ es : g) for (const auto& e : es)\n\t\t\tinf_flow = std::max({inf_flow, e.residual_cap(),\
    \ -e.residual_cap()});\n\t\tFlow delta = 1;\n\t\twhile (delta < inf_flow) delta\
    \ *= SCALING_FACTOR;\n\t\tfor (; delta; delta /= SCALING_FACTOR) {\n\t\t\tsaturate_negative(delta);\n\
    \t\t\twhile (dual(delta)) primal(delta);\n\t\t}\n\t\tCost value = 0;\n\t\tfor\
    \ (const auto& es : g) for (const auto& e : es) {\n\t\t\tvalue += e.flow * e.cost;\n\
    \t\t}\n\t\tvalue /= 2;\n\t\tif (excess_vs.empty() && deficit_vs.empty()) {\n\t\
    \t\treturn { Status::OPTIMAL, value / objective };\n\t\t} else {\n\t\t\treturn\
    \ { Status::INFEASIBLE, value / objective };\n\t\t}\n\t}\n\n\tstd::vector<Cost>\
    \ get_potential() {\n\t\t// Not strictly necessary, but re-calculate potential\
    \ to bound the potential values,\n\t\t// plus make them somewhat canonical so\
    \ that it is robust for the algorithm chaneges.\n\t\tstd::fill(std::begin(potential),\
    \ std::end(potential), 0);\n\t\tfor (size_t i = 0; i < n; ++i) for (const auto&\
    \ es : g) for (const auto& e : es)\n\t\t\tif (e.residual_cap() > 0) potential[e.dst]\
    \ = std::min(potential[e.dst], potential[e.src] + e.cost);\n\t\treturn potential;\n\
    \t}\n\n\ttemplate <class T> T get_result_value() {\n\t\tT value = 0;\n\t\tfor\
    \ (const auto& es : g) for (const auto& e : es) {\n\t\t\tvalue += (T)(e.flow)\
    \ * (T)(e.cost);\n\t\t}\n\t\tvalue /= (T)2;\n\t\treturn value;\n\t}\n\t\n\tstd::vector<size_t>\
    \ get_cut() {\n\t\tstd::vector<size_t> res;\n\t\tif (excess_vs.empty()) return\
    \ res;\n\t\tfor (size_t v = 0; v < n; ++v) {\n\t\t\tif (deficit_vs.empty() ||\
    \ (dist[v] < unreachable))\n\t\t\t\tres.emplace_back(v);\n\t\t}\n\t\treturn res;\n\
    \t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/min-cost-b-flow.hpp
  requiredBy: []
  timestamp: '2021-08-20 13:03:37-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-min_cost_b_flow.test.cpp
documentation_of: library/graphs/flows/min-cost-b-flow.hpp
layout: document
redirect_from:
- /library/library/graphs/flows/min-cost-b-flow.hpp
- /library/library/graphs/flows/min-cost-b-flow.hpp.html
title: library/graphs/flows/min-cost-b-flow.hpp
---
