#include <bits/stdc++.h>

// � Ʈ���� ��Ʈ�� 1�̶�� ������ ��, �� ����� �θ� ���ϴ� ����
// ����� �� ������ �־�����, �� ����� �θ� ��带 2�� ������ ������� ���

int N;
std::vector<std::vector<int>> tree;
std::vector<int> parent;

// DFS�� Ȱ���Ͽ� Ž�� ����
// ���� ��忡�� ����� ��带 Ž���ϸ�, ����Ǿ� �ִ� ������ �θ� �ٷ� ���� �����
void DFS(int start) {
	for (int& node : tree[start]) {
		if (parent[node] == -1) {
			parent[node] = start;
			DFS(node);
		}
	}
}

int main() {
	std::cin >> N;
	tree.resize(N + 1);
	// �θ� ����� ������ ��� vector�� -1�� �ʱ�ȭ
	parent.resize(N + 1, -1);

	for (int i = 1; i <= N - 1; ++i) {
		int a, b; 
		std::cin >> a >> b;

		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}

	// ��Ʈ ���� ������ ���ڸ� �θ� ���� ������, ���� 1�� ������ Ž��
	parent[1] = 0;
	DFS(1);

	for (int i = 2; i <= N; ++i) {
		std::cout << parent[i] << '\n';
	}
	return 0;
}