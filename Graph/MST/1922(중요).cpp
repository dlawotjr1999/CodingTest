#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// MST를 구하는 기본 문제2
// Kruskal Algorithm 사용

const int MAX = 100001;
const int INF = std::numeric_limits<int>::max();

int N, M;
std::vector<int> parent(MAX);

int Find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b)
		parent[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(0);;
	std::cin.tie(0);

	std::cin >> N >> M;

	std::vector<std::pair<int, std::pair<int, int>>> edges;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });
	}

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	std::sort(edges.begin(), edges.end());

	int mst_weight = 0;
	std::vector<std::pair<int, int>> mst_edges;

	for (const auto& edge : edges) {
		int weight = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;

		if (Find(u) != Find(v)) {
			Union(u, v);
			mst_weight += weight;
			mst_edges.push_back({ u, v });
		}
	}
	std::cout << mst_weight << std::endl;

	return 0;
}