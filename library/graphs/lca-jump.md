---
title: LCA Jump
documentation_of: lca-jump.hpp
---

## LCA Jump

### Functions
- `init(n)`: Initializes variables
- `gen(root)`: Generates from $root$, can easily change to vector for forests. Just repeat `gen`$ for each root. Does this in $\mathcal O(n \log (n))$.
- `jump(x, d)`: Jump $d$ upwards from node $x$ in $\mathcal O(\log n)$. 
- `lca(x, y)`: Lowest common ancestor of $x, y$ in $\mathcal O(\log n)$. 

