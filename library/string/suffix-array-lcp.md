---
title: Suffix Array with Longest Common Prefix
documentation_of: suffix-array-lcp.hpp
---

## Suffix Array with Longest Common Prefix

### Assumptions
- We assume that we only use latin letters from `'a'` to `'z'`. This can be modified in `generate_suffix_array`. 
- We $0$-index things. 

### Functions
- `generate_suffix_array(s)`: Generates suffix array of string $s$ in $\mathcal O(n)$.
- `generate_lcp_array`: Generates longest common prefix array in $\mathcal O(n \log n)$, must be called after `generate_suffix_array`.
- `get_lcp(int a, int b)`: Gets the longest common prefix between the suffixes starting at $a$ and $b$, assuming lcp array is already generated.

### Variables
- `sa`: Stores the indices of the sorted suffixes.
- `isa`: Inverse of `sa`. 
- `lcp`: Longest commmon prefix between consecutive elements. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/strings%20(14)/Light/SuffixArrayLinear.h)