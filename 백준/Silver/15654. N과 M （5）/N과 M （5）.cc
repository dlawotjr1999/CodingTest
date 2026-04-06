#include <bits/stdc++.h>

void DFS(std::vector<int>& vec, std::vector<bool>& visited, std::vector<int>& cur, int M) {
	if (cur.size() == M) {
		for (int elm : cur)
			std::cout << elm << ' ';
		std::cout << '\n';
		return;
	}

	for (int i = 0; i < vec.size(); ++i) {
		if (!visited[i]) {
			visited[i] = true;
			cur.push_back(vec[i]);
			DFS(vec, visited, cur, M);
			cur.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<int> vec(N, 0);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	std::sort(vec.begin(), vec.end());

	std::vector<int> cur;
	std::vector<bool> visited(N, false);
	DFS(vec, visited, cur, M);

	return 0;
}