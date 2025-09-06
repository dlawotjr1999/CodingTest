#include <bits/stdc++.h>

constexpr int MAX = 501;
constexpr int MAX_H = 257;

int N, M, B;
int field[MAX][MAX];
int heights[MAX_H];

long long best_time = LLONG_MAX;
int best_height;

int main() {
	std::cin >> N >> M >> B;

	int min_h = 1000;
	int max_h = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> field[i][j];
			heights[field[i][j]]++;
			min_h = std::min(field[i][j], min_h);
			max_h = std::max(field[i][j], max_h);
		}
	}

	for (int h = min_h; h <= max_h; ++h) {
		long long remove = 0;
		long long add = 0;

		for (int height = 0; height < MAX_H; ++height) {
			if (heights[height] == 0)
				continue;
			
			if (height > h) {
				remove += (height - h) * heights[height];
			}
			else if(height < h) {
				add += (h - height) * heights[height];
			}
		}

		if (remove + B < add)
			continue;
		long long time = 2 * remove + add;

		if (time < best_time || (time == best_time && best_height < h)) {
			best_time = time;
			best_height = h;
		}
	}

	std::cout << best_time << ' ' << best_height;
	return 0;
}