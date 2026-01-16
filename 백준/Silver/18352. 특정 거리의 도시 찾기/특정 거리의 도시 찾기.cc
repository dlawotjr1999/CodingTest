#include <bits/stdc++.h>	

const int MAX = 300001;
std::vector<int> field[MAX];

int N, M, K, X;

std::vector<int> BFS(int s) {
	std::vector<bool> visited(N + 1, false);
	std::queue<std::pair<int, int>> q;
	
	q.emplace(s, 0);
	visited[s] = true;

	std::vector<int> nodes;
	while (!q.empty()) {
		auto [cur, dist] = q.front();
		q.pop();

		if (dist == K) {
			nodes.push_back(cur);
			continue;
		}

		for (int node : field[cur]) {
			if (!visited[node]) {
				visited[node] = true;
				q.emplace(node, dist + 1);
			}
		}
	}

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

	std::vector<int> vec = std::move(BFS(X));
	std::sort(vec.begin(), vec.end());

	for (int i : vec) {
		std::cout << i << '\n';
	}
	return 0;
}