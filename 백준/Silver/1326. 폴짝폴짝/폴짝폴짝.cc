#include <iostream>
#include <vector>
#include <queue>

int N;
std::vector<int> field;

int BFS(int start, int end) {
	std::vector<bool> visited(N + 1, false);
	std::queue<std::pair<int, int>> q;
	
	q.emplace(start, 0);
	visited[start] = true;

	while (!q.empty()) {
		auto [cur, dist] = q.front();
		int jump = field[cur];
		q.pop();

		if (cur == end) 
			return dist;

		for (int next = cur + jump; next <= N; next += jump) {
			if (!visited[next]) {
				visited[next] = true;
				q.emplace(next, dist + 1);
			}
		}

		for (int next = cur - jump; next >=  1; next -= jump) {
			if (!visited[next]) {
				visited[next] = true;
				q.emplace(next, dist + 1);
			}
		}
	}

	return -1;
}

int main() {
	std::cin >> N;
	field.resize(N + 1);
	
	for (int i = 1; i <= N; ++i) {
		std::cin >> field[i];
	}

	int a, b;	
	std::cin >> a >> b;

	std::cout << BFS(a, b);
	return 0;
}