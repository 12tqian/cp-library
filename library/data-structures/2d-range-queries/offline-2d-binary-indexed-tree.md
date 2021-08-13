---
title: Offline 2D BIT
documentation_of: offline-2d-binary-indexed-tree.hpp
---

## Offline 2D BIT

This works decently fast, requires you to know locations of all updates first though. 

### Assumptions
- $x, y \in [0, sz)$

### Functions
- `update(x, y, t)`: Updates at location $(x, y)$ with $t$. Call first to store locations, and again later for actual updates. 
- `init(sz)`: Needs to be called after all updates have been called. 
- `query(xl, xr, yl, yr)`: Queries in bounds $x \in [xl, xr], y \in [yl, yr]$. 


### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/data-structures/2D%20Range%20Queries%20(15.2)/BIT2DOff%20(15.2).h)