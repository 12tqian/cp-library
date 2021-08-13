---
title: LCA RMQ
documentation_of: lca-rmq.hpp
---

## LCA RMQ

### Functions
- `init(n)`: Initializes variables
- `gen(root)`: Generates from $root$, can easily change to vector for forests. Just repeat `gen` for each root in $\mathcal O(n \log (n))$. 
- `is_ancestor(anc, src)`: Checks if $anc$ is ancestor of $src$ in $\mathcal O(1)$. 
- `lca(x, y)`: Lowest common ancestor of $x, y$ in $\mathcal O(1)$. 
- `compress(nodes)`: Tree compression of nodes. 
	- It returns a list of (parent, original index). 
	- Parent is the parent of the node in the compressed tree.
	- Original index is the node it represents in the origial tree. 
	- Works in $\mathcal O(S \log (S))$ if $nodes$ is of size $S$. 
- `get_child(anc, src)`: Returns the child of $anc$ whose subtree contains $src$ in $\mathcal O(1)$. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Trees%20(10)/LCArmq%20(10.2).h)
