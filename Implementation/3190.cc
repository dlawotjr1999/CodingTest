#include <bits/stdc++.h>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/3190

const int MAX = 101;

// 현재 좌표에 (사과의 존재 여부, 현재 위치에서의 몸통 존재 여부)를 저장하는 필드 선언 
std::pair<bool, bool> field[MAX][MAX];

int dir_x[4] = { 0, 1, 0, -1 };  
int dir_y[4] = { -1, 0, 1, 0 };

int main() {
	int N;	std::cin >> N;
	int K;	std::cin >> K;

	// 뱀의 크기 정보를 deque으로 표현
	std::deque<std::pair<int, int>> snake;
	snake.emplace_back(1, 1);
	field[1][1].second = true;

	// 사과 위치 표시
	while (K--) {
		int r, c;
		std::cin >> r >> c;
		field[r][c].first = true;
	}

	// 방향 변환 정보 입력
	int L;	std::cin >> L;
	std::vector<std::pair<int, char>> cmd;
	while (L--) {
		int X; char C;
		std::cin >> X >> C;
		cmd.emplace_back(X, C);
	}

	int cur_idx = 0;
	int cur_dir = 1;

	int time = 0;

	while (true) {
		time++;

		auto [y, x] = snake.front();
		int ny = y + dir_y[cur_dir];
		int nx = x + dir_x[cur_dir];

		// 벽에 부딪힐 경우 게임이 끝남
		if (nx < 1 || nx > N || ny < 1 || ny > N)
			break;

		// 자기자신의 몸에 부딪힐 경우에도 게임이 끝남
		// 머리가 위치할 좌표에 몸의 일부가 존재하는 경우로 확인 가능 
		if (field[ny][nx].second) {
			std::cout << time;
			return 0;
		}
		
		// 위의 경우를 제외하면, 몸길이를 늘려 머리를 다음 칸에 위치시킬 수 있음
		snake.emplace_front(ny, nx);
		field[ny][nx].second = true;

		// 이동한 칸에 사과가 있다면 그 칸의 사과는 사라짐
		if (field[ny][nx].first)
			field[ny][nx].first = false;

		// 사과가 없다면 몸길이를 줄여 꼬리가 위치한 칸을 비움
		else {
			auto [ty, tx] = snake.back();
			snake.pop_back();
			field[ty][tx].second = false;
		}

		// 커맨드 규칙에 맞게 이동 방향 전환
		// 즉 (X, C)에서 time이 X일 때 방향 전환
		if (cur_idx < cmd.size() && time == cmd[cur_idx].first) {
			// L인 경우 왼쪽으로 90도 회전
			if (cmd[cur_idx].second == 'L')
				cur_dir = (cur_dir + 3) % 4;

			// R인 경우 오른쪽으로 90도 회전
			else
				cur_dir = (cur_dir + 1) % 4;
			cur_idx++;
		}
	}

	std::cout << time;
	return 0;
}