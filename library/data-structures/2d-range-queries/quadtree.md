---
title: Quadtree
documentation_of: quadtree.hpp
---

## Quadtree

This is a pretty scuffed data structure, it sometimes works in time (like [here](http://www.usaco.org/index.php?page=viewproblem2&cpid=1094)). 

### Assumptions
- $x, y \in [0, N)$

### Functions
- `upd(x, y, inc)`: Updates at location `(x, y)` with $inc$ in $\mathcal O(\log(n))$. 

- `query(qx1, qy1, qx2, qy2)`: Queries in rectangle with corners `(qx1, qy1), (qx2, qy2)` in $\mathcal O(N)$ in worst case.  
