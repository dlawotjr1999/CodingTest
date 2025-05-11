#include <iostream>
#include <stack>
#include <vector>

// 1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν� �־��� ������ ���� �� �ִ����� ���ϴ� ����
// push�� +, pop�� -�� ���� �� ������ ������ ��� ���� �� �ִ��� �� ����� ���
// �� +�� Ư�� ���ڸ� ����� ���� ����, -�� ������ �����ϴ� ���Ҹ� �ǹ���

int main() {
	int n;
	int idx = 1;
	std::vector<char> answer;
	std::stack<int> s;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int num; std::cin >> num;
		
		// ������ top�� num���� �۰ų� ���� ������ 1, 2, ... �� ���ÿ� push
		while (num >= idx) {
			s.push(idx);
			answer.push_back('+');
			idx++;
		}
		// ������ top�� num�� ������ Ÿ������ �ϴ� �����̹Ƿ� pop
		if (s.top() == num) {
			answer.push_back('-');
			s.pop();
		}
		// ������ top�� Ÿ�� ���ڰ� �ٸ��� ���� ���� �Ұ���
		else {
			std::cout << "NO";
			return 0;
		}
	}

	for (char& c : answer) {
		std::cout << c << '\n';
	}
	return 0;
}