---
title: Line Container
documentation_of: line-container.md
---

## Line Container

This is currently modified for minimums. To modify for maximums, comment the first line in `add_line` and get rid of the negative of the `return` statement in `query`. 

This implementation is also blazingly fast for some reason, performs almost like constant time per operation. 

### Functions
- `add_line(k, m)`: Adds a line with slope $k$ and $y$-intercept $m$. 
- `query(x)`: Finds minimum of lines at location $x$. 

### Resources
- [KACTL](https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h)