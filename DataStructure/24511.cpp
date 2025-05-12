#include <iostream>
#include <vector>
#include <deque>

// queuestack�� ���ҵ��� �־��� �� �� ���ϰ��� ���ϴ� ����
// i�� �ڷᱸ���� ť��� A_i = 0, �����̶�� A_i = 1
// queuestack�� �۵��� �Ʒ��� ����

// 1. x_0�� �Է¹޴´�.
// 2. x_0�� 1�� �ڷᱸ���� ������ �� 1�� �ڷᱸ������ ���Ҹ� pop�Ѵ�.�׶� pop�� ���Ҹ� x_1�̶� �Ѵ�
// 3. x_1�� 2�� �ڷᱸ���� ������ �� 2�� �ڷᱸ������ ���Ҹ� pop�Ѵ�.�׶� pop�� ���Ҹ� x_2�̶� �Ѵ�
// ...
// 4. x_{N - 1}�� N�� �ڷᱸ���� ������ �� N�� �ڷᱸ������ ���Ҹ� pop�Ѵ�.�׶� pop�� ���Ҹ� x_N�̶� �Ѵ�
// 5. x_N�� ����

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int& elm : vec) {
		std::cin >> elm;
	}

	// stack�� ���ο� ���� ����ڸ��� pop�Ǳ� ������ �ǹ̾��� �ڷᱸ��
	// �� queuestack �� queue���� �����
	// ���ÿ����� �� �� �ֵ��� �� ���Ҵ� �� �տ��� ���ԵǸ�, ���������� pop�Ǵ� ���Ҵ� �ڷᱸ���� �� �ڿ��� ������ �̷����
	// �̷��� ������ ����⿡�� ������ ������ queuestack�� deque���� ������ �� ����
	std::deque<int> queuestack;
	for (int i = 0; i < N; i++) {
		int elm;
		std::cin >> elm;

		// queuestack �� stack�� ����(���� ���� ����)
		if (vec[i] == 0)
			queuestack.push_back(elm);
	}

	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int elm;
		std::cin >> elm;

		// queue���� ������� �� ���ο� ���Ұ� ������ ���� push_front��, ���ϵǴ� ���� pop_back���� �� �� ����
		queuestack.push_front(elm);		
		std::cout << queuestack.back() << " ";
		queuestack.pop_back();
	}

	return 0;
}