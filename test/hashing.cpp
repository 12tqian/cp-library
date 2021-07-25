#define IGNORE

#include "../library/contest/template-minimal.hpp"
#include "../library/string/hashing.hpp"

int main() {
	using namespace std;
	using namespace Hashing;
	HashRange H;
	H.add("ababab");
	for (int i = 0; i < 6; i++) 
		for (int j = i; j < 6; j++) {
			auto val = H.hash(i, j);
			cout << i << " " << j << " " << val[0] << " " << val[1] << '\n';
		}
}