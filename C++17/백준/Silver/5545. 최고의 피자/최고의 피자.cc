#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, A, B, C;
	std::cin >> N;
	std::cin >> A >> B;
	std::cin >> C;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	double cur_kcal = C;
	double cur_price = A;
	double max_ratio = cur_kcal / cur_price;

	std::sort(vec.begin(), vec.end(), std::greater<int>());
	for (int i = 0; i < N; ++i) {
		cur_kcal += vec[i];
		cur_price += B;
		max_ratio = std::max(max_ratio, cur_kcal / cur_price);
	}

	std::cout << static_cast<int>(max_ratio);
	return 0;
}