#include <iostream>
#include <queue>

// n장의 카드를 아래 규칙에 맞게 합쳐나가야 함
// 1. x번 카드와 y번 카드를 골라 그 두 장에 쓰여진 수를 더한 값을 계산함 (x != y)
// 2. 계산한 값을 x번 카드와 y번 카드 두 장 모두에 덮어씀
// m번의 합체가 끝낸 뒤, n장의 카드에 쓰여있는 수의 합이 최소가 되는 값을 구하는 문제

long long result;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	// n장의 카드를 최소 힙으로 구성
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

	for (int i = 0; i < n; i++) {
		long long elm;
		std::cin >> elm;
		pq.push(elm);
	}

	while (m--) {
		// 합이 최소가 되려면 값이 가장 작은 두 장을 뽑아야 함
		// 2번 규칙에 의해 두 장의 합을 다시 힙에 삽입
		long long a = pq.top(); pq.pop();
		long long b = pq.top(); pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}

	std::cout << result;
	return 0;
}