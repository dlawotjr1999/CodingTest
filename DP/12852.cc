#include <bits/stdc++.h>

// ���� N�� �־����� ��, N�� 1�� ����� ���� ����� �� �ִ� �������� ���� �� ������ ������
// 1. X�� 3���� ������ ��������, 3���� ����
// 2. X�� 2�� ������ ��������, 2�� ����
// 3. 1�� ��
// �� ������ �̿��ؼ� N�� 1�� ���� ��, ������ ����ϴ� �ּ� Ƚ���� ���ؾ���
// �߰���, 1�� ����� ����� ���Ե� ���� ������� �Բ� ����ؾ� ��

int main() {
	int N;
	std::cin >> N;

	// ���� Ƚ���� first�� �����ϸ� ���� ������ ��, �� ���Ŀ� ���� second�� ����
	std::vector<std::pair<int, int>> DP(N + 1, { 0,0 });
	// 1�� ��ǥ ���̹Ƿ� first(���� Ƚ��)�� 0, ���� �ܰ谡 ������ -1�� ǥ���Ͽ� second�� ����
	DP[1] = { 0,-1 };

	// 1�� �� ���, 2�� ������ ���, 3���� ������ ��츦 ��� ����Ͽ� ���� ����
	// ���� Ƚ���� �� ���� ����� ���� DP�� first�� ����
	// ������ �����ϱ� ������ ���� DP�� second�� ����(������)
	for (int i = 2; i <= N; ++i) {
		DP[i].first = DP[i - 1].first + 1;
		DP[i].second = i - 1;

		if (i % 3 == 0) {
			int temp = DP[i / 3].first + 1;
			if (temp < DP[i].first) {
				DP[i].first = temp;
				DP[i].second = i / 3;
			}
		}
		if (i % 2 == 0) {
			int temp = DP[i / 2].first + 1;
			if (temp < DP[i].first) {
				DP[i].first = temp;
				DP[i].second = i / 2;
			}
		}
	}

	std::cout << DP[N].first << '\n';

	std::cout << N << ' ';
	while (DP[N].second != -1) {
		std::cout << DP[N].second << ' ';
		N = DP[N].second;
	}

	return 0;
}