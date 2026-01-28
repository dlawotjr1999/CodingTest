#include <bits/stdc++.h>

int dice[6] = { 1,2,3,4,5,6 };

int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };
int cur_dir = 0;

int field[21][21];
bool visited[21][21];

int N, M, K;
int answer;

void Roll_East() {
	int temp = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = temp;
}

void Roll_South() {
	int temp = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = temp;
}

void Roll_West() {
	int temp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = temp;
}

void Roll_North() {
	int temp = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = temp;
}

int BFS(int y, int x, int score) {
	int cnt = 1;

	std::queue<std::pair<int, int>> q;
	q.emplace(y, x);
	memset(visited, false, sizeof(visited));
	visited[y][x] = true;

	while (!q.empty()) {
		auto [cur_y, cur_x] = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int ny = cur_y + dir_y[d];
			int nx = cur_x + dir_x[d];

			if (ny < 1 || ny > N || nx < 1 || nx > M)
				continue;
			if (visited[ny][nx])
				continue;
			if (field[ny][nx] != score)
				continue;

			visited[ny][nx] = true;
			cnt++;
			q.emplace(ny, nx);
		}
	}

	return cnt;
}

int main() {
	std::cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			std::cin >> field[i][j];
		}
	}

	int cur_x = 1, cur_y = 1;

	while (K--) {
		int nx = cur_x + dir_x[cur_dir];
		int ny = cur_y + dir_y[cur_dir];

		if (nx < 1 || nx > M || ny < 1 || ny > N) {
			cur_dir = (cur_dir + 2) % 4;
			nx = cur_x + dir_x[cur_dir];
			ny = cur_y + dir_y[cur_dir];
		}

		switch (cur_dir) {
		case 0:
			Roll_East();
			break;
		case 1:
			Roll_South();
			break;
		case 2:
			Roll_West();
			break;
		case 3:
			Roll_North();
			break;
		default:
			break;
		}
			
		cur_x = nx; cur_y = ny;
		answer += field[ny][nx] * BFS(ny, nx, field[ny][nx]);

		if (dice[5] > field[ny][nx])
			cur_dir = (cur_dir + 1) % 4;
		else if (dice[5] < field[ny][nx])
			cur_dir = (cur_dir + 3) % 4;
		else 
			continue;
	}

	std::cout << answer;
	return 0;
}