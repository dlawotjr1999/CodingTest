#include <bits/stdc++.h>

int N;
int answer = 10e6;
int start_point;

int field[11][11];
bool visited[11];

void DFS(int cur, int cost, int cnt) {
	if (cost >= answer)
		return;
	
	if (cnt == N - 1 && field[cur][start_point]) {
		answer = std::min(answer, cost + field[cur][start_point]);
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (field[cur][i] && !visited[i]) {
			visited[i] = true;
			DFS(i, cost + field[cur][i], cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	std::cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		start_point = i;
		visited[i] = true;
		DFS(i, 0, 0);
		visited[i] = false;
	}

	std::cout << answer;
	return 0;
}