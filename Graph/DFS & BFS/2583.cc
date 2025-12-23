#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 모눈종이 위에 눈금에 맞추어 직사각형들을 그릴 때, 직사각형 내부를 제외한 몇 개의 부분들이 분리된 영역으로 나누어짐
// 이 때, 직사각형 내부를 제외한 나머지 부분이 몇 개의 영역으로 나누어지는지, 그리고 각 영역들의 넓이가 얼마인지 구하는 문제

const int MAX = 100;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int M, N, K;

// (직사각형 내 영역 여부, 방문 여부) 순서쌍을 저장하는 vector
std::vector<std::vector<std::pair<bool, bool>>> field;
std::vector<int> areas;

// 영역 넓이 계산
void BFS(int x, int y) {
	std::queue<std::pair<int, int>> q;

	q.emplace(x, y);
	field[y][x].second = true;
	int area = 1;

	while (!q.empty()) {
		auto [c, r] = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int nx = c + dir_x[k];
			int ny = r + dir_y[k];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			
			// 직사각형 영역 내에 있는 좌표인 경우 무시
			if (field[ny][nx].first || field[ny][nx].second)
				continue;   

			field[ny][nx].second = true;
			area++;
			q.emplace(nx, ny);
		}
	}
	areas.push_back(area);
}

int main() {
	std::cin >> M >> N >> K;
	field.resize(MAX, std::vector<std::pair<bool, bool>>(MAX, { false, false }));

	for (int i = 0; i < K; ++i) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		// 직사각형으로 그려진 영역 표시
		for (int i = b; i < d; ++i) {
			for (int j = a; j < c; ++j) {
				if (field[i][j].first)
					continue;
				field[i][j].first = true;
			}
		}
	}

	// 직사각형들의 영역 외부에 있으며, 방문하지 않은 좌표에 대해서 탐색 진행
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!field[i][j].first && !field[i][j].second) {
				BFS(j, i);
			}
		}
	}

	// 영역의 갯수와 각 넓이를 오름차순으로 출력
	std::sort(areas.begin(), areas.end());
	std::cout << areas.size() << '\n';
	for (int area : areas) 
		std::cout << area << ' ';
	
	return 0;
}