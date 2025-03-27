#include <iostream>

// 백트래킹을 활용한 순열 생성 문제2
// 생성된 순열은 오름차순이어야 함

int N, M;
int ary[9];
bool visited[9];

// 오름차순을 구현하기 위해 num 변수를 인자로 추가
void DFS(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	// for문의 시작을 num. 즉 시작되는 번호로 설정
	for (int i = num; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ary[cnt] = i;
			DFS(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	std::cin >> N >> M;
	DFS(1, 0);

	return 0;
}