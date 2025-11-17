#include <iostream>
#include <vector>
#include <queue>

int N, M;

int BFS(std::vector<int>& truth, std::vector<std::vector<int>>& party, std::vector<std::vector<int>>& graph) {
	int cnt = 0;
	
	std::vector<bool> know_truth(N + 1, false);
	std::queue<int> q;

	for (int x : truth) {
		know_truth[x] = true;
		q.push(x);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : graph[cur]) {
			if (!know_truth[next]) {
				know_truth[next] = true;
				q.push(next);
			}
		}
	}

	for (auto& p : party) {
		bool hasTruth = false;

		for (int elm : p) {
			if (know_truth[elm]) {
				hasTruth = true;
				break;
			}
		}
		if (!hasTruth)
			cnt++;
	}

	return cnt;
}

int main() {
	std::cin >> N >> M;

	int t; std::cin >> t;
	std::vector<int> truth(t);

	for (int i = 0; i < t; ++i) {
		std::cin >> truth[i];
	}

	std::vector<std::vector<int>> party(M);
	for (int i = 0; i < M; ++i) {
		int cnt; std::cin >> cnt;
		party[i].resize(cnt);

		for (int j = 0; j < cnt; ++j) {
			std::cin >> party[i][j];
		}
	}

	std::vector<std::vector<int>> graph(N + 1);
	for (auto& p : party) {
		for (int i = 0; i < p.size(); i++) {
			for (int j = i + 1; j < p.size(); j++) {
				int a = p[i], b = p[j];
				graph[a].push_back(b);
				graph[b].push_back(a);
			}
		}
	}

	std::cout << BFS(truth, party, graph);
	return 0;
}