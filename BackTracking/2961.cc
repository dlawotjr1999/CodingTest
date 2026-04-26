#include <bits/stdc++.h>

// N개의 재료로 요리를 할 때, 각 재료의 신맛 S와 쓴맛 B를 알고 있음
// 여러 재료를 이용해서 요리할 때 그 음식의 신맛은 사용한 재료의 신맛의 곱이고, 쓴맛은 합으로 계산됨
// 물을 요리라고 할 수는 없기 때문에, 재료는 적어도 하나 사용해야 함
// 이때, 신맛과 쓴맛의 차이가 가장 작은 요리의 두 맛 차이를 구하는 문제

int N;
std::vector<std::pair<int, int>> taste;

int answer = 1e9;

void DFS(int cnt, int cur, int idx, int sweet, int bitter) {
	// 구하고자 하는 총 재료 갯수와 현재까지의 재료 갯수가 일치한 경우 맛의 차이 계산
	if (cnt == cur) {
		int diff = std::abs(sweet - bitter);
		answer = std::min(answer, diff);

		return;
	}

	// 다음 재료 탐색
	for (int i = idx; i < N; ++i) {
		int next_sweet = sweet * taste[i].first;
		int next_bitter = bitter + taste[i].second;

		DFS(cnt, cur + 1, i + 1, next_sweet, next_bitter);
	}
}

int main() {
	std::cin >> N;

	taste.resize(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> taste[i].first >> taste[i].second;
	}

	// 하나의 재료를 사용한 요리부터 N개까지의 재료를 사용한 요리까지 탐색
	// (총 재료 갯수, 현재 재료 갯수, index, 현재까지의 신맛, 현재까지의 쓴맛)으로 조합 기반 백트래킹 진행 
	// 신맛은 곱의 누적, 쓴맛은 합의 누적이기 때문에 각각 1과 0으로 시작
	for (int cnt = 1; cnt <= N; ++cnt) {
		DFS(cnt, 0, 0, 1, 0);
	}

	std::cout << answer;
	return 0;
}