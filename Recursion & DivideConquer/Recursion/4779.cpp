#include <iostream>
#include <cmath>

// �Ϲ����� ��� ����
// ���� : https://beginnerdeveloper-lit.tistory.com/141

void Cantor(int n) {
	// ���� ����; N = 0 �� ��� "-" ���
	if (n == 0) {
		std::cout << '-';
		return;
	}

	// N��° ĭ��� ������ (N - 1)��° ĭ��� ������ 2�� ���� ��
	// ���̿� ������ (N - 1)��° ĭ��� ������ ũ�⸸ŭ �־�� ��
	Cantor(n - 1);
	for (int i = 0; i < std::pow(3, (n - 1)); i++) {
		std::cout << " ";
	}
	Cantor(n - 1);
}

int main() {
	int N;

	while (std::cin >> N) {
		Cantor(N);
		std::cout << "\n";
	}

	return 0;
}