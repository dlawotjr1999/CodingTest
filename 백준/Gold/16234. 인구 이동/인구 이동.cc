#include <bits/stdc++.h>

const int dir_x[4] = { 0,1,0,-1 };
const int dir_y[4] = { -1,0,1,0 };

int answer;

struct country {
	int num = 0;
	std::vector<std::pair<int, int>> side_coords;
};

void BFS(int y, int x, std::vector<std::vector<country>>& field, std::vector<std::vector<bool>>& visited) {
	std::queue<std::pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;

	// 현재 국가에서 도달 가능한 모든 국가들의 좌표들
	std::vector<std::pair<int, int>> coords;

	int total = 0;
	while (!q.empty()) {
		auto [cur_y, cur_x] = q.front();
		q.pop();

		total += field[cur_y][cur_x].num;
		coords.emplace_back(cur_y, cur_x);

		for (auto [next_y, next_x] : field[cur_y][cur_x].side_coords) {
			if (!visited[next_y][next_x]) {
				visited[next_y][next_x] = true;
				q.emplace(next_y, next_x);
			}
		}
	}

	int population = total / coords.size();
	for (const auto [cur_y, cur_x] : coords) {
		field[cur_y][cur_x].num = population;
	}
}

int main() {
	int N, L, R;
	std::cin >> N >> L >> R;

	std::vector<std::vector<country>> field(N, std::vector<country>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> field[i][j].num;
		}
	}

	while (true) {
		bool isContinue = false;

		// 국경선 개방이 가능한 인접 국가의 좌표 저장
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {

				for (int d = 0; d < 4; ++d) {
					int nx = j + dir_x[d];
					int ny = i + dir_y[d];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					int diff = std::abs(field[i][j].num - field[ny][nx].num);
					if (diff >= L && diff <= R)
						field[i][j].side_coords.emplace_back(ny, nx);
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (field[i][j].side_coords.size() != 0) {
					isContinue = true;
					break;
				}
			}
			if (isContinue)
				break;
		}

		// 개방 가능한 인접 국가가 없으면, 즉 인구 분배가 끝나면 종료
		if (!isContinue)
			break;

		// 인구 분배 시작
		answer++;

		std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!visited[i][j]) {
					BFS(i, j, field, visited);
				}
			}
		}

		// 인접 국가들 다시 초기화
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				field[i][j].side_coords.clear();
			}
		}
	}

	std::cout << answer;
	return 0;
}