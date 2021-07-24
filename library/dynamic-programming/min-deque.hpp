#pragma once

template <class T> struct MinDeque {
	int lo = 0, hi = -1;

	std::deque<std::pair<T, int>> d;
	void ins(T x) { // add to back
		while ((int)d.size() && d.back().first >= x) d.pop_back();
		d.push_back({x, ++hi});
	}

	void del() { // delete from front
		if (d.front().second == lo++) d.pop_front();
	}

	T get() {
		return (int)d.size() ? d.front().first : std::numeric_limits<T>::max();
	}
};
