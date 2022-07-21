---
title: Formal Power Series
documentation_of: polynomial.hpp
---

## Formal Power Series

I will abbrivate formal power series as FPS.

**Beware** of polynomial division versus inverse, they are two different things!

We support many different operations, so theoretically you can treat this similarly to the way you would treat `int`. 

Note that for convolution things, we have a small degree cutoff of `60`, since straight multiplication would be faster if the degree of one of the polynomials is small enough. Also, this currently supports operations under mod `998244353`, if you want to use another mod that is not NTT friendly, you would probably have to use my other FFT implementation, and modify the multiply function. This shouldn't be that hard I think. 

There is also a function to print using `ostream`, but I'm not sure how useful this actual is. 

If you want to implement more functions, Euler's method can probably be used. Check the cp-algorithms link in resources for more information. 

### Functions
- `pre(n)`: Returns first `n` elements in $\mathcal O(n)$.
- `diff()`: Returns integral of FPS in $\mathcal O(n)$.
- `inte()`: Returns integral of FPS in $\mathcal O(n)$. 
- `exp(n)`: Returns $e^{p(x)}$ modulo $x^n$ in $\mathcal O(n \log n)$. 
- `log(n)`: Returns $\log p(x)$ module $x^n$ in $\mathcal O(n \log n)$. 
- `pow_mod(mod, n)`: Returns $p^n$ modulo the polynomial `mod` in $\mathcal O(n \log n \log k)$ using binary exponentiation.
- `pow(k, n)`: Returns $p^k$ modulo $x^n$ in $\mathcal O(n \log(nk))$. 


### Resources
- [Yosupo](http://yosupo06.github.io/Algorithm/src/math/poly.hpp)
- [Nyaan](https://nyaannyaan.github.io/library/fps/formal-power-series.hpp)
- [cp-algorithms](https://cp-algorithms.com/algebra/polynomial.html)
