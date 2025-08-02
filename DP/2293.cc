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

	// 동전의 수만큼 반복(모든 동전을 탐색)
	for (int i = 0; i < n; ++i) {
		// 현재 동전을 활용하여 만들 수 있는 금액들을 확인
		// coin[i] 미만의 금액은 coin[i]로 만들 수 없으므로 coin[i]부터 탐색
		for (int j = coin[i]; j <= k; ++j) {
			DP[j] = DP[j] + DP[j - coin[i]];
		}
	}
	std::cout << DP[k];

	return 0;
}