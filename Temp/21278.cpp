#include <iostream>
#include <algorithm>

constexpr int MAX = 101;
constexpr int INF = 1e9;

int edges[MAX][MAX];

int N, M;

void FloydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				edges[i][j] = std::min(edges[i][j], edges[i][k] + edges[k][j]);
			}
		}
	}
}

int main() {
	std::cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				edges[i][j] = 0;
			else
				edges[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b; 
		std::cin >> a >> b;
		edges[a][b] = edges[b][a] = 1;
	}

	FloydWarshall();

	int min_sum = INF;
	int result_a = -1, result_b = -1;

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int total = 0;

			for (int k = 1; k <= N; k++) {
				int to_nearest = std::min(edges[k][i], edges[k][j]);
				total += to_nearest * 2;  
			}
			if (total < min_sum) {
				min_sum = total;
				result_a = i;
				result_b = j;
			}
		}
	}

	std::cout << result_a << " " << result_b << " " << min_sum;
	return 0;
}