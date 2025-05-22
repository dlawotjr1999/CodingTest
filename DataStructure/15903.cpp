#include <iostream>
#include <queue>

long long result;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

	for (int i = 0; i < n; i++) {
		long long elm;
		std::cin >> elm;
		pq.push(elm);
	}

	while (m--) {
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