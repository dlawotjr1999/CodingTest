#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// map을 활용하여 두 번의 입력에서 중복된 값이 있는지를 검토하는 문제
int main() {
	int N, M;
	std::unordered_map<std::string, int> map;
	std::vector<std::string> vec;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string n;
		std::cin >> n;
		map.emplace(n, 1);
	}

	for (int j = 0; j < M; j++) {
		std::string m;
		std::cin >> m;

		if (map.find(m) != map.end())
			vec.emplace_back(m);
	}

	std::sort(vec.begin(), vec.end());

	std::cout << vec.size() << std::endl;
	for (auto& name : vec)
		std::cout << name << std::endl;
}

// 다르게 접근한 소스코드(단순성과 메모리 효율성에서 유리하지만, 퍼포먼스는 좀 더 불리함)
/* int main() {
	int N, M;
	int cnt = 0;
	std::map<std::string, int> map;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string n;
		std::cin >> n;
		map[n]++;
	}

	for (int j = 0; j < M; j++) {
		std::string m;
		std::cin >> m;

		if (map.find(m) != map.end()) {
			cnt++;
		}
		map[m]++;
	}

	std::cout << cnt << std::endl;
	for (auto& elm : map) {
		if (elm.second > 1) {
			std::cout << elm.first << std::endl;
		}
	}
} */