#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 200001

// �־��� �׷�������, �ִ�� �Ƴ� �� �ִ� ���� ����� ���ϴ� ����
// ��� ������ ��뿡�� MST�� ���� ����� ���� ���ָ� ��
// Prim �˰����� �̿��Ͽ� ����

int m, n;
int total;
std::vector<std::pair<int, int>> graph[MAX];
std::vector<bool> visited(MAX, false);

int Prim(int start) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > pq;
	int totalCost = 0;
	int connected = 0;

	pq.emplace(0, start);

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur])
			continue;
		visited[cur] = true;
		totalCost += cost;
		connected++;

		if (connected == m)
			break;
		for (auto& edge : graph[cur]) {
			int next = edge.first;
			int nextCost = edge.second;
			if (!visited[next])
				pq.emplace(nextCost, next);
		}
	}
	return totalCost;
}

int main() {	
	while (true) {
		std::cin >> m >> n;
		if (m == 0 && n == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			int x, y, z;
			std::cin >> x >> y >> z;
			total += z;

			graph[x].emplace_back(y, z);
			graph[y].emplace_back(x, z);
		}
		std::cout << (total - Prim(0)) << '\n';
		
		// Initialize
		m = n = 0;
		total = 0;
		std::fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();  
		}
	}
}