#include <bits/stdc++.h>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/20055

int answer;

int main() {
	int N, K;
	std::cin >> N >> K;

	// 컨베이어 벨트를 deque로 가정하여 구현
	std::deque<int> A(2 * N);
	std::deque<bool> robot_pos(2 * N, false);

	for (int i = 0; i < A.size(); ++i) {
		std::cin >> A[i];
	}

	// 컨베이어 벨트의 회전을 시뮬레이션하는 함수
	// N번째 칸, 즉 (N - 1)번째 index는 내리는 위치이므로 로봇이 존재하지 않음
	auto rotate_belt = [&]() {
		A.push_front(A.back());
		A.pop_back();

		robot_pos.push_front(robot_pos.back());
		robot_pos.pop_back();

		robot_pos[N - 1] = false;
	};

	while (true) {
		answer++;

		// 1st stage
		rotate_belt();

		// 2nd stage
		// (N + 1)번째 위치부터는 로봇이 존재할 수 없으므로 N번째 위치까지만 고려함
		// 다음 칸에 로봇이 없고, 내구도가 1 이상이라면 로봇을 다음 칸으로 옮긴 다음 내구도를 감소시킴
		for (int i = N - 2; i >= 0; i--) {
			if (robot_pos[i] && !robot_pos[i + 1] && A[i + 1] > 0) {
				robot_pos[i] = false;
				robot_pos[i + 1] = true;
				A[i + 1]--;
			}
		}
		robot_pos[N - 1] = false;


		// 3rd stage
		// 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올림
		if (A[0] != 0 && !robot_pos[0]) {
			robot_pos[0] = true;
			A[0]--;
		}

		// 4th stage
		// 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료함
		int cnt = 0;
		for (int i = 0; i < 2 * N; ++i) {
			if (A[i] == 0) 
				cnt++;
		}
		if (cnt >= K) break;
	}

	std::cout << answer;
	return 0;
}