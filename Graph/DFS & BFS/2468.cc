#include <iostream>
#include <queue>

// 장마철에 대비하기 위해 안전 영역의 갯수를 구하고자 함
// 안전 영역에서, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정함
// 높이 정보는 2차원 배열로 주어지며, 안전 영역은 잠기지 않는 지점들이 위, 아래, 오른쪽 혹은 왼쪽으로 인접해 있는, 그 크기가 최대인 영역을 의미함
// 이 때, 물에 잠기지 않는 안전 영역의 최대 갯수를 구하는 문제

int N;
int answer = -1;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

std::pair<int, bool> field[101][101];
bool visited[101][101];

// BFS로 안전 영역 탐색
void BFS(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;

	while (!q.empty()) {
		auto [cur_y, cur_x] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int dy = cur_y + dir_y[i];
			int dx = cur_x + dir_x[i];

			if (dy < 1 || dy > N || dx < 1 || dx > N) 
				continue;

			// 잠긴 영역은 건너뜀
			if (field[dy][dx].second) 
				continue;

			if (!visited[dy][dx]) {
				q.emplace(dy, dx);
				visited[dy][dx] = true;
			}
		}
	}
}

int main() {
	std::cin >> N;
	int max_h = -1;

	// 최대 높이를 미리 구해놓음
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j].first;
			field[i][j].second = false;
			max_h = std::max(max_h, field[i][j].first);
		}
	}

	// 최대 높이까지 물에 잠겼을 때까지를 각각 시뮬레이션
	// 비가 오지 않는 경우까지 고려해야 하므로 최소 높이가 아닌 0부터 시작
	for (int h = 0; h <= max_h; ++h) {
		int cnt = 0;

		// 현재 높이보다 낮은 높이의 칸은 모두 잠기므로 true로 표시함
		// 다음의 높이의 경우에도 잠겨 있게 되므로 각 시뮬레이션마다 초기화할 필요가 없음
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				field[i][j].second = (field[i][j].first <= h);
				visited[i][j] = false;
			}
		}

		// 안전 영역 탐색
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {

				// 잠기지 않고, 탐색하지 않은 칸에 대해서만 BFS 진행
				if (!field[i][j].second && !visited[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		answer = std::max(answer, cnt);
	}

	std::cout << answer;
	return 0;
}