#include <iostream>
#include <deque>

// deque Ȱ�� ����
// ǳ���� �Ͷ߸��� ������ ���ڸ�ŭ �̵��ؼ� ǳ���� ������ ������ ���ϴ� ����

int main() {
	int N;
	std::cin >> N;

	// ǳ���� ���� ���ڿ� ������ �� ���� �����ϱ� ���� pair�� ���
	std::deque<std::pair<int, int>> ballons;

	for (int i = 1; i <= N; i++) {
		int num;
		std::cin >> num;

		ballons.emplace_back(num, i);
	}

	while (!ballons.empty()) {

		// �� ���� ǳ���� �Ͷ߸���
		// �Ͷ߸� ǳ���� deque���� ����
		int num = ballons.front().first;
		std::cout << ballons.front().second << " ";
		ballons.pop_front();

		// ǳ���� '�Ͷ߸���' �ȿ� �ִ� ���ڸ�ŭ �̵��� �Ѵ�
		// '�Ͷ߸���' ��� ���� front �����͸� �˸��� ��ġ�� ��ġ�ϴ� ��
		// NOTE : ����� �Ͷ߸��� �� �� �̵���, ������ �̵� �� �Ͷ߸��⸦ �����ؾ� ��
		if (num > 0) {
			for (int i = 0; i < (num - 1); i++) {
				ballons.push_back(ballons.front());
				ballons.pop_front();
			}
		}
		else {
			for (int i = num; i < 0; i++) {
				ballons.push_front(ballons.back());
				ballons.pop_back();
			}
		}

	}
	return 0;
}