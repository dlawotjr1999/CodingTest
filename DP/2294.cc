#include <iostream>
#include <vector>

// n개의 동전들로 k원을 만들고자 하며, 각각의 동전은 몇 개라도 사용할 수 있음
// 이 때, k원을 만들 수 있는 최소 동전 갯수를 구하는 문제

const int INF = 1e8;

int DP[10001];

int main() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> vec(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> vec[i];
	}
	std::fill(DP, DP + 1 + k, INF);
	DP[0] = 0;

	// 동전을 몇 개라도 사용할 수 있으므로, 무한 배낭 문제처럼 내부 for문을 증가로 설정
	for (int i = 1; i <= n; ++i) {
		for (int j = vec[i]; j <= k; ++j) {
			DP[j] = std::min(DP[j], DP[j - vec[i]] + 1);
		}
	}

	std::cout << (DP[k] != INF ? DP[k] : -1);
	return 0;
}