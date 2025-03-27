#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9

// Dijkstra Algorithm ���� �⺻ ����

int N, M;
std::vector<std::pair<int, int>> bus[MAX];
int start, dest;
int dist[MAX];

void Dijkstra() {
	std::priority_queue<std::pair<int, int>> pq;
	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty()) {

		// �ּ� ����� ������ �����߱� ������ �ٽ� ����� ��ȯ�ؾ� �� 
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < bus[cur].size(); i++) {
			int cost2 = cost + bus[cur][i].second;

			if (cost2 < dist[bus[cur][i].first]) {
				dist[bus[cur][i].first] = cost2;

				// ������ ������ ó���ؼ� �켱���� ť�� ����
				// std::greater<std::pair<int, int>>�� �̿��ϸ� ������ �̿����� �ʾƵ� ��
				// �� �� ������ ���� ���� ��. �� �ּ� ����� ť�� ���� ��ܿ� ��ġ�ϰ� �ȴ�
				pq.emplace(-cost2, bus[cur][i].first);
			}
		}
	}
	std::cout << dist[dest] << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N;
	std::cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		bus[a].emplace_back(b, c);
	}

	std::cin >> start >> dest;
	for (int i = 1; i < MAX; i++) {
		dist[i] = INF;
	}
	Dijkstra();
	return 0;
}