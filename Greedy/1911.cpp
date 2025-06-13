#include <iostream>
#include <vector>
#include <algorithm>

// �񿬼����� �������̵��� ���� ���� �ʿ��� �κ������� �ּ� ������ ���ϴ� ����
// ��ġ�� 10�� ������ �����̱� ������, ���ͳ� �迭�� �ƴ� pair�� �̿��� ������ Ȱ���Ͽ� ���

int N, L;
std::vector<std::pair<int, int>> puddles;

int main() {
	std::cin >> N >> L;
	puddles.resize(N);

	for (int i = 0; i < N; i++) {
		std::cin >> puddles[i].first >> puddles[i].second;
	}

	// �������� ������ ������ �� ���
	std::sort(puddles.begin(), puddles.end());

	int current = 0;
	int count = 0;

	// �� ������ ���ؼ� ����
	for (auto [start, end] : puddles) {
		// ������� ������ �κ����� ���� �������� ���������� �տ� ������ ���� �������� ���������� �̵�
		if (current < start)
			current = start;

		// �� ������ ���ؼ� �κ����� �ϳ��� �̿��Ͽ� �������̸� ����
		while (current < end) {
			current += L;
			count++;
		}
	}

	std::cout << count;

	return 0;
}