#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, elm;
	float result = 0;
	std::vector<float> vec;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> elm;
		vec.push_back(elm);
	}
	float max = *std::max_element(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		vec[i] = (vec[i] / max) * 100.0f;
		result += vec[i];
	}

	result /= N;
	std::cout << result;

	return 0;
}