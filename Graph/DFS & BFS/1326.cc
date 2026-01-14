#include <iostream>
#include <vector>
#include <queue>

// 개구리가 일렬로 놓인 징검다리 사이를 뛰어다니고 있음
// 이 개구리는 어떤 징검다리에서 점프를 할 때는 그 징검다리에 쓰여 있는 수의 배수만큼 떨어져 있는 곳으로만 갈 수 있음
// 이 때, 개구리가 a번째 징검다리에서 b번째 징검다리로 이동하기 위해 최소 몇 번의 점프를 해야하는지 구하는 문제 

int N;
std::vector<int> field;

int BFS(int start, int end) {
	std::vector<bool> visited(N + 1, false);
	std::queue<std::pair<int, int>> q;
	
	q.emplace(start, 0);
	visited[start] = true;

	// 점프에 방향에 대한 제약이 없음
	// 즉 양방향으로 모두 이동이 가능함
	while (!q.empty()) {
		auto [cur, dist] = q.front();
		q.pop();

		// 현재 위치한 징검다리에 쓰여있는 수를 구함
		int jump = field[cur];

		// 목적지에 도달하면 점프 횟수를 return
		if (cur == end) 
			return dist;

		// 오른쪽으로 이동하는 경우
		// 현재 징검다리에서 오른쪽으로 jump만큼 떨어져있는 징검다리들 탐색
		for (int next = cur + jump; next <= N; next += jump) {
			if (!visited[next]) {
				visited[next] = true;
				q.emplace(next, dist + 1);
			}
		}
		
		// 왼쪽으로 이동하는 경우
		// 현재 징검다리에서 왼쪽으로 jump만큼 떨어져있는 징검다리들 탐색
		for (int next = cur - jump; next >= 1; next -= jump) {
			if (!visited[next]) {
				visited[next] = true;
				q.emplace(next, dist + 1);
			}
		}
	}

	// a에서 b로 도달할 수 없는 경우에는 -1
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