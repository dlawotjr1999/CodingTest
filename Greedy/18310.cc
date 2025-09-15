#include <iostream>
#include <vector>
#include <algorithm>

// 일직선 상의 특정 위치의 집에 안테나를 설치하려고 하며, 안테나는 집이 위치하는 곳에만 설치할 수 있음
// 이 때 효율성을 위해 모든 집까지의 거리의 합이 최소가 되는 위치에 안테나를 설치하려고 할 때, 그 위치를 구하는 문제

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// 집의 위치를 인덱스 순서대로 정렬한 후 그 중간 지점이 최적의 위치가 됨
	std::sort(vec.begin(), vec.end());

	std::cout << vec[(vec.size() - 1) / 2];
	return 0;
}