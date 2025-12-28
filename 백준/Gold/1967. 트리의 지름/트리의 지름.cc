#include <iostream>
#include <vector>
#include <queue>

const int MAX = 10001;

std::vector<std::pair<int, int>> tree[MAX];
std::vector<bool> visited(MAX);

int max_dist = 0;
int far_node = 1;

void DFS(int cur, int dist) {
	visited[cur] = true;

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

		tree[a].emplace_back(b, c);
		tree[b].emplace_back(a, c);
	}

	DFS(1, 0);
	max_dist = 0;
	std::fill(visited.begin(), visited.end(), false);
	DFS(far_node, 0);

	std::cout << max_dist;
	return 0;
}