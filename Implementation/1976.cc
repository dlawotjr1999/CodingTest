#include <bits/stdc++.h>

// N���� ���ð� ���� ��, ���� ������ ���� ������ �ϴ� ���õ��� ��� ��ȸ�� �� �ִ��� �Ǻ��ϴ� ����
// ���ô� ��������� ����Ǿ� ������, ���� �� ��� ���δ� ����Ǿ� ���� ����
// ���� ���� ���ø� ���� �� ��ġ�鼭 ������ �ϴ� ���� ������

// ��� ��θ� �湮�� �� �ִ� ���� ���� ��ȹ �� �� ���õ��� �ϳ��� ����Ǿ� �ִ� �����(��, �ϳ��� ������Ʈ�� ������)
// DFS/BFS�� ���� ������Ʈ�� ���� ���� ���� ������, Union-Find�� Ȱ���Ͽ� �� ���õ��� ����Ǿ� �ִ���(root�� ��������)�� �Ǻ���

int cities[201][201];
std::vector<int> union_vec;
std::vector<int> plans;

int Find(int parent) {
	if (parent == union_vec[parent])
		return parent;
	return union_vec[parent] = Find(union_vec[parent]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;
	union_vec[b] = a;
}

int main() {
	int N, M;
	std::cin >> N;
	std::cin >> M;
	union_vec.resize(N + 1, 0);

	for(int i = 1; i <= N; ++i) {
		union_vec[i] = i;

		for(int j = 1; j <= N; ++j) {
			std::cin >> cities[i][j];
		}	
	}

	for(int i = 0; i < M; ++i) {
		int plan;
		std::cin >> plan;
		plans.push_back(plan);
	}

	// i�� j�� ���� �������� Ȯ���ϰ�, �ٸ� ��쿡�� Union ����
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if(cities[i][j] && Find(i) != Find(j))
				Union(i, j);
		}
	}

	// �Էµ� ���� ��ȹ �� ù ��° ���ú��� �湮
	int root = union_vec[plans[0]];	
	for (int i = 1; i < M; ++i) {
		if (Find(plans[i]) != root) {
			std::cout << "NO";
			return 0;
		}
	}

	std::cout << "YES";
	return 0;
}