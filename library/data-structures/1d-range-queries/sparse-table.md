---
title: Sparse Table
documentation_of: sparse-table.hpp
---

## Sparse Table

Unfortunately, I'm not sure how to template this to do $\max$ also since you have to access `v`. This can't be modified for "destrutive combinations" like $\gcd$. 

### Assumptions
- $0$-indexed. 

### Functions
- `comb(a, b)`: You can modify this for different combinations, right now it's set to get the $min$ of elements at indices $a, b$ with tie broken by the minimum index. 
- `index(l, r)`: Gets index of `min` element in range $[l, r]$. 
- `query(l, r)`: Gets minimum element in range $[l, r]$. 

