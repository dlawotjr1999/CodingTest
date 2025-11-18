#include <iostream>
#include <vector>
#include <queue>

// 주인공이 파티에서 되도록 과장해서 거짓으로 이야기를 하려고 함
// 파티에 참여하는 일부는 그 이야기의 진실을 알기 때문에, 그러한 사람이 파티에 있는 경우 파티에서 진실을 이야기할 수 밖에 없음
// 어떤 사람이 어떤 파티에서 진실을 듣고, 다른 파티에서 과장된 이야기를 듣는 경우에도 거짓말임이 들통나게 됨
// 이 때, 과장된 이야기를 할 수 있는 파티 갯수의 최댓값을 구하는 문제

int N, M;

int BFS(std::vector<int>& truth, std::vector<std::vector<int>>& party, std::vector<std::vector<int>>& graph) {
	int cnt = 0;
	
	std::vector<bool> know_truth(N + 1, false);
	std::queue<int> q;

	// 진실을 아는 사람들을 모두 큐에 삽입하여 관계 탐색
	for (int x : truth) {
		know_truth[x] = true;
		q.push(x);
	}

	// 진실을 아는 사람과 연결된 관계에 있는 사람들은 모두 진실을 알게 될 수 있는 사람들임
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

	// 하나의 파티에 대해 진실을 아는 사람, 혹은 진실을 알게 될 사람이 한 명이라도 있으면 참여가 불가능한 파티
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

	// 진실이 알려질 수 있는 관계를 표현하는 그래프 구성
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