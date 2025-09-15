#include <bits/stdc++.h>

// 땅고르기 작업을 위한 최적의 높이와 그 소요시간을 구하는 문제
// 아래와 같은 두 가지 작업이 가능함
// 1. 특정 위치에서 블록을 하나 꺼내어 인벤토리에 저장(2초 소요)
// 2. 인벤토리에서 블록을 하나 꺼내어 좌표의 가장 위 블록 위에 쌓음(1초 소요)

constexpr int MAX = 501;
constexpr int MAX_H = 257;

int N, M, B;
int field[MAX][MAX];	// 필드에 있는 각 블록들의 높이
int heights[MAX_H];		// 블록 높이들의 갯수 

long long best_time = LLONG_MAX;
int best_height;

int main() {
	std::cin >> N >> M >> B;

	int min_h = 1000;
	int max_h = 0;

	// 입력된 높이들의 횟수를 heights저장하며, 최소 높이와 최대 높이를 갱신함
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> field[i][j];
			heights[field[i][j]]++;
			min_h = std::min(field[i][j], min_h);
			max_h = std::max(field[i][j], max_h);
		}
	}

	// 가능한 최소 높이부터 최대 높이까지 모두 탐색
	// h를 만들기 위해 각 블록 높이들의 추가, 제거를 탐색
	for (int h = min_h; h <= max_h; ++h) {
		long long remove = 0;
		long long add = 0;

		for (int height = 0; height < MAX_H; ++height) {
			// 높이가 없는 블록은 무시
			if (heights[height] == 0)
				continue;
			
			// 높이가 h보다 높을 경우, 제거해야 하는 블록의 수를 구함
			if (height > h) {
				remove += (height - h) * heights[height];
			}
			// 높이가 h보다 낮을 경우, 추가해야 하는 블록의 수를 구함
			else if(height < h) {
				add += (h - height) * heights[height];
			}
		}

		// 기존 보유 블록의 갯수 + 제거해야하는 블록의 수가 추가해야 하는 블록의 수보다 많으면 불가능하므로 무시
		if (remove + B < add)
			continue;
		// 제거는 2초의 시간이, 추가는 1초의 시간이 소요됨
		long long time = 2 * remove + add;

		// 최단 시간을 갱신하며, 시간이 동일할 경우 높이가 가장 높은 경우를 채택
		if (time < best_time || (time == best_time && best_height < h)) {
			best_time = time;
			best_height = h;
		}
	}

	std::cout << best_time << ' ' << best_height;
	return 0;
}