#include <bits/stdc++.h>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/14891

int score;

// 톱니바퀴의 회전(주기)를 담당하는 함수
void rotate(std::string& gear, int cmd) {
	if (cmd == 1) {  
		char temp = gear.back();
		gear.pop_back();
		gear.insert(gear.begin(), temp);
	}
	else {  
		char temp = gear.front();
		gear.erase(gear.begin());
		gear.push_back(temp);
	}
}

int main() {
	std::vector<std::string> gears(4);
	for (int i = 0; i < 4; ++i) {
		std::cin >> gears[i];
	}

	int K; 
	std::cin >> K;

	std::vector<std::pair<int, int>> commands(K);
	for (int i = 0; i < K; ++i) {
		int a, b;
		std::cin >> a >> b;
		commands[i] = { a, b };
	}

	for (auto& [num, cmd] : commands) {
		// 초기 상태(어떤 톱니바퀴도 회전하지 않음)
		int dir[4] = { 0,0,0,0 };
		dir[num - 1] = cmd;

		// 현재 톱니바퀴로부터 왼쪽에 있는 톱니바퀴들의 변화 계산
		for (int i = num - 1; i > 0; --i) {
			// 현재 톱니바퀴의 9시 방향 톱니(6번 인덱스)와 왼쪽에 있는 톱니바퀴의 3시 방향 톱니(2번 인덱스)의 극이 다른 경우
			// 현재 톱니바퀴의 반대 방향으로 회전함
			if (gears[i][6] != gears[i - 1][2])
				dir[i - 1] = -dir[i];  
			else
				break;              
		}

		// 현재 톱니바퀴로부터 오른쪽에 있는 톱니바퀴들의 변화 계산
		for (int i = num - 1; i < 3; ++i) {
			// 현재 톱니바퀴의 3시 방향 톱니(2번 인덱스)와 오른쪽에 있는 톱니바퀴의 9시 방향 톱니(6번 인덱스)의 극이 다른 경우
			// 위와 동일하게 현재 톱니바퀴의 반대 방향으로 회전
			if (gears[i][2] != gears[i + 1][6])
				dir[i + 1] = -dir[i];
			else
				break;
		}

		// 4개의 톱니바퀴들의 회전량을 계산한 뒤 rotate 함수를 통해 실제 결과를 계산
		// -1인 경우에는 반시계 방향, 1인 경우에는 시계 방향으로 회전
		for (int i = 0; i < 4; ++i) {
			if (dir[i] != 0)
				rotate(gears[i], dir[i] == 1 ? 1 : -1);
		}
	}

	// 각 톱니들의 12시 방향 톱니(0번 인덱스)에 따라 점수 계산
	for (int i = 0; i < 4; ++i) {
		if (gears[i][0] == '1') {
			score += (1 << i);  
		}
	}

	std::cout << score;
	return 0;
}