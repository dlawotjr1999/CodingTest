#include <bits/stdc++.h>

// 인사를 하면 L_i만큼의 체력을 잃고, i만큼의 기쁨을 얻는다고 함
// 목표는 주어진 체력 내에서 최대한의 기쁨을 느끼는 것이며, 체력이 0이나 음수가 되면 아무런 기쁨을 느끼지 못한 것이 됨
// 각각의 사람에게 최대 1번만 인사를 할 수 있다고 할 때, 얻을 수 있는 최대 기쁨을 구하는 문제

int answer;

int main() {
	int N;	std::cin >> N;

	std::vector<int> hp(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> hp[i];
	}

	std::vector<int> joy(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> joy[i];
	}

	std::vector<int> DP(100);

	// 최대 한 사람에게만 인사를 할 수 있으므로 내부 반복문은 역순으로 진행  
	for (int i = 1; i <= N; ++i) {
		int cur_hp = hp[i];
		int cur_joy = joy[i];

		// 최대 체력이 100이므로 99까지만 탐색
		for (int j = 99; j >= cur_hp; --j) {
			DP[j] = std::max(DP[j], DP[j - cur_hp] + cur_joy);
		}
	}

	for (int i = 1; i <= 99; ++i) 
		answer = std::max(answer, DP[i]);

	std::cout << answer;
	return 0;
}