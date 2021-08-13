---
title: Bellman Ford
documentation_of: bellman-ford.hpp
---

## Bellman Ford 
 
Works in $\mathcal O(VE)$ for $V$ vertices and $E$ edges. Note that `negative_cycle` is the same as `gen`, but it doesn't call `gen_bad`$. 

### Functions
- `init(n)`: Initializes the variables. 
- `gen(src)`: Generates distances from $src$. 
- `negative_cycle(src)`$: Finds a negative cycle if it exists. If it doesn't, this returns an empty list. 

### Variables
- `dist`: Stores distances to each vertex. It's infinity if you can't reach it and negative infinity if you have a negative cycle. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Basics/BellmanFord%20(7.3).h)

