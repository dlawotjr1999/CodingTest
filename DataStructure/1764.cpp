#include <iostream>
#include <map>
#include <algorithm>

int main() {
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
}