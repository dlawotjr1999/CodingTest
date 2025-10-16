#include <iostream>
#include <vector>
#include <queue>
#include <climits>

// 1�� �������� N�� ���������� �ִ� �Ÿ��� ���ϴ� ����
// �� ������ �� ���� v1, v2�� �ݵ�� ���ľ� �ϸ�, �� �� �̵��ߴ� ������ �ٽ� �̵��� ������

const int INF = INT_MAX;
const int MAX = 801;

int N, E;
int v1, v2;
long long answer;

std::vector<std::pair<int, int>> graph[MAX];

// Dijkstra �˰������� �ִ� ��� ��� ��, �� ������ ������ vector�� ��ȯ
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

	// �� ���� v1�� v2�� �ݵ�� ���ļ� 1���� N���� �� �� �ִ� ��δ� �Ʒ��� ���� �� ���� ����
	// 1 -> v1 -> v2 -> N �Ǵ� 1 -> v2 -> v1 -> N
	// �� ��� �� �� ���� ����� ���� ��ΰ� ������ ��

	std::vector<int> dist1 = Dijkstra(1);	 // 1�� �������� ����ϴ� ����� �Ÿ�
	std::vector<int> dist_v1 = Dijkstra(v1); // v1�� �������� ����ϴ� ����� �Ÿ�
	std::vector<int> dist_v2 = Dijkstra(v2); // v2�� �������� ����ϴ� ����� �Ÿ�

	long long path1 = 1LL * dist1[v1] + dist_v1[v2] + dist_v2[N]; // 1 -> v1 -> v2 -> N�� ���
	long long path2 = 1LL * dist1[v2] + dist_v2[v1] + dist_v1[N]; // 1 -> v2 -> v1 -> N�� ���

	// �� ��� �� �� ���� ����� ���� ��ΰ� �����̸�, ��ΰ� �������� �ʴ� ��� -1 ���
	answer = std::min(path1, path2);
	if (answer >= INF) {
		std::cout << -1;
		return 0;
	}

	std::cout << answer;
	return 0;
}