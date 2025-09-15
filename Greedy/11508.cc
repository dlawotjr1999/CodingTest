#include <iostream>
#include <vector>
#include <algorithm>

// 2+1 세일을 진행 중일 때, N개의 제품을 구매하는 데 필요한 최소 비용을 구하는 문제
// 세 개의 제품에서 가장 싼 제품을 무료로 제공하며, 한 번에 세 개의 제품을 사지 않으면 정가를 지불해야 함

int answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// 가격을 내림차순으로 정렬한 후, 이를 세 개씩 묶으면 최소 비용을 구할 수 있음
	// 한 꾸러미 내에서 가장 싼 제품이 무료로 제공됨
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	for (int i = 0; i < N; ++i) {
		if ((i + 1) % 3 == 0)
			continue;
		answer += vec[i];
	}

	std::cout << answer;
	return 0;
}