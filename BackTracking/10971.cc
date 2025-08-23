#include <bits/stdc++.h>

// TSP를 응용한 문제. 한 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로를 계획하려고 함
// 한 번 갔던 도시는 다시 방문할 수 없으며, 도시를 왕복하는 데 드는 비용은 오고 갈 때 다를 수도 있음
// 이 때, 모든 도시를 여행하고 다시 처음 도시로 돌아오는데 최소 비용을 구하는 문제

int N;
int answer = 10e6;
int start_point;

int field[11][11];
bool visited[11];

void DFS(int cur, int cost, int cnt) {
	// 가지치기 : 특정 조합이 현재까지의 답보다 큰 경우에는 return
	if (cost >= answer)
		return;
	
	// 모든 도시를 방문한 후 처음 도시로 돌아갈 때의 계산
	// 처음 방문한 도시를 제외한 N - 1개의 도시 방문을 성공하고, 마지막 도시에서 처음 도시로 돌아가는 경로가 있을 때 계산이 가능함
	if (cnt == N - 1 && field[cur][start_point]) {
		answer = std::min(answer, cost + field[cur][start_point]);
		return;
	}

	// 모든 도시들을 탐색
	for (int i = 1; i <= N; ++i) {
		// 현재 도시에서 경로가 있는 도시로 BackTracking 진행
		if (field[cur][i] && !visited[i]) {
			visited[i] = true;
			DFS(i, cost + field[cur][i], cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	std::cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		start_point = i;
		visited[i] = true;
		// 탐색의 인자로 현재 도시, 간선의 비용, 방문한 도시의 갯수를 사용
		DFS(i, 0, 0);
		visited[i] = false;
	}

	std::cout << answer;
	return 0;
}