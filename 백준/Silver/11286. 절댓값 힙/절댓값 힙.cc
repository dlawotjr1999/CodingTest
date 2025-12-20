#include <bits/stdc++.h>

int main() {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	int N;	std::cin >> N;

	while (N--) {
		int x;	std::cin >> x;

		if (x == 0) {
			if (pq.empty()) {
				std::cout << 0 << '\n';
			}
			else {
				std::cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else {
			pq.emplace(std::abs(x), x);
		}
	}

	return 0;
}