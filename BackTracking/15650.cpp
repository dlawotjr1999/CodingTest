#include <iostream>

// ��Ʈ��ŷ�� Ȱ���� ���� ���� ����2
// ������ ������ ���������̾�� ��

int N, M;
int ary[9];
bool visited[9];

// ���������� �����ϱ� ���� num ������ ���ڷ� �߰�
void DFS(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	// for���� ������ num. �� ���۵Ǵ� ��ȣ�� ����
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