#include <bits/stdc++.h>

// 1. 배열에 자연수를 넣는 연산
// 2. 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하되, 절댓값이 가장 작은 값이 여러 개일 때는 가장 작은 수를 출력하고, 그 값을 배열에서 제거
// 위 두 가지 연산을 지원하는 '절댓값 힙'을 구현하는 문제

int main() {
	// (절댓값 x, x)를 순서쌍으로 하는 최소 힙 선언
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	int N;	std::cin >> N;

	while (N--) {
		int x;	std::cin >> x;

		// 0을 입력했을 때 pq가 비어있으면 0을, 그렇지 않은 경우 가장 작은 값을 출력하고 pop
		// 출력 시 절댓값이 가장 작은 수를 출력
		if (x == 0) {
			if (pq.empty()) {
				std::cout << 0 << '\n';
			}
			else {
				std::cout << pq.top().second << '\n';
				pq.pop();
			}
		}

		// 0이 아닌 값을 입력했을 때는 (절댓값 x, x)를 push
		else {
			pq.emplace(std::abs(x), x);
		}
	}

	return 0;
}