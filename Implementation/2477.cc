#include <iostream>
#include <vector>
#include <cstring>

// �Ʒ� ������ ����
// https://www.acmicpc.net/problem/2477

int answer;

int main() {
	int N;
	std::cin >> N;

	int width = 1;
	int deleted_width = 1;

	std::vector<std::pair<int, int>> vec;

	// �� ������� ������ Ƚ���� ����
	int dir_cnt[4];
	memset(dir_cnt, 0, sizeof(dir_cnt));

	for (int i = 0; i < 6; ++i) {
		int dir, len;
		std::cin >> dir >> len;

		vec.emplace_back(dir, len);
		dir_cnt[dir - 1]++;
	}

	for (int i = 0; i < 6; ++i) {
		// ū ���簢���� ���̴� �� ���� ������ ���� �� ���� ������ ���� ����
		if (dir_cnt[vec[i].first - 1] == 1) {
			width *= vec[i].second;
			continue;
		}

		// ���� ���簢���� ���̸� �̷�� �� ���̴� ���� ���� ���̿� �����ϴ� ���̷� ������
		// ���� ��� 2 1 2, 1 2 1�� ������ ������ ��� ���� �簢���� ���̴� 1�� 2�� ������ ���� �� ����
		if (vec[i % 6].first == vec[(i + 2) % 6].first) {
			deleted_width *= vec[(i + 1) % 6].second;
		}
	}

	// ū �簢������ ���� �簢���� ������ �� ��, ���� �� ��� ������ ������ ���� ���ϸ� ���� ���� �� ����
	width -= deleted_width;
	answer = N * width;

	std::cout << answer;
	return 0;
}