#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 각 단지 내 집의 수를 세고, 단지의 수와 그 집의 수들을 구하는 문제
// 흔히 나오는, 방향과 DFS, BFS를 이용한 탐색 문제(미로 탐색 유형)

int N;
int graph[26][26];
bool visited[26][26];
std::vector<int> num;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0, 1, 0, -1 };

void BFS(int x, int y) {
	// 단지 내 집의 수를 세기 위한 변수
	int cnt = 0;

	std::queue<std::pair<int, int>> queue;
	visited[x][y] = true;
	queue.emplace(x, y);
	cnt++;

	while (!queue.empty()) {
		x = queue.front().first;
		y = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			if ((1 <= new_x && new_x <= N) && (1 <= new_y && new_y <= N)) {
				if (graph[new_x][new_y] == 1 && !visited[new_x][new_y]) {
					visited[new_x][new_y] = true;
					queue.emplace(new_x, new_y);
					cnt++;
				}
			}
		}
	}
	num.push_back(cnt);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N;

	std::string str;
	for (int i = 1; i <= N; i++) {
		std::cin >> str;
		for (int j = 1; j <= N; j++) {
			graph[i][j] = str[j - 1] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] && !visited[i][j]) {
				BFS(i, j);
			}
		}
	}

	std::sort(num.begin(), num.end());
	std::cout << num.size() << std::endl;
	for (int& elm : num) {
		std::cout << elm << std::endl;
	}

	return 0;
}