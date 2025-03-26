#include <iostream>

// 백트래킹을 활용한 순열 생성 문제

int N, M;
int ary[9];
bool visited[9];

void DFS(int cnt) {
	// 기저 조건: M개의 숫자가 모두 선택되었을 때 출력
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	// 1부터 N까지의 숫자 중에서 선택할 수 있는 숫자를 시도
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ary[cnt] = i;
			// 다음 자리를 선택하기 위해 DFS를 재귀적으로 호출
			DFS(cnt + 1);
			// 재귀가 끝난 후, 백트래킹 (i를 선택하지 않았다고 표시)
			visited[i] = false;
		}
	}
}

int main() {
	std::cin >> N >> M;
	DFS(0);

	return 0;
}