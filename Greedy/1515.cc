#include <iostream>
#include <string>

// ������� ������ 1���� N������ ����� �̷���� ���ڿ��� ����
// �� ���ڿ����� �Ϻΰ� �������� ��, ������ ���ڿ��κ��� ���� ������ N�� �ּڰ��� ���ϴ� ����

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::string str;
	std::cin >> str;
	
	int N = 1;
	int idx = 0;

	while (true) {
		// N�� �ϴ� ���ڿ��� ġȯ(�񱳸� �����ϰ� �ϱ� ����)
		std::string temp = std::to_string(N);

		// �ڸ����� ���� ������ idx == N�� ��쿡 ���� ���ڷ� �̵�
		// N�� �� �ڸ� ���� �ƴ� ��쿡�� �� �ڸ����� ���� ���鼭 ���� ���ڷ� �̵�
		for (int i = 0; i < temp.length(); ++i) {
			if (str[idx] == temp[i])
				idx++;
			if (idx >= str.length()) {
				std::cout << N;
				return 0;
			}
		}
		N++;
	}
	return 0;
}