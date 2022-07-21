---
title: Hungarian Algorithm
documentation_of: hungarian.hpp
---

## Hungarian Algorithm

### Assumptions
- $0$-indexed

### Functions
- `hungarian(a)`: Solves the problem if `a[i][j]` indicates the `i`th job's cost for the `j`th worker. Returns the cost and the assignment. 
	- `job` ends up storing the job each worker gets assign. 
	- Works in $\mathcal O(N^2 M)$. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Matching/Hungarian.h)