#include <bits/stdc++.h>

// �� ������ 1�� ������ ���� ¦�� ���� ���ڿ� S�� ������
// �� �� S�� �����ϴ� ���� �� ������ 0�� 1�� ���ŵ� ���ο� ���ڿ� S'�� ������� ��
// S'�� ������ ���ڿ� �� ���� ������ ���� ���� ���� ���ϴ� ����

// S'�� ������ 0�� 1�� ���������ν� ������� �� �ִ� ���ڿ�. �� �ܼ��� ������ �����θ� �̷�����ٰ� S'�� �ش����� ����
// S���� 1�� �տ�������, 0�� �ڿ������� �����ؾ� ���� ������ ���� ���� S'�� ���� �� ����

int main() {
	std::string S;
	std::cin >> S;

	int zero_cnt = 0, one_cnt = 0;

	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == '0')
			zero_cnt++;
		else
			one_cnt++;
	}

	// �Էµ� ���ڿ����� 0�� 1�� ������ ���� �������� ����
	zero_cnt /= 2, one_cnt /= 2;
	int zero_idx = 0, one_idx = 0;

	// 1���� ����. S�� �տ������� Ž���ϸ� one_cnt��ŭ�� 1�� ������
	std::string temp = "";
	for (char c : S) {
		if (c == '1' && one_idx < one_cnt) {
			one_idx++;
		}
		else
			temp.push_back(c);
	}
	
	// ���� temp ���ڿ��� S���� 0�� �״�� ������, 1�� ������ ���ŵ� ������ ���ڿ���
	// 0 ����. temp�� �ڿ������� Ž���ϸ�, zero_cnt��ŭ�� 0�� ������
	std::string answer = "";
	for (int i = temp.length() - 1; i >= 0; --i) {
		char c = temp[i];
		if (c == '0' && zero_idx < zero_cnt) {
			zero_idx++;
		}
		else
			answer.push_back(c);
	}

	// ���� answer ���ڿ��� push_back �������� ���Ͽ� one_cnt���� 1�� �տ�, zero_cnt���� 0�� �ڿ� �ִ� ����. �� ���� ������ ���� �ڿ� �ִ� ���ڿ�
	// ���ڿ��� �������� ���������� ���� ������ ���� ���� ���ڿ��� �������
	std::reverse(answer.begin(), answer.end());

	std::cout << answer;
	return 0;
}