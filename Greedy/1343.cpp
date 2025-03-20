#include <iostream>
#include <vector>

// X�� .���� �̷���� ���ڿ��� AAAA�� BB�� ġȯ�ϴ� ����
// X�� ��ƴ���� AAAA�� BB�� ������ϸ�, ���� ���ϴ� ���� -1�� ����Ѵ�

int main() {
	std::string input;
	std::string result = "";
	int cnt = 0;

	std::cin >> input;

	for (int i = 0; i < input.length(); i++) {
		// . ������ �ִ� X�� �̷���� �ִ� ���ڿ��� ���̸� ����
		if (input[i] != '.') {
			cnt++;
		}
		else {
			// cnt�� Ȧ���̸� �������̳��� ���� �� �����Ƿ� -1�� ���
			if (cnt % 2 != 0) {
				std::cout << -1;
				return 0;
			}
			// ���ڿ��� ġȯ�ϴ� ����. 
			// �ִ��� AAAA�� Ȱ���ϸ�, �������� 2���� ���� ��� BB�� ���´�
			else {
				while (cnt >= 4) {
					result += "AAAA";
					cnt -= 4;
				}
				while (cnt == 2) {
					result += "BB";
					cnt -= 2;
				}
				result += '.';
			}
		}
	}

	// .���� ������ �ʴ� ���ڿ��� ��� ���� ���ڿ��� ó���ϱ� ���� �� �� �� ������ �ؾ� ��
	// .���� ������ ���� ��� ���� �ݺ������� cnt�� Ȱ���Ͽ� ������ ���ڿ��� ó���Ѵ�
	if (cnt % 2 != 0) {
		std::cout << -1;
		return 0;
	}
	else {
		while (cnt >= 4) {
			result += "AAAA";
			cnt -= 4;
		}
		while (cnt == 2) {
			result += "BB";
			cnt -= 2;
		}
	}

	std::cout << result;

	return 0;
}