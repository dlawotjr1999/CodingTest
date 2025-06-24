#include <iostream>
#include <queue>

constexpr int MAX = 100000;

int N, K;
bool visited[100001];

int BFS(int start) {
	std::queue<std::pair<int, int>> q;

	visited[start] = true;
	q.emplace(start, 0);

	while (!q.empty()) {
		int x = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (x == K)
			return depth;

		int moves[3] = { 2 * x, x + 1, x - 1 };

		for (const int move : moves) {
			if (move < 0 || move > MAX || visited[move])
				continue;
			visited[move] = true;
			q.emplace(move, depth + 1);
		}
	}
	return -1;
}

int main() {
	std::cin >> N >> K;

	std::cout << BFS(N);

	return 0;
}