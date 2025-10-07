#include <iostream>
#include <deque>

// N���� ī�尡 ���� �� ������ ������ �ݺ��Ѵٰ� ����
// ���� ���� �ִ� ī�带 �ٴڿ� ������ �� ����, ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű�
// �� ������ ī�尡 �� ���� ���� ������ �ݺ��Ѵٰ� �� �� ���� �������� ���� ī�带 ���ϴ� ����

int main() {
	int N;	std::cin >> N;
	std::deque<int> dq;

	for (int i = 1; i <= N; ++i) {
		dq.push_back(i);
	}

	// ī�尡 �� ���� ���� ������ �ݺ�
	while (dq.size() > 1) {
		// ���� ���� �ִ� ī�带 ������, �� ���� ���� ���� �ִ� ī�带 ���� �Ʒ��� ī�� ������ �ű�
		dq.pop_front();

		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}

	// ���� �������� ���� ī�� ���
	std::cout << dq.back();
	return 0;
}