#include <iostream>

// n가지 종류의 동전이 있을 때, 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하는 경우의 수를 구하는 문제
// 각각의 동전은 몇 개라도 사용할 수 있으며, 사용한 동전의 구성이 같지만 순서만 다른 것은 같은 경우임

int n, k;

int coin[101];
int DP[10001];

int main() {
	std::cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		std::cin >> coin[i];
	}

	DP[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = coin[i]; j <= k; ++j) {
			DP[j] = DP[j] + DP[j - coin[i]];
		}
	}
	std::cout << DP[k];

	return 0;
}