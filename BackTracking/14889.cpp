#include <iostream>

// ������ �ɷ�ġ�� ����Ǿ��ִ� 2���� �ʵ尡 ���� ��, �̸� ���� ��ŸƮ ���� ��ũ ���� �����Ϸ��� ��
// �� �� ��ŸƮ ���� �ɷ�ġ�� ��ũ �� �� ���������� �ɷ�ġ�� ���� ���̰� �ּҰ� �Ǵ� ���� ���ϴ� ���� 

constexpr int MAX = 21;

int N;
int answer = 1e9;

int board[MAX][MAX];
bool visited[MAX];

void min_score() {
	int start = 0;
	int link = 0;

	// ��ŸƮ ���� ��ũ �� ���������� �ɷ�ġ ���� ����
	// Backtracking�� ���� N / 2���� ������ ã�� ��, ������ (N - N / 2)�� ����ϸ� �ɷ�ġ ���
	// ���� ���, N = 6�� �� ��ŸƮ ������ (1,2,4)�� ���õǾ��ٸ�(visited), ��ũ ���� (3,5,6)�� ��(!visited)   
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i] && visited[j]) {
				start += board[i][j];
			}
			else if (!visited[i] && !visited[j]) {
				link += board[i][j];
			}
		}
	}

	int diff = start >= link ? (start - link) : (link - start);
	answer = std::min(diff, answer);
}

// Backtracking�� ���ؼ� ���� ������ �� �ִ� ������ ã��
void select(int cnt, int idx) {
	// �� ���� N / 2�� �����Ǿ� ����
	// N / 2������ Ž���� ������ �������� �� ���� �ɷ�ġ ���� ���
	if (cnt == N / 2) {
		min_score();
		return;
	}

	for (int i = idx; i < N; i++) {
		visited[i] = true;
		select(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> board[i][j];
		}
	}

	select(0, 0);
	std::cout << answer;

	return 0;
}