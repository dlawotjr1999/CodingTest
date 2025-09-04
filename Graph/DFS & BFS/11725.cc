#include <bits/stdc++.h>

// 어떤 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 문제
// 연결된 두 노드들이 주어지며, 각 노드의 부모 노드를 2번 노드부터 순서대로 출력

int N;
std::vector<std::vector<int>> tree;
std::vector<int> parent;

// DFS를 활용하여 탐색 시작
// 현재 노드에서 연결된 노드를 탐색하며, 연결되어 있는 노드들의 부모가 바로 현재 노드임
void DFS(int start) {
	for (int& node : tree[start]) {
		if (parent[node] == -1) {
			parent[node] = start;
			DFS(node);
		}
	}
}

int main() {
	std::cin >> N;
	tree.resize(N + 1);
	// 부모 노드의 정보를 담는 vector는 -1로 초기화
	parent.resize(N + 1, -1);

	for (int i = 1; i <= N - 1; ++i) {
		int a, b; 
		std::cin >> a >> b;

		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}

	// 루트 노드는 임의의 숫자를 부모 노드로 가정함, 이후 1번 노드부터 탐색
	parent[1] = 0;
	DFS(1);

	for (int i = 2; i <= N; ++i) {
		std::cout << parent[i] << '\n';
	}
	return 0;
}