#include <bits/stdc++.h>

/**
 * Handles point update in log(n), and query in log(n)^2
 */

template <class T, int N, int M> struct QuadTree {
    T sm[16 * N * M];

    QuadTree() { memset(sm, 0, sizeof(sm)); }

    void upd(int x, int y, T inc, int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1, int y2 = M - 1) {
        if (x1 == x2 && y1 == y2) 
            sm[n] = inc;
        else {
            int xm = (x1 + x2) >> 1;
            int ym = (y1 + y2) >> 1;
            if (x <= xm && y <= ym) 
                upd(x, y, inc, 4 * n, x1, y1, xm, ym);
            else if (x <= xm && y > ym) 
                upd(x, y, inc, 4 * n + 1, x1, ym + 1, xm, y2);
            else if (x > xm && y > ym) 
                upd(x, y, inc, 4 * n + 2, xm + 1, ym + 1, x2, y2);
            else 
                upd(x, y, inc, 4 * n + 3, xm + 1, y1, x2, ym);
            sm[n] = sm[4 * n] + sm[4 * n + 1] + sm[4 * n + 2] + sm[4 * n + 3];
        }
    }

    T query(int qx1, int qy1, int qx2, int qy2, int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1, int y2 = M - 1) {
        if (qx2 < x1 || qy1 > y2 || qx1 > x2 || qy2 < y1) 
            return 0;
        else if (qx1 <= x1 && x2 <= qx2 && qy1 <= y1 && y2 <= qy2) 
            return sm[n];
        int xm = (x1 + x2) >> 1;
        int ym = (y1 + y2) >> 1;
        return query(qx1, qy1, qx2, qy2, 4 * n, x1, y1, xm, ym) 
                + query(qx1, qy1, qx2, qy2, 4 * n + 1, x1, ym + 1, xm, y2) 
                + query(qx1, qy1, qx2, qy2, 4 * n + 2, xm + 1, ym + 1, x2, y2) 
                + query(qx1, qy1, qx2, qy2, 4 * n + 3, xm + 1, y1, x2, ym);
    }
};