#include <iostream>

int N, M;
int ary[9];
bool visited[9];

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