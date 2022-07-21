#pragma once

template <int N> struct LinearSieve {
	std::bitset<N> pri;
	std::vector<int> pr;
	
	LinearSieve() {
		pri.set();
		pri[0] = pri[1] = 0;
		for (int i = 2; i < N; ++i) {
			if (pri[i]) 
				pr.push_back(i);
			for (int j = 0; j < (int)pr.size() && i * pr[j] < N; ++j) {
				pri[i * pr[j]] = 0;
				if (i % pr[j] == 0) 
					break;
			}
		}
	}
};