#include <bits/stdc++.h>

int dir_x[8] = { 0,1,1,1,0,-1,-1,-1 };
int dir_y[8] = { -1,-1,0,1,1,1,0,-1 };

struct info{
	int a = 5;
	std::vector<std::pair<int, bool>> trees;
};

int N, M, K;
int answer;

info fields[11][11];
int A[11][11];

int main() {
	std::cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; ++i) {
		int x, y, z; 
		std::cin >> x >> y >> z;
		fields[x][y].trees.emplace_back(z, true);
	}

	while (K--) {
		// spring
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				auto& cur_trees = fields[i][j].trees;
				std::sort(cur_trees.begin(), cur_trees.end());

				for (auto& tree : cur_trees) {				
					if (fields[i][j].a >= tree.first) {
						fields[i][j].a -= tree.first;
						tree.first++;
					}
					else 
						tree.second = false;
				}
			}
		}

		// summer
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				auto& cur_trees = fields[i][j].trees;

				for (auto& tree : cur_trees) {
					if (!tree.second) {
						int nutrient = tree.first / 2;
						fields[i][j].a += nutrient;
					}
				}
				cur_trees.erase(std::remove_if(cur_trees.begin(), cur_trees.end(),
						[](const auto& p) { return !p.second; }),cur_trees.end());
			}
		}

		// autumn
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				auto& cur_trees = fields[i][j].trees;

				for (auto& tree : cur_trees) {
					if (tree.first % 5 == 0 && tree.second) {
						for (int d = 0; d < 8; ++d) {
							int nx = j + dir_x[d];
							int ny = i + dir_y[d];

							if (nx < 1 || nx > N || ny < 1 || ny > N)
								continue;
							fields[ny][nx].trees.emplace_back(1, true);
						}
					}
				}
			}
		}

		// winter
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				fields[i][j].a += A[i][j];
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			auto& cur_trees = fields[i][j].trees;
			answer += cur_trees.size();
		}
	}

	std::cout << answer;
	return 0;
}