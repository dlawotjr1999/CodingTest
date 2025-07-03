#include <iostream>
#include <vector>
#include <queue>

int main() {
	int N;
	std::cin >> N;

	std::queue<std::pair<int, int>> q;
	std::vector<int> vec(N, 0);

	for (int i = 0; i < N; ++i) {
		int num;
		std::cin >> num;
		q.emplace(num, i);
	}

	int time = 0;
	while (!q.empty()) {
		auto [piece, idx] = q.front();
		piece--;
		time++;

		q.pop();

		if (piece == 0) {
			vec[idx] = time;
		}
		else {
			q.emplace(piece, idx);
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << ' ';
	}
	return 0;
}