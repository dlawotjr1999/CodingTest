#include <iostream>
#include <queue>

// N에서 다음 칸으로 1초 후에 이동할 수 있는 방법은 아래 세 개가 존재함
// X-1, X+1, 2*X(순간이동)
// 이 때 N에서 K로 이동하는 가장 빠른 시간을 구하는 문제
// 최단 시간을 구해야 하므로 DFS보다는 BFS가 적합함

constexpr int MAX = 100000;

int N, K;
bool visited[100001];

int BFS(int start) {
	std::queue<std::pair<int, int>> q;

	visited[start] = true;
	q.emplace(start, 0);	// 최초 시점이므로 시간(depth)은 0

	while (!q.empty()) {
		int x = q.front().first;
		int depth = q.front().second;
		q.pop();

		// 현재 지점과 목적지가 동일한 경우 그 시간을 리턴
		if (x == K)
			return depth;

		int moves[3] = { 2 * x, x + 1, x - 1 };

		for (const int move : moves) {
			// 범위를 벗어나거나 이미 방문한 지점은 건너뜀
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