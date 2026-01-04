#include <bits/stdc++.h>

const int MAX = 101;

std::pair<bool, bool> field[MAX][MAX];

int dir_x[4] = { 0, 1, 0, -1 };  
int dir_y[4] = { -1, 0, 1, 0 };

int main() {
	int N;	std::cin >> N;
	int K;	std::cin >> K;

	std::deque<std::pair<int, int>> snake;
	snake.emplace_back(1, 1);
	field[1][1].second = true;

	// 사과 위치 표시
	while (K--) {
		int r, c;
		std::cin >> r >> c;
		field[r][c].first = true;
	}

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

		if (nx < 1 || nx > N || ny < 1 || ny > N)
			break;
		if (field[ny][nx].second) {
			std::cout << time;
			return 0;
		}
		
		snake.emplace_front(ny, nx);
		field[ny][nx].second = true;
		if (field[ny][nx].first)
			field[ny][nx].first = false;
		else {
			auto [ty, tx] = snake.back();
			snake.pop_back();
			field[ty][tx].second = false;
		}

		if (cur_idx < cmd.size() && time == cmd[cur_idx].first) {
			if (cmd[cur_idx].second == 'L')
				cur_dir = (cur_dir + 3) % 4;
			else
				cur_dir = (cur_dir + 1) % 4;
			cur_idx++;
		}
	}

	std::cout << time;
	return 0;
}