#include <iostream>
#include <stack>
#include <algorithm>

// ���� ��ȣ�� �ݴ� ��ȣ�� �̷���� ���ڿ��� ���� ��, �������� ���ڿ��� ����� ���� ������ �ּ� Ƚ���� ���ϴ� ����
// ���ڿ��� ���� �� �ִ� ������ ���� ��ȣ�� �ݴ� ��ȣ�� �ٲٰų�, �ݴ� ��ȣ�� ���� ��ȣ�� �ٲٴ� ����

int main() {
	int index = 1;

	while (true) {
		std::string input;
		std::cin >> input;

		// �� �� �̻��� '-'�� �ԷµǸ� ����
		if (std::find(input.begin(), input.end(), '-') != input.end()) {
			return 0;
		}

		int answer = 0;

		std::stack<char> s;
		for (char c : input) {
			if (c == '{')
				s.push(c);
			else {
				// �� ó���� '}'�� ������ �ùٸ��� �����Ƿ� '{'���� ġȯ�Ͽ� ���� �� ��ȯ �� ����
				if (s.empty()) {
					answer++;
					s.push('{');
				}
				else {
					s.pop();
				}
			}
		}
		
		// ���� ������ ������ ¦�� ���� ���� ��ȣ�鸸�� ��������
		// ���� ��ȣ���� 2���� ���� �������� ������ ���� �� �ֱ� ������, ���� ���� ũ���� ���ݸ�ŭ �߰� ��ȯ�� �����ϸ� ��
		answer += static_cast<int>(s.size() / 2);
		std::cout << index << '.' << ' ' << answer << '\n';

		index++;
	}
}