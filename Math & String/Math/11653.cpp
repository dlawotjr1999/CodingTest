#include <iostream>

// ���μ����� ����
int main() {
	int num;
	int i = 2;

	std::cin >> num;

	// ���� 2�� ������ ���������� Ȯ��
	// 2�� ������ �������� ������ i�� ������Ű�鼭 ���μ��� ����
	while (num != 1) {
		if (num % i == 0) {
			std::cout << i << "\n";
			num /= i;
		}
		else 
			i++;
	}
}