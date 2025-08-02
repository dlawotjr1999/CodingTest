#include <iostream>
#include <vector>

// 캐릭터들의 전투력 수치를 기반으로 칭호를 붙여주려고 함
// 예를 들어, 전투력 10000 이하의 캐릭터는 WEAK, 10000 초과 그리고 100000 이하의 캐릭터는 NORMAL, 100000 초과 그리고 1000000 이하의 캐릭터는 STRONG 칭호를 붙임
// 이 때, 캐릭터의 전투력에 맞는 칭호를 대응시켜 구하는 문제

// 이분 탐색을 통해 전투력에 맞는 칭호를 찾음(lower_bound 방식)
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

	// 문제에서, 칭호는 비내림차순으로 주어지기 때문에(오름차순으로 주어짐) 정렬을 수행하지 않아도 됨
	for (int i = 0; i < M; ++i) {
		std::cout << binary_search(vec, values[i]) << '\n';
	}

	return 0;
}