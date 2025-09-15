#include <bits/stdc++.h>

// ������ �۾��� ���� ������ ���̿� �� �ҿ�ð��� ���ϴ� ����
// �Ʒ��� ���� �� ���� �۾��� ������
// 1. Ư�� ��ġ���� ����� �ϳ� ������ �κ��丮�� ����(2�� �ҿ�)
// 2. �κ��丮���� ����� �ϳ� ������ ��ǥ�� ���� �� ��� ���� ����(1�� �ҿ�)

constexpr int MAX = 501;
constexpr int MAX_H = 257;

int N, M, B;
int field[MAX][MAX];	// �ʵ忡 �ִ� �� ��ϵ��� ����
int heights[MAX_H];		// ��� ���̵��� ���� 

long long best_time = LLONG_MAX;
int best_height;

int main() {
	std::cin >> N >> M >> B;

	int min_h = 1000;
	int max_h = 0;

	// �Էµ� ���̵��� Ƚ���� heights�����ϸ�, �ּ� ���̿� �ִ� ���̸� ������
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> field[i][j];
			heights[field[i][j]]++;
			min_h = std::min(field[i][j], min_h);
			max_h = std::max(field[i][j], max_h);
		}
	}

	// ������ �ּ� ���̺��� �ִ� ���̱��� ��� Ž��
	// h�� ����� ���� �� ��� ���̵��� �߰�, ���Ÿ� Ž��
	for (int h = min_h; h <= max_h; ++h) {
		long long remove = 0;
		long long add = 0;

		for (int height = 0; height < MAX_H; ++height) {
			// ���̰� ���� ����� ����
			if (heights[height] == 0)
				continue;
			
			// ���̰� h���� ���� ���, �����ؾ� �ϴ� ����� ���� ����
			if (height > h) {
				remove += (height - h) * heights[height];
			}
			// ���̰� h���� ���� ���, �߰��ؾ� �ϴ� ����� ���� ����
			else if(height < h) {
				add += (h - height) * heights[height];
			}
		}

		// ���� ���� ����� ���� + �����ؾ��ϴ� ����� ���� �߰��ؾ� �ϴ� ����� ������ ������ �Ұ����ϹǷ� ����
		if (remove + B < add)
			continue;
		// ���Ŵ� 2���� �ð���, �߰��� 1���� �ð��� �ҿ��
		long long time = 2 * remove + add;

		// �ִ� �ð��� �����ϸ�, �ð��� ������ ��� ���̰� ���� ���� ��츦 ä��
		if (time < best_time || (time == best_time && best_height < h)) {
			best_time = time;
			best_height = h;
		}
	}

	std::cout << best_time << ' ' << best_height;
	return 0;
}