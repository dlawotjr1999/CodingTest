#include <bits/stdc++.h>

// ���� U�� ��Ʈ�� �ϴ� ����Ʈ���� ���� ������ ���� ���ϴ� ����

int N, R, Q;

std::vector<int> tree[100001];
// ����Ʈ���� ����� ������ �����ϴ� �迭
int DP[100001];

int DFS(int cur, int parent) {
	// �ڱ� �ڽ� ����
	DP[cur] = 1;

	// ���� ������ ��������� Ž��
	// �ܸ� ����� ��쿡�� �ݺ����� ������� �ʰ� 1�� ��ȯ��
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
	
	// ��Ʈ ���� �θ� ��尡 ����
	DFS(R, -1);

	while (Q--) {
		int U;
		std::cin >> U;
		std::cout << DP[U] << '\n';
	}

	return 0;
}