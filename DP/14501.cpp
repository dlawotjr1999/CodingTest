#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// 퇴사일까지 N일이 남아있을 때 상담 일정을 잘 조정하여 얻을 수 있는 최대 수익을 구하는 문제
// 각 상담은 아래와 같이 이루어져 있다.
// - T[i]: 상담에 걸리는 기간
// - P[i] : 상담을 완료했을 때 받을 수 있는 금액

int main() {
	int N;
	std::cin >> N;

	std::vector<int> T(N + 1, 0);
	std::vector<int> P(N + 1, 0);
	std::vector<int> DP(N + 2, 0);

	for (int i = 1; i <= N; i++) {
		std::cin >> T[i] >> P[i];
	}

	// 날짜를 거꾸로 순회하며, 상담을 시작할지 말지를 결정
	for (int i = N; i > 0; i--) {

		// i번째 날 상담을 하면, 종료일은 i + T[i] - 1
		// 이 종료일이 퇴사일(N)을 넘기면 상담 불가능 → 전날의 결과 유지
		if (i + T[i] > N + 1) {
			DP[i] = DP[i + 1];
		}

		// 두 가지의 경우 중 한 가지를 선택
		// 1. 오늘 상담을 하지 않고 내일로 미루는 경우
		// 2. 오늘 상담을 하고, 상담이 끝난 이후부터 이어가는 경우
		else {
			DP[i] = std::max(DP[i + 1], DP[i + T[i]] + P[i]);
		}
	}

	std::cout << *std::max_element(DP.begin(), DP.end());
	
	return 0;
}