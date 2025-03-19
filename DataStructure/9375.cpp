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

		// 착용할 수 있는 의상의 종류만을 고려함
		for (int j = 0; j < num; j++) {
			std::string s1, s2;
			std::cin >> s1 >> s2;
			map[s2]++;
		}

		int result = 1;

		// 의상들이 있을 때 미착용인 경우도 있으므로 +1을 하여 경우의 수를 구한다
		// 예를 들어 (headgear, 2)와 (eyewear, 1)가 있을 때 
		// (미착용, headgear1, headgear2)와 (미착용, eyewear1)의 경우의 수가 있고, 가능한 조합의 수는 3 * 2 = 6가지이다
		// (미착용, 미착용)인 경우는 빼야하므로 결괏값에서 1을 빼야한다

		for (auto& m : map)
			result *= (m.second + 1);
		std::cout << result - 1 << std::endl;
	}
}