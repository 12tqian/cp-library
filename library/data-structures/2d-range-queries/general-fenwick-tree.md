---
title: General Fenwick Tree
documentation_of: general-fenwick-tree.hpp
---

## General Fenwick Tree

Multidimensional Fenwick Tree. 

### Assumptions
- $1$-indexed. 

### Functions
- `upd(pos, ...)`: Update at location of coordinates in $\mathcal O(\log(n)^d).
- `query(l, r, ...)`: Query in "rectangular" region in $\mathcal O(\log(n)^d).

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/data-structures/1D%20Range%20Queries%20(9.2)/BitNd.h)
