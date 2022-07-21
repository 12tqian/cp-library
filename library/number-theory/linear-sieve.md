---
title: Linear Sieve
documentation_of: linear-sieve.hpp
---

## Linear Sieve

Computes all the primes less than $N$ in $\mathcal O(N)$ time. 

The way it works is it crosses out composite numbers exactly once by checking by smallest prime factors. In this manner, it is possible to compute multiplicative functions for all $N$ in a range in linear time, as shown in the CF blog post under resources.

### Resources
- [Codeforces](https://codeforces.com/blog/entry/54090)
