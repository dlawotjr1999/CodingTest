#include <iostream>

// ������ �����ϴ� ����
// https://www.acmicpc.net/problem/17070

static constexpr int MAX = 16;

int N, answer;
int field[MAX][MAX];

void DFS(int x, int y, int dir) {
	// (N-1, N-1)�� �����ϸ� �ùٸ� ������ ��ġ
	if (x == N - 1 && y == N - 1) {
		answer++;
		return;
	}

	// ���� ������ ���� �Ǵ� �밢���� ��쿡 ���� �������� ���� �� ����
	if (dir == 0 || dir == 2) {
		int nx = x + 1, ny = y;
		if (nx < N && field[ny][nx] == 0)
			DFS(nx, ny, 0);
	}

	// ���� ������ ���� �Ǵ� �밢���� ��쿡 ���� �������� ���� �� ����
	if (dir == 1 || dir == 2) {
		int nx = x, ny = y + 1;
		if (ny < N && field[ny][nx] == 0)
			DFS(nx, ny, 1);
	}

	// ���� ������ �밢���� ��� ��� ������ ���� �� ����
	// �밢�� ���⿡ ���� ���, (x+1, y+1), (x, y+1), (x+1, y) �� ĭ�� ��� ����־�� ��
	int nx = x + 1, ny = y + 1;
	if (nx < N && ny < N && field[ny][nx] == 0 && field[ny - 1][nx] == 0 && field[ny][nx - 1] == 0)
		DFS(nx, ny, 2);
}


int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> field[i][j];
		}
	}

	// 0-based�� �Ͽ� Ž�� ����
	DFS(1, 0, 0);

	std::cout << answer;
	return 0;
}