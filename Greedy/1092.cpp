#include <iostream>
#include <vector>
#include <algorithm>

int minute;

int main() {
	int N, M;
	std::cin >> N;
	std::vector<int> crains(N);

	for (int i = 0; i < N; i++) {
		std::cin >> crains[i];
	}

	std::cin >> M;
	std::vector<int> items(M);

	for (int i = 0; i < M; i++) {
		std::cin >> items[i];
	}

	std::sort(crains.rbegin(), crains.rend());
	std::sort(items.rbegin(), items.rend());

	if (crains[0] < items[0]) {
		std::cout << -1;
		return 0;
	}

	int moved = 0;
	while (moved < M) {
		int idx = 0;

		for (int i = 0; i < N; i++) {
			while (idx < M) {
				if (items[idx] != -1 && crains[i] >= items[idx]) {
					items[idx] = -1;
					moved++; idx++;
					break;
				}
				idx++;
			}
		}
		minute++;
	}
	std::cout << minute;

	return 0;
}