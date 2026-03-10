#include <bits/stdc++.h>

// 어떤 모임에서 회장을 선출하려고 하며, 회장은 회원들 중에서 점수가 가장 작은 사람이 됨
// 각 회원은 다른 회원들과 가까운 정도에 따라 점수를 받게 됨
// 예를 들어 어느 회원이 다른 모든 회원과 친구이면 이 회원의 점수는 1점이며, 어느 회원의 점수가 2점이면 다른 모든 회원이 친구이거나 친구의 친구임을 의미함
// 3점, 4점, 5점 모두 같은 방법으로 정해짐
// 이 때, 회장 후보의 점수와 후보의 수, 그리고 회장 후보를 오름차순으로 구하는 문제

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

	// BFS 탐색이 종료된 후 dist에서 가장 큰 값, 즉 그 회원의 점수를 구함
	// (특정 회원의 점수, 특정 회원의 번호) 순서쌍을 answers에 저장
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

		// 친구 관계를 나타내므로 무향 그래프로 생성
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	// 친구가 있는 회원들에 대해서 BFS로 점수 계산
	for (int i = 1; i <= 50; ++i) {
		if (graph[i].size() == 0)
			continue;
		BFS(i);
	}

	// 회원 별 점수 순으로 오름차순 정렬
	// 회장 후보의 점수는 그 중 가장 작은 점수
	// 회장 후보의 수는 그 점수를 가진 회원의 수
	std::sort(answers.begin(), answers.end());
	score = answers[0].first;
	num = std::upper_bound(answers.begin(), answers.end(), score, [](auto k, auto const& p) { return k < p.first; }) - answers.begin();

	// 회장 후보들의 번호를 순서대로 출력
	std::cout << score << ' ' << num << '\n';
	for (const auto answer : answers) {
		if(answer.first == score)
			std::cout << answer.second << ' ';
	}

	return 0;
}