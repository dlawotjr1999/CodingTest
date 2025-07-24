#include <bits/stdc++.h>

// ���� ������ �帵ũ���� �� �� ��� ��ġ���� ��
// �� ������� �ٸ� ������� ���� �� ������ �긮�� ��
// ��, a�� ���� xa + (xb / 2)�� ����� b�� �����ų�, b�� ���� xb + (xa / 2)�� ����� a�� ������ �� ��찡 ������
// �� ������ ����Ͽ� ���� ������ �帵ũ�� ���ļ� �� ���� �ִ��� ���ϴ� ����

double answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<double> beverages(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> beverages[i];
	}
	
	// �긮�� ���� �ּ�ȭ�ؾ� �� ������ �帵ũ�� ���� �ִ��� ��
	// ��, ���� ���̰� ū ������� ������ ������ ��������� ���̰� ū ������� �ξ ���ľ� �� 
	std::sort(beverages.begin(), beverages.end());
	answer = beverages[N - 1];

	for (int i = 0; i < N - 1; ++i) {
		beverages[i] /= 2;
		answer += beverages[i];
	}

	// 10e-5���� ���� ���
	answer = round(answer * 10e5) / 10e5;
	std::cout << answer;
}