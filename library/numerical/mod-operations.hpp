#pragma once

namespace ModOperations {

const int MOD = 1e9 + 7;

int mpow(long long b, long long e) {
	long long r = 1;
	while (e) {
		if (e & 1) {
			r *= b; 
			r %= MOD;
		}
		b *= b; 
		b %= MOD;
		e >>= 1;
	}
	return r;
}

int minv(int a) { assert(a); return mpow(a, MOD - 2); }
int add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += MOD; return a; }
int mul(int a, int b) { return 1LL * a * b % MOD; }
int divi(int a, int b) { return mul(a, minv(b)); }
int neg(int a) { return a == 0 ? 0 : MOD - a; }
int mod(long long v) { 
	v = int((-MOD < v && v < MOD) ? v : v % MOD); if (v < 0) v += MOD; return v; }
	
int madd(int &a, int b) { return a = add(a, b); }
int msub(int &a, int b) { return a = sub(a, b); }
int mmul(int &a, int b) { return a = mul(a, b); }
int mdivi(int &a, int b) { return a = divi(a, b); }

} // ModOperations

