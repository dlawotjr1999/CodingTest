#include <bits/stdc++.h>

// TSP�� ������ ����. �� ���ǿ��� ��� �� ���ÿ��� ����� N���� ���ø� ��� ���� �ٽ� ������ ���÷� ���ƿ��� ��ȸ ���� ��θ� ��ȹ�Ϸ��� ��
// �� �� ���� ���ô� �ٽ� �湮�� �� ������, ���ø� �պ��ϴ� �� ��� ����� ���� �� �� �ٸ� ���� ����
// �� ��, ��� ���ø� �����ϰ� �ٽ� ó�� ���÷� ���ƿ��µ� �ּ� ����� ���ϴ� ����

int N;
int answer = 10e6;
int start_point;

int field[11][11];
bool visited[11];

void DFS(int cur, int cost, int cnt) {
	// ����ġ�� : Ư�� ������ ��������� �亸�� ū ��쿡�� return
	if (cost >= answer)
		return;
	
	// ��� ���ø� �湮�� �� ó�� ���÷� ���ư� ���� ���
	// ó�� �湮�� ���ø� ������ N - 1���� ���� �湮�� �����ϰ�, ������ ���ÿ��� ó�� ���÷� ���ư��� ��ΰ� ���� �� ����� ������
	if (cnt == N - 1 && field[cur][start_point]) {
		answer = std::min(answer, cost + field[cur][start_point]);
		return;
	}

	// ��� ���õ��� Ž��
	for (int i = 1; i <= N; ++i) {
		// ���� ���ÿ��� ��ΰ� �ִ� ���÷� BackTracking ����
		if (field[cur][i] && !visited[i]) {
			visited[i] = true;
			DFS(i, cost + field[cur][i], cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	std::cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		start_point = i;
		visited[i] = true;
		// Ž���� ���ڷ� ���� ����, ������ ���, �湮�� ������ ������ ���
		DFS(i, 0, 0);
		visited[i] = false;
	}

	std::cout << answer;
	return 0;
}