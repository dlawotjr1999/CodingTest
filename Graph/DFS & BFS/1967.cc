#include <iostream>
#include <vector>

// 트리의 지름은 트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 가장 길게 늘어나는 경우로 구할 수 있음
// 즉, 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 의미함
// 이 때, 입력으로 1번 노드를 루트로 하며 가중치가 있는 간선들로 이루어진 트리의 지름을 구하는 문제

const int MAX = 10001;

std::vector<std::pair<int, int>> tree[MAX];
std::vector<bool> visited(MAX);

int max_dist = 0;
int far_node = 1;

// 가장 멀리 떨어져 있는 노드, 즉 root 노드에서 가장 깊은 노드를 탐색해야 하므로 DFS로 진행
void DFS(int cur, int dist) {
	visited[cur] = true;

	// 한 번의 탐색마다 가장 멀리 떨어진 노드와 그 거리를 갱신해나감
	if (dist > max_dist) {
		max_dist = dist;
		far_node = cur;
	}

	for (auto [node, cost] : tree[cur]) {
		if (!visited[node]) {
			DFS(node, (dist + cost));
		}
	}
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;

		// 트리는 양방향으로 구성됨
		tree[a].emplace_back(b, c);
		tree[b].emplace_back(a, c);
	}

	// 먼저 1번 노드(root)에서 가장 멀리 떨어져있는 노드를 구함
	DFS(1, 0);
	max_dist = 0;
	std::fill(visited.begin(), visited.end(), false);

	// DFS(1, 0)을 통해 구한 가장 노드로부터 가장 멀리떨어져 있는 노드를 구함
	// 이를 통해 구해진 거리가 바로 트리의 지름
	DFS(far_node, 0);

	std::cout << max_dist;
	return 0;
}