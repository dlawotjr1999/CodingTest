#include <iostream>
#include <queue>

// ����� �������� �����鼭 �踦 ä�� ��, �ִ�ġ�� ������ �������� ���ϴ� ����
// �߰��� ���� �� �� ���ø� ���ݱ����� �������� ������ ���� �� ���� 

constexpr int MAX = 5000001;

int T, A, B;
int answer;

// ���� ������ ���� ������ �ʾ��� ���� �����ϱ� ���� visited �迭�� 2�������� ����
bool visited[2][MAX];

// �� ������ �������� ���� ���, ������ ���� ���, ���� ���ô� ��� �� ������ Ʈ���������� ������
void BFS(int drink, int fullness) {
	std::queue<std::pair<int, int>> q;
	q.push({ drink, fullness });
	visited[drink][fullness] = true;

	while (!q.empty()) {
		auto [d, f] = q.front();
		q.pop();

		answer = std::max(answer, f);

		// ���� ���Ͽ� ���� ����� ���� Ž����
		for (int fruit : {A, B}) {
			int cur_f = f + fruit;
			if (cur_f <= T && !visited[d][cur_f]) {
				visited[d][cur_f] = true;
				q.push({d, cur_f});
			}
		}

		// ���� ������ ���� ���
		// ���� ���ð�, �� flag�� ǥ���� ���� �ٽ� queue�� ���� 
		if (d == 0) {
			int cur_f = f / 2;
			if (!visited[1][cur_f]) {
				visited[1][cur_f] = true;
				q.push({ 1, cur_f });
			}
		}
	}
}

int main() {
	std::cin >> T >> A >> B;
	BFS(0, 0);

	std::cout << answer;
	return 0;
}