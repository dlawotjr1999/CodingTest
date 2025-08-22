#include <bits/stdc++.h>

// N*N 크기의 꽃밭에 세 개의 꽃을, 아래의 조건을 충족시키면서 심고자 함
// 꽃은 씨앗을 심은 곳 기준으로 십자가 모양으로 피며, 꽃잎이 겹치거나 꽃밭 밖으로 나가면 꽃이 죽어버림
// 세 개의 꽃이 죽지 않도록 꽃을 심을 때, 그 최소 비용을 구하는 문제

int N;
int answer = 10e6;

int field[11][11];
bool visited[11][11];

void DFS(int cost, int cnt) {
	// 세 개의 꽃을 심었을 때 탐색을 종료하고 비용을 갱신함
	if (cnt == 3) {
		answer = std::min(answer, cost);
		return;
	}

	// 경계면(1, N)에 씨앗을 심으면 꽃이 필 수 없기 때문에, 경계면은 고려하지 않음
	for (int i = 2; i <= N - 1; ++i) {
		for(int j = 2; j <= N - 1; ++j) {
			// 꽃이 존재하는 자리는 건너뜀
			if (visited[i][j] || visited[i - 1][j] || visited[i + 1][j] || visited[i][j - 1] || visited[i][j + 1]) 
				continue;

			// 꽃은 심은 곳을 기준으로 사방위로 피기 때문에 다섯 칸을 고려하여 탐색을 진행함
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