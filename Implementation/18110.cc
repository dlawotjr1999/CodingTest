#include <bits/stdc++.h>

// solved.ac�� ���̵� ���� ����� ���ϴ� ����
// ���̵� ���� ����� �Ʒ��� ���� ������
// 1. ���� �ƹ� �ǰ��� ���ٸ� ������ ���̵��� 0���� ����
// 2. �ǰ��� �ϳ� �̻� �ִٸ�, ������ ���̵��� ��� ����� ���̵� �ǰ��� 30 % ����������� ����(�� ����, ���� 15���δ� ������)

int main() {
	int n;
	std::cin >> n;

	if (n == 0) {
		std::cout << 0;
		return 0;
	}

	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());
	// ��Ȯ���� ���� 0.15�� ���ϱ� ���ٴ� (n * 3) / 20�� ä��
	int except = round(double(n * 3) / 20);

	// 30���� ������� ���
	double sum = 0;
	for (int i = except; i < n - except; ++i) {
		sum += vec[i];
	}

	double avg = round(sum / (n - 2 * except));

	// ��� ����� ������ �ݿø�
	std::cout << std::fixed << std::setprecision(0) << avg;
	return 0;
}