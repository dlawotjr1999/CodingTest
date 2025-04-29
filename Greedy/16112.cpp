#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> stones;
long long xp;

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); 
	std::cout.tie(0);

	long long n, k;
	std::cin >> n >> k;

	stones.resize(n);
	for (long long& stone : stones) {
		std::cin >> stone;
	}

	std::sort(stones.begin(), stones.end());

	for (long long i = 1; i < stones.size(); i++) {
		long long temp = stones[i] * std::min(i, k);
		xp += temp;
	}

	std::cout << xp;

	return 0;
}