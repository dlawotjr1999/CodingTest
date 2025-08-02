#include <bits/stdc++.h>

int answer;

int main() {
	int N, K;
	std::cin >> N >> K;

	std::deque<int> A(2 * N);
	std::deque<bool> robot_pos(2 * N, false);

	for (int i = 0; i < A.size(); ++i) {
		std::cin >> A[i];
	}

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
		for (int i = N - 2; i >= 0; i--) {
			if (robot_pos[i] && !robot_pos[i + 1] && A[i + 1] > 0) {
				robot_pos[i] = false;
				robot_pos[i + 1] = true;
				A[i + 1]--;
			}
		}
		robot_pos[N - 1] = false;


		// 3rd stage
		if (A[0] != 0 && !robot_pos[0]) {
			robot_pos[0] = true;
			A[0]--;
		}

		// 4th stage
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