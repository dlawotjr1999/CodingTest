#include <iostream>
#include <vector>
#include <algorithm>

// 내려가기 게임은 세 개의 숫자 중 하나를 골라 다음 줄로 이동할 수 있음
// 단, 바로 아래의 수로 넘어가거나 바로 아래의 수와 붙어 있는 수로만 이동할 수 있음
// 내려가기 게임의 숫자표가 주어져있을 때, 얻을 수 있는 최대 / 최소 점수를 구하는 문제

// 2차원 DP 배열을 크기만큼 선언하여 풀면 메모리 초과 발생
// i번째 선택은 (i-1)번째 선택으로만 결정되기 때문에 prev와 cur 두 배열만을 사용하여 해결 

int main() {
	int N;	std::cin >> N;

	int prev_max[3]; int prev_min[3];
	int cur_max[3]; int cur_min[3];

	std::cin >> prev_max[0] >> prev_max[1] >> prev_max[2];

	prev_min[0] = prev_max[0];
	prev_min[1] = prev_max[1];
	prev_min[2] = prev_max[2];

	// 줄이 하나인 경우 그 줄의 최댓값 / 최솟값이 정답
	if (N == 1) {
		std::cout << std::max({ prev_max[0], prev_max[1], prev_max[2] }) << ' '
			<< std::min({ prev_min[0], prev_min[1], prev_min[2] });
		return 0;
	}

	// 줄이 여러 개인 경우
	// 문제에 의해 내려갈 수 있는 방향대로만 내려가며 최댓값 / 최솟값을 구함
	// 한 줄을 내려가고 prev와 cur 갱신
	for (int i = 2; i <= N; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;

		cur_max[0] = std::max(prev_max[0], prev_max[1]) + a;
		cur_max[1] = std::max({ prev_max[0], prev_max[1], prev_max[2] }) + b;
		cur_max[2] = std::max(prev_max[1], prev_max[2]) + c;

		cur_min[0] = std::min(prev_min[0], prev_min[1]) + a;
		cur_min[1] = std::min({ prev_min[0], prev_min[1], prev_min[2] }) + b;
		cur_min[2] = std::min(prev_min[1], prev_min[2]) + c;

		for (int i = 0; i < 3; ++i) {
			prev_max[i] = cur_max[i];
			prev_min[i] = cur_min[i];
		}
	}

	std::cout << std::max({ cur_max[0], cur_max[1], cur_max[2] }) << ' ' << std::min({ cur_min[0], cur_min[1], cur_min[2] });
	return 0;
}