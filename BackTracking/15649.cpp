#include <iostream>

// ��Ʈ��ŷ�� Ȱ���� ���� ���� ����

int N, M;
int ary[9];
bool visited[9];

void DFS(int cnt) {
	// ���� ����: M���� ���ڰ� ��� ���õǾ��� �� ���
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	// 1���� N������ ���� �߿��� ������ �� �ִ� ���ڸ� �õ�
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ary[cnt] = i;
			// ���� �ڸ��� �����ϱ� ���� DFS�� ��������� ȣ��
			DFS(cnt + 1);
			// ��Ͱ� ���� ��, ��Ʈ��ŷ (i�� �������� �ʾҴٰ� ǥ��)
			visited[i] = false;
		}
	}
}

int main() {
	std::cin >> N >> M;
	DFS(0);

	return 0;
}