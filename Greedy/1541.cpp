#include <iostream>
#include <string>

// �Է����� �־��� ���Ŀ��� ���ڸ� ���� �ּڰ��� ����� ����
// idea : ó�� �����ϴ� - ���� ���ں��� ��� �ᱣ������ ���ָ� �ּڰ��� ���´�
int main() {
	std::string input;
	std::string temp = "";

	int result = 0;
	bool isMinus = false;

	std::cin >> input;

	// EOF���� ����ؾ� �ϹǷ� �ݺ����� input.size()���� �ݺ��Ѵ�
	for (int i = 0; i <= input.size(); i++) {
		if (input[i] == '+' || input[i] == '-' || input[i] == '\0') {
			if (isMinus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = "";
			// ó�� -�� ��Ÿ����, �� ���� ��� ���ڴ� ���ش�
			if (input[i] == '-') {
				isMinus = true;
			}
		}
		// ��ȣ�� �ƴ� ���� stoi�� ����� �� �ֵ��� temp�� ����
		else
			temp += input[i];
	}

	std::cout << result;

	return 0;
}