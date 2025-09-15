#include <iostream>
#include <vector>
#include <algorithm>

// 최고의 피자 : 피자 가게에서 주문할 수 있는 피자 중 1원당 열량이 가장 높은 피자
// 토핑은 여러 종류를 선택할 수 있으며, 같은 종류를 여러 번 선택할 수는 없지만 토핑을 전혀 선택하지 않는 것은 가능함
// 피자의 가격은 도우와 토핑의 가격의 합이며, 피자의 열랴은 도우와 토핑의 열량의 합
// 이 때 최고의 피자의 1원당 열량을 구하는 문제

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

	// 토핑의 열량을 오름차순으로 정렬
	// 이후 토핑을 하나씩 추가해가며 가장 높은 1원당 열량을 갱신 
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	for (int i = 0; i < N; ++i) {
		cur_kcal += vec[i];
		cur_price += B;
		max_ratio = std::max(max_ratio, cur_kcal / cur_price);
	}

	std::cout << static_cast<int>(max_ratio);
	return 0;
}