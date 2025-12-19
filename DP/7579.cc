#include <iostream>
#include <vector>

// N개의 앱들 중 몇 개를 비활성화하여 M 이상의 메모리를 추가로 확보하고자 함
// 그 앱들을 비활성화 했을 경우의 비용의 합을 최소화하여 필요한 메모리 M 바이트를 확보하고자 함
// 이 때, 앱 비활성화의 최소 비용을 계산하는 문제

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<std::pair<int, int>> info(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> info[i].first;
	}

	// 앱을 비활성화하는데 드는 비용들의 합을 저장
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		std::cin >> info[i].second;
		sum += info[i].second;
	}

	// 배낭 문제와 같은 방식으로 tabulation 진행
	// DP 벡터에는 비용을 c만큼 썼을 때 확보할 수 있는 최대 메모리의 크기가 저장됨
	std::vector<int> DP(sum + 1, 0);
	for (int i = 0; i < N; ++i) {
		int mem = info[i].first;
		int cost = info[i].second;

		for (int j = sum; j >= cost; --j) {
			DP[j] = std::max(DP[j], DP[j - cost] + mem);
		}
	}

	// c만큼의 비용으로 M 이상의 메모리가 확보될 수 있을 때, 최소한의 비용 c를 구함
	int answer = 1e9;
	for (int i = 0; i <= sum; ++i) {
		if (DP[i] >= M) {
			answer = std::min(answer, i);
		}
	}

	std::cout << answer;
	return 0;
}