---
title: Simplex LP Solver
documentation_of: simplex.hpp
---

## Simplex LP Solver

Solves linear programming problems using simplex method. 

## Functions
- `Simplex(A, b, c)`: Maximizes $\vec{c}^T \vec x$ given $A \vec x \leq \vec b$ and $\vec x \geq \vec 0$. Returns `INF` if there are many good solutions, and `-INF` if there is no good solution, and the maximum value otherwise. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/numerical/Misc/Simplex.h)

