#include <bits/stdc++.h>

// �Ʒ� ������ ����
// https://www.acmicpc.net/problem/14719

int answer;

// i�� ĭ�� Ȯ���Ѵٰ� �� ��, i�� ĭ�� ��� �� �ִ� ������ ���� �Ʒ��� ����
// min((i��° ���� ���� �� ���� ���� ���� ����), ((i��° ���� ���� �� ���� ���� ���� ����)) - (i��° ���� ����)

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<int> vec(W);

	for (int i = 0; i < W; ++i) {
		std::cin >> vec[i];
	}

	// ���� ���κе��� ������ ��� �� �����Ƿ� (0, W-1) �������� Ž�� ����
	for (int i = 1; i < W - 1; ++i) {
		int left_height = -1, right_height = -1;

		// i��° ���� ���� �� ���� ���� ���� ���� ���
		for (int j = 0; j < i; ++j) {
			left_height = std::max(left_height, vec[j]);
		}

		// i��° ���� ���� �� ���� ���� ���� ���� ���
		for (int j = i + 1; j < W; ++j) {
			right_height = std::max(right_height, vec[j]);
		}

		// ��� �� �ִ� ������ ����� �����Ͽ� ���
		if (vec[i] < left_height && vec[i] < right_height) {
			answer += std::min(left_height, right_height) - vec[i];
		}
	}

	std::cout << answer;
	return 0;
}