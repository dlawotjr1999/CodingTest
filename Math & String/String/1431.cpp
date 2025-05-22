#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	std::vector<std::string> vec(N);

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
		if (a.length() != b.length()) 
			return a.length() < b.length();
		else if (a.length() == b.length()) {
			int sum_a = 0, sum_b = 0;
			
			for (char c : a) {
				if (std::isdigit(static_cast<unsigned char>(c))) sum_a += (c - '0');
			}
			for (char c : b) {
				if (std::isdigit(static_cast<unsigned char>(c))) sum_b += (c - '0');
			}
			if (sum_a != sum_b)
				return sum_a < sum_b;
		}
		return a < b;
	});

	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << '\n';
	}
	return 0;
}