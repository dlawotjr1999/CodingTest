#include <bits/stdc++.h>

// N개의 스테이션과 N-1개의 통로로 이루어진 우유 공장이 존재함
// 각 통로에 단방향의 컨베이어 벨트를 설치하였기 때문에 스테이션 간 모든 이동이 불가능해짐
// 이 때, 모든 스테이션에서 도달 가능한 스테이션이 존재하는지 구하는 문제

std::vector<int> graph[101];
std::vector<bool> visited(101);

std::vector<int> cnt(101, 0);

// DFS를 통해 각 노드를 방문할 때마다 방문 여부 체크
// 모든 노드들에 대해 탐색을 진행하므로 값을 계속 누적
void DFS(int node) {
	visited[node] = true;
	cnt[node]++;

	for (int next : graph[node]) {
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
	int N;	std::cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		std::cin >> a >> b;

		// 컨베이어 벨트 설치로 인하여 각 스테이션 간 연결은 단방향만 가능해짐
		graph[a].push_back(b);
	}

	for (int i = 1; i <= N; ++i) {
		std::fill(visited.begin(), visited.end(), false);
		DFS(i);
	}

	// 모든 노드 중 값이 N인 노드를 탐색하여 출력하고, 존재하지 않는 경우 -1 출력
	// 값이 N이라는 것은 어느 노드에서든 그 노드에 도달할 수 있음을 의미함
	for (int i = 1; i <= N; ++i) {
		if (cnt[i] == N) {
			std::cout << i;
			return 0;
		}
	}

	std::cout << -1;
	return 0;
}