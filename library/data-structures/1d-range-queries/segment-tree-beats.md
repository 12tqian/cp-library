---
title: Segment Tree Beats
documentation_of: segment-tree-beats.hpp
---

## Segment Tree Beats

Works by some spooky tag magic, no clue about the details. 

### Assumptions
- $0$-indexed. 

### Functions
All functions work in $\mathcal O(\log(n))$. 
- `upd(t, lo, hi, b)`: If $t = 0$, the update is `ckmin`, $t = 1$, it's `ckmax`, $t = 2$, it's `range_add`. 
- `qsum(l, r)`: Sum of elements in $[l, r]$. 
- `qmin(l, r)`: Min of elements in $[l, r]$. 
- `qmax(l, r)`: Max of elements in $[l, r]$. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/data-structures/1D%20Range%20Queries%20(9.2)/SegTreeBeats.h)