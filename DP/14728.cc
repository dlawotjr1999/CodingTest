#include <iostream>
#include <vector>

// 아래와 같은 힌트를 통해 벼락치기를 통해 시험공부를 하고자 함 
// 여러 단원에서 융합한 문제는 출제되지 않으며, 한 단원에서 한 문제만이 출제됨
// 어떤 단원의 문제를 맞추기 위해서는 그 단원의 예상 공부 시간만큼, 혹은 그보다 더 많이 공부하면 맞출 수 있다고 가정함
// 이 때, 남은 시간동안 공부해서 얻을 수 있는 최대 점수를 구하는 문제

int main() {
	int N, T;
	std::cin >> N >> T;

	std::vector<std::pair<int, int>> vec(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> vec[i].first >> vec[i].second;
	}

	std::vector<int> DP(T + 1, 0);

	// 단원의 갯수와 총 시간으로 tablutaion을 진행하며, table에 들어가는 값은 문제의 배점
	// 한 단원에서 하나의 문제만을 출제하므로, 0-1 배낭 문제처럼 내부 for문을 감소로 설정
	for(int i = 1; i <= N; ++i) {
		int K = vec[i].first;
		int S = vec[i].second;

		for (int j = T; j >= K; --j) {
			DP[j] = std::max(DP[j], DP[j - K] + S);
		}
	}

	std::cout << DP[T];
	return 0;
}