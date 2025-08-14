#include <iostream>
#include <string>

// �� ���� �־����� ��, �� �� ���̿� �ִ� 8�� ���� ���� ����ִ� ���� ����ִ� 8�� ������ ���ϴ� ����

int answer;

int main() {
	int L, R;
	std::cin >> L >> R;

	std::string left = std::to_string(L);
	std::string right = std::to_string(R);
	size_t len = std::max(left.length(), right.length());

	// �� ª�� ���̸� ���� ���� �տ� 0���� �е��� �־� ���̸� ����
	if (left.length() < len) {
		left.insert(0, len - left.length(), '0');
	}
	if (right.length() < len) {
		right.insert(0, len - right.length(), '0');
	}
 
	// �� ���ڿ��� ���� �ε����� ���� ���ϸ鼭 ���λ簡 ������ ��ġ�ϴ� ���� �� '8'�� �ڸ��� �����
	// ���� L[i] != R[i]�� �Ǵ� ����, ���ĺ��ʹ� �� ���̿� 8�� ������ �޶��� �� �����Ƿ� Ž���� ������
	for (int i = 0; i < len; ++i) {
		// �ڸ����� �ٸ� ��쿡�� �� ������ŭ�� 8���� ������
		if (left[i] != right[i]) {
			break;
		}
		// �ڸ����� ���� ��쿡�� �� ��ŭ�� 8�� ������
		if (left[i] == '8' && right[i] == '8')
			answer++;
	}

	std::cout << answer;
	return 0;
}