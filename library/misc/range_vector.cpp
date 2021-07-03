#include <bits/stdc++.h> 

template <class T> class range_vector : public std::vector<T> {
public:
	int min_index;

	range_vector() : min_index(0) {}

	range_vector(int _min_index, int _max_index, T&& values = T())
		: std::vector<T>(_max_index - _min_index + 1, values), min_index(_min_index) {
		assert(_min_index <= _max_index + 1);
	}
	
	range_vector(int _max_index, T&& values = T())
		: std::vector<T>(_max_index + 1, values), min_index(0) {
		assert(0 <= _max_index + 1);
	}
	
	T& operator[](int i) { std::vector<T>& self = *this; return self[i - min_index]; }
};
