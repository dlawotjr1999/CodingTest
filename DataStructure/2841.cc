#include <bits/stdc++.h>

// �ܰ����� ��Ÿ�� �־��� ��ε� �����Ϸ��� ��
// ���� ���� �� ���� ���� ������ ���� ���·� ���� ���� ������ ������, �������� ���� ���� �� ���� ������ ������ ���� ��
// �� �� ��ε� �����ϴµ� �ʿ��� �ּ����� �������� ���ϴ� ����

int answer;

int main() {
	int N, P;
	std::cin >> N >> P;

	// ��Ÿ�� 6���� �ٷ� �̷���� �����Ƿ� 7��(1 ~ 6)�� stack���� �̷���� vector�� ����
	std::vector<std::stack<int>> s(7);

	// �� ������ ��츦 �����
	// 1. ���� �ٿ��� �ƹ��͵� ������ ���� ���
	// 2. ���� fret���� ���� ���� ������ ���
	// 3. ���� fret���� ���� ���� ������ ���
	for (int i = 0; i < N; ++i) {
		int string, fret;
		std::cin >> string >> fret;
		
		// ���� fret���� �� ���� ���� fret�� ���� ��(3�� ���)
		// ���� fret�� ���� ������ 1ȸ �߰�
		while (!s[string].empty() && s[string].top() > fret) {
			s[string].pop();
			answer++;
		}

		// �ƹ��͵� ������ �ʾ��� �� ��, ���ο� �ٿ��� ������ �� ��(1�� ���)
		// ���� ���� fret�� ������ ������ 1ȸ �߰�
		if (s[string].empty()) {
			if (fret > 0) { 
				s[string].push(fret);
				answer++; 
			}
		}

		// ���� fret���� �� ���� ���� fret�� ���� ��(2�� ���)
		// �� ���� fret�� ������ ������ 1ȸ �߰�
		else { 
			if (s[string].top() < fret) {
				s[string].push(fret);
				answer++; 
			}
		}
	}

	std::cout << answer;
	return 0;
}