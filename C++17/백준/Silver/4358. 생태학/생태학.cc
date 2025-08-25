#include <iostream>
#include <map>
#include <string>
#include <iomanip>

int main() {
	int total = 0;
	std::map<std::string, int> map;

	std::string name;
	while (getline(std::cin, name)) {
		map[name]++;
		total++;
	}

	std::cout << std::fixed;
	std::cout.precision(4);
	for (const auto& [name, cnt] : map) {
		std::cout << name << " " << (cnt * 100.0 / total) << '\n';
	}

	return 0;
}