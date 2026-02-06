#include <bits/stdc++.h>	

// 어떤 나라에 1번부터 N번까지의 도시와 M개의 단방향 도로가 존재함
// 또한 한 출발 도시 X에서 출발 도시 X로 가는 최단 거리는 항상 0이라고 가정함
// 이 때, 특정한 도시 X로부터 출발하여 도달할 수 있는 모든 도시 중에서 최단 거리가 정확히 K인 모든 도시들의 번호를 구하고 오름차순으로 출력하는 문제

const int MAX = 300001;
std::vector<int> field[MAX];

int N, M, K, X;

// 최단 거리를 구해야 하기 때문에 BFS로 탐색 진행
std::vector<int> BFS(int s) {
	std::vector<bool> visited(N + 1, false);
	std::queue<std::pair<int, int>> q;
	
	q.emplace(s, 0);
	visited[s] = true;

	std::vector<int> nodes;
	while (!q.empty()) {
		auto [cur, dist] = q.front();
		q.pop();

		// 출발지로부터 거리가 K인 현재 노드를 저장  
		if (dist == K) {
			nodes.push_back(cur);
			continue;
		}

		// 노드를 한 레벨씩 증가시켜 나가면서 탐색
		for (int node : field[cur]) {
			if (!visited[node]) {
				visited[node] = true;
				q.emplace(node, dist + 1);
			}
		}
	}

	// 최단 거리가 K인 도시가 없는 경우 -1만을 저장
	if(nodes.empty())
		nodes.push_back(-1);
	return nodes;
}

int main() {
	std::cin >> N >> M >> K >> X;

	for (int i = 0; i < M; ++i) {
		int a, b; 
		std::cin >> a >> b;
		field[a].push_back(b);
	}

	// 최단 거리가 K인 노드들이 저장되며, 오름차순으로 정렬
	std::vector<int> vec = std::move(BFS(X));
	std::sort(vec.begin(), vec.end());

	// 정렬된 순서대로 출력
	for (int i : vec) {
		std::cout << i << '\n';
	}
	return 0;
}