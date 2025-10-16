#include <iostream>
#include <vector>
#include <queue>
#include <climits>

// 1번 정점부터 N번 정점까지의 최단 거리를 구하는 문제
// 단 임의의 두 정점 v1, v2를 반드시 거쳐야 하며, 한 번 이동했던 간선도 다시 이동이 가능함

const int INF = INT_MAX;
const int MAX = 801;

int N, E;
int v1, v2;
long long answer;

std::vector<std::pair<int, int>> graph[MAX];

// Dijkstra 알고리즘으로 최단 경로 계산 후, 그 값들을 저장한 vector로 번환
std::vector<int> Dijkstra(int start) {
	std::vector<int> dist(MAX, INF);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty()) {
		auto [cost, node] = pq.top();
		pq.pop();

		if (dist[node] < cost)
			continue;

		for (auto& [next_node, next_cost] : graph[node]) {
			int new_cost = cost + next_cost;
			if (new_cost < dist[next_node]) {
				dist[next_node] = new_cost;
				pq.emplace(new_cost, next_node);
			}
		}
	}

	return dist;
}

int main() {
	std::cin >> N >> E;

	for (int i = 0; i < E; ++i) {
		int a, b, c;	
		std::cin >> a >> b >> c;

		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	std::cin >> v1 >> v2;

	// 두 정점 v1과 v2를 반드시 거쳐서 1부터 N까지 갈 수 있는 경로는 아래와 같이 두 개가 있음
	// 1 -> v1 -> v2 -> N 또는 1 -> v2 -> v1 -> N
	// 두 경로 중 더 낮은 비용을 가진 경로가 정답이 됨

	std::vector<int> dist1 = Dijkstra(1);	 // 1번 정점에서 출발하는 경로의 거리
	std::vector<int> dist_v1 = Dijkstra(v1); // v1번 정점에서 출발하는 경로의 거리
	std::vector<int> dist_v2 = Dijkstra(v2); // v2번 정점에서 출발하는 경로의 거리

	long long path1 = 1LL * dist1[v1] + dist_v1[v2] + dist_v2[N]; // 1 -> v1 -> v2 -> N의 경로
	long long path2 = 1LL * dist1[v2] + dist_v2[v1] + dist_v1[N]; // 1 -> v2 -> v1 -> N의 경로

	// 두 경로 중 더 낮은 비용을 가진 경로가 정답이며, 경로가 존재하지 않는 경우 -1 출력
	answer = std::min(path1, path2);
	if (answer >= INF) {
		std::cout << -1;
		return 0;
	}

	std::cout << answer;
	return 0;
}