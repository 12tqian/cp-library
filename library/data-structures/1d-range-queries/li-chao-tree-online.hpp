#pragma once

// Currently set to get the max of things, use negatives for minimum

struct Line {
	int k; long long m;

	Line(int _k, long long _m) { k = _k, m = _m; }
	Line() : Line(0, std::numeric_limits<long long>::min()) { }

	long long get(long long x) { return k * x + m; }

	bool majorize(Line X, long long L, long long R) { 
		return get(L) >= X.get(L) && get(R) >= X.get(R); 
	}
};

struct Node {
	Node *c[2]; Line S;

	Node() { c[0] = c[1] = NULL; S = Line(); }
	~Node() { for (int i = 0; i < 2; i++) delete c[i]; }

	void mc(int i) { if (!c[i]) c[i] = new Node(); }
	long long mid(long long x) { return x & 1 ? (x - 1) / 2 : x / 2; }

	long long query(long long X, long long L, long long R) {
		long long ans = S.get(X);
		long long M = mid(L + R);
		if (X <= M) {
			if (c[0]) ans = std::max(ans, c[0]->query(X, L, M));
		} else {
			if (c[1]) ans = std::max(ans, c[1]->query(X, M + 1, R));
		}
		return ans;
	}

	void modify(Line X, long long L, long long R) {
		if (X.majorize(S, L, R)) std::swap(X, S);
		if (S.majorize(X, L, R)) return;
		if (S.get(L) < X.get(L)) std::swap(X, S);
		long long M = mid(L + R);
		if (X.get(M) >= S.get(M)) std::swap(X, S), mc(0), c[0]->modify(X, L, M);
		else mc(1), c[1]->modify(X, M + 1, R);
	}
	
	void upd(Line X, long long lo, long long hi, long long L, long long R) {
		if (R < lo || hi < L) return;
		if (lo <= L && R <= hi) return modify(X, L, R);
		long long M = mid(L + R);
		if (lo <= M) mc(0), c[0]->upd(X, lo, hi, L, M);
		if (hi > M) mc(1), c[1]->upd(X, lo, hi, M + 1, R);
	}
};

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	const int INF = 1e9;
	int n, q; cin >> n >> q;
	Node L;
	for (int i = 0; i < n; i++) {
		int l, r, a; long long b;
		cin >> l >> r >> a >> b;
		L.upd({-a, -b}, l, r - 1, -INF, INF);
	}
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 0) {
			int l, r, a; long long b; 
			cin >> l >> r >> a >> b;
			L.upd({-a, -b}, l, r - 1, -INF, INF);
		} else {
			int p; cin >> p;
			long long ans = L.query(p, -INF, INF);
			if (ans == numeric_limits<long long>::min()) {
				cout << "INFINITY" << '\n';
			} else {
				cout << -ans << '\n';
			}
		}
	}
	return 0;
}