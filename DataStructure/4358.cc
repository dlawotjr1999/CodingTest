#include <iostream>
#include <map>
#include <string>
#include <iomanip>

// 나무의 이름들이 주어질 때, 한 나무가 전체 나무들에서 몇 %를 차지하는 지 구하는 문제

int main() {
	int total = 0;
	std::map<std::string, int> map;

	// EOF를 만날 때까지 입력을 받을 수 있으며, 공백이 입력될 수 있으므로 getline을 통해 입력
	std::string name;
	while (getline(std::cin, name)) {
		map[name]++;
		total++;
	}

	// 소수점 4째자리까지 반올림하여 출력
	std::cout << std::fixed;
	std::cout.precision(4);
	for (const auto& [name, cnt] : map) {
		// 100.0을 먼저 곱합으로써 형 변환을 진행함
		std::cout << name << " " << (cnt * 100.0 / total) << '\n';
	}

	return 0;
}