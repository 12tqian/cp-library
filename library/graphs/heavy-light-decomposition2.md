---
title: Old Heavy Light Decomposition
documentation_of: heavy-light-decomposition2.hpp
---

## Old Heavy Light Decomposition

This uses my old lazy segment tree implementation, but it's still worth keeping around. 

### Functions
- `init(graph, r)`: Initializes with a graph $graph$ and a root $r$. You can easily change $r$ to a vector of roots and DFS each of them to support a forest. 
- `modify_path(u, v)`: Modifies path from $u$ to $v$. 
- `query_path(u, v)`: Queries path from $u$ to $v$. 

### Variables
- `VALUES_IN_VERTICES`: Set `true` if you want values in vertices, `false` if in edges. 

