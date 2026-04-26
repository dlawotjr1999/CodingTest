#include <bits/stdc++.h>

const int MAX = 200;

const int dir_x[4] = { 0,1,0,-1 };
const int dir_y[4] = { -1,0,1,0 };

struct info {
	int num;
	int t;
	int y, x;
};

int field[MAX + 1][MAX + 1];

int main() {
	int N, K;
	std::cin >> N >> K;

	std::vector<info> vec;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j];
			
			if (field[i][j] != 0)
				vec.push_back({ field[i][j], 0, i, j });
		}
	}
	std::sort(vec.begin(), vec.end(), [](const auto& l, const auto& r) {
		return l.num < r.num;
	});

	int S, X, Y;
	std::cin >> S >> X >> Y;

	std::queue<info> q;
	for (info elm : vec) {
		q.push(elm);
	}

	while (!q.empty()) {
		auto [cur_num, cur_t, cur_y, cur_x] = q.front();
		q.pop();

		if (cur_t == S) 
			break;
		
		for (int i = 0; i < 4; ++i) {
			int dx = cur_x + dir_x[i];
			int dy = cur_y + dir_y[i];

			if (dx < 1 || dx > N || dy < 1 || dy > N)
				continue;
			if (field[dy][dx] != 0)
				continue;
			field[dy][dx] = cur_num;
			q.push({ cur_num, cur_t + 1, dy, dx });
		}
	}

	std::cout << field[X][Y];
	return 0;
}