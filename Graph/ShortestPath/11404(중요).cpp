#include <iostream>
#include <vector>
// Floyd-Warshall 알고리즘 구현 문제

constexpr int INF = 1e9;

int n, m;
std::vector<std::vector<int>> dist;

void FloydWarshall() {
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m;
	dist.resize(n + 1, std::vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		if (dist[a][b] > c)
			dist[a][b] = c;
	}
	FloydWarshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				dist[i][j] = 0;
			std::cout << dist[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}