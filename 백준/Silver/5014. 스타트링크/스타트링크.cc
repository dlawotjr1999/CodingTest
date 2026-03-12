#include <bits/stdc++.h>

int F, S, G, U, D;

void BFS() {
	std::vector<bool> visited(F + 1, false);
	std::queue<std::pair<int, int>> q;

	q.emplace(S, 0);
	visited[S] = true;

	int answer = 0;	bool isFound = false;
	while (!q.empty()) {
		auto [cur, cnt] = q.front();
		q.pop();

		if (cur == G) {
			answer = cnt;
			isFound = true;
			break;
		}

		for (int next : {cur + U, cur - D}) {
			if (next < 1 || next > F)
				continue;
			if (visited[next])
				continue;

			visited[next] = true;
			q.emplace(next, cnt + 1);
		}
	}

	if (isFound)
		std::cout << answer;
	else
		std::cout << "use the stairs";
}

int main() {
	std::cin >> F >> S >> G >> U >> D;
	BFS();
	return 0;
}