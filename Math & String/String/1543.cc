#include <bits/stdc++.h>

// Ư�� �ܾ �ߺ��� �����ϰ� �� �� �����ϴ��� Ƚ���� ���� �Լ��� ���� ��, �� ��Ģ�� �Ʒ��� ����
// ���� ���, ������ abababa�̰� ã������ �ܾ ababa���, �� �ܾ 0������ ã�� �� �ְ� 2�����͵� ã�� �� ������, ���ÿ� �� ���� ����
// �� ��, �� �Լ��� ���� ������ �ܾ��� ���� Ƚ���� ���ϴ� ����

int cnt;

int main() {
	// ���� ���ڰ� ���Ե� ���ڿ��� �����ϹǷ� getline���� �Է��� ����
	std::string str;
	std::getline(std::cin, str);

	std::string input;
	std::getline(std::cin, input);

	int i = 0;
	while (i + input.length() <= str.length()) {
		std::string temp(str.begin() + i, str.begin() + i + input.length());
		
		// input�� ��ġ�ϴ� ��� input�� ���̸�ŭ �ǳʶ� ��ġ�������� Ž��(�ߺ� ���ܸ� ����)
		if (temp == input) {
			cnt++;
			i += input.length();
		}
		// input�� ��ġ���� �ʴ� ��� ���� ���� Ž��
		else 
			i++;
	}

	std::cout << cnt;
	return 0;
}