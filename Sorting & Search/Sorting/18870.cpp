#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	std::vector<long long> vec;
	std::map<long long, long long> map;

	for (int i = 0; i < N; i++) {
		int elm;
		std::cin >> elm;

		vec.push_back(elm);
		map.insert({ vec[i], 0 });
	}

	int i = 0;
	for (auto& elm : map) {
		elm.second = i++;
	}

	for (auto& idx : vec) {
		std::cout << map[idx] << " ";
	}

	return 0;
}