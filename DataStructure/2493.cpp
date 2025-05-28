#include <iostream>
#include <vector>
#include <stack>

// �Ϸķ� ������ ž���� ���� �������� �������� �߻��� ��, �۽��� ������ ��ȣ�� ��� ž���� �����ߴ��� ���ϴ� ����
// �۽ŵ� �������� ���� ���� ������ ž���� ������ ������
// �ϳ��� ž�� ���� ���̰� ���� ž���� �۽��� ���������� ������ �� ����

int main() {
	int N;
	std::cin >> N;

	std::stack<std::pair<int, int>> s;
	std::vector<int> answer(N + 1);

	for (int i = 1; i <= N; i++) {
		int height;
		std::cin >> height;

		// ���� ž���� �۽��� �������� ������ �� �ִ� ž�� �����ϴ� �� Ȯ����
		// ������ top�� ���� ž�� ���̺��� ���� ��쿡�� �������� ������ �� �����Ƿ� pop�� ����
		while (!s.empty() && s.top().second < height) {
			s.pop();
		}
		// ������ ���������, �� ���� ž���� �۽��� �������� ���� ž�� ���� ��쿡�� 0�� ���
		// �׷��� ������, �� �۽��� �������� ���� ž�� ������ ������ ž�� index�� ���
		answer[i] = s.empty() ? 0 : s.top().first;
		s.emplace(i, height);
	}

	for (int i = 1; i <= N; i++) 
		std::cout << answer[i] << ' ';
	return 0;
}