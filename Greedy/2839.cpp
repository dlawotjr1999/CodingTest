#include <iostream>

// ������ ��Ȯ�� Nų�α׷� ����ؾ� �� �� �ʿ��� 5kg ������ 3kg ������ �ּ� ������ ���ϴ� ����
// ���� �� ������ ���� �� ���� ������ ��� -1�� ����
int main() {
	int N;
	int pocketA, pocketB;

	std::cin >> N;

	// 5kg ������ �ִ��� Ȱ���ؾ� ������ �ּҷ� ����� �� �ִ�
	pocketA = N / 5;
	while (true) {
		if (pocketA < 0) {
			std::cout << -1;
			return 0;
		}
		// 5kg ������ ������ ���� ������ ������ 3kg ������� ���� �� �ִ����� Ȯ��
		if ((N - pocketA * 5) % 3 == 0) {
			pocketB = (N - pocketA * 5) / 3;
			break;
		}
		pocketA--;
	}
	std::cout << pocketA + pocketB << std::endl;
}