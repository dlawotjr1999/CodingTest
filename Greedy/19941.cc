#include <iostream>
#include <vector>

// 한 줄에 ‘P’(사람)와 ‘H’(햄버거)가 주어지고, 각 사람이 거리 K 이내의 햄버거를 최대 한 개 먹을 수 있음
// 이 때, 최대 몇 명이 햄버거를 먹을 수 있는지를 구하는 문제
// 가장 왼쪽 사람부터 탐색하며 아직 배정되지 않은 가장 가까운 햄버거를 할당하면 최적이 보장됨

int answer;

int main() {
	int N, K;
	std::string str;

	std::cin >> N >> K;
	std::cin >> str;

	// false : 햄버거를 먹지 않음. 즉 햄버거가 남아 있음을 의미함
	std::vector<bool> vec(N, false);

	for (int i = 0; i < N; ++i) {
		// 사람일 경우에만 고려함
		if (str[i] != 'P')
			continue;

		// 구간 내에서 탐색 진행
		for (int d = -K; d <= K; ++d) {
			int j = i + d;

			// 범위를 벗어나면 continue
			if (j < 0 || j >= N)
				continue;
			// 범위 내에 햄버거가 있고, 햄버거가 남아있다면 먹을 수 있음 
			if (str[j] == 'H' && !vec[j]) {
				vec[j] = true;
				answer++;
				break;
			}
		}
	}

	std::cout << answer;
	return 0;
}