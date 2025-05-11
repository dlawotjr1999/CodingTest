#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// 들어보지 못한 사람들과 보지 못한 사람들이 주어질 때, 듣도 보지 못한 사람을 구하는 문제

int main() {
	int N, M;
	std::unordered_map<std::string, int> map;
	std::vector<std::string> vec;

	std::cin >> N >> M;

	// 들어보지 못한 사람을 map에 삽입
	for (int i = 0; i < N; i++) {
		std::string n;
		std::cin >> n;
		map.emplace(n, 1);
	}

	// 보지 못한 사람을 입력
	for (int j = 0; j < M; j++) {
		std::string m;
		std::cin >> m;

		// 보지 못한 사람이 map에서 탐색되면 vector에 삽입
		if (map.find(m) != map.end())
			vec.emplace_back(m);
	}

	// 사전식 배치를 위한 정렬
	std::sort(vec.begin(), vec.end());

	std::cout << vec.size() << std::endl;
	for (auto& name : vec)
		std::cout << name << std::endl;
}