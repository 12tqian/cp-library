---
title: Suffix Array
documentation_of: suffix-array-lcp.hpp
---

## Suffix Array 

We assume we only use latin letters from `'a'` to `'z'`. This can be modified in `generate_suffix_array`. 

### Functions
- `generate_suffix_array(s)`: generates suffix array of string `s` in $\mathcal O(n)$
- `generate_lcp_array`: generates longest common prefix array in $\mathcal O(n \log n)$, must be called after `generate_suffix_array`,
- `get_lcp(int a, int b)`: gets the longest common prefix between the suffixes starting at `a` and `b`, assuming lcp array is already generated