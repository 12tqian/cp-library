#include<bits/stdc++.h>

template <int SZ> struct Sieve {
	int spf[SZ];
	
	Sieve() {
		spf[1] = 1;
		for (int i = 2; i < SZ; i++) 
			spf[i] = i;
		for (int i = 4; i < SZ; i += 2) 
			spf[i] = 2;
		for (int i = 3; i * i < SZ; i++) 
			if (spf[i] == i) 
				for (int j = i * i; j < SZ; j += i) 
					if (spf[j] == j) 
						spf[j] = i;
	}

	std::vector<std::pair<int, int>> factor(int x) {
		std::vector<std::pair<int, int>> ret;
		while (x != 1) {
			if ((int)ret.size() == 0) 
				ret.emplace_back(spf[x], 1);
			else {
				if (ret.back().first == spf[x]) 
					ret.back().second++;
				else 
					ret.emplace_back(spf[x], 1);
			}
			x /= spf[x];
		}
		return ret;
	}
};

int main() {
	return 0;
}