#include <iostream>
#include <vector>

constexpr int MAX = 50;
constexpr int INF = 1e9;

int ary[MAX][MAX];
std::vector<std::pair<int, int>> shark_positions;

int N, M;

int main() {
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> ary[i][j];
			if (ary[i][j]) {
				shark_positions.emplace_back(i, j);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (ary[i][j] == 0) {
				int min_distance = INF;

				for (const auto& [a, b] : shark_positions) {
					int dist = std::max(std::abs(i - a), std::abs(j - b));
					min_distance = std::min(min_distance, dist);
				}
				answer = std::max(answer, min_distance);  
			}
		}
	}

	std::cout << answer;
	return 0;
}