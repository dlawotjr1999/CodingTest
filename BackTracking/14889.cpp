#include <iostream>

// 각자의 능력치가 기재되어있는 2차원 필드가 있을 때, 이를 토대로 스타트 팀과 링크 팀을 구성하려고 함
// 이 때 스타트 팀의 능력치와 링크 팀 각 구성원들의 능력치의 합의 차이가 최소가 되는 값을 구하는 문제 

constexpr int MAX = 21;

int N;
int answer = 1e9;

int board[MAX][MAX];
bool visited[MAX];

void min_score() {
	int start = 0;
	int link = 0;

	// 스타트 팀과 링크 팀 구성원들의 능력치 합을 구함
	// Backtracking을 통해 N / 2개의 조합을 찾은 뒤, 나머지 (N - N / 2)를 고려하며 능력치 계산
	// 예를 들어, N = 6일 때 스타트 팀에서 (1,2,4)가 선택되었다면(visited), 링크 팀은 (3,5,6)이 됨(!visited)   
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i] && visited[j]) {
				start += board[i][j];
			}
			else if (!visited[i] && !visited[j]) {
				link += board[i][j];
			}
		}
	}

	int diff = start >= link ? (start - link) : (link - start);
	answer = std::min(diff, answer);
}

// Backtracking을 통해서 팀을 구성할 수 있는 조합을 찾음
void select(int cnt, int idx) {
	// 각 팀은 N / 2명씩 구성되어 있음
	// N / 2까지의 탐색을 마쳤을 시점에서 각 팀의 능력치 합을 계산
	if (cnt == N / 2) {
		min_score();
		return;
	}

	for (int i = idx; i < N; i++) {
		visited[i] = true;
		select(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> board[i][j];
		}
	}

	select(0, 0);
	std::cout << answer;

	return 0;
}