---
title: Monotonic Convex Hull Trick
documentation_of: monotonic-convex-hull.hpp
---

## Monotonic Convex Hull Trick

I should make this general for not just `long long`. 

### Assumptions
- Currently asssumes we're answering minimum queries. This can be changed with negative signs. 
- Also currently assumes the queries are in increasing order. You can flip this by changing $ord$ to $1$ or $-1$. 
- Assumes you add lines in monotonic slope order. 

### Functions
- `add(a, b)`: Adds line to hull with slope $a$ and $y$-intercept $b$ in $\mathcal O(1)$. 
- `query(x)`: Finds minimum at $x$ in $\mathcal O(1)$. 

### Variables
- `ord`: determines whether queries are in increasing or decreasing order. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/data-structures/STL%20(5)/LCDeque.h)