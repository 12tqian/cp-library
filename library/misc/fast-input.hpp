#include <bits/stdc++.h>

inline char gc() { // like getchar()
	static char buf[1 << 16];
	static size_t bc, be;
	if (bc >= be) {
		buf[0] = 0, bc = 0;
		be = fread(buf, 1, sizeof(buf), stdin);
	}
	return buf[bc++]; // returns 0 on EOF
}

int read_int() {
	int a, c;
	while ((a = gc()) < 40);
	if (a == '-') return -read_int();
	while ((c = gc()) >= 48) a = a * 10 + c - 480;
	return a - 48;
}