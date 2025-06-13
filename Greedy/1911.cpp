#include <iostream>
#include <vector>
#include <algorithm>

// 비연속적인 물웅덩이들을 덮기 위해 필요한 널빤지들의 최소 갯수를 구하는 문제
// 위치가 10억 이하의 정수이기 때문에, 벡터나 배열이 아닌 pair을 이용한 구간을 활용하여 계산

int N, L;
std::vector<std::pair<int, int>> puddles;

int main() {
	std::cin >> N >> L;
	puddles.resize(N);

	for (int i = 0; i < N; i++) {
		std::cin >> puddles[i].first >> puddles[i].second;
	}

	// 오름차순 정렬을 수행한 후 계산
	std::sort(puddles.begin(), puddles.end());

	int current = 0;
	int count = 0;

	// 각 구간에 대해서 수행
	for (auto [start, end] : puddles) {
		// 현재까지 덮어진 널빤지가 다음 웅덩이의 시작점보다 앞에 있으면 현재 웅덩이의 시작점으로 이동
		if (current < start)
			current = start;

		// 한 구간에 대해서 널빤지를 하나씩 이용하여 물웅덩이를 덮음
		while (current < end) {
			current += L;
			count++;
		}
	}

	std::cout << count;

	return 0;
}