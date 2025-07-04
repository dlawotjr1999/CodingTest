#include <iostream>
#include <vector>
#include <queue>

// �Ϸķ� ���� �� ����鿡�� �� ���� �� �������� ���ڸ� �����ַ��� ��
// ���� �� ������� �� ������ ������ �� �ڷ� �̵��ϰ� �ٽ� ������ �;� ���� ������ ���� �� ����
// �� ��, �� �ο��� ���ϴ¸�ŭ ���� ������ ��� �������� �󸶳� ��⸦ �ؾ��ϴ����� ���ϴ� ����

int main() {
	int N;
	std::cin >> N;
	
	// ���� �����ϱ� ���� ť�� ���
	// ť�� (�ʿ��� ���� ���� ��, �ε���)�� �������� ����
	std::queue<std::pair<int, int>> q;
	std::vector<int> vec(N, 0);

	for (int i = 0; i < N; ++i) {
		int num;
		std::cin >> num;
		q.emplace(num, i);
	}

	// ��� �ð� ����
	int time = 0;
	while (!q.empty()) {
		// ���ڸ� ������ ���ϴ� ���� ���� �� ��� �ð� ���� 
		auto [piece, idx] = q.front();
		piece--;
		time++;

		q.pop();

		// ���ϴ� ��ŭ ������ ��� �ð� ���
		if (piece == 0) {
			vec[idx] = time;
		}
		// ���ϴ� ������ ����������, �ϴ� ���� �ο��� �� �ڷ� �̵�
		else {
			q.emplace(piece, idx);
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << ' ';
	}
	return 0;
}