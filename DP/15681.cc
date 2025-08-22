#include <bits/stdc++.h>

// 정점 U를 루트로 하는 서브트리에 속한 정점의 수를 구하는 문제

int N, R, Q;

std::vector<int> tree[100001];
// 서브트리의 노드의 갯수를 저장하는 배열
int DP[100001];

int DFS(int cur, int parent) {
	// 자기 자신 포함
	DP[cur] = 1;

	// 하위 노드들을 재귀적으로 탐색
	// 단말 노드인 경우에는 반복문이 실행되지 않고 1을 반환함
	for (int next : tree[cur]) {
		if (next == parent) continue;
		DP[cur] += DFS(next, cur);
	}

	return DP[cur];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> N >> R >> Q;

	for(int i = 0; i < N - 1; ++i) {
		int U, V;
		std::cin >> U >> V;

		tree[U].emplace_back(V);
		tree[V].emplace_back(U);
	}
	
	// 루트 노드는 부모 노드가 없음
	DFS(R, -1);

	while (Q--) {
		int U;
		std::cin >> U;
		std::cout << DP[U] << '\n';
	}

	return 0;
}