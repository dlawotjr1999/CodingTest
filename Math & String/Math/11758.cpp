#include <iostream>

// CCW �˰��� ����
// CCW �˰��򿡼� ���� ����� ��ȣ���� ���� ������ ��ġ ����� �Ʒ��� ����
// 1. ������ ��� : ������ �ð� �������� ������
// 2. 0�� ��� : ������ ������ �� ����
// 3. ����� ��� : ������ �ݽð� �������� ������

int main() {
	int x1, y1, x2, y2, x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int result = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);

	if (result < 0)
		std::cout << -1;
	else if (result == 0)
		std::cout << 0;
	else
		std::cout << 1;

	return 0;
}