#include <iostream>
#include <algorithm>

// �־��� �� ������ Ȱ���Ͽ� S�� T�� �ٲ� �� �ִ����� ���ϴ� ����
// ������ �Ʒ��� ����.
// 1. ���ڿ��� �ڿ� A�� �߰�
// 2. ���ڿ��� ������ �ڿ� B�� �߰�
// idea : S���� T�� ���� ����� ���� �ſ� �����Ƿ�, �ݴ�� T���� S�� ���� �� �ִ����� Ȯ��

std::string S;
std::string T;

int main() {
	std::cin >> S;
	std::cin >> T;

	while (T.length() != S.length()) {

		// 1�� �ݴ� ���� : T�� �� �ڰ� A�� ��� T���� A�� ����
		if (T.back() == 'A')
			T.pop_back();

		// 2�� �ݴ� ���� : T�� �� �ڰ� B�� ��� B�� ���� T�� �����´�
		else {
			T.pop_back();
			std::reverse(T.begin(), T.end());
		}
	}

	std::cout << ((S == T) ? 1 : 0);

	return 0;
}