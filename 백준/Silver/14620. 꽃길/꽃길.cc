#include <bits/stdc++.h>

int N;
int answer = 10e6;

int field[11][11];
bool visited[11][11];

void DFS(int cost, int cnt) {
	if (cnt == 3) {
		answer = std::min(answer, cost);
		return;
	}

	for (int i = 2; i <= N - 1; ++i) {
		for(int j = 2; j <= N - 1; ++j) {
			if (visited[i][j] || visited[i - 1][j] || visited[i + 1][j] || visited[i][j - 1] || visited[i][j + 1]) 
				continue;

			visited[i][j] = true;
			visited[i - 1][j] = true; 
			visited[i + 1][j] = true; 
			visited[i][j - 1] = true; 
			visited[i][j + 1] = true; 
			int new_cost = cost + (field[i][j] + field[i - 1][j] + field[i + 1][j] +
				field[i][j - 1] + field[i][j + 1]);
			DFS(new_cost, cnt + 1);
			visited[i][j] = false;
			visited[i - 1][j] = false; 
			visited[i + 1][j] = false; 
			visited[i][j - 1] = false; 
			visited[i][j + 1] = false; 
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

	DFS(0, 0);

	std::cout << answer;
	return 0;
}