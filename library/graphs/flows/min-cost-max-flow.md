---
title: Minimum Cost Maximum Flow
documentation_of: min-cost-max-flow.hpp
---

## Minimum Cost Maximum Flow

### Functions
- `calc(s, t)`: Calculates maximum flow from `s` to `t`, returning a pair of the flow and the cost. 

### Variables
- `edges`: After calling `calc`, this holds the amount of flow through each edge, which lets us recover stuff. To obtain original edges, assign ID's in `ae`. 
	
### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Flows%20(12.3)/MCMF.h)

