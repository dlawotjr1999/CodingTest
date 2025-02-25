#include <iostream>
#include <unordered_map>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		std::unordered_map<std::string, int> map;

		std::cin >> num;
		for (int j = 0; j < num; j++) {
			std::string s1, s2;
			std::cin >> s1 >> s2;
			map[s2]++;
		}

		int result = 1;

		for (auto& m : map)
			result *= (m.second + 1);
		std::cout << result - 1 << std::endl;
	}
}