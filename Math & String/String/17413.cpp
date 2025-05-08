#include <iostream>
#include <string>
#include <algorithm>

// �Էµ� ���ڿ��� ��Ģ�� �°� ������ ����
// ��Ģ : �ܾ� ���� ������, ���� ���� �ܾ���� �״�� ���

int main() {
	std::string input;

	// ���⵵ �Է¹ޱ� ���� getline ���
	std::getline(std::cin, input);

	std::string result = "";
	std::string temp = "";
	bool isTag = false;

	for (char c : input) {

		// '<'�� �� ������ �ܾ���� ��� ����� result�� �����ϰ� isTag�� true�� ���� 
		if (c == '<') {
			std::reverse(temp.begin(), temp.end());
			result += temp;
			temp.clear();

			isTag = true;
			result += c;
		}

		// '>'�� ��, isTag�� false�� �����ϰ� '>'�� result�� ����
		else if (c == '>') {
			isTag = false;
			result += c;
		}

		// '<' ������ �ܾ�� '>'�� ������ ������ �״�� result�� ����
		else if (isTag) {
			result += c;
		}

		// �Ϲ� ���ڵ��� ���ʴ�� temp�� ������
		// ���� ���鹮�ڸ� ������ temp�� ����� ���ڿ��� ������ result�� ����
		else {
			if (c == ' ') {
				std::reverse(temp.begin(), temp.end());
				result += temp + ' ';
				temp.clear();
			}
			else {
				temp += c;
			}
		}
	}

	// ������ ���ڿ� ó��
	std::reverse(temp.begin(), temp.end());
	result += temp;

	std::cout << result;
	return 0;
}
