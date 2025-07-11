#include <iostream>
#include <vector>

inline std::string binary_search(const std::vector<std::pair<std::string, int>>& vec, int value) {
	int start = 0; int end = vec.size() - 1;

	while (start < end) {
		int mid = (start + end) / 2;

		if (value <= vec[mid].second)
			end = mid;
		else
			start = mid + 1;
	}

	return vec[start].first;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::pair<std::string, int>> vec;
	std::vector<int> values;

	for (int i = 0; i < N; ++i) {
		std::string type; int value;

		std::cin >> type >> value;
		vec.emplace_back(type, value);
	}

	for (int i = 0; i < M; ++i) {
		int value; std::cin >> value;
		values.emplace_back(value);
	}

	for (int i = 0; i < M; ++i) {
		std::cout << binary_search(vec, values[i]) << '\n';
	}

	return 0;
}