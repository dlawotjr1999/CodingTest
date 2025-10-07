#include <iostream>

// ķ���忡�� ���� ���ư��� ����� �������� ���ϴ� ����
// ķ������ ���� ���� �Ʒ��� ������, ���� ������ ���� ��ġ��
// �� �� ������ ���� �湮���� ������, T�� ǥ�õ� ���� ���� ���ϴ� ��

static constexpr int MAX = 6;

char field[MAX][MAX];
bool visited[MAX][MAX];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int R, C, K;
int answer;

void DFS(int y, int x, int dist) {
	// ����ġ�� : �Ÿ��� K�� ������ �ǵ��ư�
	if (dist > K)
		return;

	// K�� �Ÿ��� ���� �����ϸ� ����
	if ((y == 0 && x == C - 1) && dist == K) {
		answer++;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];

		if ((0 <= new_x && new_x < C) && (0 <= new_y && new_y < R)) {
			// ���� ���ϴ� ���� �ǳʶ�
			if (field[new_y][new_x] == 'T')
				continue;
			if (!visited[new_y][new_x]) {
				visited[new_y][new_x] = true;
				DFS(new_y, new_x, dist + 1);
				visited[new_y][new_x] = false;
			}
		}
	}
}

int main() {
	std::cin >> R >> C >> K;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cin >> field[i][j];
		}
	}

	// ���� ���� �ϴܿ��� ���
	visited[R - 1][0] = true;
	DFS(R - 1, 0, 1);

	std::cout << answer;
	return 0;
}