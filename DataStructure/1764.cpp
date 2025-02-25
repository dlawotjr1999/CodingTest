#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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