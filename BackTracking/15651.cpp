#include <iostream>

// 백트래킹을 활용한 순열 생성 문제2
// 중복을 허용하여 순열을 생성
// 방문 여부를 확인하는 visited를 사용하지 않으면 중복을 허용할 수 있음

int N, M;
int ary[9];

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		ary[cnt] = i;
		DFS(cnt + 1);
	}
}

int main() {
	std::cin >> N >> M;
	DFS(0);

	return 0;
}