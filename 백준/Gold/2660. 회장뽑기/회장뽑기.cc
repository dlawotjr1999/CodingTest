#include <bits/stdc++.h>

int N;

std::vector<int> graph[51];
std::vector<std::pair<int, int>> answers;

void BFS(int node) {
	std::queue<int> q;
	std::vector<bool> visited(51, false);
	
	int dist[51];
	memset(dist, 0, sizeof(dist));

	q.emplace(node);
	visited[node] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : graph[cur]) {
			if (visited[next])
				continue;
			visited[next] = true;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}

	int max_dist = *std::max_element(dist, dist + 51);
	answers.emplace_back(max_dist, node);
}

int main() {
	std::cin >> N;
	int score = 0, num = 0;

	while (true) {
		int a, b;
		std::cin >> a >> b;

		if (a == -1 && b == -1)
			break;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for (int i = 1; i <= 50; ++i) {
		if (graph[i].size() == 0)
			continue;
		BFS(i);
	}

	std::sort(answers.begin(), answers.end());
	score = answers[0].first;
	num = std::upper_bound(answers.begin(), answers.end(), score, [](auto k, auto const& p) { return k < p.first; }) - answers.begin();

	std::cout << score << ' ' << num << '\n';
	for (const auto answer : answers) {
		if(answer.first == score)
			std::cout << answer.second << ' ';
	}

	return 0;
}