#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> vec(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> vec[i];
		vec[i] += vec[i - 1];
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		std::cin >> a >> b;

		std::cout << vec[b] - vec[a - 1] << '\n';
	}

	return 0;
}