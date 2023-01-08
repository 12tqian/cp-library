#pragma once

template <class T>
struct FenwickTree {
  std::vector<T> fwt;
  int n;

  FenwickTree() = default;
  FenwickTree(int n) { init(n); }
  FenwickTree(std::vector<T>& a) { init(a); }

  void init(int n_) {
    n = n_;
    fwt.assign(n, 0);
  }

  void init(std::vector<T>& a) {
    n = (int)a.size();
    fwt.assign(n, 0);
    for (int i = 0; i < (int)a.size(); i++) {
      add(i, a[i]);
    }
  }

  T sum(int r) {
    T ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += fwt[r];
    return ret;
  }

  T query(int l, int r) { return sum(r) - sum(l - 1); }

  void add(int idx, T delta) {
    for (; idx < n; idx = idx | (idx + 1)) fwt[idx] += delta;
  }
};