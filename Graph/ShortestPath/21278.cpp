#include <iostream>
#include <algorithm>

// N개의 정점(집)과 M개의 무방향 간선(도로)이 주어졌을 때 이 중 두 개의 정점을 치킨집 위치로 선정
// 이후 모든 집에서 더 가까운 치킨집까지의 왕복 거리(편도 거리 * 2) 합을 계산함
// 이 때 최소 비용을 가질 수 있는 두 치킨집의 번호와 그 비용을 구하는 문제

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

	// 두 개의 치킨집 후보 건물 선택(i : 1번 건물, j : 2번 건물)
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int total = 0;

			// 두 개의 후보 건물들에 대한, 다른 건물과의 거리 계산
			// 두 건물 중 더 작은 비용의 거리를 선택하여 총 거리 계산
			// 왕복 거리이므로 2를 곱해줘야 함
			for (int k = 1; k <= N; k++) {
				int to_nearest = std::min(edges[k][i], edges[k][j]);
				total += to_nearest * 2;  
			}

			// 최소 비용을 가질 수 있는 두 건물과 그 거리 계산
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